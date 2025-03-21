#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// Structure definitions
typedef struct
{
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct
{
    bool inStock;
} AvailabilityStatus;

typedef struct
{
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus availability[MAX_ITEMS];
    int totalItems;
} GroceryInventory;

// Function prototypes
void displayMenu();
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main()
{
    // Initialize the inventory and choice
    GroceryInventory inventory = {0};
    int choice = 0;

    // Loop the menu until user chooses to exit (choice 5)
    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {
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
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display the menu, a prompt for the user to choose an option
void displayMenu()
{
    printf("\nGrocery Inventory Management System:\n\
1. Add Grocery Item\n\
2. List All Grocery Items\n\
3. Update Quantity\n\
4. Remove Grocery Item\n\
5. Exit\n");
}

// Function to add a grocery item
void addGroceryItem(GroceryInventory *inventory)
{
    // Initialize variables to store the name, quantity, and price of the item
    char name[100] = {0};
    int quantity = 0;
    float price = 0;

    // Check if the inventory is full
    if (inventory->totalItems >= MAX_ITEMS)
    {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    // Let item point to the new item to be added
    GroceryItem *item = &inventory->items[inventory->totalItems];
    // Let status point to the availability status of the new item
    AvailabilityStatus *status = &inventory->availability[inventory->totalItems];

    printf("Enter name of the item: ");
    getchar();             // Clear newline character from buffer
    scanf("%[^\n]", name); // Read the name of the item

    // Check if the item name already exists in the inventory by looping through the items in the inventory
    for (int i = 0; i < inventory->totalItems; i++)
    {
        if (strcmp(inventory->items[i].name, name) == 0)
        {
            printf("Item already exists in inventory.\n");
            return;
        }
    }

    // Store the name of the items into the items array
    strcpy(item->name, name);

    printf("Enter category of the item: ");
    getchar(); // Clear newline character from buffer
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = 0; // Remove newline character

    printf("Enter quantity of the item: ");
    scanf(" %d", &quantity);

    // Check if the quantity is a positive value
    if (quantity < 0)
    {
        printf("Invalid quantity. Please enter a positive value.\n");
        return;
    }
    else
    {
        // Update the quantity of the item if it is valid
        item->quantity = quantity;
    }

    printf("Enter price of the item: ");
    getchar(); // Clear newline character from buffer
    scanf(" %f", &price);
    getchar(); // Clear newline character from buffer

    // Check if the price is a positive value
    if (price < 0)
    {
        printf("Invalid price. Please enter a positive value.\n");
        return;
    }
    else
    {
        item->price = price; // Update the price of the item if it is valid
    }

    // Update the availability status of the item based on the quantity (Maybe 0, hence need to have a logic to check if it is in stock)
    status->inStock = (item->quantity > 0);

    // Increment the totalItems count
    inventory->totalItems++;
    printf("Item added successfully!\n");
}

// Function to list all grocery items with their availability
void listGroceryItems(GroceryInventory *inventory)
{
    // Check if there are is items in the inventory
    if (inventory->totalItems == 0)
    {
        printf("No items in inventory.\n");
        return;
    }

    // Loop through the items in the inventory and print their details
    for (int i = 0; i < inventory->totalItems; i++)
    {
        GroceryItem *item = &inventory->items[i];
        AvailabilityStatus *status = &inventory->availability[i];
        printf("\nName: %s\n\
Category: %s\n\
Quantity: %d\n\
Price: %.2f\n\
Status: %s\n",
               item->name, item->category, item->quantity, item->price, status->inStock ? "In Stock" : "Out of Stock");
        // For the status, if inStock is true, print "In Stock", else print "Out of Stock"
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory)
{
    // An array name to store the item name
    char name[100] = {0};
    // An integer to store the new quantity
    int newQuantity = 0;

    // If no items in the inventory, user not allowed to update quantity
    if (inventory->totalItems == 0)
    {
        printf("No items in inventory.\n");
        return;
    }

    printf("Enter the name of the item to update quantity: ");
    getchar(); // Clear newline character from buffer
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    // Loop through the inventory to find the item to update
    for (int i = 0; i < inventory->totalItems; i++)
    {
        // String comparison to check if the item name is in the inventory
        if (strcmp(inventory->items[i].name, name) == 0)
        {
            printf("Enter new quantity: ");
            scanf(" %d", &newQuantity);

            // Check if the new quantity is a positive value
            if (newQuantity < 0)
            {
                printf("Invalid quantity. Please enter a positive value.\n");
                return;
            }

            // Update the quantity of the item if it is valid
            inventory->items[i].quantity = newQuantity;
            // Update the availability status of the item based on the new quantity
            inventory->availability[i].inStock = newQuantity > 0;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(GroceryInventory *inventory)
{
    // An array name to store the item name
    char name[100] = {0};

    // User not allow to remove item if no items in the inventory
    if (inventory->totalItems == 0)
    {
        printf("No items in inventory.\n");
        return;
    }

    printf("Enter the name of the item to remove: ");
    getchar(); // Clear newline character from buffer
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    // Loop through the inventory to find the item to remove
    for (int i = 0; i < inventory->totalItems; i++)
    {
        // String comparison to check if the item name is in the inventory
        if (strcmp(inventory->items[i].name, name) == 0)
        {
            // Shift all items that is left from the loop to the left to remove the item
            for (int j = i; j < inventory->totalItems - 1; j++)
            {
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }

            // Decrement the totalItems count
            inventory->totalItems--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}
