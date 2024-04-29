#include <stdio.h>

int main (){
  int x = 10;
  int *ptr ;
  ptr = &x;


  printf ("Nilai dari x : %d\n",x);
  printf ("Alamat memori x : %p\n", &x);
  printf("Nilai dari *ptr : %d\n", *ptr);
  printf ("Alamat memori yang ditunjukkan oleh ptr : %p\n", ptr);

  return 0;
}