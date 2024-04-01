#include <stdio.h> 
#include <stdbool.h>

int main (){

  // Tipe data integer 
  int angka = 42;

  //Tipe data floating-point
  float angkaDesimal = 3.141592653589793;

  // Tipe data karakter 
  char karakter = 'A';

  // Tipe data string 
  char kata [] = "Abdullah Ubaid ";

  // Tipe data boolean 
  bool kondisi = true ;

  // Menampilkan nilai dari setiap variabel 
  printf ("Tipe data integer : %d\n", angka);
  printf ("Tipe data floating point : %f\n", angkaDesimal); // untuk mnampilkan float harus pakai %f
  printf ("Tipe data double : %lf \n", angkaDesimal); //Untuk memanggil double harus pakai %lf
  printf ("Tipe data karakter : %c \n",karakter); // Untuk memamngil karakter harus pakai %c
  printf ("Tipe data string : %s", kata);
  printf ("Tipe data boolean : %s\n", kondisi ? "benar" : "salah");

  return 0;
}