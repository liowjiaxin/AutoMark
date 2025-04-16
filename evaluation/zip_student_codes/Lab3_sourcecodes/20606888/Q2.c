#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LENGTH 100
#define CATEGORY_LENGTH 50
#define MAX_ITEMS 100

// Grocery structure
typedef struct {
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    int quantity;
    float price;
    int inStock;
} Grocery;

Grocery items[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void addItem();
void listItem();
void updateQuantity();
void removeItem();
void menu();

int main() {
    menu();
    return 0;
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    Grocery newItem;

    // Add item
    printf("Enter Item Name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter Category: ");
    scanf(" %[^\n]", newItem.category);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    // Set availability status based on quantity
    newItem.inStock = (newItem.quantity > 0) ? 1 : 0;

    items[itemCount++] = newItem;
    printf("Item added successfully.\n");
}

void listItem() {
    if (itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("\nGrocery List:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s\n Category: %s\n Quantity: %d\n Price: %.2f\n Status: %s\n",
               i + 1, items[i].name, items[i].category, items[i].quantity, items[i].price, items[i].inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity() {
    if (itemCount == 0) {
        printf("No items to update.\n");
        return;
    }

    char name[NAME_LENGTH];
    int newQuantity;
    int found = 0;

    printf("Enter name of the grocery item to update quantity: ");
    scanf(" %[^\n]", name);

    // Search for item
    for (int i = 0; i< itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            // Match found
            printf("Enter new Quantity for %s: ", items[i].name);
            scanf("%d", &newQuantity);

            // Update quantity and availability status
            items[i].quantity = newQuantity;
            items[i].inStock = (newQuantity > 0) ? 1 : 0;

            printf("Quantity updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item '%s' not found in the inventory.\n", name);
    }
}

void removeItem() {
    if (itemCount == 0) {
        printf("No items to remove.\n");
        return;
    }

    char name[NAME_LENGTH];
    int found = 0;

    printf("Enter name of the grocery item to remove: ");
    scanf(" %[^\n]", name);

    // Search for item
    for (int i = 0; i< itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            // Match found
            found = 1;

            // Remove the found item
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1];
            }

            itemCount--;
            printf("Grocery item '%s' removed successfully.\n", name);
            break;
        }
    }

    if (!found) {
        printf("Item '%s' not found in the inventory.\n", name);
    }
}

// Menu
void menu() {
    int choice;
    do {
        printf("\nGrocery Inventory Management System: \n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                listItem();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
}