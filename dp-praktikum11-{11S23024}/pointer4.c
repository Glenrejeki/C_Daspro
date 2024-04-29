#include<stdio.h>

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}


int main (){
  int a = 5, b = 10 ;
  printf ("Nilai sebelum ditukar : a = %d, b = %d\n", a, b);
  

  swap(&a, &b);
  printf ("Nilai setelah ditukar : a = %d, b = %d \n", a, b);

  return 0;
}