#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50
#define MAX_SIZE 100

//Prototype
void clearBufferInput();
void displayMenu();
void addGrocery();
void listGrocery();
void updateQuantity();
void removeGrocery();

struct Item{
    char name[MAX_LENGTH];
    char category[MAX_LENGTH];
    int quantity;
    float price; 
};
struct Item itemNo[MAX_SIZE];
int itemCount =0;
int avaibility[MAX_SIZE] = {0};


void clearBufferInput(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF){}
}

void displayMenu(){
    puts("Grocery Inventory Management System");
    puts("1. Add Grocery Item");
    puts("2. List All Grocery Items");
    puts("3. Update Qunality");
    puts("4. Remove Grocery Item");
    puts("5. Exit");
    printf("Enter your choice: ");
}

void addGrocery(){

    // Ask the user the data and directly save into itemNo struct
    // Increase the counter for total item
    printf("Enter Item Name: ");
    fgets(itemNo[itemCount].name, MAX_LENGTH, stdin);

    printf("Enter Category: ");
    fgets(itemNo[itemCount].category, MAX_LENGTH, stdin);

    printf("Enter Quantity: ");
    scanf("%d", &itemNo[itemCount].quantity);
    clearBufferInput();

    printf("Enter Price: ");
    scanf("%f", &itemNo[itemCount].price);

    clearBufferInput();
    printf("\n");

    itemCount++;
}

void listGrocery(){
    printf("\n");
    // Display by looping and increment of i.
    // Print the item sequencely
    for(int i = 0; i<itemCount; i++){
        printf("----  Item %d  ----\n", i+1); //The number of item
        printf("Name: %s", itemNo[i].name);
        printf("Category: %s", itemNo[i].category);
        printf("Quantity: %d\n", itemNo[i].quantity);
        printf("Price: %.2f\n", itemNo[i].price);
        printf("Status: ");
        (itemNo[i].quantity > 0) ?
        puts("In Stock") : puts("Out of Stock"); //Based on quantity to print in or out stock
        printf("\n");
    }
    printf(" ---- End List ----\n\n");
}

void updateQuantity(){
    char itemName[MAX_LENGTH];
    int found =0;
    int newQuantity = 0;

    printf("Enter name of the grocery item to update quantity: ");
    fgets(itemName, MAX_LENGTH, stdin);
    // Search similar item name and update it quanlity
    for (int i =0; i<itemCount; i++){ 
        if (!(strcmp(itemName,itemNo[i].name))){
            itemName[strcspn(itemName, "\n")] = '\0'; // Remove the new line character
            printf("Enter the new quantity for %s: ", itemName);
            scanf("%d", &newQuantity);
            itemNo[i].quantity = newQuantity;
            found = 1;
            break;
        }
    }

    //Print sentences if updated or not updated.
    if (found){
        puts("Quantity updated successfully! \n");
    }
    else{
        puts("Error, Item name doesn't exist!! \n");
    }
}

void removeGrocery(){
    char nameGrocery[MAX_LENGTH];
    int numGrocery = 0;
    int found = 0;
    printf("Enter name of the grocery item to remove: ");
    fgets(nameGrocery, MAX_LENGTH, stdin);
    
    // Save the number of item that want to delete
    for (int i = 0; i<itemCount; i++){
        if (!(strcmp(nameGrocery, itemNo[i].name))){
            numGrocery = i;
            found = 1;
            break;
        }
    }

    //If no item found, back to main menu
    if (found == 0){
        printf("Item name doesn't exist! \n\n");
        return;
    }

    // Rewrite the current item into next item
    // Reduce the counter for total item
    for (int i = numGrocery; i < itemCount; i++){
        itemNo[i] = itemNo[i+1];
    }
    itemCount--;

    nameGrocery[strcspn(nameGrocery, "\n")] = '\0';
    printf("Grocery item '%s' removed successfully!\n\n", nameGrocery);
}

int main(){
    int choice = 0;
    do{
        displayMenu();
        scanf("%d", &choice);
        clearBufferInput();

        switch (choice){
            case 1:
                addGrocery();
                break;
            case 2:
                listGrocery();
                break;

            case 3:
                updateQuantity();
                break;

            case 4:
                removeGrocery();
                break;

            case 5:
                puts("Exiting");
                break;

            default:
                printf("Invalid input, pls enter (1/2/3/4/5) \n");
                break;
        }

    }while (choice != 5);


}
