#include<stdio.h> 
#include<stdlib.h>

// Function prototype for the fibonacci function
void fibonacci (int *a, int *b);

int main() {

  int n, i;
  int f0=0, f1=1;
  
  printf("Enter a positive integer\n");
  scanf("%d", &n);

  // Checking if the input is a positive integer
  if(n<1) {
    printf("The number is not positive. \n");
	exit(1);
  }

  printf("The fibonacci sequence is \n");
  printf("%d, %d, ", f0, f1);

  // Calculating fibonacci sequence from 2 
  for (i=2; i<=n; i++) { 
    fibonacci(&f1, &f0);
	printf("%d, ", f1);
  if((i+1)%10 == 0) printf("\n"); 
  }

  return 0;
}

// Function to generate next number in the fibonacci sequence
void fibonacci(int *a, int *b){

  int next;
  // Calculating the next number in the fibonacci sequence
  next=*a + *b;

  // Updating value of a and b to generate next number
  *b=*a;
  *a=next;
}