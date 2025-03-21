#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

// Function prototypes
void addItem();
void displayItems();
void updateItemQuantity();
void deleteItem();
void displayMenu();

// Structure to represent a grocery item
typedef struct {
    char itemName[MAX_NAME_LEN];    
    char itemCategory[MAX_CATEGORY_LEN]; 
    int itemQuantity;              
    float itemPrice;               
    bool isAvailable;              
} GroceryItem;

// Global variables to store inventory details
GroceryItem inventoryList[MAX_ITEMS];
int totalItems = 0; 

// Function to display the main menu
void displayMenu() {
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

// Function to add a new grocery item
void addItem() {
    if (totalItems >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;
    printf("Enter Item name: ");
    fgets(newItem.itemName, MAX_NAME_LEN, stdin);
    newItem.itemName[strcspn(newItem.itemName, "\n")] = 0; 

    printf("Enter Category: ");
    fgets(newItem.itemCategory, MAX_CATEGORY_LEN, stdin);
    newItem.itemCategory[strcspn(newItem.itemCategory, "\n")] = 0; 

    printf("Enter Quantity: ");
    scanf("%d", &newItem.itemQuantity);

    printf("Enter Price: ");
    scanf("%f", &newItem.itemPrice);
    getchar(); 

    // Update availability status based on quantity
    newItem.isAvailable = newItem.itemQuantity > 0;

    // Add the new item to the inventory
    inventoryList[totalItems++] = newItem;
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items in the inventory
void displayItems() {
    if (totalItems == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < totalItems; i++) {
        printf("Name: %s\n", inventoryList[i].itemName);
        printf("Category: %s\n", inventoryList[i].itemCategory);
        printf("Quantity: %d\n", inventoryList[i].itemQuantity);
        printf("Price: %.2f\n", inventoryList[i].itemPrice);
        printf("Status: %s\n", inventoryList[i].isAvailable ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a specific item
void updateItemQuantity() {
    char targetItem[MAX_NAME_LEN];
    int updatedQuantity;

    if (totalItems == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }

    printf("Enter name of the grocery item to update quantity: ");
    fgets(targetItem, MAX_NAME_LEN, stdin);
    targetItem[strcspn(targetItem, "\n")] = 0; 

    for (int i = 0; i < totalItems; i++) {
        if (strcmp(inventoryList[i].itemName, targetItem) == 0) {
            printf("Enter new quantity for %s: ", inventoryList[i].itemName);
            scanf("%d", &updatedQuantity);
            getchar(); 

            // Update quantity and availability status
            inventoryList[i].itemQuantity = updatedQuantity;
            inventoryList[i].isAvailable = updatedQuantity > 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

// Function to remove a grocery item from the inventory
void deleteItem() {
    char targetItem[MAX_NAME_LEN];

    if (totalItems == 0) {
        printf("No items in the inventory to delete.\n");
        return;
    }

    printf("Enter name of the grocery item to remove: ");
    fgets(targetItem, MAX_NAME_LEN, stdin);
    targetItem[strcspn(targetItem, "\n")] = 0; 
    for (int i = 0; i < totalItems; i++) {
        if (strcmp(inventoryList[i].itemName, targetItem) == 0) {
            // Save the name for confirmation message
            char removedItemName[MAX_NAME_LEN];
            strcpy(removedItemName, inventoryList[i].itemName);

            // Shift items to fill the gap
            for (int j = i; j < totalItems - 1; j++) {
                inventoryList[j] = inventoryList[j + 1];
            }
            totalItems--;

            // Print confirmation message
            printf("Grocery item '%s' removed successfully!\n", inventoryList[i].itemName);
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

int main() {
    int menuChoice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);
        getchar(); 

        switch (menuChoice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                updateItemQuantity();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (menuChoice != 5);

    return 0;
}