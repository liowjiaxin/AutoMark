#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_ITEMS 100
//struct definitions
struct GroceryItem {
	char name[MAX_NAME_LENGTH];
	char category[MAX_CATEGORY_LENGTH];
	int quantity;
	float price;
};

struct AvailabilityStatus {
	bool inStock;
	bool outOfStock;
};

struct GroceryItem groceryInventory[MAX_ITEMS];
struct AvailabilityStatus availability[MAX_ITEMS];
int itemCount = 0;
//addGroceryItem function
void addGroceryItem() {
	if(itemCount>=MAX_ITEMS) {
		printf("Inventory is full.Cannot add items.\n");
		return;//check if the inventory is full!
	}

	struct GroceryItem newItem;
	printf("Enter Item Name: ");
	fgets(newItem.name, MAX_NAME_LENGTH, stdin);
	strtok(newItem.name, "\n") ; //remove newline

	printf("Enter Category: ");
	fgets(newItem.category, MAX_CATEGORY_LENGTH, stdin);
	strtok(newItem.category,"\n") ;

	printf("Enter Quantity: ");
	scanf("%d", &newItem.quantity);
	printf("Enter Price: ");
	scanf("%f", &newItem.price);
	getchar();

	groceryInventory[itemCount] = newItem;
	availability[itemCount].inStock = newItem.quantity > 0;
	availability[itemCount].outOfStock = newItem.quantity == 0;

	itemCount++;
	printf("Grocery item added successfully!\n");
}
//listGroceryItems function
void listGroceryItems() {
	if (itemCount == 0) {
		printf("No grocery items in the inventory.\n");//check if there are some items in the inventory!
		return;
	}

	for (int i = 0; i < itemCount; i++) {
		printf("Name: %s\n", groceryInventory[i].name);
		printf("Category: %s\n", groceryInventory[i].category);
		printf("Quantity: %d\n", groceryInventory[i].quantity);
		printf("Price: %.2f\n", groceryInventory[i].price);
		printf("Status: %s\n", availability[i].inStock ? "In Stock" : "Out of Stock");
		printf("-------------------------------\n");
	}
}
//updateQuantity function
void updateQuantity() {
	if (itemCount == 0) {
		printf("No grocery items in the inventory.\n");
		return;
	}

	char itemName[MAX_NAME_LENGTH];
	printf("Enter name of the grocery item to update quantity: ");
	fgets(itemName, MAX_NAME_LENGTH, stdin);
	strtok(itemName,"\n");

	int itemIndex = -1;
	for (int i = 0; i < itemCount; i++) {
		if (strcmp(groceryInventory[i].name, itemName) == 0) {
			itemIndex = i;
			break;
		}
	}

	if (itemIndex == -1) {
		printf("Item '%s' not found in the inventory.\n", itemName);//check if the items exists
		return;
	}
	int newQuantity;
	printf("Enter new quantity for %s: ", itemName);
	scanf("%d", &newQuantity);
	getchar();

	groceryInventory[itemIndex].quantity = newQuantity;
	availability[itemIndex].inStock = newQuantity > 0;//if the quantity is more than one ,that means it's instock
	availability[itemIndex].outOfStock = newQuantity == 0;//if the quantity is one ,that means it's out of stock

	printf("Quantity updated successfully!\n");
}
//removeGroceryItem function
void removeGroceryItem() {
	if (itemCount == 0) {
		printf("No grocery items in the inventory.\n");
		return;
	}

	char itemName[MAX_NAME_LENGTH];
	printf("Enter name of the grocery item to remove: ");
	fgets(itemName, MAX_NAME_LENGTH, stdin);
	strtok(itemName,"\n");

	int itemIndex = -1;
	for (int i = 0; i < itemCount; i++) {
		if (strcmp(groceryInventory[i].name, itemName) == 0) {//compare name with groceryInventory
			itemIndex = i;
			break;
		}
	}

	if (itemIndex == -1) {
		printf("Item '%s' not found in the inventory.\n", itemName);
		return;
	}

	for (int i = itemIndex; i < itemCount - 1; i++) {
		groceryInventory[i] = groceryInventory[i + 1];
		availability[i] = availability[i + 1];
	}

	itemCount--;
	printf("Grocery item '%s' removed successfully!\n", itemName);
}

//main program loop
int main() {
	int choice;

	do {
		printf("\nGrocery Inventory Management System\n");
		printf("1. Add Grocery Item\n");
		printf("2. List All Grocery Items\n");
		printf("3. Update Quantity\n");
		printf("4. Remove Grocery Item\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar();

		switch(choice) {
		case 1:
			addGroceryItem();
			break;
		case 2:
			listGroceryItems();
			break;
		case 3:
			updateQuantity();
			break;
		case 4:
			removeGroceryItem();
			break;
		case 5:
			printf("Exiting!\n");
			break;
		default:
			printf("Invalid choice!Please try again.\n");
		}
	} while(choice!=5);
	return 0;
}



