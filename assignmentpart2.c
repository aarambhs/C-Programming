#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//calling standard C libraries

//generating func prototypes for rand_u and pci
double rand_u (double Lower, double Upper);
double pci (double mean, double variance, int n_samples);




//main loop, returns value 0 after executed to exit script
int main(void){
  srand(time(0));
  //rand function seeded with time to generate 'true' random numbers
  double number;
  double mean;      //initialising global variables
  double sum;
  double variance;
  double arrayvalues[100000];
  double pci_result;
  int n_samples;

  number = 0.0;
  mean = 0.0;
  sum = 0.0;
  variance= 0.0;
  pci_result = 100.0;
  n_samples = 0;

  
 //while loop runs until percentage confidence reaches 5%
  
 while(pci_result >5) {
  
  //incrementing index value of array
  

  arrayvalues[n_samples] = rand_u(0.0, 1.0); //calling rand_u func and inserting into arrayvalues
  sum = sum + arrayvalues[n_samples];
  mean = sum / n_samples;
  double differential;
  differential = 0.0;

  //calculating variance
  for(int index = 0; index < (n_samples); index++){

	differential = differential + pow(((arrayvalues[index])- mean), 2.0);
  }
	
 
  variance = (differential/n_samples);
  //pnly calculates pci if the number of samples is over 30
  if (n_samples> 30){

	pci_result = pci(mean, variance,n_samples);
   
	}
    n_samples++;

	
  }

  //prints final values of variables
  printf("FINAL VALUES:\nNumber of samples : %d \nSample mean : %lf, Variance : %lf \nPercentage confidence interval: %lf \n", n_samples, mean, variance, pci_result);

	return 0;
}

//defining rand_u function
double rand_u(double Lower, double Upper)
{

  double value= rand();//initialising new variable for rand

    return (value * (Upper - Lower) / (double) RAND_MAX + Lower); //returns double value between the ranges given
}



double pci(double mean, double variance, int n_samples){
  double percentageconfidence;
  //new variable percentageconfidence used to temporarily store calculations
  percentageconfidence =  3.92*(sqrt(variance))/(sqrt(n_samples));
  percentageconfidence = ((percentageconfidence / mean)* 100);
 //following the standard equation given to calculate pci

  return(percentageconfidence);

}



