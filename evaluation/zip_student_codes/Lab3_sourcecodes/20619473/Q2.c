#include <stdio.h> // Standard library for input/output
#include <string.h> // String library

#define MAX_ITEMS 100 // Defining

// Struct for Grocery Items
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int inStock; 
} GroceryItem;

// Function prototypes
void addItem(GroceryItem inventory[], int *count);
void listItems(const GroceryItem inventory[], int count);
void updateQuantity(GroceryItem inventory[], int count);
void removeItem(GroceryItem inventory[], int *count);

int main() {
    GroceryItem inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    // Do while, switch case for choices
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
                addItem(inventory, &itemCount);
                break;
            case 2:
                listItems(inventory, itemCount);
                break;
            case 3:
                updateQuantity(inventory, itemCount);
                break;
            case 4:
                removeItem(inventory, &itemCount);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add
void addItem(GroceryItem inventory[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory full. Cannot add more items.\n");
        return;
    }

    printf("Enter Item Name: ");
    getchar(); // Clear the input buffer
    fgets(inventory[*count].name, sizeof(inventory[*count].name), stdin);
    strtok(inventory[*count].name, "\n"); // Remove newline

    printf("Enter Category: ");
    fgets(inventory[*count].category, sizeof(inventory[*count].category), stdin);
    strtok(inventory[*count].category, "\n"); // Remove newline

    printf("Enter Quantity: ");
    scanf("%d", &inventory[*count].quantity);

    printf("Enter Price: ");
    scanf("%f", &inventory[*count].price);

    inventory[*count].inStock = (inventory[*count].quantity > 0) ? 1 : 0;

    (*count)++;
    printf("Grocery item added successfully!\n");
}

// Function to list
void listItems(const GroceryItem inventory[], int count) {
    if (count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update quantity
void updateQuantity(GroceryItem inventory[], int count) {
    char name[100];
    int newQuantity;

    printf("Enter name of the grocery item to update quantity: ");
    getchar(); // Clear the input buffer
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            inventory[i].inStock = (newQuantity > 0) ? 1 : 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Grocery item '%s' not found in inventory.\n", name);
}

// Function to remove an item
void removeItem(GroceryItem inventory[], int *count) {
    char name[100];

    printf("Enter the name of the grocery item to remove: ");
    getchar(); // Clear the input buffer
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("Grocery item '%s' not found in inventory.\n", name);
}
