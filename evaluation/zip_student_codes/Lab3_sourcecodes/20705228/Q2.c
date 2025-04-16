#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100

// define struct
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int inStock; 
} GroceryItem;

// set global variables
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

// set functions
void addGroceryItem();
void listAllItems();
void updateQuantity();
void removeGroceryItem();

int main() {
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
        getchar(); 

        switch (choice) {
            case 1:
                addGroceryItem();
                break;
            case 2:
                listAllItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeGroceryItem();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addGroceryItem() {
    // check if the stock is full
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem item; 

    // get the item name
    printf("Enter Item Name: ");
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = 0; 

    // get the item category
    printf("Enter Category: ");
    fgets(item.category, sizeof(item.category), stdin);
    item.category[strcspn(item.category, "\n")] = 0; 

    // get the item quantity
    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);

    // get the item price
    printf("Enter Price: ");
    scanf("%f", &item.price);
    getchar(); // 清理输入缓冲区

    // set the stock status
    item.inStock = item.quantity > 0 ? 1 : 0;

    // increase the item counter
    inventory[itemCount++] = item;
    printf("Grocery item added successfully!\n");
}

void listAllItems() {
    // check if the stock is empty
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        printf("\nName: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity() {
    char name[100]; 
    int found = 0; 

    printf("Enter the name of the item to update: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; 

    // search for the related item
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            getchar(); 

            // update the stock status
            inventory[i].inStock = inventory[i].quantity > 0 ? 1 : 0;
            printf("Quantity updated successfully!\n");
            found = 1; 
            break;
        }
    }

    // if can't find the item
    if (!found) {
        printf("Item not found in the inventory.\n");
    }
}

void removeGroceryItem() {
    char name[100]; 
    int found = 0; 

    printf("Enter the name of the item to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; 

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // cover the deleted item
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--; // decrease the stock counter
            printf("Item removed successfully!\n");
            found = 1; 
            break;
        }
    }

    if (!found) {
        printf("Item not found in the inventory.\n");
    }
}
