#include <stdio.h>

int main (){
  int arr [] = {1, 2, 3, 4, 5};
  int *ptr = arr;


  printf ("Isi dari arr menggunakan pointer :\n");
  for (int  i = 0; i < 5; i++)
  {
    printf ("arr[%d] = %d\n", i, *(ptr + i) ); // jangan sampai salah tulis i menjadi 1
  }
return 0;
}