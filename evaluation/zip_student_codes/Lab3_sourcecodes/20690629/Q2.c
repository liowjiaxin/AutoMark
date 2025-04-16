#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct 
{
    char name[101];
    char category[101];
    int quantity;
    float price;
} Item;

void AddItem(Item groceries[], int status[], int* count)
{
    // if inventory is full
    if (*count >= 100)
    {
        printf("Inventory of groceries is full\n");
    }

    // prompt user to input details for new item
    char name[101];
    char category[101];
    int quantity;
    float price;

    printf("Enter item name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter category: ");
    fgets(category, 100, stdin);
    category[strcspn(category, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%f", &price);

    // if quantity or price is negative
    if (quantity < 0 || price < 0)
    {
        printf("Input is not valid\n");
        printf("Grocery item not added\n");
    }
    else
    {
        // create new item and initialise item details
        Item new_item;
        groceries[*count] = new_item;

        strcpy(groceries[*count].name, name);
        strcpy(groceries[*count].category, category);
        groceries[*count].quantity = quantity;
        groceries[*count].price = price;

        if (quantity == 0)
        {
            status[*count] = 0;
        }
        else if (quantity > 0)
        {
            status[*count] = 1;
        }

        *count += 1;
        printf("\nGrocery item added\n");
    }
}

void UpdateQuantity(Item groceries[], int status[], int* count)
{
    char name[100];
    int num;
    // prompt user for item to update quantity
    printf("Enter name of grocery item to update quantity: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    // find item in inventory
    int index = -1;
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(groceries[i].name, name) == 0)
        {
            index = i;
            break;
        }
    }

    // if item is not found in inventory
    if (index < 0)
    {
        printf("Item is not found in the item\n");
    }
    // if item is found in inventory
    else 
    {
        // prompt user for new quantity
        printf("Enter new quantity for grocery item: ");
        scanf("%d", &num);

        // if quantity is 0, item is out of stock
        if (num == 0)
        {
            groceries[index].quantity = num;
            status[index] = 0;
        }
        // if quantity is greater than 0, item is in stock
        else if (num > 0)
        {
            groceries[index].quantity = num;
            status[index] = 1;
        }
        // if quantity is less than 0, value is not valid
        else
        {
            printf("Quantity is not updated as input is not a valid quantity\n");
        }
    }
}

void RemoveItem(Item groceries[], int status[], int* count)
{
    char name[100];
    // prompt user for item to remove
    printf("Enter name of grocery item to remove: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    // search for item in inventory
    int index = -1;
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(groceries[i].name, name) == 0)
        {
            index = i;
            break;
        }
    }

    if (index >= 0 && index < *count)
    {
        // move all items after removed item one backward position and decrease number of items
        for (int i = index; i < *count - 1; i++) 
        {
            groceries[i] = groceries[i + 1];
            status[i] = status[i + 1];
        }
        (*count)--;
    }

    // if item not found
    if (index < 0)
    {
        printf("\nItem is not found in list\n");
    }
    // item is found and removed
    else
    {
        printf("\nItem removed successfully\n");
    }
}

void ListItems(Item groceries[], int status[], int* count)
{

    for (int i = 0; i < *count; i++)
    {
        // to determine if item is in stock or out of stock based on boolean value
        char* bools = (status[i]) ? "In stock" : "Out of stock";
        // display details of item
        printf("\n");
        printf("name: %s\n", groceries[i].name);
        printf("category: %s\n", groceries[i].category);
        printf("quantity: %d\n", groceries[i].quantity);
        printf("price: %.2f\n", groceries[i].price);
        printf("status: %s\n", bools);
    }
    printf("\n");
}

int main(void)
{
    Item groceries[100];
    int status[100] = {0};
    int count = 0;

    // open inventory file and read file lines into array of structs
    FILE *read_inventory = fopen("inventory.csv", "r+");
    while (fscanf(read_inventory, "%100[^,], %100[^,], %d, %f, %d\n", groceries[count].name, groceries[count].category, &groceries[count].quantity, &groceries[count].price, &status[count]) != EOF)
    {
        count++;
    }
    fclose(read_inventory);

    int choice = 0;
    while (choice != 5)
    {
        printf("\nGrocery Management Inventory System\n");
        printf("1. Add Grocery Item\n2. List All Grocery items\n3. Update Quantity\n4. Remove Grocery Item\n5. Exit\n");
        // prompt user for options on grocery items
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                AddItem(groceries, status, &count);
                break;
            case 2:
                ListItems(groceries, status, &count);
                break;
            case 3:
                UpdateQuantity(groceries, status, &count);
                break;
            case 4:
                RemoveItem(groceries, status, &count);
                break;
            case 5:
                break;
            default:
                // user option is not valid
                printf("Not a valid option\n");
                break;
        }
    }

    // write new information, array of structs, to the file inventory
    FILE *write_inventory = fopen("inventory.csv", "w");

    for (int i = 0; i < count; i++)
    {
        fprintf(write_inventory, "%s, %s, %d, %.2f, %d\n", groceries[i].name, groceries[i].category, groceries[i].quantity, groceries[i].price, status[i]);
    }
    fclose(write_inventory);
}

