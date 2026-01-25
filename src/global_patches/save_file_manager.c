#include "common.h"
#include "modding.h"

// External function declarations
extern void func_801CD24C_6600FC(void *entity);
extern void *func_801CC5C8_65F478(void *entity, s32 x, s32 y, s32 width,
                                  s32 height);
extern void func_801CC56C_65F41C(void *sprite, s32 x, s32 y, s32 width,
                                 s32 height, s32 alpha);
extern void *func_801CB6AC_65E55C(void *sprite, s32 x, s32 y, s32 z,
                                  void *data);
extern void func_801CB69C_65E54C(void *sprite, s32 param);
extern s32 func_80023840_24440(void);
extern void func_80011610_12210(void *entity, void *sprite);
extern void func_801CD3B8_660268(void *entity, void *sprite);
extern void func_80011734_12334(void *entity, void *callback);
extern void func_801CE1F0_6610A0(void *entity, s32 param2);
extern void func_801CCDCC_65FC7C(void);
extern void func_801CD410_6602C0(void *entity);
extern void func_80038B98_39798(s32 sound_id);
extern s32 func_80023410_24010(void);
extern void func_80023480_24080(void);
extern s32 func_800237F0_243F0(void);
extern s32 func_80023788_24388(void);
extern void func_8000B640_C240(void);
extern void func_8000B5D0_C1D0(void);
extern void func_8003521C_35E1C(void *func_ptr);
extern void func_801CE16C_66101C(void *entity, s32 param);
extern void func_801CEF08_661DB8(void);
extern void func_801CD910_6607C0(void);
extern void func_801CDA10_6608C0(void);
extern void func_801CE098_660F48(void);
extern void func_801CD890_660740(void);
extern void func_801CD768_660618(void);

// External data declarations
extern void *D_801CCDC4_65FC74; // Function pointer/data for conditional path
extern s32 D_801E9914_67C7C4;   // Current selection index
extern s32 D_801E9918_67C7C8;   // Secondary state flag
extern u32 D_8015C5C8_15D1C8;   // Game data base pointer
extern void *D_80168E84_169A84; // Game state structure

/**
 * Function: func_801CE3B4_661264
 *
 * Initializes a UI screen with two main sprites and sets up conditional logic
 * based on game state. Creates sprites at positions (0x38, 0x50) and (0x38,
 * 0x7A), applies data and styling, then sets up callbacks and selection
 * handling.
 *
 * @param entity - Main entity/screen object
 * @param param - Additional parameter (stored but not used in logic)
 */
RECOMP_PATCH void func_801CE3B4_661264(void *entity, s32 param)
{
    void *sprite1;
    void *sprite2;
    void *text_element1;
    void *entity_offset;
    s32 selection_index;
    void **sprite_array;

    // Initialize the entity
    func_801CD24C_6600FC(entity);

    // Create first sprite at position (0x38, 0x50)
    sprite1 = func_801CC5C8_65F478(entity, 0x38, 0x50, 0x9, 0x4);

    // Store sprite1 in entity at offset 0x7C (0x5C + 0x20)
    entity_offset = (void *)((u8 *)entity + 0x5C);
    *((void **)((u8 *)entity_offset + 0x1C)) = sprite1;

    // Configure first sprite appearance
    func_801CC56C_65F41C(sprite1, 0x20, 0x20, 0x20, 0x60, 0x0);

    // Add text/data to first sprite
    text_element1 =
        func_801CB6AC_65E55C(sprite1, 0x1A, 0x5, 0xA, "Archipelago Managed");

    // // Create second sprite at position (0x38, 0x7A)
    // sprite2 = func_801CC5C8_65F478(entity, 0x38, 0x7A, 0x9, 0x4);

    // // Store sprite2 in entity at offset 0x80 (0x5C + 0x24)
    // *((void**)((u8*)entity_offset + 0x20)) = sprite2;

    // // Configure second sprite appearance
    // func_801CC56C_65F41C(sprite2, 0x20, 0x20, 0x20, 0x60, 0x0);

    // // Add text/data to second sprite
    // func_801CB6AC_65E55C(sprite2, 0x1A, 0x5, 0xA, "Archipelago Managed");

    // Check game state condition
    if (func_80023840_24440() == 0)
    {
        // State is 0 - use first conditional path
        func_801CB69C_65E54C(text_element1, 0x2);

        // Set up callback pointer at entity offset 0xA8 (0x5C + 0x4C)
        *((void **)((u8 *)entity_offset + 0x4C)) = D_801CCDC4_65FC74;

        // Set both global state variables to 1
        D_801E9918_67C7C8 = 1;
        D_801E9914_67C7C4 = 1;
    }
    else
    {
        // State is non-zero - use second conditional path
        // Set up different callback pointer
        *((void **)((u8 *)entity_offset + 0x4C)) = func_801CCDCC_65FC7C;

        // Clear both global state variables
        D_801E9918_67C7C8 = 0;
        D_801E9914_67C7C4 = 0;
    }

    // Get current selection index and configure selected sprite
    selection_index = D_801E9914_67C7C4;
    sprite_array = (void **)((u8 *)entity_offset + 0x1C); // Start of sprite array

    // Configure the selected sprite (based on index)
    func_801CC56C_65F41C(sprite_array[selection_index],
                         0x0,  // x
                         0x0,  // y
                         0xFF, // width
                         0x80, // height
                         0x1   // alpha/flag
    );

    // Set up sprite in entity at offset 0xA4 (0x5C + 0x48)
    func_80011610_12210(*((void **)((u8 *)entity + 0x40)),
                        sprite_array[selection_index]);

    // Additional sprite configuration
    func_801CD3B8_660268(*((void **)((u8 *)entity + 0x40)),
                         sprite_array[selection_index]);

    // Set up callback function
    func_80011734_12334(entity, func_801CE1F0_6610A0);
}

/**
 * Function: func_801CE1F0_6610A0
 *
 * Main input handler and state manager for a menu/selection screen.
 * Handles controller input, manages selection state, and transitions
 * between different screens based on button presses and game state.
 *
 * @param entity - Main entity/screen object
 * @param param2 - Additional parameter (unused)
 */
RECOMP_PATCH void func_801CE1F0_6610A0(void *entity, s32 param2)
{
    void (*callback_func)(void);
    s32 current_selection, secondary_selection;
    u8 *game_data;
    u16 input_flags;
    s32 menu_result;
    void *game_state;
    s32 value1, value2, value3;

    // Call the callback function stored at offset 0xA8 in the entity
    callback_func = *(void (**)(void))((u8 *)entity + 0xA8);
    callback_func();

    // Get current selection indices
    current_selection = D_801E9914_67C7C4;
    secondary_selection = D_801E9918_67C7C8;

    // Force selection to stay at 0 (prevent selecting disabled second sprite)
    if (current_selection != 0)
    {
        current_selection = 0;
        D_801E9914_67C7C4 = 0;
    }
    if (secondary_selection != 0)
    {
        secondary_selection = 0;
        D_801E9918_67C7C8 = 0;
    }

    // If selection has changed, update display
    if (secondary_selection != current_selection)
    {
        func_801CD410_6602C0(entity);
    }

    // Read input flags from game data
    game_data = (u8 *)D_8015C5C8_15D1C8;
    input_flags = *(u16 *)(game_data + 0x3B07A);

    // Check for A button or Start button press (0x9000 = 0x8000 | 0x1000)
    if (input_flags & 0x9000)
    {
        // Play selection sound
        func_80038B98_39798(0x167);

        // Handle selection based on current index
        switch (current_selection)
        {
        case 0:
            // Selection 1: Handle special reset/exit case
            func_8000B640_C240(); // Reset function 1
            func_8000B5D0_C1D0(); // Reset function 2

            // Set value at offset 0x3B040 to -1
            *(s32 *)(game_data + 0x3B040) = -1;

            // Register exit callback
            func_8003521C_35E1C(func_801CD890_660740);
            break;

        case 1:
            // Selection 1: Handle special reset/exit case
            func_8000B640_C240(); // Reset function 1
            func_8000B5D0_C1D0(); // Reset function 2

            // Set value at offset 0x3B040 to -1
            *(s32 *)(game_data + 0x3B040) = -1;

            // Register exit callback
            func_8003521C_35E1C(func_801CD890_660740);
            break;

        default:
            // Other selections: no action
            break;
        }
    }
    // Check for B button press (0x4000)
    else if (input_flags & 0x4000)
    {
        // B button: register back/cancel callback
        func_8003521C_35E1C(func_801CD768_660618);
    }
}