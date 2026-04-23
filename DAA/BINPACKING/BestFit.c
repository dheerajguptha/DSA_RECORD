//Implementation of Bin Packing (Best Fit)  

/*
Aim : To write a program to implement the Bin Packing problem using the Best Fit method.
*/

//Program

#include <stdio.h>

// Function to implement Best Fit Algorithm
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];           
    int binCount = 0;     

    // Initialize bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Process each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;             
        int minSpace = capacity + 1;    

        // Find the best bin (least leftover space after placing item)
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If suitable bin is found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i]; // Reduce remaining capacity
            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], bestIndex + 1);
        }
        else // New bin needed
        {
            bin[binCount] = capacity - items[i]; // Initialize new bin
            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], binCount + 1);
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

    /*
    Define array after knowing size
    1. Only after we know number of items
    2. Avoid wasting memory
    3. Dynamic allocation alternative
    */
    
    int items[n];

    printf("Enter bin capacity: ");
    scanf("%d", &capacity); // Fixed : %d instead of %f

    printf("Enter item sizes:\n");

    for (int i = 0; i < n; i++)
    {
        int itemSize;

        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Validate item size
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--; // Repeat same index
        }
    }

    // Call Best Fit function
    bestFit(items, n, capacity);

    return 0;
}
