#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// struct for grocery item
typedef struct {
    char name[100], category[50];
    int quantity;
    float price;
    int in_stock;  
} GroceryItem;

// struct for grocery inv
typedef struct {
    GroceryItem items[MAX_ITEMS];
    int total_items;
} GroceryInv;

// fucntion for menu commmands
void addGroceryItem(GroceryInv *inv);
void listGroceryItems(const GroceryInv *inv);
void updateQuantity(GroceryInv *inv);
void displayMenu();

int main() {
    GroceryInv inv = {0};
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) addGroceryItem(&inv);
        else if (choice == 2) listGroceryItems(&inv);
        else if (choice == 3) updateQuantity(&inv);
        else if (choice == 4) removeGroceryitem(&inv);
        else if (choice == 5) break;
        else printf("Invalid choice! Try again.\n");
    }

    printf("Exiting...\n");
    return 0;
}

// menu
void displayMenu() {
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    rpintf("Remove grocery Item\n");// it doesnt workkkkk
    printf("5. Exit\n");
}

// Add a new grocery item
void addGroceryItem(GroceryInv *inv) {
    if (inv->total_items >= MAX_ITEMS) {
        printf("Inventory full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;
    printf("Enter Item Name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter Category: ");
    scanf(" %[^\n]", newItem.category);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    newItem.in_stock = (newItem.quantity > 0);  
    inv->items[inv->total_items++] = newItem;
    printf("Grocery item added successfully!\n");
}

// List all grocery items
void listGroceryItems(const GroceryInv *inv) {
    if (!inv->total_items) {
        printf("No items in inv.\n");
        return;
    }

    for (int i = 0; i < inv->total_items; i++) {
        GroceryItem item = inv->items[i];
        printf("\nName: %s\nCategory: %s\nQuantity: %d\nPrice: %.2f\nStatus: %s\n", 
               item.name, item.category, item.quantity, item.price, 
               item.in_stock ? "In Stock" : "Out of Stock");
    }
}

// Update the quantity of gorcery items
void updateQuantity(GroceryInv *inv) {
    char itemName[100];
    printf("Enter name of the grocery item to update quantity: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < inv->total_items; i++) {
        if (strcmp(inv->items[i].name, itemName) == 0) {
            printf("Enter new quantity for %s: ", itemName);
            scanf("%d", &inv->items[i].quantity);
            return;
        }
    }

    printf("Item not found!\n");
}
