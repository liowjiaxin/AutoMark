#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{ //Grocery Item struct
    char name[100];
    char category[100];
    int quantity;
    float price;
    char availability[100];
}GroceryItem;

//Function prototypes
void add();
void display();
void update();
void delete();

int main(){
    int choice = 0;
    int loop = 1;

    while(loop){
        //menu display
        printf("=======================\n");
        printf("Grocery Inventory Manager\n");
        printf("=======================\n");
        printf("1. Add\n2. Display\n3. Update\n4. Remove\n5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice); //user choice

        switch(choice){

            case 1:
            add(); //adding item
            break;

            case 2:
            display(); //displaying all items
            break;

            case 3:
            update(); //updating quantities
            break;

            case 4:
            delete(); //deleting items
            break;

            case 5:
            printf("Exiting..."); //exit
            loop = 0;
            break;

            default:
            printf("Please enter a valid input"); //in case user enters a value thats not supported

        }
    }
}

void add(){//function to add items to the file
    GroceryItem *item = malloc(sizeof(GroceryItem)); //allocating memory
    FILE *filept = fopen("Inventory.csv", "a+"); //opening csv file

    //prompting user inputs
    printf("Enter the name of the product: ");
    scanf(" %[^\n]s", item->name);
    printf("Enter the category of the item: ");
    scanf(" %[^\n]s", item->category);

    while(1){//infinite loop for error handling in case of a negative quantity input
        printf("Enter the quantity of the item: ");
        scanf(" %d", &item->quantity);

        if(item->quantity < 0){
            printf("The quantity of an item cannot be negative!");
        }else{
            break;
        }
    }

    printf("Enter the price of the item: RM ");
    scanf(" %f", &item->price);

    if(item->quantity > 0){ //determining whether item is in stock or not
        strcpy(item->availability, "In Stock");
    }else if(item->quantity == 0){
        strcpy(item->availability, "Out of Stock");
    }

    //writing into the file
    fprintf(filept, "%s, %s, %d, %.2f, %s\n", item->name, item->category, item->quantity, item->price, item->availability);
    fclose(filept); //closing file
    free(item);
}

//function to display all the items
void display(){
    FILE *filept = fopen("Inventory.csv", "r"); //opening the inventory in read
    char line[1024]; //fetch the items
    int i = 1; //counter
    printf("Name, Category, Quantity, Price(RM), Availability\n");

    while(fgets(line, sizeof(line), filept) != NULL){ //while fgets value is not null display the items
        printf("%d. %s\n", i, line);
        i++;
    }

    fclose(filept); //close the files
}

//function to update the quantity of the item
void update() {
    FILE *filept = fopen("Inventory.csv", "r"); //open Inventory.csv in read mode
    FILE *tempFile = fopen("Temp.csv", "w"); //open a temp file to write into
    char search[100], line[1024];
    char name[100], category[100], availability[100];
    int quantity;
    float price;
    int found = 0;

    if (filept == NULL || tempFile == NULL) { //error handling
        printf("Error: Could not open file.\n");
        if (filept != NULL) fclose(filept);
        if (tempFile != NULL) fclose(tempFile);
        return;
    }

    getchar();  // clear \n
    printf("Which product would you like to update: "); //prompting user input
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;  // remove trailing newline

    while (fgets(line, sizeof(line), filept) != NULL) {
        // traverse the current line
        int parsed = sscanf(line, "%99[^,],%99[^,],%d,%f,%99[^\n]", name, category, &quantity, &price, availability);
        if (parsed != 5) {
            printf("Error traversing line: %s", line);
            continue;  // Skip malformed lines
        }

        if (strcmp(search, name) == 0) { //checking for exact name match
            found = 1;
            printf("Enter the new quantity: ");
            while (scanf("%d", &quantity) != 1 || quantity < 0) {
                printf("Invalid input. Enter a non-negative quantity: ");
                while (getchar() != '\n');  // clear invalid input
            }
            while (getchar() != '\n');  // clear input buffer

            //updating availability
            if (quantity > 0) {
                strcpy(availability, "In Stock");
            } else {
                strcpy(availability, "Out of Stock");
            }
        }

        // Write to temp file
        fprintf(tempFile, "%s,%s,%d,%.2f,%s\n", name, category, quantity, price, availability);
    }

    //close files and replace original file with updated file
    fclose(filept);
    fclose(tempFile);

    if (found) {
        //replacing temp to Inventory.csv and deleting the old Inventory.csv
        remove("Inventory.csv");
        rename("Temp.csv", "Inventory.csv");
        printf("Quantity updated successfully.\n");
    } else {
        remove("Temp.csv");
        printf("Product not found.\n");
    }
}

//function to delete items
void delete() {
    FILE *filept = fopen("Inventory.csv", "r"); //open Inventory.csv in read mode
    FILE *tempFile = fopen("Temp.csv", "w"); //create Temp.csv to write updated list into
    char search[100], line[1024];
    char name[100], category[100], availability[100];
    int quantity;
    float price;
    int found = 0;

    if (filept == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    getchar();  //clear leftover newline from previous input
    printf("Which product would you like to delete: "); //user input for search term
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;  //remove '\n'

    while (fgets(line, sizeof(line), filept) != NULL) { //searching the file for search term
        sscanf(line, "%99[^,],%99[^,],%d,%f,%99[^\n]", name, category, &quantity, &price, availability);

        if (strcmp(search, name) == 0) { 
            found = 1;
            printf("Product '%s' deleted successfully.\n", name);
            continue;  //skips writing this line to the temp file
        }

        //write other lines to the temp file
        fprintf(tempFile, "%s,%s,%d,%.2f,%s\n", name, category, quantity, price, availability);
    }

    fclose(filept); //closing files
    fclose(tempFile);

    if (found) { //renaming temp to Inventory.csv
        remove("Inventory.csv");
        rename("Temp.csv", "Inventory.csv");
    } else {
        printf("Product not found.\n");
        remove("Temp.csv");
    }
}