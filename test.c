#include <stdio.h>

int main()
{
    int nsb = 10;
    int nsa = 200;
    int nsc = 0;
    int *p;

    p = &nsa;
    nsc = nsa + nsb;

    printf("%d", nsa);
    printf("%d", nsb);
    printf("%d", nsc);
    printf("%d",*p);
}
