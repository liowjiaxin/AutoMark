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

// Structures for Grocery Item and Availability Status
typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
    bool inStock; // Availability status
} GroceryItem;

// Global variables
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
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
        getchar(); // Consume newline left in the buffer

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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

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
void addGroceryItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;
    printf("Enter item name: ");
    fgets(newItem.name, MAX_NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove newline character

    printf("Enter category: ");
    fgets(newItem.category, MAX_CATEGORY_LEN, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = 0; // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);
    getchar(); // Consume newline left in the buffer

    newItem.inStock = newItem.quantity > 0;

    inventory[itemCount++] = newItem;
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items with their availability
void listGroceryItems() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}


// Function to update the quantity of a grocery item
void updateQuantity() {
    char itemName[MAX_NAME_LEN];
    int newQuantity;

    if (itemCount == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }

    printf("Enter name of the grocery item to update quantity: ");
    fgets(itemName, MAX_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline character

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity for \"%s\": ", inventory[i].name);
            scanf("%d", &newQuantity);
            getchar(); // Consume newline left in the buffer

            inventory[i].quantity = newQuantity;
            inventory[i].inStock = newQuantity > 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem() {
    char itemName[MAX_NAME_LEN];

    if (itemCount == 0) {
        printf("No items in the inventory to remove.\n");
        return;
    }

    printf("Enter the name of the item to remove: ");
    fgets(itemName, MAX_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline character

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            // Shift items to remove the found item
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}