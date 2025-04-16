#include <stdio.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_ITEMS 100
#define MAX_CATEGORY 50

typedef struct { // struct for grocery items
    char name [MAX_NAME];
    char category[MAX_CATEGORY];
    int quantity;
    float price;
} groceryItem;

typedef struct { // struct for availability status
    int inStock;
    int outOfStock;
} availStatus;

typedef struct { // struct for grocery inventory
    groceryItem items[MAX_ITEMS];
    availStatus status[MAX_ITEMS];
    int count;
} groceryInventory;

void menu() { // Grocery Inventory Management System menu
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

void add(groceryInventory *inventory) { // add grocery item function
    if (inventory->count < MAX_ITEMS) { // if inventory is not full, input item's name, category, quantity and price
        printf("Enter Item Name: ");
        scanf("%s", inventory->items[inventory->count].name);
        printf("Enter Category: ");
        scanf("%s", inventory->items[inventory->count].category);
        printf("Enter Quantity: ");
        scanf("%d", &inventory->items[inventory->count].quantity);
        printf("Enter Price: ");
        scanf("%f", &inventory->items[inventory->count].price);

        inventory->status[inventory->count].inStock = (inventory->items[inventory->count].quantity > 0); // update availability status
        inventory->status[inventory->count].outOfStock = (inventory->items[inventory->count].quantity == 0);

        inventory->count++;
        printf("Grocery item added successfully!\n");
    } else {
        printf("Inventory is full.\n");
    }
}

void list(groceryInventory *inventory) { // display function
    if (inventory->count == 0) { // if inventory is not empty, display items
        printf("No grocery items in the inventory.\n");
    } else {
        for (int i = 0; i < inventory->count; i++) {
            printf("Name: %s\n", inventory->items[i].name);
            printf("Category: %s\n", inventory->items[i].category);
            printf("Quantity: %d\n", inventory->items[i].quantity);
            printf("Price: %.2f\n", inventory->items[i].price);
            printf("Status: %s\n", inventory->status[i].inStock ? "In Stock" : "Out of Stock");
        }
    }
}

void update(groceryInventory *inventory) { // update function
    char name [MAX_NAME];
    int newQuantity;
    printf("Enter name of the grocery item to update quantity: "); 
    scanf("%s", name);
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);// update quantity
            scanf("%d", &newQuantity);
            inventory->items[i].quantity = newQuantity;
            inventory->status[i].inStock = (newQuantity > 0); // update availability status
            inventory->status[i].outOfStock = (newQuantity == 0);
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Grocery item not found.\n");
}

void removeGroceryItem(groceryInventory *inventory) { // remove function
    char name [MAX_NAME];
    printf("Enter name of the grocery item to remove: ");
    scanf("%s", name);
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }
            inventory->count--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("Grocery item not found.\n");
}

int main() {
    groceryInventory inventory = {0};
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) { // use switch-case
            case 1:
                add(&inventory);
                break;
            case 2:
                list(&inventory);
                break;
            case 3:
                update(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // when choice == 5 exit

    return 0;
}