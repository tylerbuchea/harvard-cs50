#include <cs50.h>
#include <stdio.h>
#include <math.h>

float makeThemPay(void);
unsigned numberOfCoinsInAmount(unsigned coin, unsigned amount, unsigned total);
unsigned dispenseChange(unsigned amount);

int main(void) {

  unsigned amount = makeThemPay() * 100;

  unsigned total = dispenseChange(amount);
  printf("%i\n", total);
}

float makeThemPay() {
    printf("How much change is owed?\n");
    float userInput = get_float();
    float amount = userInput < 0 ? makeThemPay() : userInput;
    if (userInput < 0) {
      return makeThemPay();
    }

    return amount;
}

unsigned numberOfCoinsInAmount(unsigned coin, unsigned amount, unsigned total) {
  // unsigned remainder = amount % coin;
  unsigned count = amount / coin;

  return count;
}

unsigned dispenseChange(unsigned amount) {
    unsigned coin[] = {25, 10, 5, 1};
    unsigned coinCount = 0;

    for (unsigned i = 0; i < 1; i++) {
      coinCount = coinCount + numberOfCoinsInAmount(coin[3], amount, 0);
      // amount = amount - coin[i] * coinCount;
    }
    
    return coinCount;
}