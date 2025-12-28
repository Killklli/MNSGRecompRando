// Text utility functions for scenario script generation
#include "scenario.h"
#include "common.h"

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
    static s16 dynamic_text[128];
    int idx = 0;

    // " Received "
    dynamic_text[idx++] = PCT_SPACE;
    const char *received = "Received ";
    for (int i = 0; received[i] != '\0'; i++)
    {
        dynamic_text[idx++] = char_to_chr(received[i]);
    }

    // "["
    dynamic_text[idx++] = PCT_LBRACKET;
    dynamic_text[idx++] = CTR_EM_YELLOW;

    // Item name
    for (int i = 0; item_name[i] != '\0'; i++)
    {
        dynamic_text[idx++] = char_to_chr(item_name[i]);
    }

    // "]!\n"
    dynamic_text[idx++] = CTR_CLOSE_EM;
    dynamic_text[idx++] = PCT_RBRACKET;
    dynamic_text[idx++] = PCT_EXCLAMATION;
    dynamic_text[idx++] = CTR_NEWLINE;
    dynamic_text[idx++] = CTR_ENDLINE;

    return dynamic_text;
}