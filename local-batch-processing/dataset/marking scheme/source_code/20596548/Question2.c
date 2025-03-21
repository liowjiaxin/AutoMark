#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    int itemCount;
} Inventory;

// Function prototypes
void addGroceryItem(Inventory *inv);
void listGroceryItems(const Inventory *inv);
void updateQuantity(Inventory *inv);
void removeGroceryItem(Inventory *inv);

int main() {
    Inventory inv = {{}, 0}; // Initialize empty inventory
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGroceryItem(&inv);
                break;
            case 2:
                listGroceryItems(&inv);
                break;
            case 3:
                updateQuantity(&inv);
                break;
            case 4:
                removeGroceryItem(&inv);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Add a new grocery item to inventory
void addGroceryItem(Inventory *inv) {
    if (inv->itemCount < MAX_ITEMS) {
        GroceryItem item;
        printf("Enter item name: ");
        scanf(" %[^\n]", item.name); // Read full line for string input
        printf("Enter item category: ");
        scanf(" %[^\n]", item.category);
        printf("Enter quantity: ");
        scanf("%d", &item.quantity);
        printf("Enter price: ");
        scanf("%f", &item.price);

        inv->items[inv->itemCount++] = item; // Add item to inventory
    } else {
        printf("Inventory is full! Cannot add more items.\n");
    }
}

// List all grocery items with their details
void listGroceryItems(const Inventory *inv) {
    if (inv->itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }
    printf("Grocery Inventory:\n");
    for (int i = 0; i < inv->itemCount; i++) {
        printf("Name: %s, Category: %s, Quantity: %d, Price: %.2f\n",
               inv->items[i].name, inv->items[i].category,
               inv->items[i].quantity, inv->items[i].price);
    }
}

// Update the quantity of an existing grocery item
void updateQuantity(Inventory *inv) {
    char name[100];
    printf("Enter item name to update quantity: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < inv->itemCount; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inv->items[i].quantity);
            return;
        }
    }
    printf("Item not found.\n");
}

// Remove a grocery item from the inventory
void removeGroceryItem(Inventory *inv) {
    char name[100];
    printf("Enter item name to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < inv->itemCount; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            for (int j = i; j < inv->itemCount - 1; j++) {
                inv->items[j] = inv->items[j + 1]; // Shift items
            }
            inv->itemCount--;
            return;
        }
    }
    printf("Item not found.\n");
}
