#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 100

//Structure which represents a product
typedef struct {
    char itemName[100];
    char itemCategory[50];
    int itemQuantity;
    float itemPrice;
    int isInStock;
} Product;

//Structure which represents the inventory
typedef struct {
    Product products[MAX_CAPACITY];
    int totalProducts;
} ProductInventory;

//Function t add a new product
void addProduct(ProductInventory *inventory) {
    if (inventory->totalProducts >= MAX_CAPACITY) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    Product *product = &inventory->products[inventory->totalProducts];
    printf("Enter Item Name: ");
    scanf(" %[^\n]", product->itemName);
    printf("Enter Category: ");
    scanf(" %[^\n]", product->itemCategory);
    printf("Enter Quantity: ");
    scanf("%d", &product->itemQuantity);
    printf("Enter Price: ");
    scanf("%f", &product->itemPrice);
    product->isInStock = product->itemQuantity > 0;
    inventory->totalProducts++;
    printf("Grocery item added successfully!\n");
}

//Function to list all the products available in the inventory
void listProducts(const ProductInventory *inventory) {
    if (inventory->totalProducts == 0) {
        printf("No products in inventory.\n");
        return;
    }
    for (int i = 0; i < inventory->totalProducts; i++) {
        const Product *product = &inventory->products[i];
        printf("\nProduct %d:\n", i + 1);
        printf("Name: %s\n", product->itemName);
        printf("Category: %s\n", product->itemCategory);
        printf("Quantity: %d\n", product->itemQuantity);
        printf("Price: %.2f\n", product->itemPrice);
        printf("Status: %s\n", product->isInStock ? "In Stock" : "Out of Stock");
    }
}

//Function to update the quantity of a product
void updateProductQuantity(ProductInventory *inventory) {
    char productName[100];
    printf("Enter the name of the grocery item to update quantity: ");
    scanf(" %[^\n]", productName);

    for (int i = 0; i < inventory->totalProducts; i++) {
        Product *product = &inventory->products[i];
        if (strcmp(product->itemName, productName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &product->itemQuantity);
            product->isInStock = product->itemQuantity > 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Error: Product not found.\n");
}

//Function to remove a product 
void removeProduct(ProductInventory *inventory) {
    char productName[100];
    printf("Enter name of the grocery item to remove: ");
    scanf(" %[^\n]", productName);

    for (int i = 0; i < inventory->totalProducts; i++) {
        if (strcmp(inventory->products[i].itemName, productName) == 0) {
            for (int j = i; j < inventory->totalProducts - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }
            inventory->totalProducts--;
            printf("Product removed successfully!\n");
            return;
        }
    }
    printf("Error: Product not found.\n");
}

int main() {
    ProductInventory inventory = {.totalProducts = 0};
    int userChoice;

    printf("Grocery Inventory Management System\n");

    //Displaying the menu
    do {
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: //Adding a new product
                addProduct(&inventory);
                break;
            case 2: //Listing all the products
                listProducts(&inventory);
                break;
            case 3: //Updating the quantity of a product 
                updateProductQuantity(&inventory);
                break;
            case 4: //Removing a product
                removeProduct(&inventory);
                break;
            case 5: //Exiting the program
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (userChoice != 5);

    return 0;
}
