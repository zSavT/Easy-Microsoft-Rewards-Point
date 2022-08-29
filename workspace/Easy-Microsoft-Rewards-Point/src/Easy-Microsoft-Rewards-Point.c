/*
 ============================================================================
 Name        : Easy-Microsoft-Rewards-Point.c
 Author      : zSavT
 Version     : v1.0.3
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


void punti();


int main(void) {

	//READ VAL ON FILE TIME.TXT
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int temp[2];					//file time
	int i = 0;
	FILE *fp;
	fp = fopen("C:/EasyMicrosoftPoint/time.txt", "r"); // read mode
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(-1);
	}
	while (!feof(fp)) {
		fscanf(fp, "%d", &temp[i]);			//read val from file
		printf("%d\n", temp[i]);
		i++;
	}
	fclose(fp);

	//CHECK ACTUAL DAY WITH DAY ON FILE
	i = 0;
	if (temp[0] < tm.tm_mday && temp[1] < tm.tm_mon + 1) {
		punti();
		fp = fopen("C:/EasyMicrosoftPoint/time.txt", "w"); // write mode
		if (fp == NULL) {
			perror("Error while opening the file.\n");
			exit(-2);
		} else {
			fprintf(fp, "%d \n", tm.tm_mday);			//write val on file
			fprintf(fp, "%d", tm.tm_mon + 1);			//write val on file
		}
		fclose(fp);
		return EXIT_SUCCESS;
	} else if (temp[0] == tm.tm_mday && temp[1] == tm.tm_mon) {
		return EXIT_SUCCESS;
	} else { 											//in case of time.txt is too old
		fp = fopen("C:/EasyMicrosoftPoint/time.txt", "w"); // write mode
		if (fp == NULL) {
			perror("Error while opening the file.\n");
			exit(-2);
		} else {
			fprintf(fp, "%d \n", tm.tm_mday);			//write val on file
			fprintf(fp, "%d", tm.tm_mon + 1);			//write val on file
		}
		fclose(fp);
		return EXIT_SUCCESS;
	}

}



void punti() {
	system("START microsoft-edge:https://www.bing.com/search?q=a");
	system("START microsoft-edge:https://www.bing.com/search?q=b");
	system("START microsoft-edge:https://www.bing.com/search?q=c");
	system("START microsoft-edge:https://www.bing.com/search?q=d");
	system("START microsoft-edge:https://www.bing.com/search?q=e");
	system("START microsoft-edge:https://www.bing.com/search?q=f");
	system("START microsoft-edge:https://www.bing.com/search?q=g");
	system("START microsoft-edge:https://www.bing.com/search?q=h");
	system("START microsoft-edge:https://www.bing.com/search?q=i");
	system("START microsoft-edge:https://www.bing.com/search?q=l");
	system("START microsoft-edge:https://www.bing.com/search?q=m");
	system("START microsoft-edge:https://www.bing.com/search?q=n");
	system("START microsoft-edge:https://www.bing.com/search?q=o");
	system("START microsoft-edge:https://www.bing.com/search?q=p");
	system("START microsoft-edge:https://www.bing.com/search?q=q");
	system("START microsoft-edge:https://www.bing.com/search?q=r");
	system("START microsoft-edge:https://www.bing.com/search?q=s");
	system("START microsoft-edge:https://www.bing.com/search?q=t");
	system("START microsoft-edge:https://www.bing.com/search?q=u");
	system("START microsoft-edge:https://www.bing.com/search?q=v");
	system("START microsoft-edge:https://www.bing.com/search?q=z");
	system("START microsoft-edge:https://www.bing.com/search?q=w");
	system("START microsoft-edge:https://www.bing.com/search?q=y");
	system("START microsoft-edge:https://www.bing.com/search?q=j");
	system("START microsoft-edge:https://www.bing.com/search?q=k");
	system("START microsoft-edge:https://www.bing.com/search?q=x");
	system("START microsoft-edge:https://www.bing.com/search?q=0");
	system("START microsoft-edge:https://www.bing.com/search?q=1");
	system("START microsoft-edge:https://www.bing.com/search?q=2");
	system("START microsoft-edge:https://www.bing.com/search?q=3");
	system("START microsoft-edge:https://www.bing.com/search?q=4");
	system("START microsoft-edge:https://www.bing.com/search?q=5");
	system("START microsoft-edge:https://www.bing.com/search?q=6");
	system("START microsoft-edge:https://www.bing.com/search?q=7");
	system("START microsoft-edge:https://www.bing.com/search?q=8");
	system("START microsoft-edge:https://www.bing.com/search?q=9");
	Sleep(10000);
	system("taskkill /F /IM msedge.exe");
}

