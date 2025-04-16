#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int isInStock;
} Grocery;

Grocery inventory[MAX_ITEMS];
int itemCount = 0;

// show menu
void displayMenu() 
{
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

// add item
void addGrocery() 
{
    if (itemCount >= MAX_ITEMS) 
    {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    Grocery item;

    printf("Enter Item Name: ");
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = '\0'; 

    printf("Enter Category: ");
    fgets(item.category, sizeof(item.category), stdin);
    item.category[strcspn(item.category, "\n")] = '\0'; 

    printf("Enter Quantity: ");
    // make sure the data input by user is decimal
    while (scanf("%d", &item.quantity) != 1) 
    {
        printf("Invalid input! Please enter an integer: ");
        // clear the input buffer
        while (getchar() != '\n');
    }

    printf("Enter Price: RM");
    while (scanf("%f", &item.price) != 1) 
    {
        printf("Invalid input! Please enter a valid price: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    // Ternary Operator
    item.isInStock = (item.quantity > 0) ? 1 : 0;

    inventory[itemCount++] = item;

    printf("Grocery item added successfully!\n");
}

void listGrocery() 
{
    if (itemCount == 0) 
    {
        printf("No items in the inventory.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) 
    {
        printf("Name: %s\n", inventory[i].name);
        // \033[ = starts the escape sequence
        // 0;32m = 32 is green color
        // \033[0m = resets all formatting text to default
        printf("\033[0;32mCategory: %s\033[0m\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: RM%.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].isInStock ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

void updateGroceryQuantity() 
{
    char name[100];
    int newQuantity;

    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < itemCount; i++) 
    {
        if (strcmp(inventory[i].name, name) == 0) 
        {
            printf("Enter new quantity for %s: ", name);
            while (scanf("%d", &newQuantity) != 1) 
            {
                printf("Invalid input! Please enter an integer: ");
                while (getchar() != '\n');
            }

            inventory[i].quantity = newQuantity;
            inventory[i].isInStock = (newQuantity > 0) ? 1 : 0;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found...\n");
}

void removeGrocery() 
{
    char name[100];

    printf("Enter name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    // remove trailing newline
    name[strcspn(name, "\n")] = '\0'; 

    for (int i = 0; i < itemCount; i++) 
    {
        if (strcmp(inventory[i].name, name) == 0) 
        {
            // overwrite items by changing inventory[0] to inventory[1] as example
            for (int j = i; j < itemCount - 1; j++) 
            {
                inventory[j] = inventory[j + 1];
            }

            // so the duplicate last item will be remove
            // original inventory[2] is cola for example, overwrite by 100 plus(inventory[j] = inventory[j + 1];)
            // inventory[2] = 100 plus 
            // inventory[3] = 100 plus
            // itemCount = 3 - 1 = 2
            // right now the last dduplicate item is clear
            itemCount--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found...\n");
}

int main() 
{
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");

        // validation of the input 
        if (scanf("%d", &choice) != 1) 
        {
            printf("Invalid choice! Please choose again!\n ");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) 
        {
            case 1:
                // ensure the last input buffer is not newline which would cause bug
                // then it will execute the addGrocery() function
                while (getchar() != '\n'); 
                addGrocery();
                break;
            case 2:
                listGrocery();
                break;
            case 3:
                while (getchar() != '\n'); 
                updateGroceryQuantity();
                break;
            case 4:
                while (getchar() != '\n'); 
                removeGrocery();
                break;
            case 5:
                printf("Have a nice day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
