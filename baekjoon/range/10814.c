#include <stdio.h>
#include <stdlib.h>

typedef struct s_in
{
    int age;
    char name[101];
    int ord;
}                t_in;

int cmp(const void *a, const void *b)
{
    if (((t_in *)a)->age == ((t_in *)b)->age)
        return (((t_in *)a)->ord == ((t_in *)b)->ord);
    return (((t_in *)a)->age - ((t_in *)b)->age);
}

int main()
{
    t_in *in;
    int n;
    int i;
    
    scanf("%d", &n);
    in = (t_in *)malloc(sizeof(t_in) * n + 1);
    i = -1;
    while (++i < n)
    {
        scanf("%d %s", &(in[i].age), in[i].name);
        in[i].ord = i;
    }
    qsort(in, n, sizeof(t_in), cmp);
    i = -1;
    while (++i < n)
        printf("%d %s\n", in[i].age, in[i].name);
    return (0);
}
