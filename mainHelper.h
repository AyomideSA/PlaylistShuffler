//
// Created by ayoso on 26/02/2021.
//

#ifndef SOFTWARE_PROJECT_1_MAINHELPER_H

#define SOFTWARE_PROJECT_1_MAINHELPER_H
#define MAX_LINE_LENGTH 100
#define MAX_LINE_NUMBER 121
#include <stddef.h>
void printInputFormat(void);
void getInputFromKeyboard(char inputMusic[][MAX_LINE_LENGTH]);
void getArtisteNames(char inputMusic[][MAX_LINE_LENGTH], char artisteNames[][MAX_LINE_LENGTH]);
void swap(char array[][MAX_LINE_LENGTH], size_t i, size_t j);

#endif //SOFTWARE_PROJECT_1_MAINHELPER_H



