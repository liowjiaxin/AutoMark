#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

// Struct for grocery items with relavant variables
struct groceryitem{
    char name[100];
    char category[50];
    int quantity;
    float price;
};

// Struct for item availability
struct status{
    bool instock, nostock;
};

// Struct for grocery inventory and relavant variables
struct groceryinventory{
    struct groceryitem items[MAX];
    struct status avail[MAX];
    int counter;
};

void AddItem(struct groceryinventory *inv);
void ListItems(const struct groceryinventory *inv);
int UpdateQuantity(struct groceryinventory *inv);
int RemoveItem(struct groceryinventory *inv);

// Function to add an item into inventory
void AddItem(struct groceryinventory *inv){

    // Check first if inventory is full. If full then print error message and don't need to process anymore
    if(inv->counter == MAX){
        printf("\nUnable to add more items. Inventory is full\n");
        while (getchar() != '\n');
    } else {
        // define new variables with respective struct type to hold new input
        struct groceryitem *thisitem = &inv->items[inv->counter];
        struct status *isavail = &inv->avail[inv->counter];

        printf("Enter item name: ");
        while(1){
            // First if else to check if there are any unexpected error in input
            if (fgets(thisitem->name, 101, stdin) != NULL){
                size_t len = strlen(thisitem->name);
                // Second if else to check if name exceeds 100 character and prompts for re-input if so
                if (len > 0 && thisitem->name[len - 1] == '\n'){
                    thisitem->name[len - 1] = '\0'; // If length ok put zero terminator at end of string
                    break;
                } else if (len == 100){
                    printf("Name is too long. Please keep it under 100 characters.\n");
                    while (getchar() != '\n');
                }
            } else{
                printf("Input error. Please re-enter again.\n");
                while (getchar() != '\n');
            }
            printf("\n");
            printf("Enter item name: ");
        }
        
        
        printf("Enter category: ");
        // Same as above check if category name is too long, or if unexpected error happened
          while(1){
            if (fgets(thisitem->category, 51, stdin) != NULL){
                size_t len = strlen(thisitem->category);
                if (len > 0 && thisitem->category[len - 1] == '\n'){
                    thisitem->category[len - 1] = '\0';
                    break;
                } else if (len == 50){
                    printf("Category is too long. Please keep it under 100 characters.\n");
                    while (getchar() != '\n');
                }
            } else{
                printf("Input error. Please re-enter again.\n");
                while (getchar() != '\n');
            }
            printf("\n");
            printf("Enter item category: ");
        }
        
        // Prompt for quantity and price, and do suitable validation
        printf("Enter quantity: ");
        while (scanf("%d", &thisitem->quantity) != 1) {
            printf("Invalid input. Please enter a valid integer for quantity: ");
            while (getchar() != '\n'); // Clear input buffer to prevent wierd error
        }

        printf("Enter price: ");
        while (scanf("%f", &thisitem->price) != 1) {
            printf("Invalid input. Please enter a valid number for price: ");
            while (getchar() != '\n'); // Clear input buffer to prevent wierd error
        }
        // Notify successfull addition of item and increase counter since there is one more item now
        printf("Grocery item added successfully!\n");

        inv->counter ++;

        // This is to set availability status flags. If quantity is more than 0 it is in stock. Else not in stock.
        if(thisitem->quantity<=0){
            isavail->instock = false;
            isavail->nostock = true;
        }else{
            isavail->instock = true;
            isavail->nostock = false;
        }
        
    }
}

// Function to list all the items in inventory
void ListItems(const struct groceryinventory *inv){

    // Same check if inventory is empty, if empty print error message and skip processing phase
    if(inv->counter==0){
        printf("Inventory is empty.\n");
    } else{
        // Just some header formatting to print inventory
        printf("Grocery items in inventory:\n");
        printf("No.\tName\tCategory\tQuantity\tPrice\tAvailability\n");
        printf("\n");

        // Loop based on counter since counter is the number of items in inventory
        for(int x=0;x<inv->counter;x++){
            const struct groceryitem *thisitem = &inv->items[x];
            const struct status *isavail = &inv->avail[x];
            char *flag;

            if(isavail->instock==true){
                flag = "yes";
            }else{
                flag = "no";
            }
            printf("%d\t%s\t%s\t\t%d\t\t%.2f\t\t%s\n",x+1,thisitem->name,thisitem->category,thisitem->quantity,thisitem->price,flag);
        }
    }
}

// Function to update the quantity of an item
int UpdateQuantity(struct groceryinventory *inv){

    // // Same check if inventory is empty, if empty retun 0 and exit function
    if (inv->counter == 0) {
        printf("Inventory is empty.\n");
        return 0;
    }

    // Variable for item name to be searched
    char search[100];
    printf("\nEnter item name to update quantity:\n");
    scanf(" %[^\n]", search);
   
    // Loop based on counter to compare and check if item exists
    for(int x=0;x<inv->counter;x++){
        struct groceryitem *thisitem = &inv->items[x];
        struct status *isavail = &inv->avail[x];

        // If match prompt for new quantity and validate input
        if(strcmp(thisitem->name,search)==0){

            printf("Enter new quantity to update:\n");
            while (scanf("%d", &thisitem->quantity) != 1) {
                printf("Invalid input. Please enter a valid integer for quantity:\n");
                while (getchar() != '\n'); // Clear input buffer
            }
            while (getchar() != '\n');

            // Check if flag needs to be re-updated based on new quantity
            if(thisitem->quantity<=0){
                isavail->instock = false;
                isavail->nostock = true;
            }else{
                isavail->instock = true;
                isavail->nostock = false;
            }
            
            printf("\nQuantity and availability updated successfully!\n");
            return 1;
        }
    }
    // Error message if item not found
    printf("\nItem does not exist in inventory.\n");
    while (getchar() != '\n');
    return 0;
}

// Function to remove an item from inventory
int RemoveItem(struct groceryinventory *inv){

    if (inv->counter == 0) {
        printf("Inventory is empty.\n");
        return 0;
    }
    
    // Variable to hold item name to be removed
    char search[100];
    printf("\nEnter item name to be removed:\n");
    scanf(" %[^\n]", search);
    while (getchar() != '\n');
    
    // Loop to search if item exists controlled by counter
    for(int x=0;x<inv->counter;x++){
        // If matched, remove item by replacing it with subsequent item's data
        if(strcmp(inv->items[x].name,search) == 0){
            for (int y = x; y < inv->counter - 1; y++) {
                inv->items[y] = inv->items[y + 1];
                inv->avail[y] = inv->avail[y + 1];
            }
            // Decrement item counter
            inv->counter--;
            printf("\nItem '%s' removed successfully!\n", search);
            return 1;
        }
    }
    printf("\nItem does not exist in inventory.\n");
    while (getchar() != '\n');
    return 0;
}

// Main function to start program
int main(void){
    struct groceryinventory inv = {.counter = 0};
    int function;

    printf("Grocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");

    while(1){
        printf("\nEnter desired function (5 to exit): ");
        if (scanf("%d", &function) == 1) { // Check if input is a valid integer
            while (getchar() != '\n');
            // Condition to end infinite loop and terminate program.
            if (function == 5) { 
                printf("Program terminated by user.");
                break;
            }
            // Calls respective functions base on user operations.
            switch (function) {
                case 1:
                    AddItem(&inv);
                    break;
                case 2:
                    ListItems(&inv);
                    break;
                case 3:
                    if (!UpdateQuantity(&inv) ) {
                        continue;
                    }
                    break;
                case 4:
                    if (!RemoveItem(&inv) ) {
                        continue;
                    }
                    break;
                // To check if user input integer that is not 1-5. Shows error message and prompts for re-input.
                default:
                    printf("Invalid choice. Please enter a valid function (1-5).\n");
            }
        }
    }
    return 0;
}