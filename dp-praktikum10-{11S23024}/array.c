#include <stdio.h>

int main (){
  // Array satu demensi 
  int arr[5] = {10, 20, 30, 40, 50};

  // Menampilkan elemem-elemen array satu dimensi 
  printf ("Array satu dimensi\n");
  for (int i = 0; i<5 ; i++) { // gak boleh ada titik koma setelah dalam kurung biasa 
    printf ("%d ",  arr[i]);
  }
  printf ("\n\n");

  // Array dimensi 
  printf ("Array dua dimensi\n");
  int matriks [3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  }; // jangan lupa titik koma

  // Menampilkan elemen-elemen array dua dimensi 
  for (int i = 0 ; i < 3 ; i++) {
    for (int j = 0; j < 3; j++)
    {
      printf ("%d", matriks [i][j]);
    }
    printf ("\n");
  }
  return 0 ; 
}