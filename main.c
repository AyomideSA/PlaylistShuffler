/*
 * Author: Ayomide Sola-Ayodele (ayomide.sola-ayodele@ucdconnect.ie)
 *
 * Date: 19/03/21
 *
 * Description: The purpose of this program take in a list of songs from a file specified
 *              by program arguments and to print the sorted input of these songs as well as produce a randomised playlist
 *
 * Parameters: Location of file surrounded by "" ("<File_Location>") as an argument to main.
 *             e.g. "\Users\username\Desktop\test.txt"
 *
 * Returns: Sorted list of songs and randomised playlist
 *
*/

#include "mainFunctions.h"

// Input taken (argv) is the file location
int main(int argc, char *argv[]) {

    char inputMusic[MAX_LINE_NUMBER][MAX_LINE_LENGTH] = {{0}};
    char artisteNames[MAX_LINE_NUMBER][MAX_LINE_LENGTH] = {{0}};
    char artisteSongs[MAX_LINE_NUMBER][MAX_LINE_LENGTH] = {{0}};

    readInput(inputMusic,argc, argv);
    sortInput(inputMusic, artisteNames);
    printSortedInput(inputMusic);


    getArtisteSongs(inputMusic, artisteSongs);
    shuffleSongs(artisteSongs);
    printPlaylist(artisteNames, artisteSongs, inputMusic);

    return 0;
}