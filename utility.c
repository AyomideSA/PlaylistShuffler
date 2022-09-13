/*
 *  Date: 11/03/2021.
 *
 *  Description: Various boolean conditions that are used often used in the other source files
 *
 */

#include "utility.h"
#include <string.h>


int NotEOInput(char array[])
{
    return (strcmp(array, "\0") != 0);
}


void removeNewline(char array[])
{
    size_t lastCharPos = strlen(array) - 1;

    if (array[lastCharPos] == '\n')
        array[lastCharPos] = '\0';

}


int notBlankline(char array[])
{
    return (strcmp(array, "\n") != 0);
}