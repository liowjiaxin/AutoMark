#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    bool inStock;
    bool outStock;
} AvailabilityStatus;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus availability[MAX_ITEMS];
    int count; // total number of grocery items
} GroceryInventory;

// Function to add grocery item
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full\n");
        return;
    }
    
    GroceryItem addedItem;
    printf("enter the name of the item: ");
    scanf(" %[^\n]", addedItem.name);
    printf("enter the category of the item: ");
    scanf(" %[^\n]", addedItem.category);
    printf("enter the quantity of the item: ");
    scanf("%d", &addedItem.quantity);
    printf("enter the price of the item: ");
    scanf("%f", &addedItem.price);
    
    inventory->items[inventory->count] = addedItem; // add item to the inventory
    
    // Update avvailability status
    inventory->availability[inventory->count].inStock = (addedItem.quantity > 0);
    inventory->availability[inventory->count].outStock = (addedItem.quantity == 0);
    
    inventory->count++; // increment the item in inventory
    
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listGroceryItems (const GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    for(int i = 0; i < inventory->count; i++) {
        const GroceryItem *item = &inventory->items[i];
        const AvailabilityStatus *status = &inventory->availability[i];
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->inStock ? "In Stock" : "Out of stock");
        
    }
}

// Function to update the grocery item 
void updateItem (GroceryInventory *inventory) {
    char itemName[100];
    int match = 0;
    
    if (inventory->count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    printf("Enter the name of the grocery item to update quantity: ");
    scanf(" %[^\n]", itemName); 
    
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            printf("Item found: %s\n", inventory->items[i].name);
            printf("Current quantity: %d\n", inventory->items[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &inventory->items[i].quantity);
            
            // Update availability status
            inventory->availability[i].inStock = (inventory->items[i].quantity > 0);
            printf("Item updated successfully.\n");
            match = 1;
            break;
        }
    }
    
    if (!match) {
        printf("Item not found");
    }
}

// Function to remove item
void removeItem (GroceryInventory *inventory) {
    char itemName[100];
    int match = 0;
    
    if (inventory->count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    printf("Enter the name of the grocery item to remove: ");
    scanf(" %[^\n]", itemName); 
    
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            printf("Item found: %s\n", inventory->items[i].name);
            
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->count--;
            printf("Item removed successfully!\n");
            match = 1;
            break;
        }
    }
    
    if (!match) {
        printf("Item not found");
    }
}

int main()
{
    GroceryInventory inventory = {0};
    int count = 0;
    int choice;
    
    printf("Grocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
        
    switch (choice) {
        case 1:
            addGroceryItem(&inventory);
            break;
        case 2:
            listGroceryItems(&inventory);
            break;
        case 3:
            updateItem(&inventory);
            break;
        case 4:
            removeItem(&inventory);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
