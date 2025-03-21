#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INVENTORY 100 //store up to 100 groceries
#define MAX_NAME 101 //store up to 100 letters in the string + 1 null terminator
#define MAX_CATEGORY 51 //store up to 50 letters in the string + 1 null terminator

struct grocery
{
    char item_name[MAX_NAME];
    char item_category[MAX_CATEGORY];
    int quantity;
    float price;
    char colour[5]; //colour for when displaying category
};

void list_inventory(struct grocery inventory[], int availability[], int count) {
    if (count == 0) {
        printf("\nNo grocery items in inventory\n");
        return;
    }
    for(int i = 0; i<count; i++){
        printf("\nName: %s", inventory[i].item_name);
        printf("%sCategory: %s\033[0m", inventory[i].colour, inventory[i].item_category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        if (availability[i] == 0)
        {
            printf("Status: Out of Stock\n");
        } else {
            printf("Status: In Stock\n");
        }
    }
}

void add_item(struct grocery inventory[], int availability[], int* count) {
    char colours[][5] = {
        "\033[31m", // Red
        "\033[32m", // Green
        "\033[33m", // Yellow
        "\033[34m", // Blue
        "\033[35m", // Magenta
        "\033[36m"  // Cyan
    };
    char item_name[101];
    char item_category[51];
    int quantity;
    float price;

    //reading item name
    printf("Enter item name: ");
    fgets(item_name, 101, stdin); //101 because 1 reserve space for null terminator

    //reading item category
    printf("Enter Category: ");
    fgets(item_category, 51, stdin);

    //reading item quantity
    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    //reading item price
    printf("Enter Price: ");
    scanf("%f", &price);

    //adding everything to inventory
    strcpy(inventory[*count].item_name, item_name);
    strcpy(inventory[*count].item_category, item_category);
    inventory[*count].quantity = quantity;
    inventory[*count].price = price;
    int random_colour_number = rand() % 6; //random number from 1-6 for colour
    strcpy(inventory[*count].colour, colours[rand() % 6]/*random number from 1-6 for colour*/);

    if (quantity<=0) {
        availability[*count] = 0;
    } else {
        availability[*count] = 1;
    }
    printf("\nGrocery item added successfully!\n");
    (*count) += 1;
    return;
}

void update_quantity(struct grocery inventory[], int availability[], int count) {
    if (count == 0) {
        printf("\nNo grocery items in inventory\n");
        return;
    }
    char input_name[101];
    int index = -1;
    char buffer;

    printf("Enter the name of the grocery item to update quantity: ");
    fgets(input_name, 101, stdin);

    for(int i = 0; i<count; i++) {
        if(strcmp(input_name, inventory[i].item_name) == 0) {
            index = i;
        }
    }
     
    if (index == -1) {
        printf("\nNo grocery item with the input name: %s\n", input_name);
        return;
    }

    int new_quantity;
    printf("Enter new quantity for ");
    for(int i = 0; i<=strlen(input_name); i++) {
        if(input_name[i] != '\0' && input_name[i] != '\n'){
            printf("%c", input_name[i]);
        }
    }
    printf(": ");
    scanf("%d", &new_quantity);
    inventory[index].quantity = new_quantity;

    if (inventory[index].quantity<=0) {
        availability[index] = 0;
    } else {
        availability[index] = 1;
    }
    printf("\nQuantity updated successfully!\n");

}


void remove_item(struct grocery inventory[], int availability[], int* count) {
    if (*count == 0) {
        printf("\nNo grocery items in inventory\n");
        return;
    }
    char input_name[101];
    int index = -1;
    char buffer;

    printf("Enter the name of the grocery item to update quantity: ");
    fgets(input_name, 101, stdin);

    for(int i = 0; i<*count; i++) {
        if(strcmp(input_name, inventory[i].item_name) == 0) {
            index = i;
        }
    }
     
    if (index == -1) {
        printf("\nNo grocery item with the input name: %s\n", input_name);
        return;
    }
    for (int i = index; i < *count - 1; i++) {
        inventory[i] =inventory[i + 1]; // Move the next contact into the current position
    }

    for (int i = index; i < *count - 1; i++) {
        availability[i] = availability[i + 1]; // Move the next contact into the current position
    }

    printf("\nGrocery item '");
    for(int i = 0; i<=strlen(input_name); i++) {
        if(input_name[i] != '\0' && input_name[i] != '\n'){
            printf("%c", input_name[i]);
        }
    }
    printf("' removed successfully! \n");

    (*count) -= 1;
    return;
}


int main(void) {
    srand(time(NULL));
    int function;
    int count = 0;
    struct grocery inventory[MAX_INVENTORY];
    int availability[MAX_INVENTORY];

    while(1) {
        char buffer = 'a'; 
        printf("\nGrocery Inventory Management System:\n1. Add Grocery Item\n2. List All Grocery Items\n3. Update Quantity\n4. Remove Grocery Item\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &function);
        while(buffer != '\n') {
            scanf("%c", &buffer);
        }

        switch (function)
        {
        case 1:
            buffer = 'a'; 
            add_item(inventory, availability, &count);
            while(buffer != '\n') {
                scanf("%c", &buffer);
            }
            break;
        
        case 2:
            list_inventory(inventory, availability, count);
            break;

        case 3:
            update_quantity(inventory, availability, count);
            break;

        case 4:
            remove_item(inventory, availability, &count);
            break;

        case 5: //Exit
            printf("Exiting...");
            exit(1);

        default:
            printf("Invalid choice, please try again\n");
            break;
        }
    }

    return 0;
}