#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_ITEMS 100

typedef struct {
    char Name[MAX_NAME_LENGTH];
    char Category[MAX_CATEGORY_LENGTH];
    int Quantity;
    float Price;
} Groceryitem;

typedef struct {
    int stock;
} stock;

typedef struct {
    Groceryitem item[MAX_ITEMS];
    stock availablility[MAX_ITEMS];
    int Counter;
} Groceryinventory;
//Functio to add grocery item
void Add_Grocery_item(Groceryinventory *inventory){
    Groceryitem new_item;
    printf("Enter Item Name: ");
    fgets(new_item.Name, sizeof(new_item.Name), stdin);
    new_item.Name[strcspn(new_item.Name, "\n")] = '\0';
    
    printf("Enter Category: ");
    fgets(new_item.Category,sizeof(new_item.Category), stdin);
    new_item.Category[strcspn(new_item.Category, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &new_item.Quantity);
    getchar();

    printf("Enter Price: ");
    scanf("%f", &new_item.Price);
    getchar();

    inventory->item[inventory->Counter] = new_item;
    inventory->availablility[inventory->Counter].stock = (new_item.Quantity > 0 ) ? 1 : 0;
    inventory->Counter++;

    printf("Grocery Item added successfully!\n");
}
//Function to list all grocery items with their availability 
void List_Grocery_item(const Groceryinventory *inventory) {
    if (inventory->Counter == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }
    for(int i = 0; i < inventory->Counter; i++) {
        printf("Name: %s\n", inventory->item[i].Name);
        printf("Category: %s\n", inventory->item[i].Category);
        printf("Quantity: %d\n", inventory->item[i].Quantity);
        printf("Price: %.2f\n", inventory->item[i].Price);
        printf("Status: %s\n", inventory->availablility[i].stock ? "In Stock" : "Out of Stock");
    }
}
//Function to update the quantity of a frocery item
void Update_Quantity(Groceryinventory *inventory) {
    if (inventory->Counter == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }
    char item_Name[MAX_NAME_LENGTH];
    printf("Enter name of the frocery item to update quantity: ");
    fgets(item_Name, sizeof(item_Name), stdin);
    item_Name[strcspn(item_Name, "\n")] = '\0';

    for (int i = 0; i <= inventory->Counter; i++) {
        if (strcmp(inventory->item[i].Name, item_Name) == 0) {  //Search the grocery item from the inventory
            printf("Enter new quantity: ");
            scanf("%d", &inventory->item[i].Quantity);
            getchar();

            inventory->availablility[i].stock = (inventory->item[i].Quantity > 0) ? 1 : 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Quantity updated successfully!\n");
}
//Function to remove a grocery item from the inventory
void Remove_Grocery_item(Groceryinventory *inventory) {
    if (inventory->Counter == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }
    char item_Name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    fgets(item_Name, sizeof(item_Name), stdin);
    item_Name[strcspn(item_Name, "\n")] = '\0';

    for (int i = 0; i < inventory->Counter; i++) {
        if (strcmp(inventory->item[i].Name, item_Name) == 0) {  //Search the grocery item from the inventory
            for(int j = i; j < inventory->Counter - 1; j++) {
                inventory->item[j] = inventory->item[j + 1];
                inventory->availablility[j] = inventory->availablility[j + 1];
            }
            inventory->Counter--;
            printf("Grocery item '%s' removed successfully!\n", item_Name);
            return;
        }
    }
}


int main(){
    Groceryinventory inventory = { .Counter = 0};
    int choice;

    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            Add_Grocery_item(&inventory);
            break;
        case 2:
            List_Grocery_item(&inventory);
            break;
        case 3 :
            Update_Quantity(&inventory);
            break;
        case 4 :
            Remove_Grocery_item(&inventory);
            break;
        default:
            break;
        }
    } while (choice != 5);

    return 0;
}