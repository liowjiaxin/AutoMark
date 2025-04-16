#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Structure for Grocery Item
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

// Structure for Availability Status
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Structure for Grocery Inventory
typedef struct {
    GroceryItem items[100];
    AvailabilityStatus availability[100];
    int itemCount;
} GroceryInventory;

int main() {
    int choice;
    GroceryInventory inventory;
    inventory.itemCount = 0;

    do {
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
    
        switch (choice) {
            case 1: // Add Grocery Item
                GroceryItem *item = &inventory.items[inventory.itemCount];
                AvailabilityStatus *status = &inventory.availability[inventory.itemCount];

                printf("Name: ");
                fgets(item->name, sizeof(item->name), stdin);
                item->name[strcspn(item->name, "\n")] = '\0';  // Remove newline

                printf("Category: ");
                fgets(item->category, sizeof(item->category), stdin);
                item->category[strcspn(item->category, "\n")] = '\0';  // Remove newline

                printf("Quantity: ");
                scanf("%d", &item->quantity);

                printf("Price: ");
                scanf("%f", &item->price);

                status->inStock = item->quantity > 0;
                status->outOfStock = !status->inStock;

                inventory.itemCount++;
                printf("Grocery item added successfully.\n\n");
                break;

            case 2: // List All Grocery Items
                if (inventory.itemCount == 0) {
                    printf("No grocery items in the inventory.\n\n");
                    break;
                }

                printf("\n%-20s %-15s %-10s %-10s %-s\n", "Name", "Category", "Quantity", "Price", "Availability");

                for (int i = 0; i < inventory.itemCount; i++) {
                    const GroceryItem *item = &inventory.items[i];
                    const AvailabilityStatus *status = &inventory.availability[i];
                    printf("%-20s %-15s %-10d %-10.2f %-s\n\n", item->name, item->category, item->quantity, item->price,
                        status->inStock ? "In Stock" : "Out of Stock");
                }
                break;

            case 3: // Update Quantity
                {
                    char name[100];  // Declare the name variable here, scoped to case 3

                    printf("Enter the name of the item to update: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';  // Remove newline

                    bool found = false;
                    for (int i = 0; i < inventory.itemCount; i++) {
                        GroceryItem *item = &inventory.items[i];
                        if (strcmp(item->name, name) == 0) {
                            printf("Enter the new quantity for %s: ", name);
                            scanf("%d", &item->quantity);
                            getchar();  // Consume newline

                            AvailabilityStatus *status = &inventory.availability[i];
                            status->inStock = item->quantity > 0;
                            status->outOfStock = !status->inStock;

                            printf("Quantity updated successfully.\n\n");
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Item is not found.\n");
                    }
                    break;
                }

            case 4: // Remove Grocery Item
                {
                    char name[100];  // Declare the name variable here, scoped to case 4

                    printf("Enter the name of the item to remove: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';  // Remove newline

                    bool found = false;
                    for (int i = 0; i < inventory.itemCount; i++) {
                        if (strcmp(inventory.items[i].name, name) == 0) {
                            for (int j = i; j < inventory.itemCount - 1; j++) {
                                inventory.items[j] = inventory.items[j + 1];
                                inventory.availability[j] = inventory.availability[j + 1];
                            }
                            inventory.itemCount--;
                            printf("Grocery item %s removed successfully!\n\n", name);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Item does not found in the inventory.\n\n");
                    }
                    break;
                }

            case 5: // Exit
                printf("Exiting program.\n\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}
