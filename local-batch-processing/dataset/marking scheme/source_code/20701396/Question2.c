#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//code runs on cmd

typedef struct { // Structure for grocery products
    char name[100];
    char category[100];
    int quantity;
    float price;
    char available[100];
} grocitem;

void add() { // Function to add items to the inventory
    grocitem *item = malloc(sizeof(grocitem)); // memory allocation for new iterm
    FILE *filepointer = fopen("Inventory.csv", "a+"); // Open the file in mode "append"

    // ask user for input
    printf("Enter the name of the product: ");
    scanf(" %[^\n]s", item->name);
    printf("Enter the category of the item: ");
    scanf(" %[^\n]s", item->category);

    while (1) { // infinite loop handles errors
        printf("Enter the quantity of the item: ");
        scanf(" %d", &item->quantity);

        if (item->quantity < 0) {
            printf("The quantity of an item cannot be negative!");
        } else {
            break;
        }
    }

    printf("Enter the price of the item: RM ");
    scanf(" %f", &item->price);

    
    if (item->quantity > 0) {
        strcpy(item->available, "Item is In Stock");
    } else if (item->quantity == 0) {
        strcpy(item->available, "Item is Out of Stock");
    } //Check if item is in stock by comparing to the quantity available

    // Write item details to the file
    fprintf(filepointer, "%s, %s, %d, %.2f, %s\n", item->name, item->category, item->quantity, item->price, item->available);
    fclose(filepointer); // close file "filepointer"
    free(item); // free memory
}

// Function to display the saved inventory information
void display() {
    FILE *filepointer = fopen("Inventory.csv", "r"); // Open the inventory file in read mode
    char buffer[1024]; // intialising buffer
    int i = 1; // counter
    printf("Name, Category, Quantity, Price(RM), Available\n");

    while (fgets(buffer, sizeof(buffer), filepointer) != NULL) { // Read each buffer of the inventory
        printf("%d. %s\n", i, buffer); // Display each item
        i++;
    }

    fclose(filepointer); // Close the file
}

// Function to update the quantity of an item
void update() {
    FILE *filepointer = fopen("Inventory.csv", "r"); // Open Inventory.csv in read mode
    FILE *temporaryfile = fopen("temporaryfile", "w"); // Create a temporary file for updates
    char search[100], buffer[1024];
    char name[100], category[100], available[100];
    int quantity;
    float price;
    int found = 0; // Flag to track if the item is found

    if (filepointer == NULL || temporaryfile == NULL) { // Error handling for file opening
        printf("Error: Could not open file.\n");
        if (filepointer != NULL) fclose(filepointer);
        if (temporaryfile != NULL) fclose(temporaryfile);
        return;
    }

    getchar(); // Clear the input buffer
    printf("Which product would you like to update: "); // Prompt for product to update
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0; // Remove trailing newbuffer

    while (fgets(buffer, sizeof(buffer), filepointer) != NULL) {
        // Parse the current buffer
        int parsed = sscanf(buffer, "%99[^,],%99[^,],%d,%f,%99[^\n]", name, category, &quantity, &price, available);
        if (parsed != 5) {
            printf("Error traversing buffer: %s", buffer);
            continue; // Skip malformed buffers
        }

        if (strcmp(search, name) == 0) { // Check for a match by name
            found = 1; // Mark as found
            printf("Enter the new quantity: ");
            while (scanf("%d", &quantity) != 1 || quantity < 0) {
                printf("Invalid input. Enter a non-negative quantity: ");
                while (getchar() != '\n'); // Clear invalid input
            }
            while (getchar() != '\n'); // Clear input buffer

            // Update available status
            if (quantity > 0) {
                strcpy(available, "In Stock");
            } else {
                strcpy(available, "Out of Stock");
            }
        }

        // Write to the temporary file
        fprintf(temporaryfile, "%s,%s,%d,%.2f,%s\n", name, category, quantity, price, available);
    }

    // Close files and replace the original file with the updated one
    fclose(filepointer);
    fclose(temporaryfile);

    if (found) {
        // Replace the file with the new updated one
        remove("Inventory.csv");
        rename("temporaryfile", "Inventory.csv");
        printf("Quantity updated.\n");
    } else {
        remove("temporaryfile"); // Remove temp file if no items were found
        printf("Product not found.\n");
    }
}

// Function to delete an item
void delete() {
    FILE *filepointer = fopen("Inventory.csv", "r"); // Open Inventory.csv in read mode
    FILE *temporaryfile = fopen("temporaryfile", "w"); // Create a temporary file for the updated list
    char search[100], buffer[1024];
    char name[100], category[100], available[100];
    int quantity;
    float price;
    int found = 0; // Flag to track if the item is found

    if (filepointer == NULL || temporaryfile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    getchar(); // Clear leftover newbuffer from previous input
    printf("Type product to delete: "); // Prompt for product to delete
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0; // Remove newbuffer

    while (fgets(buffer, sizeof(buffer), filepointer) != NULL) { // Search for the product in the file
        sscanf(buffer, "%99[^,],%99[^,],%d,%f,%s", name, category, &quantity, &price, available);

        if (strcmp(search, name) == 0) { // Check for a match by name
            found = 1; // Mark as found
            printf("Product '%s' deleted successfully.\n", name);
            continue; // Skip writing this buffer to the temporary file
        }

        // Write other buffers to the temporary file
        fprintf(temporaryfile, "%s,%s,%d,%.2f,%s\n", name, category, quantity, price, available);
    }

    fclose(filepointer); // Close files
    fclose(temporaryfile);

    if (found) { // Replace the original file with the updated one
        remove("Inventory.csv");
        rename("temporaryfile", "Inventory.csv");
    } else {
        printf("Product was not found\n");
        remove("temporaryfile"); // Remove temp file if no products were found
    }
}

int main() {
    int choice = 0;
    int loop = 1;

    while (loop) {
        // Display menu options
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n2. List all grocery items\n3. Update Quantity\n4. Remove Grocery Item\n5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice); // Get user choice

        switch (choice) {
            case 1:
                add(); // Function to add a grocery item
                break;

            case 2:
                display(); // Function to display all grocery items
                break;

            case 3:
                update(); // Function to update groc quantities
                break;

            case 4:
                delete(); // Function to remove grocery item
                    break;

            case 5:
                printf("Exiting..."); // Exit message
                loop = 0; // Exit the loop
                break;

            default:
                printf("Error, Enter a valid input\n"); // Error message for invalid input
        }
    }
}