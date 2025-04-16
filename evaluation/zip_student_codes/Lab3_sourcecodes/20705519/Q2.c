#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLIST 100

// struct declarations
typedef struct 
{
    char name[100];
    char category[50];
    int quantity;
    float price;
} Grocery_item;

typedef struct
{
    bool in_stock;
    bool outof_stock;
} Availability_status;

typedef struct
{
    Grocery_item item[MAXLIST];
    Availability_status status[MAXLIST];
    int total;
} Grocery_inventory;
Grocery_inventory inventory;

// function prototype declarations
void addItem ();
void displayItems ();
void updatequantity ();
void removeitem ();

int main ()
{
    while (1)
    {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            addItem();
            break;
        case 2:
            displayItems();
            break;
        case 3:
            updatequantity();
            break;
        case 4:
            removeitem();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Enter a proper choice.\n");
            break;
        }
    }
    return 0;
}

// function to insert user input of grocery item into struct
void addItem ()
{
    if (inventory.total < MAXLIST)
    {
        // user input
        printf("Enter Item Name: ");
        fgets(inventory.item[inventory.total].name, sizeof(inventory.item[inventory.total].name), stdin);
        inventory.item[inventory.total].name [strcspn(inventory.item[inventory.total].name, "\n")] = 0;

        printf("Enter Category: ");
        fgets(inventory.item[inventory.total].category, sizeof(inventory.item[inventory.total].category), stdin);
        inventory.item[inventory.total].category [strcspn(inventory.item[inventory.total].category, "\n")] = 0;

        printf("Enter Quantity: ");
        scanf("%d", &inventory.item[inventory.total].quantity);
        getchar();

        printf("Enter Price: ");
        scanf("%f", &inventory.item[inventory.total].price);
        getchar();

        // do not save grocery item into system if user enter a -ve amount for either quantity/price
        if (inventory.item[inventory.total].quantity < 0 || inventory.item[inventory.total].price < 0)
        {
            printf("Quantity/Price of grocery item must be more than 0!\n");
            return;
        }

        // check if quantity is set to 0, if yes, outof_stock will be set to true 
        // otherwise in_stock will be set to true
        if (inventory.item[inventory.total].quantity == 0)
        {
            inventory.status[inventory.total].outof_stock = true;
        }
        else
        {
            inventory.status[inventory.total].in_stock = true;
        }

        // increment array index of grocery item
        inventory.total += 1;
        printf("Grocery item added successfully!\n");
    }
    else
    {
        printf("Grocery inventory is full. No more items can be added.\n");
    }
}

// function to display all grocery items in grocery inventory
void displayItems ()
{
    if (inventory.total == 0)
    {
        printf("No grocery items in the inventory.\n");
    }
    else
    {
        for (int i = 0; i < inventory.total; i++)
        {
            // check if item in any specific array index has been removed,
            // i.e. that array index's grocery item is empty
            // if it is empty (removed) dont display anything, skip to next item
            printf("\nName: %s\n", inventory.item[i].name);
            printf("Category: %s\n", inventory.item[i].category);
            printf("Quantity: %d\n", inventory.item[i].quantity);
            printf("Price: %.2f\n", inventory.item[i].price);

            if (inventory.status[i].in_stock == true)
            {
                printf("Status: In Stock\n");
            }
            else if (inventory.status[i].outof_stock == true)
            {
                printf("Status: Out of Stock\n");
            }
            else
            {
                printf("Status: Error!\n");
            }   
        }
    }
}

// function to update quantity of selected grocery item
void updatequantity ()
{
    char choice_name[100];
    printf("Enter name of grocery item to update quantity: ");
    fgets(choice_name, 100, stdin);
    choice_name[strcspn(choice_name, "\n")] = 0;

    for (int i = 0; i < inventory.total; i++)
    {
        if ( strcmp(inventory.item[i].name, choice_name) == 0 )
        {
            printf("Enter new quantity for %s: ", inventory.item[i].name);
            scanf("%d", &inventory.item[i].quantity);
            getchar();
            
            // check if new quantity is 0, if yes update boolean value of outof_stock to true and in_stock to false
            // and vice versa
            if (inventory.item[i].quantity == 0)
            {
                inventory.status[i].in_stock = false;
                inventory.status[i].outof_stock = true;
            }
            else
            {
                inventory.status[i].in_stock = true;
                inventory.status[i].outof_stock = false;
            }

            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Grocery item not found.\n");
}

// function to remove grocery item from grocery item array
void removeitem ()
{
    char choice_name[100];
    printf("Enter name of grocery item to remove: ");
    fgets(choice_name, 100, stdin);
    choice_name[strcspn(choice_name, "\n")] = 0;

    // this for loop is to loop through all array elements
    for (int i = 0; i < inventory.total; i++)
    {
        // if statement to check if user's targeted grocery is in array list or not
        if ( strcmp(inventory.item[i].name, choice_name) == 0 )
        {
            // if yes, this for loop will continue from main for loop's counter
            // to replace targeted grocery item's array index with the grocery item in the next array index
            // effectively removing the targeted grocery item and shifting every other item on the RHS to the left
            for (int j = i; j < inventory.total; j++)
            {
                /* bruh
                strcpy(inventory.item[j].name, inventory.item[j + 1].name);
                strcpy(inventory.item[j].category, inventory.item[j + 1].category);
                inventory.item[j].quantity = inventory.item[j + 1].quantity;
                inventory.item[j].price = inventory.item[j + 1].price;
                inventory.status[j].in_stock = inventory.status[j + 1].in_stock;
                inventory.status[j].outof_stock = inventory.status[j + 1].outof_stock;
                */
                inventory.item[j] = inventory.item[j + 1];
                inventory.status[j] = inventory.status[j + 1];
            }
            inventory.total -= 1;
            printf("Grocery item '%s' removed successfully!\n", choice_name);
            return;
        }
    }
    printf("Grocery item not found.\n");
}