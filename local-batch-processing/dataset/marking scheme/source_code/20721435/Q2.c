#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Union for availability status
union AvailabilityStatus {
    bool inStock;
    bool outOfStock;
};

// Structure for Grocery Item
struct GroceryItem {
    char name[100];
    char category[50];
    int quantity;
    float price;
    union AvailabilityStatus availability;
};

// Structure for Grocery Inventory
struct GroceryInventory {
    struct GroceryItem items[100];
    int itemCount;
};

// Function prototypes
void addGroceryItem(struct GroceryInventory *inventory);
void listAll(struct GroceryInventory *inventory);
void updateQuantity(struct GroceryInventory *inventory);
void removeGroceryItem(struct GroceryInventory *inventory);

// Main function
int main() {
    struct GroceryInventory inventory = {{0}, 0};
    int choice = 0;
    while (1) {
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        // Validate input
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
            printf("Enter your choice: ");
        }

        switch(choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listAll(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a grocery item to the inventory
void addGroceryItem(struct GroceryInventory *inventory) {
    // Check if inventory is full
    if (inventory->itemCount == 100) {
        printf("Inventory is full. Cannot add more items.\n\n");
        return;
    }

    struct GroceryItem *item = &inventory->items[inventory->itemCount];
    printf("Enter Item name: ");
    getchar();
    fgets(item->name, 100, stdin);
    item->name[strcspn(item->name, "\n")] = 0; // Remove newline character

    printf("Enter Category: ");
    fgets(item->category, 50, stdin);
    item->category[strcspn(item->category, "\n")] = 0; // Remove newline character

    printf("Enter Quantity: ");
    while (scanf("%d", &item->quantity) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        while (getchar() != '\n'); // Clear input buffer
        printf("Enter Quantity: ");
    }
    
    printf("Enter Price: ");
    while (scanf("%f", &item->price) != 1) {
        printf("Invalid input. Please enter a valid price.\n");
        while (getchar() != '\n'); // Clear input buffer
    }

    // Set availability status
    if (item->quantity > 0) {
        item->availability.inStock = true;
    } else {
        item->availability.outOfStock = true;
    }

    inventory->itemCount++;

    printf("Grocery item added successfully!\n\n");
}

// Function to list all grocery items in the inventory
void listAll (struct GroceryInventory *inventory) {
    // Check if inventory is empty
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) {
        printf("Name: %s\n", inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Status: %s\n", 
            inventory->items[i].quantity > 0 ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

// Function to update quantity of a grocery item
void updateQuantity(struct GroceryInventory *inventory) {
    // Check if inventory is empty
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n\n");
        return;
    }

    char name[100];
    int c;

    // Loop to update quantity
    while (1) {
        printf("Enter name of the grocery item to update quantity: ");
        getchar();
        // Read and validate input
        if (fgets(name, 100, stdin) == NULL) {
            printf("Error reading input.\n");
            return;
        }
        name[strcspn(name, "\n")] = 0;  // Remove newline

        // Search for the item in the inventory
        bool found = false;
        for (int i = 0; i < inventory->itemCount; i++) {
            if (strcmp(inventory->items[i].name, name) == 0) {
                found = true; // Set to true if item is found
                printf("Enter new quantity for %s: ", inventory->items[i].name);

                // Read and validate input
                while (scanf("%d", &inventory->items[i].quantity) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n');
                    printf("Enter new quantity for %s: ", inventory->items[i].name);
                }
                
                while (getchar() != '\n');  // Clear input buffer
                
                // Update availability status based on quantity
                if (inventory->items[i].quantity > 0) {
                    inventory->items[i].availability.inStock = true;
                    inventory->items[i].availability.outOfStock = false;
                } else {
                    inventory->items[i].availability.inStock = false;
                    inventory->items[i].availability.outOfStock = true;
                }
                printf("Quantity updated successfully!\n\n");

                return;  // Exit function after successful update
            }
        }
        
        // If item is not found
        if (!found) {
            printf("Item not found!\n");
        }
    }
}

void removeGroceryItem(struct GroceryInventory *inventory) {
    // Check if inventory is empty
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n\n");
        return;
    }

    char name[100];
    int c;
    // Clear any leftover newline from previous input
    getchar();

    // Loop to remove item
    while (1) {
        printf("Enter name of the grocery item to remove: ");
        // Read and validate input
        if (fgets(name, 100, stdin) == NULL) {
            printf("Error reading input.\n");
            return;
        }
        name[strcspn(name, "\n")] = 0;  // Remove newline

        // Search for the item in the inventory
        bool found = false;
        for (int i = 0; i < inventory->itemCount; i++) {
            if (strcmp(inventory->items[i].name, name) == 0) {
                found = true; // Set to true if item is found
                // Shift items to the left to remove the item
                for (int j = i; j < inventory->itemCount - 1; j++) {
                    inventory->items[j] = inventory->items[j + 1];
                }
                inventory->itemCount--;
                printf("Grocery item '%s' removed successfully!\n\n", name);
                return;  // Exit function after successful removal
            }
        }
        
        // If item is not found
        if (!found) {
            printf("Item not found!\n");
        }
    }
}