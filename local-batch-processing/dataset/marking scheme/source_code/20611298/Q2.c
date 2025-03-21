#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//maximum 100 item can be added in this array later
#define ITEMS 100
//Use of ANSI escape code for the 92 is green, and 0 is reset its colour
#define GREEN "\033[92m"
#define RESET "\033[0m"

// Define Grocery Item including size
typedef struct { 
    char name[100];
    char category[50]; 
    int quantity;
    float price;
} Grocery_Item;

// Stocks boolean
typedef struct { 
    bool in_stock; 
    } AvailabilityStatus;

// Inventory structure
typedef struct {
    //define a array for grocery item
    Grocery_Item items[ITEMS];
    //define an array for availability statuses
    AvailabilityStatus statuses[ITEMS];
    int count;
} GroceryInventory;

// Function prototypes
void Add_Item(GroceryInventory *inventory);
void Items_List(const GroceryInventory *inventory);
void Update_Quantity(GroceryInventory *inventory);
void Remove_Item(GroceryInventory *inventory);

void Add_Item(GroceryInventory *inventory) {
    if (inventory->count >= ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    Grocery_Item *item = &inventory->items[inventory->count];
    AvailabilityStatus *status = &inventory->statuses[inventory->count];

    printf("Enter Item Name: ");
    //clear new line
    fgets(item->name, 100, stdin);
    item->name[strcspn(item->name, "\n")] = 0; 

    printf("Enter Category: ");
    //clear new line
    fgets(item->category, 50, stdin);
    item->category[strcspn(item->category, "\n")] = 0; 

    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter Price: ");
    scanf("%f", &item->price);
    //clear input buffer
    getchar(); 

    status->in_stock = item->quantity > 0;

    inventory->count++;
    printf("Grocery item added successfully!\n");
}

//Display all grocery items and their availability status base on it quantity
void Items_List(const GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->count; i++) {
        const Grocery_Item *item = &inventory->items[i];
        const AvailabilityStatus *status = &inventory->statuses[i];

        printf("Name: %s\n", item->name);
        //use of the ANSI escape codes to mek the category line green, 
        //Reset after this row to make others still in normal colour
        printf("%sCategory: %s%s\n", GREEN, item->category, RESET);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->in_stock ? "In Stock" : "Out of Stock");
    }
}

void Update_Quantity(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    char name[100];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < inventory->count; i++) {
        Grocery_Item *item = &inventory->items[i];
        if (strcmp(item->name, name) == 0) {
            printf("Enter new quantity for %s: ", item->name);
            scanf("%d", &item->quantity);
            getchar(); // Clear newline from buffer

            //Available status
            inventory->statuses[i].in_stock = item->quantity > 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

void Remove_Item(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    char name[100];
    printf("Enter name of the grocery item to remove: ");
    //remove new line
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0; 

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            // Shift items to remove the current item
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->statuses[j] = inventory->statuses[j + 1];
            }

            inventory->count--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

int main() {
    GroceryInventory inventory = { .count = 0 };
    int Choices;

    //use do while loop to start the menu
    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &Choices);
        //get rid of newline buffer
        getchar();

        //switch case to handle each written function
        switch (Choices) {
            case 1:
                Add_Item(&inventory);
                break;
            case 2:
                Items_List(&inventory);
                break;
            case 3:
                Update_Quantity(&inventory);
                break;
            case 4:
                Remove_Item(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (Choices != 5);

    return 0;
}
