#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTodoList(char **todosList, int listCount, int *notification) {
    if (listCount > *notification) {
        *notification *= *notification; // Memperbarui nilai notifikasi secara eksponensial
    }
    printf("Daftar Todo [%d/%d]:\n", listCount, *notification);
    if (listCount == 0) {
        printf("- belum terdapat data yang tersedia!\n");
    } else {
        for (int i = 0; i < listCount; ++i) {
            printf("%d. %s\n", i + 1, todosList[i]);
        }
    }
}

void addTodo(char ***todoList, int *listCount, int *maxLimit) {
    char input[100];
    printf("\nMenambah Todo: ");
    fgets(input, sizeof(input), stdin);

    // Membersihkan karakter newline ('\n') dari string jika ada
    size_t length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    if (strlen(input) < 6) {
        printf("Gagal melakukan tindakan.\n");
        printf("Todo harus terdiri dari minimal 6 karakter.\n\n");
        return;
    }

    if (*listCount >= *maxLimit) {
        // Mengalokasikan memori baru dengan batas dua kali lipat
        *maxLimit *= 2;
        *todoList = realloc(*todoList, *maxLimit * sizeof(char *));
        if (*todoList == NULL) {
            printf("Gagal melakukan realokasi memori!\n");
            exit(1);
        }
    }

    (*todoList)[*listCount] = malloc(100 * sizeof(char));
    if ((*todoList)[*listCount] == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }

    strcpy((*todoList)[*listCount], input);
    (*listCount)++;
    printf("Berhasil melakukan tindakan.\n");
    printf("Todo baru yang ditambahkan '%s'.\n\n", input);
}

void deleteTodo(char ***todoList, int *listCount, int *maxLimit) {
    int choice;
    printf("\nMenghapus Todo\n");
    printf("No todo: ");
    scanf("%d", &choice);
    while(getchar() != '\n');

    if (choice < 1 || choice > *maxLimit) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n\n", *maxLimit);
    } else if (choice > *listCount) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo ini belum tersedia.\n\n");
    } else {
        char todo_before[100];
        strcpy(todo_before, (*todoList)[choice - 1]);

        free((*todoList)[choice - 1]);

        for (int i = choice - 1; i < *listCount - 1; ++i) {
            (*todoList)[i] = (*todoList)[i + 1];
        }

        (*listCount)--;
        printf("Berhasil melakukan tindakan.\n");
        printf("Todo '%s' telah dihapus.\n\n", todo_before);
    }
}

void modifyTodo(char **todoList, int listCount) {
    int choice;

    printf("\nMengubah Todo\n");
    printf("No todo: ");
    scanf("%d", &choice);
    while(getchar() != '\n');

    if (choice < 1 || choice > listCount) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n\n", listCount);
    } else {
        char todo_before[100];
        strcpy(todo_before, todoList[choice - 1]);

        char input[100];
        printf("Ubah todo menjadi: ");
        fgets(input, sizeof(input), stdin);

        size_t length = strlen(input);
        if (input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        if (strlen(input) < 6) {
            printf("Gagal melakukan tindakan.\n");
            printf("Todo harus terdiri dari minimal 6 karakter.\n\n");
            return;
        }

        strcpy(todoList[choice - 1], input);
        printf("Berhasil melakukan tindakan.\n");
        printf("Todo '%s' telah diubah menjadi '%s'.\n\n", todo_before, todoList[choice - 1]);
    }
}

int main() {
    char **todoList = NULL;
    int listCount = 0;
    int choice;
    int maxLimit = 2;
    int notification = 2;

    todoList = (char **)malloc(maxLimit * sizeof(char *));
    if (todoList == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }

    do {
        printTodoList(todoList, listCount, &notification);
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Ubah Data\n");
        printf("3. Hapus Data\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addTodo(&todoList, &listCount, &maxLimit);
                break;
            case 2:
                modifyTodo(todoList, listCount);
                break;
            case 3:
                deleteTodo(&todoList, &listCount, &maxLimit);
                break;
            case 0:
                break;
            default:
                printf("Pilihan tidak valid.\n\n");
                break;
        }
    } while (choice != 0);

    for (int i = 0; i < listCount; i++) {
        free(todoList[i]);
    }
    
    free(todoList);

    printf("\nMenutup aplikasi!\n");
    return 0;
}