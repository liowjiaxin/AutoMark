#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define NAME_LEN 100
#define CATEGORY_LEN 50

//Struct to store grocery item information
typedef struct {
    char name[NAME_LEN];
    char category[CATEGORY_LEN];
    int quantity;
    float price;
    bool in_stock;
} GroceryItem;

//Global inventory
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

//Function prototypes
void addGroceryItem();
void listGroceryItems();
void updateQuantity();
void removeGroceryItem();

int main() {
    int choice;

    while (1) {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //Consume newline character

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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addGroceryItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem item;
    printf("Enter Item Name: ");
    fgets(item.name, NAME_LEN, stdin);
    item.name[strcspn(item.name, "\n")] = '\0'; //Remove newline

    printf("Enter Category: ");
    fgets(item.category, CATEGORY_LEN, stdin);
    item.category[strcspn(item.category, "\n")] = '\0'; //Remove newline

    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter Price: ");
    scanf("%f", &item.price);
    getchar(); //Consume newline character

    item.in_stock = (item.quantity > 0);

    inventory[itemCount++] = item;
    printf("Grocery item added successfully!\n");
}

void listGroceryItems() {
    if (itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].in_stock ? "In Stock" : "Out of Stock");
        printf("--------------------\n");
    }
}

void updateQuantity() {
    if (itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    char name[NAME_LEN];
    printf("Enter the name of the grocery item to update quantity: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; //Remove newline

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory[i].quantity);
            getchar(); //Consume newline character

            inventory[i].in_stock = (inventory[i].quantity > 0);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Grocery item '%s' not found.\n", name);
}

void removeGroceryItem() {
    if (itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    char name[NAME_LEN];
    printf("Enter the name of the grocery item to remove: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; //Remove newline

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Grocery item '%s' not found.\n", name);
}
