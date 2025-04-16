#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the Grocery Item structure
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

// Define the Availability Status union
typedef union {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Define the Grocery Inventory structure
typedef struct {
    GroceryItem items[100];
    AvailabilityStatus status[100];
    int itemCount;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory;
    inventory.itemCount = 0;
    int choice;

    do {
        // Menu
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= 100) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem item;
    printf("Enter Item Name: ");
    getchar(); // Consume the newline character left by previous input
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = '\0'; // Remove the newline character

    printf("Enter Category: ");
    fgets(item.category, sizeof(item.category), stdin);
    item.category[strcspn(item.category, "\n")] = '\0'; // Remove the newline character

    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter Price: ");
    scanf("%f", &item.price);


    inventory->items[inventory->itemCount] = item;
    inventory->status[inventory->itemCount].inStock = item.quantity > 0;
    inventory->itemCount++;

    printf("Item added successfully.\n");
}

// Function to list all grocery items with their availability
void listGroceryItems(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("\nGrocery Items:\n");
    for (int i = 0; i < inventory->itemCount; i++) {
        GroceryItem item = inventory->items[i];
        printf("Name: %s \nCategory: %s \nQuantity: %d \nPrice: %.2f \nStatus: %s \n",
               item.name, item.category, item.quantity, item.price,
               inventory->status[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory) {
    char name[100];
    printf("Enter the name of the grocery item to update quantity: ");
    getchar(); // Consume the newline character left by previous inputs
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcasecmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", inventory->items[i]);
            scanf("%d", &inventory->items[i].quantity);
            inventory->status[i].inStock = inventory->items[i].quantity > 0;
            printf("Quantity updated successfully.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(GroceryInventory *inventory) {
    char Deletename[100];
    printf("Enter name of the item to remove: ");
    getchar(); // Consume the newline character left by previous inputs
    fgets(Deletename, sizeof(Deletename), stdin);
    Deletename[strcspn(Deletename, "\n")] = '\0'; // Remove the newline character

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcasecmp(inventory->items[i].name, Deletename) == 0) {
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }
            inventory->itemCount--;
            printf("Grocery item '%s' removed successfully\n", Deletename);
            return;
        }
    }

    printf("Item not found.\n");
}