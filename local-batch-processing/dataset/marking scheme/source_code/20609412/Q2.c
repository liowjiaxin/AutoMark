#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_ITEMS 100


// Structure for all contact information
struct groceryItem {
    char name[100];
    char category[50];
    int quantity;
    float price;
};

struct availabilityStatus {
    bool inStock;
    bool outOfStock;
};

struct groceryInventory {
    struct groceryItem items[MAX_ITEMS];
    struct availabilityStatus availability[MAX_ITEMS];
    int totalGroceries;
};

void addGroceryItem(struct groceryInventory *inventory);
void listGroceryItem(struct groceryInventory *inventory);
void updateGroceryQuantity(struct groceryInventory *inventory);
void removeGroceryItem(struct groceryInventory *inventory);

int main(void) {

    struct groceryInventory inventory = {0};

    char choice[2];  
    
    do {
        // Display menu
        printf("\nGrocery Inventory Management System");
        printf("\n1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%s", choice);  // Read input as string
 
        
        if (strlen(choice) != 1) {
            printf("Invalid choice! Please select a valid option (1-5).\n");
            continue;
        }

        switch (choice[0]) {
            case '1': 
                addGroceryItem(&inventory); 
                break;
            case '2': 
                listGroceryItem(&inventory);
                break;
            case '3': 
                updateGroceryQuantity(&inventory); 
                break;
            case '4': 
                removeGroceryItem(&inventory);
                break;
            case '5':
                printf("Exiting the program. Goodbye!\n"); 
                break;
            default: 
                printf("Invalid choice! Please select a valid option (1-5).\n");
        }

    }  while (choice[0] != '5');  // Loop until user chooses to exit

    return 0;
}

// Add a grocery item to the inventory
void addGroceryItem(struct groceryInventory *inventory) {

    //check if inventory is full
    if (inventory->totalGroceries >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    // Get the details for the grocery item
    struct groceryItem item;
    printf("Enter Item Name: ");
    scanf(" %[^\n]", item.name);

    printf("Enter Category: ");
    scanf(" %[^\n]", item.category);

    // Get and validate quantity (must be a number)
    printf("Enter Quantity: ");

    while (scanf("%d", &item.quantity) != 1) {
        // Invalid input for integer
        printf("Please input a valid integer for quantity: ");
        while (getchar() != '\n');  // Clear the buffer
    }

    // Get and validate price (must be a number)
    printf("Enter Price: ");
    while (scanf("%f", &item.price) != 1) {
        // Invalid input for float
        printf("Please input a valid number for price: ");
        while (getchar() != '\n');  // Clear the buffer
    }

    // Determine availability based on quantity
    struct availabilityStatus status = {item.quantity > 0};

    // Add the item to the inventory
    inventory->items[inventory->totalGroceries] = item;
    inventory->availability[inventory->totalGroceries] = status;
    inventory->totalGroceries++;

    printf("Item added successfully.\n");
}


// List all the grocery items
void listGroceryItem(struct groceryInventory *inventory) {

    // Check if the inventory is empty
    if (inventory->totalGroceries == 0) {
        printf("No grocery items in the inventory.\n");
        return;

    } else {
        //print out the inventory list
        for (int i = 0; i < inventory->totalGroceries; i++) {

            // Determine item status is in stock or out stock
            const char *status = inventory->availability[i].inStock ? "In Stock" : "Out of Stock";
    
            printf("Name:\t\t %s\n", inventory->items[i].name);
            printf("Category:\t %s\n", inventory->items[i].category);
            printf("Quantity:\t %d\n", inventory->items[i].quantity);
            printf("Price:\t\t %.2f\n", inventory->items[i].price);
            printf("Status:\t\t %s\n", status);
        }
    }

}


// Update a grocery's quantity
void updateGroceryQuantity(struct groceryInventory *inventory) {

    // Check if the inventory is empty
    if (inventory->totalGroceries == 0) {
        printf("Inventory is empty. No items found.\n");
        return;
    }

    //get the item name to update
    char name[100];
    int newQuantity;

    printf("Enter name of the grocery item to update quantity: ");
    scanf(" %[^\n]", name);

    // Loop through all items and find the one that matches the user input
    for (int i = 0; i < inventory->totalGroceries; i++) {

        // if matches, get the new quantity
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &newQuantity);

            // update the quantity and availability status  
            inventory->items[i].quantity = newQuantity;
            inventory->availability[i].inStock = newQuantity > 0;
            inventory->availability[i].outOfStock = newQuantity == 0;

            printf("Quantity updated successfully.\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}


// remove grocery item from inventory
void removeGroceryItem(struct groceryInventory *inventory) {
    // Check if the inventory is empty
    if (inventory->totalGroceries == 0) {
        printf("Inventory is empty. No items found.\n");
        return;
    }

    //get the item name to remove
    char name[100];

    printf("Enter name of the grocery item to remove: ");
    scanf(" %[^\n]", name);

    // Loop through all items and find the one that matches the user input
    for (int i = 0; i < inventory->totalGroceries; i++) {

        // if matches, shift all subsequent items one position to the left to delete the item
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->totalGroceries - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
            inventory->totalGroceries--; //decrement the total groceries number

            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found in inventory.\n");
}