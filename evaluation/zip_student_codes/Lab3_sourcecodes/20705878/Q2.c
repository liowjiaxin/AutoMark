#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100 // Maximum number of grocery items

// Structure for a grocery item
typedef struct {
    char name[100];  // Name of the item
    char category[50];  // Category of the item
    int quantity;  // Quantity of the item
    float price;  // Price of the item
    bool inStock;  // Availability status
} GroceryItem;

// Array to store grocery items and the count of items
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

// Function to add a new grocery item
void addGroceryItem() {
    if (itemCount >= MAX_ITEMS) { // Check if inventory is full
        printf("Error: Inventory is full!\n");
        return;
    }
    
    GroceryItem newItem; // Create a new grocery item
    
    printf("Enter name: ");
    scanf(" %[^\n]", newItem.name); // Read item name
    printf("Enter category: ");
    scanf(" %[^\n]", newItem.category); // Read category
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity); // Read quantity
    printf("Enter price: ");
    scanf("%f", &newItem.price); // Read price
    
    // Set availability status based on quantity
    newItem.inStock = (newItem.quantity > 0);
    
    inventory[itemCount++] = newItem; // Add item to the inventory
    printf("Item added successfully!\n");
}

// Function to list all grocery items
void listGroceryItems() {
    if (itemCount == 0) { // Check if inventory is empty
        printf("No grocery items in the inventory.\n");
        return;
    }
    
    printf("\nGrocery Inventory:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) { // Iterate through all items
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Availability: %s\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
        printf("-------------------------------------------------\n");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity() {
    char name[100];
    int newQuantity;
    
    printf("Enter the name of the item to update: ");
    scanf(" %[^\n]", name); // Read item name
    
    for (int i = 0; i < itemCount; i++) { // Search for the item
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity); // Read new quantity
            
            inventory[i].quantity = newQuantity;
            inventory[i].inStock = (newQuantity > 0); // Update availability
            
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    
    printf("Error: Item not found.\n");
}

// Function to remove a grocery item
void removeGroceryItem() {
    char name[100];
    
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]", name); // Read item name
    
    for (int i = 0; i < itemCount; i++) { // Search for the item
        if (strcmp(inventory[i].name, name) == 0) {
            // Shift remaining items
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--; // Decrement item count
            printf("Item removed successfully!\n");
            return;
        }
    }
    
    printf("Error: Item not found.\n");
}

int main() {
    int choice;
    
    do {
        printf("\nGrocery Inventory Management:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addGroceryItem();
                break;
            case 2:
                listGroceryItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeGroceryItem();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

