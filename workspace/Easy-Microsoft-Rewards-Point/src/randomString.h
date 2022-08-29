/*
 * randomString.h
 *
 *  Created on: 18 gen 2022
 *      Author: zSavT
 */

#ifndef SRC_RANDOMSTRING_H_
#define SRC_RANDOMSTRING_H_
#include <stdbool.h>
#define MAX_DICTIONARY 30

int randomValue();
bool alreadyTaken(int value, bool taken);

int randomValue(){
	srand(time(NULL));   // Initialization, should only be called once.
	int r = rand() % MAX_DICTIONARY;      // Returns a pseudo-random integer between 0 and RAND_MAX.
	return r;
}

bool alreadyTaken(int value, bool taken) {

	return true;
}




#endif /* SRC_RANDOMSTRING_H_ */
