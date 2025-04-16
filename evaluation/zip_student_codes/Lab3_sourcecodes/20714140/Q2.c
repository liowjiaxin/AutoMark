#include <stdio.h>
#include <string.h>

struct Item {
    char name[100];
    char category[50];
    int quantity;
    float price;
};

void AddGroItem(struct Item gro_item[], int *item_count) {

    if (*item_count >= 100) {
        printf("Inventory is full!\n");
        return;
    }
    
    struct Item new_item;
    printf("Enter Item Name: ");
    getchar();
    fgets(new_item.name, sizeof(new_item.name), stdin);
    new_item.name[strcspn(new_item.name, "\n")] = 0;  // Remove newline

    printf("Enter Category: ");
    fgets(new_item.category, sizeof(new_item.category), stdin);
    new_item.category[strcspn(new_item.category, "\n")] = 0;  // Remove newline

    printf("Enter Quantity: ");
    scanf("%d", &new_item.quantity);

    printf("Enter Price: ");
    scanf("%f", &new_item.price);

    gro_item[*item_count] = new_item;
    (*item_count)++;
    printf("Grocery item added successfully!\n");
}

void ListItem(struct Item gro_item[], int item_count) {
    if (item_count == 0) {
        printf("No grocery items in inventory.\n");
        return;
    }
    
    for (int i = 0; i < item_count; i++) {
        printf("Name: %s\nCategory: %s\nQuantity: %d\nPrice: %.2f\n", gro_item[i].name, gro_item[i].category, gro_item[i].quantity, gro_item[i].price);
        if (gro_item[i].quantity != 0){
            printf("Status: In Stock\n");
        } else {printf("Status: Out of Stock\n");}
    }
}

void UpdateQuantity(struct Item gro_item[], int item_count) {
    char item_name[100];
    int new_quantity;
    
    printf("Enter name of the grocery item to update quantity: ");
    getchar();
    fgets(item_name, sizeof(item_name), stdin);
    item_name[strcspn(item_name, "\n")] = 0;  // Remove newline

    for (int i = 0; i < item_count; i++) {
        if (strcmp(gro_item[i].name, item_name) == 0) {
            printf("Enter new quantity for %s: ", gro_item[i].name);
            scanf("%d", &new_quantity);
            gro_item[i].quantity = new_quantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found!\n");
}

//
void RemoveItem(struct Item gro_item[], int *item_count) {
    char item_name[100];
    
    printf("Enter name of the grocery item to remove: ");
    getchar();
    fgets(item_name, sizeof(item_name), stdin);
    item_name[strcspn(item_name, "\n")] = 0;  // Remove newline

    for (int i = 0; i < *item_count; i++) {
        if (strcmp(gro_item[i].name, item_name) == 0) {
            for (int j = i; j < *item_count - 1; j++) { 
                gro_item[j] = gro_item[j + 1]; // Shift items left after removal
            }
            (*item_count)--;  // Decrease item count
            printf("Grocery item '%s' removed successfully!\n", item_name);
            return;
        }
    }

    printf("Item not found!\n");
}

int main(){
    struct Item gro_item[100]; //Array to hold 100 items
    int item_count = 0; //number of item in the inventory
    
    int choice = 0;
    while (choice != 5) { //Selection Menu
        printf("Grocery Inventory Management System\n1. Add Grocery Item\n2. List All Grocery Items\n3. Update Quantity\n4. Remove Grocery Item\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            AddGroItem(gro_item, &item_count);  //Add Grocery Item
        }
        else if (choice == 2) {
            ListItem(gro_item, item_count);  // List all grocery items with their availability
        }
        else if (choice == 3) {
            UpdateQuantity(gro_item, item_count);  // Update the quantity of a grocery item
        }
        else if (choice == 4) {
            RemoveItem(gro_item, &item_count);  // Remove a grocery item from the inventory
        } else if (choice != 5) {
            printf("There is no such option. Please enter again.\n");
        }
    }
    printf("Exiting...\n");

    return 0;
}