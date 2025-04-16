#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define FILE_NAME "grocery_inventory.csv"

// grocery item structure
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    char availability[20];
} GroceryItem;

//load grocery items from csv file
void loadItems(GroceryItem items[], int *itemCount) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No inventory file found. Starting fresh.\n");
        *itemCount = 0;
        return;
    }

    char line[MAX_LINE_LENGTH];
    *itemCount = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%d,%f,%[^\n]", items[*itemCount].name, items[*itemCount].category,
               &items[*itemCount].quantity, &items[*itemCount].price, items[*itemCount].availability);
        (*itemCount)++;
    }

    fclose(file);
}

//save items to file
void saveItems(GroceryItem items[], int itemCount) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Error saving inventory to file.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%s,%s,%d,%.2f,%s\n", items[i].name, items[i].category, items[i].quantity,
                items[i].price, items[i].availability);
    }

    fclose(file);
}

//display the items function
void displayItems(GroceryItem items[], int itemCount) {
    printf("\nName\tCategory\tQuantity\tPrice\tAvailability\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s\t%s\t%d\t%.2f\t%s\n", items[i].name, items[i].category, items[i].quantity,
               items[i].price, items[i].availability);
    }
}

//adding items to list function
void addItem(GroceryItem items[], int *itemCount) {
    printf("Enter Item Name: ");
    scanf("%s", items[*itemCount].name);
    printf("Enter Category: ");
    scanf("%s", items[*itemCount].category);
    printf("Enter Quantity: ");
    scanf("%d", &items[*itemCount].quantity);
    printf("Enter Price: ");
    scanf("%f", &items[*itemCount].price);

    strcpy(items[*itemCount].availability, (items[*itemCount].quantity > 0) ? "In Stock" : "Out of Stock");
    (*itemCount)++;

    saveItems(items, *itemCount);
    printf("Item added successfully!\n");
}

//update quantity of existing item
void updateQuantity(GroceryItem items[], int itemCount) {
    char itemName[100];
    printf("Enter item name to update quantity: ");
    scanf("%s", itemName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            strcpy(items[i].availability, (items[i].quantity > 0) ? "In Stock" : "Out of Stock");
            saveItems(items, itemCount);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

//remove an item from list
void removeItem(GroceryItem items[], int *itemCount) {
    char itemName[100];
    printf("Enter item name to remove: ");
    scanf("%s", itemName);

    for (int i = 0; i < *itemCount; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            for (int j = i; j < *itemCount - 1; j++) {
                items[j] = items[j + 1];
            }
            (*itemCount)--;
            saveItems(items, *itemCount);
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    GroceryItem groceryItems[100];
    int itemCount = 0;

    loadItems(groceryItems, &itemCount);

    int choice;
    do {
        //options
        printf("-----------------------------------------");
        printf("\nGrocery Inventory Management System\n");
        printf("-----------------------------------------\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //handling options
        switch (choice) {
            case 1:
                addItem(groceryItems, &itemCount);
                break;

            case 2:
                displayItems(groceryItems, itemCount);
                break;

            case 3:
                updateQuantity(groceryItems, itemCount);
                break;

            case 4:
                removeItem(groceryItems, &itemCount);
                break;

            case 5:
                printf("Exiting!\n");
                break;

            default:
                //invalid input handling
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
