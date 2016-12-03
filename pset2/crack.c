#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

char* bruteForce(char hash[], unsigned current[]);
char* convertToString(unsigned current[]);
char* encryptString(char currentString[]);

int main(int argc, string argv[]) {
    
    char* hash = argc == 2 ? argv[1] : "50fkUxYHbnXGw";
    unsigned* current[] = {65};
    char* password = bruteForce(hash, current);
    unsigned passwordFound = strcmp(password, "");

    if (passwordFound == 0) {
        printf("Password could not be matched\n");
        return 1;
    } else {
        printf("Password: %s\n", password);
        return 0;
    }
}

char* bruteForce(string hash, unsigned current[]) {
    
    char* currentString = convertToString(current);
    char* encryptedString = encryptString(currentString);
    unsigned matchesHash = strcmp(encryptedString, hash);
    unsigned matchesUpwardBound = strcmp(currentString, "zzzz");
    
    printf("Match: %i\n", matchesHash);
    printf("Encrypted String: %s\n", encryptedString);
    printf("Hash : %s\n", hash);
    printf("currentString : %s\n", currentString);
    
    
    if (matchesHash == 0) {
        return currentString;
    }
    
    if (matchesUpwardBound == 0) {
        return "";
    }
    
    // unsigned nextCurrent[] = getNextCurrent(current);
    // return brutForce(hash, nextCurrent);
    return "nah";
}

// unsigned getNextCurrent(unsigned *current) {
    // get length
    // start at end of array
    // if int != 122
        // int =  int == 90 ? 97 : int++
    // else
        // next item in array if none append && reset ^ 
// }

char* convertToString(unsigned current[]) {
    unsigned length = 3;
    char* passwordArray[3];
    
    for (unsigned i = 0; i < length; i++) {
      passwordArray[i] = (char) current[i];
    }

    // printf("passwordArray: %s\n", **passwordArray);
    // char* passwordArray2 = {"A"};
    return passwordArray;
}

char* encryptString(char currentString[]) {
    char* encryptedString = crypt(currentString, "pw");
    return encryptedString;
}