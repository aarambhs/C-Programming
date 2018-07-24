#include <stdio.h>
#include <math.h>

int main (void) {
  double square_roots [100];        /* declare an array of type double called 'square_roots' */
  for (int i=1; i<=100; i++) {
    square_roots[i] = sqrt(i);     /* store the square root of each number */
    }

  for (int i=100; i>0; i--) {       /* using a second for loop to print out the data */
    printf("square root of %d =\t%.3lf\n", i, square_roots[i]);
    }

  return 0;
}
