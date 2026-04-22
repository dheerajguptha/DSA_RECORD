

/* 
=====================================================================
                            AIM
=====================================================================
To write a C program that performs a Linear Search on a list of 
user-entered elements to find a specified target number.

=====================================================================
                           ALGORITHM
=====================================================================
1. Start the program.
2. Read the number of elements 'n' from the user.
3. Read 'n' elements and store them in an array 'arr[]'.
4. Read the element to be searched, called 'target'.
5. Initialize a loop variable 'i = 0'.
6. Repeat steps 7–8 while 'i < n':
     - If arr[i] == target, then
         • Print that the element is found at position (i + 1).
         • Stop the search.
     - Else, increment i by 1.
7. If the loop completes and no match is found,
   print that the element is not found.
8. End the program.

=====================================================================
                            PROGRAM
=====================================================================
*/

#include<stdio.h>

int main()
{
    int n, key, i, found = 0;

    // Ask user how many elements they want to store
    printf("enter how many elements do you want to store:\n");
    scanf("%d", &n);

    // Declare an array of size n
    int a[n];

    // Input n elements from the user
    printf("\n enter the %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);   // storing each value in array
    }

    // Ask user for the key value to search
    printf("\n enter the key value to search:\n");
    scanf("%d", &key);

    // Linear search: check each element one by one
    for(i = 0; i < n; i++)
    {
        if(key == a[i])       // if element matches key
        {
            printf("\nkey found at index %d\n", i);
            found = 1;        // set flag to show key is found
        }
    }

    // If key not found in entire array
    if(found == 0)
    {
        printf("\nkey not found");
    }
}
