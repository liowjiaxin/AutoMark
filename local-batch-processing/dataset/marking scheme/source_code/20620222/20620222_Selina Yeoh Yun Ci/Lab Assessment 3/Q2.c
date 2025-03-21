#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100
#define NAME 100
#define CATEGORY 50

struct groceries {
    char name[NAME];
    char category[CATEGORY];
    int quantity;
    float price;
};

void add(struct groceries *s, int *numGroceries);
void list(struct groceries *groceryArray, int numGroceries);
void update(struct groceries *groceryArray, int numGroceries);
void remove_item(struct groceries *groceryArray, int *numGroceries);
void remove_whitespaces();

int main() {
    struct groceries groceryArray[MAX_ITEMS];
    int numGroceries = 0;
    char choice;
    while (1) {
        puts("***************************************************************");
        puts("             Grocery Inventory Management System");
        puts("***************************************************************");
        puts("                   1.   Add Grocery Items");
        puts("                   2. List All Grocery Items");
        puts("                   3.    Update Quantity");
        puts("                   4. Remove Grocery Item");
        puts("                   5.         Exit");
        puts("***************************************************************");
        printf("Please enter your choice: ");
        scanf(" %c", &choice);
        remove_whitespaces();

        switch (choice) {
            case '1':
                if (numGroceries < MAX_ITEMS) {
                    add(&groceryArray[numGroceries], &numGroceries);
                } else {
                    printf("Inventory is full. Cannot add more items.\n");
                }
                break;
            case '2':
                list(groceryArray, numGroceries);
                break;
            case '3':
                update(groceryArray, numGroceries);
                break;
            case '4':
                remove_item(groceryArray, &numGroceries);
                break;
            case '5':
                puts("Exiting...");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 to 5.\n");
        }
    }
}

//Function to add different groceries
void add(struct groceries *s, int *numGroceries) {
    printf("Enter Item Name: ");
    if (fgets(s->name, NAME, stdin) == NULL) {
        printf("Error reading name.\n");
        return;
    }
    s->name[strcspn(s->name, "\n")] = 0; 

    printf("Enter Category: ");
    if (fgets(s->category, CATEGORY, stdin) == NULL) {
        printf("Error reading category.\n");
        return;
    }
    s->category[strcspn(s->category, "\n")] = 0; 

    printf("Enter Quantity: ");
    if (scanf("%d", &s->quantity) != 1) {
        printf("Invalid input. Quantity set to 0.\n");
        s->quantity = 0;
        remove_whitespaces(); 
    }

    printf("Enter Price: ");
    if (scanf("%f", &s->price) != 1) {
        printf("Invalid input. Price set to 0.0.\n");
        s->price = 0.0;
        remove_whitespaces(); 
    }

    (*numGroceries)++;
    printf("Item added successfully!\n");
}

//Function to list out all groceries
void list(struct groceries *groceryArray, int numGroceries) {
    if (numGroceries == 0) {
        printf("No items found in inventory.\n");
        return;
    }

    for (int i = 0; i < numGroceries; i++) {
        printf("\n***Item %d***\n", i + 1);
        printf("Name: %s\n", groceryArray[i].name);
        printf("Category: %s\n", groceryArray[i].category);
        printf("Quantity: %d\n", groceryArray[i].quantity);
        printf("Price: %.2f\n", groceryArray[i].price);
    }
}

//Function to update quantity
void update(struct groceries *groceryArray, int numGroceries) {
    if (numGroceries == 0) {
        printf("No items to update. Inventory is empty.\n");
        return;
    }

    int index;
    printf("Enter the item number to update quantity (1 to %d): ", numGroceries);
    if (scanf("%d", &index) != 1 || index < 1 || index > numGroceries) {
        printf("Invalid item number.\n");
        getchar(); // Clear invalid input
        return;
    }

    index--; // Adjust to 0-based index

    printf("Enter new Quantity: ");
    if (scanf("%d", &groceryArray[index].quantity) != 1) {
        printf("Invalid input. Quantity not updated.\n");
        getchar(); // Clear invalid input
        return;
    }

    printf("Quantity updated successfully!\n");
}

//Function to remove item
void remove_item(struct groceries *groceryArray, int *numGroceries){
    if (*numGroceries == 0) {
        printf("No items to remove. Inventory is empty.\n");
        return;
    }

    int index;
    printf("Enter the item number to remove (1 to %d): ", *numGroceries);
    if (scanf("%d", &index) != 1 || index < 1 || index > *numGroceries) {
        printf("Invalid item number.\n");
        getchar(); // Clear invalid input
        return;
    }

    index--; // Adjust to 0-based index

    // Shift items to overwrite the removed item
    for (int i = index; i < *numGroceries - 1; i++) {
        groceryArray[i] = groceryArray[i + 1];
    }

    (*numGroceries)--;
    printf("Item removed successfully!\n");
}

//Function to remove whitespaces
void remove_whitespaces() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        continue;
    }
}
