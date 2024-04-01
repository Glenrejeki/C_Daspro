#include <stdio.h>

int main () {
  // If - else statement 
  int nilai = 73 ; 

  if (nilai >= 80) {
    printf ("Nilai A\n");
  }
  else if (nilai >= 70) {
    printf ("Nilai B\n");
  }
  else if (nilai >= 60 ) {
    printf ("Nilai C\n");
  }
  else {
    printf ("Nilai D\n");
  }


  // Switch- Case statement
  char pilihan = 'c';
  switch (pilihan)
  {
  case 'A':
  case 'a':
  printf ("Anda memilih opsi A\n");
    break; 
  case 'B':
  case 'b':
  printf ("Anda memilih opsi C\n");
  break; 

  case 'C':
  case 'c':
  printf ("Anda memilih opsi C\n");
  break; 

  default :
  printf("Pilihan tidak valid \n");
  // switch hampir mirip fungsinya dengan if else tapi disini gk perlu simbol "||" 
  
  }
  return 0;

}