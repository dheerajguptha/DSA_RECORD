                                                                                  ----//TOWER OF HANOI//----
                                                                                    
⏲ Program:
                                                                                    
#include <stdio.h>
void towerofhanoi(int n, char S, char A, char D)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", S, D);
        return;
    }
    towerofhanoi(n - 1, S, D, A);
    printf("Move disk %d from %c to %c\n", n, S, D);
    towerofhanoi(n - 1, A, S, D);
}
int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("\nRequired moves:\n");
    towerofhanoi(n, 'S', 'A', 'D');
    return 0;
}
