#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GroceryItem {
    char name[100];
    char category[50];
    int quantity;
    float price;
};
typedef struct GroceryItem GroceryItem;

// Make bool type just an int
typedef int bool;
struct AvailabilityStatus {
    bool inStock;
};
typedef struct AvailabilityStatus AvailabilityStatus;

struct GroceryInventory {
    GroceryItem* items[100];
    AvailabilityStatus statuses[100];
    int count;
};
typedef struct GroceryInventory GroceryInventory;

void addGroceryItem(GroceryInventory*);
void listInventory(GroceryInventory*);
void updateQuantity(GroceryInventory*);
void rmvGroceryItem(GroceryInventory*);

// To clear input buffer until a newline
void clearInput() {
    scanf("%*[^\n]");scanf("%*c");
}

int main() {
    GroceryInventory inventory;
    inventory.count = 0;
    int choice;

    while (choice != 5) {
        printf("\nGrocery Inventory Management System\n"
            "1. Add Grocery Item\n"
            "2. List All Grocery Items\n"
            "3. Update quantity\n"
            "4. Remove Grocery Item\n"
            "5. Exit\n"
            "Enter your choice: ");
        scanf("%d", &choice);
        clearInput();

        puts("");
        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listInventory(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                rmvGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void addGroceryItem(GroceryInventory* invPtr) {
    int index = invPtr->count;
    char name[100], category[50];
    int quantity;
    float price;

    // Initialize GroceryItem and space needed to store it
    GroceryItem item;
    invPtr->items[index] = malloc(sizeof(GroceryItem));

    // Prompt for item details
    printf("Enter Item Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name,"\n")] = 0;

    printf("Enter Category: ");
    fgets(category, sizeof(category), stdin);
    category[strcspn(category,"\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    printf("Enter Price: ");
    scanf("%f", &price);

    clearInput();

    // Populating the GroceryItem with its values
    strcpy(item.name, name);
    strcpy(item.category, category);
    item.quantity = quantity;
    item.price = price;

    // Copy the GroceryItem into the premade pointer in the inventory
    memcpy(invPtr->items[index], &item, sizeof(item));

    // Update the Availability array in inventory
    AvailabilityStatus status;
    status.inStock = (quantity > 0) ? 1 : 0;
    memcpy(&(invPtr->statuses[index]), &status, sizeof(status));

    // Update count of inventory
    invPtr->count++;

    puts("Item added successfully!");
}

void listInventory(GroceryInventory* invPtr) {
    GroceryItem* itemPtr;
    int count = invPtr->count;

    if (!count) {
        puts("No items to list");
        return;
    }

    for (size_t i = 0; i < count; i++) {
        itemPtr = invPtr->items[i];

        printf("Name: %s\n", itemPtr->name);
        printf("Category: %s\n", itemPtr->category);
        printf("Quantity: %d\n", itemPtr->quantity);
        printf("Price: %.2f\n", itemPtr->price);
        printf("Status: %s\n", (invPtr->statuses[i].inStock) ? "In Stock" : "Out Stock");
        puts("");
    }
    
}

void updateQuantity(GroceryInventory* invPtr) {
    char name[100];
    int newQuantity;
    int count = invPtr->count;

    if (!count) {
        puts("No items to update");
        return;
    }

    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    // Iterate through the array of pointers checking each name
    for (size_t i = 0; i < count; i++) {
        if (strcmp(invPtr->items[i]->name, name)) {
            continue;
        }

        printf("Enter new quantity for %s: ", name);
        scanf("%d", &newQuantity);
        clearInput();

        invPtr->items[i]->quantity = newQuantity;
        invPtr->statuses[i].inStock = (newQuantity > 0) ? 1 : 0;
        puts("Quantity updated successfully!");
        return;
    }

    puts("Item not found");    
}

void rmvGroceryItem(GroceryInventory* invPtr) {
    char name[100];
    int newQuantity;
    int count = invPtr->count;

    if (!count) {
        puts("No items to remove");
        return;
    }

    printf("Enter name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    // Iterate through items until matching name
    for (size_t i = 0; i < count; i++) {
        if (strcmp(invPtr->items[i]->name, name)) {
            continue;
        }

        // Free pointer that points to the item to be removed
        free(invPtr->items[i]);

        // Shifts the pointers after it to the prevoius index by one
        memcpy(&(invPtr->items[i]), &(invPtr->items[i+1]), sizeof(invPtr->items[i])*(count-i-1));

        // Decrements counts
        invPtr->count--;

        puts("Successfully removed item!");
        return;
    }

    puts("Item not found"); 
}