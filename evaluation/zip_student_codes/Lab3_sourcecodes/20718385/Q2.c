#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_CATEGORY 100
#define MAX_ITEM 100

// Struct for grocery item
typedef struct {
        char name[MAX_NAME];
        char category[MAX_CATEGORY];
        int quantity;
        float price;
        bool inStock;
        bool outOfStock;
    } item;

item inventory[MAX_ITEM];
int total = 0;

// Function to add item
void addItem(){
    if(total >= MAX_ITEM){
        printf("Inventory is full!\n");
        return;
    }
    printf("Enter Item Name: ");
    scanf(" %[^\n]", inventory[total].name);
    printf("Enter Category: ");
    scanf(" %[^\n]", inventory[total].category);
    printf("Enter Quantity: ");
    scanf("%d", &inventory[total].quantity);
    printf("Enter Price: ");
    scanf("%f", &inventory[total].price);
    total++;
    printf("Grocery item added successfully!\n");
}

// Function to list item
void listItem(){
    if (total == 0){
        printf("Grocery inventory is empty.\n");
        return;
    }
    for(int i = 0; i < total; i++){
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: $%.2f\n", inventory[i].price);      
        printf("\n");
    }
}

// Function to update quantity
void updateQuantity(){
    char name[MAX_NAME];
    int newQuantity;

    printf("Enter name of grocery item to update quantity: ");
    scanf(" %[^\n]", &name);

    for(int i = 0; i < total; i++){
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Grocery item not found!\n");
}

// Funtion to remove item
void removeItem(){
    char name[MAX_NAME];

    printf("Enter name of the grocery item to remove: ");
    scanf(" %[^\n]", &name);
    for (int i = 0; i < total; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < total - 1; j++) {
            inventory[j] = inventory[j + 1];
            }
            total--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Error: Grocery item not found.\n");
}


int main(){
    int choice = 0;

    while(choice != 5){
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addItem();
                break;
            case 2:
                listItem();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter a valid choice!\n");
        }
    }
    
    return 0;
}