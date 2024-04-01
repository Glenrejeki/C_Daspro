#include <stdio.h>
#include <stdbool.h>

int main() {
    char nama[200];
    printf("Masukkan nama Anda: ");
    scanf(" %[^\n]", nama);

    int usia;
    printf("Masukkan usia Anda: ");
    scanf("%d", &usia);
    printf("Hay %s, kamu telah berusia %d tahun.\n", nama, usia);

    char hobi[200];
    printf("Masukkan hobi Anda: ");
    scanf(" %[^\n]", hobi);

    int kondisi1;
    printf("Masukkan kondisi (0 untuk salah, 1 untuk benar): ");
    scanf("%d", &kondisi1);

    printf("Kamu memiliki hobi %s dan %s kamu seorang pelajar.\n", hobi, kondisi1 ? "benar" : "salah");

    return 0;
}
