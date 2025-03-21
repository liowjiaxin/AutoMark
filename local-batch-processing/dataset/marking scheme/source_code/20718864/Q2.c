#include <stdio.h>
#include <string.h>

// Create struct for grocery items
struct GroceryItem {
    char name[100];
    char category[50];
    int quantity;
    float price;
};

// Global Variables
struct GroceryItem items[100]; 
int itemCount = 0;             

// Add a grocery item
void addItem() 
{
    // Checks if the amount is below maximum
    if (itemCount >= 100) {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", items[itemCount].name);  

    printf("Enter category: ");
    scanf("%s", items[itemCount].category);

    printf("Enter quantity: ");
    scanf("%d", &items[itemCount].quantity);

    printf("Enter price: ");
    scanf("%f", &items[itemCount].price);

    itemCount++;
    printf("Item added.\n");
}


void listItems() 
{
    // Checks if the inventory is empty or not
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }

    // Loop through each item in the inventory
    for (int i = 0; i < itemCount; i++) 
    {
        // Print details of each item 
        printf("Item %d: %s, %s, Quantity: %d, Price: %.2f, Status: %s\n", 
            i + 1, items[i].name, items[i].category, items[i].quantity, 
            items[i].price, items[i].quantity > 0 ? "In Stock" : "Out of Stock");
    }
}

void removeItem() 
{
    // Checks if the inventory is empty or not
    if (itemCount == 0) 
    {
        printf("Inventory is empty.\n");
        return;
    }

    // Get the name of the item to remove
    char name[100];
    printf("Enter the name of the item to remove: ");
    scanf("%s", name);  

    // Loop through the inventory to find the item by nbame
    for (int i = 0; i < itemCount; i++) 
    {
        if (strcmp(items[i].name, name) == 0) 
        {
            // Shift all items after the found item one position to the left
            for (int j = i; j < itemCount - 1; j++) 
            {
                items[j] = items[j + 1];
            }
            itemCount--;  
            printf("Item '%s' removed successfully.\n", name);
            return;  
        }
    }

    // check if item exist
    printf("Item not found.\n");
}



void updateItem() 
{
    // Checks if the inventory is empty or not
    if (itemCount == 0) 
    {
        printf("Inventory is empty.\n");
        return;
    }

    // Find the mentioned item
    char name[100];
    printf("Enter the name of the item to update: ");
    scanf("%s", name);

    // Loop to find the item that wanted to be updated
    for (int i = 0; i < itemCount; i++) 
    {
        if (strcmp(items[i].name, name) == 0) 
        {
            // Update quantity and price
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &items[i].price);

            printf("Item '%s' updated.\n", name);
            return;
        }
    }

    // Checks if item exist or not
    printf("Item not found.\n");
}



int main() {

    printf("\nGrocery Inventory Menu:\n");
    printf("1. Add Grocery Item\n");
    printf("2. List Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");

    int choice;
    // Use while loop to keep looping until user exit the program
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 


        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                // Exit the program
                printf("Exiting program...\n");
                return 0; 
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}




