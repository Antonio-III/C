// This program outputs what moves should be taken to solve an n-disk Tower of Hanoi game. 
#include <stdio.h>
#include <stdlib.h>

#define DISKS 2

#define BASE 'A'
#define AUX 'B'
#define TARGET 'C'

int hanoi(char base, char auxilliary, char target, int disks);

int main(int argc, char *argv[]) {
    printf("This script shows what moves should be taken to solve a %d-disk ToH, from %c to %c.\n", DISKS, BASE, TARGET);

    int total_moves = hanoi(BASE, AUX, TARGET, DISKS);
    
    if (total_moves == 0) {
        printf("No disks were moved!\n");
    }
    printf("It takes a total of %d moves to go from %c to %c.\n", total_moves, BASE, TARGET, DISKS);
    return 0;
}

int hanoi(char base, char auxilliary, char target, int disks) {	
    if (disks <= 0) {
        return 0;
    }

    int moves = hanoi(base, target, auxilliary, disks-1);

    printf("Move %c to %c.\n",base, target);

    moves += 1;
    moves += hanoi(auxilliary, base, target, disks-1);

    return moves;
}