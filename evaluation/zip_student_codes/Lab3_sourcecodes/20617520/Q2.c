#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME 100
#define MAX_CATEGORY 50


typedef struct
{
    char name[MAX_NAME];
    char category[MAX_CATEGORY];
    int quantity;
    float price;
} groceryItem;

typedef struct 
{
    bool inStock;
    bool outOfStock;
} availabilityStatus;

typedef struct 
{
    groceryItem items[MAX_ITEMS];
    availabilityStatus status[MAX_ITEMS];
    int count; 
}groceryInventory;

groceryInventory inventory;


//function prototypes
void clearInputBuffer();
void addItem();
void displayItems();
void updateQuantity();
void removeItem();

int main()
{
    inventory.count = 0;

    int option;

    do
    {
        printf("Grocery Inventory Management System \n1. Add Grocery Item \n2. List All Grocery Items \n3. Update Quantity \n4. Remove Grocery Item \n5. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        clearInputBuffer();


        switch (option)
        {
            case 1: //add grocery item
                addItem();
                break;
            case 2:
                displayItems();
                break;

            case 3:
                updateQuantity();
                break;

            case 4:
                removeItem();
                break;

            case 5:
                printf("Thank you for using Grocery Inventory Management System. \nExiting... \n");
                break;

            default: 
            printf("Invalid option. Please enter a valid option. \n");
        }
    } while(option != 5);

    return 0;
}

void clearInputBuffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void addItem()
{
    if (inventory.count >= MAX_ITEMS) //check if the inventory is full
    {
        printf("Inventory is full! Cannot add more items. \n"); 
        return;
    }

    //create pointers  to point to the memory location of the new grocery item and its availability status
    groceryItem *item = &inventory.items[inventory.count];  //the new item will be added at inventory.count
    availabilityStatus *status = &inventory.status[inventory.count];

    printf("Enter item name: ");
    fgets(item -> name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = 0; //remove null terminator

    printf("Enter category: ");
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = 0;

    do
    {
        printf("Enter quantity: ");
        scanf("%d", &item->quantity);
        clearInputBuffer();
        if (item->quantity < 0)
        {
            printf("Quantity cannot be negative. Try again.\n");
        }
    } while (item->quantity < 0);

    do
    {
        printf("Enter price: ");
        scanf("%f", &item->price);
        clearInputBuffer();
        if (item->price < 0)
        {
            printf("Price cannot be negative. Try again.\n");
        }
    } while (item->price < 0);
    
    //update avalilability status
    status->inStock = (item->quantity > 0); //if item->quantity > 0, status->inStock is set to true
    status->outOfStock = !status->inStock; //if not, status->outOfStock is set to true

    inventory.count++;
    printf("Grocery item added successfully! \n");
    
}

void displayItems()
{
    //check if inventory is empty
    if (inventory.count == 0)
    {
        printf("No grocery items in the inventory. \n");
        return;
    }

    for(int i = 0; i < inventory.count; i++)
    {
        groceryItem *item = &inventory.items[i]; //item points to the ith item in inventory.item arr
        availabilityStatus *status = &inventory.status[i]; //status points to ith availability ststus in the inventory.status arr
        
        printf("Item %d: \n", i+1);
        printf("Name: %s \n", item->name);
        printf("Category: %s \n", item->category);
        printf("Quantity: %d \n", item->quantity);
        printf("Price: %.2f \n", item->price);
        printf("Status: %s \n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity()
{
    char name[MAX_NAME];
    printf("Enter the name of the grocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < inventory.count; i++)
    {
        if (strcmp(inventory.items[i].name, name) == 0)//compares the name of current inventory item with the name the user entered
        {
            int newQuantity; //new variable declared to hold the new quantity value for the item
            printf("Enter the new quantity: ");
            scanf("%d", &newQuantity);

            clearInputBuffer();
            inventory.items[i].quantity = newQuantity; //update the quantity of the found inventory item to the new value entered by user

            //update the inStock status of the item based on the new quantity
            inventory.status[i].inStock = (newQuantity > 0);
            inventory.status[i].outOfStock = !inventory.status[i].inStock;

            printf("Quantity updated successfully! \n");
            return;
        }
    }
    printf("Item not found in inventory. \n");
}

void removeItem()
{
    char name[MAX_NAME]; //declared to hold the name of the grocery item user wants to remove
    printf("Enter the name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < inventory.count; i++) //iterate through the items in the inventory array
    {
        if (strcmp(inventory.items[i].name, name) == 0) //compare the name of current inventory item with the item entered by user
        {
            for (int j = i; j < inventory.count - 1; j++) //when the item is found, this will shift the items in the inventory.items and inventory.status arrays to the left
            {
                inventory.items[j] = inventory.items[j + 1]; //each item at j is replaced by the item at position j+1, shifted to the left one position
                inventory.status[j] = inventory.status [j + 1]; //this is also the same as above
            }
            inventory.count--;
            printf("Item '%s' removed from inventory. \n", name);
            return;
        }
    }
    printf("Item not found inventory. \n");
}