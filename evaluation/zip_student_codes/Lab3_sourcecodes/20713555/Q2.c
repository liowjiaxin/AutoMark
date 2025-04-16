#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Define the structure for a grocery item
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} GroceryItem;

// Define the structure for availability status
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Define the structure for grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus availability[MAX_ITEMS];
    int count;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateGroceryItemQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);
void displayMenu();
int findItemByName(GroceryInventory *inventory, const char *name);
bool isValidName(const char *name);
bool isValidCategory(const char *category);

int main() {
    GroceryInventory inventory = { .count = 0 };
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { // Check if input is valid
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input from buffer
            continue; // Restart loop
        }

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateGroceryItemQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 to 5 only.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Grocery Inventory Management ---\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity by Item Name\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}


// Function to validate category (only alphabetic characters and spaces)
bool isValidCategory(const char *category) {
    for (int i = 0; category[i] != '\0'; i++) {
        if (!isalpha(category[i]) && !isspace(category[i])) {
            return false; // Invalid character found
        }
    }
    return true; // Valid category
}

// Function to add a grocery item
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;

    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.name); // Read string with spaces

    printf("Enter category: ");
    scanf(" %[^\n]", newItem.category);

    // Validate category
    if (!isValidCategory(newItem.category)) {
        printf("Invalid category! Only alphabetic characters are allowed.\n");
        return;
    }

    printf("Enter quantity: ");
    while (scanf("%d", &newItem.quantity) != 1 || newItem.quantity < 0) { 
        // Validate integer input and ensure quantity is non-negative
        printf("Invalid input. Please enter a valid non-negative quantity: ");
        while (getchar() != '\n'); // Clear invalid input from buffer
    }

    printf("Enter price: ");
    while (scanf("%f", &newItem.price) != 1 || newItem.price < 0.0f) { 
        // Validate float input and ensure price is non-negative
        printf("Invalid input. Please enter a valid non-negative price: ");
        while (getchar() != '\n'); // Clear invalid input from buffer
    }

    inventory->items[inventory->count] = newItem;

    // Set availability status based on quantity
    inventory->availability[inventory->count].inStock = (newItem.quantity > 0);
    inventory->availability[inventory->count].outOfStock = (newItem.quantity == 0);

    inventory->count++;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items with their availability
void listGroceryItems(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in inventory.\n");
        return;
    }

    printf("\n--- Grocery Items ---\n");

    for (int i = 0; i < inventory->count; i++) {
        GroceryItem item = inventory->items[i];
        AvailabilityStatus status = inventory->availability[i];

        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Availability: %s\n", status.inStock ? "In Stock" : "Out of Stock");
        printf("-----------------------\n");
    }
}

// Function to find an item by name, returns index or -1 if not found
int findItemByName(GroceryInventory *inventory, const char *name) {
   for (int i = 0; i < inventory->count; i++) {
       if (strcmp(inventory->items[i].name, name) == 0) { // Case-sensitive comparison
           return i; // Return index of found item
       }
   }
   return -1; // Return -1 if not found
}

// Function to update the quantity of a grocery item by name
void updateGroceryItemQuantity(GroceryInventory *inventory) {
   if (inventory->count == 0) {
       printf("No grocery items in inventory.\n");
       return;
   }

   char name[MAX_NAME_LENGTH];

   // Prompt for item name
   printf("Enter the name of the item to update: ");
   scanf(" %[^\n]", name); // Read string with spaces

   int index = findItemByName(inventory, name); // Find index of the item by name

   if (index == -1) { // If not found, notify user
       printf("Item '%s' not found in inventory.\n", name);
       return;
   }

   int newQuantity;

   // Loop until a valid quantity is provided
   do {
       printf("Enter new quantity for '%s' (must be >= 0): ", inventory->items[index].name);
       while (scanf("%d", &newQuantity) != 1 || newQuantity < 0) { 
           // Validate integer input and ensure quantity is non-negative
           printf("Invalid input. Please enter a valid non-negative quantity: ");
           while (getchar() != '\n'); // Clear invalid input from buffer
       }
   } while (newQuantity < 0); // Repeat until valid input

   // Update quantity and availability status
   inventory->items[index].quantity = newQuantity;
   inventory->availability[index].inStock = (newQuantity > 0);
   inventory->availability[index].outOfStock = (newQuantity == 0);

   printf("Quantity updated successfully!\n");
}

// Function to remove a grocery item from the inventory by name
void removeGroceryItem(GroceryInventory *inventory) {
   if (inventory->count == 0) {
       printf("No grocery items in inventory.\n");
       return;
   }

   char name[MAX_NAME_LENGTH];

   // Prompt for item name
   printf("Enter the name of the item to remove: ");
   scanf(" %[^\n]", name); // Read string with spaces

   int index = findItemByName(inventory, name); // Find index of the item by name

   if (index == -1) { // If not found, notify user
       printf("Item '%s' not found in inventory.\n", name);
       return;
   }

   // Shift items to fill the gap
   for (int i = index; i < inventory->count - 1; i++) {
       inventory->items[i] = inventory->items[i + 1];
       inventory->availability[i] = inventory->availability[i + 1];
   }

   // Decrease the count of items in the inventory
   inventory->count--;

   printf("Grocery item '%s' removed successfully!\n", name);
}
