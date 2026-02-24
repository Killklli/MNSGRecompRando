"""Generate a Graphviz DOT diagram from MN64 logic files."""

import importlib.util
import inspect
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Set


def load_logic_module(file_path: Path, logic_dir: Path):
    """Dynamically load a logic module."""
    # First, ensure the parent package is importable
    parent_dir = logic_dir.parent
    if str(parent_dir) not in sys.path:
        sys.path.insert(0, str(parent_dir))

    # Load the logic classes and holder first if not already loaded
    if "apworld.Logic.mn64_logic_classes" not in sys.modules:
        classes_path = logic_dir / "mn64_logic_classes.py"
        holder_path = logic_dir / "mn64_logic_holder.py"

        # Load logic holder
        holder_spec = importlib.util.spec_from_file_location("apworld.Logic.mn64_logic_holder", holder_path)
        holder_module = importlib.util.module_from_spec(holder_spec)
        sys.modules["apworld.Logic.mn64_logic_holder"] = holder_module
        holder_spec.loader.exec_module(holder_module)

        # Load logic classes
        classes_spec = importlib.util.spec_from_file_location("apworld.Logic.mn64_logic_classes", classes_path)
        classes_module = importlib.util.module_from_spec(classes_spec)
        sys.modules["apworld.Logic.mn64_logic_classes"] = classes_module
        classes_spec.loader.exec_module(classes_module)

    # Now load the actual logic file
    module_name = f"apworld.Logic.{file_path.stem}"
    spec = importlib.util.spec_from_file_location(module_name, file_path)
    module = importlib.util.module_from_spec(spec)
    sys.modules[module_name] = module
    spec.loader.exec_module(module)
    return module


def extract_logic_string(lambda_func) -> str:
    """Extract a readable string from a lambda function."""
    try:
        source = inspect.getsource(lambda_func).strip()
        # Extract the lambda body
        if "lambda l:" in source:
            logic = source.split("lambda l:", 1)[1].strip()
            # Clean up common patterns
            logic = logic.rstrip(",)")
            # Remove trailing context
            if logic.endswith(")"):
                # Count parentheses to find the actual end
                depth = 0
                for i, char in enumerate(logic):
                    if char == "(":
                        depth += 1
                    elif char == ")":
                        depth -= 1
                        if depth < 0:
                            logic = logic[:i]
                            break
            return logic if logic != "True" else "Always"
        return "Unknown"
    except (OSError, TypeError):
        # If we can't get source, try to represent the function
        return "Complex Logic"


def sanitize_node_id(name: str) -> str:
    """Create a valid node ID from a region name."""
    # Replace spaces and special characters
    return name.replace(" ", "_").replace("'", "").replace("-", "_").replace("(", "").replace(")", "")


def generate_graphviz_diagram(logic_dir: Path, output_file: Path):
    """Generate a Graphviz DOT diagram with better formatting."""

    all_regions: Dict[str, dict] = {}

    # Load all logic files
    logic_files = sorted(logic_dir.glob("mn64_*.py"))
    logic_files = [f for f in logic_files if f.stem not in ["mn64_logic_classes", "mn64_logic_holder"]]

    print(f"Found {len(logic_files)} logic files")

    for logic_file in logic_files:
        print(f"Processing {logic_file.name}...")
        try:
            module = load_logic_module(logic_file, logic_dir)
            if hasattr(module, "LogicRegions"):
                regions = module.LogicRegions
                for region_key, region_obj in regions.items():
                    all_regions[region_key] = {
                        "name": region_obj.name,
                        "locations": region_obj.locations,
                        "exits": region_obj.exits,
                        "level": region_obj.level.value if hasattr(region_obj.level, "value") else str(region_obj.level),
                    }
        except Exception as e:
            print(f"Error processing {logic_file.name}: {e}")
            continue

    print(f"\nTotal regions found: {len(all_regions)}")

    # Build DOT content with better formatting
    dot_lines = [
        "digraph MN64Logic {",
        "  rankdir=LR;",
        '  node [shape=box, style=filled, fontname="Arial", fontsize=10];',
        '  edge [fontname="Arial", fontsize=8];',
        "  splines=ortho;",
        "  ranksep=2;",
        "  nodesep=0.8;",
        "  concentrate=true;",
        '  charset="UTF-8";',
        "",
    ]

    # Color palette for different levels
    level_colors = {
        "Oedo Town": "#FFB3BA",
        "Musashi": "#BAFFC9",
        "Mutsu": "#BAE1FF",
        "Yamato": "#FFFFBA",
        "Sanuki": "#FFD8BA",
        "Folkypoke Village": "#E0E0E0",
        "Tosa": "#C9C9FF",
        "Iyo": "#E4C1F9",
        "Ghost Toys Castle": "#FFC1E3",
        "Oedo Castle": "#FFF4BA",
        "Kai": "#D4A5F4",
        "Bizen": "#A5F4C3",
        "Festival Temple Castle": "#FFCBA4",
        "Gorgeous Music Castle": "#F4C2C2",
    }

    # Add nodes with better formatting
    for region_key, region_data in all_regions.items():
        region_name = region_data["name"].replace('"', '\\"').replace("'", "\\'")
        level = region_data["level"]
        color = level_colors.get(level, "#D3D3D3")

        # Count notable items
        notable_items = []
        for location in region_data["locations"]:
            item_name = location.item_type.value if hasattr(location.item_type, "value") else str(location.item_type)
            if item_name not in ["Ryo", "Pot of Ryo", "Pot"]:
                loc_name = location.name.replace('"', '\\"').replace("'", "\\'")
                item_display = f"{loc_name}: {item_name}".replace('"', '\\"').replace("'", "\\'")
                notable_items.append(item_display)

        # Create label with items
        if notable_items:
            items_str = "\\n".join(notable_items[:5])
            if len(notable_items) > 5:
                items_str += f"\\n... +{len(notable_items) - 5} more"
            label = f"{region_name}\\n\\n{items_str}"
        else:
            label = region_name

        # Special formatting for Goemon's House
        if region_key == "GoemonsHouse":
            dot_lines.append(f'  "{region_key}" [label="{label}", fillcolor="{color}", penwidth=3, color=gold];')
        else:
            dot_lines.append(f'  "{region_key}" [label="{label}", fillcolor="{color}"];')

    dot_lines.append("")

    # Track missing destinations
    missing_destinations = set()

    # Add edges with bidirectional detection
    connections_added = set()
    reverse_connections = {}

    for region_key, region_data in all_regions.items():
        for exit_info in region_data["exits"]:
            dest_region = exit_info.destinationRegion
            if dest_region not in all_regions:
                missing_destinations.add(dest_region)
                continue

            logic = extract_logic_string(exit_info.logic)
            reverse_connections[(region_key, dest_region)] = logic

    if missing_destinations:
        print(f"\nWarning: {len(missing_destinations)} destination regions not found:")
        for dest in sorted(missing_destinations):
            print(f"  - {dest}")

    for region_key, region_data in all_regions.items():
        for exit_info in region_data["exits"]:
            dest_region = exit_info.destinationRegion
            if dest_region not in all_regions:
                continue

            connection_tuple = (region_key, dest_region)
            reverse_tuple = (dest_region, region_key)

            if connection_tuple in connections_added:
                continue

            logic = extract_logic_string(exit_info.logic)
            logic_label = logic.replace('"', '\\"').replace("'", "\\'").replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;")

            # Truncate long logic strings
            if len(logic_label) > 40:
                logic_label = logic_label[:37] + "..."

            # Check for bidirectional with same logic
            reverse_logic = reverse_connections.get(reverse_tuple, None)
            is_bidirectional = reverse_logic == logic and reverse_tuple not in connections_added

            if is_bidirectional:
                connections_added.add(connection_tuple)
                connections_added.add(reverse_tuple)
                dot_lines.append(f'  "{region_key}" -> "{dest_region}" [label="{logic_label}", dir=both, color=green];')
            else:
                connections_added.add(connection_tuple)
                dot_lines.append(f'  "{region_key}" -> "{dest_region}" [label="{logic_label}"];')

    dot_lines.append("}")

    # Write DOT file
    dot_content = "\n".join(dot_lines)
    output_file.write_text(dot_content, encoding="utf-8")
    print(f"\n✓ Graphviz DOT file written to {output_file}")
    print(f"  Total regions: {len(all_regions)}")
    print(f"  Total connections: {len(connections_added)}")

    # Try to convert to SVG (better for large graphs than PNG)
    try:
        svg_output = output_file.with_suffix(".svg")
        result = subprocess.run(["dot", "-Tsvg", str(output_file), "-o", str(svg_output)], capture_output=True, text=True, check=True)
        print(f"✓ SVG diagram created: {svg_output}")
        print(f"  Open {svg_output.name} in your browser to view")
        return True
    except subprocess.CalledProcessError as e:
        print(f"\nNote: Could not auto-convert to SVG: {e}")
        print("Install Graphviz and add it to PATH to enable auto-conversion")
        print(f"Or run manually: dot -Tsvg {output_file.name} -o logic_diagram.svg")
        return False
    except FileNotFoundError:
        print(f"\nNote: Graphviz 'dot' command not found")
        print("Install Graphviz from https://graphviz.org/download/")
        print(f"Or run manually after install: dot -Tsvg {output_file.name} -o logic_diagram.svg")
        return False


def main():
    """Main entry point."""
    script_dir = Path(__file__).parent
    logic_dir = script_dir / "apworld" / "Logic"
    output_file = script_dir / "logic_diagram.dot"
    svg_file = script_dir / "logic_diagram.svg"

    if not logic_dir.exists():
        print(f"Error: Logic directory not found at {logic_dir}")
        return

    print("Generating Graphviz DOT diagram from MN64 logic files...")
    print("=" * 60)

    success = generate_graphviz_diagram(logic_dir, output_file)

    if not success:
        print("\n" + "=" * 60)
        print("Attempting to render diagram with subprocess call...")

        # Try direct subprocess call to dot
        try:
            result = subprocess.run(["dot", "-Tsvg", str(output_file), "-o", str(svg_file)], capture_output=True, text=True, check=True)
            print(f"✓ SVG diagram created: {svg_file}")
            print(f"\nYou can now open {svg_file.name} in your browser to view the diagram!")
        except FileNotFoundError:
            print("\n✗ Graphviz 'dot' command not found in PATH")
            print("Please install Graphviz from https://graphviz.org/download/")
            print(f"Or upload {output_file.name} to http://www.webgraphviz.com/ to view it online.")
        except subprocess.CalledProcessError as e:
            print(f"\n✗ Error running dot command: {e.stderr}")
            print(f"You can upload {output_file.name} to http://www.webgraphviz.com/ to view it online.")


if __name__ == "__main__":
    main()
