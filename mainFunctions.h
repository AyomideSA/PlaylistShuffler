//
// Created by ayoso on 18/02/2021.
//

#ifndef SOFTWARE_PROJECT_1_MAINFUNCTIONS_H

#define SOFTWARE_PROJECT_1_MAINFUNCTIONS_H
#define MAX_LINE_LENGTH 100
#define MAX_LINE_NUMBER 121
void readInput(char inputMusic[][MAX_LINE_LENGTH], int argc, char *argv[]); // Takes input
void sortInput(char inputMusic[][MAX_LINE_LENGTH], char artisteNames[][MAX_LINE_LENGTH]);
void printSortedInput(char inputMusic[][MAX_LINE_LENGTH]);
void getArtisteSongs(char inputMusic[][MAX_LINE_LENGTH], char artisteSongs[][MAX_LINE_LENGTH]); // Isolates artiste songs
void printPlaylist(char artisteNames[][MAX_LINE_LENGTH], char artisteSongs[][MAX_LINE_LENGTH], char inputMusic[][MAX_LINE_LENGTH]);
void shuffleSongs(char artisteSongs[][MAX_LINE_LENGTH]);

#endif //SOFTWARE_PROJECT_1_MAINFUNCTIONS_H




