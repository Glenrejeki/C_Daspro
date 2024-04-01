#include <stdio.h> 
#include <stdbool.h>

int main () {

  // Operator aritmatika
  int angka1 = 10, angka2 = 5;
  int hasiPejumlahan = angka1 + angka2 ;
  int hasilPengurangan = angka1 - angka2 ;
  int hasilPerkalian = angka1 * angka2 ;
  int hasilPembagian = angka1 / angka2 ; 
  int sisaBagi = angka1 % angka2 ;
  
  printf ("Penjumlahan : %d\n", hasiPejumlahan);
  printf ("Pengurangna : %d\n",hasilPengurangan);
  printf ("Perkalian : %d\n",hasilPerkalian );
  printf ("Pembagian : %d\n", hasilPembagian );
  printf ("Sisa bagi : %d\n", sisaBagi);

  //Operasi  relasional 
  int nilai1 = 5, nilai2 = 10;
  bool relasional1 = nilai1 > nilai2;
  bool relasional2 = nilai1 < nilai2;
  bool relasional3 = nilai1 == nilai2; 
  bool relasional4 = nilai1 != nilai2;

    // jangan lupa petik dua dalam kurung saat printf 
  printf ("%d > %d is %s\n", nilai1, nilai2, relasional1 ? "benar" : "salah");
  printf ("%d<%d is %s\n", nilai1, nilai2, relasional2 ? "benar" : "salah");
  printf ("%d == %d is %s\n", nilai1, nilai2, relasional3 ? "benar" : "salah");
  printf ("%d != %d is %s \n", nilai1, nilai2, relasional4 ? "benar" : "salah");

  // Operator logika
  bool kondisi1 = true, kondisi2 = false;
  bool logika1 = kondisi1 && kondisi2 ;
  bool logika2 = kondisi1 || kondisi2 ;
  bool logika3 = !kondisi1 ; // negasi = megubah nilai kebenaran, jadi true = 1 dan false = 0 jadi disi kita mengubah fakta nilai benar menjadi false atau 0 atau null

  printf ("%d && %d is %s\n", kondisi1, kondisi2, logika1 ? "benar" : "salah");
  printf ("%d || %d is %s \n", kondisi1, kondisi2, logika2 ? "benar" : "salah") ;  
  printf ("%d ! %d is %s\n", kondisi1, kondisi2, logika3);
  
  // Operasi Teranary 
  int angka = 42 ;
  bool genap = (angka %2 == 0 ) ; 
  printf ("Nilai %d adalah %s\n", angka, genap ? "benar" : "salah");

  // Opertor Bitwise 
  int a = 60 ; 
  int b = 13 ; 

  int hasilAnd = a & b ;
  int hasilOr = a | b ; 
  int hasilXor = a ^ b ;
  int hasilLeftShift = a << 2 ;
  int hasilRightShift = a >> 2 ; 
  int hasilNotA = ~ a ; 

  printf ("Hasil And : %d\n", hasilAnd);
  printf ("Hasil OR : %d\n ", hasilOr);
  printf ("Hasil Left Shift : %d\n", hasilLeftShift);
  printf ("Hasil Right Shift : %d\n", hasilRightShift);
  printf ("Hasil NOT dari a : %d\n",hasilNotA);
  return 0;
}