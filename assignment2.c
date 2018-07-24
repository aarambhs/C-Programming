#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Function prototypes
double rand_u (double Lower, double Upper);
double pci (double mean, double variance, int n_samples);
double sum_array(double array[], int n_samples);
double calc_mean(double sum, int n_samples);
double calc_variance(double array[], int n_samples, double mean);

int main(void)
{
    srand(time(NULL)); //Seed rand_u function

    double array[100000];
    double sum = 0.0, mean = 0.0, variance = 0.0;
    double pci_result = 100.0;

    int n_samples;

    for (n_samples = 0; pci_result > 5; n_samples++) {
        array[n_samples] = rand_u(0.0, 1.0);
        sum = sum_array(array, n_samples);
        mean = calc_mean(sum, n_samples);
        variance = calc_variance(array, n_samples, mean);

        if (n_samples >= 30) {
            pci_result = pci(mean, variance, n_samples);
        }
    }

    printf("FINAL VALUES:\n");
    printf("No. of samples: %d, Sample mean = %lf, Variance = %lf \n", n_samples, mean, variance);
    printf("Percentage confidence interval: %lf \n", pci_result);

    return 0;
}

//Functions

//Generate random number between specified lower/upper bound
double rand_u(double Lower, double Upper)
{
    return ((double) rand() * (Upper - Lower) / (double) RAND_MAX + Lower); //Return randomly generated double between lower and upper bound
}

//Calculate percentage confidence interval
double pci(double mean, double variance, int n_samples)
{
    double tmp; //to make pci formula easier to read, using tmp variable
    tmp = 1.96 * ((sqrt(variance))/(sqrt(n_samples)));
    return (2 * (tmp/mean) * 100);
}

//Sum all elements in an array
double sum_array(double *array, int n_samples)
{
    double sum = 0.0;
    for(int i = 0; i < n_samples; i++) {
        sum += *(array + i);
    }
    return(sum);
}

//Calculate mean
double calc_mean(double sum, int n_samples)
{
    return(sum / n_samples);
}

//Calculate variance
double calc_variance(double *array, int n_samples, double mean)
{
    double sum_sq_diff = 0.0;
    for (int i = 0; i < n_samples; i++) {
        sum_sq_diff += (*(array + i) - mean) * (*(array + i) - mean);
    }
    return(sum_sq_diff / (n_samples - 1));
}
