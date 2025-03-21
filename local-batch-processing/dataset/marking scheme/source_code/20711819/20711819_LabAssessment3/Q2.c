#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a typedef to reference to stock status
typedef int availabilityStatus;

enum EnumAvailabilityStatus{
    OUT_OF_STOCK = 0,
    IN_STOCK = 1
};

// typedef for operation type cause why not
typedef int operationType;
// typedef for sentient check CAUSE WHY NOT
typedef int sentientType;

enum EnumSentientType{
    CONTINUE = 1,
    STOP = 0
};

// struct for grocery item
struct GroceryItem{
    char name[101];
    char category[51];
    int quantity;
    float price;
};

// struct for grocery inventory
struct GroceryInventory{
    struct GroceryItem *itemList[100];
    availabilityStatus itemAvailability[100];
    int itemCount;
};

// function to read string
void readString(char *storeTo){
    int i = 0;
    char hold = ' ';
    // scanf until encounter return
    for (scanf(" %c", &hold); hold != '\n'; scanf("%c", &hold))
        storeTo[i++] = hold;
    // make sure the ending char is \0
    storeTo[i] = '\0';
}

// add grocery item
void addGrocery(struct GroceryInventory *thisInventory){
    struct GroceryItem *newGroceryItem = malloc(sizeof(struct GroceryItem));
    printf("\nAdding new item...\n");
    printf("Enter item name: ");
    readString(newGroceryItem->name);
    printf("Enter category: ");
    readString(newGroceryItem->category);
    printf("Enter quantity: ");
    scanf("%d", &newGroceryItem->quantity);
    printf("Enter price: RM");
    scanf("%f", &newGroceryItem->price);

    for (int i = 0; i < 100; i++){
        if (thisInventory->itemList[i] == NULL){
            ((*thisInventory).itemList)[i] = newGroceryItem;
            (thisInventory->itemAvailability)[i] = (newGroceryItem->quantity > 0 ? IN_STOCK : OUT_OF_STOCK);
            (thisInventory->itemCount)++;
            break;
        }
    }
}

// update quantity uwu
void updateGroceryItemQuantity(struct GroceryInventory *thisInventory){
    int hasUpdated = 0;
    char updateItem[101];
    printf("\nUpdating grocery item's quantity...\n");
    printf("Enter the name of the grocery item to update quantity: ");
    readString(updateItem);
    for (int i = 0; i < 100; i++){
        if (thisInventory->itemList[i] != NULL){
            if (strcmp(updateItem, thisInventory->itemList[i]->name) == 0){
                printf("Enter new quantity for %s: ", updateItem);
                scanf("%d", &(thisInventory->itemList[i]->quantity));
                if (thisInventory->itemList[i]->quantity < 1){
                    thisInventory->itemAvailability[i] = OUT_OF_STOCK;
                }
                hasUpdated++;
                break;
            }
        }
    }
    if (hasUpdated == 0){
        printf("Unable to locate item '%s'...\n", updateItem);
    }
}

// remove grocery item
void removeGroceryItem(struct GroceryInventory *thisInventory){
    int hasUpdated = 0;
    char updateItem[101];
    printf("\nRemoving a grocery item...\n");
    printf("Enter the name of the grocery item to remove: ");
    readString(updateItem);

    for (int i = 0; i < 100; i++){
        if (thisInventory->itemList[i] != NULL){
            if (strcmp(updateItem, thisInventory->itemList[i]->name) == 0){
                (thisInventory->itemList[i]) = NULL;
                (thisInventory->itemAvailability[i]) = OUT_OF_STOCK;
                (thisInventory->itemCount)--;
                hasUpdated++;
                break;
            }
        }
    }

    if (hasUpdated == 0){
        printf("Unable to locate item '%s'...\n", updateItem);
    }
}

// function to print all items in grocery inventory
void printGroceryInventory(struct GroceryInventory *thisInventory){
    int itemPrint = 0;
    printf("\nPrinting all items in grocery inventory...\n");
    for (int i = 0; i < 100; i++){
        if (thisInventory->itemList[i] != NULL){
            printf("_________________________\n");
            printf("Item %d\n", ++itemPrint);
            printf("Name: %s\n", thisInventory->itemList[i]->name);
            printf("Category: %s\n", thisInventory->itemList[i]->category);
            printf("Quantity: %d\n", thisInventory->itemList[i]->quantity);
            printf("Price: RM%.2f\n", thisInventory->itemList[i]->price);
            printf("Status: %s\n", (thisInventory->itemAvailability[i] == IN_STOCK ? "In stock" : "Out of stock"));
        }
    }
}

int main(){
    struct GroceryInventory myGroceryInventory = {{}, {}, 0}; // variable for grocery inventory
    sentientType sentient = CONTINUE; // sentient check
    int choice = 0;
    while(sentient){
        choice = 0; // choice = 0
        // print options
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add grocery item\n");
        printf("2. List all grocery items\n");
        printf("3. Update quantity\n");
        printf("4. Remove grocery item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // repeat until valid choice
        while (choice < 1 || choice > 5){
            printf("Invalid choice, please try again.\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
        }
        // perform operation base on choice
        switch(choice){
            case 1:
                addGrocery(&myGroceryInventory);
                break;
            case 2:
                printGroceryInventory(&myGroceryInventory);
                break;
            case 3:
                updateGroceryItemQuantity(&myGroceryInventory);
                break;
            case 4:
                removeGroceryItem(&myGroceryInventory);
                break;
            case 5:
                printf("Exiting... uwu\n");
                sentient = STOP;
                break;
        }
    }
}