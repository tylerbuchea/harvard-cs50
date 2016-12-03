#include <cs50.h>
#include <stdio.h>

unsigned promptUserForHeight(void);
void buildPyramid(unsigned height);
void repeatChar(char character, unsigned repeatLength);

int main(void) {
    unsigned height = promptUserForHeight();
    buildPyramid(height);
}

unsigned promptUserForHeight() {
    printf("Height: ");
    unsigned userInput = get_int();
    unsigned height = userInput < 24 ? userInput : promptUserForHeight();
    
    unsigned int sup = -1;
    printf("%i\n", sup);

    return height;
}

void buildPyramid(unsigned height) {
    for (unsigned i = 0; i < height; i++) {
        unsigned numberOfBricks = i + 1;
        unsigned numberOfSpaces = height - numberOfBricks;

        repeatChar(' ', numberOfSpaces);
        repeatChar('#', numberOfBricks);
        printf("  ");
        repeatChar('#', numberOfBricks);
        printf("\n");
    }
}

void repeatChar(char character, unsigned repeatLength) {
    for (unsigned i = 0; i < repeatLength; i++) {
        printf("%c", character);
    }
}