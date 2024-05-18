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
    p += length;

    int count = 0;
    int success = 0;
    while (1)
    {
        if (count == length)
        {
            success = 1;
            break;
        }
        else if ((length - count) >= 7 && strncmp(p-7, s2, 7) == 0)
        {
            count += 7;
            p -= 7;
            continue;
        }
        else if ((length - count) >= 6 && strncmp(p-6, s4, 6) == 0)
        {
            count += 6;
            p -=6;
            continue;
        }
        else if ((length - count) >= 5)
        {
            if (strncmp(p-5, s1, 5) == 0 || strncmp (p-5, s3, 5) == 0)
            {
                count += 5;
                p -= 5;
                continue;
            }
        }
        break;
    }

    if (success == 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}