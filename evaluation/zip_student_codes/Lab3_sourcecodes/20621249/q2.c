#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum number of grocery items

// Structure to represent a grocery item
typedef struct {
    char name[100];     // Name of the item
    char category[100]; // Category of the item
    int quantity;       // Quantity available
    float price;        // Price of the item
} GroceryItem;

// Structure to represent the availability status of an item
typedef struct {
    int InStock;     // Flag for items in stock
    int OutofStock;  // Flag for items out of stock
} AvailablityStatus;

// Structure to represent the grocery inventory
typedef struct {
    GroceryItem items[MAX_SIZE];         // Array to hold grocery items
    AvailablityStatus availabity[MAX_SIZE]; // Array to hold availability statuses
    int totalitems;                      // Total number of items in the inventory
} GroceryInventory;

// Function to add a new grocery item to the inventory
void AddGroceryItems(GroceryInventory *inventory) {
    // Check if the inventory has reached its maximum size
    if ((*inventory).totalitems >= MAX_SIZE) {
        printf("\nThe max number of items has been reached!\n");
        return;  
    }

    // Get pointers to the current product and its status
    GroceryItem *product = &(*inventory).items[(*inventory).totalitems];
    AvailablityStatus *status = &(*inventory).availabity[(*inventory).totalitems];

    // Input details for the new item
    printf("Enter item name: ");
    fgets((*product).name, sizeof((*product).name), stdin);
    (*product).name[strcspn((*product).name, "\n")] = '\0'; // Remove newline character

    printf("Enter your category: ");
    fgets((*product).category, sizeof((*product).category), stdin);
    (*product).category[strcspn((*product).category, "\n")] = '\0'; // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &(*product).quantity);

    printf("Enter price: ");
    scanf("%f", &(*product).price);

    // Set availability status based on quantity
    if ((*product).quantity > 0) {
        (*status).InStock = 1;
    } else if ((*product).quantity == 0) {
        (*status).OutofStock = 1;
    }

    // Increment the total number of items in the inventory
    (*inventory).totalitems++;

    printf("\nGrocery item added successfully!\n");
}

// Function to list all grocery items in the inventory
void ListGroceryItems(GroceryInventory *inventory) {
    // Check if the inventory is empty
    if ((*inventory).totalitems == 0) {
        printf("\nNo grocery items in the inventory.\n");
        return;
    }

    // Print details of each item
    for (int i = 0; i < (*inventory).totalitems; i++) {
        GroceryItem *product = &(*inventory).items[i];
        AvailablityStatus *status = &(*inventory).availabity[i];

        printf("Name: %s\n", (*product).name);
        printf("Category: %s\n", (*product).category);
        printf("Quantity: %d\n", (*product).quantity);
        printf("Price: %.2f\n", (*product).price);
        if ((*status).InStock == 1) {
            printf("Status: In Stock\n");
        }
        if ((*status).OutofStock == 1) {
            printf("Status: Out of Stock\n");
        }
        printf("\n");
    }
}

// Function to update the quantity of a specific grocery item
void UpdateQuantity(GroceryInventory *inventory) {
    char name[100];

    // Input the name of the item to update
    printf("Enter the name of the grocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    int itemfound = 0;

    // Search for the item in the inventory
    for (int i = 0; i < (*inventory).totalitems; i++) {
        GroceryItem *product = &(*inventory).items[i];
        AvailablityStatus *status = &(*inventory).availabity[i];

        if (strcmp((*product).name, name) == 0) {
            itemfound = 1;
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &(*product).quantity);
            
            // Clear input buffer
            while (getchar() != '\n');

            // Update availability status
            if ((*product).quantity <= 0) {
                (*status).InStock = 0;
                (*status).OutofStock = 1;
            }
            printf("\nQuantity updated successfully!\n");
            break;
        }
    }

    // If the item is not found
    if (!itemfound) {
        printf("Name not found in the inventory!\n");
    }
}

// Function to remove a grocery item from the inventory
void RemoveGroceryItems(GroceryInventory *inventory) {
    char name[100];

    // Input the name of the item to remove
    printf("Enter the name of the grocery item to be removed: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    int itemfound = 0;

    // Search for the item in the inventory
    for (int i = 0; i < (*inventory).totalitems; i++) {
        GroceryItem *product = &(*inventory).items[i];
        AvailablityStatus *status = &(*inventory).availabity[i];

        if (strcmp((*product).name, name) == 0) {
            itemfound = 1;
            // Remove the item by shifting the remaining items
            for (int j = i; j < (*inventory).totalitems - 1; j++) {
                (*inventory).items[j] = (*inventory).items[j + 1];
                (*inventory).availabity[j] = (*inventory).availabity[j + 1];
            }
            (*inventory).totalitems--; // Decrement total items
            printf("Grocery item '%s' removed successfully!\n", name);
            break;
        }
    }

    // If the item is not found
    if (!itemfound) {
        printf("\nItem name was not found in the inventory!\n");
    }
}

// Main function to display the menu and handle user choices
int main() {
    int choice = 0;
    GroceryInventory inventory = {.totalitems = 0}; // Initialize inventory

    while (1) {
        // Display menu
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Items\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear input buffer
        while (getchar() != '\n');

        // Perform the selected operation
        switch (choice) {
            case 1:
                AddGroceryItems(&inventory);
                break;
            case 2:
                ListGroceryItems(&inventory);
                break;
            case 3:
                UpdateQuantity(&inventory);
                break;
            case 4:
                RemoveGroceryItems(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again!\n");
                break;
        }
    }

    return 0;
}
