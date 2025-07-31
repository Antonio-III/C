// A program that calculates how many days has it been since Dec 31.
#include <stdio.h>
#include <stdlib.h>

// Months in 0 index.
#define FEB 1
// 30-day months
#define APR 3
#define JUNE 5
#define SEP 8
#define NOV 10

#define LEAP_YEAR 4
#define HUNDRED_YEARS 100
#define FOUR_HUNDRED_YEARS 400

int main(int argc, char *argv[]) {
	int dd, mm, yyyy;
	int len_of_feb, day_no, month;

	printf("Enter date in dd/mm/yyyy format: \n");

	if (scanf("%d/%d/%d", &dd, &mm, &yyyy ) != 3){

		printf("Invalid input\n");

		exit(EXIT_FAILURE);
	}

    // Offset to 0 index.
    mm -= 1;

	len_of_feb = 28 + (yyyy % LEAP_YEAR == 0 && (yyyy % HUNDRED_YEARS != 0 || yyyy % FOUR_HUNDRED_YEARS == 0));
	
    day_no = dd;
	
    for (int curr_mm = 0; curr_mm < mm - 1; curr_mm += 1) {
		if (curr_mm == FEB) {
			day_no += len_of_feb;
		} else if (curr_mm == APR || curr_mm == JUNE || curr_mm == SEP || curr_mm == NOV) {
			day_no += 30;
		} else {
			day_no += 31;
		}
	}

    if (day_no == 1) {
	    printf("You are %d day into the year. \n", day_no);    
    } else {
        printf("You are %d days into the year. \n", day_no);
    }

    return EXIT_SUCCESS;
}