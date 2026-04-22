/*
===========================================================
                        AIM
===========================================================
To write a C program to search an element in a sorted array 
using Binary Search technique.

===========================================================
                      ALGORITHM
===========================================================
1. Start the program.
2. Read how many elements (n) the user wants to enter.
3. Read 'n' sorted numbers into an array.
4. Ask the user for the number to search (target).
5. Set two variables: left = 0 and right = n - 1.
6. Repeat while left <= right:
      a) Find mid = left + (right - left) / 2
      b) If arr[mid] == target → element found, return mid.
      c) If arr[mid] < target → move left to mid + 1.
      d) Else → move right to mid - 1.
7. If not found, return -1.
8. Display result on the screen.
9. Stop the program.

===========================================================
                        PROGRAM
===========================================================
*/

#include<stdio.h>
int main()
{
    int i, j, low = 0, high, mid, n, key, sort, found = 0;

    // Ask user how many elements to store
    printf("\n enter how many elements do you want to store:\n");
    scanf("%d", &n);

    // Declare array of size n
    int a[n];

    // Input array elements
    printf("\n enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Display given/unsorted data
    printf("\n given data:\n");
    for(i = 0; i < n; i++)
    {
        printf("\n %d", a[i]);
    }

    // Sorting the array (Using simple comparison sort)
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i + 1; j++)
        {
            // If current element is smaller, swap them
            if(a[i] < a[j])
            {
                sort = a[i];
                a[i] = a[j];
                a[j] = sort;
            }
        }
    }

    // Display sorted array
    printf("\nsorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("\n %d", a[i]);
    }

    // Input key to search
    printf("\n enter the key to search:\n");
    scanf("%d", &key);

    // Binary search initialization
    low = 0;
    high = n - 1;

    // Binary search loop
    while(low < high)
    {
        // Find middle index
        mid = (low + high) / 2;

        // If middle element is the key
        if(a[mid] == key)
        {
            printf("\n key found at index: %d", mid + 1); // +1 for position
            found = 1;
            break;
        }

        // If key is greater, search in right half
        if(a[mid] < key)
        {
            low = mid + 1;
            high = n - 1;
        }

        // If key is smaller, search in left half
        if(a[mid] > key)
        {
            low = 0;
            high = mid - 1;
        }
    }

    // If key was not found
    if(found == 0)
    {
        printf("\n element not found");
    }
}
