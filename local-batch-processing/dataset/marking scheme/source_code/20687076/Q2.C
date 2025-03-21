#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Struct for storing grocery item details
typedef struct {
    char itemName[100];
    char itemCategory[50];
    int itemQuantity;
    float itemPrice;
} Grocery;

// Struct for item availability status
typedef struct {
    bool isAvailable;
    bool isOutOfStock;
} Availability;

// Struct to manage the inventory
typedef struct {
    Grocery items[100];        // Array to store items
    Availability statuses[100]; // Array to track availability
    int totalItems;             // Total number of items in inventory
} Inventory;

// Function Prototypes
void addGroceryItem(Inventory* inventory);
void displayInventory(const Inventory* inventory);
void modifyQuantity(Inventory* inventory);
void deleteItem(Inventory* inventory);
void printMenu();

int main() {
    Inventory inventory = { .totalItems = 0 }; // Initialize inventory with no items
    int userChoice;

    do {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                displayInventory(&inventory);
                break;
            case 3:
                modifyQuantity(&inventory);
                break;
            case 4:
                deleteItem(&inventory);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (userChoice != 5);

    return 0;
}

// Function to display menu options
void printMenu() {
    printf("\n--- Grocery Inventory Menu ---\n");
    printf("1. Add a Grocery Item\n");
    printf("2. View All Items\n");
    printf("3. Update Item Quantity\n");
    printf("4. Remove an Item\n");
    printf("5. Exit\n");
}

// Function to add a grocery item to the inventory
void addGroceryItem(Inventory* inventory) {
    if (inventory->totalItems >= 100) {
        printf("The inventory is full! Cannot add more items.\n");
        return;
    }

    Grocery* newItem = &inventory->items[inventory->totalItems];
    Availability* newStatus = &inventory->statuses[inventory->totalItems];

    printf("Enter item name: ");
    getchar(); // Clear input buffer
    fgets(newItem->itemName, sizeof(newItem->itemName), stdin);
    newItem->itemName[strcspn(newItem->itemName, "\n")] = '\0'; // Remove newline

    printf("Enter item category: ");
    fgets(newItem->itemCategory, sizeof(newItem->itemCategory), stdin);
    newItem->itemCategory[strcspn(newItem->itemCategory, "\n")] = '\0';

    printf("Enter item quantity: ");
    scanf("%d", &newItem->itemQuantity);

    printf("Enter item price: ");
    scanf("%f", &newItem->itemPrice);

    // Set availability status based on quantity
    newStatus->isAvailable = newItem->itemQuantity > 0;
    newStatus->isOutOfStock = !newStatus->isAvailable;

    inventory->totalItems++;
    printf("Item added successfully!\n");
}

// Function to display all items in the inventory
void displayInventory(const Inventory* inventory) {
    if (inventory->totalItems == 0) {
        printf("The inventory is currently empty.\n");
        return;
    }

    printf("\n--- Inventory List ---\n");
    for (int i = 0; i < inventory->totalItems; i++) {
        const Grocery* item = &inventory->items[i];
        const Availability* status = &inventory->statuses[i];

        printf("Item %d:\n", i + 1);
        printf("  Name: %s\n", item->itemName);
        printf("  Category: %s\n", item->itemCategory);
        printf("  Quantity: %d\n", item->itemQuantity);
        printf("  Price: %.2f\n", item->itemPrice);
        printf("  Status: %s\n", status->isAvailable ? "Available" : "Out of Stock");
    }
}

// Function to update the quantity of an item
void modifyQuantity(Inventory* inventory) {
    if (inventory->totalItems == 0) {
        printf("No items available to update.\n");
        return;
    }

    char nameToUpdate[100];
    printf("Enter the name of the item to update: ");
    getchar(); // Clear input buffer
    fgets(nameToUpdate, sizeof(nameToUpdate), stdin);
    nameToUpdate[strcspn(nameToUpdate, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].itemName, nameToUpdate) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &inventory->items[i].itemQuantity);

            // Update availability status
            inventory->statuses[i].isAvailable = inventory->items[i].itemQuantity > 0;
            inventory->statuses[i].isOutOfStock = !inventory->statuses[i].isAvailable;

            printf("Item quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

// Function to delete a grocery item from the inventory
void deleteItem(Inventory* inventory) {
    if (inventory->totalItems == 0) {
        printf("No items available to delete.\n");
        return;
    }

    char nameToRemove[100];
    printf("Enter the name of the item to remove: ");
    getchar(); // Clear input buffer
    fgets(nameToRemove, sizeof(nameToRemove), stdin);
    nameToRemove[strcspn(nameToRemove, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].itemName, nameToRemove) == 0) {
            // Shift remaining items
            for (int j = i; j < inventory->totalItems - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->statuses[j] = inventory->statuses[j + 1];
            }
            inventory->totalItems--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}
