#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Max_Name 100
#define Max_Category 50
#define Max_Items 100

// Grocery Item struct
typedef struct {
    char name[Max_Name];
    char category[Max_Category];
    int quantity;
    float price;
} GroceryItem;

//  Availability status struct
typedef struct {
    bool inStock;
    bool outStock;
} AvailabilityStatus;

GroceryItem inventory[Max_Items];
AvailabilityStatus availability[Max_Items];
int numItems = 0;

// Function to add grocery item
void addGroceryItem() {
    if (numItems >= Max_Items) {
        printf("Inventory is full\n");
        return;
    }

    GroceryItem newItem;

    printf("Enter Item Name: ");
    fgets(newItem.name, Max_Name, stdin);
    
    printf("Enter Category: ");
    fgets(newItem.category, Max_Category, stdin);
    
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    getchar(); 

    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    getchar(); 

    inventory[numItems] = newItem;
    availability[numItems].inStock = newItem.quantity > 0;                //new item more than 0 mean in stock
    availability[numItems].outStock = newItem.quantity == 0;              //new item equal to 0 mean out stock

    numItems++;

    printf("Grocery item added successfully!\n");
}

// Function to list grocery items
void listGroceryItems() {
    if (numItems == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < numItems; i++) {
        printf("\nName: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        if (availability[i].inStock) {
            printf("Status: In Stock\n");
        } else if (availability[i].outStock) {
            printf("Status: Out of Stock\n");
        }
    }
}

// Function to update the quantity of grocery item
void updateQuantity() {
    char name[Max_Name];

    printf("Enter the name of the grocery item to update quantity: ");
    fgets(name, Max_Name, stdin);
    name[strcspn(name, "\n")] = 0; 

    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter the new quantity for %s: ", inventory[i].name);
            scanf("%d", &inventory[i].quantity);
            getchar(); 

            availability[i].inStock = inventory[i].quantity > 0;        //item in inventory more than 0 mean in stock
            availability[i].outStock = inventory[i].quantity == 0;       //item in inventory equal to 0 mean out stock

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found\n");
}

// Function to remove a grocery item 
void removeGroceryItem() {
    char name[Max_Name];

    printf("Enter the name of the grocery item to remove: ");
    fgets(name, Max_Name, stdin);
    name[strcspn(name, "\n")] = 0; 

    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            
            for (int j = i; j < numItems - 1; j++) {
                inventory[j] = inventory[j + 1];
                availability[j] = availability[j + 1];
            }
            numItems--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found\n");
}

int main() {
    int choice;

    while (1) {
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addGroceryItem();
                break;
            case 2:
                listGroceryItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeGroceryItem();
                break;
            case 5:
                printf("Exiting system\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
