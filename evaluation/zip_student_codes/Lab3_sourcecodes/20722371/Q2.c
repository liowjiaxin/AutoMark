#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 25

typedef struct{
    char name[100];
    char category[50];
    int quantity;
    double price;
} groceryitems;

typedef struct{
    bool instock;
    bool outofstock;
} availabilitystatus;

typedef struct{
    groceryitems items[100];
    availabilitystatus availability[100];
    int count;
} groceryinventory;

int main() {
    int choice;
    char name[100];
    
    groceryinventory inventory;
    inventory.count = 0;

    do {
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid choice. Please enter a number between 1 to 5.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }

        while (getchar() != '\n'); //clear any leftover newline character from previous input

        switch (choice) {
            case 1:
                // 1. Add Grocery Item
                groceryitems newitem;
               
                printf("Enter Item Name: ");
                fgets(newitem.name, sizeof(newitem.name), stdin);
                newitem.name[strcspn(newitem.name, "\n")] = '\0'; // remove newline character from name

                printf("Enter Category: ");
                fgets(newitem.category, sizeof(newitem.category), stdin);
                newitem.category[strcspn(newitem.category, "\n")] = '\0'; // remove newline character from category

                printf("Enter Quantity: ");
                scanf("%d", &newitem.quantity);

                printf("Enter Price: ");
                scanf("%lf", &newitem.price);

                inventory.items[inventory.count++] = newitem;
                printf("Grocery item added successfully!\n");
                break;

            case 2:
                // 2. List All Grocery Items
                if (inventory.count == 0) {
                    printf("No grocery items in the inventory.\n");
                    break;
                }
                
                for (int i = 0; i < inventory.count; i++) {
                    groceryitems *item = &inventory.items[i];

                    printf("Name: %s\n", item->name);
                    printf("Category: %s\n", item->category);
                    printf("Price: %.2f\n", item->price);
                    printf("Status: %s\n", item->quantity > 0 ? "In Stock" : "Out of Stock");
                }
                break;

            case 3:
                // 3. Update Quantity
                printf("Enter the name of the grocery item to update quantity: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline character from name input

                int found = 0;
                for (int i = 0; i < inventory.count; i++) {
                    if (strcmp(inventory.items[i].name, name) == 0) {
                        printf("Enter new quantity: ");
                        scanf("%d", &inventory.items[i].quantity);
                        printf("Quantity updated successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found in inventory.\n");
                }
                break;

            case 4:
                // 4. Remove Grocery Item
                printf("Enter the name of the grocery item to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline character from name input

                found = 0;
                for (int i = 0; i < inventory.count; i++) {
                    if (strcmp(inventory.items[i].name, name) == 0) {
                        // shift the items to remove the current item
                        for (int j = i; j < inventory.count - 1; j++) {
                            inventory.items[j] = inventory.items[j + 1];
                        }
                        inventory.count--;
                        printf("Grocery item '%s' removed successfully!\n", name);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found in inventory.\n");
                }
                break;

            case 5:
                // 5. Exit
                printf("Exiting...\n");
                return 0;
                break;
        }
    } while (choice != 5); // menu loops until user exits

    return 0;
}
