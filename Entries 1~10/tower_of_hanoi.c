// This program outputs what moves should be taken to solve an `n`-disk Tower of Hanoi game. 
// The program assumes that all disks are initially on pole A and the goal is to put all disks onto C, using B as the auxilliary.
#include <stdio.h>
#include <stdlib.h>

#define DISKS 2

int hanoi(char base, char auxilliary, char target, int disks);

int main(int argc, char *argv[]){
    char base = 'A';
    char auxilliary = 'B';
    char target = 'C';
    int total_moves=hanoi(base, auxilliary, target,DISKS);
    
    if (total_moves==0){
        printf("No disks were moved!\n");
    }
    printf("It took a total of %d moves to go from %c to %c\n", total_moves, base, target);
    return 0;
}

int hanoi(char base, char auxilliary, char target, int disks){	
    if (disks<=0){
        return 0;
    }
    int moves=hanoi(base,target,auxilliary,disks-1);
    printf("Move %c to %c.\n",base, target);
    moves+=1;
    moves+=hanoi(auxilliary, base, target,disks-1);
    return moves;
}