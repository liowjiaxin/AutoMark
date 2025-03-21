#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to define grocery item
struct groceryItem {
    char name[100];  // Name of the item 
    char category[50];  // Category of the item
    int quantity;  // Quantity of the item 
    float price;  // Price of the item 
};

// Structure to track availability status of an item 
struct availabilityStatus {
    int inStock;  // 1 for in stock, 0 for out of stock (boolean)
};

// Structure to manage grocery inventory 
struct groceryInventory {
    struct groceryItem items[100];  // Array of grocery items 
    struct availabilityStatus status[100];  // Corresponding availability status 
    int count;  // Number of items in the inventory 
};

// Function prototypes
struct groceryInventory addGroceryItem(struct groceryInventory inventory);
void listGroceryItems(struct groceryInventory inventory);
struct groceryInventory updateQuantity(struct groceryInventory inventory);
struct groceryInventory removeGroceryItem(struct groceryInventory inventory);

int main(void) {
    struct groceryInventory inventory;
    inventory.count = 0; // Initialize inventory
    int choice;

    while (1) {
        // Display menu 
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Check if user enter valid input 
        if (scanf("%d", &choice) == 1) {
            switch (choice) {
                case 1:
                    inventory = addGroceryItem(inventory);
                    break;
                case 2:
                    listGroceryItems(inventory);
                    break;
                case 3:
                    inventory = updateQuantity(inventory);
                    break;
                case 4:
                    inventory = removeGroceryItem(inventory);
                    break;
                case 5:
                    printf("Exiting Program...\n");
                    return 0;
                default:
                    printf("Please enter a valid choice.\n");
                    continue;
            }
        } else {
            printf("Error: Please enter a valid choice.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
    }
}

// Function to add grocery item 
struct groceryInventory addGroceryItem(struct groceryInventory inventory) {
    if (inventory.count >= 100) {  // Check if inventory is full 
        printf("Inventory is full!\n");
        return inventory;
    }
    printf("Enter Item Name: ");
    scanf(" %99[^\n]", inventory.items[inventory.count].name); // Read item name until newline
    printf("Enter Category: ");
    scanf(" %49[^\n]", inventory.items[inventory.count].category); // Read category until newline
    printf("Enter Quantity: ");
    scanf("%d", &inventory.items[inventory.count].quantity);  // Read quantity
    printf("Enter Price: ");
    scanf("%f", &inventory.items[inventory.count].price);  // Read price 

    if (inventory.items[inventory.count].quantity > 0){
        inventory.status[inventory.count].inStock = 1;  // In stock
    }
    else{
        inventory.status[inventory.count].inStock = 0;  // Out of stock 
    }

    inventory.count++;  // increment item count 
    printf("Grocery item added successfully!\n");

    return inventory;
}

// Function to list all grocery items in inventory 
void listGroceryItems(struct groceryInventory inventory) {
    if (inventory.count == 0) {  // If inventory is empty
        printf("No grocery items in the inventory.\n");
    } else {
        // List all the items in inventory 
        for (int i = 0; i < inventory.count; i++) {
            printf("\nName: %s\n", inventory.items[i].name);
            printf("Category: %s\n", inventory.items[i].category);
            printf("Quantity: %d\n", inventory.items[i].quantity);
            printf("Price: %.2f\n", inventory.items[i].price);
            if (inventory.status[i].inStock == 1){
                printf("Status: In Stock\n");
            }
            else{
                printf("Status: Out of Stock\n");
            }
        }
    }
}

// Function to update quantity of grocery item 
struct groceryInventory updateQuantity(struct groceryInventory inventory) {
    char name[100];  // Item name to search for
    int newQuantity;  // New quantity to set

    printf("Enter the name of the grocery item to update quantity: ");
    scanf(" %99[^\n]", name);

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, name) == 0) {  // Compare and match item name 
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);  // Update new quantity 

            // Update availability status 
            inventory.items[i].quantity = newQuantity;
            if (newQuantity > 0){
                inventory.status[i].inStock = 1;
            }
            else{
                inventory.status[i].inStock = 0;
            }

            printf("Quantity updated successfully!\n");
            return inventory;
        }
    }

    printf("Item not found.\n");  // If item not searched 
    return inventory;
}

// Function to remove grocery item 
struct groceryInventory removeGroceryItem(struct groceryInventory inventory) {
    char name[100];

    printf("Enter the name of the item to remove: ");
    scanf(" %99[^\n]", name);

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, name) == 0) {  // Compare and match item name
            // Shift item to delete item selected 
            for (int j = i; j < inventory.count - 1; j++) {
                inventory.items[j] = inventory.items[j + 1];
                inventory.status[j] = inventory.status[j + 1];
            }
            inventory.count--;  // Decrement item count 
            printf("Grocery item '%s' removed successfully!\n", inventory.items);
            return inventory;
        }
    }

    printf("Item not found.\n");  // If item not searched 
    return inventory;
}
