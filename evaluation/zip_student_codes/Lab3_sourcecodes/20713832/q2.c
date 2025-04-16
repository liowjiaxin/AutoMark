#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool inStock;
} GroceryItem; // defining a structure called GroceryItem which has functions like name,  category , quantity , price, instock.

// Global variables
GroceryItem inventory[100]; // Th Inventory array of the grocery
int itemCount = 0;          // Count of items in inventory

// The Function prototypes
void addGroceryItem(); 
void listGroceryItems();
void updateQuantity();
void removeGroceryItem();
void printItem(GroceryItem item);

int main() {
    int choice;

    do {                                // using a do loop so that the user can access the menu again until the exit choice is selected
        // Display menu
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: "); // asking the user to input
        scanf("%d", &choice);// to read the input of the user

        // Process the user choice
        switch (choice) {                    // using switch - case to use the respective functions
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
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item
void addGroceryItem() {
    if (itemCount >= 100) {
        printf("Inventory is full! Cannot add more items.\n"); // if the inventory is more than 100 items , the following message is displayed
        return;
    }

    GroceryItem item;
    printf("Enter name of the grocery item: "); // asking the user to input the name of the grocery item 
    getchar(); // Clear the buffer
    fgets(item.name, 100, stdin); // used to ensure the buffer is not overflowed
    item.name[strcspn(item.name, "\n")] = '\0'; // Used to Remove the trailing newline

    printf("Enter category of the grocery item: "); // Asking the user to input the category 
    fgets(item.category, 50, stdin); // used to ensure the buffer is not overflowed
    item.category[strcspn(item.category, "\n")] = '\0'; // Used to remove trailing newline

    printf("Enter quantity of the grocery item: "); // Asking the user to input the quantity of the grocery item
    scanf("%d", &item.quantity); // to read the input

    printf("Enter price of the grocery item: ");
    scanf("%f", &item.price); // to read the input

    // Set availability status
    item.inStock = item.quantity > 0;

    // Add to inventory
    inventory[itemCount++] = item;
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listGroceryItems() {
    if (itemCount == 0) {
        printf("No grocery items in the inventory.\n"); // if there are no grocery item, the following message will be displayed
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        printItem(inventory[i]);
    }
}

// Function to update the quantity of a grocery item
void updateQuantity() {
    char name[100];
    int newQuantity;

    printf("Enter name of the grocery item to update quantity: ");
    getchar(); // Clear the buffer
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &newQuantity);

            inventory[i].quantity = newQuantity;
            inventory[i].inStock = newQuantity > 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Grocery item '%s' not found!\n", name);
}

// Function to remove a grocery item from the inventory
void removeGroceryItem() {
    char name[100];

    printf("Enter name of the grocery item to remove: ");
    getchar(); // Clear the buffer
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

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
    printf("Grocery item '%s' not found!\n", name);
}

// Function to print a grocery item
void printItem(GroceryItem item) {
    printf("\nName: %s\n", item.name);
    printf("Category: %s\n", item.category);
    printf("Quantity: %d\n", item.quantity);
    printf("Price: %.2f\n", item.price);
    printf("Status: %s\n", item.inStock ? "In Stock" : "Out of Stock");
}
