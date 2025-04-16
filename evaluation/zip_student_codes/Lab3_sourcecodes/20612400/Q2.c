#include <stdio.h>
#include <string.h>

#define MAX 100
#define BUFFER_SIZE 100

typedef struct {
    char name[BUFFER_SIZE];
    char category[50];
    int quantity;
    float price;
    int inStock; 
} Item;

Item inventory[MAX];
int itemCount = 0;

void addItem();
void displayItems();
void updateQuantity();
void removeGroceryItem();

int main() {
    int choice;

    do {
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
                displayItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeGroceryItem();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

void addItem() {
    if (itemCount >= MAX) {
        printf("Inventory is full.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");

    getchar();

    fgets(newItem.name, sizeof(newItem.name), stdin);
    strtok(newItem.name, "\n"); 

    printf("Enter category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    strtok(newItem.category, "\n"); 

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    newItem.inStock = (newItem.quantity > 0) ? 1 : 0;

    inventory[itemCount++] = newItem;
    printf("Item added successfully.\n");
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\nInventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. Name: %s, Category: %s, Quantity: %d, Price: %.2f, Status: %s\n",
               i + 1, inventory[i].name, inventory[i].category, inventory[i].quantity,
               inventory[i].price, inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity() {
    char name[100];
    printf("Enter the name of the item to update: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); 

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);

            inventory[i].inStock = (inventory[i].quantity > 0) ? 1 : 0;

            printf("Quantity updated successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

void removeGroceryItem() {
    char name[100];
    printf("Enter the name of the item to remove: ");

    getchar(); 

    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); 

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }

            itemCount--;
            printf("Item removed successfully.\n");
            
            return;
        }
    }

    printf("Item not found.\n");
}
