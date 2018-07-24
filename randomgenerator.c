#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double rand_u(double Lower, double Upper)
{

  double value= rand();//initialising new variable for rand

    return (value * (Upper - Lower) / (double) RAND_MAX + Lower); //returns double value between the ranges given
}
int main(void){
	srand(time(0));
	double randomvalue = rand_u(-25,25);
	printf("%lf\n",randomvalue );

	return 0;
}