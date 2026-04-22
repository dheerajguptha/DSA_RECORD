
/*
===========================================================
                        AIM
===========================================================
To write a C program to implement stack operations such as 
PUSH, POP, PEEK, and checking if the stack is empty using arrays.

===========================================================
                      ALGORITHM
===========================================================
1. Start the program.
2. Initialize an array 'stack[MAX]' and a variable 'top = -1'.
3. Define the following functions:
    a) push(x):
        - If top >= MAX - 1, display "Stack Overflow".
        - Else, increment top and insert element.
    b) pop():
        - If top < 0, display "Stack Underflow".
        - Else, return and remove the top element.
    c) peek():
        - If stack is empty, print message.
        - Else, return the top element.
    d) isEmpty():
        - Return 1 if top == -1, else 0.
4. In main(), perform operations based on user choice.
5. Stop the program.

===========================================================
                        PROGRAM
===========================================================
*/
#include<stdio.h>
#include<string.h>

int main()
{
    int n, max, choice, items;

    // Ask user for size of the stack
    printf("enter the size of stack:\n");
    scanf("%d", &n);

    int stack[n];      // stack of size n
    max = n - 1;       // maximum allowed index
    int top = -1;      // stack initially empty

    char op[5];        // to store yes/no option for repeating

    do
    {
        // Show menu to user
        printf("\n 1. push\n 2. pop\n 3. exit\n");
        printf("\n choose the operation to be done:\n");
        scanf("%d", &choice);

        // Perform selected operation
        switch(choice)
        {
            case 1: // PUSH operation
            {
                // Check overflow (stack full)
                if(top == max - 1)
                {
                    printf("\n stack is overflow");
                }
                else
                {
                    top++;   // move top to next position
                    printf("\n enter the element to be push:\n");
                    scanf("%d", &stack[top]);   // insert element
                    printf("\n entered element: %d\n top value: %d\n", stack[top], top);
                }
                break;
            }

            case 2: // POP operation
            {
                // Check underflow (stack empty)
                if(top == -1)
                {
                    printf("\n stack is underflow\n");
                }
                else
                {
                    items = stack[top];  // get the top element
                    top--;               // decrease top
                    printf("\n items %d has been poped out of stack\n top value is %d ", items, top);
                }
                break;
            }

            case 3: // EXIT program
            {
                printf("\n exiting of stack");
                return 0;
            }

            default: // invalid menu option
            {
                printf("invalid operation");
            }   
        }

        // Ask if the user wants to continue
        printf("\n enter your choice to repeat yes or no:\n");
        scanf("%s", op);

    }
    while(strcmp(op, "no"));   // repeat until user enters 'no'
}
