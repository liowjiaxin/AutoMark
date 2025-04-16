#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// Defining structures for Grocery Item and Availability Status
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} grocery_item;

typedef struct {
    bool in_stock;
    bool outOfStock;
} availability_status;

typedef struct {
    grocery_item items[MAX_ITEMS];
    availability_status status[MAX_ITEMS];
    int count;
} grocery_inventory;

// Function prototypes
void addGroceryItem(grocery_inventory *inventory);
void listGroceryItems(grocery_inventory inventory);
void updateQuantity(grocery_inventory *inventory);
void removeGroceryItem(grocery_inventory *inventory);

int main() {
    grocery_inventory inventory = { .count = 0 };
    int choice;

    do {
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
                listGroceryItems(inventory);
                break;
            case 3:
                updateQuantity(&inventory);
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
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item
void addGroceryItem(grocery_inventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    grocery_item *item = &inventory->items[inventory->count];
    printf("Enter Item Name: ");
    fgets(item->name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = '\0';

    printf("Enter Category: ");
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter Price: ");
    scanf("%f", &item->price);
    getchar(); 

    availability_status *status = &inventory->status[inventory->count];
    status->in_stock = item->quantity > 0;
    status->outOfStock = item->quantity == 0;

    inventory->count++;
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listGroceryItems(grocery_inventory inventory) {
    if (inventory.count == 0) {
        printf("No grocery items in the inventory\n");
        return;
    }

    for (int i = 0; i < inventory.count; i++) {
        grocery_item item = inventory.items[i];
        availability_status status = inventory.status[i];

        printf("\nItem Name: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Status: %s\n", status.in_stock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(grocery_inventory *inventory) {
    char name[100];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory->items[i].quantity);
            getchar();

            inventory->status[i].in_stock = inventory->items[i].quantity > 0;
            inventory->status[i].outOfStock = inventory->items[i].quantity == 0;

            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Grocery item not found!\n");
}

// Function to remove a grocery item
void removeGroceryItem(grocery_inventory *inventory) {
    char name[100];
    printf("Enter name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

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
    printf("Grocery item not found!\n");
}
