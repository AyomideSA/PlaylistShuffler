/*
 * Description: All functions present in main()
 *
 * Date: 18/02/2021.
 *
*/

#include "mainFunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "mainHelper.h"
#include "printPlaylistHelp.h"
#include "sorting.h"
#include "utility.h"
#define SIXTY_MINUTES 3600
#define MAX_SONG_NUM_OF_ARTISTE 3
#define THREE_IN_A_ROW 3
#define DEFAULT "artistes+songs.txt"


void readInput(char inputMusic[][MAX_LINE_LENGTH], int argc, char *argv[]) {

    FILE *fp;
    size_t i;
    char *FILE_PATH = DEFAULT;

    if (argc == 2) // If a file was specified
        FILE_PATH = argv[1];

    // If file can't be opened input is obtained from keyboard
    if ((fp = fopen(FILE_PATH, "r")) == NULL) {

        printf("No file found.\n"
               "Please follow the following instructions:\n\n");

        printInputFormat();

        printf("Enter list of songs below (Max of 10 songs from a max 10 of artistes).\n");
        printf("Enter the character 'F' when inputting an artiste name to end your input and start the generation of the randomised playlist.\n");
        printf("Enter the character 'G' when inputting songs to move on to the next artiste early.\n\n");

        getInputFromKeyboard(inputMusic);

    }

    // If file is succesfully opened read input from file
    else {

        i = 0;
        while (!feof(fp)) {

            fgets(inputMusic[i], MAX_LINE_LENGTH, fp);
            i++;

        }

        fclose(fp);
    }

}


void sortInput(char inputMusic[][MAX_LINE_LENGTH], char artisteNames[][MAX_LINE_LENGTH]) {

    sortArtistMusic(inputMusic);
    getArtisteNames(inputMusic, artisteNames);
    sortArtistNames(artisteNames);
    sortInputByArtistNames(inputMusic, artisteNames);

}


void printSortedInput(char inputMusic[][MAX_LINE_LENGTH]) {

    size_t i = 0;
    size_t j;

    printf("Your sorted input is as follows:\n\n");

    while (NotEOInput(inputMusic[i])) {

        printf("%s", inputMusic[i]); // Prints artiste name

        // Prints artiste songs
        for (j=i+1; notBlankline(inputMusic[j]) && NotEOInput(inputMusic[j]); j++) {
            printf("  o %s", inputMusic[j]);
        }

        printf("\n");
        i=j+1; // Sets i to position of next artist name

    }

}


void getArtisteSongs(char inputMusic[][MAX_LINE_LENGTH], char artisteSongs[][MAX_LINE_LENGTH]) {

    size_t i = 0;
    size_t j = 0;

    while (NotEOInput(inputMusic[i])) {

        if(strstr(inputMusic[i], "***") != NULL) // If inputMusic[i] is a song
            strcpy(artisteSongs[j++], inputMusic[i]); // Song added to artisteSongs[]

        i++;

    }

}


// Fisher Yates Shuffle Implementation: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
void shuffleSongs(char artisteSongs[][MAX_LINE_LENGTH]) {

    size_t songCount = 0;
    size_t i = 0;
    size_t j;
    srand(time(NULL));

    // Counts number of songs
    while (NotEOInput(artisteSongs[i]) ) {
        songCount++;
        i++;
    }

    // Fisher Yates Shuffle
    for (i = songCount-1; i > 0; i--) {

        j = rand() % (i+1); // index randomised for shuffle
        swap(artisteSongs, i, j); // artisteSongs[i] swapped with random element

    }

}


void printPlaylist(char artisteNames[][MAX_LINE_LENGTH], char artisteSongs[][MAX_LINE_LENGTH], char inputMusic[][MAX_LINE_LENGTH]) {

    char artistName[MAX_LINE_LENGTH];
    int artistSongCount[MAX_LINE_NUMBER] = {0}; // How many songs by an artist has been played
    int triplePlayCount[MAX_LINE_NUMBER]; // How many times in a row a song by an artist has been chosen
    bool isTriplePlay[MAX_LINE_NUMBER] = {false}; // True when a song by an artist has been chosen 3 times in a row
    size_t prevArtisteloc = 0; // location of artiste of previously played song
    size_t songloc;

    char songDur[6]; // Song Duration in MM:SS where MM is minutes and SS is seconds
    char songDurM[3]; // MM
    char songDurS[3]; // SS
    char song[MAX_LINE_LENGTH];
    char *token;
    char *tokenDur;
    long int totalDurS = 0; // Song duration in seconds
    long int currSongDur; // Duration of current chosen song
    bool maxSongDur = false;

    for (size_t n = 0;n<MAX_LINE_NUMBER;n++) {
        triplePlayCount[n] = 1;
    }

    size_t j;
    bool firstSong = true; // tracks whether the very first song of the playlist has been chosen or not

    printf("------Randomised Playlist------\n");

    for (size_t i = 0; NotEOInput(artisteSongs[i]) && !maxSongDur; i++) {

        songloc = findSongloc(artisteSongs[i], inputMusic); // location, in inputMusic[], of chosen song
        j = findSongArtiste(artisteNames, inputMusic, songloc); // location, in artisteNames[], of artist of chosen song
        strcpy(artistName, artisteNames[j]);


        // Updates how many times song has been chosen in a row.
        // artistSongCount[j] == song will be played
        if (!firstSong && artistSongCount[j] < MAX_SONG_NUM_OF_ARTISTE && strcmp(artistName, artisteNames[prevArtisteloc]) == 0)
            triplePlayCount[j]++;

        // When a different song to the previous song will be played, the triple play status of the previous song is reset
        else if (!firstSong && artistSongCount[j] < MAX_SONG_NUM_OF_ARTISTE && strcmp(artistName, artisteNames[prevArtisteloc]) != 0) {
            isTriplePlay[prevArtisteloc] = false;
            triplePlayCount[prevArtisteloc] = 1;
        }


        if (triplePlayCount[j] >= THREE_IN_A_ROW)
            isTriplePlay[j] = true;


        if (artistSongCount[j] < MAX_SONG_NUM_OF_ARTISTE && !isTriplePlay[j]) {
            artistSongCount[j]++;

            removeNewline(artistName); // Trailing newline from fgets removed
            removeNewline(artisteSongs[i]);

            token = strtok(artisteSongs[i], "***"); // song name isolated
            strcpy(song, token);

            token = strtok(NULL, "***"); // Song duration isolated
            strcpy(songDur, token);

            tokenDur = strtok(songDur, ":"); // Gets minutes of song duration
            strcpy(songDurM, tokenDur);

            tokenDur = strtok(NULL, ":"); // Gets seconds of song duration
            strcpy(songDurS, tokenDur);

            currSongDur = convertDurToSecs(songDurM, songDurS);

            // If max song duration is exceeded and there are no more songs to choose from
            if ((totalDurS + currSongDur) > SIXTY_MINUTES && !NotEOInput(artisteSongs[i + 1]))
                maxSongDur = true;

            else if ((totalDurS + currSongDur) <= SIXTY_MINUTES ) {
                totalDurS = totalDurS + currSongDur;
                printf("%s: \"%s\" (%s:%s)\n", artistName, song, songDurM, songDurS);
            }

            prevArtisteloc = j; // Location set for triple play comparison

            if (firstSong)
                firstSong = false;


        }

    }

    printf("\n");
    printTotalDur(totalDurS);

}