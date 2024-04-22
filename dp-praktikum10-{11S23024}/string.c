#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Untuk menggunakan malloc

int main() {
    char firstName[] = "Glen";
    char lastName[20];

    // Salin string
    strcpy(lastName, "Rejeki");

    // Menggabungkan string
    char fullName[50]; // Buat array yang lebih besar untuk menggabungkan nama
    strcpy(fullName, firstName); // Salin nama depan ke fullName
    strcat(fullName, " "); // Tambahkan spasi
    strcat(fullName, lastName); // Gabungkan dengan nama belakang

    // Menghitung panjang string
    int lenFullName = strlen(fullName);
    int lenLastName = strlen(lastName);

    // Menampilkan hasil
    printf("Nama Depan : %s\n", firstName);
    printf("Panjang Nama Depan: %d\n", strlen(firstName)); // Bisa juga menggunakan lenFullName
    printf("Nama Belakang: %s\n", lastName);
    printf("Panjang Nama Belakang: %d\n", lenLastName);
    printf("Nama Lengkap: %s\n", fullName);
    printf("Panjang Nama Lengkap: %d\n", lenFullName);

    // Membandingkan string
    int resultCompare = strcmp(firstName, lastName);
    if (resultCompare == 0) {
        printf("Nama Depan dan Nama Belakang sama.\n");
    } else {
        printf("Nama Depan dan Nama Belakang berbeda.\n");
    }

    // Deklarasi string
    char source[] = "Saya Sedang Belajar Bahasa Pemrograman C";

    // Menentukan panjang substring yang ingin diambil
    int lenSubstring = 19;
    char resultSubstring[lenSubstring + 1];

    // Potong string dengan strncpy
    strncpy(resultSubstring, source, lenSubstring);
    resultSubstring[lenSubstring] = '\0';

    // Menampilkan hasil
    printf("String Asli : %s\n", source);
    printf("String Potong : %s\n", resultSubstring);

    // Menggunakan strtok untuk memotong string
    char *token;
    token = strtok(source, " ");

    // Menampilkan setiap token hasil pemotongan
    int counter = 0;
    while (token != NULL) {
        counter++;
        printf("Token ke-%d: %s\n", counter, token);

        // Melanjutkan ke token berikutnya
        token = strtok(NULL, " ");
    }

    // String Array
    char names[3][10];
    strcpy(names[0], "Glen");
    strcpy(names[1], "Hizkia");
    strcpy(names[2], "Juan");

    for (int i = 0; i < 3; i++) {
        printf("Nama ke-%d = %s\n", (i + 1), names[i]);
    }

    return 0;
}
