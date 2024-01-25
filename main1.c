#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// for getch function

// Structure to store user details
typedef struct {
    char username[50];
    char password[50];
    int age;
    char gender;  // 'M' for Male, 'F' for Female, 'O' for Other
} User;

// Structure to store ticket details
typedef struct {
    int seatNumber;
    User passenger;
} Ticket;

// Global user variable to store the current user
User currentUser;

// Function prototypes
void login();
void bookIndividual(Ticket *ticket);
void bookBulk();
void checkInactivity();

int main() {
    login();  // Call the login function to populate the currentUser

    char choice;

    while (1) {
        //checkInactivity(start_time);

        printf("\nDo you want to book seats individually or in bulk? (I/B): ");
        scanf(" %c", &choice);

        if (choice == 'I' || choice == 'i') {
            Ticket ticket;
            bookIndividual(&ticket);
            printf("\nTicket booked successfully for seat number: %d\n", ticket.seatNumber);
            printf("\n Use code 'SAVE20' to get 20 percent off on your next booking!\n ");
            break;
        } else if (choice == 'B' || choice == 'b') {
            bookBulk();
            break;
        } else {
            printf("\nInvalid choice!\n");
            break;
        }
    }

    return 0;
}

void login() {
    printf("\t\t\t\t\tWelcome to Advanced Train Reservation\n");
    printf("Enter your username: ");
    scanf("%s", currentUser.username);

    // Prompt for password with asterisk symbols
    printf("Enter your password: ");
    int i = 0;
    while (1) {
        currentUser.password[i] = getch();  // Use getch to get characters without echoing
        if (currentUser.password[i] == '\r') {  // Enter key pressed
            currentUser.password[i] = '\0';  // Null-terminate the password string
            break;
        } else {
            printf("*");  // Print asterisk for each character
            i++;
        }
    }

    printf("\nEnter your age: ");
    scanf("%d", &currentUser.age);

    // Option to choose gender
    printf("\nChoose your gender (M for Male, F for Female, O for Other): ");
    scanf(" %c", &currentUser.gender);
}

void bookIndividual(Ticket *ticket) {
    printf("\nBooking ticket individually...\n");

    // For simplicity, if the user is a female or old (age > 60), assign a lower berth
    if (currentUser.gender == 'F' || currentUser.age > 60 || currentUser.gender == 'f') {
        printf("Assigning lower berth seat...\n");
        ticket->seatNumber = 1;  // Assume seat 1 as the lower berth
    } else {
        printf("Assigning upper berth seat...\n");
        ticket->seatNumber = 2;  // Assume seat 2 as the upper berth
    }
}

void bookBulk() {
    printf("\nBulk Booking Offer:\n");
    int bulk_no;
    printf("\nEnter The Number Of Seats You Want : ");
    scanf("%d", &bulk_no);
    int amount = bulk_no * 50;
    if (bulk_no >= 101) {
        printf("Sorry, Our train Only Has 100 Seats\n");
    } else if (bulk_no >= 11 && bulk_no <= 100) {
        printf("\nYou Got Discount For Booking More Than 10 Seats ");

        float discount = amount * 0.2;
        printf("\nYour Actual Price : %d$", amount);
        printf("\nAfter %20 Discount : %f$", amount - discount);
        printf("\nUse code 'SAVE20' to get 20 percent off on your next booking!\n");

    } else {
        printf("\nYour Ticket Price is %d$ for Booking %d Seats", amount, bulk_no);
        printf("\nUse code 'SAVE20' to get 20 percent off on your next booking!\n");
    }

}
