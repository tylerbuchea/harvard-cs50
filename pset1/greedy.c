#include <cs50.h>
#include <stdio.h>
#include <math.h>

float makeThemPay(void);
unsigned numberOfCoinsInAmount(unsigned coin, unsigned amount, unsigned total);
void dispenseChange(unsigned amount);

int main(void) {
    printf("O hai! ");
    unsigned amount = makeThemPay() * 100;
    dispenseChange(amount);
}

float makeThemPay() {
    printf("How much change is owed?\n");
    float userInput = get_float();
    float amount = userInput < 0 ? makeThemPay() : userInput;

    return amount;
}

void dispenseChange(unsigned amount) {
    unsigned coin[] = {25, 10, 5, 1};
    unsigned coinCount = 0;
    
    for (unsigned i = 0; i < 3; i++) {
      coinCount = coinCount + numberOfCoinsInAmount(coin[0], amount, 0);
      amount = amount - coin[0] * coinCount;
    }
    
    printf("sup: %i\n", coinCount);
}

unsigned numberOfCoinsInAmount(unsigned coin, unsigned amount, unsigned total) {
  unsigned remainder = amount % coin;

  if (remainder == 0) {
    return total;
  }
  
  total += floor(amount / coin);

  return numberOfCoinsInAmount(coin, remainder, total);
}