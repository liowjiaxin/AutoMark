#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  // Include for bool, true, and false

struct Grocery_item {
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool stock;
};

struct Grocery_inventory {
    struct Grocery_item Grocery_items[100];
    int total_items;
};

struct Grocery_inventory inventory = {{0}, 0};  // Declaring and initializing the inventory

// FUNCTION PROTOTYPES
void add_grocery_item(void);
void list_all_grocery_items(void);
void update_quantity(void);
void remove_grocery_item(void);

// INPUT FUNCTIONS
void standard_input(char[], size_t); // Primary way to get input, size_t is size of array.
void clear_buffer(void); // Flush buffer

int main (void) {
    char input[50] = "\0";
    int choice = -1;

    while (1) {
        puts("\nGrocery Inventory Management System\n");
        puts("Enter 1 to Add Grocery Item");
        puts("Enter 2 to List All Grocery Items");
        puts("Enter 3 to Update Quantity");
        puts("Enter 4 to Remove Grocery Item");
        puts("Enter 5 to exit program");
        printf("Choice: ");
        standard_input(input, sizeof(input));
        choice = atoi(input); // Convert input to int
    
        if (choice == 5) {
            puts("Exiting program");
            break;
        }

        switch (choice) {
            default:
                puts("Invalid input. Please enter a number (1-5)");
                break;
            case 1:
                add_grocery_item();
                break;
            case 2:
                list_all_grocery_items();
                break;
            case 3:
                update_quantity();
                break;
            case 4:
                remove_grocery_item();
                break;
        }
    }
    return 0;
}


// MAIN FUNCTIONS
void add_grocery_item(void){
    char input[100] = "\0";
    struct Grocery_item new_item;
    if (inventory.total_items < 100) {
        printf("Enter item name: ");
        standard_input(inventory.Grocery_items[inventory.total_items].name, 100);
        
        printf("Enter item category: ");
        standard_input(inventory.Grocery_items[inventory.total_items].category, 50);

        printf("Enter item quantity: ");
        while (scanf("%d", &inventory.Grocery_items[inventory.total_items].quantity) != 1 || inventory.Grocery_items[inventory.total_items].quantity < 0) {
            clear_buffer();
            printf("Invalid quantity, please enter a non-negative number: ");
        }

        printf("Enter item price: ");
        while (scanf("%f", &inventory.Grocery_items[inventory.total_items].price) != 1 || inventory.Grocery_items[inventory.total_items].price <= 0) {
            clear_buffer();
            printf("Invalid price, please enter a positive number: ");
        }

        printf("Is the item in stock (1 for Yes, 0 for No): ");
        while (scanf("%d", (int *)&inventory.Grocery_items[inventory.total_items].stock) != 1 || (inventory.Grocery_items[inventory.total_items].stock != 0 && inventory.Grocery_items[inventory.total_items].stock != 1)) {
            clear_buffer();
            printf("Invalid input, enter 1 for Yes, 0 for No: ");
        } 

        puts("Grocery item added succesfully");

        inventory.total_items++; // Add one item
    }
    else puts("Inventory is full. Can not add more items"); 
}

void list_all_grocery_items(void) {
    printf("Total items: %d\n", inventory.total_items);
    for (int i = 0; i < inventory.total_items; i++) {
        printf("Item %d: %s, Category: %s, Quantity: %d, Price: %.2f, Stock: %s\n",
        i + 1, inventory.Grocery_items[i].name, 
        inventory.Grocery_items[i].category,
        inventory.Grocery_items[i].quantity, 
        inventory.Grocery_items[i].price,
        inventory.Grocery_items[i].stock? "In Stock":"Out of Stock");
    }
}

void update_quantity(void) {
    char name[100];
    int update_quantity;
    int found = 0;
    printf("Enter name of grocery item to update quantity: ");
    standard_input(name, sizeof(name));
    for (int i = 0; i < inventory.total_items; i++) {
        if (strcmp(name, inventory.Grocery_items[i].name) == 0) {
            printf("Enter new quantity for %s: ", inventory.Grocery_items[i].name);
            scanf("%d", &inventory.Grocery_items[i].quantity);
            clear_buffer();
            puts("Quantity updated succesfully");
            found++; // Mark as found
        }
    }
    if (found == 0) printf("%s is not in grocery inventory list\n", name);
}


void remove_grocery_item(void) {
    char name[100];
    int found = 0;
    printf("Enter name of grocery item to remove: ");
    standard_input(name, sizeof(name));
    for (int i = 0; i < inventory.total_items; i++) {
        if (strcmp(name, inventory.Grocery_items[i].name) == 0) {
            found++; // Mark as found
            inventory.total_items--; // Remove an item
            // Shift items in grocery inventory to the left after removing an item
            for (int j = i; j < inventory.total_items; j++) {
                    inventory.Grocery_items[j] = inventory.Grocery_items[j + 1];
            }
            // Clear the last item in the array 
            memset(&inventory.Grocery_items[inventory.total_items], 0, sizeof(struct Grocery_item));
            printf("Grocery item %s removed successfully.\n", name);
        }
    }

    if (found == 0) {
        printf("%s is not in grocery inventory list\n", name);
    }
}

//INPUT FUNCTIONS
void clear_buffer(void){
    while(getchar() != '\n');
}

void standard_input(char input[], size_t size) {
    fgets(input, size, stdin); // Directly read into the passed array
    if (!strchr(input, '\n')) { // Check if the newline was not present (overflow occurred)
        clear_buffer(); // Clear the buffer
    } 
    else {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character if present
    }
}


