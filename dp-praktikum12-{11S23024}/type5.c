#include <stdio.h>
#include <string.h>

typedef struct
{
  char nim [9];
  char nama[50];
  float ipk;
}Mahasiswa;


void inputData(Mahasiswa *m){
  printf ("Masukkan Nim : ");
  scanf ("%s", m->nim);
  printf ("Masukkan nama : ");
  scanf ("%s", m-> nama);
  printf ("Masukkan IPK : ");
  scanf ("%f",m->ipk);
}

void printData(Mahasiswa *m){
  printf("Nim :%s\n", m->nim);
  printf ("Nama : %s\n", m-> nama);
  printf ("IPK : %.2f\n", m->ipk);
}

int main (){
  Mahasiswa m1;
  Mahasiswa *ptr;
  ptr = &m1;
  inputData(ptr);
  printData(ptr);

  return 0;
}