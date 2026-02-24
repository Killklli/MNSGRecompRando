#!/usr/bin/env python3
"""
Convert scenario.txt format to C code for MNSG Recomp Rando
"""

import re
import sys
from typing import List, Dict, Tuple

# Character mappings
CHAR_MAP = {
    "a": "CHR_a",
    "b": "CHR_b",
    "c": "CHR_c",
    "d": "CHR_d",
    "e": "CHR_e",
    "f": "CHR_f",
    "g": "CHR_g",
    "h": "CHR_h",
    "i": "CHR_i",
    "j": "CHR_j",
    "k": "CHR_k",
    "l": "CHR_l",
    "m": "CHR_m",
    "n": "CHR_n",
    "o": "CHR_o",
    "p": "CHR_p",
    "q": "CHR_q",
    "r": "CHR_r",
    "s": "CHR_s",
    "t": "CHR_t",
    "u": "CHR_u",
    "v": "CHR_v",
    "w": "CHR_w",
    "x": "CHR_x",
    "y": "CHR_y",
    "z": "CHR_z",
    "A": "CHR_A",
    "B": "CHR_B",
    "C": "CHR_C",
    "D": "CHR_D",
    "E": "CHR_E",
    "F": "CHR_F",
    "G": "CHR_G",
    "H": "CHR_H",
    "I": "CHR_I",
    "J": "CHR_J",
    "K": "CHR_K",
    "L": "CHR_L",
    "M": "CHR_M",
    "N": "CHR_N",
    "O": "CHR_O",
    "P": "CHR_P",
    "Q": "CHR_Q",
    "R": "CHR_R",
    "S": "CHR_S",
    "T": "CHR_T",
    "U": "CHR_U",
    "V": "CHR_V",
    "W": "CHR_W",
    "X": "CHR_X",
    "Y": "CHR_Y",
    "Z": "CHR_Z",
    " ": "PCT_SPACE",
    "!": "PCT_EXCLAMATION",
    '"': "PCT_DOUBLEQUOTE",
    "'": "PCT_APOSTROPHE",
    ",": "PCT_COMMA",
    ".": "PCT_PERIOD",
    ":": "PCT_COLON",
    ";": "PCT_SEMICOLON",
    "?": "PCT_QUESTION",
    "-": "PCT_HYPHEN",
    "(": "PCT_OPENPAREN",
    ")": "PCT_CLOSEPAREN",
    "/": "PCT_SLASH",
}

# Control tag mappings
CONTROL_MAP = {
    "{begin}": "CTR_BEGIN",
    "{end}": "CTR_END",
    "{newline}": "CTR_NEWLINE",
    "{button}": "CTR_BUTTON",
    "{waitinput}": "CTR_WAITINPUT",
    "{newwindow}": "CTR_NEWWINDOW",
    "{em-yellow}": "CTR_EM_YELLOW",
    "{em-red}": "CTR_EM_RED",
    "{em-blue}": "CTR_EM_BLUE",
    "{em-green}": "CTR_EM_GREEN",
    "{/em}": "CTR_CLOSE_EM",
    "{big}": "CTR_BIG",
    "{/big}": "CTR_CLOSE_BIG",
    "{blink}": "CTR_BLINK",
    "{/blink}": "CTR_CLOSE_BLINK",
    "{endline}": "CTR_ENDLINE",
}

# Opcode mappings - based on scenario.h
OPCODE_MAP = {
    "02": "SNE",  # Skip Next If Not Equal
    "03": "SEQ",  # Skip Next If Equal
    "04": "STW",  # Store Word To Address
    "06": "LDW",  # Load Word From Address
    "08": "END",  # End Scenario
    "09": "WTS",  # Word To Store
    "0a": "JMP",  # Jump To Address
    "0b": "ESR",  # Execute Subroutine At Address
    "0c": "SNL",  # Skip Next If Not Less Than
    "10": "TXT",  # Print Text
    "11": "BOS",  # Begin Option Selection
    "12": "EOS",  # End Option Selection
    "13": "INC",  # Increase By Value
    "20": "SFG",  # Set Flag
    "21": "CFG",  # Clear Flag
    "22": "JFS",  # Jump To Address If Flag Set
    "23": "SFL",  # Set Flag Limited
    "30": "SAN",  # Skip Next If Address Not Equal
    "31": "LDF",  # Load Flag
    "32": "JNE",  # Jump If Not Equal
    "33": "CLF",  # Clear Flag Limited
}


def parse_text_to_c(text: str) -> Tuple[List[str], str]:
    """Convert text with {tags} to C array elements"""
    elements = []
    i = 0

    while i < len(text):
        # Check for control tags
        if text[i] == "{":
            end = text.find("}", i)
            if end != -1:
                tag = text[i : end + 1]
                if tag in CONTROL_MAP:
                    elements.append(CONTROL_MAP[tag])
                    i = end + 1
                    continue

        # Regular character
        if text[i] in CHAR_MAP:
            elements.append(CHAR_MAP[text[i]])

        i += 1

    # Add endline if not present
    if not elements or elements[-1] != "CTR_ENDLINE":
        elements.append("CTR_ENDLINE")

    return elements, text


def parse_scenario_file(filename: str) -> Dict:
    """Parse scenario.txt and extract messages and instructions"""
    with open(filename, "r", encoding="utf-8") as f:
        content = f.read()

    # Split by MESSAGE markers
    messages = {}
    current_msg = None
    current_addr = None
    current_instructions = []
    current_texts = {}
    text_counter = 0

    lines = content.split("\n")
    i = 0

    while i < len(lines):
        line = lines[i].strip()

        # MESSAGE header
        if line.startswith("! MESSAGE "):
            if current_addr:
                messages[current_addr] = {"instructions": current_instructions, "texts": current_texts}

            # Parse: ! MESSAGE 226: 069-31f0.31f0
            match = re.match(r"! MESSAGE (\d+): [^.]+\.([0-9a-f]+)", line)
            if match:
                current_msg = match.group(1)
                current_addr = match.group(2)
                current_instructions = []
                current_texts = {}
                text_counter = 0

        # Address label (optional for branching)
        elif line.startswith("@"):
            pass  # We'll handle address labels in instructions

        # Instruction line
        elif re.match(r"^\s*[0-9a-f]+\.\s+[0-9a-f]{2}:", line):
            # Parse: "31f0. 04:8007785c      # Write to RAM 8007785c"
            # or:    "3208. 22:1a,08,@3c30   # If Flag 01a"
            match = re.match(r"^\s*([0-9a-f]+)\.\s+([0-9a-f]{2}):([^#]*)#?\s*(.*)?$", line)
            if match:
                addr, opcode, params_str, comment = match.groups()

                # Parse parameters - remove commas and @signs, split by any delimiter
                params_str = params_str.strip().replace(",", " ").replace("@", "")
                params = []
                if params_str:
                    # Split hex values - could be like "8007785c" or "08 000000"
                    # Handle both continuous hex strings and space-separated
                    for part in params_str.split():
                        if part:
                            # If it's a long hex string, keep it as-is
                            # Otherwise, it's already split
                            params.append(part.lower())

                instruction = {"addr": addr, "opcode": opcode.lower(), "params": params, "comment": comment.strip() if comment else ""}

                current_instructions.append(instruction)

        # Text line
        elif "text:" in line and "|" in line:
            # Extract text between pipes
            match = re.search(r"text:\s*\|([^|]+)\|", line)
            if match:
                text = match.group(1)
                text_id = f"{text_counter:04d}"
                current_texts[text_id] = text
                text_counter += 1

        i += 1

    # Save last message
    if current_addr:
        messages[current_addr] = {"instructions": current_instructions, "texts": current_texts}

    return messages


def generate_c_code(messages: Dict, output_file: str):
    """Generate C code from parsed messages"""

    lines = []
    lines.append('#include "types.h"')
    lines.append('#include "scenario.h"')
    lines.append("")

    # Forward declarations
    lines.append("// Forward declarations")
    for addr in sorted(messages.keys()):
        lines.append(f"s32 scenario_code_{addr}[];")
    lines.append("")

    # Generate text arrays
    lines.append("// ==================== TEXT STRINGS ====================")
    lines.append("")

    all_texts = {}
    text_id_counter = 0
    for addr, msg_data in messages.items():
        for text_id, text in msg_data["texts"].items():
            # Use hex format for text IDs like scenario_text_0000, scenario_text_0014, etc.
            text_name = f"scenario_text_{text_id_counter:04X}"
            all_texts[f"{addr}_{text_id}"] = (text_name, text)
            text_id_counter += len(text) + 20  # Approximate offset increment

    for text_key in sorted(all_texts.keys()):
        text_name, text = all_texts[text_key]
        elements, _ = parse_text_to_c(text)

        lines.append(f"// {text}")
        lines.append(f"static s16 {text_name}[] = {{")

        # Format elements - try to fit nicely but don't force specific width
        if len(elements) <= 12:
            # Short arrays on one line
            lines.append("    " + ", ".join(elements) + "};")
        else:
            # Longer arrays on multiple lines
            current_line = "    "
            for i, elem in enumerate(elements):
                if len(current_line) > 100 or (i > 0 and i % 10 == 0):
                    lines.append(current_line)
                    current_line = "    "
                current_line += elem + ", "
            if current_line.strip():
                # Remove trailing comma and space, then add closing
                current_line = current_line.rstrip(", ") + "};"
                lines.append(current_line)
            else:
                lines.append("};")

        lines.append("")

    # Generate scenario code arrays
    lines.append("// ==================== SCENARIO CODE ====================")
    lines.append("")

    for addr in sorted(messages.keys()):
        msg_data = messages[addr]
        lines.append(f"// Message at @{addr}")
        lines.append(f"s32 scenario_code_{addr}[] = {{")
        lines.append("")

        # Track text index for this message
        text_index = 0

        for inst in msg_data["instructions"]:
            opcode = inst["opcode"]
            params = inst["params"]
            comment = inst["comment"]

            if opcode in OPCODE_MAP:
                macro_name = OPCODE_MAP[opcode]

                if macro_name == "TXT":
                    # TXT - Print text: references text array by name
                    # Find the text array for this instruction
                    text_key = f"{addr}_{text_index:04d}"
                    if text_key in all_texts:
                        text_name, _ = all_texts[text_key]
                        lines.append(f'    // {inst["addr"]}: {comment}')
                        lines.append(f"    TXT,")
                        lines.append(f"    (s32)&{text_name},")
                        lines.append("")
                        text_index += 1
                    else:
                        lines.append(f'    // {inst["addr"]}: {comment}')
                        lines.append(f"    TXT,")
                        lines.append(f'    0x{params[1] if len(params) > 1 else "00000000"},')
                        lines.append("")

                elif macro_name == "JMP":
                    # JMP - Jump to another scenario block
                    target_addr = params[1] if len(params) > 1 else params[0]
                    lines.append(f'    // {inst["addr"]}: {comment}')
                    lines.append(f"    JMP,")
                    lines.append(f"    (s32)&scenario_code_{target_addr},")
                    lines.append("")

                elif macro_name == "JFS":
                    # JFS - Jump if flag set: flag_id, target_address
                    if len(params) >= 3:
                        flag_id = params[0]
                        target_addr = params[2]
                        lines.append(f'    // {inst["addr"]}: {comment}')
                        lines.append(f"    JFS,")
                        lines.append(f"    0x{flag_id},")
                        lines.append(f"    (s32)&scenario_code_{target_addr},")
                        lines.append("")
                    else:
                        lines.append(f'    // {inst["addr"]}: {comment}')
                        lines.append(f"    JFS,")
                        for p in params:
                            lines.append(f"    0x{p},")
                        lines.append("")

                elif macro_name == "END":
                    # END - End scenario
                    lines.append(f'    // {inst["addr"]}: {comment}')
                    lines.append(f"    END,")
                    lines.append("")

                elif macro_name in ["STW", "LDW"]:
                    # STW/LDW - Memory operations with address
                    if len(params) >= 1:
                        addr_val = params[0]
                        lines.append(f'    // {inst["addr"]}: {comment}')
                        lines.append(f"    {macro_name},")
                        lines.append(f"    0x{addr_val},")
                        lines.append("")

                elif macro_name == "WTS":
                    # WTS - Word to store (value)
                    if len(params) >= 1:
                        value = params[0]
                        lines.append(f'    // {inst["addr"]}: {comment}')
                        lines.append(f"    WTS,")
                        lines.append(f"    0x{value},")
                        lines.append("")

                elif macro_name in ["SNE", "SEQ"]:
                    # SNE/SEQ - Skip if (not) equal
                    if len(params) >= 1:
                        value = params[0]
                        lines.append(f'    // {inst["addr"]}: {comment}')
                        lines.append(f"    {macro_name},")
                        lines.append(f"    0x{value},")
                        lines.append("")

                elif macro_name == "ESR":
                    # ESR - Execute subroutine
                    if len(params) >= 1:
                        addr_val = params[0]
                        lines.append(f'    // {inst["addr"]}: {comment}')
                        lines.append(f"    ESR,")
                        lines.append(f"    0x{addr_val},")
                        lines.append("")

                elif macro_name in ["BOS", "EOS"]:
                    # BOS/EOS - Begin/End option selection
                    lines.append(f'    // {inst["addr"]}: {comment}')
                    lines.append(f"    {macro_name},")
                    lines.append("")

                elif macro_name in ["SFG", "CFG", "LDF"]:
                    # Flag operations
                    if len(params) >= 1:
                        flag_id = params[0]
                        lines.append(f'    // {inst["addr"]}: {comment}')
                        lines.append(f"    {macro_name},")
                        lines.append(f"    0x{flag_id},")
                        lines.append("")

                else:
                    # Other opcodes - generic handling
                    lines.append(f'    // {inst["addr"]}: {comment}')
                    lines.append(f"    {macro_name},")
                    for p in params:
                        lines.append(f"    0x{p},")
                    lines.append("")
            else:
                # Unknown opcode - output raw
                lines.append(f'    // {inst["addr"]}: {comment} (UNKNOWN OPCODE)')
                lines.append(f"    0x80{opcode},")
                for p in params:
                    lines.append(f"    0x{p},")
                lines.append("")

        lines.append("};")
        lines.append("")

    # Write to file
    with open(output_file, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))

    print(f"Generated {len(all_texts)} text arrays")
    print(f"Generated {len(messages)} scenario code arrays")
    print(f"Output written to {output_file}")


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python convert_scenario_v2.py <input.txt> <output.c>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    messages = parse_scenario_file(input_file)
    generate_c_code(messages, output_file)
