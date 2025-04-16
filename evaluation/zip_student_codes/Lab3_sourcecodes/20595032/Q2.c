#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool in_stock;
} GroceryItem;


// Store up to MAX_ITEMS in grocery
GroceryItem inventory[MAX_ITEMS];
int item_count = 0;

// Functions
void addITEM();
void listITEM();
void updateITEM();
void removeITEM();

int main() {
    int choice;
    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                addITEM();
                break;
            case 2:
                listITEM();
                break;
            case 3:
                updateITEM();
                break;
            case 4:
                removeITEM();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid. Please enter a number from 1-5.\n");
        }
    } while (choice != 5);

    return 0;
}

void addITEM() {
    if (item_count >= MAX_ITEMS) {
        printf("Inventory is full. Please remove an item first.\n");
        return;
    }

    GroceryItem newITEM;

    printf("Enter Item Name: ");
    fgets(newITEM.name, sizeof(newITEM.name), stdin);
    newITEM.name[strcspn(newITEM.name, "\n")] = 0; 

    printf("Enter Category: ");
    fgets(newITEM.category, sizeof(newITEM.category), stdin);
    newITEM.category[strcspn(newITEM.category, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &newITEM.quantity);

    printf("Enter Price: ");
    scanf("%f", &newITEM.price);

    newITEM.in_stock = (newITEM.quantity > 0);

    inventory[item_count++] = newITEM;

    printf("Grocery item added successfully!\n");
}

void listITEM() {
    if (item_count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < item_count; i++) {
        printf("\nName: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].in_stock ? "In Stock" : "Out of Stock");
    }
}

void updateITEM() {
    char itemName[100];
    int newITEM;

    printf("Enter name of the grocery item to update quantity: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0;

    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity for %s: ", inventory[i].name);
            scanf("%d", &newITEM);
            getchar();

            inventory[i].quantity = newITEM;
            inventory[i].in_stock = (newITEM > 0);

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

void removeITEM() {
    char itemName[100];

    printf("Enter name of the grocery item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0;

    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            for (int j = i; j < item_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            item_count--;
            printf("Grocery item '%s' removed successfully!\n", itemName);
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}
