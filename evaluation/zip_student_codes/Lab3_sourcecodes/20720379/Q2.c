#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Define a boolean type for convenience
typedef enum { FALSE, TRUE } bool;

// Define a struct for Availability Status
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Define a struct for a Grocery Item
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
    AvailabilityStatus availability;
} GroceryItem;

// Define a struct for Grocery Inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    int totalItems;
} GroceryInventory;

// Function Declarations
void addGroceryItem(GroceryInventory* inventory);
void listGroceryItems(const GroceryInventory* inventory);
void updateQuantity(GroceryInventory* inventory);
void removeGroceryItem(GroceryInventory* inventory);
void displayMenu();

int main() {
    GroceryInventory inventory = { .totalItems = 0 };
    int choice;

    do {
        displayMenu();
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nGrocery Inventory Management\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

// Function to add a new grocery item to the inventory
void addGroceryItem(GroceryInventory* inventory) {
    if (inventory->totalItems >= MAX_ITEMS) {
        printf("Inventory is full, cannot add more items.\n");
        return;
    }

    GroceryItem newItem;

    // Input the name of the item
    printf("Enter item name: ");
    getchar(); // To clear the newline character from the buffer
    fgets(newItem.name, MAX_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline character

    // Input the category
    printf("Enter category: ");
    fgets(newItem.category, MAX_CATEGORY_LENGTH, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0'; // Remove newline character

    // Input the quantity
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    // Input the price
    printf("Enter price: ");
    scanf("%f", &newItem.price);

    // Determine availability based on quantity
    if (newItem.quantity > 0) {
        newItem.availability.inStock = TRUE;
        newItem.availability.outOfStock = FALSE;
    } else {
        newItem.availability.inStock = FALSE;
        newItem.availability.outOfStock = TRUE;
    }

    // Add the new item to the inventory
    inventory->items[inventory->totalItems] = newItem;
    inventory->totalItems++;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items with their availability status
void listGroceryItems(const GroceryInventory* inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\nList of Grocery Items:\n");
    for (int i = 0; i < inventory->totalItems; i++) {
        const GroceryItem* item = &inventory->items[i];
        printf("\nItem %d:\n", i + 1);
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Availability: %s\n", item->availability.inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a specific grocery item
void updateQuantity(GroceryInventory* inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }

    int itemIndex;
    printf("Enter the name of the grocery item to update quantity: ", inventory->totalItems);
    scanf("%d", &itemIndex);
    
    if (itemIndex < 1 || itemIndex > inventory->totalItems) {
        printf("Invalid item index.\n");
        return;
    }

    itemIndex--; // Convert to 0-based index

    int newQuantity;
    printf("Enter the new quantity for item '%s': ", inventory->items[itemIndex].name);
    scanf("%d", &newQuantity);

    inventory->items[itemIndex].quantity = newQuantity;

    // Update availability based on new quantity
    if (newQuantity > 0) {
        inventory->items[itemIndex].availability.inStock = TRUE;
        inventory->items[itemIndex].availability.outOfStock = FALSE;
    } else {
        inventory->items[itemIndex].availability.inStock = FALSE;
        inventory->items[itemIndex].availability.outOfStock = TRUE;
    }

    printf("Quantity updated successfully!\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(GroceryInventory* inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in the inventory to remove.\n");
        return;
    }

    int itemIndex;
    printf("Enter the index of the item to remove (1 to %d): ", inventory->totalItems);
    scanf("%d", &itemIndex);
    
    if (itemIndex < 1 || itemIndex > inventory->totalItems) {
        printf("Invalid item index.\n");
        return;
    }

    itemIndex--; // Convert to 0-based index

    // Shift items after the removed one to fill the gap
    for (int i = itemIndex; i < inventory->totalItems - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
    }

    // Decrease the item count
    inventory->totalItems--;

    printf("Grocery item removed successfully!\n");
}
