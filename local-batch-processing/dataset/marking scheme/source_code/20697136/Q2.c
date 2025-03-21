#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// structs
typedef struct { // struct for individual items
    char name[100];
    char category[50];
    int quantity;
    float price;
} item;
typedef struct { // struct for availability status
    bool inStock;
    bool outStock;
} availability;
struct i{ // struct for inventory as a whole
    item list[100];
    availability status[100];
    int counter;
} inventory;

// function prototypes
void addItem();
void displayItems();
void updateItem();
void deleteItem();

// main function
int main(){
    int mainChoice = 0;

    // main menu
    do{    
    printf("\t----------------------------------------\n");
    printf("\tGrocery Inventory Management System\n");
    printf("\t1. Add Grocery Item\n");
    printf("\t2. List All Grocery Items\n");
    printf("\t3. Update Quantity\n");
    printf("\t4. Remove Grocery Item\n");
    printf("\t5. Exit\n");
    printf("\t----------------------------------------\n");

        printf("\tEnter your choice: ");
        // Get input from user
        scanf("%d", &mainChoice);
        getchar(); // read new line

        // switch case handling user inputs
        switch (mainChoice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                updateItem();
                break;
            case 4: 
                deleteItem();
                break;
            case 5:
                printf("\n\t----------------------------------------------------------\n");
                printf("\tThank you for using the Grocery Inventory Management System!\n\tExiting the Program.");
                printf("\n\t----------------------------------------------------------\n");
                break;
            default:
                printf("\tInvalid input. Please input a number from 1 - 5.\n");
                break;
        }
    }while(mainChoice != 5); // loop while user input is not exit code
    return 0;
}    
// add grocery item
void addItem(){
    // prompt for and get user input for name
    printf("\n\tEnter Item Name: ");
    fgets(inventory.list[inventory.counter].name, 100, stdin);
    // remove new line
    inventory.list[inventory.counter].name[strcspn(inventory.list[inventory.counter].name, "\n")] = '\0';

    // prompt for and get user input for email
    printf("\tEnter Category: ");
    fgets(inventory.list[inventory.counter].category, 50, stdin);
    // remove new line
    inventory.list[inventory.counter].category[strcspn(inventory.list[inventory.counter].category, "\n")] = '\0';

    // prompt for and get user input for quantity
    printf("\tEnter Quantity: ");
    scanf("%d", &inventory.list[inventory.counter].quantity);
    getchar(); // read new line

    // prompt for and get user input for price
    printf("\tEnter Price: ");
    scanf("%f", &inventory.list[inventory.counter].price);
    getchar(); // read new line

    // success message
    printf("\tGrocery Item added successfully!\n");
    inventory.counter++; // increment item counter
}
// list all grocery items and their availability
void displayItems(){
    if(inventory.counter == 0){ // base case if there are no items saved
        printf("\n\tNo grocery items in the inventory.\n");
    }
    for(int i=0; i<inventory.counter; i++){
        char currentStatus[15];
        printf("\n\t----------------------------------------\n");
        // printf name, category, quantity, price of each item
        printf("\tName: %s\n", inventory.list[i].name);
        printf("\tCategory: %s\n", inventory.list[i].category);
        printf("\tQuantity: %d\n", inventory.list[i].quantity);
        printf("\tPrice: %.2f\n", inventory.list[i].price);        
        // set general condition for in/out of stock
        if (inventory.list[i].quantity == 0){ // if quantity of item is 0
            inventory.status[i].outStock = true; // set out of stock as true
        }
        else{
            inventory.status[i].inStock = true; // else if it has quantity>0, set in stock as true
        }
        // print status of each item
        if(inventory.status[i].outStock){ // if out of stock = true
            printf("\tStatus: Out of stock\n"); // print status
        }
        else if(inventory.status[i].inStock){ // if in stock = true
            printf("\tStatus: In Stock\n"); // print status
        }
    }
}
// update the quantity of a grocery item
void updateItem(){
    char updateChoice[100];
    printf("\tEnter the name of the item to update quantity: ");
    // user enters name of item to edit
    fgets(updateChoice, 100, stdin);
    updateChoice[strcspn(updateChoice, "\n")] = '\0'; // remove new line

    for(int i=0; i<inventory.counter; i++){
        // if user input matches any saved item:
        if(strcmp(inventory.list[i].name, updateChoice) == 0){
            // enter new quantity
            printf("\tEnter new quantity for %s: ", inventory.list[i].name);
            scanf("%d", &inventory.list[i].quantity);
            getchar(); // read new line
            printf("\n\tQuantity updated successfully!\n"); // success message
            break;
        }
        // if user input does not match any saved item:
        else if((i==inventory.counter-1) && strcmp(inventory.list[i].name, updateChoice) != 0){
            printf("\n\tGrocery item not found. \n"); // print error message
        }
    }
} 
// remove a grocery item from the inventory
void deleteItem(){
    char deleteChoice[100];
    printf("\tEnter the name of the item to delete: ");
    // user enters name of item to delete
    fgets(deleteChoice, 100, stdin);
    deleteChoice[strcspn(deleteChoice, "\n")] = '\0'; // remove new line

    for(int i=0; i<inventory.counter; i++){
        // if user input matches any saved item:
        if(strcmp(inventory.list[i].name, deleteChoice) == 0){
            // delete item
            inventory.list[i] = inventory.list[i+1];
            inventory.counter--; // decrement item counter
            printf("\tGrocery item removed successfully!\n\n"); // success message
            break;
        }
        // if user input does not match any saved item:
        else if((i==inventory.counter-1) && strcmp(inventory.list[i].name, deleteChoice) != 0){
            printf("\n\tGrocery item not found. \n"); // print error message
        }
    }
}