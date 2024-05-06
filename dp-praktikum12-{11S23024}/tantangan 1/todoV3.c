#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TASKS 2
#define MAX_TASK_LENGTH 100

typedef enum {
    TODO,
    PROGRESS,
    DONE
} TaskStatus;

typedef struct {
    char description[MAX_TASK_LENGTH];
    TaskStatus status; 
} Task;

typedef struct {
    Task *tasks;
    int num_tasks;
    int capacity;
} ToDoList;

// Fungsi untuk menampilkan daftar todo
void display_tasks(const ToDoList *todo_list) {
    printf("Daftar Todo [%d/%d]:\n", todo_list->num_tasks, todo_list->capacity);
    if (todo_list->num_tasks == 0) {
        printf("- belum terdapat data yang tersedia!\n");
    } else {
        for (int i = 0; i < todo_list->num_tasks; i++) {
            char *status_str;
            switch (todo_list->tasks[i].status) {
                case TODO:
                    status_str = "Todo";
                    break;
                case PROGRESS:
                    status_str = "Progress";
                    break;
                case DONE:
                    status_str = "Done";
                    break;
                default:
                    status_str = "Unknown";
            }
            printf("%d. %s [%s]\n", i + 1, todo_list->tasks[i].description, status_str);
        }
    }
}

// Fungsi untuk mengalokasikan memori untuk todo
void allocate_todo_list(ToDoList *todo_list, int new_capacity) {
    Task *new_tasks = realloc(todo_list->tasks, new_capacity * sizeof(Task));
    if (new_tasks == NULL) {
        printf("Gagal melakukan tindakan.\n");
        printf("Pengalokasian memori gagal!\n");
        exit(1);
    }
    todo_list->tasks = new_tasks;
    todo_list->capacity = new_capacity;
}

// Fungsi untuk menambah todo ke ToDo list
void add_task(ToDoList *todo_list, const char *description) {

    for (int i = 0; i < todo_list->num_tasks; i++) {
        if (strcmp(todo_list->tasks[i].description, description) == 0) {
            printf("Gagal melakukan tindakan.\n");
            printf("Todo '%s' telah tersedia.\n", description);
            printf("\n");
            return; // Keluar dari fungsi jika todo sudah ada
        }
    }

    if (todo_list->num_tasks >= todo_list->capacity) {
        allocate_todo_list(todo_list, todo_list->capacity * todo_list->capacity); // Perpanjang ukuran menjadi dua kali lipat dari ukuran sebelumnya
    }
    strcpy(todo_list->tasks[todo_list->num_tasks].description, description);
    todo_list->tasks[todo_list->num_tasks].status = TODO;
    todo_list->num_tasks++;
    printf("Berhasil melakukan tindakan.\n");
    printf("Todo baru yang ditambahkan '%s'.\n", description);
    printf("\n");
}

void edit_task(ToDoList *todo_list, int task_number, const char *new_description) {

    for (int i = 0; i < todo_list->num_tasks; i++) {
        if (strcmp(todo_list->tasks[i].description, new_description) == 0) {
            printf("Ubah todo menjadi: ");
            printf("Gagal melakukan tindakan.\n");
            printf("Todo '%s' telah tersedia.\n", new_description);
            printf("\n");
            return; // Keluar dari fungsi jika todo sudah ada
        }
    }

    if (!isdigit(task_number)) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n", todo_list->capacity);
        printf("\n");
        display_tasks(todo_list);
        printf ("\n");
        printf("Menu:\n");
        printf("1. Tambah Data\n");
        printf("2. Ubah Data\n");
        printf("3. Ubah Status\n");
        printf("4. Filter Data\n");
        printf("5. Cari Data\n");
        printf("6. Hapus Data\n");
        printf("0. Keluar\n");
        printf("Pilih:\n");
        printf("Mengubah Todo\n");

    for (int i = 0; i < 10; i++) {


        printf("No todo: Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n", todo_list->capacity);
        printf("\n"); 
        display_tasks(todo_list);
        printf ("\n");
        printf("Menu:\n");
        printf("1. Tambah Data\n");
        printf("2. Ubah Data\n");
        printf("3. Ubah Status\n");
        printf("4. Filter Data\n");
        printf("5. Cari Data\n");
        printf("6. Hapus Data\n");
        printf("0. Keluar\n");
        printf("Pilih:\n");
        printf("Mengubah Todo\n");
       
    }
    printf("No todo: Gagal melakukan tindakan.\n");
    printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n", todo_list->capacity);
    printf("\n"); 

    } else if (task_number >= 1 && task_number <= todo_list->num_tasks) {
        printf("Ubah todo menjadi: ");
        printf("Berhasil melakukan tindakan.\n");
        printf("Todo '%s' ", todo_list->tasks[task_number - 1].description);
        strcpy(todo_list->tasks[task_number - 1].description, new_description);
        printf("telah diubah menjadi '%s'.\n", new_description);
        printf("\n");
    } else if (task_number > todo_list->num_tasks && task_number <= todo_list->capacity) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo ini belum tersedia.\n");
        printf("\n");
    }else if (task_number > todo_list->capacity || task_number < 1) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n", todo_list->capacity);
        printf("\n");
    } 
}
    

void ubah_status(ToDoList *todo_list, int task_number) {
    if (task_number >= 1 && task_number <= todo_list->num_tasks) {
        printf("\nPilih Status:\n");
        printf("1. Todo\n");
        printf("2. Progress\n");
        printf("3. Done\n");
        printf("0. Batal\n");
        printf("Pilih: ");
        int choice;
        scanf("%d", &choice);
        printf("\nTodo dipilih: %s\n", todo_list->tasks[task_number - 1].description); // Menampilkan todo yang dipilih
        switch (choice) {
            case 1:
                todo_list->tasks[task_number - 1].status = TODO;
                printf("Berhasil mengubah status todo menjadi [Todo]\n");
                break;
            case 2:
                todo_list->tasks[task_number - 1].status = PROGRESS;
                printf("Berhasil mengubah status todo menjadi [Progress]\n");
                break;
            case 3:
                todo_list->tasks[task_number - 1].status = DONE;
                printf("Berhasil mengubah status todo menjadi [Done]\n");
                break;
            case 0:
                printf("Batal mengubah status todo.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
        printf("\n");
    } else if (task_number > todo_list->num_tasks && task_number <= todo_list->capacity) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo ini belum tersedia.\n");
        printf("\n");
    } else if (task_number > todo_list->capacity || task_number < 1) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n", todo_list->capacity);
        printf("\n");
    }
}

void filter_data(const ToDoList *todo_list) {
    int todo_count = 0, progress_count = 0, done_count = 0;

    printf("=====[TODO]=====\n");
    for (int i = 0; i < todo_list->num_tasks; i++) {
        if (todo_list->tasks[i].status == TODO) {
            printf("%d. %s\n", i + 1, todo_list->tasks[i].description);
            todo_count++;
        }
    }
    printf("Total Data: %d\n\n", todo_count);

    printf("=====[PROGRESS]=====\n");
    for (int i = 0; i < todo_list->num_tasks; i++) {
        if (todo_list->tasks[i].status == PROGRESS) {
            printf("%d. %s\n", i + 1, todo_list->tasks[i].description);
            progress_count++;
        }
    }
    printf("Total Data: %d\n\n", progress_count);

    printf("=====[DONE]=====\n");
    for (int i = 0; i < todo_list->num_tasks; i++) {
        if (todo_list->tasks[i].status == DONE) {
            printf("%d. %s\n", i + 1, todo_list->tasks[i].description);
            done_count++;
        }
    }
    printf("Total Data: %d\n\n", done_count);
}


void Cari_Todo(const ToDoList *todo_list, const char *search_query) {
    int found = 0;
    printf("Mencari Data:\n");
    printf("Cari todo: %s\n", search_query);
    printf("Hasil pencarian untuk '%s':\n", search_query);
    for (int i = 0; i < todo_list->num_tasks; i++) {
        if (strstr(todo_list->tasks[i].description, search_query) != NULL) {
            found++;
            printf("%d. %s [%s]\n", found, todo_list->tasks[i].description,
                   todo_list->tasks[i].status == TODO ? "TODO" : 
                   todo_list->tasks[i].status == PROGRESS ? "PROGRESS" : "DONE");
        }
    }
    printf("Total Data: %d\n", found);
    printf("\n");
    if (!found) {
        printf("Tidak ada hasil yang ditemukan.\n");
    }
}

// Fungsi untuk menghapus data dari ToDo list
void delete_task(ToDoList *todo_list, int task_number) {
    if (task_number >= 1 && task_number <= todo_list->num_tasks) {
        for (int i = task_number - 1; i < todo_list->num_tasks - 1; i++) {
            strcpy(todo_list->tasks[i].description, todo_list->tasks[i + 1].description);
            todo_list->tasks[i].status = todo_list->tasks[i + 1].status;
        }
        todo_list->num_tasks--;
        printf("Berhasil menghapus todo nomor %d.\n", task_number);
        printf("\n");
    } else if (task_number > todo_list->num_tasks && task_number <= todo_list->capacity) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo ini belum tersedia.\n");
        printf("\n");
    } else if (task_number > todo_list->capacity || task_number < 1) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n", todo_list->capacity);
        printf("\n");
    }
}

int main() {
    ToDoList todo_list;
    todo_list.num_tasks = 0;
    todo_list.capacity = MAX_TASKS;
    todo_list.tasks = (Task *)malloc(todo_list.capacity * sizeof(Task));
    if (todo_list.tasks == NULL) {
        printf("Gagal melakukan tindakan.\n");
        printf("Pengalokasian memori gagal!\n");
        return 1;
    }

    int choice;
     int task_number;
    char description[MAX_TASK_LENGTH]; // Variable untuk menyimpan deskripsi pencarian
    do {
        
        display_tasks(&todo_list);
        printf ("\n");
        printf("Menu:\n");
        printf("1. Tambah Data\n");
        printf("2. Ubah Data\n");
        printf("3. Ubah Status\n");
        printf("4. Filter Data\n");
        printf("5. Cari Data\n");
        printf("6. Hapus Data\n");
        printf("0. Keluar\n");
        printf("Pilih:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char new_task[MAX_TASK_LENGTH];
                printf("Menambah Todo: ");
                scanf(" %[^\n]s", new_task);
                add_task(&todo_list, new_task);
                break;
            }
          case 2: {
               printf("Mengubah Todo\n");
    printf("No todo: ");
    scanf("%d", &task_number);
    if (task_number >= 1 && task_number <= todo_list.num_tasks) {
        scanf(" %[^\n]", description);
        edit_task(&todo_list, task_number, description);
    } else {
                    printf("Gagal melakukan tindakan.\n");
                    if (task_number > todo_list.num_tasks && task_number <= todo_list.capacity) {
                        printf("No todo ini belum tersedia.\n");
                        printf("\n");
                    } else {
                        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n", todo_list.capacity);
                        printf("\n");
                    }
                }
                break;}
            case 3: {
                printf("Mengubah Status Todo\n");
                printf("No todo: ");
                int task_number;
                scanf("%d", &task_number);
                ubah_status(&todo_list, task_number);
                break;
            }
            case 4: {
                printf("Filter Data:\n");
                filter_data(&todo_list);
                break;
            }
            case 5:
                printf("\nMencari Data:\n");
                printf("Cari Todo: ");
                scanf(" %[^\n]", description);
                Cari_Todo(&todo_list, description);
                break;
            case 6: {
                printf("Hapus Data:\n");
                printf("No todo: ");
                int task_number;
                scanf("%d", &task_number);
                delete_task(&todo_list, task_number);
                break;
            }
            case 0:
                printf("Menutup aplikasi!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n\n");
        }
    } while (choice != 0);

    free(todo_list.tasks);

    return 0;
}