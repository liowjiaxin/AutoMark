#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

struct Grocery {
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool stock;
};

struct Grocery inventory[MAX];
int count = 0;

void addItem() {
    struct Grocery item;
    
    if (count >= MAX) {
        printf("Inventory is full. Failed to add item.\n");
        return;
    }
    
    getchar();
    printf("Enter Item Name: ");
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = '\0';
    
    printf("Enter Category: ");
    fgets(item.category, sizeof(item.category), stdin);
    item.category[strcspn(item.category, "\n")] = '\0';

    
    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);
    
    printf("Enter Price: ");
    scanf("%f", &item.price);
    
    item.stock = (item.quantity > 0);
    
    inventory[count++] = item;
    
    printf("Grocery item added successfully!\n\n");
    
}

void listItem () {
    if (count==0) {
        printf("\nNo grocery items in the inventory.\n\n");
        return;
    }
    
    for(int i=0; i<count; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n\n", inventory[i].stock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity() {
    if (count == 0) {
        printf("\nNo grocery items in the inventory.\n\n");
        return;
    }

    getchar();
    char name[100];
    printf("Enter the name of the grocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the trailing newline

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory[i].quantity);
            inventory[i].stock = (inventory[i].quantity > 0); // Update stock status
            printf("Quantity updated successfully!\n\n");
            return;
        }
    }
    printf("Item not found in the inventory.\n\n");
}

void removeItem() {
    if (count == 0) {
        printf("\nNo grocery items in the inventory.\n\n");
        return;
    }

    getchar(); // Clear input buffer
    char name[100];
    printf("Enter the name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1]; 
            }
            count--;
            printf("Grocery item '%s' removed successfully!\n\n", name);
            return;
        }
    }
    printf("Item not found in the inventory.\n\n");
}

int main()
{
    int choice;
    
    do {
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            
            case 2:
                listItem();
                break;
              
            case 3:
                updateQuantity();
                break;
                
            case 4:
                removeItem();
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.");
        }
    }while(choice!=5);
}


