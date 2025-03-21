// Q2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_item 500
#define max_name_length 100
#define max_category_length 50

int add_grocery_item();
int list_grocery_item();
int update_quantity();
int remove_grocery_item();
void exit_();

struct grocery_item {
    char name[max_name_length];
    char category[max_category_length];
    int quantity;
    float price;
    int stock;
};

struct grocery_item gI[max_item];
int item_count = 0;

int main(){
    while(1){
        int choice;
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n2. List All Grocery Item\n");
        printf("3. Update Quantity\n4. Remove Grocery Item\n5. Exit\n");
        printf("Enter yout choice: ");
        scanf("%d",&choice);
        getchar();
        
        switch(choice){
            case 1:
                add_grocery_item();
                break;
            case 2:
                list_grocery_item();
                break;
            case 3:
                update_quantity();
                break;
            case 4:
                remove_grocery_item();
                break;
            case 5:
                exit_();
                return 0;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }

    return 0;
}

int add_grocery_item(){
    if (item_count >= max_item){
        printf("\nMaximum grocery item reached. Cannot add new item.");
        return 0;
    }
    
    printf("\nEnter Item Name: ");
    fgets(gI[item_count].name,max_name_length,stdin);
    gI[item_count].name[strcspn(gI[item_count].name, "\n")] = 0;
    printf("Enter Category: ");
    fgets(gI[item_count].category,max_category_length,stdin);
    gI[item_count].category[strcspn(gI[item_count].category, "\n")] = 0;
    printf("Enter Quantity: ");
    scanf("%d",&gI[item_count].quantity);
    printf("Enter Price: ");
    scanf("%f",&gI[item_count].price);
    
    if (gI[item_count].quantity == 0){
        gI[item_count].stock = 0;
    } else {
        gI[item_count].stock = 1;
    }
    
    printf("\nGrocery item added sucessfully!\n");
    
    item_count++;
    
    return 0;
}

int list_grocery_item(){
    if (item_count == 0){
        printf("\nNo grocery item available");
        return 0;
    }
    
    for (int i = 0; i < item_count; i++){
        printf("\nName: %s",gI[i].name);
        printf("\nCategory: %s",gI[i].category);
        printf("\nQuantity: %d",gI[i].quantity);
        printf("\nPrice: %.2f",gI[i].price);
        if (gI[i].stock == 0){
            printf("\nStatus: Out of Stock");
        } else {
            printf("\nStatus: In Stock");
        }
        printf("\n");
    }
    
    return 0;
}

int update_quantity(){
    char namE[max_name_length];
    int item_exist = 0;
    
    printf("\nEnter name of the grocery item to update quantity: ");
    fgets(namE,max_name_length,stdin);
    namE[strcspn(namE, "\n")] = 0;
    
    for(int j = 0; j < item_count; j++){
        if (strcmp(gI[j].name,namE) == 0){
            item_exist = 1;
            printf("\nEnter new quantity for %s: ",gI[j].name);
            scanf("%d",&gI[j].quantity);
            printf("\nQuantity updated sucessfully.");
            if (gI[j].quantity == 0){
                gI[j].stock = 0;
            } else {
                gI[j].stock = 1;
            }
            break;
        } 
    }
    
    if (item_exist == 0){
        printf("\nGrocery item not found.");
        return 0;
    }
    
    return 0;
}

int remove_grocery_item(){
    char namE[max_name_length];
    int item_exist = 0;
    int remove_item_index;

    printf("\nEnter name of the grocery item to remove: ");
    fgets(namE,max_name_length,stdin);
    namE[strcspn(namE, "\n")] = 0;
    
    for(int j = 0; j < item_count; j++){
        if (strcmp(gI[j].name,namE) == 0){
            item_exist = 1;
            remove_item_index = j;
            item_count--;
            
            for(int k = remove_item_index; k < item_count; k++){
                gI[k] = gI[k + 1];
            }
            
            printf("\nGrocery item remove sucessfully!\n");
            break;
        } 
    }
    
    if (item_exist == 0){
        printf("\nGrocery item not found.");
        return 0;
    }
    
    return 0;
}


void exit_(){
    printf("\nSystem exited. :(\n");
}