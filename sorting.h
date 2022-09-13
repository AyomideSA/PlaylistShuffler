//
// Created by ayoso on 19/03/2021.
//

#ifndef SOFTWARE_PROJECT_1_SORTING_H

#define SOFTWARE_PROJECT_1_SORTING_H
#define MAX_LINE_LENGTH 100
#define MAX_LINE_NUMBER 121
#include <stddef.h>
void sortArtistNames(char artisteNames[][MAX_LINE_LENGTH]);
void sortInputByArtistNames(char inputMusic[][MAX_LINE_LENGTH], char artisteNames[][MAX_LINE_LENGTH]);
void sortArtistMusic(char inputMusic[][MAX_LINE_LENGTH]);
size_t sortMusic(char inputMusic[][MAX_LINE_LENGTH], size_t loc);

#endif //SOFTWARE_PROJECT_1_SORTING_H


