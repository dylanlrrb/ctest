/**
 * arith.h header file function definitions.
 * Define all functions here, that are declared in arith.h!
 */

float sum (float x, float y)
{
    return (x + y);
}

float sub (float x, float y)
{
    return (x - y);
}

float div (float x, float y)
{
    return (x == 0 || y == 0) 
            ? 0
            : (x / y);
}

float mult (float x, float y)
{
    return (x * y);
}

int mod (int x, int y)
{
    return (x % y);
}
