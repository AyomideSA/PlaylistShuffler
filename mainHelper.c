/*
 * Date: 26/2/21
 *
 * Description: Functions to assist the functions shufflesongs, readInput and sortInput in main.
 *
 */

#include "mainHelper.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utility.h"
#define MAX_ARTISTE_NUM 10
#define MAX_SONG_NUM 10
#define INPUT_FINISHED(x) (strcmp(x, "F\n") == 0)
#define SONG_INPUT_FINISHED(x)  (strcmp(x, "G\n") == 0)


void printInputFormat(void) {

    printf("Each song title should comprise of alphanumeric characters (letters, numbers and symbols) and not contain the\n"
           "sub-string \"***\"\n\n");

    printf("\"Song duration\" should be in the form [m]m:ss, where [m]m denotes a one- or two-digit number of minutes and ss\n"
           "denotes a two-digit number of seconds (e.g. FLamingo***3:17).\n\n\n");

}


// Artiste Names isolated from inputMusic[]
void getArtisteNames(char inputMusic[][MAX_LINE_LENGTH], char artisteNames[][MAX_LINE_LENGTH]) {

    size_t i = 0;
    size_t j = 0;

    while (NotEOInput(inputMusic[i])) {

        // Artist names and blank lines do not contain "***"
        if (strstr(inputMusic[i], "***") == NULL && notBlankline(inputMusic[i]))
            strcpy(artisteNames[j++], inputMusic[i]);

        i++;

    }

}


// Strings at location i and j swapped
void swap(char array[][MAX_LINE_LENGTH], size_t i, size_t j) {

    char temp[MAX_LINE_LENGTH]; // Holds original value for swapping

    strcpy(temp, array[i]);
    strcpy(array[i], array[j]);
    strcpy(array[j], temp);

}

void getInputFromKeyboard(char inputMusic[][MAX_LINE_LENGTH]) {

    int i;
    int j;
    int songCtr = 0;
    int artisteCtr = 0;
    bool EOInput = false; // End of Input
    bool EOSongInput = false; // End of Song Input

    for (i = 0; artisteCtr < MAX_ARTISTE_NUM && !EOInput; i++) {

        printf("Enter artiste name: ");
        fgets(inputMusic[i], MAX_LINE_NUMBER, stdin); // gets artiste names
        artisteCtr++; // Number of artistes updated
        j = i + 1;

        if (INPUT_FINISHED(inputMusic[i])) {
            strcpy(inputMusic[i], "\n"); // marks end of input with newline
            EOInput = true;
        }

        printf("\nEnter artiste songs: ");
        while (!EOInput && !EOSongInput && songCtr < MAX_SONG_NUM) {

            fgets(inputMusic[j], MAX_LINE_NUMBER, stdin); // gets artiste songs
            j++;
            songCtr++; // Number of songs input updated

            if (SONG_INPUT_FINISHED(inputMusic[j-1])) {
                EOSongInput = true;
                strcpy(inputMusic[j-1], "\n"); // separates artiste songs by adding newline
                j--; // moves j to position of new added newline
            }

            else if (songCtr == MAX_SONG_NUM) {
                EOSongInput = true;
                strcpy(inputMusic[j], "\n"); // separates artiste songs by adding newline
            }

        }

        EOSongInput = false;
        songCtr = 0; // Number of songs inputted reset for next artiste
        i = j; // i set to position of newline

    }




}