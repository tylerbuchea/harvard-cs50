#include <cs50.h>
#include <stdio.h>

int main(void)
{
    unsigned int showerTime = get_int();
    int ouncesOfWaterPerMinute = 192;
    int totalBottlesOfWater = showerTime * ouncesOfWaterPerMinute / 16;
    printf("%i\n", totalBottlesOfWater);
}