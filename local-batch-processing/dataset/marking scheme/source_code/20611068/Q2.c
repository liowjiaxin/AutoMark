#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define structures for Grocery Item and Availability Status
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Define Grocery Inventory
typedef struct {
    GroceryItem items[100];
    AvailabilityStatus availability[100];
    int count;
} GroceryInventory;


// Function to add a grocery item
void addItem(GroceryInventory *inventory) {
    if (inventory->count < 100) {
        printf("Enter item name: ");
        fgets(inventory->items[inventory->count].name, sizeof(inventory->items[inventory->count].name), stdin);
        inventory->items[inventory->count].name[strcspn(inventory->items[inventory->count].name, "\n")] = 0; //remove trailing newline

        printf("Enter item category: ");
        fgets(inventory->items[inventory->count].category, sizeof(inventory->items[inventory->count].category), stdin);
        inventory->items[inventory->count].category[strcspn(inventory->items[inventory->count].category, "\n")] = 0; //remove trailing newline

        printf("Enter quantity: ");
        scanf("%d", &inventory->items[inventory->count].quantity);
        
        printf("Enter price: ");
        scanf("%f", &inventory->items[inventory->count].price);
        getchar();  //To consume the newline character

        inventory->availability[inventory->count].inStock = (inventory->items[inventory->count].quantity > 0);
        inventory->availability[inventory->count].outOfStock = !inventory->availability[inventory->count].inStock;
        inventory->count++;
        printf("Grocery item added successfully!\n");
    } else {
        printf("Inventory is full!\n");
    }
}

// Function to list all grocery items with their availability 
void listItems(const GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }
    for (int i = 0; i < inventory->count; i++) {
        printf("Item Name: %s\n", inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Status: %s\n", inventory->availability[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update quantity of a grocery item
void updateQuantity(GroceryInventory *inventory) {
    char itemName[100];
    int quantity;
    int index = -1;

    printf("Enter Item Name: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0;  //remove trailing newline

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found!\n");
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &quantity);
    getchar(); // To consume the newline character

    inventory->items[index].quantity = quantity;
    inventory->availability[index].inStock = (quantity > 0);
    inventory->availability[index].outOfStock = !inventory->availability[index].inStock;
    printf("Quantity updated successfully!\n");
}


// Function to remove grocery item 
void removeItem(GroceryInventory *inventory) {
    char itemName[100];
    int index = -1;

    printf("Enter the name of the item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0; //remove trailing newline

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found!\n");
        return;
    }

    // Shift remaining items to fill the gap
    for (int i = index; i < inventory->count - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
        inventory->availability[i] = inventory->availability[i + 1];
    }
    inventory->count--;
    printf("Item removed successfully!\n");
}


int main() {
    GroceryInventory inventory = { .count = 0 };
    int choice;

    do {
        printf("\nGrocery Inventory Management\n");
        printf("1. Add grocery item\n");
        printf("2. List all grocery items\n");
        printf("3. Update item quantity\n");
        printf("4. Remove grocery item\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1: addItem(&inventory); break;
            case 2: listItems(&inventory); break;
            case 3: updateQuantity(&inventory); break;
            case 4: removeItem(&inventory); break;
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 5);

    return 0;
}