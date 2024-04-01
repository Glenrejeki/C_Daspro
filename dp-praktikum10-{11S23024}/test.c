#include <stdio.h>

int main() {
    int row, col, num_spreads;
    
    // Input panjang baris dan kolom matriks
    scanf("%d %d", &row, &col);
    
    // Inisialisasi matriks dengan nilai 0
    int matriks[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matriks[i][j] = 0;
        }
    }
    
    // Input jumlah penyebaran data
    scanf("%d", &num_spreads);
    
    // Input rentang baris dan kolom untuk setiap penyebaran data
    for (int i = 0; i < num_spreads; i++) {
        int start_row, end_row, start_col, end_col;
        scanf("%d %d %d %d", &start_row, &end_row, &start_col, &end_col);
        
        // Validasi rentang agar tidak melebihi ukuran matriks
        if (start_row >= 0 && start_row < row && end_row >= 0 && end_row < row &&
            start_col >= 0 && start_col < col && end_col >= 0 && end_col < col &&
            start_row <= end_row && start_col <= end_col) {
            
            // Update nilai matriks sesuai rentang yang dipilih
            for (int r = start_row; r <= end_row; r++) {
                for (int c = start_col; c <= end_col; c++) {
                    matriks[r][c]++;
                }
            }
        }
    }
    
    // Print matriks dengan visual penyebaran data
    printf("Visual penyebaran data:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }
    
    // Hitung dan print laporan penyebaran data
    printf("Laporan penyebaran data:\n");
    for (int val = 0; val <= 3; val++) {
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matriks[i][j] == val) {
                    count++;
                }
            }
        }
        printf("Total penyebaran data %d sebanyak %d\n", val, count);
    }
    
    return 0;
}
