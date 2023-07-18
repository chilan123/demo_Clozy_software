#include <stdio.h>
#include <ncurses.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to display the main menu
void displayMenu() {
    clear();
    printw("Welcome to All Students - University of XYZ (UOM)\n");
    printw("1. Sticky Notes\n");
    printw("2. Special Notes\n");
    printw("3. Reminder\n");
    printw("4. Calculator\n");
    printw("5. Private (Password Protected)\n");
    printw("Enter your choice (1-5): ");
    refresh();
}

// Function to read password
void readPassword(char *password) {
    echo(); // Enable input echoing
    getstr(password);
    noecho(); // Disable input echoing
}

// Function to display and handle sticky notes
void handleStickyNotes() {
    clear();
    printw("Welcome to Sticky Notes\n");
    // Add your sticky notes functionality here
    printw("Press any key to go back to the main menu.");
    refresh();
    getch();
}

// Function to display and handle special notes
void handleSpecialNotes() {
    clear();
    printw("Welcome to Special Notes\n");
    // Add your special notes functionality here
    printw("Press any key to go back to the main menu.");
    refresh();
    getch();
}

// Function to display and handle reminders
void handleReminders() {
    clear();
    printw("Welcome to Reminders\n");
    // Add your reminders functionality here
    printw("Press any key to go back to the main menu.");
    refresh();
    getch();
}

// Function to display and handle the calculator
void handleCalculator() {
    clear();
    printw("Welcome to Calculator\n");
    // Add your calculator functionality here
    printw("Press any key to go back to the main menu.");
    refresh();
    getch();
}

// Function to display and handle private (password-protected) section
void handlePrivateSection() {
    char password[MAX_LENGTH];
    clear();
    printw("Enter Password: ");
    refresh();
    readPassword(password);
    // Add your password verification logic here
    if (strcmp(password, "mypassword") == 0) {
        printw("\nWelcome to Private Section\n");
        // Add your private section functionality here
    } else {
        printw("\nInvalid Password. Access Denied.\n");
    }
    printw("Press any key to go back to the main menu.");
    refresh();
    getch();
}

int main() {
    initscr(); // Initialize ncurses
    cbreak(); // Line buffering disabled, pass on everything to me
    keypad(stdscr, TRUE); // Enable special keys (function keys, arrow keys, etc.)

    int choice;
    do {
        displayMenu();
        scanw("%d", &choice);

        switch (choice) {
            case 1:
                handleStickyNotes();
                break;
            case 2:
                handleSpecialNotes();
                break;
            case 3:
                handleReminders();
                break;
            case 4:
                handleCalculator();
                break;
            case 5:
                handlePrivateSection();
                break;
            default:
                clear();
                printw("Invalid choice. Please enter a valid option (1-5).\n");
                printw("Press any key to continue.");
                refresh();
                getch();
                break;
        }

    } while (choice != 5);

    endwin(); // End ncurses mode

    return 0;
}
