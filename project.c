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
struct Client {
    int clientID;
    char clientName[50];
    char phone[20];
    char email[50];
    char address[100];
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
           //DOMAIN NO : 2

    // Check if Event ID was found
    if (found == 0) {
        printf("\nEvent Not Found!\n");
    }
}
// Function to add a new client
void addClient(struct Client clients[], int *clientCount)
{
    // Take Client ID from the user
    printf("\nEnter Client ID: ");
    scanf("%d", &clients[*clientCount].clientID);

    // Take Client Name (including spaces)
    printf("Enter Client Name: ");
    scanf(" %49[^\n]", clients[*clientCount].clientName);

    // Take Client Phone Number
    printf("Enter Phone Number: ");
    scanf(" %19[^\n]", clients[*clientCount].phone);

    // Take Client Email
    printf("Enter Email: ");
    scanf(" %49[^\n]", clients[*clientCount].email);

    // Take Client Address (including spaces)
    printf("Enter Address: ");
    scanf(" %99[^\n]", clients[*clientCount].address);

    // Increase the original client counter by one
    (*clientCount)++;

    // Display success message
    printf("\nClient added successfully!\n");
}

// Function to display all client records
void displayClients(struct Client clients[], int clientCount)
{
    // Check whether any clients have been added
    if (clientCount == 0)
    {
        printf("\nNo clients available!\n");
    }
    else
    {
        // Loop through all stored clients
        for (int i = 0; i < clientCount; i++)
        {
            printf("\n-----------------------------\n");

            // Display client information
            printf("Client ID: %d\n", clients[i].clientID);
            printf("Client Name: %s\n", clients[i].clientName);
            printf("Phone: %s\n", clients[i].phone);
            printf("Email: %s\n", clients[i].email);
            printf("Address: %s\n", clients[i].address);
        }
    }
}

// Function to search for a client using Client ID
void searchClient(struct Client clients[], int clientCount)
{
    int searchID;
    int found = 0;  // Flag to check whether client exists

    // Ask the user for the Client ID
    printf("\nEnter Client ID to search: ");
    scanf("%d", &searchID);

    // Search through all stored clients
    for (int i = 0; i < clientCount; i++)
    {
        // Compare entered ID with stored Client IDs
        if (clients[i].clientID == searchID)
        {
            // Display the matching client's details
            printf("\nClient Found!\n");
            printf("Client ID: %d\n", clients[i].clientID);
            printf("Client Name: %s\n", clients[i].clientName);
            printf("Phone: %s\n", clients[i].phone);
            printf("Email: %s\n", clients[i].email);
            printf("Address: %s\n", clients[i].address);

            found = 1;  // Mark client as found
            break;      // Stop searching
        }
    }

    // Display message if no matching client exists
    if (found == 0)
    {
        printf("Client not found!\n");
    }
}

// Function to update an existing client's information
void updateClient(struct Client clients[], int clientCount)
{
    int updateID;
    int found = 0;  // Flag to check whether client exists

    // Ask for the Client ID to update
    printf("\nEnter Client ID to update: ");
    scanf("%d", &updateID);

    // Search for the client
    for (int i = 0; i < clientCount; i++)
    {
        // Check whether the entered ID matches
        if (clients[i].clientID == updateID)
        {
            printf("\nClient Found! Enter New Details:\n");

            // Update client name
            printf("Enter New Name: ");
            scanf(" %49[^\n]", clients[i].clientName);

            // Update phone number
            printf("Enter New Phone: ");
            scanf(" %19[^\n]", clients[i].phone);

            // Update email address
            printf("Enter New Email: ");
            scanf(" %49[^\n]", clients[i].email);

            // Update client address
            printf("Enter New Address: ");
            scanf(" %99[^\n]", clients[i].address);

            found = 1;  // Mark client as found

            printf("'\nClient Updated Successfully!\n");
            break;  // Stop searching
        }
    }

    // Check whether the client was not found
    if (found == 0)
    {
        printf("Client not found!\n");
    }
}

// Function to delete a client using Client ID
void deleteClient(struct Client clients[], int *clientCount)
{
    int deleteID;
    int found = 0;  // Flag to check whether client exists

    // Ask the user for the Client ID
    printf("\nEnter Client ID to delete: ");
    scanf("%d", &deleteID);

    // Search for the client
    for (int i = 0; i < *clientCount; i++)
    {
        // Check whether the entered ID matches
        if (clients[i].clientID == deleteID)
        {
            // Shift all records after the deleted client one position left
            for (int j = i; j < *clientCount - 1; j++)
            {
                clients[j] = clients[j + 1];
            }

            // Decrease the original client counter
            (*clientCount)--;

            found = 1;  // Mark client as found

            printf("\nClient Deleted Successfully!\n");
            break;  // Stop searching
        }
    }

    // Display message if client does not exist
    if (found == 0)
    {
        printf("\nClient not found!\n");
    }
}




    
int main() {

    // Array to store maximum 100 events
    struct Event events[100];
    // Initially, no events are stored
    int count = 0;
    struct Client clients[100];
    int clientCount = 0;

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
        // Client Management options
        printf("\n--- CLIENT MANAGEMENT ---\n");
        printf("6. Add Client\n");
        printf("7. Display All Clients\n");
        printf("8. Search Client\n");
        printf("9. Update Client\n");
        printf("10. Delete Client\n");
        printf("11. Exit\n");

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
                addClient(clients, &clientCount);
                break;

            case 7:
                displayClients(clients, clientCount);
                break;

            
            case 8:
                searchClient(clients, clientCount);
                break;

             case 9:
                updateClient(clients, clientCount);
                break;

            case 10:
                deleteClient(clients, &clientCount);
                break;

            //exit program
            case 11:
            printf("\nThank you for using Event Management System!\n");
            return 0;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


    



    