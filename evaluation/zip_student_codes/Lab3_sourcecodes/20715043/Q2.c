#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_ITEMS 100

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int count;
} GroceryInventory;

// Functions
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = {.count = 0};
    int choice;

    while (1) {    //menu
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Emter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->count];
    AvailabilityStatus *status = &inventory->status[inventory->count];

    getchar();
    printf("Enter item name: ");    //ask for item name
    fgets(item->name, sizeof(item->name), stdin);   //store item name
    item->name[strcspn(item->name, "\n")] = '\0';
    printf("Enter category: ");     //ask for item category
    fgets(item->category, sizeof(item->category), stdin);    //store item category
    item->category[strcspn(item->category, "\n")] = '\0';
    printf("Enter Quantity: ");     //ask for quantity
    scanf("%d", &item->quantity);    //store the quantity
    printf("Enter price: ");         //ask for price
    scanf("%f", &item->price);        //store price

    status->inStock = item->quantity > 0;
    status->outOfStock = item->quantity == 0;

    inventory->count++;
    printf("Grocery item added successfully!\n");
}

void listGroceryItems(GroceryInventory *inventory) {       //display list function
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->count; i++) {
        GroceryItem *item = &inventory->items[i];
        AvailabilityStatus *status = &inventory->status[i];

        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity(GroceryInventory *inventory) {    //update function
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    char itemName[100];
    getchar();
    printf("Enter name of the grocery item to update quantity: ");   //ask for the name to update quantity
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    int itemIndex = -1;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            itemIndex = i;
            break;
        }
    }
    if (itemIndex == -1) {
        printf("Item '%s' not found in inventory.\n", itemName);
        return;
    }

    int newQuantity;
    printf("Enter new quantity for %s: ", itemName);             //ask for new quantity
    while (scanf("%d", &newQuantity) != 1) {
        printf("Invalid input. Please enter an integer for quantity: ");
        while (getchar() != '\n');
    }

    GroceryItem *item = &inventory->items[itemIndex];
    AvailabilityStatus *status = &inventory->status[itemIndex];

    item->quantity = newQuantity;
    status->inStock = newQuantity > 0;
    status->outOfStock = newQuantity == 0;

    printf("Quantity updated successfully!\n");
}

void removeGroceryItem(GroceryInventory *inventory) {    //remove grocery item function
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    char itemName[100];
    getchar(); 
    printf("Enter name of the grocery item to remove: ");      //ask for name of grocery
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    int itemIndex = -1;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            itemIndex = i;
            break;
        }
    }
    if (itemIndex == -1) {
        printf("Item '%s' not found in inventory.\n", itemName);
        return;
    }
    for (int i = itemIndex; i < inventory->count - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
        inventory->status[i] = inventory->status[i + 1];
    }

    inventory->count--;
    printf("Grocery item '%s' removed successfully!\n", itemName);
}
