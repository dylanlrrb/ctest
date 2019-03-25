#include <stdio.h>
#include "../deps/arith.h"   // Include our custom header file

int main()
{
    printf("sum(10, 20)  = %.2f\n", sum(10, 20));
    printf("sub(10, 20)  = %.2f\n", sub(10, 20));
    printf("mult(10, 20) = %.2f\n", mult(10, 20));
    printf("div(10, 20)  = %.2f\n", div(10, 20));
    printf("mod(10, 20)  = %d\n",   mod(10, 20));

    return 0;
}