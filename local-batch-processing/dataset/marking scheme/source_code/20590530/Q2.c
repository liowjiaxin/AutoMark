#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Create structs for managing grocery item info and item availability

typedef struct  {
    char Name[100];         //limited to a size of 100
    char Category[50];      //limited to a size of 50
    int Quantity;
    float Price;
} GroceryItem;

typedef union  {
    bool inStock;
    bool outStock;
} AvailabilityStatus;

typedef struct GroceryInventory {
    GroceryItem items[100];
    AvailabilityStatus status[100];
    int count;              //counter for total number of grocery items
} GroceryInventory;

int main() {
    //Set counter to 0
    GroceryInventory inventory = {.count = 0};

    //Declare variables
    int choice;

    //Prompt user the options for the system
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid Input. Exiting program...\n");
            return 1;  // Terminating program if invalid input
        }
        getchar(); // clear the newline from the buffer

        switch (choice) {
            case 1: {
                GroceryItem *item = &inventory.items[inventory.count];
                AvailabilityStatus *status = &inventory.status[inventory.count];

                //Prompt user to input name of item
                printf("Enter Item Name: ");
                fgets(item->Name, sizeof(item->Name), stdin);
                item->Name[strcspn(item->Name, "\n")] = '\0'; //remove newline character

                //Prompt user to input Category of item
                printf("\nEnter Category: ");
                fgets(item->Category, sizeof(item->Category), stdin);
                item->Category[strcspn(item->Category, "\n")] = '\0'; //remove newline character

                //Prompt user to input Quantity of item
                printf("\nEnter Quantity: ");
                if (scanf("%d", &item->Quantity) != 1) {
                    printf("Invalid input for Quantity.\n");
                    while (getchar() != '\n'); //clear the buffer
                    break;  
                }
                getchar();

                //Prompt user to input Price of item
                printf("\nEnter Price: ");
                if (scanf("%f", &item->Price) != 1) {
                    printf("Invalid input for Price.\n");
                    while (getchar() != '\n'); //clear the buffer
                    break;  
                }
                getchar();

                //update status and availability based on item->Quantity
                status->inStock = item->Quantity > 0;

                //update the counter
                inventory.count++;

                //display output to user for confirmation
                printf("\nGrocery Item added successfully!\n");
                break;
            }

            case 2: {
                //Check if inventory is empty
                if (inventory.count == 0) {
                    printf("No Grocery Items in inventory.\n");
                } else {
                    //If inventory is not empty, display items to user
                    for (int i = 0; i < inventory.count; i++) {
                        GroceryItem item = inventory.items[i];
                        AvailabilityStatus status = inventory.status[i];

                        printf("\nName: %s\n", item.Name);
                        printf("Category: %s\n", item.Category);
                        printf("Quantity: %d\n", item.Quantity);
                        printf("Price: %.2f\n", item.Price);
                        printf("Status: %s\n", status.inStock ? "In Stock" : "Out of Stock");
                    }
                }
                break;
            }

            case 3: {
                //check if inventory is empty or not
                if (inventory.count == 0) {
                    printf("No Grocery Items in inventory to update.\n");
                } else {
                    //Prompt user to input name of item to update quantity
                    char name[100];
                    printf("Enter name of the grocery item to update quantity: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0'; //Remove newline character

                    int found = 0;
                    for (int i = 0; i < inventory.count; i++) {
                        GroceryItem *item = &inventory.items[i];
                        AvailabilityStatus *status = &inventory.status[i];

                        if (strcmp(item->Name, name) == 0) {
                            found = 1;
                            printf("Enter new quantity for %s: ", item->Name);
                            if (scanf("%d", &item->Quantity) != 1) {
                                printf("Invalid input for Quantity.\n");
                                while (getchar() != '\n'); //clear buffer
                                break;  
                            }

                            getchar();
                            status->inStock = item->Quantity > 0;
                            printf("Quantity updated for %s.\n", item->Name);
                            break;
                        }
                    }

                    if (!found) {
                        printf("This item does not exist.\n");
                    }
                }
                break;
            }

            case 4: {
                //Check if inventory is empty
                if (inventory.count == 0) {
                    printf("No Grocery Items in inventory to remove.\n");
                } else {
                    //Prompt user to input name of item to remove
                    char name[100];
                    printf("Enter name of the grocery item to remove: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0'; //Remove newline character

                    int found = 0;
                    for (int i = 0; i < inventory.count; i++) {
                        GroceryItem *item = &inventory.items[i];
                        AvailabilityStatus *status = &inventory.status[i];

                        if (strcmp(item->Name, name) == 0) {
                            found = 1;
                            printf("Grocery item '%s' has been removed successfully!\n", item->Name);

                            //Update the inventory by shifting items
                            for (int j = i; j < inventory.count - 1; j++) {
                                inventory.items[j] = inventory.items[j + 1];
                                inventory.status[j] = inventory.status[j + 1];
                            }

                            inventory.count--;
                            break;
                        }
                    }

                    if (!found) {
                        //if nothing was found
                        printf("No such item exists in inventory.\n");
                    }
                }
                break;
            }

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice, please try again.\n");
        }
    }

    return 0;
}
