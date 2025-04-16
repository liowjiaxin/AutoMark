#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100 //max size of grocery list
#define NAME 100
#define CATEGORY 100

void r_scan(){
    int c;
    while ((c = getchar()) != '\n')
    continue;
}
void strget(char* str, int constant){   //end "/n in fgets"
    fgets(str, constant, stdin);
    str[strcspn(str, "\n")] = 0; 
}

typedef struct {
    char name[NAME];  
    char category[CATEGORY];
    int quantity;
    float price;
}Item;

typedef struct {
    bool in_stock;
    bool out_of_stock;
}Avaliability;

Item item[SIZE];
Avaliability avaliable[SIZE];

int main() {
    int total_items = 0;

    while(1){
        puts("Grocery Inventory Management Menu: ");
        puts("1. Add Grocery Item");
        puts("2. List All Grocery Items");
        puts("3. Update Quantity");
        puts("4. Remove Grocery Item");
        puts("5. Exit");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        r_scan();


        switch (choice) {
        case 1: //Add
            printf("Enter Item Name: ");
            strget(item[total_items].name, NAME);

            printf("Enter Catergory: ");
            strget(item[total_items].category, CATEGORY);

            printf("Enter Quantity: ");
            scanf("%d",&item[total_items].quantity);
            r_scan();

            printf("Enter Price: ");
            scanf("%f",&item[total_items].price);
            r_scan();

            if (item[total_items].quantity <= 0){
                avaliable[total_items].in_stock = false;
                avaliable[total_items].out_of_stock = true;
            }else{
                avaliable[total_items].in_stock = true;
                avaliable[total_items].out_of_stock = false;
            }

            printf("Grocery item added successfully!\n\n");
            total_items++;
            
            break;

        case 2: //List All
            if (total_items == 0){
                puts("No grocery in inventory");
                break;
            }
            for (int i = 0; i < total_items; i++) {
                printf("Name: %s\n", item[i].name);
                printf("Category: %s\n", item[i].category);
                printf("Quantity: %d\n", item[i].quantity);
                printf("Price: %.2f\n", item[i].price);

                if (avaliable[i].in_stock==true){
                    printf("Status: In Stock\n\n");
                }else if (avaliable[i].out_of_stock==true){
                    printf("Status: Out of Stock\n\n");
                }
            }
            break;

        case 3: // update quantity
            char name[NAME];
            int found = 0;
            printf("Enter the name of grocery item to update quantity: ");
            strget(name, NAME);
            for (int i = 0; i <= total_items; i++) {
                if (strcmp(name, item[i].name)==0){
                    found = 1;
                    printf("Enter new quantity for %s: ", item[i].name);
                    scanf("%d",&item[i].quantity);
                    puts("Quantity updated successfully!\n\n");
                    if (item[total_items].quantity <= 0){
                        avaliable[i].in_stock = false;
                        avaliable[i].out_of_stock = true;
                    }else{
                        avaliable[i].in_stock = true;
                        avaliable[i].out_of_stock = false;
                    }
                    break;
                }
            }
            if (found == 0){
                puts("Item not found\n");
            }
            break;

        case 4: // remove item
            printf("Enter the name of the grocery item to remove: ");
            strget(name, NAME);

            found = 0; 
            for (int i = 0; i < total_items; i++) {
                if (strcmp(name, item[i].name) == 0) {
                    found = 1;
                    for (int j = i; j <= total_items - 1; j++) {        //<= cause after total item is empty so copy empty to last string
                        item[j] = item[j + 1];
                        avaliable[j] = avaliable[j + 1];
                    }
                    total_items--;
                    printf("Grocery item '%s' removed successfully!\n\n", name);
                    break;
                }
            }

            if (found==0) {
                printf("Item not found");
            }
            break;
        
        case 5:
            return 0;
            break;

        default:
            puts("Please enter between number 1-5");
            break;
        }
    }
}