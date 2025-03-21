#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Structure for Grocery Item
typedef struct{
    char Name[100];
    char Category[50];
    int Quantity;
    float Price;
}GroceryItem;

// Structure for Availability
typedef struct{
    bool instock;
    bool outofstock;
}Availablity;

// Structure for Inventory
typedef struct{
    GroceryItem item[100];
    Availablity status;
    int num;
}Inventory;

Inventory inven;

// Declare functions
void addGroceryItem();
void listAllGroceryItems();
void updateQuantity();
void removeGroceryItem();

int main(){
    int choice;
    //Loop menu for grocery inventory management system
    do{
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                addGroceryItem();
                break;
            case 2:
                listAllGroceryItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeGroceryItem();
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice");
                continue;
        }
    }while(choice!=5);//Exit when choice is 5
    return 0;
}

//Function to add grocery item
void addGroceryItem(){
    //Input grocery item details
    printf("Enter Item Name: ");
    fgets(inven.item[inven.num].Name, 100, stdin);
    inven.item[inven.num].Name[strcspn(inven.item[inven.num].Name, "\n")] = '\0';//Remove newline character
    printf("Enter Category: ");
    fgets(inven.item[inven.num].Category, 50, stdin);
    inven.item[inven.num].Category[strcspn(inven.item[inven.num].Category, "\n")] = '\0'; //Remove newline character
    printf("Enter Quantity: ");
    scanf("%d", &inven.item[inven.num].Quantity);
    printf("Enter Price: ");
    scanf("%f", &inven.item[inven.num].Price);
    inven.num++; //Increment to number of grocery items
    printf("Grocery item added successfully\n");
}

//Function to list all grocery items
void listAllGroceryItems(){
    //Check if inventory is empty
    if (inven.num==0){
        printf("No grocery items in the inventory\n");
        return;
    }
    //Loop and display all grocery items
    for(int i=0; i<inven.num; i++){
        printf("Name: %s\n", inven.item[i].Name);
        printf("Category: %s\n", inven.item[i].Category);
        printf("Quantity: %d\n", inven.item[i].Quantity);
        printf("Price: %.2f\n", inven.item[i].Price);
        printf("Status: ");

        //Reset status
        inven.status.instock = false;
        inven.status.outofstock = false;
        
        //Check the status of grocery item
        if(inven.item[i].Quantity>0){
            inven.status.instock = true;
        }
        else{
            inven.status.outofstock = true;
        }
        if(inven.status.instock){
            printf("In Stock\n");
        }
        else if(inven.status.outofstock){
            printf("Out of Stock\n");
        }
    }
}

//Function to update quantity of grocery item
void updateQuantity(){
    char name[100];
    //Input name of grocery item to update quantity
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0'; //Remove newline character

    //Loop and search(compare) for the grocery item
    for(int i=0; i<inven.num; i++){
        if(strcasecmp(inven.item[i].Name, name)==0){
            //Update quantity
            printf("Enter new quantity for %s: ", inven.item[i].Name);
            scanf("%d", &inven.item[i].Quantity);
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    //If grocery item not found
    printf("Item not found\n");
}

//Function to remove grocery item
void removeGroceryItem(){
    char name[100];
    //Input name of grocery item to remove
    printf("Enter name of grocery item to remove: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';// Remove newline character

    //Loop and search(compare) for the grocery item
    for(int i=0; i<inven.num; i++){
        if(strcasecmp(inven.item[i].Name, name)==0){
            for(int j=i; j<inven.num-1; j++){
                //Replace and delete the matched grocery item
                inven.item[j] = inven.item[j+1];
            }
            inven.num--;//Decrement to the number of grocery items
            printf("Grocery item '%s' removed successfully\n", inven.item[i].Name);   
            return;
        }
    }
    //If grocery item not found
    printf("Item not found\n");
}

