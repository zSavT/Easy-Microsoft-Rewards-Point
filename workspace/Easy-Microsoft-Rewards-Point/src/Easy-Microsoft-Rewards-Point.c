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

#define NUMBER_SEARCH 30
#define FILE_PATH "C:/EasyMicrosoftPoint/time.txt"

void punti();
bool isEmpty();
char* concatenateStrings(const char* string1, const char* string2, const char* string3);
void writeDateToFile(const char* filePath);
void readDateFromFile(const char* filePath, int temp[]);
const char* getRandomString(const char* stringArray[], int numStrings);


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
        const char* stringArray[] = {"weather+today","weather+tomorrow","how+to+prepare+a+lasagna","how+to+prepare+a+pizza","how+to+prepare+a+hotdog","best+soccer+team","how+to+fix+pc+errors",
        		"how+many+languages+exist","how+many+nations+exist","How+to+tie+a+tie","Healthy+breakfast+recipes","Best+budget+smartphones","Weather+forecast+for+Rome","Weather+forecast+for+LA","Learn+to+play+guitar+online",
        		"Quick+dinner+recipes","Home+workout+routines","Latest+technology+trends","How+to+start+a+blog","Travel+destinations+2023","Job+opportunities+near+me","DIY+home+decor+ideas","Movie+release+schedule","How+to+meditate+for+beginners",
        		"Top+fashion+trends","Best+productivity+apps","Car+maintenance+tips","Popular+podcast+recommendations","Financial+planning+for+beginners","Learn+a+new+language+online","Upcoming+concerts+near+me","Healthy+lunch+ideas","Home+gardening+tips",
        		"DIY+skincare+routines","Investing+for+beginners","Virtual+team-building+activities","Online+learning+platforms+comparison","Latest+science+discoveries","Popular+video+games+pc","How+to+make+pizza+at+home","Effective+time+management+techniques",
        		"Easy+dessert+recipes","Job+interview+tips","Online+dating+advice","Best+mystery+novels","How+to+start+a+YouTube+channel","Home+office+setup+ideas","Travel+hacks+for+America","Popular+workout+playlists","Budget+travel+tips","How+to+make+money+online",
        		"DIY+home+organization","Healthy+snacks+for+weight+loss","Latest+smartphone+reviews","Digital+photography+tips","How+to+write+a+resume","Popular+online+multiplayer+games","Home+remedies+for+stress+relief","Learn+to+code+for+free","Learn+to+code+C+++for+free"};
	for (int i = 0; i < NUMBER_SEARCH; i++) {
		char *str = getRandomString(stringArray, (int)(sizeof(stringArray) / sizeof(stringArray[0])));
		char openCommand[] =
				"START microsoft-edge:\"https://www.bing.com/search?q=";
		char flags[] = "&form=QBRE&sp=-1&ghc=2&lq=0&pq=d&sc=11-1&sk=\"";
		char* finalComand = concatenateStrings(openCommand, str, flags);

		system(finalComand);
		Sleep(5000);//pause to make the search more natural and to avoid problems with string generation
		system("taskkill /F /IM msedge.exe");
		free(str);
	}
	Sleep(10000);	//give enough time for potato computer to load everything
	system("taskkill /F /IM msedgee.exe");
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

/*
*   Function to generate a random string from a pre-configured array
*/ 
const char* getRandomString(const char* stringArray[], int numStrings) {
    static const char** usedStrings = NULL;
    static int usedStringsCount = 0;

    // If all strings have been used, reset the state
    if (usedStringsCount == numStrings) {
        free(usedStrings);
        usedStrings = NULL;
        usedStringsCount = 0;
    }

    // Initialize the random number generator with the current time
    srand((unsigned int)time(NULL));

    // If there are no used strings, create a temporary array
    if (usedStrings == NULL) {
        usedStrings = (const char**)malloc(numStrings * sizeof(const char*));
        memcpy(usedStrings, stringArray, numStrings * sizeof(const char*));
    }

    // Choose a random string from the unused ones
    int randomIndex = rand() % (numStrings - usedStringsCount);
    const char* newString = usedStrings[randomIndex];

    // Remove the used string from the temporary array
    usedStrings[randomIndex] = usedStrings[numStrings - usedStringsCount - 1];
    usedStringsCount++;

    return newString;
}

/*
 * starting from the generated string, the method opens an edge page with the search of the generated string
//old
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
*/
