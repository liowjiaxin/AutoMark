#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];  // The name of the grocery item 
    char category[50];  // The category of the item 
    int quantity;  // How many of this item are in stock
    float price;  // The price per unit of the item
    bool inStock;  // Whether the item is in stock (true = yes, false = no)
} GroceryItem;

GroceryItem inventory[MAX_ITEMS];  // An array to store all grocery items
int itemCount = 0;  

void addItem();  // Function to add a new item to the inventory
void listItems();  // Function to display all items in the inventory
void updateQuantity();  // Function to update the quantity of an existing item
void removeItem();  // Function to remove an item from the inventory

int main() {
    int choice;  

    while (1) { 
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        // Perform the action based on the user's choice
        switch (choice) {
            case 1:
                addItem();  // Call the function to add a new item
                break;
            case 2:
                listItems();  // Call the function to list all items
                break;
            case 3:
                updateQuantity();  // Call the function to update item quantity
                break;
            case 4:
                removeItem();  // Call the function to remove an item
                break;
            case 5:
                printf("Exiting...\n");
                return 0;  // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;  
}

// Function to add a new grocery item
void addItem() {
    if (itemCount >= MAX_ITEMS) {  // Check if there is room in the inventory
        printf("Inventory is full! Cannot add more items.\n");
        return;  // Exit the function if inventory is full
    }

    GroceryItem newItem;  
    
    // Prompt for the item's name
    printf("Enter Item Name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0;  

    // Prompt for the item's category
    printf("Enter Category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    newItem.category[strcspn(newItem.category, "\n")] = 0;  
    
    // Prompt for the quantity of the item
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    // Prompt for the price of the item
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    // Set the availability status based on quantity
    newItem.inStock = newItem.quantity > 0;  // true if quantity > 0, false otherwise

    // Add the new item to the inventory and increment the count
    inventory[itemCount++] = newItem;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items in the inventory
void listItems() {
    if (itemCount == 0) {  // Check if the inventory is empty
        printf("No grocery items in the inventory.\n");
        return;  // Exit the function
    }

    // Loop through the inventory and display each item's details
    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a specific grocery item
void updateQuantity() {
    char itemName[100];  // Variable to store the name of the item to update

    // Prompt for the item's name
    printf("Enter name of the grocery item to update quantity: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0;  
    
    // Search for the item in the inventory
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {  // Check if names match
            // Prompt for the new quantity
            printf("Enter new quantity for %s: ", inventory[i].name);
            scanf("%d", &inventory[i].quantity);

            // Update the availability status
            inventory[i].inStock = inventory[i].quantity > 0;  // true if quantity > 0, false otherwise

            printf("Quantity updated successfully!\n");
            return;  // Exit the function
        }
    }

    // If no match was found
    printf("Grocery item not found in the inventory.\n");
}

// Function to remove an item from the inventory
void removeItem() {
    char itemName[100];  
    
    // Prompt for the item's name
    printf("Enter name of the grocery item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0;  

    // Search for the item in the inventory
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {  // Check if names match
            // Shift all subsequent items one position up to fill the gap
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }

            itemCount--;  // Decrement the count of items in the inventory

            printf("Grocery item '%s' removed successfully!\n", itemName);
            return;  // Exit the function
        }
    }

    // If no match was found
    printf("Grocery item not found in the inventory.\n");
}