#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#define NAME_MAX_LEN 100
#define CATEGORY_MAX_LEN 50
#define GROCERY_MAX_LEN 100

typedef struct s_grocery {
	char name[NAME_MAX_LEN + 1];
	char category[CATEGORY_MAX_LEN + 1];
	int quantity;
	float price;
}	t_grocery;

typedef bool t_in_stock;

typedef struct s_inventory {
	t_grocery groceries[GROCERY_MAX_LEN];
	t_in_stock availability[GROCERY_MAX_LEN];
	size_t items_count;
}	t_inventory;

static int get_int(int *input, const char *format, ...) {
	va_list args;

    // print the formatted string
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    if (scanf("%d", input) == EOF) {
		return EOF;	
	}

	fflush(stdin);
	return 0;
}

static void print_menu(void) {
	puts("Grocery Inventory Management System");
	puts("1. Add Grocery Item");
	puts("2. List All Grocery Items");
	puts("3. Update Quantity");
	puts("4. Remove Grocery Item");
	puts("5. Exit");
}

static void add_grocery_item(t_inventory *inventory) {
	if (inventory->items_count >= 100) {
		fprintf(stderr, "Inventory full.\n");
		return;
	}

	t_grocery *current_empty_item = &(inventory->groceries[inventory->items_count]);

	// get grocery item name
	printf("Enter Item Name: ");
	if (scanf(" %100[^\n]", current_empty_item->name) == EOF) {
		return;
	}

	// get grocery item category
	printf("Enter Category: ");
	if (scanf(" %50[^\n]", current_empty_item->category) == EOF) {
		return;
	}

	// get grocery item quantity
	if (get_int(&(current_empty_item->quantity), "Enter Quantity: ") == EOF) {
		return;
	}
	if (current_empty_item->quantity < 0) {
		fprintf(stderr, "Quantity shouldn't be less than 0.\n");
		return;
	}

	// get grocery item price
	printf("Enter Price: ");
	if (scanf(" %f", &(current_empty_item->price)) == EOF) {
		return;
	}
	if (current_empty_item->price < 0) {
		fprintf(stderr, "Price shouldn't be less than 0.\n");
		return;
	}

	// update availability and increment items_count
	inventory->availability[inventory->items_count] = current_empty_item->quantity > 0;
	inventory->items_count++;

	puts("Grocery item added successfully!");
	printf("\n");
}

static void list_grocery_items(t_inventory *inventory) {
	if (inventory->items_count == 0) {
		puts("No grocery items in inventory.");
		return;
	}

	for (size_t i = 0; i < inventory->items_count; ++i) {
		t_grocery *current_item = &(inventory->groceries[i]);
		printf("Name: %s\n", current_item->name);
		printf("Category: %s\n", current_item->category);
		printf("Quantity: %d\n", current_item->quantity);
		printf("Price: %.2f\n", current_item->price);
		printf("Status: %s\n", inventory->availability[i] ? "In Stock" : "Out of Stock");
		printf("\n");
	}
	printf("\n");
}

static void update_quantity(t_inventory *inventory) {
	char name[NAME_MAX_LEN + 1];
	printf("Enter the name of the grocery item to update quantity: ");
	if (scanf(" %100[^\n]", name) == EOF) {
		return;
	}

	for (size_t i = 0; i < inventory->items_count; ++i) {
		t_grocery *current_item = &(inventory->groceries[i]);
		if (strcmp(current_item->name, name) == 0) {
			int new_quantity = 0;
			if (get_int(&new_quantity, "Enter new quantity for %s: ", name) == EOF) {
				return;
			}
			if (new_quantity < 0) {
				fprintf(stderr, "Quantity shouldn't be less than 0.\n");
				return;
			}

			// update quantity
			current_item->quantity = new_quantity;
			inventory->availability[i] = new_quantity > 0;
			puts("Quantity updated successfully!");
			printf("\n");
			return;
		}
	}

	fprintf(stderr, "Item not found.\n");
	printf("\n");
}

static void remove_grocery_item(t_inventory *inventory) {
	char name[NAME_MAX_LEN + 1];
	printf("Enter the name of the grocery item to remove: ");
	if (scanf(" %100[^\n]", name) == EOF) {
		return;
	}

	for (size_t i = 0; i < inventory->items_count; ++i) {
		t_grocery *current_item = &(inventory->groceries[i]);
		if (strcmp(current_item->name, name) == 0) {
			for (size_t j = i; j < inventory->items_count - 1; ++j) {
				// shift the items on the right of the current item to the left by 1 position
				inventory->groceries[j] = inventory->groceries[j + 1];
				inventory->availability[j] = inventory->availability[j + 1];
			}
			inventory->items_count--;
			puts("Item removed successfully!");
			printf("\n");
			return;
		}
	}

	fprintf(stderr, "Item not found.\n");
	printf("\n");
}

static void loop_do_op(t_inventory *inventory) {
	int choice = 0;
	while (true) {
		print_menu();

		// scanf for choice
		if (get_int(&choice, "Enter your choice: ") == EOF) {
			return;
		}

		// do op, or exit
		switch (choice) {
			case 1:
				add_grocery_item(inventory);
				break;
			case 2:
				list_grocery_items(inventory);
				break;
			case 3:
				update_quantity(inventory);
				break;
			case 4:
				remove_grocery_item(inventory);
				break;
			case 5:
				puts("Exiting...");
				return;
			default:
				printf("Invalid choice.\n\n");
		}
	}
}

int main(void) {
	t_inventory *inventory = malloc(sizeof(t_inventory));
	if (inventory == NULL) {
		fprintf(stderr, "malloc error.\n");
		return 1;
	}

	inventory->items_count = 0;

	loop_do_op(inventory);
	free(inventory);
	return 0;
}