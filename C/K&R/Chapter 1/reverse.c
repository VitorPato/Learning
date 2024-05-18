#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_string(char const string[])
{
    size_t const size = strlen(string);
    char *reversed_string = malloc(sizeof(*reversed_string) * (size+1));
    if (reversed_string == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++)
    {
        reversed_string[i] = string[(size-1) - i];
    }

    reversed_string[size] = '\0';
    return reversed_string;

}

int main(void)
{
    char teste[] = "ABCDEFGH";
    char *string_reversed = reverse_string(teste);
    printf("%s\n", string_reversed);
    free(string_reversed);
}