#include <stdio.h>
#include <stdlib.h>

void open_file(FILE *file, const char *filename) {
    *file = fopen(filename, "r+");
    if (*file == NULL) {
        *file = fopen(filename, "w+");
        if (*file == NULL) {
            perror("Ошибка при открытии файла");
            exit(EXIT_FAILURE);
        }
    }
}

void write_to_file(FILE *file) {
    char buffer[256];
    printf("Введите текст (введите 'exit' для выхода):\n");
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
        fputs(buffer, file);
    }
}

void save_file(FILE *file) {
    fflush(file); // Сохранить изменения в файле
}

void close_file(FILE *file) {
    fclose(file);
}

int main(int argc, char *argv[]) {
    FILE *file;
    const char *filename = "rouge.org";

    open_file(&file, filename);
    write_to_file(file);
    save_file(file);
    close_file(file);

    printf("Файл сохранен и закрыт. Выход.\n");
    return 0;
} 



