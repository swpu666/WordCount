
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char *filename;
    char *option;
    char buffer[1000];
    int word_count = 0, char_count = 0, line_count = 0, in_word = 0;

    if (argc != 3) {
        printf("Usage: wordcount.exe -w/-c/-l filename\n");
        return 1;
    }

    option = argv[1];
    filename = argv[2];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    while (fgets(buffer, 1000, fp)) {
        char_count += strlen(buffer);
		int i = 0;
        for (i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '\n') {
                line_count++;
            }

            if (isspace(buffer[i])) {
                in_word = 0;
            } else if (!in_word) {
                word_count++;
                in_word = 1;
            }
        }
    }

    fclose(fp);

    if (strcmp(option, "-w") == 0) {
        printf("Word count: %d\n", word_count);
    } else if (strcmp(option, "-c") == 0) {
        printf("Character count: %d\n", char_count);
    } else if (strcmp(option, "-l") == 0) {
        printf("Line count: %d\n", line_count);
    } else {
        printf("Invalid option\n");
        return 1;
    }

    return 0;
}
