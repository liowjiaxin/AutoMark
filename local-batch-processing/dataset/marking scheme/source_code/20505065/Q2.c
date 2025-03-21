#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100

// Structs
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    int inStock;
} AvailabilityStatus;

// Global Variables
GroceryItem inventory[MAX_ITEMS];
AvailabilityStatus availability[MAX_ITEMS];
int itemCount = 0;

// Function Prototypes
void addGroceryItem();
void listGroceryItems();
void updateQuantity();
void removeGroceryItem();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

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
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

void addGroceryItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;

    printf("Enter item name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    strtok(newItem.name, "\n");

    printf("Enter category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    strtok(newItem.category, "\n");

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount] = newItem;
    availability[itemCount].inStock = (newItem.quantity > 0);

    itemCount++;
    printf("Item added successfully!\n");
}

void listGroceryItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\n%-20s %-15s %-10s %-10s %-10s\n", "Name", "Category", "Quantity", "Price", "Status");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < itemCount; i++) {
        printf("%-20s %-15s %-10d %-10.2f %-10s\n",
               inventory[i].name,
               inventory[i].category,
               inventory[i].quantity,
               inventory[i].price,
               availability[i].inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity() {
    char itemName[100];
    int newQuantity;

    printf("Enter the name of the item to update: ");
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);

            inventory[i].quantity = newQuantity;
            availability[i].inStock = (newQuantity > 0);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

void removeGroceryItem() {
    char itemName[100];

    printf("Enter the name of the item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
                availability[j] = availability[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}
