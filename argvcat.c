#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
    char* str = (char*) malloc((strlen(s1) + strlen(s2)) * sizeof(char) + 1);
    
    if (str == NULL) {
        my_error("Failed to allocated memory.");
    }

    strcpy(str, s1);
    strcat(str, s2);

    return str;
}

int main(int argc, char *argv[])
{
    char    *s;

    s = my_strcat("", argv[0]);

    for (int i = 1; i < argc; i ++) {
        char *old_s = s;
        s = my_strcat(old_s, argv[i]);
        free(old_s);
    }
    
    printf("%s\n", s);

    free(s);

    return 0;
}