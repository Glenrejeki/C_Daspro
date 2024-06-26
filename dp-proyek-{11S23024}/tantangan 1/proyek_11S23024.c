#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *tipe;
    char *merek;
    char *ukuran;
    char *warna;
    double harga;
    int stok;
} KatalogPakaian;

double totalPendapatan = 0; // Deklarasi variabel global totalPendapatan

// Deklarasi fungsi
void tampilkanPendapatan();
void tampilkanKatalog(KatalogPakaian *katalog, int jumlah);
void tambahKatalog(KatalogPakaian *katalog, int *jumlah);
void jualPakaian(KatalogPakaian *katalog, int *jumlah);

int main(){
    KatalogPakaian katalog[100]; // Maksimum 100 katalog
    int jumlah = 0;

    char pilihan;
    do {
        // Output awal
        tampilkanPendapatan();
        tampilkanKatalog(katalog, jumlah);
        printf("\nMenu:\n");
        printf("1. Tambah Katalog\n");
        printf("2. Baju Dijual\n");
        printf("x. Keluar\n");
        printf("Pilih: ");
        scanf(" %c", &pilihan);

        switch(pilihan) {
            case '1':
                tambahKatalog(katalog, &jumlah);
                break;
            case '2':
                jualPakaian(katalog, &jumlah);
                break;
            case 'x':
            case 'X':
                printf("\nMenutup aplikasi!\n");
                break;
            default:
                printf("\nPilihan tidak valid!\n");
        }
    } while(pilihan != 'x' && pilihan != 'X');

    return 0;
}

void tampilkanPendapatan() {
    printf("Total Pemasukan : $%.3lf\n", totalPendapatan);
}

void tampilkanKatalog(KatalogPakaian *katalog, int jumlah) {
    printf("Daftar Katalog Baju :\n");
    if (jumlah == 0)
        printf("- Belum ada daftar katalog baju yang tersedia\n");
    else {
        for (int i = 0; i < jumlah; i++) {
            printf("%d. %s (%s | %s | %s | $%.3lf/item) [%d tersedia]\n", i+1, 
                   katalog[i].merek, katalog[i].tipe, katalog[i].warna, 
                   katalog[i].ukuran, katalog[i].harga, katalog[i].stok);
        }
    }
}

void tambahKatalog(KatalogPakaian *katalog, int *jumlah) {
    printf("\nMenambah Katalog Baju:\n");
    printf("Brand (x Jika Batal) : ");
    char merek[50];
    scanf(" %[^\n]", merek);
    if (strcmp(merek, "x") == 0 || strcmp(merek, "X") == 0) {
        printf("Tindakan dibatalkan\n");
        printf("\n");
        return;
    }
    printf("Model : ");
    char tipe[50];
    scanf(" %[^\n]", tipe);
    printf("Ukuran : ");
    char ukuran[10];
    scanf(" %[^\n]", ukuran);
    printf("Warna : ");
    char warna[20];
    scanf(" %[^\n]", warna);
    printf("Harga ($) : ");
    double harga;
    scanf("%lf", &harga);
    printf("Stok Tersedia : ");
    int stok;
    scanf("%d", &stok);

    // Mengecek apakah katalog baju dengan merek, model, dan ukuran yang sama sudah ada
    for (int i = 0; i < *jumlah; i++) {
        if (strcmp(katalog[i].merek, merek) == 0 &&
            strcmp(katalog[i].tipe, tipe) == 0 &&
            strcmp(katalog[i].ukuran, ukuran) == 0 &&
            strcmp(katalog[i].warna, warna) == 0) {
            // Jika ada, hanya perbarui harga dan stok
            katalog[i].harga = harga;
            katalog[i].stok += stok;
            printf("SUKSES MEMPERBARUI HARGA DAN STOK KATALOG BAJU :  %s (%s | %s | %s)\n", 
                   merek, tipe, warna, ukuran);
            printf("\n");
            return;
        }
    }

    // Jika tidak ada, tambahkan katalog baru
    katalog[*jumlah].merek = strdup(merek);
    katalog[*jumlah].tipe = strdup(tipe);
    katalog[*jumlah].ukuran = strdup(ukuran);
    katalog[*jumlah].warna = strdup(warna);
    katalog[*jumlah].harga = harga;
    katalog[*jumlah].stok = stok;
    (*jumlah)++;

    printf("SUKSES MENAMBAH KATALOG BAJU :  %s (%s | %s | %s)\n", 
           merek, tipe, warna, ukuran);
    printf("\n");
}

void jualPakaian(KatalogPakaian *katalog, int *jumlah) {
    printf("\nBaju Dijual\n");
    int indeks;
    printf("No (0 Jika Batal) : ");
    scanf("%d", &indeks);

    if (indeks == 0) {
        printf("Tindakan dibatalkan\n");
        printf("\n");
        return;
    }

    if (indeks > *jumlah) {
        printf("Tindakan dibatalkan\n");
        printf("KATALOG BAJU dengan Posisi ke-%d tidak tersedia\n", indeks);
        printf("\n");
        return;
    }

    if (indeks >= 1 && indeks <= *jumlah) {
        printf("\nBaju Tersedia :\n");
        printf("%s (%s | %s | %s | $%.3lf/item) [%d tersedia]\n", 
               katalog[indeks-1].merek, katalog[indeks-1].tipe, 
               katalog[indeks-1].warna, katalog[indeks-1].ukuran, 
               katalog[indeks-1].harga, katalog[indeks-1].stok);

        int jumlahJual;
        printf("Jumlah Dijual : ");
        scanf("%d", &jumlahJual);

        if (jumlahJual <= 0) {
            printf("\nTindakan dibatalkan\n");
            printf("GAGAL MENJUAL BAJU : Jumlah penjualan barang minimal 1\n");
            printf("\n");
            return;
        }

        if (jumlahJual > katalog[indeks-1].stok) {
            printf("\nTindakan dibatalkan\n");
            printf("GAGAL MENJUAL BAJU : Stok tersedia [%d] tidak mencukupi jumlah ingin dijual [%d]\n",
                   katalog[indeks-1].stok, jumlahJual);
            printf("\n");
            return;
        }

        katalog[indeks-1].stok -= jumlahJual;
        double pendapatan = jumlahJual * katalog[indeks-1].harga;
        totalPendapatan += pendapatan;
        printf("\nBERHASIL MENJUAL BAJU : Pemasukan bertambah sebanyak $%.3lf\n", pendapatan);
        printf("\n");

        // Menghapus katalog jika stok habis
        if (katalog[indeks-1].stok == 0) {
            free(katalog[indeks-1].merek);
            free(katalog[indeks-1].tipe);
            free(katalog[indeks-1].ukuran);
            free(katalog[indeks-1].warna);
            for (int i = indeks - 1; i < *jumlah - 1; i++) {
                katalog[i] = katalog[i + 1];
            }
            (*jumlah)--;
        }
    }
}
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 
// JEKI CODINGAN 