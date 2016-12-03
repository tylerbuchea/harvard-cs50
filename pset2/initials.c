#include <cs50.h>
#include <stdio.h>
#include <string.h>

void printInitials(char* initials, int length) {
    for (unsigned i = 0; i < length; i++) {
        printf("%c", initials[i]);
    }
    printf("\n");
}

char* getInitials(string username[], int length) {
    
    char initials[length];

    for (unsigned i = 0; i < length; i++) {
        initials[i] = username[i + 1][0];
    }

    initials[length] = '\0';
    char *tmp = malloc(length);
    sprintf(tmp, "%s", initials);

    return tmp;
}

int main(int argc, string argv[]) {

    if (argc == 0) {
        printf("Error: Initials requires a name as an argument.");
        return 1;
    } else {
        char* initials = getInitials(argv, argc - 1);
        printInitials(initials, argc);
        return 0;
    }
    
}