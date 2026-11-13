#include<stdio.h>
//DOMAIN NO :1
struct Event {
    int eventID;
    char eventName[50];
    char eventType[30];
    char eventDate[20];
    int clientID;
    int venueID;
    int guestCount;
    float budget;
};

void addEvent(struct Event events[], int *count) {

    printf("\nEnter Event ID: ");
    scanf("%d", &events[*count].eventID);

    printf("Enter Event Name: ");
    scanf("%49[^\n]", events[*count].eventName);

    printf("Enter Event Type: ");
    scanf("%29[^\n]", events[*count].eventType);

    printf("Enter Event Date: ");
    scanf("%19[^\n]", events[*count].eventDate);

    printf("Enter Client ID: ");
    scanf("%d", &events[*count].clientID);

    printf("Enter Venue ID: ");
    scanf("%d", &events[*count].venueID);

    printf("Enter Guest Count: ");
    scanf("%d", &events[*count].guestCount);

    printf("Enter Budget: ");
    scanf("%f", &events[*count].budget);

    (*count)++;

    printf("\nEvent added successfully!\n");
}

// Function to display all stored events
void displayEvents(struct Event events[], int count) {

    // Check if there are no events
    if (count == 0) {
        printf("No events available!\n");
        return;
    }

    // Loop through all stored events
    for (int i = 0; i < count; i++) {

        printf("\n******Event %d*******\n", i + 1);

        printf("Event ID: %d\n", events[i].eventID);
        printf("Event Name: %s\n", events[i].eventName);
        printf("Event Type: %s\n", events[i].eventType);
        printf("Event Date: %s\n", events[i].eventDate);
        printf("Client ID: %d\n", events[i].clientID);
        printf("Venue ID: %d\n", events[i].venueID);
        printf("Guest Count: %d\n", events[i].guestCount);
        printf("Budget: %.2f\n", events[i].budget);
    }
}

// Function to search an event using Event ID
void searchEvent(struct Event events[], int count) {

    int searchID;
    int found = 0;

    // Ask user for Event ID
    printf("\nEnter Event ID to search: ");
    scanf("%d", &searchID);

    // Search through all stored events
    for (int i = 0; i < count; i++) {

        // Compare entered ID with stored Event ID
        if (events[i].eventID == searchID) {

            printf("\nEvent Found!\n");

            printf("Event ID: %d\n", events[i].eventID);
            printf("Event Name: %s\n", events[i].eventName);
            printf("Event Type: %s\n", events[i].eventType);
            printf("Event Date: %s\n", events[i].eventDate);
            printf("Client ID: %d\n", events[i].clientID);
            printf("Venue ID: %d\n", events[i].venueID);
            printf("Guest Count: %d\n", events[i].guestCount);
            printf("Budget: %.2f\n", events[i].budget);

            found = 1;
            break;
        }
    }

    // Check whether the event was found
    if (found == 0) {
        printf("\nEvent not found!\n");
    }
}

// Function to update an existing event
void updateEvent(struct Event events[], int count) {

    int updateID;
    int found = 0;

    // Ask for Event ID
    printf("\nEnter Event ID to update: ");
    scanf("%d", &updateID);

    // Search for the event
    for (int i = 0; i < count; i++) {

        if (events[i].eventID == updateID) {

            printf("\nEvent Found! Enter New Details.\n");

            // Update Event Name
            printf("Enter New Event Name: ");
            scanf(" %49[^\n]", events[i].eventName);

            // Update Event Type
            printf("Enter New Event Type: ");
            scanf(" %29[^\n]", events[i].eventType);

            // Update Event Date
            printf("Enter New Event Date: ");
            scanf(" %19[^\n]", events[i].eventDate);

            // Update Client ID
            printf("Enter New Client ID: ");
            scanf("%d", &events[i].clientID);

            // Update Venue ID
            printf("Enter New Venue ID: ");
            scanf("%d", &events[i].venueID);

            // Update Guest Count
            printf("Enter New Guest Count: ");
            scanf("%d", &events[i].guestCount);

            // Update Budget
            printf("Enter New Budget: ");
            scanf("%f", &events[i].budget);

            found = 1;

            printf("\nEvent Updated Successfully!\n");

            break;
        }
    }

    // Check if Event ID was found
    if (found == 0) {
        printf("\nEvent Not Found!\n");
    }
}

// Function to delete an existing event
void deleteEvent(struct Event events[], int *count) {

    int deleteID;
    int found = 0;

    // Ask user for Event ID
    printf("\nEnter Event ID to delete: ");
    scanf("%d", &deleteID);

    // Search for the event
    for (int i = 0; i < *count; i++) {

        if (events[i].eventID == deleteID) {

            // Shift remaining events one position to the left
            for (int j = i; j < *count - 1; j++) {
                events[j] = events[j + 1];
            }

            // Decrease count after deletion
            (*count)--;

            found = 1;

            printf("\nEvent Deleted Successfully!\n");

            break;
        }
    }

    // Check if Event ID was found
    if (found == 0) {
        printf("\nEvent Not Found!\n");
    }
}





    
int main() {

    // Array to store maximum 100 events
    struct Event events[100];

    // Initially, no events are stored
    int count = 0;

    int ch;

    // Repeat menu until user chooses Exit
    while (1) {

        printf("==============================\n");
        printf("       EVENT MANAGEMENT       \n");
        printf("==============================\n");

        printf("1. Add Event\n");
        printf("2. Display All Events\n");
        printf("3. Search Event\n");
        printf("4. Update Event\n");
        printf("5. Delete Event\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        // Perform operation according to user's choice
        switch (ch) {

            case 1:
                addEvent(events, &count);
                break;

            case 2:
                displayEvents(events, count);
                break;

            case 3:
                searchEvent(events, count);
                break;

            case 4:
                updateEvent(events, count);
                break;

            case 5:
                deleteEvent(events, &count);
                break;

            case 6:
                printf("\nThank you for using Event Management System!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}


    



    