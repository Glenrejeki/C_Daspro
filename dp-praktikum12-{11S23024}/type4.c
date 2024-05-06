#include <stdio.h>
#include <string.h>

struct Mahasiswa {
  char nim[9];
  char nama[50];
  float ipk;
};

void inputData(struct Mahasiswa *m){
  printf ("Masukkan NIM :");
  scanf ("%s", m->nim);
  printf ("Masukkan Nama :");
  scanf("%s",m->nama);
  printf ("Masukkan IPK : ");
  scanf ("%f", &m->ipk);
}

void printData (struct Mahasiswa *m){
  printf("NIM : %s\n", m->nim);
  printf ("Nama :%s\n", m->nama);
  printf("IPK : %.2f\n", m->ipk);
}

int main (){
  struct Mahasiswa m1;
  struct Mahasiswa *ptr;
  ptr = &m1;
  
  inputData(ptr);
  printData(ptr);

  return 0;
}

