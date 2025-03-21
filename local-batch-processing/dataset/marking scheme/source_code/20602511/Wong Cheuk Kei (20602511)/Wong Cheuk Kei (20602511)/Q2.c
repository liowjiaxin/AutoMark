#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAMES 100
#define MAX_CATEGORY 50
#define MAX_ITEMS 100

// Define a structure for grocery items
struct GroceryItem {
    char name[MAX_NAMES];
    char category[MAX_CATEGORY];
    int quantity;
    float price;
};

// Define a structure to represent availability status
struct AvailabilityStatus {
    bool inStock;
    bool outOfStock;
};

// Define the inventory structure
struct GroceryInventory {
    struct GroceryItem items[MAX_ITEMS];
    struct AvailabilityStatus status[MAX_ITEMS];
    int totalItems;
};

// Function prototypes
void addGroceryItem(struct GroceryInventory *inventory);
void listGroceryItems(struct GroceryInventory inventory);
void updateQuantity(struct GroceryInventory *inventory);
void removeGroceryItem(struct GroceryInventory *inventory);
void displayMenu();

int main() {
    struct GroceryInventory inventory = { .totalItems = 0 };  // Initialise the inventory

    int choice;

    while (1) {
        displayMenu();  // Display menu options
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);  // Add a grocery item
                break;
            case 2:
                listGroceryItems(inventory);  // List all grocery items
                break;
            case 3:
                updateQuantity(&inventory);  // Update the quantity of a grocery item
                break;
            case 4:
                removeGroceryItem(&inventory);  // Remove a grocery item from inventory
                break;
            case 5:
                printf("Exiting...\n");
                return 0;  
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

// Function to add a grocery item
void addGroceryItem(struct GroceryInventory *inventory) {
    if (inventory->totalItems >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    struct GroceryItem newItem;
    struct AvailabilityStatus newStatus;

    printf("Enter Item Name: ");
    getchar();  
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; 
    
    printf("Enter Category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0';  
    
    do {
        printf("Enter Quantity: ");
        if (scanf("%d", &newItem.quantity) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (newItem.quantity < 0) {
            printf("Quantity cannot be negative. Please try again.\n"); // Input validation for quantity (no negative values)
        }
    } while (newItem.quantity < 0);

    do {
        printf("Enter Price: ");
        if (scanf("%f", &newItem.price) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (newItem.price <= 0) {
            printf("Price must be greater than 0. Please try again.\n"); // Input validation for prices (no negative values)
        }
    } while (newItem.price <= 0);

    // Set availability status based on quantity
    if (newItem.quantity > 0) {
        newStatus.inStock = true;
        newStatus.outOfStock = false;
    } else {
        newStatus.inStock = false;
        newStatus.outOfStock = true;
    }

    // Add the item to inventory
    inventory->items[inventory->totalItems] = newItem;
    inventory->status[inventory->totalItems] = newStatus;
    inventory->totalItems++;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items and their availability status
void listGroceryItems(struct GroceryInventory inventory) {
    if (inventory.totalItems == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory.totalItems; i++) {
        printf("Name : %s\n", inventory.items[i].name);
        printf("Category: %s\n", inventory.items[i].category);
        printf("Quantity: %d\n", inventory.items[i].quantity);
        printf("Price: %.2f\n", inventory.items[i].price);
        if (inventory.status[i].inStock) {
            printf("Status: In Stock\n");
        } else {
            printf("Status: Out of Stock\n");
        }
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(struct GroceryInventory *inventory) {
    char itemName[50];
    printf("Enter name of the grocery item to update quantity: ");
    scanf(" %[^\n]", itemName);  

    // Search for the item by name
    int index = -1;
    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found in inventory.\n");
        return;
    }

    int newQuantity;
    printf("Enter new quantity for %s: ", inventory->items[index].name);
    scanf("%d", &newQuantity);

    // Update the quantity
    inventory->items[index].quantity = newQuantity;

    // Update the availability status based on the new quantity
    if (newQuantity > 0) {
        inventory->status[index].inStock = true;
        inventory->status[index].outOfStock = false;
    } else {
        inventory->status[index].inStock = false;
        inventory->status[index].outOfStock = true;
    }

    printf("Quantity updated successfully!\n");
}

// Function to remove a grocery item from inventory
void removeGroceryItem(struct GroceryInventory *inventory) {
    char itemName[50];
    printf("Enter the name of the grocery item to remove: ");
    scanf(" %[^\n]", itemName);  

    // Search for the item by name
    int index = -1;
    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found in inventory.\n");
        return;
    }

    // Shift the items index to remove the item
    for (int i = index; i < inventory->totalItems - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
        inventory->status[i] = inventory->status[i + 1];
    }

    // Decrease the total item count
    inventory->totalItems--;

    printf("Grocery item '%s' removed successfully!\n", itemName);
}