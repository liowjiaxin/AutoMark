
#include <stdio.h>
#define MAX_ITEMS 100 


typedef struct {
    char name[100]; 
    int quantity;   
    float price;    
} groceryitem;

//add groceryitem
void add(groceryitem inventory[], int *itemcount) {
    printf("Enter item name: ");
    scanf("%s", inventory[*itemcount].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*itemcount].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[*itemcount].price);
    (*itemcount)++;
    printf("Item added!\n");
}

// list groceryitem
void list(groceryitem inventory[], int itemcount) {
    if (itemcount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    for (int i = 0; i < itemcount; i++) {
        printf("Item %d: %s - Quantity: %d, Price: $%.2f\n", i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

//update groceryitem
void update(groceryitem inventory[], int itemcount){
    int index, quantity;
    printf("Enter item number to update (1 to %d): ", itemcount);
    scanf("%d", &index);
    if (index < 1 || index > itemcount) {
        printf("Invalid item number!\n");
        return;
    }
    printf("Enter new quantity: ");
    scanf("%d", &quantity);
    inventory[index - 1].quantity = quantity;
    printf("Quantity updated!\n");
}

// Remove grocery items
void Remove(groceryitem inventory[], int *itemcount){
    int index;
    printf("Enter item number to remove (1 to %d): ",*itemcount);
    scanf("%d",&index);
    if(index<1 || index> *itemcount){
        printf("Invalid item number!\n");
        return;
    }
    for(int i = index-1; i < *itemcount - 1; i++){
        inventory[i] = inventory[i + 1];//move items at the back to the front
    }
    (*itemcount)--;//decrease item count by one
    printf("Item removed!\n");
}

int main(){
    groceryitem inventory[MAX_ITEMS]; // Define inventory array
    int itemcount = 0; // initialization
    int choice;

    do {
        printf("\nMenu:\n1.add item\n2.list items\n3.update quantity\n4.remove item\n5.exit\nenter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if (itemcount < MAX_ITEMS)
                    add(inventory, &itemcount);
                else
                    printf("Inventory is full!\n");
                break;
            case 2:
                list(inventory, itemcount);
                break;
            case 3:
                update(inventory, itemcount);
                break;
            case 4:
                
                Remove(inventory, &itemcount);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 5);

    return 0;
}


