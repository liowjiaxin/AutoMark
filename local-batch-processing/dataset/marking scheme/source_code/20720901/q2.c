#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[101];
  char category[51];
  int quantity;
  float price;
} Item;

typedef union
{
  int InStock;
  int OutOfStock;
} Availability;

typedef struct
{
  Item itemArr[100];
  Availability availArr[100];
  int count; // total number of grocery items[index]
} Inventory;

// function prototype
void printMenu();
void addGrocery(Inventory *inventoryItem);
void listAllItems(Inventory *inventoryItem);
void updateQuantity(Inventory *inventoryItem);
void removeGrocery(Inventory *inventoryItem);

void printMenu()
{
  printf("Grocery Inventory Management System\n");
  printf("1. Add Grocery Item\n");
  printf("2. List All Grocery Items\n");
  printf("3. Update Quantity\n");
  printf("4. Remove Grocery Item\n");
  printf("5. Exit\n");
}

void addGrocery(Inventory *inventoryItem)
{
  if (inventoryItem->count >= 100)
  {
    printf("Inventory full...");
    return;
  }

  char inputName[101];
  char inputCategory[51];
  int inputQuantity;
  float inputPrice;

  while (1)
  {
    printf("Enter Item Name: ");
    fgets(inputName, 101, stdin);
    inputName[strcspn(inputName, "\n")] = '\0';

    printf("Enter Category: ");
    fgets(inputCategory, 51, stdin);
    inputCategory[strcspn(inputCategory, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &inputQuantity);

    if (inputQuantity < 0)
    {
      printf("quantity cannot less than 0.\n");
      continue;
    }

    printf("Enter Price: ");
    scanf("%f", &inputPrice);

    if (inputPrice < 0)
    {
      printf("price cannot less than 0.\n");
      continue;
    }
    break;
  }

  Item newItem;
  strcpy(newItem.name, inputName);
  strcpy(newItem.category, inputCategory);
  newItem.quantity = inputQuantity;
  newItem.price = inputPrice;

  // check if quantity of product is more than 0
  if (inputQuantity > 0)
  {
    inventoryItem->availArr[inventoryItem->count].InStock = 1;
  }
  else
  {
    inventoryItem->availArr[inventoryItem->count].OutOfStock = 1;
  }

  // add item into array
  inventoryItem->itemArr[inventoryItem->count++] = newItem;

  printf("Grocery Item added successfully!\n\n");
}

void listAllItems(Inventory *inventoryItem)
{
  int index = inventoryItem->count;
  if (index == 0)
  {
    printf("No grocery items in the inventory.\n\n");
    return;
  }

  for (int i = 0; i < index; i++)
  {
    printf("Name: %s\n", inventoryItem->itemArr[i].name);
    printf("Category: %s\n", inventoryItem->itemArr[i].category);
    printf("Quantity: %d\n", inventoryItem->itemArr[i].quantity);
    printf("Price: %.2f\n", inventoryItem->itemArr[i].price);

    if (inventoryItem->itemArr[i].quantity > 0)
    {
      printf("Status: %s\n", inventoryItem->availArr[i].InStock == 1 ? "In Stock\n" : "Error\n");
    }
    else
    {
      printf("Status: %s\n", inventoryItem->availArr[i].OutOfStock == 1 ? "Out of Stock\n" : "Error\n");
    }
  }
}

void updateQuantity(Inventory *inventoryItem)
{
  // ask for input
  char inputName[101];
  printf("Enter name of the grocery item to update quantity: ");
  fgets(inputName, 101, stdin);
  inputName[strcspn(inputName, "\n")] = '\0';

  for (int i = 0; i < inventoryItem->count; i++)
  {
    // check if name and inputName is same or not
    if (strcmp(inventoryItem->itemArr[i].name, inputName) == 0)
    {
      int inputQuantity;
      printf("Enter new quantity for %s: ", inventoryItem->itemArr[i].name);
      scanf("%d", &inputQuantity);
      getchar();

      if (inputQuantity < 0)
      {
        printf("Quantity cannot less than 0.\n");
        return;
      }

      // check if quantity of product is more than 0
      if (inputQuantity > 0)
      {
        inventoryItem->availArr[i].InStock = 1;
      }
      else
      {
        inventoryItem->availArr[i].OutOfStock = 1;
      }
      inventoryItem->itemArr[i].quantity = inputQuantity;
      printf("Quantity updated successfully!\n");
      return;
    }
  }

  printf("No Item Found...\n");
}

void removeGrocery(Inventory *inventoryItem)
{
  // ask for input
  char inputName[101];
  printf("Enter name of the grocery item to remove: ");
  fgets(inputName, 101, stdin);
  inputName[strcspn(inputName, "\n")] = '\0';

  for (int i = 0; i < inventoryItem->count; i++)
  {
    // check if name and inputName is same or not
    if (strcmp(inventoryItem->itemArr[i].name, inputName) == 0)
    {
      // shift following items
      for (int j = i; j < inventoryItem->count; j++)
      {
        inventoryItem->itemArr[j] = inventoryItem->itemArr[j + 1];
        inventoryItem->availArr[j] = inventoryItem->availArr[j + 1];
      }
      inventoryItem->count--;
      printf("Grocery item '%s' removed successfully!\n", inputName);
      return;
    }
  }
  printf("No Item Found...\n");
}

int main()
{
  Inventory inventoryItem;
  // initialize total items to 0
  inventoryItem.count = 0;

  while (1)
  {
    printMenu();
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1: // add
      addGrocery(&inventoryItem);
      break;
    case 2: // list All
      listAllItems(&inventoryItem);
      break;
    case 3: // update quantity
      updateQuantity(&inventoryItem);
      break;
    case 4: // remove item
      removeGrocery(&inventoryItem);
      break;
    case 5: // exit
      printf("Exit...");
      exit(0);
      break;
    default:
      printf("Invalid Input...");
      break;
    }
  }

  return 0;
}