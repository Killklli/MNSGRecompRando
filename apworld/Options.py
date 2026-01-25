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


@dataclass
class MN64Options(PerGameCommonOptions):
    """Options for MN64"""

    enemy_rando: EnemyRando
    starting_room_rando: StartingRoomRando
