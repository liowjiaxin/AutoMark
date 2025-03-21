//include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//define
#define SIZE 100

//struture
struct Grocery {
    char name[101];
    char category[51];
    int quantity;
    float price;
};

//global variables
struct Grocery item[SIZE];
bool status[SIZE];
int total;

//check boolean and display status
void statusDisplay(int index){
    if (status[index]){     //true
        printf("Status: In Stock\n");
    }else{                  //false
        printf("Status: Out of Stock\n");
    }
}

//count total number of grocery item name in inventory
int checkIndex(){
    for (int i=0;i<SIZE;i++){
        if (item[i].name[0]=='\0'){ //no grocery than stop counting
            return i;
        }else{
            continue;
        }
    }
    return -1;                      //inventory is full
}

//add new grocery item
void addItem(){
    int index = checkIndex(item);   //count total number of grocery item name in inventory
    if (index==-1){                 //if inventory is full, stop adding new item
        printf("Grocery items reach maximum. Cannot add more grocery item.\n");
        return;
    }

    //Add new grocery item information
    printf("Enter Item Name: ");    //item name
    fgets(item[index].name, sizeof(item[index].name), stdin);
    item[index].name[strcspn(item[index].name, "\n")] = '\0';

    printf("Enter Category: ");     //item category
    fgets(item[index].category, sizeof(item[index].category), stdin);
    item[index].category[strcspn(item[index].category, "\n")] = '\0'; 

    printf("Enter Quantity: ");     //item quantity
    int quantity;
    scanf(" %d", &quantity);
    while (getchar() != '\n');

    printf("Enter Price: ");        //item price
    float price;
    scanf(" %f", &price);
    while (getchar() != '\n');

    item[index].quantity=quantity;  //copy the data input into the information 
    item[index].price=price;
    total+=quantity;                //update total number of grocery items in inventory
    
    //check availability status
    if (quantity!=0){               //in stock
        status[index]=true;
    }else{                          //out of stock
        status[index]=false;
    }
    
    //if number of item name not reach the maximum, insert NULL value in next index for remark
    if (index<(SIZE-1)){
        item[index+1].name[0]='\0';
    }
    printf("Grocery item added successfully!\n");
    return;                         //return main menu
}

//list all grocery items
void listItem(){
    int index=checkIndex();         //count total number of grocery name in inventory
    if (index==0){                  //if no items then return main menu
        printf("No grocery items in the inventory.\n");
        return;
    }
    
    //loop to list all items
    for (int i=0;i<index;i++){      //list until all grocery items in inventory have been listed
        printf("Name: %s\n",item[i].name);
        printf("Category: %s\n",item[i].category);
        printf("Quantity: %d\n",item[i].quantity);
        printf("Price: %.2f\n",item[i].price);
        statusDisplay(i);           //base on boolean in status list, show availability status
    }
    printf("Total number of grocery items in the inventory: %d\n",total);
    return;                         //return main menu
}

//search an item and update item quantity
void updateQuantity(){
    int index=checkIndex();         //count total number of grocery item name in inventory
    if (index==0){                  //if no grocery item in inventory, return main menu
        printf("No grocery items in the inventory.\n");
        return;
    }

    //Input for item name to update
    printf("Enter name of the grocery item to update quantity: ");
    char name[101];
    int quantity;
    scanf(" %[^\n]",name);
    while (getchar() != '\n');      //clear input buffer

    //Searching item name one by one
    for (int i=0;i<index;i++){
        if(strcmp(item[i].name,name)==0){   //if item name found, prompt user input new quantity
            printf("Enter new quantity for %s: ",name);
            scanf(" %d",&quantity);
            while (getchar() != '\n');      //clear input buffer

            total-=item[i].quantity;        //update the total number of items in inventory
            total+=quantity;                
            item[i].quantity=quantity;      //update the item quantity
            //update item availability status
            if (quantity!=0){       //in stock
                status[i]=true;
            }else{                  //out of stock
                status[i]=false;
            }
            printf("Quantity updated successfully!\n");
            return;                 //return main menu
        }
    }
    printf("'%s' not found.\n",name);
    return;                         //return main menu if searching fail
}

//remove item and item information by name
void removeItem(){
    int index=checkIndex();         //count number of item name in inventory
    if (index==0){                  //if no grocery item in inventory, return main menu
        printf("No grocery items in the inventory.\n");
        return;
    }

    //Input for name of item to remove
    printf("Enter name of the grocery item to remove: ");
    char name[101];
    int quantity;
    scanf(" %[^\n]",name);
    while (getchar() != '\n');      //clear input buffer

    //searching item one by one until all inventory searched
    for (int i=0;i<index;i++){
        if(strcmp(item[i].name,name)==0){   //if item found, deletion start
            if ((index==1)||(i==index-1)){  //if only one grocery in inventory or it located last in list
                total-=item[i].quantity;    //update total number of items in inventory 
                item[i].name[0]='\0';       //replace name to NULL as a remark for end of list
                printf("Grocery item '%s' removed successfully!",name);
                return;                     //return main menu
            }

            //for grocery item name that is not placed at last or the only grocery
            total-=item[i].quantity;           //update total number of items in inventory
            //replace current item information with the item placed at last in the list
            strcpy(item[i].name,item[index-1].name);
            strcpy(item[i].category,item[index-1].category);
            item[i].price=item[index-1].price;
            item[i].quantity=item[index-1].quantity;
            status[i]=status[index-1];      //replace availability status
            item[index-1].name[0]='\0';     //set new end of list remark
            printf("Grocery item '%s' removed successfully!",name);
            return;                         //item remove, return main menu
        }
    }
    printf("'%s' not found.\n",name);   //item name not found in inventory
    return;                             //return main menu
}

//main program
int main(){
    item[0].name[0]='\0';           //as not yet add item, set first index name as Null for remark
    //main operation loop
    while (1){
        //display menu
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        while (getchar() != '\n'); //Clear input buffer

        switch (choice){
            case 1:                 //add item information into inventory
                addItem();
                break;
            case 2:                 //list all items with informations
                listItem();
                break;
            case 3:                 //search and update an item quantity
                updateQuantity();
                break;
            case 4:                 //search and remove an item information
                removeItem();
                break;
            case 5:                 //exit program
                printf("Exiting...\n");
                exit(0);
            default:                //default
                printf("Please enter a valid choice.\n");
        }
    }

    return 0;
}