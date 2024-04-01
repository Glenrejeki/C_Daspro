#include <stdio.h> 

// Mendefinisikan konstanta 
#define PI  3.14

int main (){
  // Deklarasi variabel
  int n1 ;
  n1 = 10 ;
  printf("n1 = %d\n",n1);

  // Deklarasi banyak variabel 
  int x, y, z ;
  x=1;
  y=0;
  z=-1;
  printf ("x=%d, y = %d, z = %d\n",x,y,z);// Untuk memanggil variabel int harus pakai %d


  // Deklarasi dan inisialisasi variabel 
  int n2 = 100;
  printf ("n2 = %d\n",n2);

  // Menampilkan nilai konstanta 
  printf ("PI = %f", PI); // untuk memanggil varibel yang gk int harus pakai %ff
  return 0;

}