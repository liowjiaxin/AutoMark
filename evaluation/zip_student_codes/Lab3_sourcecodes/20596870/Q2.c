#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Sturcture for grocery item
struct GroceryItem {
    char name[100]; //Name of the grocery item
    char category[50]; // Category of the grocery item
    int quantity; // Quantity of the item in stock
    float price; // Price of the grocery item
};

// Structure for availability status
struct AvailabilityStatus {
    int inStock; // Boolean: 1 if the item is in stock, 0 otherwise
    int outofStock; // Boolean: 1 if the item is out of stock, 0 otherwise
};

// Functions
void addItem (struct GroceryItem inventory[], struct AvailabilityStatus availability[], int *itemCount) {
    if (*itemCount < MAX_ITEMS) {
        printf ("Enter details for the new item: \n");
        printf ("Name: "); //Input item name
        scanf (" %99[^\n]", inventory[*itemCount].name);
        
        printf ("Category: "); // Input item category
        scanf (" %49[^\n]", inventory[*itemCount].category);
        
        printf ("Quantity: "); // Input item quantity
        if (scanf ("%d", &inventory[*itemCount].quantity) != 1 || inventory[*itemCount].quantity < 0) {
            printf ("Invalid quantity. Please enter a non-negative number.\n");
            while (getchar() != '\n'); // Clear input buffer
            return;
        }
        
        printf ("Price: "); // Input item price
        if (scanf ("%f", &inventory[*itemCount].price) != 1 || inventory[*itemCount].price < 0) {
            printf ("Invalid price. Please enter a non-negative number.\n");
            while (getchar() != '\n'); // Clear input buffer
            return;
        }

        // Set availability status
        availability[*itemCount].inStock = (inventory[*itemCount].quantity > 0);
        availability[*itemCount].outofStock = (inventory[*itemCount].quantity == 0);

        (*itemCount)++; // Increment the item count
        printf ("Item added successfully!\n");
    } else {
        printf ("Inventory is full.\n");
    }
}

void listItems (struct GroceryItem inventory[], struct AvailabilityStatus availability[], int itemCount) {
    if (itemCount == 0) {
        printf ("No items in inventory.\n");
        return;
    }
    
    printf ("List of Grocery Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf ("\nName: %s\n", inventory[i].name);
        printf ("Category: %s\n", inventory[i].category);
        printf ("Quantity: %d\n", inventory[i].quantity);
        printf ("Price: %.2f\n", inventory[i].price);
        printf ("Status: %s\n", availability[i].inStock ? "In stock"  : "Out of stock");
    }
}

void updateQuantity (struct GroceryItem inventory[], struct AvailabilityStatus availability[], int itemCount) {
    if (itemCount == 0) {
        printf ("No item in inventory to update.\n");
        return;
    }
    
    char name [100];
    printf ("Enter the name of the item to update: ");
    scanf (" %99[^\n]", name);

    // Search for the item by name
    int found = -1;
    for (int i = 0; i < itemCount; i ++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf ("Item '%s' not found in inventory.\n", name);
        return;
    }

    // Update quantity with validation
    printf("Enter new quantity: ");
    if (scanf("%d", &inventory[found].quantity) != 1 || inventory[found].quantity < 0){
        printf ("Invalid quantity. Please enter a non-negative number.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    // Update availability status based on new quantity
    availability[found].inStock = (inventory[found].quantity > 0);
    availability[found].outofStock = (inventory[found].quantity == 0);

    printf ("Quantity updated successfully!\n");
}

void removeItem (struct GroceryItem inventory[], struct AvailabilityStatus availability[], int *itemCount){
    if (*itemCount == 0) {
        printf ("No items in inventory to remove.\n");
        return;
    }
    
    char name [100];
    printf ("Enter the name of the item to remove: ");
    scanf (" %99[^\n]", name);

    // Search for the item by name
    int found = -1;
    for (int i = 0; i < *itemCount; i ++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf ("Item '%s' not found in inventory.\n", name);
        return;
    }
    
    //Shift items to fill the gap
    for(int i = found; i < *itemCount -1; i++) {
        inventory[i] = inventory[i+1];
        availability[i] = availability[i+1];
    }
    (*itemCount)--; // Decrement the item count

    printf ("Grocery item '%s'removed successfully!\n", name);
}

int main () {
    struct GroceryItem inventory[MAX_ITEMS]; // Array of grocery items
    struct AvailabilityStatus availability[MAX_ITEMS]; // Array of availability statuses
    int itemCount = 0; // Total number of items in inventory
    int choice;

    while (1) {
        printf ("\n Grocery Inventory Management\n");
        printf ("1. Add Grocery Item\n");
        printf ("2. List All Grocery Items\n");
        printf ("3. Update Quantity of a Grocery Item\n");
        printf ("4. Remove a Grocery Item\n");
        printf ("5. Exit\n");
        printf ("Enter your choice: ");
        
        // Read user input with validation
        if (scanf ("%d", &choice)!= 1) {
            printf ("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addItem(inventory, availability, &itemCount);
                break;

            case 2:
                listItems(inventory, availability, itemCount);
                break;

            case 3:
                updateQuantity(inventory, availability, itemCount);
                break;

            case 4:
                removeItem(inventory, availability, &itemCount);
                break;

            case 5:
                printf ("Exiting program...\n");
                return 0;

            default:
                printf ("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}