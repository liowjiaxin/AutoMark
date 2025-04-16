#include <stdio.h> 
#include <string.h>  

#define MAX_ITEMS 100  // Define maximum number of items in the inventory
#define MAX_NAME_LENGTH 100  // Define maximum length for the grocery item name
#define MAX_CATEGORY_LENGTH 50  // Define maximum length for the grocery item category

// Function prototypes 
void listItems();
void addItem();
void updateItemQuantity();
void removeItem();
void showMenu();

// Structure to define a grocery item
typedef struct {
    char itemName[MAX_NAME_LENGTH];  
    char itemCategory[MAX_CATEGORY_LENGTH];  
    int itemQuantity;  
    float itemPrice;  
    char itemStatus[20];  // Item status (either "In Stock" or "Out of Stock")
} DataForGrocery;  

//array and counter to store grocery items
DataForGrocery groceryList[MAX_ITEMS]; 
int groceryCount = 0;    // Tracking the number of items in the list. 

// Function to add a grocery item to the inventory
void addItem() {
    if (groceryCount >= MAX_ITEMS) {  // To check if the number of items in the list exceed the max amount or not 
        printf("Inventory is full! Cannot add more items.\n");
        return;  
    }
 
 // Ask for user inputs
    DataForGrocery newGrocery;  // Declare a new grocery item variable
    printf("Enter Item Name: "); 
    scanf(" %[^\n]", newGrocery.itemName);  

    printf("Enter Category: ");  
    scanf(" %[^\n]", newGrocery.itemCategory);  // Read item category 

    printf("Enter Quantity: ");  
    scanf("%d", &newGrocery.itemQuantity); 

    printf("Enter Price: ");  
    scanf("%f", &newGrocery.itemPrice);  

    // Set the item status based on the quantity
    if (newGrocery.itemQuantity > 0) {
        strcpy(newGrocery.itemStatus, "In Stock");  // If quantity is greater than 0, set status as "In Stock"
    } else {
        strcpy(newGrocery.itemStatus, "Out of Stock");  // Otherwise it is "Out of Stock"
    }

    groceryList[groceryCount++] = newGrocery;  // Add the new item to the inventory and increment item count
    printf("Grocery item added successfully!\n"); 
}

// Function to list all grocery items in the inventory
void listItems() {
    if (groceryCount == 0) {  // Check if the inventory is empty
        printf("Inventory is empty.\n");  
        return;  
    }

    // Loop through the inventory and display details of each item
    for (int i = 0; i < groceryCount; i++) {
        printf("Name: %s\n", groceryList[i].itemName);  
        printf("Category: %s\n", groceryList[i].itemCategory); 
        printf("Quantity: %d\n", groceryList[i].itemQuantity);  
        printf("Price: %.2f\n", groceryList[i].itemPrice);  
        printf("Status: %s\n", groceryList[i].itemStatus); 
        printf("---------------------------\n");  
    }
}

// Function to update the quantity of a specific grocery item
void updateItemQuantity() {
    if (groceryCount == 0) {  // Check if the inventory is empty
        printf("Inventory is empty.\n");  
        return;  
    }

    char searchName[MAX_NAME_LENGTH];  
    printf("Enter name of the grocery item to update quantity: ");  // Prompt user to enter item name
    scanf(" %[^\n]", searchName);

    // Loop through the inventory to find the item
    for (int i = 0; i < groceryCount; i++) {
        if (strcmp(groceryList[i].itemName, searchName) == 0) {  // Compare input name with item names in inventory
            printf("Enter new quantity for %s: ", searchName); 
            scanf("%d", &groceryList[i].itemQuantity);  

            // Update the item status based on the new quantity
            if (groceryList[i].itemQuantity > 0) {
                strcpy(groceryList[i].itemStatus, "In Stock");  
            } else {
                strcpy(groceryList[i].itemStatus, "Out of Stock"); 
            }

            printf("Quantity updated successfully!\n");  // Display success message
            return;  
        }
    }

    printf("Item not found in the inventory.\n");  // Display message if item not found
}

// Function to remove a grocery item from the inventory
void removeItem() {
    if (groceryCount == 0) {  
        printf("Inventory is empty.\n");  // Display message if inventory is empty
        return; 
    }

    char searchName[MAX_NAME_LENGTH];  // Declare a variable to hold the item name to remove
    printf("Enter name of the grocery item to remove: "); 
    scanf(" %[^\n]", searchName); 

    // Loop through the inventory to find the item
    for (int i = 0; i < groceryCount; i++) {
        if (strcmp(groceryList[i].itemName, searchName) == 0) {  
            // Shift all items after the found item one position back to remove it
            for (int j = i; j < groceryCount - 1; j++) {
                groceryList[j] = groceryList[j + 1];  // Shift items
            }
            groceryCount--;  // Decrement item count
            printf("Grocery item removed successfully!\n"); 
            return;  
        }
    }

    printf("Item not found in the inventory.\n");  // Display message if item not found
}

// Main menu function
void showMenu() {
    int userInput;  
    do {
        // Display the menu options
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: "); 
        scanf("%d", &userInput);  

        // Use switch case to choose between the different operations or functions
        switch (userInput) {
            case 1:
                addItem();  // Call function to add item
                break;
            case 2:
                listItems();  // Call function to list items
                break;
            case 3:
                updateItemQuantity();  // Call function to update quantity
                break;
            case 4:
                removeItem();  // Call function to remove item
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");  
                break;
            default:
                printf("Invalid choice! Please try again.\n");  // Display error message for invalid input
        }
    } while (userInput != 5);  
}

int main() {
    showMenu();  // Call function to display the menu
    return 0;  
}
