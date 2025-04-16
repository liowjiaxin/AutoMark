#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct  // struct for items 
{
    char name[100];
    char cat[50];
    int qty;
    float price;
    bool stock_status;
} groc_item;

typedef struct // struct for the whole inventory
{
    groc_item items[100];
    int item_count;
} groc_inventory;

void add_item(groc_inventory *invtry) {  // function for adding items to the inventory with user input
    if (invtry->item_count >= 100) {
        printf("Inventory is full, more items cannot be added \n");
        return;
    }

    groc_item *new_item = &invtry->items[invtry->item_count]; 
    getchar(); 
    printf("Enter item name : ");
    scanf("%[^\n]", new_item->name);
    getchar();

    printf("Enter category : ");
    scanf("%[^\n]", new_item->cat);
    getchar();

    printf("Enter quantity : ");
    scanf("%d", &new_item->qty);

    printf("Enter price : ");
    scanf("%f", &new_item->price);

    new_item->stock_status = (new_item->qty > 0); 
    invtry->item_count++;

    printf("Item added successfully!\n");
}

void list_items(const groc_inventory *invtry) {  // function to list details of every item from the inventory struct
    if (invtry->item_count == 0) {
        printf("Inventory is empty, there is no item to list \n");
        return;
    } 

    printf("\nGrocery Inventory Management System\n");
    for (int i = 0; i < invtry->item_count; i++) {
        groc_item item = invtry->items[i];
        printf("Name: %s\n", item.name);
        printf("Category: %s\n", item.cat);
        printf("Quantity: %d\n", item.qty);
        printf("Price: %.2f\n", item.price);
        printf("Status: %s\n", item.stock_status ? "In Stock" : "Out of Stock");
        printf("---------------------------------------------\n");  // blank line to diffrentiate between products :)
    }       
}

void update_qty(groc_inventory *invtry) { // function to update quantity x
    if (invtry->item_count == 0) {
        printf("Inventory is empty, there is no item to update the quantity for\n");
        return;
    }

    getchar(); 
    char name[100];
    printf("Enter name of the grocery item to update quantity: ");
    scanf("%[^\n]", name);
    getchar();

    for (int i = 0; i < invtry->item_count; i++) {
        if (strcasecmp(invtry->items[i].name, name) == 0) { // strcasecmp for case insensitivty in search 
            printf("Enter new quantity for %s: ", invtry->items[i].name);
            scanf("%d", &invtry->items[i].qty);
            if (invtry->items[i].qty < 0) {
                printf("Enter a positive number or 0\n");
                return;
            }
            invtry->items[i].stock_status = (invtry->items[i].qty > 0);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found\n");
}

void remove_item(groc_inventory *invtry) { // function to remove items from the struct
    if (invtry->item_count == 0) {
        printf("Inventory is empty, there is nothing to remove\n");
        return;
    }    

    getchar(); // 
    char name[100];
    printf("Enter name of grocery item to remove: ");
    scanf("%[^\n]", name);
    getchar();

    for (int i = 0; i < invtry->item_count; i++) {
        if (strcasecmp(invtry->items[i].name, name) == 0) { // Case-insensitive comparison
            for (int j = i; j < invtry->item_count - 1; j++) {
                invtry->items[j] = invtry->items[j + 1];
            }
            invtry->item_count--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory\n");
}

int main() {
    groc_inventory invtry;
    invtry.item_count = 0;
    int choice;

    while (1) {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List all Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&invtry);
                break;
            
            case 2:
                list_items(&invtry);
                break;

            case 3:
                update_qty(&invtry);
                break;

            case 4:
                remove_item(&invtry);
                break;

            case 5:
                printf("Exiting system\n");
                return 0;

            default:
                printf("Invalid choice, please re-enter your choice\n");
        }
    }
}
