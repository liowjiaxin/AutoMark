#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct groceryItem {        //defining a struct which stores infromation about the grocery item
    char Name[100];
    char Category[50];
    int Quantity;
    float Price;
};

struct availabilityStatus {     //defining a struct to store information about the availability status of the grocery item
    bool inStock;           //Returns true if item is in stock
    bool outofStock;        //Returns true if item is not in stock
};

struct groceryInventory {
    struct groceryItem items[100];      //Array of grocery items
    struct availabilityStatus status[100];      //Array of availability status
    int totalCount;     //Stores the total number of grocery items
};

void addGroceryItem (struct groceryInventory *inventory) {      //defining a function to add new grocery item
    if (inventory->totalCount >= 100) {
        printf("The inventory is full!\n");     //Gives error message if total count exceeds 100
        return;
    }
    struct groceryItem newItem;     //initializing struct groceryItem variable to store all information of the new item added
    printf("Enter Item name: ");
    scanf("%s", newItem.Name);
    printf("Enter Category: ");
    scanf("%s", newItem.Category);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.Quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.Price);
    printf("Item added successfully!\n");

    inventory->items[inventory->totalCount] = newItem;      //This adds the new item to the inventory
    // Update the availability status
    inventory->status[inventory->totalCount].inStock = newItem.Quantity > 0;    //If the quantity is greater than zero, then the inStock field of the status array at index i is set to true otherwise false
    inventory->status[inventory->totalCount].outofStock = newItem.Quantity == 0;    //If the quantity is exactly zero, then the outofStock field of the status array at index i is set to true otherwise false
    inventory->totalCount++;    //This increments the total count of grocery items by 1 when new item is added
    
}

void listGroceryItems(struct groceryInventory *inventory) {     //function to list all grocery items with their name, category, quantity, price and availability status
    for (int i = 0; i < inventory->totalCount; i++) {
        struct groceryItem item = inventory->items[i];  //Initializing a struct variable of type groceryItem and assigning it to element at index i of items array in the inventory structure
        struct availabilityStatus status = inventory->status[i]; //Initializing a struct variable of type availabilityStatus and assigning it to element at index i of status array in the inventory structure
        printf("Name: %s\n", item.Name);
        printf("Category: %s\n", item.Category);
        printf("Quantity: %d\n", item.Quantity);
        printf("Price: %.2f\n", item.Price);
        if(status.inStock) {
            printf("Status: In stock\n");
        } else {
            printf("Status: Out of stock\n");
        }
    }
}

void updateQuantity (struct groceryInventory *inventory) {  //function to update the quantity of a grocery item
    char itemName[100];
    printf("Enter name of the grocery item to update quantity: ");  //Prompts the user to enter grocery item name
    scanf(" %s", itemName);     //Stores the name of the grocery item entered by user

    for (int i = 0; i<inventory->totalCount ; i++) {
        if(strncmp(inventory->items[i].Name, itemName , strlen(itemName)) == 0) {   //strncmp compares the size of item entered by user with other grocery items in the list
            printf("Enter new quantity for %s:", itemName);
            scanf("%d", &inventory->items[i].Quantity);
            inventory->status[i].inStock = inventory->items[i].Quantity > 0;    //If the quantity is greater than zero, then the inStock field of the status array at index i is set to true otherwise false
            inventory->status[i].outofStock = inventory->items[i].Quantity == 0;    //If the quantity is exactly zero, then the outofStock field of the status array at index i is set to true otherwise false
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("The item doesnt exist in the list!\n");     //Gives error message when item name entered by user doesnt match with any of the grocery items in the list
}

void removeGroceryItem (struct groceryInventory *inventory) {   //function to delete a grocery item from the list
    char itemName[100];
    printf("Enter name of the grocery item to remove: ");   //Prompts the user to enter grocery item name
    scanf(" %s", itemName);     //Stores the name of the grocery item entered by user


    for (int i = 0; i<inventory->totalCount ; i++) {
        if(strncmp(inventory->items[i].Name, itemName , strlen(itemName)) == 0) {   //strncmp compares the size of item entered by user with other grocery items in the list
            for (int j = i; j < inventory->totalCount - 1; j++) {   //The loop starts at the index i (the position of the item to be removed) and goes up to inventory->totalCount - 1
                inventory->items[j] = inventory->items[j + 1];  //This moves the item one position (index) to the left of the array
                inventory->status[j] = inventory->status[j + 1];      //This moves the status one position (index) to the left of the array
            }
        inventory->totalCount--;    //This reduces the total count of grocery items by 1 after removing an item
        printf("Item has been removed successfully!\n");
        return;
        }
    }
    printf("The item doesnt exist in the list!\n");     //Gives error message when item name entered by user doesnt match with any of the grocery items in the list
}

int main(void) {
    struct groceryInventory inventory;    //Initializing a struct variable 
    inventory.totalCount = 0;   //Setting total count to 0 means that initially there were no any grocery item
    int choice;

    while (choice!=5) {
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n2. List All Grocery Items\n3. Update Quantity\n4. Remove Grocery Item\n5. Exit\n");
        printf("Enter your choice:");       //Prompts the user to enter a number of his/her choice
        scanf("%d", &choice);       //Stores the number entered by user

        switch(choice) {
            case 1:
                addGroceryItem(&inventory);     //calling the addGroceryItem function to add a new item to the list
                break;

            case 2:
                listGroceryItems(&inventory);   //calling the listGroceryItems function to display all the items in the list
                break;

            case 3:
                updateQuantity(&inventory);     //calling the updateQuantity function to update the quantity of an item in the list
                break;

            case 4:
                removeGroceryItem(&inventory);  //calling the removeGrocery function to delete an item in the list
                break;

            case 5:
                printf("Exiting...\n");     //Exits the loop
                break;

            default:
                printf("You have entered an invalid choice! Please enter a number from 1 to 5");       //Gives error message if user enters invalid input
        }
    } 
    return 0;
}