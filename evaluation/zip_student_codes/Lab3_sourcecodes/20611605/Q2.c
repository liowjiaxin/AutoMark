#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Define the struct
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool inStock;
} GroceryItem;

// Inventory structure
typedef struct {
    GroceryItem items[100];
    int count;
} Inventory;

Inventory inventory = { .count = 0 };

// function to validate if user entered numbers 
int getValidatedInteger(const char* prompt) {
    int value;
    char buffer[50];
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
        }
    }
}

// function to check if user entered proper float
float getValidatedFloat(const char* prompt) {
    float value;
    char buffer[50];
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%f", &value) == 1) {
            return value;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }
}

// function to add a grocery item
void addGroceryItem() {
    GroceryItem newItem;
    printf("Enter name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    strtok(newItem.name, "\n"); // Remove newline

    printf("Enter category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    strtok(newItem.category, "\n");

    newItem.quantity = getValidatedInteger("Enter quantity: ");
    newItem.price = getValidatedFloat("Enter price: ");

    newItem.inStock = newItem.quantity > 0;
    inventory.items[inventory.count++] = newItem;
    printf("Item added successfully.\n");
}

// function to list all grocery items
void listGroceryItems() {
    if (inventory.count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\nList:\n");
    for (int i = 0; i < inventory.count; i++) {
        GroceryItem item = inventory.items[i];
        printf("Name: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Status: %s\n\n", item.inStock ? "In Stock" : "Out of Stock");
    }
}

// function to update the quantity of a grocery item
void updateQuantity() {
    char name[100];
    printf("Enter the name of the item to update: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, name) == 0) {
            inventory.items[i].quantity = getValidatedInteger("Enter new quantity: ");
            inventory.items[i].inStock = inventory.items[i].quantity > 0;
            printf("Quantity updated successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

// function to remove a grocery item
void removeGroceryItem() {
    char name[100];
    printf("Enter the name of the item to remove: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, name) == 0) {
            for (int j = i; j < inventory.count - 1; j++) {
                inventory.items[j] = inventory.items[j + 1];
            }
            inventory.count--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

int main() {
    int choice;

    //do while loop
    do {
        //print menu
        printf("\nMenu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        choice = getValidatedInteger("");

        switch (choice) {
            //call for add item function
            case 1:
                addGroceryItem();
                break;
            //call for list item function
            case 2:
                listGroceryItems();
                break;
            //call for update item function
            case 3:
                updateQuantity();
                break;
            // call for remove item function
            case 4:
                removeGroceryItem();
                break;
            // exit 
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}