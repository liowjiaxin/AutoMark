#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// Struct definitions
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool inStock;
} GroceryItem;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = { .itemCount = 0 }; 
    int choice;

    do {
        printf("\nGrocery Inventory Management System\n"); //Show the menu
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline character

        switch (choice) { //Collect the input 1,2,3,4,5 
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
                printf("Exiting ...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addGroceryItem(GroceryInventory *inventory) { //for adding grocery
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->itemCount]; 

    printf("Enter Item Name: "); //item name
    fgets(item->name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = '\0'; // Remove newline

    printf("Enter Category: ");
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = '\0'; // Remove newline

    printf("Enter Quantity: "); //item quantity
    scanf("%d", &item->quantity);

    printf("Enter Price: "); //item price
    scanf("%f", &item->price);

    item->inStock = item->quantity > 0;
    inventory->itemCount++;

    printf("Grocery item added successfully!\n");
}

void listGroceryItems(GroceryInventory *inventory) { //show list of the grocery on the inventory
    if (inventory->itemCount == 0) {
        printf("No items in inventory.\n"); //if there's nothing on inventory
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) { //show the item
        GroceryItem *item = &inventory->items[i];
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n\n", item->inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity(GroceryInventory *inventory) { //update the quantity
    char name[100];
    printf("Enter name of the grocery item to update quantity: ");
    getchar(); // Consume leftover newline character
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < inventory->itemCount; i++) {
        GroceryItem *item = &inventory->items[i];
        if (strcmp(item->name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &item->quantity);
            item->inStock = item->quantity > 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n"); //if there's nothing on inventory
}

void removeGroceryItem(GroceryInventory *inventory) { //remove item
    char name[100];
    printf("Enter name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            // Shift remaining items to overwrite the removed item
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->itemCount--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("Item '%s' not found in inventory.\n", name); //if there's no item that you input on inventory
}


