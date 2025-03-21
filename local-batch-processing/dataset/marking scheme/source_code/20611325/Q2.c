#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Groceries {
    char name[100];
    char category[50];
    int quantity;
    float price;
};

// Function prototypes
void add_grocery_item(struct Groceries groceries[], int *count);
void list_all_grocery_items(struct Groceries groceries[], int count);
void update_quantity(struct Groceries groceries[], int count);
void remove_grocery_item(struct Groceries groceries[], int *count);

int main(){
    struct Groceries groceries[MAX_ITEMS];
    int count = 0; // Number of items in the inventory
    int choice = 0;

    while (choice != 5){
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n2. List All Grocery Items\n3. Update Quantity\n4. Remove Grocery Item\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch(choice){
            case 1:
                add_grocery_item(groceries, &count);
                printf("\n");
                break;
            case 2:
                list_all_grocery_items(groceries, count);
                printf("\n");
                break;
            case 3:
                update_quantity(groceries, count);
                printf("\n");
                break;
            case 4:
                remove_grocery_item(groceries, &count);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Add grocery items
void add_grocery_item(struct Groceries groceries[], int *count){
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }
    printf("Enter item name: ");
    fgets(groceries[*count].name, 100, stdin);
    groceries[*count].name[strcspn(groceries[*count].name, "\n")] = '\0'; // Remove newline character

    printf("Enter category: ");
    fgets(groceries[*count].category, 50, stdin);
    groceries[*count].category[strcspn(groceries[*count].category, "\n")] = '\0'; // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &groceries[*count].quantity);
    getchar(); // Consume newline character

    printf("Enter price: ");
    scanf("%f", &groceries[*count].price);
    getchar(); // Consume newline character

    (*count)++;
    printf("Item added successfully\n");    
}

// List all grocery items
void list_all_grocery_items(struct Groceries groceries[], int count){
    if(count == 0){   // Check if inventory is empty
        printf("No grocery items in the inventory\n");
    } else {
        for (int i = 0; i < count; i++) {   // List out all the items in the inventory
            printf("Name: %s\n\033[0;32mCategory: %s\033[0m\nQuantity: %d\nPrice: %.2f\n", groceries[i].name, groceries[i].category, groceries[i].quantity, groceries[i].price);
            if (groceries[i].quantity <= 0){
                printf("Status: Out of stock\n");
            } else {
                printf("Status: In stock\n");
            }
        }
    }
}

// Update quantity of grocery items
void update_quantity(struct Groceries groceries[], int count){
    char item_name[100];
    int new_quantity;

    printf("Enter the name of the grocery item to update quantity: ");
    fgets(item_name, 100, stdin);
    item_name[strcspn(item_name, "\n")] = '\0'; // Remove newline character

    if (count == 0) {   // Check if inventory is empty
        printf("No grocery items in the inventory\n");
        return;
    }

    for (int i = 0; i < count; i++) {   // Loop through the inventory to find the item
        if (strcmp(groceries[i].name, item_name) == 0) {    // Found item then update quantity
            printf("Enter new quantity for %s: ", item_name);
            scanf("%d", &new_quantity);
            getchar(); // Consume newline character

            groceries[i].quantity = new_quantity;   //Update quantity
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("No grocery item in the inventory!\n"); // No grocery items found
}

// Remove grocery items
void remove_grocery_item(struct Groceries groceries[], int *count){
    char item_name[100];

    printf("Enter the name of the grocery item to remove: ");
    fgets(item_name, 100, stdin);
    item_name[strcspn(item_name, "\n")] = '\0'; // Remove newline character

    for(int i = 0; i < *count; i++){   // Loop through the inventory to find the item
        if (strcmp(groceries[i].name, item_name) == 0){   // Found item then remove the specified item
            for (int j = i; j < *count - 1; j++){   // Shift the items to the left
                groceries[j] = groceries[j + 1];    
            }
            (*count)--; // Decrement the count
            printf("Grocery item '%s' removed successfully!\n", item_name); 
            return;
        }
    }
    printf("No grocery item in the inventory!\n"); // No grocery items found
}
