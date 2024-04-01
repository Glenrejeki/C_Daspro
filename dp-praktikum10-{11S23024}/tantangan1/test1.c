#include <stdio.h>

int main() {
    int row, col, i, j, k, n;
    int matrix[100][100] = {0}; // Maksimum ukuran matrix 100x100
    
    
    // Input ukuran matrix
    scanf("%d %d", &row, &col);
    
    // Inisialisasi matrix dengan nilai 0
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            matrix[i][j] = 0;
        }
    }
    
    // Input jumlah penyebaran data
    scanf("%d", &n);
    
    // Penyebaran data
    for(k = 0; k < n; k++) {
        int startRow, endRow, startCol, endCol;
        scanf("%d %d %d %d", &startRow, &endRow, &startCol, &endCol);
        
        for(i = startRow - 1; i <= endRow - 1; i++) {
            for(j = startCol - 1; j <= endCol - 1; j++) {
                matrix[i][j]++;
            }
        }
    }
    
    // Mencetak matrix
    printf("Visual penyebaran data:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Laporan penyebaran data
    printf("\nLaporan penyebaran data:\n");
    for(int num = 0; num <= n; num++) {
        int count = 0;
        for(i = 0; i < row; i++) {
            for(j = 0; j < col; j++) {
                if(matrix[i][j] == num) {
                    count++;
                }
            }
        }
        printf("Total penyebaran data %d sebanyak %d\n", num, count);
    }

    return 0;

}


// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf
// adfadsfadfadsfadfadsfadsf