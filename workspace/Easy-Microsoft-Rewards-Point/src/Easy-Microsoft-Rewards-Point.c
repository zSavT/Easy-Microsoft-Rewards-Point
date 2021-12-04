/*
 ============================================================================
 Name        : Easy-Microsoft-Rewards-Point.c
 Author      : zSavT
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



int main(void) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	 char ch;
	 FILE *fp;
	 fp = fopen("time.txt", "r"); // read mode
	 char check[] = "00";
	 int i = 0;
	   if (fp == NULL)
	   {
		  perror("Error while opening the file.\n");
		  exit(EXIT_FAILURE);
	   }
	   while((ch = fgetc(fp)) != EOF) {
		   if (ch != EOF) {
			   check[i]=ch;
		   }
		   i++;
	   }
	   fclose(fp);
	   char temp[2];
	   itoa(tm.tm_mday, temp, 10);
	   printf("Value of temp: %s\nGiorno: %02d\n", temp, tm.tm_mday);
	   FILE *fp2;
	   fp2 = fopen("time.txt", "w"); // write mode
	   fputs(temp, fp2);
	   fclose(fp2);
	   printf("\nValue of check: %s\n", check);
	   if (atoi(check) > tm.tm_mday) {
		   printf("ok\n");
	   }


	//printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	system("PAUSE");
	return EXIT_SUCCESS;
}
