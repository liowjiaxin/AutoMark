#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100

//Struct for grocery items
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int inStock;
} GroceryItem;

GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

//Function
void addItem();
void listItems();
void updateQuantity();
void removeItem();

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
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem item;

    printf("Enter item name: ");
    getchar();
    fgets(item.name, sizeof(item.name), stdin);
    strtok(item.name, "\n");

    printf("Enter item category: ");
    fgets(item.category, sizeof(item.category), stdin);
    strtok(item.category, "\n");

    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter item price: ");
    scanf("%f", &item.price);

    item.inStock = (item.quantity > 0) ? 1 : 0;

    inventory[itemCount++] = item;
    printf("Item added successfully!\n");
}

void listItems() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    char itemName[100];
    printf("Enter name of the grocery item to update quantity: ");
    getchar();
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcasecmp(inventory[i].name, itemName) == 0) {
            int newQuantity;
            printf("Enter new quantity for %s: ", inventory[i].name);
            scanf("%d", &newQuantity);

            inventory[i].quantity = newQuantity;
            inventory[i].inStock = (newQuantity > 0) ? 1 : 0;

            printf("Quantity updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found in inventory.\n");
    }
}

void removeItem() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    char itemName[100];
    printf("Enter name of the grocery item to remove: ");
    getchar();
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcasecmp(inventory[i].name, itemName) == 0) {
            printf("Grocery item '%s' removed successfully!\n", inventory[i].name);
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found in inventory.\n");
    }
}
