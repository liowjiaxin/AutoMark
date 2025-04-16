#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Char_Name_Size 100
#define Char_Category_Size 50

int option, i = 0;

struct grocery {
    char Name[Char_Name_Size];
    char Category[Char_Category_Size];
    int Quantity;
    float Price;
    bool InStock;
};

struct grocery Grocery_Item[100];

void Add_Grocery();
void List_All_Grocery();
void Update_Quantity();
void Remove_Grocery();
void Update_Stock_Status(struct grocery *item);

int main() {
    while (1) {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar(); // Clear newline from input buffer

        switch (option) {
            case 1:
                Add_Grocery();
                break;
            case 2:
                List_All_Grocery();
                break;
            case 3:
                Update_Quantity();
                break;
            case 4:
                Remove_Grocery();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Option. Please try again.\n");
        }
    }
    return 0;
}

void Add_Grocery() {
    printf("Enter Item Name: ");
    fgets(Grocery_Item[i].Name, Char_Name_Size, stdin);
    Grocery_Item[i].Name[strcspn(Grocery_Item[i].Name, "\n")] = '\0'; // Remove newline

    printf("Enter Category: ");
    fgets(Grocery_Item[i].Category, Char_Category_Size, stdin);
    Grocery_Item[i].Category[strcspn(Grocery_Item[i].Category, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &Grocery_Item[i].Quantity);
    getchar();

    printf("Enter Price: ");
    scanf("%f", &Grocery_Item[i].Price);
    getchar();

    Update_Stock_Status(&Grocery_Item[i]);

    i++;
    printf("Grocery item added successfully!\n");
}

void List_All_Grocery() {
    if (i == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int j = 0; j < i; ++j) {
        printf("\nName: %s\n", Grocery_Item[j].Name);
        printf("Category: %s\n", Grocery_Item[j].Category);
        printf("Quantity: %d\n", Grocery_Item[j].Quantity);
        printf("Price: %.2f\n", Grocery_Item[j].Price);
        printf("Status: %s\n", Grocery_Item[j].InStock ? "In Stock" : "Out of Stock");
    }
}

void Update_Quantity() {
    char Update_Item[Char_Name_Size];
    printf("Enter the name of the grocery item to update the quantity: ");
    fgets(Update_Item, Char_Name_Size, stdin);
    Update_Item[strcspn(Update_Item, "\n")] = '\0'; // Remove newline

    for (int j = 0; j < i; ++j) {
        if (strcmp(Update_Item, Grocery_Item[j].Name) == 0) {
            printf("Enter new quantity for %s: ", Grocery_Item[j].Name);
            scanf("%d", &Grocery_Item[j].Quantity);
            getchar();

            Update_Stock_Status(&Grocery_Item[j]);

            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Grocery item '%s' not found.\n", Update_Item);
}

void Remove_Grocery() {
    char Remove_Item[Char_Name_Size];
    printf("Enter name of the grocery item to remove: ");
    fgets(Remove_Item, Char_Name_Size, stdin);
    Remove_Item[strcspn(Remove_Item, "\n")] = '\0'; // Remove newline

    for (int j = 0; j < i; ++j) {
        if (strcmp(Grocery_Item[j].Name, Remove_Item) == 0) {
            for (int k = j; k < i - 1; ++k) {
                Grocery_Item[k] = Grocery_Item[k + 1];
            }
            i--;
            printf("Grocery item '%s' removed successfully!\n", Remove_Item);
            return;
        }
    }
    printf("Grocery item '%s' not found.\n", Remove_Item);
}

void Update_Stock_Status(struct grocery *item) {
    item->InStock = (item->Quantity > 0);
}