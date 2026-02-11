#include <stdio.h>
#include <string.h>

// Recursive function to print string in reverse
void mirror(char str[], int index)
{
    if (index < 0)
        return;

    printf("%c", str[index]);
    mirror(str, index - 1);
}

int main()
{
    char str[100];

    scanf("%s", str);   // input string (no spaces)

    int len = strlen(str);
    mirror(str, len - 1);

    return 0;
}
