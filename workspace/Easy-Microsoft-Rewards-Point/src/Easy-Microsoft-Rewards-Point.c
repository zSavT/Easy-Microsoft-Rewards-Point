/*
 ============================================================================
 Name        : Easy-Microsoft-Rewards-Point.c
 Author      : zSavT
 Version     : v1.1
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
	while (!feof(fp)) {
		fscanf(fp, "%d", &temp[i]);			//read val from file
		printf("%d\n", temp[i]);
		i++;
	}
	fclose(fp);


	//CHECK ACTUAL DAY MONTH YEAR WITH DAY MONTH YEAR ON FILE
	i = 0;
	if(temp[2] < tm.tm_year + 1900) {
		punti();
	} else if ( (temp[1] == tm.tm_mon + 1) && (temp[0] < tm.tm_mday) && temp[2] < tm.tm_year + 1900) {
		punti();
	} else if (temp[0] == tm.tm_mday) {
		return EXIT_SUCCESS;
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

		return EXIT_SUCCESS;
}

/*
 * starting from the generated string, the method opens an edge page with the search of the generated string
 */
void punti() {
	for (int i = 0; i<NUMBER_SEARCH; i++)
	{
		char* str = createRandomString();
		char openCommand[] = "START microsoft-edge:https://www.bing.com/search?q=";
		strcat(openCommand,str);
		system(openCommand);
		Sleep(1000);	//pause to make the search more natural and to avoid problems with string generation
		free(str);
	}
	Sleep(10000);		//give enough time for potato computer to load everything
	system("taskkill /F /IM msedge.exe");
}

