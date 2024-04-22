#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 3
#define MAX_TASK_LENGTH 50

// Struktur untuk menyimpan task
typedef struct {
    char description[MAX_TASK_LENGTH];
    int status; // 0: belum selesai, 1: selesai
} Task;

// Struktur untuk menyimpan ToDo list
typedef struct {
    Task tasks[MAX_TASKS];
    int num_tasks;
} ToDoList;

// Fungsi untuk menampilkan daftar todo
void display_tasks(const ToDoList *todo_list) {
    printf("Daftar Todo [%d/3]:\n", todo_list->num_tasks);
    if (todo_list->num_tasks == 0) {
        printf("- belum terdapat data yang tersedia!\n");
    } else {
        for (int i = 0; i < todo_list->num_tasks; i++) {
            printf("%d. %s\n", i + 1, todo_list->tasks[i].description);
        }
    }
}

// Fungsi untuk menambah todo ke ToDo list
void add_task(ToDoList *todo_list, const char *description) {
    if (todo_list->num_tasks < MAX_TASKS) {
        strcpy(todo_list->tasks[todo_list->num_tasks].description, description);
        todo_list->tasks[todo_list->num_tasks].status = 0; // Default: belum selesai
        todo_list->num_tasks++;
        printf("Berhasil melakukan tindakan.\n");
        printf("Todo baru yang ditambahkan '%s'.\n", description);
        printf("\n");
    } else {
        printf("ToDo list sudah penuh. Tidak dapat menambahkan lagi.\n");
    }
}

// Fungsi untuk menghapus todo dari ToDo list
void remove_task(ToDoList *todo_list, int task_number) {
    if (task_number >= 1 && task_number <= todo_list->num_tasks) {
        printf("Berhasil melakukan tindakan.\n");
        printf("Todo '%s' telah dihapus.\n", todo_list->tasks[task_number - 1].description); 
        printf("\n");// Menampilkan deskripsi sebelum dihapus
        for (int i = task_number - 1; i < todo_list->num_tasks - 1; i++) {
            strcpy(todo_list->tasks[i].description, todo_list->tasks[i + 1].description);
            todo_list->tasks[i].status = todo_list->tasks[i + 1].status;
        }
        todo_list->num_tasks--;
    } else if (task_number > todo_list->num_tasks && task_number <= MAX_TASKS) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo ini belum tersedia.\n");
        printf("\n");
    } else if (task_number > MAX_TASKS || task_number < 1) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai 3.\n");
        printf("\n");
    } 
}


// Fungsi untuk mengubah todo dari Todo List
void edit_task(ToDoList *todo_list, int task_number, const char *new_description) {
    if (task_number >= 1 && task_number <= todo_list->num_tasks) {
        printf("Berhasil melakukan tindakan.\n");
        printf("Todo '%s' ", todo_list->tasks[task_number - 1].description); // Menampilkan deskripsi sebelum perubahan
        strcpy(todo_list->tasks[task_number - 1].description, new_description);
        printf("telah diubah menjadi '%s'.\n", new_description); // Menampilkan deskripsi setelah perubahan
        printf("\n"); 
    } else if (task_number > todo_list->num_tasks && task_number <= MAX_TASKS) {
        printf("No todo: Gagal melakukan tindakan.\n");
        printf("No todo ini belum tersedia.\n");
        printf("\n");
    } else if (task_number > MAX_TASKS ) {
        printf("No todo: Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai 3.\n");
        printf("\n");
    } 
}





int main() {
    ToDoList todo_list = { .num_tasks = 0 };

    int choice;
    char description[MAX_TASK_LENGTH];
    int task_number;

    while (1) {
        display_tasks(&todo_list);
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Ubah Data\n");
        printf("3. Hapus Data\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        if (choice == 25) {
            printf("\nDaftar Todo [0/3]:\n");
            printf("- belum terdapat data yang tersedia!\n");
            printf("\nMenu:\n");
            printf("1. Tambah Data\n");
            printf("2. Ubah Data\n");
            printf("3. Hapus Data\n");
            printf("0. Keluar\n");
            printf("Pilih: ");
            continue;
        }

        switch (choice) {
            case 1:
            if (todo_list.num_tasks >= MAX_TASKS) {
            printf("\nMenambah Todo: Gagal melakukan tindakan.\n");
            printf("Kapasitas penyimpanan telah penuh.\n");
            printf("Silahkan menghapus todo lama terlebih dahulu!\n");
            printf("\n");
            continue;}
            else{
                printf("\nMenambah Todo: ");
                scanf(" %[^\n]", description);
                add_task(&todo_list, description);
                break;} 
            case 2:  
                 printf("\nMengubah Todo\n");
    printf("No todo: ");
    scanf("%d", &task_number);
    if (task_number >= 1 && task_number <= todo_list.num_tasks) {
        printf("Ubah todo menjadi: ");
        scanf(" %[^\n]", description);
        edit_task(&todo_list, task_number, description);
    } else {
        printf("Gagal melakukan tindakan.\n");
        if (task_number > todo_list.num_tasks && task_number <= MAX_TASKS) {
            printf("No todo ini belum tersedia.\n");
            printf("\n");}
        else {
            printf("No todo yang tersedia berada pada rentang 1 sampai 3.\n");
            printf("\n");}
            
    }
    break;
            case 3:
                printf("\nMenghapus Todo\n");
                printf("No todo: ");
                scanf("%d", &task_number);
                remove_task(&todo_list, task_number);
                break;
            case 0:
                printf("\nMenutup aplikasi!\n");
                exit(0);
            default:
                printf("Pilihan tidak valid. Mohon masukkan pilihan yang benar.\n");
        }
    }

    return 0;
}