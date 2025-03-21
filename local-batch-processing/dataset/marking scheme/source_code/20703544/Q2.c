#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h> 

#define MAX_CONTACT 100

int compareItem(const void *a, const void *b);

struct GroceryItem {
    int quantity;  
    char name[100], category[50];
    float price;
} new_item, grocery_item[MAX_CONTACT];

int main() {
    FILE *fPtr = NULL;
    int choice = 0;
    while(choice != 5) {
    printf("GROCERY INVENTORY MANAGEMENT SYSTEM\n");
    printf("[1]ADD GROCERY ITEM\n");
    printf("[2]LIST ALL GROCERY ITEM\n");
    printf("[3]UPDATE QUANTITY\n");
    printf("[4]REMOVE GROCERY ITEM\n");
    printf("[5]EXIT\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch(choice) {
        case 1:
        printf("Enter Item Name: ");
        fgets(new_item.name, 100, stdin);
        new_item.name[strcspn(new_item.name, "\n")] = '\0';
        printf("Enter Category: ");
        fgets(new_item.category, 50, stdin);
        new_item.category[strcspn(new_item.category, "\n")] = '\0';
        printf("Enter Quantity: ");
        scanf("%d", &new_item.quantity);
        getchar();
        printf("Enter Price: ");
        scanf("%f", &new_item.price);
        getchar();
        fPtr = fopen("GroceryItem.txt", "a+");
        if (fPtr == NULL) {
        printf("Error opening file!\n");
        }
        fwrite(&new_item, sizeof(struct GroceryItem), 1, fPtr);
        fclose(fPtr);
        printf("Item added succesfully.\n\n");
        break;
        case 2:
        fPtr = fopen ("GroceryItem.txt", "r");
        while(fread(&new_item, sizeof(struct GroceryItem), 1, fPtr)) {
        if(fread(&new_item, sizeof(struct GroceryItem), 1, fPtr)==0) {
            printf("No item in the inventory.\n\n");
        } else if(new_item.quantity > 0) {
            printf("Grocery Item Name: %s\nCategory: %s\nQuantity: %d\nPrice: %.2f\nStatus: In Stock\n\n", new_item.name, new_item.category, new_item.quantity, new_item.price);
        } else {
            printf("Grocery Item Name: %s\nCategory: %s\nQuantity: %d\nPrice: %.2f\nStatus: Out of Stock\n\n", new_item.name, new_item.category, new_item.quantity, new_item.price); 
        }
        }
        if(fread(&new_item, sizeof(struct GroceryItem), 1, fPtr)==0) {
            printf("No item in the inventory.\n\n");
        }
        fclose(fPtr);
        break;
        case 3:
        fPtr = fopen("GroceryItem.txt", "r");
        if (fPtr == NULL) {
        printf("Error opening file!\n");
        }

        FILE *newFile = fopen("NEW.txt", "w");
        if (newFile == NULL) {
        printf("Error opening temporary file!\n");
        fclose(fPtr);
        }

        char searchName[100];
        int found = 0;
    
        printf("Enter the name of the item to update: ");
        fgets(searchName, 100, stdin);
        searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline character

        while (fread(&new_item, sizeof(struct GroceryItem), 1, fPtr)) {
        if (strcmp(new_item.name, searchName) == 0) {
        found = 1;
        printf("Enter Quantity: ");
        scanf("%d", &new_item.quantity);
        getchar();
        }
        fwrite(&new_item, sizeof(struct GroceryItem), 1, newFile);
        }

        fclose(fPtr);
        fclose(newFile);

        if (found) {
        remove("GroceryItem.txt");
        rename("NEW.txt", "GroceryItem.txt");
        printf("Quantity updated successfully.\n\n");
        } else {
        remove("NEW.txt");
        printf("Item not found.\n\n");
        }
        
        break;
        case 4:
        fPtr = fopen("GroceryItem.txt", "r");
        if (fPtr == NULL) {
        printf("Error opening file!\n");
        }

        FILE *new_File = fopen("NEW.txt", "w");
        if (new_File == NULL) {
        printf("Error opening temporary file!\n");
        fclose(fPtr);
        }

        char search_Name[100];
        int FOUND = 0;
    
        printf("Enter the name of the item to remove: ");
        fgets(search_Name, 100, stdin);
        search_Name[strcspn(search_Name, "\n")] = '\0'; 
        
        while (fread(&new_item, sizeof(struct GroceryItem), 1, fPtr)) {
        if (strcmp(new_item.name, search_Name) != 0) {
            fwrite(&new_item, sizeof(struct GroceryItem), 1, new_File);
        } else {
            FOUND = 1;
        }
        }
        fclose(fPtr);
        fclose(new_File);
        if (FOUND) {
        remove("GroceryItem.txt");
        rename("NEW.txt", "GroceryItem.txt");
        printf("Item removed successfully.\n\n");
        } else {
        remove("NEW.txt");
        printf("Item not found.\n\n");
        }
        break;
        case 5:
        printf("Exiting program.\n");
        break;
        default:
        printf("Undefined choice. PLease try again.\n");
        break;

        fclose(fPtr);
            
        }
    }
    return 0;
}

