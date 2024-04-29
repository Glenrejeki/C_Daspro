#include <stdio.h>

int main (){
  // Array satu dimensi
  int arr [5] = {10, 20, 30, 40, 50};

  // Menampilkan elemen-elemen array satu dimensi 
  printf("Array satu dimensi\n");
  for (int i =0; i < 5 ; i++){
    printf ("%d",arr[i]);
  }
  printf("\n\n");

  // Array dua dimensi 
  int matrix [3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};

  // Menampilkan elemen-elemen array dua dimensi 
  printf ("Array dua dimensi : \n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j <3; j++)
    {
      printf ("%d", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;

}