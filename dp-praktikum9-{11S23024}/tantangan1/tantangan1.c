#include <stdio.h>

int main (){
  // Mari buat asumsi angka yang mau kita tebak adalah 51

  int target;
  int myGuess, totalGuess = 0 ;
  printf ("Silahkan tebak angka antara 1 sampai 100: \n");
  do {
    scanf("\n%d",&target);
    if (target > 51) 
    {
    printf("Angka lebih kecil!\n"); 
    }
    else if (target < 51) {
    printf("Angka lebih besar!\n");
  } else {
    printf("Hore, kamu berhasil menebak angka dengan benar.\n");
  }
    totalGuess++;
  } while ( target != 51 ); 
  printf("Jumlah tebakan kamu sebanyak: %d ",totalGuess);

  return 0;
}
