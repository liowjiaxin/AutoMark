#include <stdio.h>
#include <string.h>

#define max_name_length 100
#define max_category_length 50
#define max_item 100

typedef struct {
    char name[max_name_length];
    char category[max_category_length];
    int quantity;
    float price;
    int stock;
} grocery_item;

grocery_item gI[max_item];
int item_count = 0;

void addItem() {
    if (item_count >= max_item) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    grocery_item newItem;

    printf("Enter Item Name: ");
    scanf(" %[^\n]", newItem.name);
    if (strlen(newItem.name) >= max_name_length) {
        printf("Name too long. Please enter a shorter name.\n");
        return;
    }

    printf("Enter Category: ");
    scanf(" %[^\n]", newItem.category);
    if (strlen(newItem.category) >= max_category_length) {
        printf("Category too long. Please enter a shorter category.\n");
        return;
    }

    printf("Enter Quantity: ");
    if (scanf("%d", &newItem.quantity) != 1) {
        printf("Invalid input for quantity. Please enter an integer.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    printf("Enter Price: ");
    if (scanf("%f", &newItem.price) != 1) {
        printf("Invalid input for price. Please enter a floating-point number.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }

    newItem.stock = newItem.quantity > 0 ? 1 : 0;

    gI[item_count] = newItem;
    item_count++;

    printf("Grocery item added successfully!\n");
}

void listItems() {
    if (item_count == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    for (int i = 0; i < item_count; i++) {
        grocery_item item = gI[i];
        printf("Name: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Status: %s\n\n", item.stock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity() {
    char name[max_name_length];
    printf("Enter the name of the item to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(gI[i].name, name) == 0) {
            printf("Enter new quantity: ");
            if (scanf("%d", &gI[i].quantity) != 1) {
                printf("Invalid input for quantity. Please enter an integer.\n");
                while (getchar() != '\n'); // Clear input buffer
                return;
            }

            gI[i].stock = gI[i].quantity > 0 ? 1 : 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

void removeItem() {
    char name[max_name_length];
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(gI[i].name, name) == 0) {
            for (int j = i; j < item_count - 1; j++) {
                gI[j] = gI[j + 1];
            }

            // Clear the last item's memory
            memset(&gI[item_count - 1], 0, sizeof(grocery_item));

            item_count--;
            printf("Grocery item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

int main() {
    int choice;

    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

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
