#include<stdio.h>
#include<math.h>

// Function prototype for Maclaurin series approximation
double archtanh1(const double x, const double delta);

// Function prototype for formula
double archtanh2(const double x);

int main() {

 double delta, x;
 printf("Enter the precession for the Maclauren series:\n");
 scanf("%lf", &delta);

 int length = 1000;
 double tan1[length]; // Array to store the result of archtan1
 double tan2[length]; // sArray to store the result of archtan2

 int j =0; //j: array index
 x = -0.9;
 while(x<0.9 && j<length) {
  tan1[j] = archtanh1(x, delta);
  tan2[j] = archtanh2(x);
  printf("The difference at x=%lf between is %.10lf.\n", x, fabs(tan1[j]-tan2[j]));
 j++;
 x = x+0.1;

}

 return 0;
}

// Maclaurin series approximation of arctanh()
double archtanh1(const double x, const double delta) {
 double archTan = 0; // approximation
 double elem, val; // element in the sereis
 int n=0; // sum parameter

 do{
  val = 2*n+1;
  elem = pow(x, val)/val; // Calculation of each element in the series
  archTan += elem; // summing elements
  n++;

 } while(fabs(elem) >= delta); // Loop until the desired precision is reached

 return archTan;
}

// Direct formula for the archtanh() - natural logarithm
double archtanh2(const double x) {

 return (log(1+x) - log(1-x))/2;

}
