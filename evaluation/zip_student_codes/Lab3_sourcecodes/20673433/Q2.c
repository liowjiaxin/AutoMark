#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 25

struct Part {
    int number;
    char name[NAME_LEN + 1];
    int quantity;
    float price;
    struct Part *next;
};

// Function prototypes
void add_part(struct Part **stock);
struct Part *find_part(struct Part *stock, int number);
void search_part(struct Part *stock);
void update_quantity(struct Part *stock);
void display_inventory(struct Part *stock);
void delete_part(struct Part **stock);
void clear_stock(struct Part *stock);
void clear_input_buffer();

int main() {
    struct Part *stock = NULL;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Grocery items \n");
        printf("2. Search for an items\n");
        printf("3. Update quantity\n");
        printf("4. Display items\n");
        printf("5. Delete an item\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_part(&stock);
                break;
            case 2:
                search_part(stock);
                break;
            case 3:
                update_quantity(stock);
                break;
            case 4:
                display_inventory(stock);
                break;
            case 5:
                delete_part(&stock);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free memory allocated for stock
    clear_stock(stock);

    return 0;
}

void add_part(struct Part **stock) {
    struct Part *new_part = (struct Part *)malloc(sizeof(struct Part));
    if (new_part == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter Grocery Number: ");
    if (scanf("%d", &new_part->number) != 1) {
        printf("Invalid input for grocery number. Please try again.\n");
        free(new_part);
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    // Check if part number already exists
    if (find_part(*stock, new_part->number) != NULL) {
        printf("Grocery Number already exists. Try again.\n");
        free(new_part);
        return;
    }

    printf("Enter grocery name: ");
    if (scanf("%s", new_part->name) != 1) {
        printf("Invalid input for grocery name. Please try again.\n");
        free(new_part);
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    printf("Enter initial quantity: ");
    if (scanf("%d", &new_part->quantity) != 1) {
        printf("Invalid input for quantity. Please try again.\n");
        free(new_part);
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    printf("Enter the price: ");
    if (scanf("%f", &new_part->price) != 1) {
        printf("Invalid input for price. Please try again.\n");
        free(new_part);
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    // Insert the new part into the linked list while maintaining sorted order
    struct Part *current = *stock;
    struct Part *previous = NULL;
    while (current != NULL && current->number < new_part->number) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        new_part->next = *stock;
        *stock = new_part;
    } else {
        previous->next = new_part;
        new_part->next = current;
    }

    printf("Items added successfully.\n");
}

struct Part *find_part(struct Part *stock, int number) {
    struct Part *current = stock;
    while (current != NULL && current->number != number) {
        current = current->next;
    }
    return current;
}

void search_part(struct Part *stock) {
    int number;
    printf("Enter grocery number to search: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input for grocery number. Please try again.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    struct Part *part = find_part(stock, number);
    if (part == NULL) {
        printf("Grocery not found.\n");
    } else {
        printf("Grocery Name: %s\n", part->name);
        printf("Quantity: %d\n", part->quantity);
        printf("Price: %.2f\n", part->price);
    }
}

void update_quantity(struct Part *stock) {
    int number;
    printf("Enter grocery number to update quantity: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input for grocery number. Please try again.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    struct Part *part = find_part(stock, number);
    if (part == NULL) {
        printf("Grocery not found.\n");
        return;
    }

    int quantity;
    printf("Enter new quantity: ");
    if (scanf("%d", &quantity) != 1) {
        printf("Invalid input for quantity. Please try again.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    part->quantity = quantity;
    printf("Quantity updated successfully.\n");
}

void display_inventory(struct Part *stock) {
    printf("\nInventory:\n");
    printf("Grocery Number\tGrocery Name\tQuantity\tPrice\n");
    printf("-------------------------------------------------------\n");

    struct Part *current = stock;
    while (current != NULL) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", current->number, current->name, current->quantity, current->price);
        current = current->next;
    }
}

void delete_part(struct Part **stock) {
    int number;
    printf("Enter grocery number to delete: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input for grocery number. Please try again.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    struct Part *current = *stock;
    struct Part *previous = NULL;

    while (current != NULL && current->number != number) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Grocery not found.\n");
        return;
    }

    if (previous == NULL) {
        *stock = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Grocery deleted successfully.\n");
}

void clear_stock(struct Part *stock) {
    struct Part *temp;
    while (stock != NULL) {
        temp = stock;
        stock = stock->next;
        free(temp);
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
