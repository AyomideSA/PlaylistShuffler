//
// Created by ayoso on 26/02/2021.
//

#ifndef SOFTWARE_PROJECT_1_FILLPLAYLISTHELP_H

#define SOFTWARE_PROJECT_1_FILLPLAYLISTHELP_H
#define MAX_LINE_LENGTH 100
#define MAX_LINE_NUMBER 121
int findSongloc(char song[], char inputMusic[][MAX_LINE_LENGTH]);
int findSongArtiste(char artisteNames[][MAX_LINE_LENGTH], char inputMusic[][MAX_LINE_LENGTH], int songloc);
long int convertDurToSecs(char songDurM[], char songDurS[]);
void printTotalDur(long int totalDurS);

#endif //SOFTWARE_PROJECT_1_FILLPLAYLISTHELP_H

