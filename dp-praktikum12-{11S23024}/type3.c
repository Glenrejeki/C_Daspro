#include <stdio.h>
#include <stdlib.h>

struct Mahasiswa
{
  char nama [100];
  char nim [9];
  float ipk;
};

// Fungsi untuk mengisi data mahasiswa
struct Mahasiswa inputDataMahasiswa ()
{
  struct Mahasiswa mhs;
  printf ("Masukkan nama Mahasiswa :");
  scanf ("%s", mhs.nama);
  printf ("Masukkan NIM Mahasiswa :");
  scanf ("%s",mhs.nim);
  printf("Masukkan IPK : ");
  scanf ("%f", &mhs.ipk);
  return mhs;
};

// Fungsi untuk menampilkan data mahasiswa 
void tampilDataMahasiswa (struct Mahasiswa mhs){
  printf("Nama mahasiswa : %s\n", mhs.nama);
  printf ("Nim Mahasiswa :%s\n", mhs.ipk);
  printf ("IPK Mahasiswa : %2.f", mhs.ipk);
}


int main (){
  struct Mahasiswa mhs = inputDataMahasiswa();
  tampilDataMahasiswa(mhs);
  return 0;
}