/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

// Structure for Grocery Item
typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
    bool inStock; // Availability status
} GroceryItem;

// Global Variables
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

// Function Prototypes
void addItem();
void listItems();
void updateItemQuantity();
void removeItem();
void displayMenu();

int main() {
    int option;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar(); // Clear newline character from input buffer

        switch (option) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                updateItemQuantity();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 5);

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

// Function to add a grocery item
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;
    printf("Enter Item Name: ");
    fgets(newItem.name, MAX_NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove newline

    printf("Enter Category: ");
    fgets(newItem.category, MAX_CATEGORY_LEN, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = 0; // Remove newline

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    getchar(); // Clear newline character

    newItem.inStock = newItem.quantity > 0;
    inventory[itemCount++] = newItem;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listItems() {
    if (itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

// Function to update the quantity of an item
void updateItemQuantity() {
    char itemName[MAX_NAME_LEN];
    int newQuantity;

    if (itemCount == 0) {
        printf("No grocery items in the inventory to update.\n");
        return;
    }

    printf("Enter name of the grocery item to update quantity: ");
    fgets(itemName, MAX_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity for \"%s\": ", inventory[i].name);
            scanf("%d", &newQuantity);
            getchar(); // Clear newline character

            inventory[i].quantity = newQuantity;
            inventory[i].inStock = newQuantity > 0;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

// Function to remove a grocery item
void removeItem() {
    char itemName[MAX_NAME_LEN];

    if (itemCount == 0) {
        printf("No grocery items in the inventory to remove.\n");
        return;
    }

    printf("Enter name of the grocery item to remove: ");
    fgets(itemName, MAX_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            // Shift items to fill the gap
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf(" Grocery item removed successfully!\n");
            return;
        }
    }

    printf("Grocery item not found in the inventory.\n");
}
