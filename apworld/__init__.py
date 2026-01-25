"""
Mystical Ninja Starring Goemon (MN64) for Archipelago Multi-World Randomizer
"""

import logging
from typing import Any, ClassVar, Dict, List, Set

from BaseClasses import CollectionState, Entrance, Item, ItemClassification, Location, MultiWorld, Region, Tutorial
from worlds.AutoWorld import WebWorld, World

from .Items import MN64Item, all_item_table, get_item_name_to_id
from .Locations import get_location_name_to_id
from .Logic.mn64_logic_classes import MN64DoorType, MN64HintRegion, MN64Items, MN64Levels
from .Logic.mn64_logic_holder import MN64LogicHolder

logger = logging.getLogger("Mystical Ninja 64")


class MN64Location(Location):
    """Location class for MN64."""

    game: str = "Mystical Ninja Starring Goemon"


class MN64Web(WebWorld):
    """Web world configuration for MN64."""

    theme = "partyTime"

    tutorials = [
        Tutorial(
            "Multiworld Setup Guide",
            "A guide to setting up Mystical Ninja Starring Goemon for Archipelago.",
            "English",
            "setup_en.md",
            "setup/en",
            ["Killklli", "littlecube_hax", "klorfmorf", "abyssonym", "Umed"],
        )
    ]


class MN64World(World):
    """
    Mystical Ninja Starring Goemon is a 3D action-adventure game for the Nintendo 64.
    Play as Goemon and his friends as they travel across Japan to stop the evil Mangamore Corps
    from turning Japan into a giant stage. Explore towns, dungeons, and pilot giant robots!
    """

    game = "Mystical Ninja Starring Goemon"
    web = MN64Web()

    data_version = 1

    # Item and location mappings
    item_name_to_id = get_item_name_to_id()
    location_name_to_id = get_location_name_to_id()

    # Required client version
    required_client_version = (0, 5, 0)

    # Store location metadata for client
    location_metadata: Dict[str, Dict[str, Any]]
    item_metadata: Dict[str, Dict[str, Any]]

    def _populate_item_metadata(self) -> None:
        """Populate item_metadata with all items from the item table."""
        for item_name, item_data in all_item_table.items():
            # Skip event items that don't have AP IDs
            if item_data.id is None:
                continue

            # Use AP ID as the key
            ap_id = item_data.id
            self.item_metadata[ap_id] = {}

            # Add item name as description
            self.item_metadata[ap_id]["name"] = item_name

            # Add save ID if it exists
            if item_data.save_id is not None:
                self.item_metadata[ap_id]["save_id"] = item_data.save_id

            # Add entity ID if it exists
            if item_data.entity_id is not None:
                self.item_metadata[ap_id]["entity_id"] = item_data.entity_id

            # Add classification
            self.item_metadata[ap_id]["classification"] = item_data.classification.name

            # Add quantity
            self.item_metadata[ap_id]["qty"] = item_data.qty

    def create_regions(self) -> None:
        """Create all regions for MN64."""
        # Menu region (required)
        menu = Region("Menu", self.player, self.multiworld)
        self.multiworld.regions.append(menu)

        # Import all region logic definitions
        from .Logic import (
            mn64_bizen,
            mn64_festival_temple_castle,
            mn64_folypoke_village,
            mn64_ghost_toys_castle,
            mn64_gorgeous_music_castle,
            mn64_gourmet_submarine,
            mn64_iyo,
            mn64_kai,
            mn64_musashi,
            mn64_mutsu,
            mn64_oedo_castle,
            mn64_oedo_town,
            mn64_sanuki,
            mn64_tosa,
            mn64_yamamoto,
            mn64_zazen_town,
        )

        # Collect all region definitions
        all_regions = {}
        all_regions.update(mn64_oedo_town.LogicRegions)
        all_regions.update(mn64_zazen_town.LogicRegions)
        all_regions.update(mn64_musashi.LogicRegions)
        all_regions.update(mn64_mutsu.LogicRegions)
        all_regions.update(mn64_yamamoto.LogicRegions)
        all_regions.update(mn64_sanuki.LogicRegions)
        all_regions.update(mn64_folypoke_village.LogicRegions)
        all_regions.update(mn64_tosa.LogicRegions)
        all_regions.update(mn64_iyo.LogicRegions)
        all_regions.update(mn64_kai.LogicRegions)
        all_regions.update(mn64_bizen.LogicRegions)
        all_regions.update(mn64_oedo_castle.LogicRegions)
        all_regions.update(mn64_ghost_toys_castle.LogicRegions)
        all_regions.update(mn64_festival_temple_castle.LogicRegions)
        all_regions.update(mn64_gorgeous_music_castle.LogicRegions)
        all_regions.update(mn64_gourmet_submarine.LogicRegions)

        # Event items are progression flags, not collectible items
        event_item_names = {
            MN64Items.CRANE_GAME_POWER_ON.value,
            MN64Items.VISITED_WITCH.value,
            MN64Items.VISITED_GHOST_TOYS_ENTRANCE.value,
            MN64Items.beat_tsurami.value,
            MN64Items.BEAT_THAISAMBDA.value,
            MN64Items.BEAT_DHARUMANYO.value,
            MN64Items.BEAT_CONGO.value,
            MN64Items.BEAT_GAME_DIE_HARD_FANS.value,
            MN64Items.CUCUMBER_QUEST_PRIEST.value,
            MN64Items.CUCUMBER_QUEST_START.value,
            MN64Items.KUYSHU_FLY.value,
            MN64Items.SASUKE_DEAD.value,
            MN64Items.MOVING_BOULDER_IN_FOREST.value,
            MN64Items.MOKUBEI_BROTHER.value,
            "Sasuke Battery 2 Event",
        }

        # Items that should stay at their vanilla locations
        vanilla_item_names = {
            MN64Items.MIRACLE_STAR.value,
            MN64Items.MIRACLE_SNOW.value,
            MN64Items.MIRACLE_MOON.value,
            MN64Items.MIRACLE_FLOWER.value,
            # MN64Items.GOLDEN_HEALTH.value,
            # MN64Items.NORMAL_HEALTH.value,
        }

        # Create all regions and their locations
        all_location_names = []
        self.location_metadata = {}
        self.item_metadata = {}

        # Populate item_metadata with all items from the item table
        self._populate_item_metadata()

        for region_name, region_data in all_regions.items():
            region = Region(region_name, self.player, self.multiworld)

            # Add locations to region with unique names
            location_counter = {}  # Track duplicate names within same region
            for location_logic in region_data.locations:
                # Create unique location name using internal region name (without spaces)
                base_name = location_logic.name
                item_name = location_logic.item_type.value

                # Check if this location name was already used in this region
                if base_name in location_counter:
                    location_counter[base_name] += 1
                    unique_name = f"{region_name} - {base_name} {location_counter[base_name]}"
                else:
                    location_counter[base_name] = 1
                    unique_name = f"{region_name} - {base_name}"

                all_location_names.append(unique_name)

                # Event locations have address None
                # Use internal region name to find the location ID in Locations.py
                location_id = None if item_name in event_item_names else self.location_name_to_id.get(unique_name, None)

                location = MN64Location(self.player, unique_name, location_id, region)

                # Store metadata for this location
                location_meta = {}
                if location_id is not None:
                    location_meta["ap_location_id"] = location_id
                if hasattr(location_logic, "flag_id") and location_logic.flag_id is not None:
                    location_meta["flag_id"] = location_logic.flag_id
                if hasattr(location_logic, "instance_id") and location_logic.instance_id is not None:
                    location_meta["instance_id"] = location_logic.instance_id
                if hasattr(region_data, "room_id") and region_data.room_id is not None:
                    location_meta["room_id"] = region_data.room_id

                # Store the original item that was at this location
                location_meta["original_item"] = item_name
                # Store the unique location name for reference
                location_meta["location_name"] = unique_name

                if location_meta and hasattr(region_data, "room_id") and region_data.room_id is not None:
                    # Use room_id as key, but handle multiple locations per room
                    room_id = region_data.room_id
                    if room_id not in self.location_metadata:
                        self.location_metadata[room_id] = []
                    self.location_metadata[room_id].append(location_meta)

                # Place event items on event locations immediately
                if item_name in event_item_names:
                    event_item = MN64Item(item_name, ItemClassification.progression, None, self.player)
                    location.place_locked_item(event_item)
                # Place vanilla items (miracles and health) at their vanilla locations
                elif item_name in vanilla_item_names:
                    vanilla_item = MN64Item(item_name, ItemClassification.progression, all_item_table[item_name].id, self.player)
                    location.place_locked_item(vanilla_item)

                region.locations.append(location)

            self.multiworld.regions.append(region)

        # Print all location names
        # print("\n=== All MN64 Location Names ===")
        # print(f"Total locations: {len(all_location_names)}")
        # for i, location_name in enumerate(all_location_names, 1):
        #     print(f"{i:3}. {location_name}")
        # print("=" * 50 + "\n")

        # Create entrances between regions
        for region_name, region_data in all_regions.items():
            region = self.multiworld.get_region(region_name, self.player)

            for exit_logic in region_data.exits:
                # Check if destination region exists before creating entrance
                try:
                    destination = self.multiworld.get_region(exit_logic.destinationRegion, self.player)
                except KeyError:
                    # Destination region doesn't exist, skip this entrance
                    logger.warning(f"Region {exit_logic.destinationRegion} not found for entrance from {region_name}")
                    continue

                entrance = Entrance(self.player, f"{region_name} -> {exit_logic.destinationRegion}", region)
                region.exits.append(entrance)
                entrance.connect(destination)

        # Connect Menu to starting region (Oedo Town or GoemonsHouse)
        # Randomly select a starting region.
        possible_regions = [
            "GoemonsHouse",
            "ZazenTownEntrance",
            "FestivalVillageEntrance",
            "KaisCoffeeShop",
            "IyoCoffeeShop",
            "IzumoCoffeeShop",
            "KompurasCoffeeShop",
            "KiisCoffeeShop",
        ]
        # Choose one based on multiworld random
        starting_region_name = self.random.choice(possible_regions)
        self.starting_region_name = starting_region_name  # Store for slot data

        # Store the room_id for the starting region
        starting_region_data = all_regions.get(starting_region_name)
        self.starting_room_id = getattr(starting_region_data, "room_id", None) if starting_region_data else None
        try:
            menu = self.multiworld.get_region("Menu", self.player)
            starting_region = self.multiworld.get_region(starting_region_name, self.player)
            menu_entrance = Entrance(self.player, "Start Game", menu)
            menu.exits.append(menu_entrance)
            menu_entrance.connect(starting_region)
        except KeyError:
            logger.warning(f"Could not find starting region {starting_region_name}")

    def create_items(self) -> None:
        """Create all items for the multiworld."""
        pool = []

        # Items that are placed at vanilla locations (not randomized)
        vanilla_item_names = {
            "Miracle Star",
            "Miracle Snow",
            "Miracle Moon",
            "Miracle Flower",
            # "Golden Health",
            # "Normal Health",
        }

        # Characters that can start the game
        character_names = ["Goemon", "Ebismaru", "Yae", "Sasuke"]

        # Randomly select one character to start with
        starting_character = self.random.choice(character_names)

        # Create items based on Items.py definitions (respecting qty field)
        for item_name, item_data in all_item_table.items():
            # Skip event items - they don't go in the item pool
            if item_data.id is None:
                continue

            # Skip vanilla items - they are placed at vanilla locations during region creation
            if item_name in vanilla_item_names:
                continue

            # Skip the starting character - they'll be added to the precollected pool
            if item_name == starting_character:
                continue

            # Triton Horn is forced start currently
            if item_name == MN64Items.TRITON_HORN.value:
                continue

            # Create qty number of this item
            for _ in range(item_data.qty):
                pool.append(self.create_item(item_name))

        for _ in range(6):
            pool.append(self.create_item("Suprise Pack"))

        # Add items to the multiworld
        self.multiworld.itempool += pool

        # Add the starting character to precollected items
        self.multiworld.push_precollected(self.create_item(starting_character))
        self.multiworld.push_precollected(self.create_item(MN64Items.TRITON_HORN.value))

    def create_item(self, name: str) -> Item:
        """Create an item by name."""
        item_data = all_item_table.get(name)
        if item_data is None:
            raise ValueError(f"Item {name} is not a valid MN64 item")

        return MN64Item(name, item_data.classification, item_data.id, self.player)

    def set_rules(self) -> None:
        """Set access rules for regions and locations."""
        from .Rules import set_rules

        set_rules(self)

        # Set completion condition - player must defeat all bosses
        self.multiworld.completion_condition[self.player] = lambda state: (
            # state.has("Beat Congo", self.player) and
            # state.has("Beat Dharumanyo", self.player) and
            # state.has("Beat Tsurami", self.player) and
            # state.has("Beat Thaisambda", self.player) and
            state.has("Beat Game Die Hard Fans", self.player)
        )

    def post_fill(self):
        # Update location metadata with the actual items placed at each location
        for location in self.multiworld.get_locations(self.player):
            # Find the location in our room-based metadata structure
            for room_id, location_list in self.location_metadata.items():
                for location_meta in location_list:
                    if location_meta["location_name"] == location.name:
                        if location.item:
                            location_meta["new_item"] = location.item.name
                            # Also include the new item's AP ID if it has one
                            if hasattr(location.item, "code") and location.item.code is not None:
                                location_meta["new_item_ap_id"] = location.item.code
                        else:
                            location_meta["new_item"] = None
                        break

        all_enemies = [
            0x0FB,
            0x0FC,
            0x0FD,
            0x100,
            0x103,
            0x12C,
            0x12D,
            0x130,
            0x0FF,
            0x104,
            0x106,
            0x132,
            0x133,
            0x145,
            0x148,
            0x105,
            0x10C,
            0x13C,
            0x13D,
            0x13F,
            0x147,
            0x13E,
            0x140,
            0x141,
            0x190,
            0x108,
            0x109,
            0x10A,
            0x10B,
            0x12E,
            0x12F,
            0x144,
        ]
        RESTRICTED_ENEMIES = {0x106, 0x10C, 0x133, 0x13A, 0x13C, 0x13D, 0x13E, 0x144}
        RESTRICTED_ENEMY_ROOMS = {0, 0x87}

        # Initialize enemy data storage for slot data
        self.randomized_enemy_data = {}

        # Import all region logic definitions
        from .Logic import (
            mn64_bizen,
            mn64_festival_temple_castle,
            mn64_folypoke_village,
            mn64_ghost_toys_castle,
            mn64_gorgeous_music_castle,
            mn64_gourmet_submarine,
            mn64_iyo,
            mn64_kai,
            mn64_musashi,
            mn64_mutsu,
            mn64_oedo_castle,
            mn64_oedo_town,
            mn64_sanuki,
            mn64_tosa,
            mn64_yamamoto,
            mn64_zazen_town,
        )

        # Collect all region definitions
        all_regions = {}
        all_regions.update(mn64_oedo_town.LogicRegions)
        all_regions.update(mn64_zazen_town.LogicRegions)
        all_regions.update(mn64_musashi.LogicRegions)
        all_regions.update(mn64_mutsu.LogicRegions)
        all_regions.update(mn64_yamamoto.LogicRegions)
        all_regions.update(mn64_sanuki.LogicRegions)
        all_regions.update(mn64_folypoke_village.LogicRegions)
        all_regions.update(mn64_tosa.LogicRegions)
        all_regions.update(mn64_iyo.LogicRegions)
        all_regions.update(mn64_kai.LogicRegions)
        all_regions.update(mn64_bizen.LogicRegions)
        all_regions.update(mn64_oedo_castle.LogicRegions)
        all_regions.update(mn64_ghost_toys_castle.LogicRegions)
        all_regions.update(mn64_festival_temple_castle.LogicRegions)
        all_regions.update(mn64_gorgeous_music_castle.LogicRegions)
        all_regions.update(mn64_gourmet_submarine.LogicRegions)

        # Randomize enemies in each room with memory constraints
        for region_name, region_data in all_regions.items():
            # Check if this region has a room with enemies
            if hasattr(region_data, "enemies") and region_data.enemies and hasattr(region_data, "room_id"):
                room_id = region_data.room_id

                # Initialize storage for this room's enemy data
                if room_id not in self.randomized_enemy_data:
                    self.randomized_enemy_data[room_id] = {}

                # Function to calculate room memory with current enemy setup
                def calculate_room_memory_with_enemies(enemy_config):
                    from .file_memory_sizes import ENEMY_FILES, MINIMUM_SAFE_BUDGET, PICKUP_FILES, entities_dict, file_sizes
                    from .Items import all_item_table

                    # Use a list to preserve order, but track what's been added to avoid duplicates
                    current_files_list = list(region_data.room_default_definitions)
                    current_files_set = set(current_files_list)

                    # Add files for randomized items in this room
                    if hasattr(region_data, "locations"):
                        for location_logic in region_data.locations:
                            # Find the multiworld location that matches this logic location
                            for multiworld_location in self.multiworld.get_locations(self.player):
                                if hasattr(multiworld_location, "name") and multiworld_location.name.endswith(f" - {location_logic.name}") and multiworld_location.item:

                                    item_name = multiworld_location.item.name
                                    item_data = all_item_table.get(item_name)
                                    if item_data and hasattr(item_data, "entity_id") and item_data.entity_id is not None:
                                        entity_id = item_data.entity_id
                                        if entity_id in entities_dict:
                                            file_id = entities_dict[entity_id][0]  # Extract file ID from entity mapping
                                            if file_id not in current_files_set:
                                                current_files_list.append(file_id)
                                                current_files_set.add(file_id)
                                    break

                    # Add files for enemies
                    for enemy_id in enemy_config.values():
                        if enemy_id in entities_dict:
                            file_id = entities_dict[enemy_id][0]  # Extract file ID from entity mapping
                            if file_id not in current_files_set:
                                current_files_list.append(file_id)
                                current_files_set.add(file_id)

                    # Remove unused pickup files
                    used_pickup_files = set()
                    if hasattr(region_data, "locations"):
                        for location_logic in region_data.locations:
                            for multiworld_location in self.multiworld.get_locations(self.player):
                                if hasattr(multiworld_location, "name") and multiworld_location.name.endswith(f" - {location_logic.name}") and multiworld_location.item:

                                    item_name = multiworld_location.item.name
                                    item_data = all_item_table.get(item_name)
                                    if item_data and hasattr(item_data, "entity_id") and item_data.entity_id is not None:
                                        entity_id = item_data.entity_id
                                        if entity_id in entities_dict:
                                            file_id = entities_dict[entity_id][0]  # Extract file ID from entity mapping
                                            if file_id in PICKUP_FILES:
                                                used_pickup_files.add(file_id)
                                    break

                    # for pickup_file in PICKUP_FILES:
                    #     # Never remove 0x2B, but other pickup files can be removed if unused
                    #     if (
                    #         pickup_file != 0x02B
                    #         and pickup_file not in used_pickup_files
                    #         and pickup_file in current_files_set
                    #     ):
                    #         current_files_list.remove(pickup_file)
                    #         # current_files_set.discard(pickup_file)

                    # Remove unused enemy files
                    used_enemy_files = set()
                    for enemy_id in enemy_config.values():
                        if enemy_id in entities_dict:
                            file_id = entities_dict[enemy_id][0]  # Extract file ID from entity mapping
                            if file_id in ENEMY_FILES:
                                used_enemy_files.add(file_id)

                    # for enemy_file in ENEMY_FILES:
                    #     if enemy_file not in used_enemy_files and enemy_file in current_files_set:
                    #         current_files_list.remove(enemy_file)
                    #         current_files_set.discard(enemy_file)

                    # Calculate total size
                    total_size = 0
                    for file_id in current_files_list:
                        if file_id in file_sizes:
                            total_size += file_sizes[file_id]

                    return current_files_list, total_size, total_size <= MINIMUM_SAFE_BUDGET

                # Try normal enemy randomization first
                max_attempts = 5
                attempt = 0
                success = False
                current_enemy_pool = all_enemies.copy()

                # If this room is in RESTRICTED_ENEMY_ROOMS, exclude restricted enemies
                if room_id in RESTRICTED_ENEMY_ROOMS:
                    current_enemy_pool = [e for e in current_enemy_pool if e not in RESTRICTED_ENEMIES]

                while not success and attempt < max_attempts:
                    attempt += 1
                    temp_enemy_config = {}

                    # Limit to maximum 5 enemy types per room for memory safety
                    # Get all randomizable enemies in this room
                    randomizable_enemies = [enemy_id for enemy_id in region_data.enemies.values() if enemy_id in all_enemies]
                    non_randomizable_enemies = [enemy_id for enemy_id in region_data.enemies.values() if enemy_id not in all_enemies]

                    # Select at most 5 unique enemy types from the pool
                    max_enemy_types = 3
                    num_types_to_select = min(max_enemy_types, len(current_enemy_pool))

                    # First, select random enemy types
                    selected_enemy_types = self.random.sample(current_enemy_pool, num_types_to_select)

                    # Check how many enemy files this would require
                    from .file_memory_sizes import ENEMY_FILES, entities_dict

                    required_enemy_files = set()
                    for enemy_id in selected_enemy_types:
                        if enemy_id in entities_dict:
                            file_id = entities_dict[enemy_id][0]
                            if file_id in ENEMY_FILES:
                                required_enemy_files.add(file_id)

                    # If we have more than 3 enemy files, optimize to use fewer files
                    if len(required_enemy_files) > 3:
                        # Group enemies by their file
                        enemies_by_file = {}
                        for enemy_id in current_enemy_pool:
                            if enemy_id in entities_dict:
                                file_id = entities_dict[enemy_id][0]
                                if file_id in ENEMY_FILES:
                                    if file_id not in enemies_by_file:
                                        enemies_by_file[file_id] = []
                                    enemies_by_file[file_id].append(enemy_id)

                        # Select up to 3 enemy files and pick enemies from those files
                        selected_files = self.random.sample(list(enemies_by_file.keys()), min(3, len(enemies_by_file)))
                        selected_enemy_types = []

                        for file_id in selected_files:
                            available_enemies = enemies_by_file[file_id]
                            # Pick 1-2 enemies from each file to reach our target count
                            enemies_from_this_file = min(2, len(available_enemies), max_enemy_types - len(selected_enemy_types))
                            if enemies_from_this_file > 0:
                                selected_enemy_types.extend(self.random.sample(available_enemies, enemies_from_this_file))

                        # If we still need more types and have room, add from any file
                        if len(selected_enemy_types) < max_enemy_types:
                            remaining_enemies = [e for e in current_enemy_pool if e not in selected_enemy_types]
                            additional_needed = min(max_enemy_types - len(selected_enemy_types), len(remaining_enemies))
                            if additional_needed > 0:
                                selected_enemy_types.extend(self.random.sample(remaining_enemies, additional_needed))

                    # Assign selected enemy types to randomizable slots
                    for instance_id, enemy_id in list(region_data.enemies.items()):
                        if enemy_id in all_enemies:
                            # Use one of the selected types (random choice from the limited set)
                            new_enemy_id = self.random.choice(selected_enemy_types)
                            temp_enemy_config[instance_id] = new_enemy_id
                        else:
                            temp_enemy_config[instance_id] = enemy_id

                    # Test memory with this enemy configuration
                    current_files, total_size, under_budget = calculate_room_memory_with_enemies(temp_enemy_config)

                    if under_budget:
                        # Success! Apply this configuration
                        for instance_id, enemy_id in temp_enemy_config.items():
                            region_data.enemies[instance_id] = enemy_id
                            self.randomized_enemy_data[room_id][instance_id] = enemy_id

                        # Update room default definitions
                        region_data.room_default_definitions = current_files
                        success = True

                if not success:
                    # Apply extreme memory reduction for any room that fails memory limits
                    from .file_memory_sizes import ENEMY_FILES, MINIMUM_SAFE_BUDGET, entities_dict, file_sizes

                    # Save original for reference
                    original_definitions = list(region_data.room_default_definitions)

                    # Identify essential non-enemy files under 50KB
                    essential_files = []
                    for file_id in original_definitions:
                        if file_id not in ENEMY_FILES:
                            file_size = file_sizes.get(file_id, 0)
                            if file_size < 50000:  # Only files under 50KB
                                essential_files.append(file_id)

                    # Remove duplicates
                    essential_files = list(set(essential_files))

                    # Find the smallest enemy available
                    smallest_enemy = None
                    smallest_size = float("inf")

                    for enemy_id in all_enemies:
                        if enemy_id not in RESTRICTED_ENEMIES and enemy_id in entities_dict:
                            file_id = entities_dict[enemy_id][0]
                            size = file_sizes.get(file_id, 0)
                            if size < smallest_size:
                                smallest_size = size
                                smallest_enemy = enemy_id

                    if smallest_enemy:
                        # Use the smallest enemy for all slots
                        minimal_config = {}
                        for instance_id, enemy_id in list(region_data.enemies.items()):
                            minimal_config[instance_id] = smallest_enemy

                        # Test with minimal files + smallest enemy
                        region_data.room_default_definitions = essential_files
                        current_files, total_size, under_budget = calculate_room_memory_with_enemies(minimal_config)

                        if under_budget:
                            for instance_id, enemy_id in minimal_config.items():
                                region_data.enemies[instance_id] = enemy_id
                                self.randomized_enemy_data[room_id][instance_id] = enemy_id

                            region_data.room_default_definitions = current_files
                            success = True
                        else:
                            # Even more extreme - use only smallest files
                            file_sizes_sorted = [(f, file_sizes.get(f, 0)) for f in essential_files]
                            file_sizes_sorted.sort(key=lambda x: x[1])

                            # Take only smallest 50% of files
                            minimal_files = [f[0] for f in file_sizes_sorted[: max(1, len(file_sizes_sorted) // 2)]]

                            region_data.room_default_definitions = minimal_files
                            current_files, total_size, under_budget = calculate_room_memory_with_enemies(minimal_config)

                            if under_budget:
                                for instance_id, enemy_id in minimal_config.items():
                                    region_data.enemies[instance_id] = enemy_id
                                    self.randomized_enemy_data[room_id][instance_id] = enemy_id

                                region_data.room_default_definitions = current_files
                                success = True

                    # If still failing, restore original for error
                    if not success:
                        region_data.room_default_definitions = original_definitions

                if not success:
                    from .file_memory_sizes import MINIMUM_SAFE_BUDGET

                    # Print the files that this room is trying to load
                    final_files_hex = [hex(file_id) for file_id in current_files]
                    raise RuntimeError(
                        f"Room {hex(room_id)} in region '{region_name}' exceeds memory budget even with single enemy type! "
                        f"Final size: {total_size} bytes, Budget limit: {MINIMUM_SAFE_BUDGET} bytes, "
                        f"Overage: {total_size - MINIMUM_SAFE_BUDGET} bytes. "
                        f"Final enemy pool size: {len(current_enemy_pool)}. "
                        f"Room ID: {hex(room_id)}, Files being loaded: {' '.join(final_files_hex)}"
                    )

        # Update room default definitions for rooms without enemies
        from .file_memory_sizes import update_room_default_definitions_post_fill
        from .Items import all_item_table

        self.room_file_data = update_room_default_definitions_post_fill(
            all_regions,
            self.multiworld.get_locations(self.player),
            self.randomized_enemy_data,
            all_item_table,
            all_enemies,
            RESTRICTED_ENEMIES,
            RESTRICTED_ENEMY_ROOMS,
            self.random,
        )

    def fill_slot_data(self) -> Dict[str, Any]:
        """Fill slot data to be sent to the client."""
        # Convert enemy data integer keys to strings for JSON serialization consistency
        enemy_data_with_string_keys = {}
        for room_id, room_enemies in getattr(self, "randomized_enemy_data", {}).items():
            room_key = str(room_id)
            enemy_data_with_string_keys[room_key] = {}
            for instance_id, enemy_id in room_enemies.items():
                instance_key = str(instance_id)
                enemy_data_with_string_keys[room_key][instance_key] = enemy_id
        # print(self.room_file_data)
        # import time
        # time.sleep(10)
        # Determine starting characters
        character_names = ["Goemon", "Yae", "Ebismaru", "Sasuke"]
        starting_characters = {}

        # Check which characters are precollected (starting inventory)
        precollected_character_names = {item.name for item in self.multiworld.precollected_items[self.player] if item.name in character_names}
        # print("Precollected characters:", precollected_character_names) case sensitivity

        # Mark each character as available or not at start
        for character in character_names:
            starting_characters[character.lower()] = character in precollected_character_names

        # Collect all starting/precollected items
        starting_items = []
        for item in self.multiworld.precollected_items[self.player]:
            item_info = {"name": item.name, "ap_id": item.code if hasattr(item, "code") else None}
            # Add additional metadata if available in item_metadata
            if hasattr(item, "code") and item.code and item.code in self.item_metadata:
                item_meta = self.item_metadata[item.code]
                if "save_id" in item_meta:
                    item_info["save_id"] = item_meta["save_id"]
                if "entity_id" in item_meta:
                    item_info["entity_id"] = item_meta["entity_id"]
                if "qty" in item_meta:
                    item_info["qty"] = item_meta["qty"]
            starting_items.append(item_info)

        room_data = getattr(self, "room_file_data", {})
        # Recreate it so its just a dict of the id and then the list of files
        room_data_simple = {room_id: data["files"] for room_id, data in room_data.items() if room_id is not None}

        # Create flag_id to ap_location_id mapping
        flag_id_to_ap_location_id = {}
        for room_id, location_list in self.location_metadata.items():
            for location_data in location_list:
                if "flag_id" in location_data and "ap_location_id" in location_data:
                    flag_id = location_data["flag_id"]
                    ap_location_id = location_data["ap_location_id"]
                    # Convert flag_id hex to decimal string
                    flag_id_str = str(flag_id)
                    flag_id_to_ap_location_id[flag_id_str] = ap_location_id
        slot_data = {
            "seed": self.multiworld.seed,
            "location_metadata": self.location_metadata,
            "item_metadata": self.item_metadata,
            "enemy_data": getattr(self, "randomized_enemy_data", {}),
            "room_file_data": room_data_simple,
            "starting_room": getattr(self, "starting_room_id", None),
            "starting_characters": starting_characters,
            "starting_items": starting_items,
            "flag_id_to_ap_location_id": flag_id_to_ap_location_id,
        }

        return slot_data
