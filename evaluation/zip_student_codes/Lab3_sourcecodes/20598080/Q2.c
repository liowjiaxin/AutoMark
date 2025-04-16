# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# define MAX_ITEMS 100  // Maximum number of items allowed in the inventory

// Struct to define a grocery item
typedef struct {
    char name[100];  // Name of the grocery item
    char category[50];  // Category of the grocery item
    int quantity;  // Quantity of the item in stock
    float price;  // Price of the item
} GroceryItem;

// Struct to define the availability status
typedef struct {
    bool inStock;  // Indicates if the item is in stock
} AvailabilityStatus;

// Inventory struct
typedef struct {
    GroceryItem items[MAX_ITEMS];  // Array of grocery items
    AvailabilityStatus availability[MAX_ITEMS];  // Array of availability statuses
    int count;  // Number of items currently in the inventory
} GroceryInventory;

// Function prototypes
void addItem(GroceryInventory *inventory);
void listItems(const GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = { .count = 0 };  // Initialize inventory with no items
    int choice;  // Variable to store user's menu choice

    // Main menu loop
    do {
        printf("\nGrocery Inventory Management System:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                addItem(&inventory);  // Add a new grocery item
                break; 
            case 2:
                listItems(&inventory);  // Display all grocery items
                break;
            case 3:
                updateQuantity(&inventory);  // Update the quantity of a specific item
                break;
            case 4:
                removeItem(&inventory);  // Remove an item from the inventory
                break;
            case 5:
                printf("Exiting...\n");  // Exit the program
                break;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);  // Loop until the user chooses to exit

    return 0;
}

// Function to add a grocery item to the inventory
void addItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->count];
    AvailabilityStatus *status = &inventory->availability[inventory->count];
    
    // Input item details
    printf("Enter Item Name: ");
    fgets(item->name, 100, stdin);
    item->name[strcspn(item->name, "\n")] = '\0';  // Remove newline
    
    printf("Enter Category: ");
    fgets(item->category, 50, stdin);
    item->category[strcspn(item->category, "\n")] = '\0';  // Remove newline

    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter Price: ");
    scanf("%f", &item->price);
    getchar();  // Consume newline
    
    // Update availability status
    status->inStock = item->quantity > 0;
    
    // Increment item count in the inventory
    inventory->count++;
    printf("Grocery item added successfully!\n");
}

// Functiion to list all grocery items
void listItems(const GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }
    
    // Display details of each item
    for (int i = 0; i < inventory->count; i++) {
        const GroceryItem *item = &inventory->items[i];
        const AvailabilityStatus *status = &inventory->availability[i];

        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->inStock ? "In Stock" : "Out of Stock");    
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory) {
    if (inventory->count == 0) {  // Check if inventory is empty
        printf("No items in the inventory to update.\n");
        return;
    }

    char itemName[100];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';  // Remove newline character

    // Find the item and update its quantity
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            printf("Enter new quantity for %s: ",inventory->items[i].name);
            scanf("%d", &inventory->items[i].quantity);
            getchar();  // Clear the newline character from the buffer
            
            // Update availability status
            inventory->availability[i].inStock = inventory->items[i].quantity > 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}


// Function to remove a grocery item from the inventory
void removeItem(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in the inventory to remove.\n");
        return;
    }

    char itemName[100];
    printf("Enter name of the grocery item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';  // Remove newline character
    
    // Find the item and remove it
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            // Shift items to remove the selected one
            for (int j = i; j<inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j +1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
             
            //  Decrease the count of items in the inventory 
            inventory->count--;
            printf("Grocery item '%s' removed successfully!\n", itemName);
            return;
        }
    }

    printf("Item '%s' not found in the inventory.\n", itemName);
}