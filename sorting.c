/*
 *  Date:19/3/21
 *
 *  Description: Sorting functions used in the function sortInput in main
 *
 */

#include "sorting.h"
#include <string.h>
#include <stdbool.h>
#include "mainHelper.h"
#include "utility.h"


void sortArtistMusic(char inputMusic[][MAX_LINE_LENGTH]) {

    size_t loc; // Location of first song of an artist
    size_t i = 0;

    while (NotEOInput(inputMusic[i]))  {

        loc = i+1;
        i = sortMusic(inputMusic, loc); // sorts music from artiste name to newline
                                        // i set to location of blank line between different artiste's songs

    }

}


size_t sortMusic(char inputMusic[][MAX_LINE_LENGTH], size_t loc) {

    size_t endloc = loc;

    // Counts number of songs to be sorted
    for (size_t i = loc; notBlankline(inputMusic[i]) && NotEOInput(inputMusic[i]); i++) {
        endloc++;
    }


    size_t j;

    // Insertion sort implementation
    for (size_t i = loc+1; i < endloc; i++) {

        j = i;

        // Compares strings lexicographically
        while (j > loc && strcmp(inputMusic[j], inputMusic[j-1])  < 0) {

            swap(inputMusic, j, j-1);
            j--;

        }

    }

    return endloc+1; // Returns location of blank line between songs of different artistes

}


void sortArtistNames(char artisteNames[][MAX_LINE_LENGTH]) {

    size_t j;
    size_t i;

    // Insertion sort implementation
    for (i = 1; NotEOInput(artisteNames[i]); i++) {

        j = i;

        // Compares strings lexicographically
        while (j > 0 && strcmp(artisteNames[j], artisteNames[j - 1]) < 0) {

            swap(artisteNames, j, j - 1);
            j--;

        }

    }

}


void sortInputByArtistNames(char inputMusic[][MAX_LINE_LENGTH], char artisteNames[][MAX_LINE_LENGTH]) {

    char temp[MAX_LINE_NUMBER][MAX_LINE_LENGTH] = {{0}}; // temporarily holds sorted input
    bool found; // Records when an artist name is found
    size_t i;
    size_t j;
    size_t n = 0;

    for (i = 0; NotEOInput(artisteNames[i]); i++) {

        found = false;

        for(j = 0; !found; j++) {

            // If an artiste name has been found
            if (strcmp(artisteNames[i], inputMusic[j]) == 0) {

                found = true;
                strcpy(temp[n], inputMusic[j]); // Copies artiste name to temp
                n++;
                j++;

                // Copies all songs of found artiste into temp until newline
                while (strstr(inputMusic[j], "***") != NULL) {

                    strcpy(temp[n], inputMusic[j]);
                    n++;
                    j++;

                }

                strcpy(temp[n], "\n"); // Blank line to separate each artiste's songs
                n++;

            }

        }

    }

    // Sorted input copied back into inputMusic[i]
    for (i=0; NotEOInput(temp[i]); i++)
        strcpy(inputMusic[i], temp[i]);

}