/*
 * randomString.h
 *
 *  Created on: 18 gen 2022
 *      Author: zSavT
 */

#ifndef SRC_RANDOMSTRING_H_
#define SRC_RANDOMSTRING_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DICTIONARY 30
#define MIN_STR_LENGHT 2

char random_char(int index);
char* createRandomString();

/*
 * returns a char at the index passed in input
 */
char random_char(int index) 
{
	char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	return charset[index];
}

/*
 * generates a random string with maximum length MAX_DICTIONARY and minimum MIN_STR_LENGHT
 */
char* createRandomString()
{
	srand(time(NULL));
	int dim =  MIN_STR_LENGHT + rand() % (MAX_DICTIONARY - MIN_STR_LENGHT);
	char *str = malloc(dim * sizeof(char));
	int i, index;
	for (i = 0; i < dim - 1; i++) {
		index = rand() % 62;
		str[i] = random_char(index);
	}
	str[i] = '\0';
	return str;
}






#endif /* SRC_RANDOMSTRING_H_ */
