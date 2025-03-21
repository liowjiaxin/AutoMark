#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define CATEGORY_SIZE 50

// structure of grocery
typedef struct grocery
{
    char name[MAX_SIZE];
    char category[CATEGORY_SIZE];
    int quantity;
    float price;
    bool avai_status;       // availability status of item
}Item;

// Function prototypes
void add_item(struct grocery item_array[], int* n, bool status[], bool i_stock, bool o_stock);
void list_item(struct grocery item_array[], int n, bool status[], bool i_stock, bool o_stock);
void update_quantity(struct grocery item_array[], int n, bool status[], bool i_stock, bool o_stock);
void remove_item(struct grocery item_array[], int* n, bool status[], bool i_stock, bool o_stock);
void clear (void);

int main(){
    // Grocery Inventory:
    Item grocery_items[MAX_SIZE];                   // array of grocery items

    // Avaibility status: 
    bool in_stock = true;
    bool out_of_stock = false;
    bool item_status[MAX_SIZE]={out_of_stock};      // set values in array of avaibility status default to out-of-stock (0)

    int count_total =0;                             // count of total num of items in inventory

    while(1){
        char choice;
        // menu
        puts("\n");
        puts("Grocery Inventory Management System");
        puts("1. Add Grocery Item");
        puts("2. List All Grocery Items");
        puts("3. Update Quantity");
        puts("4. Remove Grocery Item");
        puts("5. Exit");

        printf("Enter your choice: ");
        scanf(" %c", &choice);          
        // uses %c instead of %d to prevent error if user enters characters/string, space before %c to prevent newline being read as 2nd choice

        puts(" ");
        switch (choice){
        case '1':
            add_item(grocery_items, &count_total, item_status, in_stock, out_of_stock);
            break;
        case '2':
            list_item(grocery_items, count_total, item_status, in_stock, out_of_stock);
            break;
        case '3':
            update_quantity(grocery_items, count_total, item_status, in_stock, out_of_stock);
            break;
        case '4':
            remove_item(grocery_items, &count_total, item_status, in_stock, out_of_stock);
            break;
        case '5':
            printf("Exiting...");
            return 0;
        default:
            printf("Error. Pls enter available choice(1-5).");
            break;
        }
    }
    return 0;
}

void add_item(struct grocery item_array[], int* n, bool status[], bool i_stock, bool o_stock){

    clear();        // clear input buffer

    printf("Enter Item Name: ");
    fgets(item_array[*n].name, MAX_SIZE, stdin);
    item_array[*n].name[strcspn(item_array[*n].name, "\n")]='\0';     // remove newline character

    // change all characters to lowercase for comparing in other functions
    for (int k=0; k< sizeof(item_array[*n].name); k++){
        item_array[*n].name[k] = tolower(item_array[*n].name[k]);
    }

    printf("Enter Category: ");
    fgets(item_array[*n].category, CATEGORY_SIZE, stdin);
    item_array[*n].category[strcspn(item_array[*n].category, "\n")]='\0';     // remove newline character    

    // change all characters to lowercase for comparing in other functions
    for (int k=0; k< sizeof(item_array[*n].category); k++){
        item_array[*n].category[k] = tolower(item_array[*n].category[k]);
    }

    while (1){
        printf("Enter Quantity: ");
        scanf("%d", &item_array[*n].quantity);
        
        if (item_array[*n].quantity <= 0){
            clear();
            printf("Initial quantity of item must not be less than 0.\n");
            continue;
        }
        else{
            break;       
        }
    }

    while(1){
        printf("Enter Price: ");
        scanf("%f", &item_array[*n].price);

        if (item_array[*n].price <= 0){
            clear();
            printf("Price of item must not be less than 0.00.\n");
            continue;
        }
        else{
            break;       
        }
    }

    if (item_array[*n].quantity > 0){
        item_array[*n].avai_status = i_stock;

        for (int i=0; i < MAX_SIZE; i++){
            if (status[i] == o_stock && i >= *n){
                status[i] = i_stock;
                break;
            }
        }
    }
    else{
        item_array[*n].avai_status = o_stock;
    }

    printf("Grocery item added successfully!\n");

    (*n) += 1;      // count of total num +1
}

void list_item(struct grocery item_array[], int n, bool status[], bool i_stock, bool o_stock){

    if (n==0){
        printf("No grocery items in the inventory.");
        return;     // return to main function
    }
    
    for (int i=0; i < n; i++){        
        printf("Item [%d]:\n", i+1);

        item_array[i].name[0] = toupper(item_array[i].name[0]);     // display 1st character in uppercase
        printf("Name: %s\n", item_array[i].name);

        item_array[i].category[0] = toupper(item_array[i].category[0]);     // display 1st character in uppercase
        printf("Category: %s\n", item_array[i].category);

        printf("Quantity: %d\n", item_array[i].quantity);
        printf("Price: %.2f\n", item_array[i].price);

        if (item_array[i].avai_status == i_stock){
            printf("Status: %s", "In Stock\n");
        }
        else{
            printf("Status: %s", "Out of Stock\n");
        }
        printf("------------------------------\n");
        // return back to lowercase for comparing in option 3 & 4
        item_array[i].name[0] = tolower(item_array[i].name[0]);
        item_array[i].category[0] = tolower(item_array[i].category[0]);
    }
}

void update_quantity(struct grocery item_array[], int n, bool status[], bool i_stock, bool o_stock){
    clear();

    char temp[MAX_SIZE];

    printf("Enter the name of the grocery item to update quantity: ");
    fgets(temp, MAX_SIZE, stdin);
    temp[strcspn(temp, "\n")]='\0';         // remove '\n'

    // change all characters to lowercase -> easy for comparing
    for (int k=0; k< sizeof(temp)/sizeof(temp[0]); k++){
        temp[k] = tolower(temp[k]);
    }

    for (int i=0; i < n; i++){
        if (strcmp(temp, item_array[i].name)==0){
            while (1){
                printf("Enter new quantity for %s: ", temp);
                scanf("%d", &item_array[i].quantity);
            
                if (item_array[i].quantity > 0){
                    item_array[i].avai_status = i_stock;
                    break;      // break while loop
                }
                else if (item_array[i].quantity == 0){
                    item_array[i].avai_status = o_stock;
                    break;       // break while loop
                }
                else{
                    printf("Quantity of item must not be less than 0.\n");
                }
            }  
            printf("Quantity updated successfully!\n");
            return;      // return to main function
        }
    }
    // after looping through the array, if the item name is not found, display the message below
    temp[0] = toupper(temp[0]);
    printf("Item '%s' not found in the inventory.\n", temp);
}

void remove_item(struct grocery item_array[], int* n, bool status[], bool i_stock, bool o_stock){
    clear();

    char temp[MAX_SIZE];
    
    printf("Enter the name of the grocery item to remove: ");
    fgets(temp, MAX_SIZE, stdin);
    temp[strcspn(temp, "\n")]='\0';         // remove '\n'

    // change all characters to lowercase -> easy for comparing
    for (int k=0; k< sizeof(temp)/sizeof(temp[0]); k++){
        temp[k] = tolower(temp[k]);
    }

    for (int i=0; i < *n; i++){
        if (strcmp(temp, item_array[i].name)==0){
            item_array[i]=item_array[i+1];          // move elements in next index to current index, current index elements replaced by next index's elements

            temp[0] = toupper(temp[0]);
            printf("Grocery item '%s' removed successfully!", temp);
            (*n) -= 1;      // count of total num -1
            return;         // return to main function
        }
    }
    // display message below if item name is not found after looping through the array
    temp[0] = toupper(temp[0]);
    printf("Item '%s' not found in the inventory.\n", temp);
}

// clear input buffer
void clear (void){
    while ( getchar() != '\n' );
}
