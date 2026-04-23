//Implementation of Bin Packing (First Fit) 

/*
   AIM : To write a program to implement the Bin Packing problem      using the First Fit method
*/

// Program

#include <stdio.h>

// Function to implement First Fit Algorithm
void firstFit(int items[], int n, int capacity)
{
    int bin[n];              // Available capacity of bins
    int binCount = 0;        // Number of bins used / active bins

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Process each item
    for (int i = 0; i < n; i++)
    {
        int placed = 0; // Flag to check if item is placed

        // Check existing bins
        for (int j = 0; j < binCount; j++)
        {
            // If item fits in the current bin
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i]; // Reduce bin capacity
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break; // First Fit: stop at first match
            }
        }

        // Create new bin if item not placed
        if (!placed)
        {
            bin[binCount] = capacity - items[i];
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++;
        }
    }

    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    int items[n];

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        int itemSize;

        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Check if item size is valid
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--; // Repeat input for same index
        }
    }

    // Call First Fit function
    firstFit(items, n, capacity);

    return 0;
}
