/*
 ============================================================================
 Name        : Easy-Microsoft-Rewards-Point.c
 Author      : zSavT
 Version     : v1.0.1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

void punti();

int main(void) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int temp = 1;
	FILE *fp;
	fp = fopen("C:/EasyMicrosoftPoint/time.txt", "r"); // read mode
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(-1);
	}
	while (!feof(fp)) {
		fscanf(fp, "%d", &temp);
	}
	fclose(fp);
	if (temp >= tm.tm_mday) {
		fp = fopen("C:/EasyMicrosoftPoint/time.txt", "w"); // write mode
		if (fp == NULL) {
			perror("Error while opening the file.\n");
			exit(-2);
			return EXIT_SUCCESS;
		} else {
			fp = fopen("C:/EasyMicrosoftPoint/time.txt", "w"); // write mode
			if (fp == NULL) {
				perror("Error while opening the file.\n");
				exit(-2);
			}
			fprintf(fp, "%d", tm.tm_mday);
			fclose(fp);
			punti();
		}
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
