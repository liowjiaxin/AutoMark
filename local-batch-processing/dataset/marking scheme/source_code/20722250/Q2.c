#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus statuses[MAX_ITEMS];
    int totalItems;
} GroceryInventory;

// function prototypes
void addItem(GroceryInventory *inventory);
void listItems(const GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeItem(GroceryInventory *inventory);
void displayMenu();
void capitaliseStr(char *str);

int main() 
{
    int choice;
    GroceryInventory inventory = {.totalItems = 0};

    do 
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) 
        {
            case 1:
                addItem(&inventory);
                break;
            case 2:
                listItems(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeItem(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// function to add a grocery item to the inventory
void addItem(GroceryInventory *inventory) 
{
    if (inventory->totalItems >= MAX_ITEMS) 
    {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->totalItems];
    AvailabilityStatus *status = &inventory->statuses[inventory->totalItems];
    
    printf("Enter item name: ");
    fgets(item->name, sizeof(item->name), stdin);
    strtok(item->name, "\n"); // remove newline character
    capitaliseStr(item->name); // capitalise first letter of each word in item name

    printf("Enter category: ");
    fgets(item->category, sizeof(item->category), stdin);
    strtok(item->category, "\n");
    capitaliseStr(item->category); // capitalise first letter of each word in item category

    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    getchar();

    printf("Enter price: ");
    scanf("%f", &item->price);
    getchar();

    status->inStock = item->quantity > 0;
    status->outOfStock = !status->inStock;

    inventory->totalItems++;
    printf("Grocery item added successfully!\n");
}

// function to display a list of all grocery items in the inventory
void listItems(const GroceryInventory *inventory) 
{
    if (inventory->totalItems == 0) 
    {
        printf("No grocery items available in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->totalItems; i++) 
    {
        const GroceryItem *item = &inventory->items[i];
        const AvailabilityStatus *status = &inventory->statuses[i];

        printf("\n-Grocery Item #%d-\n", i + 1);
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

// function to update the quantity of a grocery item in the inventory
void updateQuantity(GroceryInventory *inventory) 
{
    if (inventory->totalItems == 0) 
    {
        printf("No grocery items available to update.\n");
        return;
    }

    char name[100];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");
    capitaliseStr(name); // capitalise before comparison

    for (int i = 0; i < inventory->totalItems; i++) 
    {
        GroceryItem *item = &inventory->items[i];
        AvailabilityStatus *status = &inventory->statuses[i];

        if (strcmp(item->name, name) == 0) // compare the name of current item with the entered name to find a match
        {
            // if found, update quantity of current item
            printf("Enter new quantity for %s: ", item->name);
            scanf("%d", &item->quantity);
            getchar();

            status->inStock = item->quantity > 0;
            status->outOfStock = !status->inStock;

            printf("Quantity updated successfully!\n");
            return;
        }
    }
    // if not found
    printf("Grocery item not found in the inventory.\n");
}

// function to remove a grocery item from the inventory
void removeItem(GroceryInventory *inventory) 
{
    if (inventory->totalItems == 0) 
    {
        printf("No grocery items available to remove.\n");
        return;
    }

    char name[100];
    printf("Enter name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");
    capitaliseStr(name); // capitalise before comparison

    for (int i = 0; i < inventory->totalItems; i++) 
    {
        if (strcmp(inventory->items[i].name, name) == 0) // compare the name of current item with the entered name to find a match
        {
            // if found, remove current item (by shifting items and statuses to the left to fill the current item's spot)
            for (int j = i; j < inventory->totalItems - 1; j++) 
            {
                inventory->items[j] = inventory->items[j + 1];
                inventory->statuses[j] = inventory->statuses[j + 1];
            }

            inventory->totalItems--; // decrement total number of items by 1 after removal
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }
    // if not found
    printf("Grocery item not found in the inventory.\n");
}

// function to display menu
void displayMenu() 
{
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

// function to capitalise the first letter of each word in a string
void capitaliseStr(char *str) 
{
    int isWordStart = 1; // tracks if the current character is the start of a word

    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (isWordStart && isalpha(str[i])) 
        {
            str[i] = toupper(str[i]); // capitalize the first letter of the word
            isWordStart = 0;
        } 
        else 
        {
            str[i] = tolower(str[i]); // convert the remaining letters in the word to lowercase
        }

        if (isblank(str[i])) 
        {
            isWordStart = 1; // reset for the next word after a space
        }
    }
}
