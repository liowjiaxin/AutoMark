#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

//ftruct to hold grocery item information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} GroceryItem;

//struct to hold availability status
typedef struct {
    int inStock;
    int outOfStock;
} AvailabilityStatus;

//struct to hold the grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

//declare all the below functions here
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateGroceryItemQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = { .itemCount = 0 };
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //takes away newline character so input buffer is cleared otherwise everything gets jumbled up

        // Perform the selected operation using a switch case
        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateGroceryItemQuantity(&inventory);
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

// Function to add a grocery item to the inventory
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->itemCount];
    AvailabilityStatus *status = &inventory->status[inventory->itemCount];

    printf("Enter item name: ");
    fgets(item->name, MAX_NAME_LENGTH, stdin);
    item->name[strcspn(item->name, "\n")] = '\0'; // Remove newline character

    printf("Enter item category: ");
    fgets(item->category, MAX_CATEGORY_LENGTH, stdin);
    item->category[strcspn(item->category, "\n")] = '\0'; // Remove newline character

    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
    getchar(); // Consume newline character  so input buffer is cleared 

    printf("Enter item price: ");
    scanf("%f", &item->price);
    getchar(); // Consume newline character

    // Set availability status based on quantity
    status->inStock = item->quantity > 0;
    status->outOfStock = item->quantity == 0;

    inventory->itemCount++;
    printf("Item added successfully.\n");
}

// Function to list all grocery items with their availability
void listGroceryItems(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) {
        GroceryItem *item = &inventory->items[i];
        AvailabilityStatus *status = &inventory->status[i];

        printf("Item Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateGroceryItemQuantity(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    int index;
    printf("Enter the item number to update quantity: ");
    scanf("%d", &index);
    getchar(); // Consume newline character

    if (index < 1 || index > inventory->itemCount) {
        printf("Invalid item number.\n");
        return;
    }

    GroceryItem *item = &inventory->items[index - 1];
    AvailabilityStatus *status = &inventory->status[index - 1];

    printf("Enter new quantity for %s: ", item->name);
    scanf("%d", &item->quantity);
    getchar(); // Consume newline character

    // Update availability status based on new quantity
    status->inStock = item->quantity > 0;
    status->outOfStock = item->quantity == 0;

    printf("Quantity updated successfully!\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    int index;
    printf("Enter the item number to remove: ");
    scanf("%d", &index);
    getchar(); // Consume newline character so  input buffer is cleared 

    if (index < 1 || index > inventory->itemCount) {
        printf("Invalid item number.\n");
        return;
    }

    // Shift items to fill the gap
    for (int i = index - 1; i < inventory->itemCount - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
        inventory->status[i] = inventory->status[i + 1];
    }

    inventory->itemCount--;
    printf("Item removed successfully.\n");
}