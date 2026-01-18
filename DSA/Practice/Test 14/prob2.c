#include <stdio.h>


int sumLowToHigh(int low, int high){
  if(high == low) return low;
  
  return sumLowToHigh(low, high-1) + high;
}

//we can treat high or low like a variable to run recursion(i use high)

//basecase: when high == low;
//basecase result: return low;(return 1)

//before basecase: high - 1 == low;
//return high + sumLowToHigh(low, high - 1) = high + low; (2+1)

//before before: high - 2 == low;
//return sumLowToHigh(low, high - 1) + high = sumLowToHigh(low, high - 1) + high - 1 + high;
//= low + high-1 + high 
int main(){
  printf("%d", sumLowToHigh(1, 10));
}
