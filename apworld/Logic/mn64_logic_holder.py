"""Logic holder class that maintains the state of all logic conditions for MN64."""

from typing import Any, Dict


class MN64LogicHolder:
    """
    Logic holder class that retains the state of all logic conditions used in lambda functions.

    This class is passed to all lambda functions defined in the logic files (e.g., for medal_of_flames).    It maintains the current state of all items, abilities, flags, and conditions that determine
    accessibility in the game logic.
    """

    def __init__(self) -> None:
        """Initialize all logic properties to False by default."""
        # Items and Keys (now using counts instead of booleans)
        self.silver_key_count: int = 0
        self.gold_key_count: int = 0
        self.diamond_key_count: int = 0
        self.jump_gym_key: bool = False  # This one stays boolean as it's a special key

        # Equipment and Tools
        self.windup_camera: bool = False
        self.chain_pipe: bool = False
        self.ice_kunai: bool = False
        self.medal_of_flames: bool = False
        self.bazooka: bool = False
        self.bombs: bool = False
        self.flute: bool = False
        self.meat_hammer: bool = False

        # Characters and Abilities
        self.mermaid: bool = False
        self.mini_ebismaru: bool = False
        self.sudden_impact: bool = False
        self.jetpack: bool = False

        self.goemon: bool = False
        self.yae: bool = False
        self.ebismaru: bool = False
        self.sasuke: bool = False

        # Game Progression Flags
        self.beat_tsurami: bool = False
        self.congo_defeated: bool = False
        self.ghost_toys_defeated: bool = False
        self.beat_thaisambda: bool = False

        # Crane Game Related
        self.power_on_crane_game: bool = False

        # Character Specific Items/Batteries
        self.sasuke_battery_1: bool = False
        self.sasuke_battery_2: bool = False
        self.sasuke_dead: bool = False

        # Transportation and Access
        self.superpass: bool = False

        # Quest and Event States
        self.event_cucumber_quest_need_key: bool = False
        self.requires_visiting_ghost_toys_entrance_ebismaru: bool = False
        self.moving_boulder_in_forest: bool = False
        self.visited_witch: bool = False
        self.kyushu_fly: bool = False
        # self.fish_quest: bool = False
        self.cucumber: bool = False
        self.triton_horn: bool = False
        self.event_cucumber_quest_find_priest: bool = False
        self.mokubei_brother: bool = False

        # Character Interactions and Story Flags
        self.omitsu_talked: bool = False
        self.strength_upgrade_1: bool = False
        self.strength_upgrade_2: bool = False  # Special Items and Conditions
        self.all_miracle_items: bool = False
        self.achilles_heel: bool = False

        # Item Counters
        self.silver_fortune_doll_count: int = 0
        self.gold_fortune_doll_count: int = 0
        self.golden_health_count: int = 0
        self.normal_health_count: int = 0

    # Key management methods
    def has_silver_key(self) -> bool:
        """Check if we have at least one silver key."""
        return self.silver_key_count > 0

    def has_gold_key(self) -> bool:
        """Check if we have at least one gold key."""
        return self.gold_key_count > 0

    def has_diamond_key(self) -> bool:
        """Check if we have at least one diamond key."""
        return self.diamond_key_count > 0

    def use_silver_key(self) -> bool:
        """Use a silver key if available. Returns True if used successfully."""
        if self.silver_key_count > 0:
            self.silver_key_count -= 1
            return True
        return False

    def use_gold_key(self) -> bool:
        """Use a gold key if available. Returns True if used successfully."""
        if self.gold_key_count > 0:
            self.gold_key_count -= 1
            return True
        return False

    def use_diamond_key(self) -> bool:
        """Use a diamond key if available. Returns True if used successfully."""
        if self.diamond_key_count > 0:
            self.diamond_key_count -= 1
            return True
        return False

    def add_silver_key(self):
        """Add a silver key to inventory."""
        self.silver_key_count += 1

    def add_gold_key(self):
        """Add a gold key to inventory."""
        self.gold_key_count += 1

    def add_diamond_key(self):
        """Add a diamond key to inventory."""
        self.diamond_key_count += 1

    def set_state(self, property_name: str, value: bool) -> None:
        """
        Set the state of a specific property.

        Args:
            property_name: The name of the property to set
            value: The boolean value to set
        """
        if hasattr(self, property_name):
            setattr(self, property_name, value)
        else:
            raise ValueError(f"Property '{property_name}' does not exist in MN64LogicHolder")

    def get_state(self, property_name: str) -> bool:
        """
        Get the state of a specific property.

        Args:
            property_name: The name of the property to get

        Returns:
            The boolean value of the property
        """
        if hasattr(self, property_name):
            return getattr(self, property_name)
        else:
            raise ValueError(f"Property '{property_name}' does not exist in MN64LogicHolder")

    def get_all_states(self) -> Dict[str, bool]:
        """
        Get all property states as a dictionary.

        Returns:
            Dictionary mapping property names to their boolean values
        """
        return {attr: getattr(self, attr) for attr in dir(self) if not attr.startswith("_") and not callable(getattr(self, attr))}

    def set_multiple_states(self, states: Dict[str, bool]) -> None:
        """
        Set multiple property states at once.

        Args:
            states: Dictionary mapping property names to boolean values
        """
        for property_name, value in states.items():
            self.set_state(property_name, value)

    def reset_all(self) -> None:
        """Reset all properties to False."""
        for attr in dir(self):
            if not attr.startswith("_") and not callable(getattr(self, attr)):
                setattr(self, attr, False)

    def __repr__(self) -> str:
        """String representation showing current state of all properties."""
        states = self.get_all_states()
        true_states = [name for name, value in states.items() if value]
        return f"MN64LogicHolder(active_states={true_states})"
