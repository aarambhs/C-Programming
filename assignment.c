#include <stdio.h>
#include <stdlib.h>       //calling standard c libraries
#include <time.h> 

//generating prototype for rand_coin function
int rand_coin();

//main loop returns 0 when finished executing
int main() {

  srand(time(0));
  //seeding time domain into random function
  int loopsmax = 3;
  //the test will be completed 3 times (3 sets of data)

  int loops = 0;
  
  //coins will flipped 2000 times in one set
  //completes the test up to the number in loopsmax
  for (loops = 0; loops < loopsmax; loops++){
    rand_coin();
  }

}

//defining function of rand_coin
int rand_coin()
{

  int countermax = 2000;

int heads;
int tails;
int counter;


int coin;
heads = 0;
tails = 0;




  //loops up to the amount saved in countermax
  for (counter = 0; counter < countermax; counter++){

    coin = rand();



    //int value is generated, work out modulus of 2 to either have a value of 0 or 1
    if (coin%2 == 0 ){
      heads++;
    }
    else{
      tails++;
    }

}

//prints outcome
printf("Heads = %d", heads);
printf(", Tails = %d\n", tails );
heads = 0;
tails = 0;

//outputs null to exit script
return 0;

}
