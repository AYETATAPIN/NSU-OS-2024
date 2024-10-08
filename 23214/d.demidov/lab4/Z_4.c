#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int arr_index = 0, arr_size = 2;
    char **arr = malloc(sizeof(char *) * arr_size);
    char *temp_string = malloc(sizeof(char) * 8192);
    int temp_string_length;
    while (fgets(temp_string, 8192, stdin)) {
        temp_string_length = strlen(temp_string);
        if (arr_index == arr_size - 1) {
            arr_size *= 2;

            arr = realloc(arr, sizeof(char *) * arr_size);
        }
        arr[arr_index] = malloc(sizeof(char) * (temp_string_length + 1));
        memcpy(arr[arr_index], temp_string, temp_string_length + 1);
        arr_index++;
        if (temp_string[0] == '.') {
            free(temp_string);
            break;
        }
    }

    printf("\n");

    for (int i = 0; i < arr_index; ++i) {
        if (i == arr_index - 1) {
            printf("%s", arr[i] + 1);
        }
        else {
            printf("%s", arr[i]);   
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}