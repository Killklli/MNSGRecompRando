#include "types.h"
#include "file_state.h"
#include "Archipelago.h"
#include "recomputils.h"

// Global flag to track if we're in a file
bool file_started = false;

bool should_run_ap_logic()
{
  bool connected = rando_is_connected();
  bool scouted = rando_is_scouted();

  if (!file_started)
  {
    return false;
  }

  if (!connected)
  {
    return false;
  }

  if (!scouted)
  {
    return false;
  }

  return true;
}

void set_file_started()
{
  file_started = true;
  DEBUG_PRINTF("File started flag set to true\n");
  
  // Check if this is the first time the seed has been started
  if (rando_is_connected())
  {
    rando_set_datastorage_u32_sync("seed_started", 1);
  }
}

bool file_state_has_started()
{
  return file_started;
}
