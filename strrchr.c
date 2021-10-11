#include <unistd.h>
char *ft_strrchr(char *s, int c)
{
    int i;
    int p;

    p = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            p = i;
        i++;
        if (s[i] == '\0' && c == 0)
            p = i;
        printf("p = %d\n", p);
    }
    if (p == 0 && s[p] != c)
        return(NULL);
    return(s + p);
}