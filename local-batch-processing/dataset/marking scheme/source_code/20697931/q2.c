#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 100

struct grocery_item{
    char name[100];
    char category[100];
    int quantity;
    float price;
};

struct availability_status{
    bool instock;
};

struct grocery_inventory{
    struct grocery_item items_array[1000];
    struct availability_status available_array[100];
    int total_items_num;
};




void Add_GroceryItem(struct grocery_inventory* groceryaddress){

    if (groceryaddress->total_items_num == 1000){
        printf("inventory is full");
        printf("Not successful");
    }
    else{
        int index=groceryaddress->total_items_num;
       
        
        printf("Enter Item Name:");
        getchar();
        
        fgets(groceryaddress->items_array[index].name,sizeof(groceryaddress->items_array[index].name),stdin);
        groceryaddress->items_array[index].name[strcspn(groceryaddress->items_array[index].name, "\n")] = '\0'; // Remove newline
        
        
        printf("Enter Item category:");
        fgets(groceryaddress->items_array[index].category,sizeof(groceryaddress->items_array[index].category),stdin);
        groceryaddress->items_array[index].category[strcspn(groceryaddress->items_array[index].category, "\n")] = '\0'; // Remove newline

        int item_quantity=0;
        printf("Enter Quantity:");
        scanf("%d",&item_quantity);
        groceryaddress->items_array[index].quantity=item_quantity;
        if( item_quantity ==0){
            groceryaddress->available_array[index].instock=false;
        }

        

        float item_price=0.0;
        printf("Enter price:");
        scanf("%f",&item_price);
        groceryaddress->items_array[index].price=item_price;

        groceryaddress->total_items_num++;

        printf("Grocery item added succesfully\n");
       
    
    }

}


void List_GroceryItems(struct grocery_inventory* groceryaddress){
    for (int i=0;i<groceryaddress->total_items_num;i++){
        printf("Name:%s\n",groceryaddress->items_array[i].name);
        printf("Category:%s\n",groceryaddress->items_array[i].category);
        printf("Quantity:%d\n",groceryaddress->items_array[i].quantity);
        printf("Price:%.2f\n",groceryaddress->items_array[i].price);

        
        if (groceryaddress->available_array[i].instock == true){
            printf("Status:In Stock\n");
        }
        else{
            printf("Status:Out of Stock\n");
    
        }
        


    }
}




void Update_GroceryItem(struct grocery_inventory* groceryaddress,char item_name[100]){
    int found=0;
    for (int i=0; i < groceryaddress->total_items_num;i++){
        if (strcmp(groceryaddress->items_array[i].name,item_name) == 0){
            printf("Enter a new quantity:");
            scanf("%d",&groceryaddress->items_array[i].quantity);
            if(groceryaddress->items_array[i].quantity == 0){
                groceryaddress->available_array[i].instock = false;
            }
            found=1;
            printf("Updated successfully\n");
            break;
        }
    }
    if (found == 0){
        printf("Grocery item not found\n");
    }

}

void Remove_GroceryItem(struct grocery_inventory* groceryaddress,char item_name[100]){
    int found=0;
    for (int i=0; i < groceryaddress->total_items_num;i++){
        if (strcmp(groceryaddress->items_array[i].name,item_name) == 0 ){
            strcpy(groceryaddress->items_array[i].name,"");
            strcpy(groceryaddress->items_array[i].category,"");
            groceryaddress->items_array[i].quantity=0;
            groceryaddress->items_array[i].price=0.0;
            found=1;
            groceryaddress->total_items_num --;
            printf(" Grocery item deleted successfully\n");

            break;
        }
    }
    if (found == 0){
        printf("Grocery item not found\n");
    }

}








void main(){

    struct grocery_inventory grocery;
    struct grocery_inventory* groceryptr=&grocery;
    
    
    grocery.total_items_num=0;

    int choice=0;

    while(1){
        printf("Menu:\n");
        printf("1.Add Grocery Item\n");
        printf("2.List All Grocery Items\n");
        printf("3.Update Quantity\n");
        printf("4.Remove Grocery Item\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        
        //Validation
        while(choice < 1|| choice >5){
            printf("Invalid");
            printf("Enter your choice:");
            scanf("%d",&choice);

        }
        
        //Exit
        if (choice == 5){
            break;
        }

        switch (choice){

        //Add the grocery item
        case 1:
           Add_GroceryItem(groceryptr);
           break;
        
        //display 
        case 2:
            List_GroceryItems(groceryptr);
            break;
        
        //update
        case 3:
            char update_item[100];
            printf("Enter the name of item to update:");
            getchar();
            fgets(update_item,sizeof(update_item),stdin);
            update_item[strcspn(update_item, "\n")] = '\0';
            
           
            Update_GroceryItem(groceryptr,update_item);
            break;

        //delete
        case 4:
            char delete_item[100];
             printf("Enter the name of item to delete:");
            getchar();
            fgets(delete_item,sizeof(delete_item),stdin);
            update_item[strcspn(delete_item, "\n")] = '\0';
            
            Remove_GroceryItem(groceryptr,delete_item);

            break;
        

        
        }

    }
    
}