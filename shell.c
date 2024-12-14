// Followed Stephen Brennan's tutorial online to learn
// Additions and modifications made by Bilal Suleman

#include "shell.h"

// Forward declarations for built in commands

int builtin_cd(char **args);
int builtin_help(char **args);
int builtin_exit(char **args);

// List of all built in commands supported

char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &builtin_cd,
    &builtin_help,
    &builtin_exit
};

// The entry point and command loop for the project will be defined here.

// We can start with the main function

// It is probably a good idea to start splitting functionality into the neccesary functions with the command loop for the shell remaining in the main function

// The following are functions that should be implemented for basic functionality:

// get_command(): Retrieve line input in a memory safe manor.

#define INPUT_BUFFER 1024;

char* get_command() {
    int buffSize = INPUT_BUFFER;
    int position = 0;
    char *buffer = malloc(sizeof(char) * buffSize);
    int c;

    // Attempted to allocate a buffer, if failed then exit with allocation failure.
    if (!(buffer))
    {
        fprintf(stderr, "simpleShell: allocation error");
        exit(EXIT_FAILURE);
    }

    // read until all input is read, or a newline (enter key) is pressed.
    while (1)
    {
        c = getchar();

        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // Reallocate buffer as neccessary.
        if (position >= buffSize)
        {
            buffSize += INPUT_BUFFER;
            buffer = realloc(buffer, buffSize);

            if (!buffer)
            {
                fprintf(stderr, "simpleShell: allocation error.");
                exit(EXIT_FAILURE);
            }
        }
    }
};

// parse_command(): Parse and tokenize input to separate command and args
#define TOK_BUFSIZE 64
#define TOK_DELIM "\t\r\n\a"
char** parse_command(char* line) {
    // Need to tokenize the input.
    int bufsize = TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "simpleShell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens)
            {
                fprintf(stderr, "simpleShell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        
        token = strtok(NULL, TOK_DELIM);
    }

    tokens[position] = NULL;
    return tokens;
};

// exec_command(): Fork and execute command

int exec_command(char ** args);

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