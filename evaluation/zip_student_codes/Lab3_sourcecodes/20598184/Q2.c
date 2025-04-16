#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ITEM 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 100

// struct to hold grocery information
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

// struct to hold availability status
typedef struct {
    bool inStock;
    bool outOfStock;
} StockAvailability;

// struct to hold inventory
typedef struct {
    GroceryItem item[MAX_ITEM];
    StockAvailability availability[MAX_ITEM];
    int itemCounter;
} Inventory;

//Calling functions
void AddGrocery(Inventory *inventory);
void listGrocery(Inventory *inventory);
void updateGrocery(Inventory *inventory);
void removeGrocery(Inventory *inventory);

int main() {
    Inventory inventory = {{0}, {{false, false}}, 0};
    int choice;

    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            AddGrocery(&inventory);
            break;

        case 2:
            listGrocery(&inventory);
            break;

        case 3:
            updateGrocery(&inventory);
            break;

        case 4:
            removeGrocery(&inventory);
            break;
        
        case 5:
            printf("Exiting...\n");
            break;
        
        default:
            printf("Invalid choice. Please try again. \n");
        }
    } while (choice != 5);

    return 0;
}

// Implementing functons 
// Adding grocery function
void AddGrocery(Inventory *inventory) {
    if (inventory->itemCounter >= MAX_ITEM) {
        printf("Inventory is full! Adding items unavailable. \n");
        return;
    }

    GroceryItem newItem;
    printf("Enter Item Name: ");
    fgets(newItem.name, MAX_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // removes newline created by fgets

    printf("Enter Category: ");
    fgets(newItem.category, MAX_CATEGORY_LENGTH, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0'; // rmeoves newline created by fgets

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    getchar(); // removes newline created by scanf

    // assigning item to invenetory
    inventory->item[inventory->itemCounter] = newItem;
    inventory->availability[inventory->itemCounter].inStock = (newItem.quantity > 0);
    inventory->availability[inventory->itemCounter].outOfStock = (newItem.quantity == 0);
    inventory->itemCounter++;

    printf("Grocery item added successfully! \n");
}

// Listing feature
void listGrocery(Inventory *inventory) {
    if (inventory->itemCounter == 0) {
        printf("\nNo items found.\n");
        return;
    }

    printf("\nGrocery Stock Inventory: \n");
    for (int i = 0; i < inventory->itemCounter; i++) {
        printf("Name: %s\n", inventory->item[i].name);
        printf("Category: %s\n", inventory->item[i].category);
        printf("Quantity: %d\n", inventory->item[i].quantity);
        printf("Price: %.2f\n", inventory->item[i].price);
        if (inventory->availability[i].inStock) {
            printf("Status: In Stock\n");
        } else if (inventory->availability[i].outOfStock) {
            printf("Status: Out of Stock\n");
        }
        printf("\n");
    }
}

// Updating grocery function
void updateGrocery(Inventory *inventory) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // removes newline created

    for (int i = 0; i < inventory->itemCounter; i++) {
        if (strcmp(inventory->item[i].name, name) == 0) {
            printf("Enter the new quantity: ");
            int newQuantity;
            scanf("%d", &newQuantity);
            getchar(); // removes newline

            inventory->item[i].quantity = newQuantity;
            inventory->availability[i].inStock = (newQuantity > 0);
            inventory->availability[i].outOfStock = (newQuantity == 0);
            
            printf("Quantity updated successfully! \n");
        }
    }
}

// Remove Grocery Function
void removeGrocery(Inventory *inventory) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the grocery item to remove: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // removes newline

    for (int i = 0; i < inventory->itemCounter; i++) {
        if (strcmp(inventory->item[i].name, name) == 0) {
            // Moves every items up one slot after deletion
            for (int j = 0; j < inventory->itemCounter - 1; j++) {
                inventory->item[j] = inventory->item[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
            inventory->itemCounter--;
            printf("Grocery item '%s' removed successfully\n", name);
            return;
        }
    }

    printf("Item not found in inventory. \n");
}
 