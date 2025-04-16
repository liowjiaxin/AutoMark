#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[100];
    char category[100];
    int quantity;
    float price;
    bool availability;
} GrocItem;

GrocItem *items[100];

void allocateMemory() {
    for (int i = 0; i < 100; i++) {
        items[i] = (GrocItem*)malloc(sizeof(GrocItem));
        if (items[i] == NULL) {
            printf("Memory allocation failed for item %d\n", i);
            exit(1);
        }
    }
}

void freeMemory() {
    for (int i = 0; i < 100; i++) {
        free(items[i]);
    }
}

void addItem(int *item_count) {
    if (*item_count >= 100) {
        printf("Inventory is full, cannot add more items.\n");
        return;
    }
    getchar();  // Clear newline from input buffer
    printf("Enter the name of the product: ");
    scanf(" %[^\n]s", items[*item_count]->name);
    
    printf("Enter the category of the item: ");
    scanf(" %[^\n]s", items[*item_count]->category);
    
    while (1) {
        printf("Enter the quantity of the item: ");
        scanf("%d", &items[*item_count]->quantity);
        if (items[*item_count]->quantity < 0) {
            printf("Quantity cannot be negative. Try again.\n");
        } else {
            break;
        }
    }
    
    printf("Enter the price of the item: ");
    scanf("%f", &items[*item_count]->price);
    
    items[*item_count]->availability = (items[*item_count]->quantity > 0);
    printf("Item added!\n");
    (*item_count)++;
}

void displayGroceryItem(int item_count) {
    if (item_count == 0) {
        printf("No items to display.\n");
        return;
    }
    printf("=========== Grocery Items ===========\n");
    for (int i = 0; i < item_count; i++) {
        printf("Item %d\n", i + 1);
        printf("  Name: %s\n", items[i]->name);
        printf("  Category: %s\n", items[i]->category);
        printf("  Quantity: %d\n", items[i]->quantity);
        printf("  Price: %.2f\n", items[i]->price);
        printf("  Availability: %s\n", items[i]->availability ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity(int item_count) {
    if (item_count == 0) {
        printf("No items in inventory. Request failed.\n");
        return;
    }
    getchar();  // Clear newline from input buffer
    char search_name[100];
    printf("Enter the name of the item whose quantity you'd like to change: ");
    scanf(" %[^\n]s", search_name);
    
    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i]->name, search_name) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &items[i]->quantity);
            while (items[i]->quantity < 0) {
                printf("Quantity cannot be negative. Enter a new quantity: ");
                scanf("%d", &items[i]->quantity);
            }
            items[i]->availability = (items[i]->quantity > 0);
            printf("updated quantity!\n");
            return;
        }
    }
    printf("Item could not be found.\n");
}

void deleteItem(int *item_count) {
    if (*item_count == 0) {
        printf("No items in inventory. Nothing can be deleted.\n");
        return;
    }
    char search_name[100];
    printf("Enter the name of the item you'd like to delete: ");
    scanf(" %[^\n]s", search_name);

    for (int i = 0; i < *item_count; i++) {
        if (strcmp(items[i]->name, search_name) == 0) {
            for (int j = i; j < *item_count - 1; j++) {
                items[j] = items[j + 1];
            }
            printf("Item deleted successfully.\n");
            (*item_count)--;  // Decrease the item count
            return;
        }
    }
    printf("Item could not be found.\n");
}

int main() {
    int choice = 0;
    int item_count = 0;
    allocateMemory();
    
    do {
        printf("=======================\n");
        printf("Grocery Inventory Manager\n");
        printf("=======================\n");
        printf("1. Add\n2. Display\n3. Update\n4. Remove\n5. Exit\n");

        printf("Enter your choice: ");
        int valid = scanf("%d", &choice);
        if (!valid) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            choice = 0; // Reset choice
        }

        switch(choice) {
            case 1:
                addItem(&item_count);
                break;
            case 2:
                displayGroceryItem(item_count);
                break;
            case 3:
                updateQuantity(item_count);
                break;
            case 4:
                deleteItem(&item_count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Please enter a valid input\n");
        }
    } while (choice != 5);
    
    freeMemory();
    return 0;
}
