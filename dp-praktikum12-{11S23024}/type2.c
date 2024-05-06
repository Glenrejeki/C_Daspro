#include <stdio.h>
#include <string.h>

struct Mahasiswa 
{
  char nim[9];
  char nama[50];
  int umur;
};

void tampilData(struct Mahasiswa mhs){
  printf("NIM : %s\n", mhs.nim);
  printf("Nama : %s\n", mhs.nama);
  printf("Umur : %d\n", mhs.umur);
}

int main() {
  struct Mahasiswa mhs1 = {"11S18005", "Abdullah Ubaid", 22};
  tampilData(mhs1);

  return 0;
}
