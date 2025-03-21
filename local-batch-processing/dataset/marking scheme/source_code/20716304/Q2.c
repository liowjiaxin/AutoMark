#include <stdio.h>
#include <string.h>

// Define all the maximum length
#define MAX_NAME 101
#define MAX_CATEGORY 51
#define MAX_ITEMS 100

// Define three struct for store data
typedef struct {
    char name[MAX_NAME];
    char category[MAX_CATEGORY];
    int quantity;
    float price;
} Grocery_Item;

typedef struct{
    int in_stock;   // 1 = in stock, 0 = out of stock
} Availability_Status;

typedef struct {
    Grocery_Item items[MAX_ITEMS];
    Availability_Status status[MAX_ITEMS];
    int total_item;
} Grocery_Inventory;

// Function to display the menu and get option
int menu() {
    int option;
    printf("\nGrocery Inventory Management System\n");
    while (1) {
        printf("1. Add Grocery Item\n2. List All Grocery Items\n3. Update Quantity\n4. Remove Grocery Item\n5. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d", &option) != 1 || option <= 0 || option > 5) {
            printf("Invalid input. Enter again\n\n");
            while (getchar() != '\n');
        } else {
            while (getchar() != '\n');
            break;
        }
    }  
    return option;
}

// Function to add an item to the inventory
void add_items(Grocery_Inventory* inventory) {
    // If there are 100 items(max)
    if (inventory->total_item >= MAX_ITEMS) {
        printf("Inventory is full\n");
        return;
    } else {
        Grocery_Item new_item;
        // Get user input
        printf("Enter Item Name: ");
        fgets(new_item.name, MAX_NAME, stdin);
        new_item.name[strcspn(new_item.name, "\n")] = 0;    // Delete \n

        printf("Enter Category: ");
        fgets(new_item.category, MAX_CATEGORY, stdin);
        new_item.category[strcspn(new_item.category, "\n")] = 0;

        printf("Enter Quantity: ");
        while (1) {
            if (scanf("%d", &new_item.quantity) != 1 || new_item.quantity < 0) {
                printf("Invalid quantity. Enter again: ");
                while (getchar() != '\n');  // Clear buffer
            } else {
                break;
            }
        }
        
        printf("Enter Price: ");
        while (1) {
            if (scanf("%f", &new_item.price) != 1 || new_item.price < 0.0) {
                printf("Invalid price. Enter again: ");
                while (getchar() != '\n');  // Clear buffer
            } else {
                break;
            }
        }     

        while (getchar() != '\n'); // Clear the input buffer
        // Update inventory with the input item
        inventory->items[inventory->total_item] = new_item; 
        inventory->status[inventory->total_item].in_stock = (new_item.quantity > 0) ? 1 : 0; 
        inventory->total_item++;
        printf("Grocery item added successfully!\n");
    }
    
}

// Function to display all the items
void list_items(Grocery_Inventory* inventory) {
    // If there is no items
    if (inventory->total_item == 0) {
        printf("There is no items.\n");
        return;
    }
    // For loop to display all the items
    for (int i = 0; i < inventory->total_item; i++) {
        printf("\nName: %s\nCategory: %s\nQuantity: %d\nPrice: %.2f\nStatus: %s", 
        inventory->items[i].name, 
        inventory->items[i].category,
        inventory->items[i].quantity,
        inventory->items[i].price,
        inventory->status[i].in_stock ? "In Stock" : "Out of Stock");
        puts("");
    }
}

// Function to update the item quantity
void update_quantity(Grocery_Inventory* inventory) {
    // If there is no items
    if (inventory->total_item == 0) {
        printf("There is no items\n");
        return;
    }
    char finding[MAX_NAME];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(finding, MAX_NAME, stdin);
    finding[strcspn(finding, "\n")] = 0;
    // Find the matching item in the inventory
    for (int i = 0; i < inventory->total_item; i++) {
        // If there is matching item
        if (strcmp(inventory->items[i].name, finding) == 0) {
            printf("Enter new quantitiy for %s: ", finding);
            scanf("%d", &inventory->items[i].quantity);
            inventory->status[i].in_stock = (inventory->items[i].quantity > 0) ? 1 : 0; // Indicates "in stock" or "out of stock"
            printf("Quantity updated successfully!\n");
            while (getchar() != '\n');
            return;
        }
    }
    printf("Item not found\n");
}

// Function to remove item from the inventory
void remove_item(Grocery_Inventory* inventory) {
    // If there is no items
    if (inventory->total_item == 0) {
        printf("There is no items\n");
        return;
    }
    // Get user input
    char finding[MAX_NAME];
    printf("Enter name of the grocery item to remove: ");
    fgets(finding, MAX_NAME, stdin);
    finding[strcspn(finding, "\n")] = 0;
    // Search for the matching item in the inventory
    for (int i = 0; i < inventory->total_item; i++) {
        // Search for the matching item
        if (strcmp(inventory->items[i].name, finding) == 0) {
            // Shift every items to the front to delete
            for (int j = i; j < inventory->total_item - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }
            // Update the total number of items
            inventory->total_item--;
            printf("Grocery item '%s' removed successfully!\n", finding);
            return;
        }
    }
    printf("Item not found\n");
}

int main() {
    Grocery_Inventory inventory = { .total_item = 0 };  // Initialise the total number to 0
    int choice;
    while (1) {
        choice = menu();
        switch (choice){
            case 1:
                add_items(&inventory);
                break;
            case 2:
                list_items(&inventory);
                break;
            case 3:
                update_quantity(&inventory);
                break;
            case 4:
                remove_item(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid input. Enter again\n");
                break;
        }
    }
    return 0;
}