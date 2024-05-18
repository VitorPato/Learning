#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_STOPS   8
#define MAX_SIZE    1000

int calculate_number_spaces(int const index)
{
    return TAB_STOPS - (index % TAB_STOPS);
}

void insert_blanks_string(int number_of_blanks, char string[], int const index)
{
    for (int i = 0; i < number_of_blanks; i++)
    {
        string[index + i] = ' ';
    }

}

char* string_replace_tabs_with_spaces(char const string[])
{   
    size_t str_size = strlen(string);
    char *new_string = malloc(sizeof(*new_string) * (str_size * TAB_STOPS + 1));
    if (new_string == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    size_t new_string_index = 0;
    for (size_t i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '\t')
        {
            int number_of_blanks = calculate_number_spaces(new_string_index);
            insert_blanks_string(number_of_blanks,new_string, new_string_index);
            new_string_index += number_of_blanks;
        }
        else
        {
            new_string[new_string_index++] = string[i];
        }
    }

    new_string[new_string_index] = '\0';
    return new_string;
}

int get_line(char array[], int const max_size)
{
    int c;
    size_t i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < max_size-1)
    {
        array[i] = c;
        i++;
    }

    if (c == '\n')
    {
        array[i++] = '\n';
    }

    array[i] = '\0';
    return i;
}

int main(void)
{   
    char array[MAX_SIZE];
    get_line(array, MAX_SIZE);
    char *new_str = string_replace_tabs_with_spaces(array);
    printf("%s", new_str);
    free(new_str);
}                               