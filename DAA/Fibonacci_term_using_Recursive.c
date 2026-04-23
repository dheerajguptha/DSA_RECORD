// Fibonacci term using Recursion

/*
AIM : To write a program to find the nth Fibonacci term using recursion
*/

//Program

#include <stdio.h>

/*
 * Function: fib
 * Description: Computes the nth Fibonacci term using recursion.
 * Complexity: O(2^n) - due to overlapping subproblems.
 * @param n: index of the Fibonacci term
 * @return: Fibonacci value at index n
 */
int fib(int n)
{
    // Base condition
    if (n <= 1)
    {
        return n;
    }

    // Recursive step
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    
    // Validate input
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Nth Fibonacci term = %d\n", fib(n));

    return 0;
}
