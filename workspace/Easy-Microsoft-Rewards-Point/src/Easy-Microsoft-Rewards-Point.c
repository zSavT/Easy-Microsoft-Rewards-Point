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
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "randomString.h"

#define NUMBER_SEARCH 36

void punti();
bool isEmpty(int i);
char* concatenateStrings(const char* string1, const char* string2, const char* string3);

int main(void) {

	//READ VAL ON FILE TIME.TXT
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int temp[3];					//file time
	int i = 0;
	FILE *fp;
	fp = fopen("C:/EasyMicrosoftPoint/time.txt", "r"); // read mode
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(-1);
	}
	printf("Day, month and year saved on file.\n");
	do {
		fscanf(fp, "%d", &temp[i]);			//read val from file
		printf("%d\n", temp[i]);
		i++;
	} while (!feof(fp));
	fclose(fp);

	if (isEmpty(i) == TRUE)	// if file is empty, write today value and run points script
	{
		fp = fopen("C:/EasyMicrosoftPoint/time.txt", "w"); // write mode
		if (fp == NULL) {
			perror("Error while opening the file.\n");
			system("PAUSE");
			exit(-2);
		} else {
			tm = *localtime(&t);						//reset val
			fprintf(fp, "%d\n", tm.tm_mday);			//write day on file
			fprintf(fp, "%d\n", tm.tm_mon + 1);			//write mouth on file
			fprintf(fp, "%d", tm.tm_year + 1900);		//write year on file
		}
		fclose(fp);
		punti();
	} else {
		//CHECK ACTUAL DAY MONTH YEAR WITH DAY MONTH YEAR ON FILE
		i = 0;
		if (temp[2] == tm.tm_year + 1900 && temp[0] == tm.tm_mday
				&& temp[1] == tm.tm_mon + 1) {
			return EXIT_SUCCESS;
		} else if (temp[0] == tm.tm_mday && temp[1] == tm.tm_mon + 1
				&& temp[2] < tm.tm_year + 1900) {
			punti();
		} else if (temp[0] == tm.tm_mday && temp[1] < tm.tm_mon + 1
				&& temp[2] <= tm.tm_year + 1900) {
			punti();
		} else if (temp[0] > tm.tm_mday && temp[1] < tm.tm_mon + 1
				&& temp[2] <= tm.tm_year + 1900) {
			punti();
		}

		fp = fopen("C:/EasyMicrosoftPoint/time.txt", "w"); // write mode
		if (fp == NULL) {
			perror("Error while opening the file.\n");
			system("PAUSE");
			exit(-2);
		} else {
			tm = *localtime(&t);						//reset val
			fprintf(fp, "%d\n", tm.tm_mday);			//write day on file
			fprintf(fp, "%d\n", tm.tm_mon + 1);			//write mouth on file
			fprintf(fp, "%d", tm.tm_year + 1900);		//write year on file
		}
		fclose(fp);
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

bool isEmpty(int i) {
	if (i > 1)		// if file is empty, do while loop make just one iterations
		return FALSE;
	else
		return TRUE;
}

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

