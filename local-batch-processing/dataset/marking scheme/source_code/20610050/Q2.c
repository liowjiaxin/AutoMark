
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
    int inStock; // 1 if in stock, 0 if out of stock
} AvailabilityStatus;
GroceryItem inventory[MAX_ITEMS];
AvailabilityStatus availability[MAX_ITEMS];
int itemCount = 0;
void addItem();
void listItems();
void updateQuantity();
void removeItem();
void printItem(int index);

int main() {
    int choice;

    do {
        printf("\nGrocery Inventory Management\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    printf("Enter item name: ");
    fgets(inventory[itemCount].name, sizeof(inventory[itemCount].name), stdin);
    strtok(inventory[itemCount].name, "\n"); 
 printf("Enter item category: ");
    fgets(inventory[itemCount].category, sizeof(inventory[itemCount].category), stdin);
    strtok(inventory[itemCount].category, "\n");

    printf("Enter item quantity: ");
    scanf("%d", &inventory[itemCount].quantity);

    printf("Enter item price: ");
    scanf("%f", &inventory[itemCount].price);
    getchar(); 
    availability[itemCount].inStock = (inventory[itemCount].quantity > 0) ? 1 : 0;

    itemCount++;
    printf("Item added successfully.\n");
}
void listItems() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nGrocery Inventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printItem(i);
    }
}
void updateQuantity() {
    char itemName[100];
    int newQuantity;

    printf("Enter the name of the item to update: ");
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            getchar(); // Consume newline character

            inventory[i].quantity = newQuantity;
            availability[i].inStock = (newQuantity > 0) ? 1 : 0;

            printf("Quantity updated successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}
void removeItem() {
    char itemName[100];

    printf("Enter the name of the item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
                availability[j] = availability[j + 1];
            }
            itemCount--;
            printf("Item removed successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}
void printItem(int index) {
    printf("Name: %s\n", inventory[index].name);
    printf("Category: %s\n", inventory[index].category);
    printf("Quantity: %d\n", inventory[index].quantity);
    printf("Price: %.2f\n", inventory[index].price);
    printf("Status: %s\n", availability[index].inStock ? "In Stock" : "Out of Stock");
}
