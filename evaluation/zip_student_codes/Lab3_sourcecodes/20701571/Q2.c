#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int inStock;
} GroceryItem;

GroceryItem inventory[MAX_ITEMS];
int Numitems = 0; //initialize number of items to 0

void addItem() {
    if (Numitems >= MAX_ITEMS) { //if statement to ensure the user doesnt exceed the maximum number of items defined previously
        printf("Inventory is full.\n");
    }

    GroceryItem item; // declares a variable item of type GroceryItem
    printf("Enter item name: "); //item.name is the destination where the entered string is stored, so the string entered will be stored in the array "name" in the struct GroceryItem
    scanf(" %[^\n]s", item.name);// %[^\n] is a format specifier used with scanf to read an entire line
    printf("Enter category: "); 
    scanf(" %[^\n]s", item.category); //The category field of the item struct will store the input string.
    printf("Enter quantity: "); // we use the ampersand (&) for quantity and not in "name" and "category" fields because they are arrays and the name of an array is a pointer to the first element of the array.
    scanf("%d", &item.quantity); // the quantity inputted by the user should be an integer so %d is used. "&item.quantity" passes the address of the quantity field to scanf.
    printf("Enter price: ");// we use the ampersand for price as well as it does not have an array rather it is a float.
    scanf("%f", &item.price);// for price we have to use floating point format specifier.
    item.inStock = item.quantity > 0; // item is in stock if quantity of the item is greater than 0.

    inventory[Numitems++] = item;
    printf("Item added successfully.\n");
}

void listItems() {
    if (Numitems == 0) {
        printf("No items in inventory.\n");
        return;
    }

printf("Inventory List:\n"); 
    for (int i = 0; i < Numitems; i++) { // Loop through all items in the inventory
        printf("Name: %s\n, Category: %s\n, Quantity: %d\n, Price: %.2f\n, Status: %s\n",
               inventory[i].name,         // Print the item's name
               inventory[i].category,     // Print the item's category
               inventory[i].quantity,     // Print the item's quantity
               inventory[i].price,        // Print the item's price to 2 decimal places
               inventory[i].inStock ? "In Stock" : "Out of Stock"); // Print stock status based on quantity, using ternary operator
    }
}

void updateQuantity() {
    char name[100]; // Buffer to store the name of the item to be updated
    printf("Enter item name to update: "); // Prompt the user for the item's name
    scanf(" %[^\n]s", name); // Read the item name, allowing spaces

    for (int i = 0; i < Numitems; i++) { // Loop through the inventory
        if (strcmp(inventory[i].name, name) == 0) { // Check if the current item's name matches the input
            printf("Enter new quantity: "); // Prompt for the new quantity
            scanf("%d", &inventory[i].quantity); // Read the new quantity
            inventory[i].inStock = inventory[i].quantity > 0; // Update stock status based on the new quantity
            printf("Quantity updated successfully.\n"); 
            return; // Exit the function after updating.
        }
    }

    printf("Item not found.\n"); // Inform the user if the item was not found in the inventory
}

void removeItem() {
    char name[100]; // Buffer to store the name of the item to be removed
    printf("Enter item name to remove: "); // Prompt the user for the item's name
    scanf(" %[^\n]s", name); // Read the item name, allowing spaces

    for (int i = 0; i < Numitems; i++) { // Loop through the inventory.
        if (strcmp(inventory[i].name, name) == 0) { // Check if the current item's name matches the input
            for (int j = i; j < Numitems - 1; j++) { // Shift subsequent items to fill the gap
                inventory[j] = inventory[j + 1]; // Overwrite the current item with the next one
            }
            Numitems--; // Decrement the item count after removal
            printf("Item removed successfully.\n"); 
            return; // Exit the function after removing
        }
    }

    printf("Item not found.\n"); // Inform the user if the item was not found in the inventory
}

int main() {
    int choice;
    do { // do while loop so it allows the program to keep looping the Menu until the user enters 5 and exits the program
        printf("\nMenu:\n1. Add Item\n2. List Items\n3. Update Quantity\n4. Remove Item\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeItem();
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
