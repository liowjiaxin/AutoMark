#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_NAME 100
#define MAX_CATEGORY 50
#define MAX_ITEMS 100

//defining the groceryitem struct
typedef struct {
    char name[MAX_NAME];
    char category[MAX_CATEGORY];
    int quantity;
    float price;
}Groceryitem;

typedef struct{
    bool Instock;  //boolean to store if item is in or out of stock

}Availabilitystatus;

typedef struct{
    Groceryitem groceryarray[MAX_ITEMS]; //array to store groceryitems
    Availabilitystatus availabilityarr[MAX_ITEMS]; //array to store availability status
    int itemcount;  
}GroceryInventory;


//adding new item to inventory function
void additem(GroceryInventory *inventory){

    //check if inventory is full
    if(inventory->itemcount>=MAX_ITEMS){
        printf("Inventory is full. Unable to add more items.\n");
        return;
    }

    //pointers for new item and its availability status
    Groceryitem *item=&inventory->groceryarray[inventory->itemcount];
    Availabilitystatus *status=&inventory->availabilityarr[inventory->itemcount];


    printf("Enter Item Name: ");
    getchar();  //clear newline left from previour input

    fgets(item->name,MAX_NAME,stdin);
    item->name[strcspn(item->name,"\n")]='\0';  //remove trailing newline


    printf("Enter Category: ");

    fgets(item->category,MAX_CATEGORY,stdin);
    item->category[strcspn(item->category,"\n")]='\0';  //remove trailing newline


    printf("Enter Quantity: ");
    scanf("%d",&item->quantity);

    printf("Enter Price: ");
    scanf("%f",&item->price);

    getchar();  //clear newline character left from scanf

    inventory->itemcount++;
    if(item->quantity >0){
        status->Instock=1;
    }
    printf("Grocery item added successfully!\n");
}


//function to list all items in inventory
void listitems(GroceryInventory *inventory){


    if(inventory->itemcount<=0){
        printf("No grocery items in the inventory.\n");
        return;
    }

    for(int i=0;i<inventory->itemcount;i++){

        Groceryitem *item=&inventory->groceryarray[i];
        Availabilitystatus *status=&inventory->availabilityarr[i];

        printf("Name: %s\n",item->name);
        printf("Category: %s\n",item->category);
        printf("Quantity: %d\n",item->quantity);
        printf("Price: %.2f\n",item->price);

        if(status->Instock==1){
            printf("Status: In Stock\n");
        }else{printf("Status: Out of Stock\n");}
        printf("\n");
    }
}

//function for updating quantity of an item
void updatequantity(GroceryInventory *inventory){

    //check if any items in inventory
    if(inventory->itemcount<=0){
        printf("No grocery items in inventory\n");
        return;
    }

    char itemtoupdate[MAX_NAME];
    int updated=0;

    printf("Enter name of grocery item to update quantity: ");
    getchar();
    fgets(itemtoupdate,MAX_NAME,stdin);  
    itemtoupdate[strcspn(itemtoupdate,"\n")]='\0';

    //search for item name in inventory
    for(int i=0;i<inventory->itemcount;i++){
        Groceryitem *item=&inventory->groceryarray[i];
        if (strcmp(inventory->groceryarray[i].name,itemtoupdate)==0){
            printf("Enter new quantity of %s: ",itemtoupdate);
            scanf("%d",&item->quantity);    //update quantity to new input value
            getchar();
            updated=1;

            if (item->quantity==0){
                inventory->availabilityarr[i].Instock=0;  //if new quantity is 0, update availability status
            }
        }
    }
    if (updated==0){
        printf("Item not found.\n");
    }else{
        printf("Quantity updated successfully!\n");
    }
}

//removing item function
void removeitem(GroceryInventory *inventory){
    if(inventory->itemcount<=0){
        printf("No grocery items in inventory\n");
        return;
    }
    char itemtoremove[MAX_NAME];
    int removed=0;

    printf("Enter name of grocery item to remove: ");
    getchar();
    fgets(itemtoremove,MAX_NAME,stdin);  
    itemtoremove[strcspn(itemtoremove,"\n")]='\0';

    //search for item name
    for(int i=0 ; i<inventory->itemcount ; i++){
        Groceryitem *item=&inventory->groceryarray[i];
        if (strcmp(inventory->groceryarray[i].name,itemtoremove)==0){
            for(int j=i;j<inventory->itemcount-1;j++){

                //shift items and availability status to fill the space of removed item
                inventory->groceryarray[j] = inventory->groceryarray[j + 1];
                inventory->availabilityarr[j] = inventory->availabilityarr[j + 1];
            }
            removed=1;
            inventory->itemcount--;  //update itemcount
        }
    }

    if (removed==0){
        printf("Item not found.\n");
    }else{
        printf("Grocery Item '%s' removed successfully!\n",itemtoremove);
    }
}




int main(){
    int choice;
    GroceryInventory Inventory;
    do{
        printf("\nGrocery Inventory Management System\n");
        printf("=====================================\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            choice = 0; // Ensure choice isn't treated as valid
        } else {
            switch(choice){
                case 1:
                    additem(&Inventory);
                    break;
                case 2:
                    listitems(&Inventory);
                    break;
                case 3:
                    updatequantity(&Inventory);
                    break;

                case 4:
                    removeitem(&Inventory);
                    break;
                
                case 5:
                    printf("Exiting...");
                    break;

                default:
                    printf("Invalid Choice: Must be within 1 to 5 only. \n");
            }   
    
        }
    }while(choice!=5);

    return 0;
}