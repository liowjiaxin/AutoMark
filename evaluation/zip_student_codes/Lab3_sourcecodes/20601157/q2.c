#include <stdio.h>
#include <string.h>

struct GroceryItem {

    char name[101];
    char category[50];
    int quantity;
    float price;

};

struct AvailabilityStatus {

    // 0 for false, 1 for true

    int inStock;
    int outofStock;

};

struct GroceryInventory {

    struct GroceryItem items [100];
    struct AvailabilityStatus status [100];
    int totalItems;

};

void addGroceryItem (struct GroceryInventory *modifyinventory){

    if (modifyinventory->totalItems>100){
        printf("Grocery Inventory is full! Unable to add more new items.");
    }

    else{

        struct GroceryItem newItemEntry; // newItemEntry having the struct of GroceryItem!

        printf("Enter Item Name :");
        getchar(); // consume the newline character
        fgets (newItemEntry.name, 101, stdin);
        newItemEntry.name[strcspn(newItemEntry.name, "\n")] = 0; // Remove trailing newline from name

        printf("Enter Category :");
        fgets (newItemEntry.category, 101, stdin);
        newItemEntry.category[strcspn(newItemEntry.category, "\n")] = 0; // Remove trailing newline from category

        printf("Enter Quantity :");
        scanf("%d",&newItemEntry.quantity);
        
        printf("Enter Price :");
        scanf("%f",&newItemEntry.price);

        // Add the new item entry to inventory

        modifyinventory->items[modifyinventory->totalItems]=newItemEntry;

        // modifyinventory is pointing to address of items array in GroceryInventory struct
        // modifyinventory->totalItems means modifyinventory is pointing to totalItems value in GroceryInventory
        // totalItems will have an initial value of 0
        // so basically modifyinventory points to items [0] in GroceryInventory, then newItemEntry values are stored there

        modifyinventory->status[modifyinventory->totalItems].inStock = 1; // Initially mark the item as in stock
        modifyinventory->status[modifyinventory->totalItems].outofStock = 0;
        modifyinventory->totalItems++; 

        // Increment the totalItems counter after each item entry       

        printf("%s has been successfully added into inventory.\n",newItemEntry.name);

    }   

}

void listAllGroceryItems (struct GroceryInventory *modifyinventory){


    if (modifyinventory->totalItems == 0){

        printf("There are currently no items in inventory!");

    }

    else{ // list out all current items in GroceryInventory

        printf("All Grocery Items Stored: \n");
        printf("\n");

        for (int i=0; i<modifyinventory->totalItems; ++i){
            printf("Item %d :\n", i+1);
            printf("Name : %s\n",modifyinventory->items[i].name);
            printf("Category : %s\n", modifyinventory->items[i].category);
            printf("Quantity : %d\n", modifyinventory->items[i].quantity);
            printf("Price : %.2f\n", modifyinventory->items[i].price);
           
            // Display status based on inStock or outOfStock flags

            if (modifyinventory->status[i].inStock == 1) {
                printf("Status: In Stock\n");

            } 
            else if (modifyinventory->status[i].inStock == 0) {
                printf("Status: Out of Stock\n");
            }

            printf("\n");
        }

    }

}

void updateQuantity(struct GroceryInventory* modifyinventory) {

    if (modifyinventory->totalItems == 0) {

        printf("There are currently no items in inventory!\n");

        return;
    }

    char searchItemName[101];
    int newQuantity;
    int foundFlag = 0; // flag for found items

    printf("Enter the name of the grocery item to update quantity: ");
    getchar(); // consume the leftover newline character from previous input
    fgets(searchItemName, 101, stdin);
    searchItemName[strcspn(searchItemName, "\n")] = 0; // remove trailing newline from searchItemName

    // Searching code

    for (int i = 0; i < modifyinventory->totalItems; ++i) {

        if (strcmp(modifyinventory->items[i].name, searchItemName) == 0) {

            printf("Enter new quantity for %s: ", modifyinventory->items[i].name);
            scanf("%d", &newQuantity);

            // Validate the new quantity

            if (newQuantity < 0) {
                printf("Quantity cannot be negative. Please enter a valid quantity.\n");
            } 
            
            else {
                modifyinventory->items[i].quantity = newQuantity;
                printf("Quantity updated successfully!\n\n");
            }

            // Stock status based on the quantity of item

            if (modifyinventory->items[i].quantity > 0) {
                modifyinventory->status[i].inStock = 1;  
                modifyinventory->status[i].outofStock = 0;
            } 
            else {
                modifyinventory->status[i].inStock = 0;
                modifyinventory->status[i].outofStock = 1;
            }

            foundFlag = 1; // mark that item was found and updated
            break;  // exit loop after updating
        }
    }

    if (!foundFlag) {
        printf("Item not found in inventory.\n");
    }
}

void removeGroceryItem (struct GroceryInventory *modifyinventory){

    if (modifyinventory->totalItems == 0) {

        printf("There are currently no items in inventory!\n");

        return;
    }

    char removeItemName[101];
    int foundFlag=0;

    printf("Enter name of grocery item to remove: ");
    getchar();
    fgets(removeItemName,101,stdin);
    removeItemName[strcspn(removeItemName, "\n")] = 0;

    

    for (int i=0 ; i < modifyinventory->totalItems; ++i){
        if (strcmp(modifyinventory->items[i].name, removeItemName) == 0){ // 0 returned = item found

            printf("Grocery item %s removed successfully!\n",modifyinventory->items[i].name);

            for (int j=i; j <modifyinventory->totalItems; ++j){

                // replace the left element with the right element
                modifyinventory->items[j]=modifyinventory->items[j+1];
                modifyinventory->status[j]=modifyinventory->status[j+1];

            }

            modifyinventory->totalItems--; // remove 1 item = decrement in total items
            
        }
    }

}



int main(){

    int choice;
    struct GroceryInventory inventory = {0}; 
    // address for the GroceryInventory struct
    // will be used to pass into functions for various function uses

    while (1){
        printf("\n");
        printf("Grocery Inventory Management System\n");
        printf("\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("\n");

        printf("Enter your choice :");
        scanf("%d",&choice);

        switch (choice){

        case 1:
            addGroceryItem(&inventory);
            break;

        case 2:
            listAllGroceryItems(&inventory);
            break;

        case 3:
            updateQuantity(&inventory);
            break;

        case 4:
            removeGroceryItem(&inventory);
            break;
            
        case 5:
            printf("Exiting...\n");
            return 0;
        
        default:
            printf("Invalid input, please re-enter choice!\n");
            printf("\n");

        }

    }

}