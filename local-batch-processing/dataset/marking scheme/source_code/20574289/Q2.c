
//----------------------------------------------------------------

// Library Header Pull & Variable Definitions/Constants
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>    // Used for the boolean/Availability Status.

#define MAXIMUM_ITEMS_ALLOWED 100
#define MAXIMUM_NAME_LEN 100
#define MAXIMUM_CATEGORY_LEN 50

//----------------------------------------------------------------

// Structure for Grocery Item
typedef struct {
    char name[MAXIMUM_NAME_LEN];
    char category[MAXIMUM_CATEGORY_LEN];
    int quantity;
    float price;
} GROCItem;

// Structure for Availability Status
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Structure for Grocery Inventory
typedef struct {
    GROCItem items[MAXIMUM_ITEMS_ALLOWED];
    AvailabilityStatus availability[MAXIMUM_ITEMS_ALLOWED];
    int count;
} GROCInv;

//----------------------------------------------------------------

// Function prototypes
void addGROCItem(GROCInv *inventory);               // Function for adding a Grocery Item with its Category, Price & Quantity
void listGROCItems(GROCInv *inventory);             // Lists all the Grocery Items
void updateGROCItemQuantity(GROCInv *inventory);    // Updates a specified Grocery Item's quantity.
void removeGROCItem(GROCInv *inventory);            // Function for removing a specified Grocery Item.

//----------------------------------------------------------------

int main() {
    GROCInv inventory = {{}, {}, 0};            // Grocery Struct, Availability, Items in Inv, starting from zero.
    int choice;
    printf("Welcome to the Grocery Inventory Management System! \nThis Software serves to manage your grocery inventory by allowing you to add, modify, remove and view all your inventory. \nFor more information or assistance, reach out to IT @ efyms24 <3 \n\n");
    do {
        // Menu
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
                addGROCItem(&inventory);
                break;
            case 2:
                listGROCItems(&inventory);
                break;
            case 3:
                updateGROCItemQuantity(&inventory);
                break;
            case 4:
                removeGROCItem(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:                            // Data Validation & Error Handling with Return Handler
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item
void addGROCItem(GROCInv *inventory) {
    if (inventory->count >= MAXIMUM_ITEMS_ALLOWED) {
        printf("Inventory is full!\n");
        return;
    }

    getchar(); // Consume leftover newline
    printf("Enter Item Name: ");
    fgets(inventory->items[inventory->count].name, MAXIMUM_NAME_LEN, stdin);
    inventory->items[inventory->count].name[strcspn(inventory->items[inventory->count].name, "\n")] = 0; // Remove newline character

    printf("Enter Category: ");
    fgets(inventory->items[inventory->count].category, MAXIMUM_CATEGORY_LEN, stdin);
    inventory->items[inventory->count].category[strcspn(inventory->items[inventory->count].category, "\n")] = 0; // Remove newline character

    printf("Enter Quantity: ");
    scanf("%d", &inventory->items[inventory->count].quantity);

    printf("Enter Price: ");
    scanf("%f", &inventory->items[inventory->count].price);

    // Set availability based on quantity
    if (inventory->items[inventory->count].quantity > 0) {
        inventory->availability[inventory->count].inStock = true;
        inventory->availability[inventory->count].outOfStock = false;
    } else {
        inventory->availability[inventory->count].inStock = false;
        inventory->availability[inventory->count].outOfStock = true;
    }

    inventory->count++;                                       // Incremental line

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listGROCItems(GROCInv *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");     // Data Validation & Error Handling with Return Handler
        return;
    }

    printf("\nGrocery Items List:\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("Name: %s\n", inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Status: %s\n\n", inventory->availability[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateGROCItemQuantity(GROCInv *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items to update.\n");            // Data Validation & Error Handling with Return Handler
        return;
    }

    char itemName[MAXIMUM_NAME_LEN];
    int newQuantity;

    getchar(); // Consume leftover newline
    printf("Enter the name of the item to update: ");
    fgets(itemName, MAXIMUM_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found!\n");                        // Data Validation & Error Handling with Return Handler
        return;
    }

    printf("Enter the new quantity: ");
    scanf("%d", &newQuantity);

    inventory->items[index].quantity = newQuantity;                         // Pointer Segment
    inventory->availability[index].inStock = (newQuantity > 0);             // Usage of Arrow operator to access values of Quantity & Availability.
    inventory->availability[index].outOfStock = (newQuantity <= 0);

    printf("Quantity updated successfully!\n");
}

// Function to remove a grocery item
void removeGROCItem(GROCInv *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items to remove.\n");            // Data Validation & Error Handling with Return Handler
        return;
    }

    char itemName[MAXIMUM_NAME_LEN];

    getchar(); // Consume leftover newline
    printf("Enter the name of the item to remove: ");
    fgets(itemName, MAXIMUM_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found!\n");                        // Data Validation & Error Handling with Return Handler
        return;
    }

    for (int i = index; i < inventory->count - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];                  // Pointer Segment
        inventory->availability[i] = inventory->availability[i + 1];    // Usage of Arrow operator to access values of Quantity & Availability.
    }

    inventory->count--;

    printf("Grocery item removed successfully!\n");
}
