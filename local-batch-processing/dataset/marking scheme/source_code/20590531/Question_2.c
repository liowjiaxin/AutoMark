#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];     // Name of the grocery item
    char category[50];  // Category of the item
    int quantity;       // Quantity of the item
    float price;        // Price of the item
    char status[20];    // Status: "In Stock" or "Out of Stock"
} GroceryItem;

// Function Prototypes

// Function to add a new grocery item to the inventory
void addGroceryItem (GroceryItem inventory[], int *count) {
    // Check if the inventory is full
    if (*count >= MAX_ITEMS) {
        printf ("Inventory is full. Cannot add more items. \n");
        return;
    }
    GroceryItem item;

    // Input item details
    printf ("Enter Item Name: ");
    scanf (" %[^\n]%*c", item.name);
    printf ("Enter Category: ");
    scanf (" %[^\n]%*c", item.category);
    printf ("Enter Quantity: ");
    scanf ("%d", &item.quantity);
    printf ("Enter Price: ");
    scanf ("%f", &item.price);

    // Set the status based on the quantity
    strcpy (item.status, item.quantity > 0 ? "In Stock" : "Out of Stock");

    // Add item to the inventory
    inventory[*count] = item;
    (*count)++; // Increment the inventory count
    printf ("Grocery item added successfully! \n");
}

// Function to list all grocery items in the inventory
void listGroceryItems (GroceryItem inventory[], int count) {
    // Check if there are no items in the inventory
    if (count == 0) {
        printf ("No grocery items in the inventory.\n");
        return;
    }

    // Loop and display each item
    for (int i = 0; i < count; i++) {
        printf ("Name: %s\n", inventory[i].name);
        printf ("Category: %s\n", inventory[i].category);
        printf ("Quantity: %d\n", inventory[i].quantity);
        printf ("Price: %.2f\n", inventory[i].price);
        printf ("Status: %s\n\n", inventory[i].status);
    }
}

// Function to update the quantity of a specific grocery item
void updateQuantity (GroceryItem inventory[], int count) {
    char name[100];
    int newQuantity;

    // Prompt user to input the name fo the item to update
    printf ("Enter name of the grocery item to update quantity: ");
    scanf (" %[^\n]%*c", name);

    // Search for the item in the inventory
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Prompt user to input the new quantity
            printf ("Enter new quantity for %s: ", name);
            scanf ("%d", &newQuantity);

            // Update the quantity and status
            inventory[i].quantity = newQuantity;
            strcpy (inventory[i].status, newQuantity > 0 ? "In Stock" : "Out of Stock");
            printf ("Quantity updated successfully! \n");
            return;
        }
    }
    // If item is not found
    printf ("Item not found in inventory. \n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem (GroceryItem inventory[], int *count) {
    char name[100];
    // Prompt user to input the name fo the item to remove
    printf ("Enter name of the grocery item to remove: ");
    scanf (" %[^\n]%*c", name);
    
    // Search for the item in the inventory
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Shift all items after the found item to fill the gap
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--; // Decrement the inventory count
            printf ("Grocery item '%s' removed successfully! \n", name);
            return;
        }
    }
    // If the item is not found
    printf ("Item not found in inventory.\n");
}

// Main function to manage the grocery inventory system
int main () {
    GroceryItem inventory[MAX_ITEMS];   // Array to store grocery items
    int count = 0;  // Number of items in the inventory
    int choice; // User's menu choice

    // Loop until user choose to exit
    while (choice != 5) {
        printf ("\nGrocery Inventory Management System\n");
        printf ("1. Add Grocery Item\n");
        printf ("2. List All Grocery Items\n");
        printf ("3. Update Quantity\n");
        printf ("4. Remove Grocery Item\n");
        printf ("5. Exit\n");
        printf ("Enter Your Choice: ");
        scanf ("%d", &choice);

        switch (choice) {
            case 1:
                addGroceryItem (inventory, &count);
                break;
            
            case 2: 
                listGroceryItems (inventory, count);
                break;

            case 3: 
                updateQuantity (inventory, count);
                break;

            case 4: 
                removeGroceryItem (inventory, &count);
                break;

            case 5: 
                printf ("Exiting...\n");
                break;
            
            default:
                printf ("Invalid Choice. Please try again. \n");
        }
    }
    return 0;
}