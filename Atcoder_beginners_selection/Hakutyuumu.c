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
    char *p = s;

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
        else if (strncmp(p, s2, 7) == 0)
        {
            p += 7;
            count += 7;
        }
        else if (strncmp(p, s4, 6) == 0)
        {
            p += 6;
            count += 6;
        }
        else if (strncmp(p, s1, 5) == 0)
        {
            p += 5;
            count += 5;
        }
        else if (strncmp(p, s3, 5) == 0)
        {
            p += 5;
            count += 5;
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