#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure Definitions
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int isAvailable; // 1 for available, 0 for not available
} Item;

// Global Variables
Item items[MAX_ITEMS];
int totalItems = 0;

// Function Declarations
void addNewItem();
void showItems();
void modifyQuantity();
void deleteItem();
void menu();

int main() {
    int option;

    do {
        menu();
        scanf("%d", &option);
        getchar(); // Flush newline

        switch (option) {
            case 1:
                addNewItem();
                break;
            case 2:
                showItems();
                break;
            case 3:
                modifyQuantity();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 5);

    return 0;
}

void menu() {
    printf("\nInventory System:\n");
    printf("1. Add New Item\n");
    printf("2. Display All Items\n");
    printf("3. Update Item Quantity\n");
    printf("4. Remove an Item\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addNewItem() {
    if (totalItems >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    strtok(newItem.name, "\n");

    printf("Enter category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    strtok(newItem.category, "\n");

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    newItem.isAvailable = newItem.quantity > 0 ? 1 : 0;

    items[totalItems] = newItem;
    totalItems++;
    printf("Item added successfully.\n");
}

void showItems() {
    if (totalItems == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("%-20s %-15s %-10s %-10s %-10s\n", "Name", "Category", "Quantity", "Price", "Availability");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < totalItems; i++) {
        printf("%-20s %-15s %-10d %-10.2f %-10s\n",
               items[i].name,
               items[i].category,
               items[i].quantity,
               items[i].price,
               items[i].isAvailable ? "Available" : "Unavailable");
    }
}

void modifyQuantity() {
    char searchName[100];
    int newQuantity;

    if (totalItems == 0) {
        printf("No items to update.\n");
        return;
    }

    printf("Enter the name of the item to update: ");
    fgets(searchName, sizeof(searchName), stdin);
    strtok(searchName, "\n");

    for (int i = 0; i < totalItems; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);

            items[i].quantity = newQuantity;
            items[i].isAvailable = newQuantity > 0;

            printf("Item updated successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

void deleteItem() {
    char searchName[100];

    if (totalItems == 0) {
        printf("No items to delete.\n");
        return;
    }

    printf("Enter the name of the item to remove: ");
    fgets(searchName, sizeof(searchName), stdin);
    strtok(searchName, "\n");

    for (int i = 0; i < totalItems; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            for (int j = i; j < totalItems - 1; j++) {
                items[j] = items[j + 1];
            }
            totalItems--;
            printf("Item removed successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}
