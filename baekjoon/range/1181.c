#include <stdio.h>
#include <stdlib.h>

typedef struct s_word
{
    int len;
    char word[51];
}            t_word;

int wordcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != 0 && s2[i] != 0 && s1[i] - s2[i] == 0)
        i++;
    if (s1[i] == 0 && s2[i] == 0)
        return (-1);
    return (i);
}

int compare(const void *a, const void *b)
{
    int i;

    if (((t_word *)a)->len == ((t_word *)b)->len)
    {
        i = wordcmp(((t_word *)a)->word, ((t_word *)b)->word);
        return (((t_word *)a)->word[i] - ((t_word *)b)->word[i]);
    }
    return (((t_word *)a)->len - ((t_word *)b)->len);
}

int main()
{
    t_word word[20001];
    int n;
    int i;
    int j;
    int k;
    int check;

    scanf("%d", &n);
    i = -1;
    check = 0;
    while (++i < n)
    {
        scanf("%s", word[i].word);
        j = -1;
        while (++j < i)
        {
            check = 0;
            k = wordcmp(word[i].word, word[j].word);
            if (k == -1)
            {
                i--;
                n--;
                check = 1;
                break ;
            }
        }
        if (check == 1)
            continue ;
        j = -1;
        while (word[i].word[++j])
            ;
        word[i].len = j;
    }
    qsort(word, n, sizeof(t_word), compare);
    i = -1;
    while (++i < n)
        printf("%s\n", word[i].word);
    return (0);
}
