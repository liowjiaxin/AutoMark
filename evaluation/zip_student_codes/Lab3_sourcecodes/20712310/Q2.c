
#include <stdio.h>
#include <string.h>

// define the  largest number of grocery
#define MAX_ITEMS 100

// define the single item
typedef struct {
    char name[101];
    char category[51];
    int quantity;
    float price;
    int inStock; // 1 for In Stock, 0 for Out of Stock
} GroceryItem;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

// five functions

void addGroceryItem(GroceryInventory *inventory);
void listAllGroceryItems(GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);
void printGroceryItem(const GroceryItem *item);

int main() {

// initializ inventory as 0
    GroceryInventory inventory = { .itemCount = 0 };
    int choice;

//loop

    while (1) {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listAllGroceryItems(&inventory);
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

//declare concrete function
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }
    GroceryItem newItem;
    printf("Enter Item Name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    strtok(newItem.name, "\n");
    printf("Enter Category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    strtok(newItem.category, "\n");
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    getchar(); // Consume newline
    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    getchar(); // Consume newline
    newItem.inStock = newItem.quantity > 0;
    inventory->items[inventory->itemCount++] = newItem;
    printf("Grocery item added successfully!\n");
}

void listAllGroceryItems(GroceryInventory *inventory) {
    for (int i = 0; i < inventory->itemCount; i++) {
        printGroceryItem(&inventory->items[i]);
    }
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
    }
}

void updateQuantity(GroceryInventory *inventory) {
    char name[101];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory->items[i].quantity);
            getchar(); // Consume newline
            inventory->items[i].inStock = inventory->items[i].quantity > 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Grocery item not found.\n");
}

void removeGroceryItem(GroceryInventory *inventory) {
    char name[101];
    printf("Enter name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->itemCount--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("Grocery item not found.\n");
}

void printGroceryItem(const GroceryItem *item) {
    printf("Name: %s\n", item->name);
    printf("Category: %s\n", item->category);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n", item->price);
    printf("Status: %s\n", item->inStock ? "In Stock" : "Out of Stock");
}