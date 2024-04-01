#include <stdio.h>
#include <string.h>
#include <stdbool.h>


  int main (){

    
    char nama[200];
    scanf ("%[^\n]s ", nama);

    int usia ;
    scanf ("%d", &usia);
    printf ("Hay %s, kamu telah berusia %d tahun.\n", nama, usia);


  char hobi[200];
  scanf(" %[^\n]", hobi);


  int kondisi1 ;
  scanf ("%d", &kondisi1);

  printf ("Kamu memiliki hobi %s dan %s kamu seorang pelajar.",hobi, kondisi1  ? "benar" : "salah");
    return 0;
  }