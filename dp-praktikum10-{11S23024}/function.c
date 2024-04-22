#include <stdio.h>

void sayHello() {
    printf("Hallo, selamat datang!\n");
}

void sayHelloWithName(char name[]) {
    printf("Hello %s!\n", name);
}

int add(int a, int b) {
    return a + b;
}

int *makeArray() {
    static int arr[5] = {2, 4, 6, 8, 10};
    return arr;
}

void showArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Index ke-%d = %d\n", i, arr[i]);
    }
}

int main() {
    sayHello();

    char nama[] = "Glen Rejeki";
    sayHelloWithName(nama);

    int result = add(5, 3);
    printf("Hasil Penjumlahan 5 + 3 = %d\n", result);

    int *arr = makeArray();
    showArray(arr, 5);

    return 0;
}
