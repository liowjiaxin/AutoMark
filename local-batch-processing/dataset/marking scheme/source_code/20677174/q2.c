#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct{
    char name[101]; // Max length 100 !! Additional 1 space is included to store NULL terminator in case of max length
    char category[51]; // Max length 50
    int quantity; // Quantity of the grocery item
    float price; // Price of the grocery item
} groceryItem;

typedef union { // Use union to represent the availabilityStatus to save space. Only inStock is accessed in all operations
    int inStock;
    int outOfStock;
} availabilityStatus;

typedef struct {
    groceryItem groceryItems[MAX_SIZE]; // Array of grocery items
    availabilityStatus status [MAX_SIZE]; // Array of availability status
    int count; // Total number of grocery items in the system
} groceryInventory;

void addGroceryItem(groceryInventory * inventory) {
    if ((*inventory).count >= MAX_SIZE) { // Check if the inventory is already full before adding
        printf("Inventory full. Unable to add new grocery items anymore.\n\n");
        return;
    }
    // Get name of new item
    printf("Enter Item Name: ");
    fgets((*inventory).groceryItems[(*inventory).count].name, 101, stdin);
    // Get category of new item
    printf("Enter Category: ");
    fgets((*inventory).groceryItems[(*inventory).count].category, 51, stdin);
    // Get quantity of new item
    printf("Enter Quantity: ");
    scanf("%d", &(*inventory).groceryItems[(*inventory).count].quantity);
    // Set the availability status of the new item based on the quantity
    if ((*inventory).groceryItems[(*inventory).count].quantity == 0) {
        (*inventory).status[(*inventory).count].inStock = 0;
    } else {
        (*inventory).status[(*inventory).count].inStock = 1;
    }
    // Get price of new item
    printf("Enter Price: ");
    scanf("%f", &(*inventory).groceryItems[(*inventory).count].price);
    ++(*inventory).count;
    printf("Grocery item added successfully!\n\n");
}

void listGroceryItems(groceryInventory * inventory) {
    if ((*inventory).count == 0) { // Check if the inventory is empty before displaying all items
        printf("No grocery items in the inventory.\n\n");
        return;
    }
    for (int i = 0; i < (*inventory).count; ++i){
        printf("Name: %s", (*inventory).groceryItems[i].name); // Print the name
        printf("Category: %s", (*inventory).groceryItems[i].category); // Print the category
        printf("Quantity: %d\n", (*inventory).groceryItems[i].quantity); // Print the quantity
        printf("Price: %.2f\n", (*inventory).groceryItems[i].price); // Print the quantity
        if ((*inventory).status[i].inStock) {
            printf("Status: In Stock\n\n");
        } else {
            printf("Status: Out of Stock\n\n");
        }
    }
}

void updateQuantity(groceryInventory * inventory) {
    if ((*inventory).count == 0) { // Check if the inventory is empty before allowing user to update quantity
        printf("No grocery items in the inventory.\n\n");
        return;
    }
    char target[101];
    int newQuantity;
    printf("Enter name of the grocery item to update quantity: ");
    fgets(target, 101, stdin);
    for (int i = 0; i < (*inventory).count; ++i) {
        if (strcmp(target, (*inventory).groceryItems[i].name) == 0) {
            target[strcspn(target, "\n")] = '\0';
            printf("Enter new quantity for %s: ", target);
            scanf("%d", &newQuantity);
            (*inventory).groceryItems[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n\n");
            // Reset the availability status accordingly
            if ((*inventory).groceryItems[i].quantity <= 0) {
                (*inventory).status[i].inStock = 0;
            } else {
                (*inventory).status[i].inStock = 1;
            }
            return;
        }
    }
    printf("Grocery item not found.\n\n");
}

void removeGroceryItem(groceryInventory * inventory) {
    if ((*inventory).count == 0) { // Check if the inventory is empty before allowing user to remove grocery
        printf("No grocery items in the inventory.\n\n");
        return;
    }
    char target[101];
    printf("Enter name of the grocery item to remove: ");
    fgets(target, 101, stdin);
    for (int i = 0; i < (*inventory).count; ++i) {
        if (strcmp(target, (*inventory).groceryItems[i].name) == 0) {
            target[strcspn(target, "\n")] = '\0';
            printf("Grocery item '%s' removed successfully!\n\n", target);
            // Move backwards 1 position for all the remaining grocery items located after the removed grocery item
            // Move backwards 1 position for all the remaining status located after the status of the removed grocery item
            // Remaining grocery items that must stay = (*inventory).count - 1 - i, where i is index of grocery item to be removed
            memcpy((*inventory).groceryItems + i, (*inventory).groceryItems + i + 1, sizeof(groceryItem) * ((*inventory).count - 1 - i));
            memcpy((*inventory).status + i, (*inventory).status + i + 1, sizeof(availabilityStatus) * ((*inventory).count - 1 - i));
            --(*inventory).count;
            return;
        }
    }
    printf("Grocery item not found.\n\n");
}

int main (void) {
    groceryInventory inventory; // Create a new inventory
    inventory.count = 0; // Initialise count to 0

    int choice; // Store the choice of the user about which operation to perform
    do{
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the remaining newline '\n' in input buffer
        // Pass the inventory by reference to modify or use it directly
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
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please input again\n");
        }
    } while (choice != 5);
    return 0;
}