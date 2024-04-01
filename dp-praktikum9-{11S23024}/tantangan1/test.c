#include <stdio.h>

int main() {
    int nilaia, nilaib, nilai;
    scanf("%d %d", &nilaia, &nilaib);
    nilai = nilaia;

    do {
        if (nilai % 3 == 0 && nilai % 5 == 0 && nilai % 7 == 0 && nilai % 2 == 0 && nilai != 105) {
            printf("ABC\n");
        } else if (nilai % 3 == 0) {
            if (nilai % 5 == 0) {
                printf("IU\n");
            } else if (nilai % 7 == 0) {
                printf("IE\n");
            } else {
                printf("I\n");
            }
        } else if (nilai % 5 == 0) {
            printf("U\n");
        } else if (nilai % 7 == 0) {
            printf("E\n");
        } else if (nilai % 3 != 0 && nilai % 5 != 0 && nilai % 7 == 0 && nilai % 2 != 0 && nilai != 105) {
            printf("CBA\n"); // Output "CBA" when none of the conditions are met
        } else {
            printf("%d\n", nilai); // Output the number itself
        }
        nilai++;
    } while (nilai <= nilaib);

    return 0;
}
