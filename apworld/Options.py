"""Options for MN64."""

import numbers
import typing
from dataclasses import dataclass
from typing import List

from BaseClasses import PlandoOptions
from worlds.AutoWorld import World

from Options import Choice, DeathLink, DefaultOnToggle, Option, OptionDict, OptionError, OptionGroup, OptionList, PerGameCommonOptions, Range, TextChoice, Toggle


class StartingRoomRando(Toggle):
    """Determines if the starting spawn is randomized."""

    display_name = "Starting Room Rando"


class EnemyRando(Toggle):
    """Determines if enemies are randomized."""

    display_name = "Enemy Rando"

class IncreasedPotRyo(Toggle):
    """Determines if pots have an increased amount of ryo."""

    display_name = "Increase Pot Ryo"


class HealthInPool(Toggle):
    """Determines if Health Items are added into the pool."""

    display_name = "Health In Pool"


class PreventOneWaySoftlocks(DefaultOnToggle):
    """Entrances that are normally one-way are now two-way."""

    display_name = "Prevent One-Way Softlocks"


@dataclass
class MN64Options(PerGameCommonOptions):
    """Options for MN64"""

    enemy_rando: EnemyRando
    starting_room_rando: StartingRoomRando
    increase_pot_ryo: IncreasedPotRyo
    randomize_health: HealthInPool
    prevent_oneway_softlocks: PreventOneWaySoftlocks
