/*
 ============================================================================
 Name        : Easy-Microsoft-Rewards-Point.c
 Author      : zSavT
 Version     : v1.2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include "randomString.h"

#define NUMBER_SEARCH 36
#define FILE_PATH "C:/EasyMicrosoftPoint/time.txt"

void punti();
bool isEmpty();
char* concatenateStrings(const char* string1, const char* string2, const char* string3);
void writeDateToFile(const char* filePath);
void readDateFromFile(const char* filePath, int temp[]);

int main(void) {

	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int temp[3];  // file time

    readDateFromFile(FILE_PATH, temp);

    if (isEmpty()) {
        writeDateToFile(FILE_PATH);
        punti();
    } else {
        // CHECK ACTUAL DAY MONTH YEAR WITH DAY MONTH YEAR ON FILE
        if (temp[2] < tm.tm_year + 1900 || (temp[2] == tm.tm_year + 1900 && (temp[1] < tm.tm_mon + 1 ||
                                      (temp[1] == tm.tm_mon + 1 && temp[0] < tm.tm_mday)))) {
            punti();
        }

        writeDateToFile(FILE_PATH);
    }

    return EXIT_SUCCESS;
}
/*
 * starting from the generated string, the method opens an edge page with the search of the generated string
 */
void punti() {
	for (int i = 0; i < NUMBER_SEARCH; i++) {
		char *str = createRandomString();
		char openCommand[] =
				"START microsoft-edge:\"https://www.bing.com/search?q=";
		char flags[] = "&form=QBRE\"";
		char* finalComand = concatenateStrings(openCommand, str, flags);
		system(finalComand);
		Sleep(2500);//pause to make the search more natural and to avoid problems with string generation
		free(str);
	}
	Sleep(10000);	//give enough time for potato computer to load everything
	system("taskkill /F /IM msedge.exe");
}

/*
 * Returns true if the file is empty, false otherwise
 */
bool isEmpty() {
    FILE* file = fopen(FILE_PATH, "r");
    if (file == NULL) {
        perror("Error opening the file.\n");
        return false;
    }
    int character = fgetc(file);
    fclose(file);
    return (character == EOF);
}

/*
 * Take string1, string2, string3 and return string1+string2+string3
 */
char* concatenateStrings(const char* string1, const char* string2, const char* string3) {

    size_t totalLength = strlen(string1) + strlen(string2) + strlen(string3) + 1; // Calculate the total length of the strings
    char* result = (char*)malloc(totalLength); // Allocate memory for the result string
    if (result == NULL) {	// Check if memory allocation was successful
        perror("Error during memory allocation");
        exit(EXIT_FAILURE);
    }

    // Copy the strings into the result string
    strcpy(result, string1);
    strcat(result, string2);
    strcat(result, string3);

    return result;
}

/*
 * Write on file date val
 */
void writeDateToFile(const char* filePath) {
    FILE* fp = fopen(filePath, "w");  // write mode
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        system("PAUSE");
        exit(EXIT_FAILURE);
    } else {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        fprintf(fp, "%d\n", tm.tm_mday);        // write day on file
        fprintf(fp, "%d\n", tm.tm_mon + 1);     // write mouth on file
        fprintf(fp, "%d", tm.tm_year + 1900);   // write year on file
    }
    fclose(fp);
}

/*
 * Read from file date val
 */
void readDateFromFile(const char* filePath, int temp[]) {
    FILE* fp = fopen(filePath, "r");  // read mode
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Day, month, and year saved on file.\n");
    for (int i = 0; i < 3; i++) {
        fscanf(fp, "%d", &temp[i]);  // read val from file
        printf("%d\n", temp[i]);
    }

    fclose(fp);
}

