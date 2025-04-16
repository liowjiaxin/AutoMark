#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100

// Structure to represent a grocery item
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int inStock;
} GroceryItem;

GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void addItem();
void listItems();
void updateQuantity();
void removeItem();

int main() {
    int choice;

    // Menu for managing the grocery inventory
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Function to add a new item to the inventory
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full!\n");
        return;
    }
    printf("Enter item name: ");
    scanf(" %[^
]", inventory[itemCount].name);
    printf("Enter category: ");
    scanf(" %[^
]", inventory[itemCount].category);
    printf("Enter quantity: ");
    scanf("%d", &inventory[itemCount].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[itemCount].price);

    inventory[itemCount].inStock = (inventory[itemCount].quantity > 0) ? 1 : 0;
    itemCount++;
    printf("Item added successfully!\n");
}

// Function to list all items in the inventory
void listItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("Inventory List:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s, Category: %s, Quantity: %d, Price: %.2f, Status: %s\n",
               inventory[i].name, inventory[i].category, inventory[i].quantity,
               inventory[i].price, inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of an item
void updateQuantity() {
    char name[100];
    int newQuantity;

    printf("Enter the name of the item to update: ");
    scanf(" %[^
]", name);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            inventory[i].inStock = (newQuantity > 0) ? 1 : 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

// Function to remove an item from the inventory
void removeItem() {
    char name[100];

    printf("Enter the name of the item to remove: ");
    scanf(" %[^
]", name);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}
