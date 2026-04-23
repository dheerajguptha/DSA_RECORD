// Tower Of Hanoi

/*
AIM : To write a program to solve the Tower of Hanoi problem using recursion and display the sequence of moves required to transfer all disks
from the source rod to the destination rod following the rules.
*/

// Program

#include <stdio.h>

void towerOfHanoi(int diskNumber, char source, char destination, char auxiliary)
{
    
// Base Condition: Only one disk to move 

if (diskNumber == 1) {
    printf("Move disk 1 from %c to %c\n", source, destination);
return;
}

// Step 1: Move n-1 disks from source to auxiliary 
  
towerOfHanoi(diskNumber - 1, source, auxiliary, destination);

// Step 2: Move the nth disk from source to destination 
  
printf("Move disk %d from %c to %c\n", diskNumber, source, destination);

// Step 3: Move n-1 disks from auxiliary to destination 
  
towerOfHanoi(diskNumber - 1, auxiliary, destination, source);
}

int main() {
    int n; 
    printf("Enter number of disks: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
 }
 printf("\nRequired moves:\n");
 towerOfHanoi(n, 'S', 'D', 'A');

 return 0;
 }
