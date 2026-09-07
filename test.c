#include <stdio.h>

int main()
{
    int nsb = 10;
    int nsa = 200;
    int nsc = 0;
    int *p;

    p = &nsa;
    nsc = nsa + nsb;

    printf("%d\n", nsa);
    printf("%d\n", nsb);
    printf("%d\n", nsc);
    printf("%d\n",*p);
}
