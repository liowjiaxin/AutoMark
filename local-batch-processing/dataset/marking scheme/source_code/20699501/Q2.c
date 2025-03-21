#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for Grocery item
struct Grocery_item {
    char Name[100];
    char Category[100];
    int Quantity;
    float Price;
    bool In_stock; // Boolean to track availability
};

// Array of Grocery_item structs
struct Grocery_item Inventory[100];

// Counter to keep track of the current number of items
int Counter = 0;

// Function to add a new item to the inventory
void addItem() {
    if (Counter >= 100) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    printf("Enter Item Name: ");
    scanf(" %[^\n]%*c", Inventory[Counter].Name);

    printf("Enter Category: ");
    scanf(" %[^\n]%*c", Inventory[Counter].Category);

    printf("Enter Quantity: ");
    scanf("%d", &Inventory[Counter].Quantity);

    printf("Enter Price: ");
    scanf("%f", &Inventory[Counter].Price);

    // Set availability based on quantity
    Inventory[Counter].In_stock = Inventory[Counter].Quantity > 0;

    Counter++;  // Increment counter
    printf("Grocery item added successfully!\n");
}

// Function to display availability status
void displayAvailability(bool in_stock) {
    if (in_stock) {
        printf("Availability: In stock\n");
    } else {
        printf("Availability: Out of stock\n");
    }
}

// Function to list all items in the inventory
void listItems() {
    if (Counter == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < Counter; i++) {
        printf("Name: %s\nCategory: %s\nQuantity: %d\nPrice: %.2f\n", 
               Inventory[i].Name, Inventory[i].Category, Inventory[i].Quantity, Inventory[i].Price);
        displayAvailability(Inventory[i].In_stock);
        printf("\n");
    }
}

// Function to update the quantity of an item
void updateQuantity() {
    char search_name[100];
    printf("Enter the name of the grocery item to update quantity: ");
    scanf(" %[^\n]%*c", search_name);

    for (int i = 0; i < Counter; i++) {
        if (strcasecmp(Inventory[i].Name, search_name) == 0) {
            printf("Enter new quantity for %s: ", Inventory[i].Name);
            scanf("%d", &Inventory[i].Quantity);

            // Update availability based on the new quantity
            Inventory[i].In_stock = Inventory[i].Quantity > 0;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

// Function to remove an item from the inventory
void removeItem() {
    char name[100];
    printf("Enter the name of the grocery item to remove: ");
    scanf(" %[^\n]%*c", name);

    for (int i = 0; i < Counter; i++) {
        if (strcasecmp(Inventory[i].Name, name) == 0) {
            // Shift all items after the removed one to fill the gap
            for (int j = i; j < Counter - 1; j++) {
                Inventory[j] = Inventory[j + 1];
            }
            Counter--;  // Decrease counter after removal
            printf("Grocery item \"%s\" removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found.\n");
}

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

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
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
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
