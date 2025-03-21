#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100

//A structure named GroceryItem is defined to represent a commodity. 
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    _Bool isAvailable; // true for in stock, false for out of stock
} GroceryItem;

// Define Grocery Inventory
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

//Define the prototypes of four functions
void addGroceryItem();
void listGroceryItems();
void updateQuantity();
void removeGroceryItem();

int main() {
    int choice;
    // Main program loop（do-while）
    do {
        // Display menu options
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        //Process user's choice
        switch (choice) {
            case 1:
                addGroceryItem();//Add a new grocery item
                break;
            case 2:
                listGroceryItems();//List all grocery items
                break;
            case 3:
                updateQuantity();//Update the quantity of an existing item
                break;
            case 4:
                removeGroceryItem();//Remove an item from the inventory
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

//Function to add a new grocery item to the inventory
void addGroceryItem() {
    //Check if inventory is full
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem item;

    printf("Enter Item name: ");
    fgets(item.name, sizeof(item.name), stdin);
    strtok(item.name, "\n"); // Remove newline character

    printf("Enter Category: ");
    fgets(item.category, sizeof(item.category), stdin);
    strtok(item.category, "\n");

    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter Price: ");
    scanf("%f", &item.price);

    item.isAvailable = (item.quantity > 0); // Set availability based on quantity

    inventory[itemCount++] = item;
    printf("Grocery item added successfully!\n");
}

//Function to list all grocery items in the inventory
void listGroceryItems() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    // Print the table header
    printf("Name: %s\n", inventory[0].name);
    printf("Category: %s\n", inventory[0].category);
    printf("Quantity: %d\n", inventory[0].quantity);
    printf("Price: %.2f\n", inventory[0].price);
    printf("Status: %s\n", inventory[0].isAvailable ? "In Stock" : "Out of Stock");
}

//Function to update the quantity of an existing grocery item
void updateQuantity() {
    char name[100];
    int found = 0;

    printf("Enter name of the geocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");

    //Find products matching the entered name
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            inventory[i].isAvailable = (inventory[i].quantity > 0); // Update availability
            printf("Quantity updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found in the inventory.\n");
    }
}

//Function to remove a grocery item from the inventory
void removeGroceryItem() {
    char name[100];
    int found = 0;

    printf("Enter name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");
    
    //Find products matching the entered name
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found in the inventory.\n");
    }
}