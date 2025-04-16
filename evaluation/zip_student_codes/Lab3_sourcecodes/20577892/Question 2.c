#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NOITEMS 50  // Maximum number of items that can be added to the inventory

// Define the structure for grocery items
struct grocery_items {
    char name[100];       

    
    char category[50];    
    int quantity;        
    float price;          
    bool availability;    // Availability status (in stock or out of stock)
};

int main() {
    int choice; 
    struct grocery_items grocery[NOITEMS];  // Array to store grocery items
    int index_counter = 0;  // Counter to track how many items are added
    char search[50];  // Variable to store the name of the item to search or update
    int search_index = 0;  // Index to track the item position for updates
    char remove[50];  // Variable to store the name of the item to remove

    while (1) {
        // Display the menu
        printf("Grocery Inventory Management System\n"
               "1. Add grocery item\n"
               "2. List all grocery items with their availability\n"
               "3. Update the quantity of a grocery item\n"
               "4. Remove a grocery item from the inventory\n"
               "5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice); 

       
        switch (choice) {
        case 1:
            // Add a new grocery item to the inventory
            printf("Enter item Name: ");
            scanf(" %[^\n]", grocery[index_counter].name);  // Input the item's name

            printf("Enter Category: ");
            scanf(" %[^\n]", grocery[index_counter].category);  // Input the item's category

            printf("Enter Quantity: ");
            scanf(" %d", &grocery[index_counter].quantity);  // Input the quantity of the item

            printf("Enter Price: ");
            scanf("%f", &grocery[index_counter].price);  // Input the price of the item

            // Set availability based on the quantity
            grocery[index_counter].availability = (grocery[index_counter].quantity > 0) ? true : false;

            // If quantity is less than or equal to 0, the item is out of stock
            if (grocery[index_counter].quantity <= 0) {
                grocery[index_counter].availability = false;
            }

            puts("Grocery item added successfully!");
            index_counter++;  // Increment the item count
            break;

        case 2:
            // List all the grocery items with their availability status
            if (index_counter == 0) {
                printf("No items in the inventory.\n");  // If no items are added
            } else {
                // Loop through all items and display their details
                for (int l = 0; l < index_counter; l++) {
                    printf("\nItem %d:\n", l + 1);
                    printf("Name: %s\n", grocery[l].name);
                    printf("Category: %s\n", grocery[l].category);
                    printf("Quantity: %d\n", grocery[l].quantity);
                    printf("Price: %.2f\n", grocery[l].price);
                    printf("Availability: %s\n", grocery[l].availability ? "In-stock" : "Out-stock");
                }
            }
            break;

        case 3:
            // Update the quantity of an existing grocery item
            printf("Enter name of the grocery item to update quantity: ");
            scanf(" %[^\n]", search);  // Input the item name to search for

            // Search for the item in the inventory
            for (size_t s = 0; s < index_counter; s++) {
                if (strcmp(search, grocery[s].name) == 0) {
                    search_index = s;  // Item found, store its index
                    break;
                }
            }

            // If the item was found, update its quantity
            if (search_index >= 0) {
                printf("Enter new quantity for %s: ", search);  // Prompt for the new quantity
                scanf("%d", &grocery[search_index].quantity);  // Update the quantity
                puts("Quantity updated successfully!");

                // Update availability based on the new quantity
                if (grocery[search_index].quantity <= 0) {
                    grocery[search_index].availability = false;  // Mark item as out of stock if quantity is 0 or less
                }
            } else {
                printf("Item not found.\n");  // If item is not found, notify the user
            }
            break;

        case 4:
            // Remove a grocery item from the inventory
            printf("Enter name of the grocery item to remove: ");
            scanf(" %[^\n]", remove);  // Input the item name to remove

            int remove_index = -1;  // Variable to store the index of the item to remove

            // Search for the item to remove
            for (int r = 0; r < index_counter; r++) {
                if (strcmp(remove, grocery[r].name) == 0) {
                    remove_index = r;  // Item found, store its index
                    break;
                }
            }

            // If the item is found, remove it by shifting the remaining items to the left
            if (remove_index == -1) {
                printf("Item not found.\n");  // if Item not found, show an error
            } else {
                // Shift the items to the left to fill the gap
                for (int i = remove_index; i < index_counter - 1; i++) {
                    grocery[i] = grocery[i + 1];
                }
                index_counter--;  // Decrease the item count
                printf("Grocery item '%s' removed successfully!\n", remove);
            }
            break;

        case 5:
            // Exit the program
            printf("Exiting...\n");
            return 0;

        default:
            // For invalid menu choice
            printf("Error: Invalid choice!\n");
            break;
        }
    }
    return 0;
}
