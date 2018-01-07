/*Brandon Navarro
bmnavarro@wpi.edu*/

#include<stdio.h>
/** Calculates what day of the week January 1st falls on. The algorithm that I used is Gauss's algorithm that I found on https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
* @param yearr Year (A.D.)
* @return Day of the week (Sunday = 0)
*/
int startDay(int year){
	int dayofweek;	//// where sunday == 0, monday == 1... saturday == 6

	dayofweek = (year + ((year - 1)/ 4) - ((year - 1)/ 100) + ((year - 1)/ 400)) % 7;

	return dayofweek;

}

/** This method is passed the input year and the start day from the startDay method. It then counts through all 12 months (0 = Jan). First the month name and the days-of-the-week header is printed, then the param dayofweek is changed to become the return value of printMonth
* @param year Year (A.D.)
* @param dayofweek the starting day of January (Sunday = 0) 
* @return void
*/
void printCalendar(int year, int dayofweek){ 
int month; 

for (month = 0; month <= 11; month++)
	{
	printName(year, month);
	printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
	dayofweek = printMonth(year, month, dayofweek);

	}
}

/** This method runs individually for all 12 months and figures out how to format said month. It also changes dayformonth param to the starting day for the next month and returns that value.
* @param year Year (A.D.)
* @param month (January = 0)
* @param dayformonth (Sunday = 0) 
* @return dayformonth
*/
int printMonth(int year, int month, int dayformonth){	

	int day; // the day the next month starts
	int space;
		
	// Print the first date in the correct place
	for (space = 1; space <= 1 + dayformonth * 5; space++)
	{
		printf(" ");
	}
	
	// Print all the dates for one month
	for (day = 1; day <= printMonthName(year, month); day++)
	{
		printf("%2d", day);
		
	// If not Sunday, print spaces, else print newline
		if ((day + dayformonth) % 7 > 0)
			printf("   ");
		else
			printf("\n ");
	}
	// Set position for next month, remainder should be number 0-6, thus signaling what day to next month on
	dayformonth = ((dayformonth + printMonthName(year, month)) % 7);
return dayformonth;

}


/** This method runs individually for all 12 months and simply prints the name of the month
* @param year Year (A.D.)
* @param month (January = 0)
* @return void
*/
int printName(int year, int month){
int day;
	switch(month){
		case 0:
			printf("\n\n\nJanuary %d", year);
			break;
		case 1:
			printf("\n\n\nFebuary %d", year);
			break;
		case 2:
			printf("\n\n\nMarch %d", year);
			break;
		case 3:
			printf("\n\n\nApril %d", year);
			break;
			
		case 4:
			printf("\n\n\nMay %d", year);
			break;
		case 5:
			printf("\n\n\nJune %d", year);
			break;
		case 6:
			printf("\n\n\nJuly %d", year);
			break;
		case 7:
			printf("\n\n\nAugust %d", year);
			break;
		case 8:
			printf("\n\n\nSeptember %d", year);
			break;
		case 9:
			printf("\n\n\nOctober %d", year);
			break;
		case 10:
			printf("\n\n\nNovember %d", year);
			break;
		case 11:
			printf("\n\n\nDecember %d", year);
			break;
	}
}

/** This method returns the number of days in that month, if the month is febuary then it uses the algorithm given in the K&R reading to determine whether or not it should be a leap year
* @param year Year (A.D.)
* @param month (January = 0) 
* @return int (number of days in corresponding month)
*/
int printMonthName(int year, int month){
int day;
	switch(month){
		case 0:
			//printf("\n\n\nJanuary");
			return 31;
			break;
		case 1:
			//printf("\n\n\nFebuary");
			if(year% 4 == 0 && year%100 != 0 || year%400 == 0)	//this is from the K&R reading from chapter 2
			return 29;
			else
			return 28;
			break;
		case 2:
			//printf("\n\n\nMarch");
			return 31;
			break;
		case 3:
			//printf("\n\n\nApril");
			return 30;
			break;
		case 4:
			//printf("\n\n\nMay");
			return 31;
			break;
		case 5:
			//printf("\n\n\nJune");
			return 30;
			break;
		case 6:
			//printf("\n\n\nJuly");
			return 31;
			break;
		case 7:
			//printf("\n\n\nAugust");
			return 31;
			break;
		case 8:
			//printf("\n\n\nSeptember");
			return 30;
			break;
		case 9:
			//printf("\n\n\nOctober");
			return 31;
			break;
		case 10:
			//printf("\n\n\nNovember");
			return 30;
			break;
		case 11:
			//printf("\n\n\nDecember");
			return 31;
			break;
	}


}

/** The main method promts the user to enter a year and then stores that input and runs the startDay method with it to begin the program. Once we get the correct start day for Jan of that year, the rest of the program can run by inputing those 2 values into the print calendar
* @param year Year (A.D.)
* @param month (January = 0) 
* @return int (number of days in corresponding month)
*/
int main(void){
int year;
int day; // where sunday == 0, monday == 1... saturday == 6

printf("Please enter year for this calendar: ");
scanf("%d", &year);
printf("\n\n********CALANDAR FOR %d********", year);

day = startDay(year);
printCalendar(year, day);

}

