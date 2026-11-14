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
// Structure to store inventory item information
struct Inventory {
    int itemID;             // Unique ID of each item
    char itemName[50];      // Name of the item
    char category[30];      // Category of the item
    int quantity;           // Available quantity
    float price;            // Price per item
};
// Structure to store venue information
struct Venue {
    int venueID;                 // Unique ID of each venue
    char venueName[50];          // Name of the venue
    char location[100];          // Venue location
    int capacity;                // Maximum number of guests
    float rentalPrice;           // Venue rental cost
    char availability[20];       // Availability status
    char contactNumber[20];      // Venue contact number
};
// Structure to store vendor information
struct Vendor {
    int vendorID;             // Unique ID of each vendor
    char vendorName[50];      // Name of vendor or company
    char serviceType[50];     // Service provided by vendor
    char phone[20];           // Vendor contact number
    char email[50];           // Vendor email address
    float servicePrice;       // Price of the service
};
// Structure to store payment information
struct Payment {
    int paymentID;             // Unique payment ID
    int eventID;               // Related event ID
    int clientID;              // Related client ID
    float totalAmount;         // Total event amount
    float paidAmount;          // Amount already paid
    char paymentDate[20];      // Date of payment
    char paymentStatus[20];    // Payment status
};

void addEvent(struct Event events[], int *count) {
    // Check whether the array is full
    if (*count >= 100) {
    printf("\nMaximum event limit reached!\n");
    return;
}

    int newID;

    printf("Enter Event ID: ");
    scanf("%d", &newID);

    // Check whether this ID already exists
    for (int i = 0; i < *count; i++) {
        if (events[i].eventID == newID) {
            printf("\nThis Event ID already exists!\n");
            return;
        }
    }

    events[*count].eventID = newID;

    printf("Enter Event Name: ");
    scanf(" %49[^\n]", events[*count].eventName);

    printf(" Enter Event Type: ");
    scanf(" %29[^\n]", events[*count].eventType);

    printf("Enter Event Date: ");
    scanf(" %19[^\n]", events[*count].eventDate);

    printf("Enter Client ID: ");
    scanf("%d", &events[*count].clientID);

    printf("Enter Venue ID: ");
    scanf("%d", &events[*count].venueID);

    printf("Enter Guest Count: ");
    scanf("%d", &events[*count].guestCount);

    if (events[*count].guestCount < 0) {
        printf("\nGuest count cannot be negative!\n");
        return;
}

    printf("Enter Budget: ");
    scanf("%f", &events[*count].budget);

    if (events[*count].budget < 0) {
        printf("\nBudget cannot be negative!\n");
        return;
}

    printf("\nEvent added successfully!\n");
    (*count)++;
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
void addClient(struct Client clients[], int *clientCount){
    if (*clientCount >= 100) {
    printf("\nMaximum client limit reached!\n");
    return;
}
    // Take Client ID from the user
    int newID;

    printf("\nEnter Client ID: ");
    scanf("%d", &newID);

    // Check for duplicate Client ID
    for (int i = 0; i < *clientCount; i++) {
        if (clients[i].clientID == newID) {
            printf("\nThis Client ID already exists!\n");
            return;
        }
    }

clients[*clientCount].clientID = newID;

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
        //DOMAIN NO:3

// Function to add a new inventory item
void addInventory(struct Inventory inventory[], int *inventoryCount)
{
    if (*inventoryCount >= 100) {
    printf("\nMaximum inventory limit reached!\n");
    return;
}
    int newID;

    printf("Enter Item ID: ");
    scanf("%d", &newID);

    // Check for duplicate Item ID
    for (int i = 0; i < *inventoryCount; i++) {
        if (inventory[i].itemID == newID) {
            printf("\nThis Item ID already exists!\n");
            return;
        }
    }

    inventory[*inventoryCount].itemID = newID;

    // Take Item Name (including spaces)
    printf("Enter Item Name: ");
    scanf(" %49[^\n]", inventory[*inventoryCount].itemName);

    // Take Item Category
    printf("Enter Category: ");
    scanf(" %29[^\n]", inventory[*inventoryCount].category);

    // Take Available Quantity
    printf("Enter Quantity: ");
    scanf("%d", &inventory[*inventoryCount].quantity);

    if (inventory[*inventoryCount].quantity < 0) {
        printf("\nQuantity cannot be negative!\n");
        return;
}

    // Take Price of one item
    printf("Enter Price: ");
    scanf("%f", &inventory[*inventoryCount].price);

    if (inventory[*inventoryCount].price < 0) {
        printf("\nPrice cannot be negative!\n");
        return;
}

    // Increase inventory counter by one
    (*inventoryCount)++;

    // Display success message
    printf("\nInventory Item Added Successfully!\n");
}
// Function to display all inventory items
void displayInventory(struct Inventory inventory[], int inventoryCount)
{
    // Check whether inventory is empty
    if (inventoryCount == 0)
    {
        printf("\nNo inventory items available!\n");
    }
    else
    {
        // Loop through all stored inventory items
        for (int i = 0; i < inventoryCount; i++)
        {
            printf("\n-----------record %d------------------\n",i+1);

            // Display item information
            printf("Item ID: %d\n", inventory[i].itemID);
            printf("Item Name: %s\n", inventory[i].itemName);
            printf("Category: %s\n", inventory[i].category);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
        }
    }
}
// Function to search for an inventory item using Item ID
void searchInventory(struct Inventory inventory[], int inventoryCount)
{
    int searchID;
    int found = 0;  // Flag to check whether item exists

    // Ask the user for the Item ID
    printf("\nEnter Item ID to search: ");
    scanf("%d", &searchID);

    // Search through all inventory records
    for (int i = 0; i < inventoryCount; i++)
    {
        // Compare entered ID with stored Item IDs
        if (inventory[i].itemID == searchID)
        {
            // Display the matching item's details
            printf("\nInventory Item Found!\n");
            printf("Item ID: %d\n", inventory[i].itemID);
            printf("Item Name: %s\n", inventory[i].itemName);
            printf("Category: %s\n", inventory[i].category);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);

            found = 1;  // Mark item as found
            break;      // Stop searching
        }
    }

    // Display message if item does not exist
    if (found == 0)
    {
        printf("\nInventory Item Not Found!\n");
    }
}
// Function to update an existing inventory item
void updateInventory(struct Inventory inventory[], int inventoryCount)
{
    int updateID;
    int found = 0;  // Flag to check whether item exists

    // Ask for the Item ID to update
    printf("\nEnter Item ID to update: ");
    scanf("%d", &updateID);

    // Search for the inventory item
    for (int i = 0; i < inventoryCount; i++)
    {
        // Check whether entered ID matches
        if (inventory[i].itemID == updateID)
        {
            printf("\nItem Found! Enter New Details:\n");

            // Update item name
            printf("Enter New Item Name: ");
            scanf(" %49[^\n]", inventory[i].itemName);

            // Update item category
            printf("Enter New Category: ");
            scanf(" %29[^\n]", inventory[i].category);

            // Update available quantity
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);

            // Update item price
            printf("Enter New Price: ");
            scanf("%f", &inventory[i].price);

            found = 1;  // Mark item as found

            printf("\nInventory Item Updated Successfully!\n");
            break;  // Stop searching
        }
    }

    // Check whether item was not found
    if (found == 0)
    {
        printf("\nInventory Item Not Found!\n");
    }
}
// Function to delete an inventory item using Item ID
void deleteInventory(struct Inventory inventory[], int *inventoryCount)
{
    int deleteID;
    int found = 0;  // Flag to check whether item exists

    // Ask the user for the Item ID to delete
    printf("\nEnter Item ID to delete: ");
    scanf("%d", &deleteID);

    // Search through all inventory records
    for (int i = 0; i < *inventoryCount; i++)
    {
        // Check whether entered ID matches
        if (inventory[i].itemID == deleteID)
        {
            // Shift remaining records one position to the left
            for (int j = i; j < *inventoryCount - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }

            // Decrease the original inventory counter
            (*inventoryCount)--;

            found = 1;  // Mark item as found

            printf("\nInventory Item Deleted Successfully!\n");
            break;  // Stop searching
        }
    }

    // Display message if item does not exist
    if (found == 0)
    {
        printf("\nInventory Item Not Found!\n");
    }
}
        //DOMAIN NO: 4

// Function to add a new venue
void addVenue(struct Venue venues[], int *venueCount)
{
    if (*venueCount >= 100) {
    printf("\nMaximum venue limit reached!\n");
    return;
}
    int newID;

    printf("\nEnter Venue ID: ");
    scanf("%d", &newID);

    // Check for duplicate Venue ID
    for (int i = 0; i < *venueCount; i++) {
        if (venues[i].venueID == newID) {
            printf("\nThis Venue ID already exists!\n");
            return;
        }
    }

    venues[*venueCount].venueID = newID;

    // Take Venue Name (including spaces)
    printf("Enter Venue Name: ");
    scanf(" %49[^\n]", venues[*venueCount].venueName);

    // Take Venue Location
    printf("Enter Venue Location: ");
    scanf(" %99[^\n]", venues[*venueCount].location);

    // Take maximum guest capacity
    printf("Enter Venue Capacity: ");
    scanf("%d", &venues[*venueCount].capacity);
    
    if (venues[*venueCount].capacity <= 0) 
    {
    printf("\nVenue capacity must be greater than zero!\n");
    return;
}

    // Take venue rental price
    printf("Enter Rental Price: ");
    scanf("%f", &venues[*venueCount].rentalPrice);
    if (venues[*venueCount].rentalPrice < 0) {
    printf("\nRental price cannot be negative!\n");
    return;
}

    // Take venue availability status
    printf("Enter Availability (Available/Booked): ");
    scanf(" %19[^\n]", venues[*venueCount].availability);

    // Take venue contact number
    printf("Enter Contact Number: ");
    scanf(" %19[^\n]", venues[*venueCount].contactNumber);

    // Increase venue counter by one
    (*venueCount)++;

    // Display success message
    printf("\nVenue Added Successfully!\n");
}

// Function to display all venue records
void displayVenues(struct Venue venues[], int venueCount)
{
    // Check whether any venues have been added
    if (venueCount == 0)
    {
        printf("\nNo venues available!\n");
    }
    else
    {
        // Loop through all stored venues
        for (int i = 0; i < venueCount; i++)
        {
            printf("-----------------------------\n");

            // Display venue information
            printf("Venue ID: %d\n", venues[i].venueID);
            printf("Venue Name: %s\n", venues[i].venueName);
            printf("Location: %s\n", venues[i].location);
            printf("Capacity: %d\n", venues[i].capacity);
            printf("Rental Price: %.2f\n", venues[i].rentalPrice);
            printf("Availability: %s\n", venues[i].availability);
            printf("Contact Number: %s\n", venues[i].contactNumber);
        }
    }
}

// Function to search for a venue using Venue ID
void searchVenue(struct Venue venues[], int venueCount)
{
    int searchID;
    int found = 0;  // Flag to check whether venue exists

    // Ask the user for Venue ID
    printf("\nEnter Venue ID to search: ");
    scanf("%d", &searchID);

    // Search through all stored venues
    for (int i = 0; i < venueCount; i++)
    {
        // Compare entered ID with stored Venue IDs
        if (venues[i].venueID == searchID)
        {
            // Display the matching venue's details
            printf("\nVenue Found!\n");
            printf("Venue ID: %d\n", venues[i].venueID);
            printf("Venue Name: %s\n", venues[i].venueName);
            printf("Location: %s\n", venues[i].location);
            printf("Capacity: %d\n", venues[i].capacity);
            printf("Rental Price: %.2f\n", venues[i].rentalPrice);
            printf("Availability: %s\n", venues[i].availability);
            printf("Contact Number: %s\n", venues[i].contactNumber);

            found = 1;  // Mark venue as found
            break;      // Stop searching
        }
    }

    // Display message if venue was not found
    if (found == 0)
    {
        printf("\nVenue Not Found!\n");
    }
}

// Function to update an existing venue
void updateVenue(struct Venue venues[], int venueCount)
{
    int updateID;
    int found = 0;  // Flag to check whether venue exists

    // Ask for Venue ID to update
    printf("\nEnter Venue ID to update: ");
    scanf("%d", &updateID);

    // Search for the venue
    for (int i = 0; i < venueCount; i++)
    {
        // Check whether entered ID matches
        if (venues[i].venueID == updateID)
        {
            printf("\nVenue Found! Enter New Details:\n");

            // Update venue name
            printf("Enter New Venue Name: ");
            scanf(" %49[^\n]", venues[i].venueName);

            // Update venue location
            printf("Enter New Location: ");
            scanf(" %99[^\n]", venues[i].location);

            // Update venue capacity
            printf("Enter New Capacity: ");
            scanf("%d", &venues[i].capacity);

            // Update venue rental price
            printf("Enter New Rental Price: ");
            scanf("%f", &venues[i].rentalPrice);

            // Update venue availability
            printf("Enter New Availability: ");
            scanf(" %19[^\n]", venues[i].availability);

            // Update venue contact number
            printf("Enter New Contact Number: ");
            scanf(" %19[^\n]", venues[i].contactNumber);

            found = 1;  // Mark venue as found

            printf("\nVenue Updated Successfully!\n");
            break;  // Stop searching
        }
    }

    // Display message if venue was not found
    if (found == 0)
    {
        printf("\nVenue Not Found!\n");
    }
}

// Function to delete a venue using Venue ID
void deleteVenue(struct Venue venues[], int *venueCount)
{
    int deleteID;
    int found = 0;  // Flag to check whether venue exists

    // Ask the user for Venue ID to delete
    printf("\nEnter Venue ID to delete: ");
    scanf("%d", &deleteID);

    // Search through all stored venues
    for (int i = 0; i < *venueCount; i++)
    {
        // Check whether entered ID matches
        if (venues[i].venueID == deleteID)
        {
            // Shift remaining records one position to the left
            for (int j = i; j < *venueCount - 1; j++)
            {
                venues[j] = venues[j + 1];
            }

            // Decrease the original venue counter
            (*venueCount)--;

            found = 1;  // Mark venue as found

            printf("\nVenue Deleted Successfully!\n");
            break;  // Stop searching
        }
    }

    // Display message if venue was not found
    if (found == 0)
    {
        printf("\nVenue Not Found!\n");
    }
}
    // DOMAIN NO :5

// Function to add a new vendor
void addVendor(struct Vendor vendors[], int *vendorCount)
{
    if (*vendorCount >= 100) {
    printf("\nMaximum vendor limit reached!\n");
    return;
}
    int newID;

    printf("\nEnter Vendor ID: ");
    scanf("%d", &newID);

    // Check for duplicate Vendor ID
    for (int i = 0; i < *vendorCount; i++) {
        if (vendors[i].vendorID == newID) {
            printf("\nThis Vendor ID already exists!\n");
            return;
        }
    }

vendors[*vendorCount].vendorID = newID;
    // Take Vendor Name
    printf("Enter Vendor Name: ");
    scanf(" %49[^\n]", vendors[*vendorCount].vendorName);

    // Take Service Type
    printf("Enter Service Type: ");
    scanf(" %49[^\n]", vendors[*vendorCount].serviceType);

    // Take Phone Number
    printf("Enter Phone Number: ");
    scanf(" %19[^\n]", vendors[*vendorCount].phone);

    // Take Email
    printf("Enter Email: ");
    scanf(" %49[^\n]", vendors[*vendorCount].email);

    // Take Service Price
    printf("Enter Service Price: ");
    scanf("%f", &vendors[*vendorCount].servicePrice);
    if (vendors[*vendorCount].servicePrice < 0) {
    printf("\nService price cannot be negative!\n");
    return;
}

    // Increase vendor counter
    (*vendorCount)++;

    // Display success message
    printf("\nVendor Added Successfully!\n");
}

// Function to display all vendors
void displayVendors(struct Vendor vendors[], int vendorCount)
{
    // Check whether any vendor records exist
    if (vendorCount == 0)
    {
        printf("\nNo Vendor Records Found!\n");
        return;
    }

    // Display all vendor records
    for (int i = 0; i < vendorCount; i++)
    {
        printf("\nVendor ID: %d", vendors[i].vendorID);
        printf("\nVendor Name: %s", vendors[i].vendorName);
        printf("\nService Type: %s", vendors[i].serviceType);
        printf("\nPhone Number: %s", vendors[i].phone);
        printf("\nEmail: %s", vendors[i].email);
        printf("\nService Price: %.2f\n", vendors[i].servicePrice);
    }
}

// Function to search for a vendor by ID
void searchVendor(struct Vendor vendors[], int vendorCount)
{
    int id;
    int found = 0;

    // Ask the user for Vendor ID
    printf("\nEnter Vendor ID to Search: ");
    scanf("%d", &id);

    // Search through all vendor records
    for (int i = 0; i < vendorCount; i++)
    {
        if (vendors[i].vendorID == id)
        {
            // Display the matching vendor
            printf("\nVendor Found!");
            printf("\nVendor ID: %d", vendors[i].vendorID);
            printf("\nVendor Name: %s", vendors[i].vendorName);
            printf("\nService Type: %s", vendors[i].serviceType);
            printf("\nPhone Number: %s", vendors[i].phone);
            printf("\nEmail: %s", vendors[i].email);
            printf("\nService Price: %.2f\n", vendors[i].servicePrice);

            found = 1;
            break;
        }
    }

    // Display message if vendor was not found
    if (found == 0)
    {
        printf("\nVendor Not Found!\n");
    }
}

// Function to update vendor information
void updateVendor(struct Vendor vendors[], int vendorCount)
{
    int id;
    int found = 0;

    // Ask for Vendor ID
    printf("\nEnter Vendor ID to Update: ");
    scanf("%d", &id);

    // Search for the vendor
    for (int i = 0; i < vendorCount; i++)
    {
        if (vendors[i].vendorID == id)
        {
            // Take updated vendor information
            printf("\nEnter New Vendor Name: ");
            scanf(" %49[^\n]", vendors[i].vendorName);

            printf("Enter New Service Type: ");
            scanf(" %49[^\n]", vendors[i].serviceType);

            printf("Enter New Phone Number: ");
            scanf(" %19[^\n]", vendors[i].phone);

            printf("Enter New Email: ");
            scanf(" %49[^\n]", vendors[i].email);

            printf("Enter New Service Price: ");
            scanf("%f", &vendors[i].servicePrice);

            // Display success message
            printf("\nVendor Updated Successfully!\n");

            found = 1;
            break;
        }
    }

    // Check whether vendor was found
    if (found == 0)
    {
        printf("\nVendor Not Found!\n");
    }
}

// Function to delete a vendor
void deleteVendor(struct Vendor vendors[], int *vendorCount)
{
    int id;
    int found = 0;

    // Ask for Vendor ID
    printf("\nEnter Vendor ID to Delete: ");
    scanf("%d", &id);

    // Search for the vendor
    for (int i = 0; i < *vendorCount; i++)
    {
        if (vendors[i].vendorID == id)
        {
            // Shift remaining records one position to the left
            for (int j = i; j < *vendorCount - 1; j++)
            {
                vendors[j] = vendors[j + 1];
            }

            // Decrease vendor counter
            (*vendorCount)--;

            printf("\nVendor Deleted Successfully!\n");

            found = 1;
            break;
        }
    }

    // Check whether vendor was found
    if (found == 0)
    {
        printf("\nVendor Not Found!\n");
    }
}

        // DOMAIN NO :6

// Function to add a new payment
void addPayment(struct Payment payments[], int *paymentCount)
{
    if (*paymentCount >= 100) {
    printf("\nMaximum payment limit reached!\n");
    return;
}
    int newID;

    printf("\nEnter Payment ID: ");
    scanf("%d", &newID);

    // Check for duplicate Payment ID
    for (int i = 0; i < *paymentCount; i++) {
        if (payments[i].paymentID == newID) {
            printf("\nThis Payment ID already exists!\n");
            return;
        }
    }

    payments[*paymentCount].paymentID = newID;
    
    // Take Event ID
    printf("Enter Event ID: ");
    scanf("%d", &payments[*paymentCount].eventID);

    // Take Client ID
    printf("Enter Client ID: ");
    scanf("%d", &payments[*paymentCount].clientID);

    // Take Total Amount
    printf("Enter Total Amount: ");
    scanf("%f", &payments[*paymentCount].totalAmount);
    if (payments[*paymentCount].totalAmount < 0) {
    printf("\nTotal amount cannot be negative!\n");
    return;
}

    // Take Paid Amount
    printf("Enter Paid Amount: ");
    scanf("%f", &payments[*paymentCount].paidAmount);

if (payments[*paymentCount].paidAmount < 0 ||
    payments[*paymentCount].paidAmount > payments[*paymentCount].totalAmount) {
    printf("\nInvalid paid amount!\n");
    return;
}

    // Take Payment Date
    printf("Enter Payment Date: ");
    scanf(" %19[^\n]", payments[*paymentCount].paymentDate);

    // Take Payment Status
    printf("Enter Payment Status: ");
    scanf(" %19[^\n]", payments[*paymentCount].paymentStatus);

    // Increase payment counter
    (*paymentCount)++;

    // Display success message
    printf("\nPayment Added Successfully!\n");
}

// Function to display all payment records
void displayPayments(struct Payment payments[], int paymentCount)
{
    // Check whether payment records exist
    if (paymentCount == 0)
    {
        printf("\nNo Payment Records Found!\n");
        return;
    }

    // Display all payment records
    for (int i = 0; i < paymentCount; i++)
    {
        printf("\nPayment ID: %d", payments[i].paymentID);
        printf("\nEvent ID: %d", payments[i].eventID);
        printf("\nClient ID: %d", payments[i].clientID);
        printf("\nTotal Amount: %.2f", payments[i].totalAmount);
        printf("\nPaid Amount: %.2f", payments[i].paidAmount);
        printf("\nPayment Date: %s", payments[i].paymentDate);
        printf("\nPayment Status: %s\n", payments[i].paymentStatus);
    }
}

// Function to search for a payment by ID
void searchPayment(struct Payment payments[], int paymentCount)
{
    int id;
    int found = 0;

    // Ask the user for Payment ID
    printf("\nEnter Payment ID to Search: ");
    scanf("%d", &id);

    // Search through all payment records
    for (int i = 0; i < paymentCount; i++)
    {
        if (payments[i].paymentID == id)
        {
            // Display the matching payment
            printf("\nPayment Found!");
            printf("\nPayment ID: %d", payments[i].paymentID);
            printf("\nEvent ID: %d", payments[i].eventID);
            printf("\nClient ID: %d", payments[i].clientID);
            printf("\nTotal Amount: %.2f", payments[i].totalAmount);
            printf("\nPaid Amount: %.2f", payments[i].paidAmount);
            printf("\nPayment Date: %s", payments[i].paymentDate);
            printf("\nPayment Status: %s\n", payments[i].paymentStatus);

            found = 1;
            break;
        }
    }

    // Display message if payment was not found
    if (found == 0)
    {
        printf("\nPayment Not Found!\n");
    }
}

// Function to update payment information
void updatePayment(struct Payment payments[], int paymentCount)
{
    int id;
    int found = 0;

    // Ask for Payment ID
    printf("\nEnter Payment ID to Update: ");
    scanf("%d", &id);

    // Search for the payment
    for (int i = 0; i < paymentCount; i++)
    {
        if (payments[i].paymentID == id)
        {
            // Take updated payment information
            printf("\nEnter New Event ID: ");
            scanf("%d", &payments[i].eventID);

            printf("Enter New Client ID: ");
            scanf("%d", &payments[i].clientID);

            printf("Enter New Total Amount: ");
            scanf("%f", &payments[i].totalAmount);

            printf("Enter New Paid Amount: ");
            scanf("%f", &payments[i].paidAmount);

            printf("Enter New Payment Date: ");
            scanf(" %19[^\n]", payments[i].paymentDate);

            printf("Enter New Payment Status: ");
            scanf(" %19[^\n]", payments[i].paymentStatus);

            // Display success message
            printf("\nPayment Updated Successfully!\n");

            found = 1;
            break;
        }
    }

    // Check whether payment was found
    if (found == 0)
    {
        printf("\nPayment Not Found!\n");
    }
}

// Function to delete a payment
void deletePayment(struct Payment payments[], int *paymentCount)
{
    int id;
    int found = 0;

    // Ask for Payment ID
    printf("\nEnter Payment ID to Delete: ");
    scanf("%d", &id);

    // Search for the payment
    for (int i = 0; i < *paymentCount; i++)
    {
        if (payments[i].paymentID == id)
        {
            // Shift remaining records one position to the left
            for (int j = i; j < *paymentCount - 1; j++)
            {
                payments[j] = payments[j + 1];
            }

            // Decrease payment counter
            (*paymentCount)--;

            printf("\nPayment Deleted Successfully!\n");

            found = 1;
            break;
        }
    }

    // Check whether payment was found
    if (found == 0)
    {
        printf("\nPayment Not Found!\n");
    }
}
        // file handling 
 // Function to save event records in a file
void saveEvents(struct Event events[], int count)
{
    // Open file in binary write mode
    FILE *file = fopen("events.dat", "wb");

    // Check whether file opened successfully
    if (file == NULL)
    {
        printf("\nError saving events!\n");
        return;
    }

    // Save the total number of events
    fwrite(&count, sizeof(int), 1, file);

    // Save all event records
    fwrite(events, sizeof(struct Event), count, file);

    // Close the file
    fclose(file);

    printf("\nEvents Saved Successfully!\n");
}

// Function to load event records from a file
void loadEvents(struct Event events[], int *count)
{
    // Open file in binary read mode
    FILE *file = fopen("events.dat", "rb");

    // Check whether file exists
    if (file == NULL)
    {
        printf("\nNo previous event records found.\n");
        return;
    }

    // Load the total number of events
    fread(count, sizeof(int), 1, file);
    if (*count < 0 || *count > 100) {
    printf("\nInvalid event file data!\n");
    *count = 0;
    fclose(file);
    return;
}

    // Load all event records
    fread(events, sizeof(struct Event), *count, file);

    // Close the file
    fclose(file);

    printf("\nEvents Loaded Successfully!\n");
}

// Function to save client records in a file
void saveClients(struct Client clients[], int count)
{
    // Open file in binary write mode
    FILE *file = fopen("clients.dat", "wb");

    // Check whether file opened successfully
    if (file == NULL)
    {
        printf("\nError saving clients!\n");
        return;
    }

    // Save the total number of clients
    fwrite(&count, sizeof(int), 1, file);

    // Save all client records
    fwrite(clients, sizeof(struct Client), count, file);

    // Close the file
    fclose(file);

    printf("\nClients Saved Successfully!\n");
}

// Function to load client records
void loadClients(struct Client clients[], int *count)
{
    FILE *file = fopen("clients.dat", "rb");

    if (file == NULL)
    {
        printf("\nNo previous client records found.\n");
        return;
    }

    // Load client count
    fread(count, sizeof(int), 1, file);
    if (*count < 0 || *count > 100) {
    printf("\nInvalid client file data!\n");
    *count = 0;
    fclose(file);
    return;
}

    // Load all client records
    fread(clients, sizeof(struct Client), *count, file);

    fclose(file);

    printf("\nClients Loaded Successfully!\n");
}

// Function to save inventory records
void saveInventory(struct Inventory inventory[], int count)
{
    FILE *file = fopen("inventory.dat", "wb");

    if (file == NULL)
    {
        printf("\nError saving inventory!\n");
        return;
    }

    // Save inventory count
    fwrite(&count, sizeof(int), 1, file);

    // Save all inventory records
    fwrite(inventory, sizeof(struct Inventory), count, file);

    fclose(file);

    printf("\nInventory Saved Successfully!\n");
}

// Function to load inventory records
void loadInventory(struct Inventory inventory[], int *count)
{
    FILE *file = fopen("inventory.dat", "rb");

    if (file == NULL)
    {
        printf("\nNo previous inventory records found.\n");
        return;
    }

    // Load inventory count
    fread(count, sizeof(int), 1, file);
    if (*count < 0 || *count > 100) {
    printf("\nInvalid inventory file data!\n");
    *count = 0;
    fclose(file);
    return;
}

    // Load all inventory records
    fread(inventory, sizeof(struct Inventory), *count, file);

    fclose(file);

    printf("\nInventory Loaded Successfully!\n");
}

// Function to save venue records
void saveVenues(struct Venue venues[], int count)
{
    FILE *file = fopen("venues.dat", "wb");

    if (file == NULL)
    {
        printf("\nError saving venues!\n");
        return;
    }

    // Save venue count
    fwrite(&count, sizeof(int), 1, file);

    // Save all venue records
    fwrite(venues, sizeof(struct Venue), count, file);

    fclose(file);

    printf("\nVenues Saved Successfully!\n");
}

// Function to load venue records
void loadVenues(struct Venue venues[], int *count)
{
    FILE *file = fopen("venues.dat", "rb");

    if (file == NULL)
    {
        printf("\nNo previous venue records found.\n");
        return;
    }

    // Load venue count
    fread(count, sizeof(int), 1, file);
    if (*count < 0 || *count > 100) {
    printf("\nInvalid venue file data!\n");
    *count = 0;
    fclose(file);
    return;
}

    // Load all venue records
    fread(venues, sizeof(struct Venue), *count, file);

    fclose(file);

    printf("\nVenues Loaded Successfully!\n");
}

// Function to save vendor records
void saveVendors(struct Vendor vendors[], int count)
{
    FILE *file = fopen("vendors.dat", "wb");

    if (file == NULL)
    {
        printf("\nError saving vendors!\n");
        return;
    }

    // Save vendor count
    fwrite(&count, sizeof(int), 1, file);

    // Save all vendor records
    fwrite(vendors, sizeof(struct Vendor), count, file);

    fclose(file);

    printf("\nVendors Saved Successfully!\n");
}

// Function to load vendor records
void loadVendors(struct Vendor vendors[], int *count)
{
    FILE *file = fopen("vendors.dat", "rb");

    if (file == NULL)
    {
        printf("\nNo previous vendor records found.\n");
        return;
    }

    // Load vendor count
    fread(count, sizeof(int), 1, file);
    if (*count < 0 || *count > 100) {
    printf("\nInvalid vendor file data!\n");
    *count = 0;
    fclose(file);
    return;
}

    // Load all vendor records
    fread(vendors, sizeof(struct Vendor), *count, file);

    fclose(file);

    printf("\nVendors Loaded Successfully!\n");
}

// Function to save payment records
void savePayments(struct Payment payments[], int count)
{
    FILE *file = fopen("payments.dat", "wb");

    if (file == NULL)
    {
        printf("\nError saving payments!\n");
        return;
    }

    // Save payment count
    fwrite(&count, sizeof(int), 1, file);

    // Save all payment records
    fwrite(payments, sizeof(struct Payment), count, file);

    fclose(file);

    printf("\nPayments Saved Successfully!\n");
}

// Function to load payment records
void loadPayments(struct Payment payments[], int *count)
{
    FILE *file = fopen("payments.dat", "rb");

    if (file == NULL)
    {
        printf("\nNo previous payment records found.\n");
        return;
    }

    // Load payment count
    fread(count, sizeof(int), 1, file);
    if (*count < 0 || *count > 100) {
    printf("\nInvalid payment file data!\n");
    *count = 0;
    fclose(file);
    return;
}

    // Load all payment records
    fread(payments, sizeof(struct Payment), *count, file);

    fclose(file);

    printf("\nPayments Loaded Successfully!\n");
}

    
int main() {

    // Array to store maximum 100 events
    struct Event events[100];
    // Initially, no events are stored
    int count = 0;
    struct Client clients[100];
    int clientCount = 0;
    struct Inventory inventory[100];
    int inventoryCount = 0;
    struct Venue venues[100];
    int venueCount = 0;
    struct Vendor vendors[100];
    int vendorCount = 0;
    struct Payment payments[100];
    int paymentCount = 0;

    // Load all previously saved records
    loadEvents(events, &count);
    loadClients(clients, &clientCount);
    loadInventory(inventory, &inventoryCount);
    loadVenues(venues, &venueCount);
    loadVendors(vendors, &vendorCount);
    loadPayments(payments, &paymentCount);

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
        printf("\n--- INVENTORY MANAGEMENT ---\n");
        printf("11. Add Inventory Item\n");
        printf("12. Display All Inventory Items\n");
        printf("13. Search Inventory Item\n");
        printf("14. Update Inventory Item\n");
        printf("15. Delete Inventory Item\n");
        // Venue Management options
        printf("\n--- VENUE MANAGEMENT ---\n");
        printf("16. Add Venue\n");
        printf("17. Display All Venues\n");
        printf("18. Search Venue\n");
        printf("19. Update Venue\n");
        printf("20. Delete Venue\n");
        // Vendor Management Menu
        printf("\n--- VENDOR MANAGEMENT ---\n");
        printf("21. Add Vendor\n");
        printf("22. Display Vendors\n");
        printf("23. Search Vendor\n");
        printf("24. Update Vendor\n");
        printf("25. Delete Vendor\n");
        // Payment Management Menu
        printf("\n--- PAYMENT MANAGEMENT ---\n");
        printf("\n26. Add Payment");
        printf("\n27. Display Payments");
        printf("\n28. Search Payment");
        printf("\n29. Update Payment");
        printf("\n30. Delete Payment");
        //exit
        printf("\n31. Exit\n");

        
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

            case 11:
                addInventory(inventory, &inventoryCount);
                break;

            case 12:
                displayInventory(inventory, inventoryCount);
                break;

            case 13:
                searchInventory(inventory, inventoryCount);
                break;

            case 14:
                updateInventory(inventory, inventoryCount);
                break;

            case 15:
                deleteInventory(inventory, &inventoryCount);
                break;

            // Venue Management

            case 16:
                addVenue(venues, &venueCount);
                break;

            case 17:
                displayVenues(venues, venueCount);
                break;

            case 18:
                searchVenue(venues, venueCount);
                break;

            case 19:
                updateVenue(venues, venueCount);
                break;

            case 20:
                deleteVenue(venues, &venueCount);
                break;

            case 21:
                addVendor(vendors, &vendorCount);
                break;

            case 22:
                displayVendors(vendors, vendorCount);
                break;

            case 23:
                searchVendor(vendors, vendorCount);
                break;

            case 24:
                updateVendor(vendors, vendorCount);
                break;

            case 25:
                deleteVendor(vendors, &vendorCount);
                break;

            case 26:
                addPayment(payments, &paymentCount);
                break;

            case 27:
                displayPayments(payments, paymentCount);
                break;

            case 28:
                searchPayment(payments, paymentCount);
                break;

            case 29:
                updatePayment(payments, paymentCount);
                break;

            case 30:
                deletePayment(payments, &paymentCount);
                break;


            case 31:
                saveEvents(events, count);
                saveClients(clients, clientCount);
                saveInventory(inventory, inventoryCount);
                saveVenues(venues, venueCount);
                saveVendors(vendors, vendorCount);
                savePayments(payments, paymentCount);
                printf("\nThank you for using our system!\n");
                return 0; 
                
                
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


    



    