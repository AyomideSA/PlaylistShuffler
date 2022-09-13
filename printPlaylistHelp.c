/*
 * Functions to assist printPlaylist
 *
 * Date: 26/2/21
 *
 */

#include "printPlaylistHelp.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utility.h"


int findSongloc(char song[], char inputMusic[][MAX_LINE_LENGTH]) {

    int i = 0;

    while (NotEOInput(inputMusic[i])) {

        // When song is found in inputMusic[] its location is returned
        if (strcmp(song, inputMusic[i]) == 0)
            break;

        i++;

    }

    return i;

}


int findSongArtiste(char artisteNames[][MAX_LINE_LENGTH], char inputMusic[][MAX_LINE_LENGTH], int songloc) {

    int i;
    int j;
    int artistloc;
    bool found = false;

    // Searches backwards from location of song for the song artist
    for (i = songloc-1; !found; i--) {

        if (strstr(inputMusic[i], "***") == NULL) { // if inputMusic[i] is an artiste name
            found = true;
            artistloc = i; // location of artiste in inputMusic[]
        }

    }


    found = false;
    for (j = 0; NotEOInput(artisteNames[j]) && !found; j++) {

        // If name of artist has been found in artisteNames[]
        if(strcmp(artisteNames[j], inputMusic[artistloc]) == 0) {
            artistloc = j; // location of artiste in artisteNames[]
            found = true;
        }

    }

    return artistloc;

}


long int convertDurToSecs(char songDurM[], char songDurS[]) {

    long int minutes = strtol(songDurM,NULL,10);
    long int seconds = strtol(songDurS,NULL,10);

    seconds = seconds + (minutes*60);

    return seconds;

}

void printTotalDur(long int totalDurS) {

    long int seconds;
    long int minutes;

    minutes = totalDurS / 60;
    seconds = totalDurS % 60;

    printf("Total duration: %ld:%02ld.", minutes, seconds);

}