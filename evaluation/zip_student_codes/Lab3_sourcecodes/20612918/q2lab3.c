#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define NAME_LENGTH 100
#define CATEGORY_LENGTH 50
#define MAXGROCERY 100

typedef struct {
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    int quantity;
    float price;
    bool inStock;
} groceryItem;

typedef struct {
    groceryItem items[MAXGROCERY];
    int total;
} groceryInventory;

void addGrocery(groceryInventory *inventory);
void listGrocery(const groceryInventory *inventory);
void updateQuantity(groceryInventory *inventory);
void removeGrocery(groceryInventory *inventory);



int main(){
    groceryInventory inventory = {0};
    int choice;

    do{
        //display menu
        printf("\nGrocery Inventory Management System\n1. Add Grocery Item\n2. List all Grocery Items\n3. Update Quanitity\n4. Remove Grocery Item\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            addGrocery(&inventory);
            break;
        case 2:
            listGrocery(&inventory);
            break;
        case 3:
            updateQuantity(&inventory);
            break;
        case 4:
            removeGrocery(&inventory);
            break;
        case 5:
            printf("Exiting..");
            break;
        }
    }while (choice != 5);

    return 0;
}

//function to add item to grocery
void addGrocery(groceryInventory *inventory){
    //checking if number of items exceeds maximum
    if ((*inventory).total >= MAXGROCERY){
        printf("Inventory is full.\n");
        return;
    }

    groceryItem newItem;

    getchar(); //clear leftover newline from previous input
    
    //input new item namw
    printf("Enter Item Name: ");
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0';

    //input new item category
    printf("Enter Category: ");
    fgets(newItem.category, CATEGORY_LENGTH, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0';

    //input new item quantity
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    getchar(); // Clear newline after scanf

    //input new  item  price
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    getchar(); // Clear newline after scanf

    newItem.inStock = (newItem.quantity > 0);

    //adding new item to inventory structure
    (*inventory).items[(*inventory).total] = newItem;  
    (*inventory).total++;

    printf("Grocery item added successfully!\n");
}

//function to display all items in grocery inventory
void listGrocery(const groceryInventory *inventory){
    if ((*inventory).total == 0){
        printf("No grocery items in inventory. \n");
        return;
    }

    //loop to display all items in the grocery
    for (int i = 0; i < (*inventory).total; i++){
        printf("Name: %s\n", (*inventory).items[i].name);
        printf("Category: %s\n", (*inventory).items[i].category);
        printf("Quantity: %d\n", (*inventory).items[i].quantity);
        printf("Price: %.2f\n\n", (*inventory).items[i].price);
         printf("Stock Status: %s\n", (*inventory).items[i].inStock ? "In Stock" : "Out of Stock");
    }
}

//function to update quantity of a grocery item
void updateQuantity(groceryInventory *inventory){
    char updateItem[NAME_LENGTH];

    if ((*inventory).total == 0){
        printf("No grocery items in inventory. \n");
        return;
    }

    getchar();

    //input name of grocery item to be updated
    printf("Enter name of the grocery item to update quantity: ");
    fgets(updateItem, NAME_LENGTH, stdin);
    updateItem[strcspn(updateItem, "\n")] = '\0';

    //loop to find the name
    for (int i = 0; i < (*inventory).total; i++) {
        if (strcmp((*inventory).items[i].name, updateItem) == 0) {
            //input new item quantity
            printf("Enter new quantity for %s: ", (*inventory).items[i].name);
            scanf("%d", &(*inventory).items[i].quantity);
            getchar(); 

            (*inventory).items[i].inStock = ((*inventory).items[i].quantity > 0);

            printf("Quantity updated successfully!\n");
            return;
        }
    }
    //if item is not found
    printf("Item with the name '%s' not found in the inventory.\n", updateItem);
}

//function to remove an item from grocery structure
void removeGrocery(groceryInventory *inventory) {
    if ((*inventory).total == 0) {
        printf("No grocery items in inventory.\n");
        return;
    }

    getchar();

    char removeName[NAME_LENGTH];
    //input  name of grocery item to be removed
    printf("Enter name of the grocery item to remove: ");
    fgets(removeName, NAME_LENGTH, stdin);
    removeName[strcspn(removeName, "\n")] = '\0'; // Remove newline

    //loop to find item
    for (int i = 0; i < (*inventory).total; i++) {
        if (strcmp((*inventory).items[i].name, removeName) == 0) {
            //removing item 
            for (int j = i; j < (*inventory).total - 1; j++) {
                (*inventory).items[j] = (*inventory).items[j + 1];
            }
            //reducing number of items
            (*inventory).total--;
            printf("Grocery item '%s' removed successfully!\n", removeName);
            return;
        }
    }
        //if item not found
        printf("Item with the name '%s' not found in the inventory.\n", removeName);
}
