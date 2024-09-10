#include <stdio.h>
// Define a structure for Date
struct Date {
int day;
int month;
int year;
};
// Function to initialize the date
void initDate(struct Date* ptrDate) {
ptrDate->day = 1;
ptrDate->month = 1;
ptrDate->year = 2000;
}
// Function to print the date on the console
void printDateOnConsole(struct Date* ptrDate) {
printf("Date: %02d-%02d-%04d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}
// Function to accept date from the console
void acceptDateFromConsole(struct Date* ptrDate) {
printf("Enter day (1-31): ");
scanf("%d", &ptrDate->day);
printf("Enter month (1-12): ");
scanf("%d", &ptrDate->month);
printf("Enter year: ");
scanf("%d", &ptrDate->year);
}
// Main function with menu-driven program
int main() {
struct Date date;
int choice;
do {
printf("\nMenu:\n");
printf("1. Initialize Date\n");
printf("2. Accept Date from Console\n");
printf("3. Print Date on Console\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
initDate(&date);
printf("Date initialized to default values.\n");
break;
case 2:
acceptDateFromConsole(&date);
break;
case 3:
printDateOnConsole(&date);
break;
case 4:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 4);
return 0;
}