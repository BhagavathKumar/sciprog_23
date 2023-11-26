#include<stdio.h>
#include<math.h>

// intitatizing global variable
double degtorad(double degree);
double trap_rule(int n);

int main(){
 int n = 12;
 double integral_approx = trap_rule(n);
 double integral_exact = log(2.0);

 printf("Your approximation of the integral from x=0 degrees to x=60 degrees of the funtion tan(x) with respect to x is:\n%.5f\nThe exact solution is:\n%.5f\n", integral_approx, integral_exact); 

}

// Function to convert degrees to radians
double degtorad(double degree){
 return (degree * M_PI)/180;
}

// Function to approximate integral using trapezoidal rule
double trap_rule(int n){

 int i;
 // Array to store tangent values
 double tan_values[n+1], degree, radians, width;
 // Calculate tangent values for each interval
 for(i=0; i<=n; i++){
  degree = i * 5.0;
  radians = degtorad(degree);
  tan_values[i] = tan(radians);
  // Uncomment below line to print tangent values for each degree
  //printf("tan_values[%d] = %f at x=%.2f degrees\n", i, tan_values[i], degree);
  }
  
 // Calculate area using trapezoidal rule
 double area = tan_values[0] + tan_values[n];
 for(i=1; i<n; i++) {
  area += 2.0*tan_values[i];	
 }
 
 // Calculate width of each interval
 width = degtorad((60.0 - 0)/(2.0*n));
 area = width*area;
 
 return area;
  
}
