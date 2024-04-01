#include <stdio.h> 


// Fungsi rekursif untuk menghitung faktorial
int faktorial (int n ) { // ini terpisah dari int main, karena ini cuma prosedur bukan untuk print
  if (n<=1) {
    return 1;
  } else {
    return n * faktorial ( n -1 );
  }
}
  // Memanggil fungsi rekursif 
int main (){
  int n = 5;
  int result = faktorial (n);
  printf ("\n Hasil faktorial %d = %d", n, result);


  // Looping dnengan for
  printf ("\nLooping dengan for : \n");
  for (int i = 1; i <= 5; i++){ // ini maksudnya mencoba untuk menampikan angka 1-5
    printf ("%d",i);
  }
  printf ("\n"); 

  // Looping dengan while 
  printf ("\nLooping dengan while\n");
  int i = 1 ;
  while (i <= 5) // tidak bisa menempatkan increment di luar print, karena tidak akan loopin dan hasilnya outputnya malah 6
  {
    printf ("%d",i);
    i++; // jangan lupa increment untuk mencegah infinite loop
  }
  printf ("\n");

  // Loping dengan do-while 
  printf ("\nLooping dengan do-while : \n");
  int j = 1 ;
  do {
    printf ("%d",j);
    j++; // jangan lupa increment untuk mencegah infinite loop
  } while ( j <= 5);
  

  
  
}