#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

char* encryptPassword(char passwordChar[]) {
    char* encryptedPassword = crypt(passwordChar, "50");
    return encryptedPassword;
}

char* convertToChar(unsigned passwordInt[], unsigned length) {
    char passwordChar[length];
    
    for (unsigned i = 0; i < length; i++) {
        passwordChar[i] = (char) passwordInt[i];
    }
    
    passwordChar[length] = '\0';
    char *tmp = malloc(length);
    sprintf(tmp, "%s", passwordChar);

    return tmp;
}

unsigned* copyArray(unsigned intArray[], unsigned length) {
    unsigned * tmp = malloc(sizeof(int) * length);
    memcpy(tmp, intArray, length * sizeof(int));
    return tmp;
}

unsigned* getNextPasswordInt(unsigned passwordInt[], unsigned length, unsigned offset) {

    if (passwordInt[length - offset] == 90) {
        passwordInt[length - offset] = 97;
        return copyArray(passwordInt, length);
    } else if (passwordInt[length - offset] == 122) {
        offset = offset + 1;
        return getNextPasswordInt(passwordInt, length, offset);
    } else {
        passwordInt[length - offset] = passwordInt[length - offset] + 1;
        return copyArray(passwordInt, length);
    }

}

unsigned* getNewIntArray(unsigned length) {
    if (length == 2) {
        unsigned intArray[] = {65, 65};
        return copyArray(intArray, length);
    } else if (length == 3) {
        unsigned intArray[] = {65, 65, 65};
        return copyArray(intArray, length);
    } else if (length == 4) {
        unsigned intArray[] = {65, 65, 65, 65};
        return copyArray(intArray, length);
    } else {
        unsigned intArray[] = {65};
        return copyArray(intArray, length);
    }
}

char* bruteForce(char hash[], unsigned passwordInt[], unsigned length) {

    char* passwordChar = convertToChar(passwordInt, length);
    char* passwordHash = encryptPassword(passwordChar);

    unsigned matchesHash = strcmp(passwordHash, hash);
    unsigned matchesUpperBound1 = strcmp(passwordChar, "z");
    unsigned matchesUpperBound2 = strcmp(passwordChar, "zz");
    unsigned matchesUpperBound3 = strcmp(passwordChar, "zzz");
    unsigned matchesUpperBound4 = strcmp(passwordChar, "zzzz");

    // printf("%s\n", passwordChar);
    
    if (matchesHash == 0) {
        return passwordChar;
    }
    
    if (matchesUpperBound4 == 0) {
        return "";
    }

    unsigned * nextPasswordInt;
    if (matchesUpperBound1 == 0 || matchesUpperBound2 == 0 || matchesUpperBound3 == 0) {
        length = length + 1;
        unsigned * array;
        array = getNewIntArray(length);
        nextPasswordInt = getNextPasswordInt(array, length, 1);
    } else {
        nextPasswordInt = getNextPasswordInt(passwordInt, length, 1);
    }

    return bruteForce(hash, nextPasswordInt, length);
}

int main(void) {
    char* hash2 = encryptPassword("andi");
    printf("%s\n", hash2);
    char* hash = "50fkUxYHbnXGw";
    unsigned passwordInt[] = {65};
    unsigned length = 1;
    char* password = bruteForce(hash, passwordInt, length);

    printf("%s\n", password);
}