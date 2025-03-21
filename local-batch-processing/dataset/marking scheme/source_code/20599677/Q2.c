#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

//structure to store grocery items' info
typedef struct{
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool in_stock;
    bool out_stock;
}info_grocery;
info_grocery inventory[MAX_SIZE]; //array to store inventory
int count = 0;

//function to add grocery item
void add_grocery(){
    if(count >= MAX_SIZE){
        printf("Inventory is full.\n");
        return;
    }

    info_grocery *item = &inventory[count]; //pointer to next slot available

    printf("Enter Item Name: ");
    getchar();
    fgets(item -> name, sizeof(item -> name), stdin);
    item -> name[strcspn(item -> name, "\n")] = '\0'; //remove trailing newline

    printf("Enter Category: ");
    fgets(item -> category, sizeof(item -> category), stdin); 
    item -> category[strcspn(item -> category, "\n")] = '\0'; //remove trailing newline

    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter Price: ");
    scanf("%f", &item->price);
    //set stock availability based on quantity
    item -> in_stock = item -> quantity > 0;
    item -> out_stock = item -> quantity == 0;
    count++; //increment inventory count
    printf("Grocery item added successfully!\n");

}

//function to show list of grocery items
void list_grocery(){
    if(count == 0){
        printf("No grocery items in the inventory.\n");
        return;
    }

    for(int i = 0; i < count; i++){
        info_grocery *item = &inventory[i];
        printf("%d. Name: %s\n", i + 1, item -> name);
        printf("   Category: %s\n", item -> category);
        printf("   Quantity: %d\n", item -> quantity);
        printf("   Price: %.2f\n", item -> price);
        printf("   Availability: %s\n", item -> in_stock ? "In Stock":"Out of Stock");
    }

}

//function to update quantity
void update_grocery(){
    if (count == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }

    char item_name[100];
    printf("Enter the name of the grocery item to update quantity: ");
    getchar(); //consume newline left in input buffer
    fgets(item_name, sizeof(item_name), stdin);
    item_name[strcspn(item_name, "\n")] = '\0'; //remove trailing newline

    int index = -1;
    //search item by name
    for(int i = 0; i < count; i++){
        if(strcmp(inventory[i].name, item_name) == 0){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Item not found.\n");
        return;
    }

    info_grocery *item = &inventory[index]; //pointer to found item

    printf("Enter new quantity for %s: ", item -> name);
    scanf("%d", &item -> quantity); //update quantity

    //update stock availability based on new quantity
    item -> in_stock = item -> quantity > 0;
    item -> out_stock = item -> quantity == 0;
    printf("Quantity updated successfully!\n");

}


//function to remove grocery item
void remove_grocery(){
    if(count == 0){
        printf("No grocery items in the inventory to remove.\n");
        return;
    }

    char item_name[100];
    printf("Enter name of the grocery item to remove: ");
    getchar(); //consume newline left in buffer
    fgets(item_name, sizeof(item_name), stdin);
    item_name[strcspn(item_name, "\n")] = '\0'; //remove trailing newline

    int index = -1;
    //search item by name
    for(int i = 0; i < count; i++){
        if(strcmp(inventory[i].name, item_name) == 0){
            index = i;
            break;
        }
    }

    if (index == -1){
        printf("Item not found.\n");
        return;
    }

    //shift items to fill gap
    for(int i = index; i < count - 1; i++){
        inventory[i] = inventory[i + 1];
    }

    count--; //decrement inventory count
    printf("Grocery item '%s' removed successfully!\n", item_name);
}

int main(){

    while(1){
        int choice;

        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        //prompt user to enter a choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_grocery();
                break;

            case 2:
                list_grocery();
                break;

            case 3:
                update_grocery();
                break;

            case 4:
                remove_grocery();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Error: Please enter a number between 1 and 5.\n");


        }

    }


    return 0;
}