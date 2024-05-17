#include <stdio.h>
#include <string.h>

int main()
{
    char s[100000];
    scanf("%s", &s);
    char *s1 = "dream";
    char *s2 = "dreamer";
    char *s3 = "erase";
    char *s4 = "eraser";

    int length = strlen(s);

    int count = 0;
    int success = 0;
    while (1)
    {
        if (count == length)
        {
            success = 1;
            break;
        }
        else if (strncmp(s, s1, 5) == 0)
        {
            *s += 5;
        }
        else if (strncmp(s, s2, 6) == 0)
        {
            *s += 6;
        }
        else if (strncmp(s, s3, 5) == 0)
        {
            *s += 5;
        }
        else if (strncmp(s, s4, 6) == 0)
        {
            *s += 6;
        }
        else
        {
            break;
        }
    }

    if (success == 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}