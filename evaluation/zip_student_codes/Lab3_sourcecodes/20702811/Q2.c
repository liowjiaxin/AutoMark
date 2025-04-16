#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100  // Define the maximum number of items able to be input into the list

// Define variables in the struct data type to call upon anytime within the code
struct Grocery {
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool availability;
};

// Create a void function to code on adding grocery items into the grocery list
void addGroceryItems(struct Grocery Grocer_Item[], int *list_count) {
    // Prints out an error/following message if the number of grocery items in the list is more than the required max amount
    if (*list_count >= MAX_ITEMS) {
        printf("List is full. Cannot add more items.\n");
        return;
    }

    struct Grocery item; // calls the struct data type
    getchar();           // Clear the buffer before reading strings

    printf("Enter Item Name: ");                             // Prompts user to input the item name
    fgets(item.name, sizeof(item.name), stdin);              // Stores the string into the item.name variable
    item.name[strcspn(item.name, "\n")] = 0;                 // Remove trailing newline

    printf("Enter Category: ");                              // Prompts user to input the item category
    fgets(item.category, sizeof(item.category), stdin);      // Stores the string into the item.category variable
    item.category[strcspn(item.category, "\n")] = 0;         // Remove trailing newline

    printf("Enter Quantity: ");                              // Prompts user to input the item quantity
    scanf("%d", &item.quantity);                             // Stores the string into the item.quantity variable

    printf("Enter Price: ");                                 // Prompts user to input the item price
    scanf("%f", &item.price);                                // Stores the string into the item.price variable

    Grocer_Item[*list_count] = item;   // Code assigns the struct type of Grocery (item) to the array Grocer_Item at the position *list_count
    (*list_count)++;                   // increments the grocery count by 1 after every grocery name is input

    printf("Grocery item added successfully!\n");
}

// Create a void function to code the grocery list to output
void listGroceryItems(struct Grocery *item, int list_count) {
    // If no grocery items are in the list, system outputs the following message
    if (list_count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("Grocery List\n");
    // Prints every stored value in the i arrays
    for (int i = 0; i < list_count; i++) {
        printf("\nItem %d:\n", i + 1);                  // Prints the current item number on the list, up to down 1 - 100
        printf("Name: %s\n", item[i].name);             // Prints the name of item stored in the current i array
        printf("Category: %s\n", item[i].category);     // Prints the category of stored item in the current i array
        printf("Quantity: %d\n", item[i].quantity);     // Prints the quantity of stored item in the current i array
        printf("Price: $%.2f\n", item[i].price);        // Prints the price of stored item in the current i array

        // Create an if else statement on whether the quantity of items is either 0 or not 0.
        if(item[i].quantity > 0) {
            item[i].availability = true;
        } else {
            item[i].availability = false;
        }
                    
        if(item[i].availability) {
            printf("Status: In Stock\n");               // Prints "In Stock" if quantity > 0
        } else {
            printf("Status: Out of Stock\n");           // Prints "Out of Stock" if quantity == 0
        }
    }
}

// Create a void function to update the quantity of an item in the grocery list
void updateQuantity(struct Grocery *item, int list_count) {
    char tempSearch[100]; // new define char to hold the temporary string input from user to compare with the grocery items saved in the grocery list
    int tempQ;
    int index = -1;
    // If there is no items in the grocery list, print the following message
    if (list_count == 0) {
        printf("No grocery list to update quantity.\n");
        return;
    }

    getchar();              // Clear the buffer before reading strings                 

    printf("Enter name of the grocery item to update quantity: ");      // Prompt user to input the name of grocery item to change quantity of
    fgets(tempSearch, sizeof(tempSearch), stdin);                       // Store value into the temporary variable tempSearch
    tempSearch[strcspn(tempSearch, "\n")] = 0;

    printf("Enter new quantity for %s: ", tempSearch);                  // Prompt user to enter the new quantity for the following grocery item
    scanf("%d", &tempQ);                                                // Store value into the temporary variable tempQ

    // For loop is used to search and compare the item name from user input with what is saved into the list
    for (int i = 0; i < list_count; i++) {
        if (strcmp(item[i].name, tempSearch) == 0) {
            index = i;                                  // If the name is found, index will equal to the following i value on where it was found
            break;
        }
    }

    if (index != -1) { // Since index = -1 is what we used to flag the original index value, and since it's not possible for i to be -1, if index = -1 or it has changed, that means the name has been found
        item[index].quantity = tempQ;
        printf("Quantity uploaded successfully!\n");    // If found print this message
    } else {
        printf("Grocery item does not exist in the list.\n");   // If not print this message
    }

}

// Create a void function to remove any grocery items from the grocery list
void removeGroceryItems(struct Grocery *item, int *list_count) {
    char delname[100];   // Holds part of the name of the grocery item to delete
    int found = -1;      // Flag to track if a matching grocery item is found

    getchar(); // Clear the buffer before reading strings
    
    printf("Enter name of the grocery item to remove: ");       // Prompts user to input the name of grocery item to remove
    fgets(delname, sizeof(delname), stdin);                     // Stores the value into the variable delname
    delname[strcspn(delname, "\n")] = '\0';                     // Remove newline from input

    // For loop is used to search and compare the item name from user input with what is saved into the list
    for (int i = 0; i < *list_count; i++) {
        if (strcmp(item[i].name, delname) == 0) {
            found = i;                                          // If the name is found, found will equal to the following i value on where it was found
            break;
        }
    }

    if (found != -1) {  // Since found = -1 is what we used to flag the original index value, and since it's not possible for i to be -1, if found = -1 or it has changed, that means the name has been found
        printf("Grocery item '%s' removed successfully!\n", item[found].name);
        // Shift remaining grocery items to fill the gap
        for (int j = found; j < *list_count - 1; j++) {
            item[j] = item[j + 1];
        }

        (*list_count)--; // Decrease the total grocery item count
    } else {
        printf("The grocery you're looking for is not in the list.\n");
    }
}

int main() {
    // define the variables to use in the main function of the code
    int choice;
    int list_count = 0;
    struct Grocery list[MAX_ITEMS];
    do { // Create a do loop to print out the management system menu and prompt the user to input their choice
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);   // system receives the input from user and stores into choice which is used for the following switch case loop

        switch(choice) {
            case 1: // Add Grocery Item
                addGroceryItems(list, &list_count); // Calls the void funtion to add a grocery item
                break;  // breaks from the switch case before repeating with the do while loop
            case 2: // List All Grocery Items
                listGroceryItems(list, list_count); // Calls the void function to print the grocery items in the grocery list
                break;  // breaks from the switch case before repeating with the do while loop
            case 3: // Update Quantity
                updateQuantity(list, list_count);   // Calls the void funtion to update the quantity of a chosen qrocery item
                break;  // breaks from the switch case before repeating with the do while loop
            case 4: // Remove Quantity Item
                removeGroceryItems(list, &list_count);  // Calls the void function to remove an item from the quantity list
                break;  // breaks from the switch case before repeating with the do while loop
            case 5: // Exit
                printf("Exiting...\n");     // Prints the following message before continuing the do while loop
                break;  // breaks from the switch case before repeating with the do while loop
            default:
                printf("Invalid choice. Please try again.\n");  // Prints the following message before continuing the do while loop
                break;  // breaks from the switch case before repeating with the do while loop
        }
    } while (choice != 5); // the do while loop will keep repeating until user inputs the value 5, which then will close not only the do while loop but hence closes the system

    return 0;
}