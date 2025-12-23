#include <stdio.h>

//First function
int f(int n){
  if(n == 1){
    return 1;
  }
  return f(n-1)*2;
}
/*
Base case: happen when n = 1; 
Result of the base case: f(1) = 1;
Before base case: f(2) = f(1) * 2 = 1 * 2;
Before before: f(3) = f(2) * 2 = (f(1) * 2) * 2 = 1*4 = 4;
*/


//Second function
float g(int n){
  if( n == 1 ){
    return (float) 1;
  }
  return n*n + g(n-1);
}

/*
Base case: occurs when n = 1;
Result of the base case: g(1) = 1;
Before base case: g(2) = 2*2 + g(1) = 2*2 + 1 = 5;
Before before: g(3) = 3*3 + g(2) = 9 + 2*2 +g(1) = 14;
*/


//Third function
int F(int n){
  if(n == 1) return 1;
  if(n == 2) return 1;
  return F(n-1) + F(n-2);
}
/*
Base case: happen when n = 1 or n = 2;
Result of base case: F(1) = F(2) = 1;
Before base case: F(3) = F(2) + F(1) = 1 + 1 = 2;
Before before: F(4) = F(3) + F(2) = (F(2) + F(1)) + F(2) = 3;
*/


//Fourth function
int P(int n){
  if(n == 0) return 1;
  if(n == 1) return 2;
  if(n == 2) return 3;
  return P(n-1) * P(n-3);
}
/*
Base case: happen when n = 0 or n = 1 or n = 2;
Result of base case: P(0) = 1; P(1) = 2; P(2) = 3;
Before base case: P(3) = P(2) * P(0) = 3;
Before before: P(4) = P(3) * P(1) = P(2) * P(0) * P(1) = 6;
*/

int main(){
  printf("My name is Po! Hi!");
  return 0;
}
