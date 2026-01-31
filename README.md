# Mystical Ninja Starring Goemon Randomizer (Archipelago)

This is a randomizer for Mystical Ninja Starring Goemon (N64) that integrates with the [Archipelago multiworld randomizer](https://archipelago.gg/). This randomizer shuffles items, equipment, abilities, and other game elements across multiple worlds and players in a connected multiworld session.

## What is Archipelago?

Archipelago is a multiworld randomizer framework that allows you to play randomized games with friends across different titles. Items from your game can end up in other players' worlds, and vice versa, creating a collaborative randomizer experience.

## Features

This randomizer includes the following options and features:

### Randomizer Options
- **Enemy Randomization**: Enemies throughout the game are shuffled
- **Starting Room Randomization**: Your starting spawn location is randomized
- **Increased Pot Ryo**: Pots contain more money for better progression balance
- **Health in Item Pool**: Health upgrades are added to the randomized item pool
- **Prevent One-Way Softlocks**: Normally one-way entrances are locked off to prevent softlocks

### Randomized Items
The randomizer shuffles a comprehensive set of items including:
- **Keys**: Silver, Gold, Diamond, and Jump Gym keys
- **Equipment**: Chain Pipe, Bazooka, Meat Hammer, Wind-up Camera, Ice Kunai, Medal of Flames, Flute
- **Abilities**: Mermaid, Mini Ebisumaru, Sudden Impact, Jetpack
- **Characters**: Goemon, Yae, Ebisumaru, Sasuke
- **Quest Items**: Cucumber, Super Pass
- **Collectibles**: Fortune Dolls (Silver/Gold), Mr. Elly Fant and Mr. Arrow collectibles, Achilles Heel
- **Upgrades**: Strength upgrades and Surprise Packs
- **Health Items**: Golden and Normal Health pickups (when enabled)

## Installation

### Step 1: Get the APWorld File
1. Download the latest `mnsg.apworld` file from the releases, or
2. Build it yourself using the provided `package_apworld.py` script

### Step 2: Install in Archipelago
1. Place the `mnsg.apworld` file in your Archipelago `custom_worlds` folder
2. The world will now be available when creating new Archipelago games

### Step 3: Get the Mod File
1. Download the latest `mod.zip` file from the releases
2. Install the mod in your Mystical Ninja Starring Goemon: Recompiled mods folder

### Step 4: Generate and Play
1. Create a new multiworld game in Archipelago with Mystical Ninja Starring Goemon included
2. Generate your game and use the generated `.zip` file with either the Archipelago Website or local hosting
3. The mod will connect to your Archipelago world using the generated data

## Building the APWorld

To build the `mnsg.apworld` file from source:

1. Run the packaging script:
   ```
   python package_apworld.py
   ```
2. This will create `mnsg.apworld` in the root directory
3. The APWorld file can then be distributed to other Archipelago users

## Building the Recomp Mod (for Developers)

If you want to build the recomp mod portion from source, you'll need to install `clang` and `make`.
* On Windows, using [chocolatey](https://chocolatey.org/) to install both is recommended. The packages are `llvm` and `make` respectively.
  * The LLVM 19.1.0 [llvm-project](https://github.com/llvm/llvm-project) release binary, which is also what chocolatey provides, does not support MIPS correctly. The solution is to install 18.1.8 instead, which can be done in chocolatey by specifying `--version 18.1.8` or by downloading the 18.1.8 release directly.
* On Linux, these can both be installed using your distro's package manager. You may also need to install your distro's package for the `lld` linker. On Debian/Ubuntu based distros this will be the `lld` package.
* On MacOS, these can both be installed using Homebrew. Apple clang won't work, as you need a mips target for building the mod code.

On Linux and MacOS, you'll need to also ensure that you have the `zip` utility installed.

You'll also need to grab a build of the `RecompModTool` utility from the releases of [N64Recomp](https://github.com/N64Recomp/N64Recomp). You can also build it yourself from that repo if desired.

### Building the Mod Code
* First, run `make` (with an optional job count) to build the mod code itself.
* Next, run the `RecompModTool` utility with `mod.toml` as the first argument and the build dir (`build` in the case of this mod) as the second argument.
  * This will produce your mod's `.nrm` file in the build folder.
  * If you're on MacOS, you may need to specify the path to the `clang` and `ld.lld` binaries using the `CC` and `LD` environment variables, respectively.

## How It Works

This randomizer consists of two main components:

1. **APWorld File (`mnsg.apworld`)**: Contains the randomizer logic, item definitions, location mappings, and game rules for Archipelago
2. **Recomp Mod**: A native code modification for Mystical Ninja Starring Goemon: Recompiled that implements the randomizer features in-game

When you generate a randomized seed in Archipelago, it creates a data file that the recomp mod reads to determine item placements, enemy randomization, and other randomized elements.
