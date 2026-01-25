// Text utility functions for scenario script generation
#include "common.h"
#include "libc/stdbool.h"
#include "libc/string.h"
#include "scenario.h"

// Function to convert character to CHR_ constant
s16 char_to_chr(char c)
{
  if (c >= 'A' && c <= 'Z')
    return CHR_A + (c - 'A');
  if (c >= 'a' && c <= 'z')
    return CHR_a + (c - 'a');
  if (c >= '0' && c <= '9')
    return NUM_0 + (c - '0');
  if (c == ' ')
    return PCT_SPACE;
  if (c == '!')
    return PCT_EXCLAMATION;
  if (c == '?')
    return PCT_QUESTION;
  if (c == '.')
    return PCT_PERIOD;
  if (c == ',')
    return PCT_COMMA;
  if (c == ':')
    return PCT_COLON;
  if (c == '(')
    return PCT_LPAREN;
  if (c == ')')
    return PCT_RPAREN;
  if (c == '[')
    return PCT_LBRACKET;
  if (c == ']')
    return PCT_RBRACKET;
  if (c == '\'')
    return PCT_APOSTROPHE;
  if (c == '-')
    return PCT_DASH;
  if (c == '/')
    return PCT_SLASH;
  if (c == '"')
    return PCT_QUOTE;
  return PCT_SPACE; // Default to space for unknown characters
}

// Function to dynamically create "Received [item]!" text
s16 *create_received_text(const char *item_name)
{
  static s16 dynamic_text[512];
  int idx = 0;
  int line_count = 0;
  int current_line_length = 0;

  // Build the full text manually: " Got [item_name]!"
  char full_text[256];
  int full_idx = 0;

  // Add " Got ["
  full_text[full_idx++] = ' ';
  full_text[full_idx++] = 'G';
  full_text[full_idx++] = 'o';
  full_text[full_idx++] = 't';
  full_text[full_idx++] = ' ';
  full_text[full_idx++] = '[';

  // Add item name
  for (int i = 0; item_name[i] != '\0' && full_idx < 250; i++)
  {
    full_text[full_idx++] = item_name[i];
  }

  // Add "]!"
  full_text[full_idx++] = ']';
  full_text[full_idx++] = '!';
  full_text[full_idx] = '\0';

  int text_pos = 0;
  int full_text_len = strlen(full_text);
  bool in_brackets = false;
  bool color_applied = false;

  while (text_pos < full_text_len && line_count < 4)
  {
    // Start of a new line
    if (current_line_length == 0 && line_count > 0)
    {
      dynamic_text[idx++] = CTR_NEWLINE;
    }

    // Check for bracket start/end to handle coloring
    if (full_text[text_pos] == '[')
    {
      in_brackets = true;
      dynamic_text[idx++] = PCT_LBRACKET;
      dynamic_text[idx++] = CTR_EM_YELLOW;
      color_applied = true;
      text_pos++;
      current_line_length += 1; // Only count the bracket, not the color code
      continue;
    }
    else if (full_text[text_pos] == ']')
    {
      in_brackets = false;
      dynamic_text[idx++] = CTR_CLOSE_EM;
      dynamic_text[idx++] = PCT_RBRACKET;
      color_applied = false;
      text_pos++;
      current_line_length += 1; // Only count the bracket, not the color code
      continue;
    }

    // Find the end of current word or line
    int word_end = text_pos;
    while (word_end < full_text_len && full_text[word_end] != ' ' &&
           full_text[word_end] != '[' && full_text[word_end] != ']')
    {
      word_end++;
    }

    int word_length = word_end - text_pos;

    // Check if we need to wrap
    if (current_line_length + word_length > 32)
    {
      // If we're at line 4 and need to wrap, truncate
      if (line_count == 3)
      {
        // Fill remaining space up to 31 chars, then close
        int remaining_space = 31 - current_line_length;
        for (int i = 0; i < remaining_space && text_pos < full_text_len; i++)
        {
          if (full_text[text_pos] == '[' || full_text[text_pos] == ']')
            break;
          dynamic_text[idx++] = char_to_chr(full_text[text_pos++]);
        }

        // Close color if we're in brackets
        if (color_applied)
        {
          dynamic_text[idx++] = CTR_CLOSE_EM;
        }
        dynamic_text[idx++] = PCT_RBRACKET;
        break;
      }

      // Move to next line
      line_count++;
      current_line_length = 0;

      // Skip any leading space on new line
      if (text_pos < full_text_len && full_text[text_pos] == ' ')
      {
        text_pos++;
      }

      // Re-apply color if we were in brackets
      if (in_brackets && !color_applied)
      {
        dynamic_text[idx++] = CTR_EM_YELLOW;
        color_applied = true;
      }
      continue;
    }

    // Add the word/character
    if (word_length == 0)
    {
      // Single character (space or special char)
      if (full_text[text_pos] == ' ')
      {
        dynamic_text[idx++] = PCT_SPACE;
      }
      else
      {
        dynamic_text[idx++] = char_to_chr(full_text[text_pos]);
      }
      text_pos++;
      current_line_length++;
    }
    else
    {
      // Add word, but check if it's too long for any line
      if (word_length > 32)
      {
        // Split word at 32 character boundary
        int chars_to_add = 32 - current_line_length;
        for (int i = 0; i < chars_to_add; i++)
        {
          dynamic_text[idx++] = char_to_chr(full_text[text_pos++]);
        }
        current_line_length = 32;
      }
      else
      {
        // Add whole word
        for (int i = 0; i < word_length; i++)
        {
          dynamic_text[idx++] = char_to_chr(full_text[text_pos++]);
        }
        current_line_length += word_length;
      }
    }
  }

  // End the text
  dynamic_text[idx++] = CTR_ENDLINE;

  return dynamic_text;
}