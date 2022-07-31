#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Algoritmo que imprime a sequência Fibonacci usando Programação Dinâmica

long long int fibPD(n)
{
    int f[n];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i < n; i++)
    {
        f[i] = f[i-1] + f[i-2];
        printf("%lld\n", f[i]);
    }

    return f[n];
}

int fib(n)
{
    if(n <= 1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main(void)
{
    for(int i = 0; i < 20; i++)
    {
        printf("%lld\n", fib(i));
    }
    
    return 0;
}