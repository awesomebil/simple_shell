#include "shell.h"

// The entry point and command loop for the project will be defined here.

// We can start with the main function

int main() {

    int status = -1;
    size_t line_buf = 0;
    char *line = NULL;
    char **args;

    do {
        printf("simpleShell$ ");
        getline(&line, &line_buf, stdin);
        printf(line);
        if (strcmp("exit\n", line) == 0)
        {
            free(line);
            return 0;
        }
        
    } while(status == -1);

    free(line);
    return 0;
}