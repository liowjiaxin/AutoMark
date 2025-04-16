#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_CATE 50
#define MAX_ITEM 100

// struct for item
struct Item {
    char name[MAX_NAME];
    char cate[MAX_CATE];
    int quant;
    float price;
    bool inStock;
};

// Nested struct for item
struct Inven {
    struct Item items[MAX_ITEM];
    int totalNum;
};

// Function prototypes
void Trim(char *str);
size_t isPos(char *message);

// Main function
int main() {
    // Define and initialise variables & strings
    struct Inven Stock;
    Stock.totalNum = 0;
    char choiceC[10];
    int choice;
    char tempName[MAX_NAME];
    char updtName[MAX_NAME];
    char deleName[MAX_NAME];
    int run = 1;

    // Display menu
    printf("\nGrocery inventory management system");
    while (run != 0) {
        puts("\n1. Add grocery item\n2. List all grocery items\n3. Update quantity\n4. Remove item\n5. Exit");
        printf("Enter your choice: ");
        if (fgets(choiceC, sizeof(choiceC), stdin) != NULL) {
            Trim(choiceC);
            choice = atoi(choiceC);
        }
        
        // Use switch case
        switch (choice) {
            case 1:
                if (Stock.totalNum >= MAX_ITEM) { // If inventory is full, end
                    puts("\nInventory is full.");
                    break;
                }

                // Obtain item name
                printf("Enter item name: ");
                if (fgets(tempName, MAX_ITEM, stdin) != NULL) {
                    Trim(tempName);
                    int checkDupe2 = 0;
                    for (int i = 0; i < Stock.totalNum; i++) {
                        // Reject if item already exists
                        if (strcasecmp(Stock.items[i].name, tempName) == 0) {
                            printf("This product already exists. Please update it.\n");
                            checkDupe2 = 1;
                            break;
                        }
                    }
                    if (checkDupe2) {
                        break;
                    }

                    // If item did not exist, move from temporary variable to struct
                    struct Item *newItem = &Stock.items[Stock.totalNum];
                    strcpy(newItem->name, tempName);
                    
                    // Obtain category
                    printf("Enter category: ");
                    if (fgets(newItem->cate, MAX_CATE, stdin) != NULL) {
                        Trim(newItem->cate);
                    }
                    
                    // Obtain quantity, ensuring it is 0 or more
                    char buffer[10];
                    int pos = 1;
                    while (pos != 0) {
                        printf("Enter quantity: ");
                        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                            Trim(buffer);
                            size_t posCheck = isPos(buffer);
                            if (posCheck == 0) {
                                newItem->quant = atoi(buffer);
                                pos = 0;
                                break;
                            } else {
                                puts("Please enter zero or positive values.");
                                continue;
                            }
                        }
                    }

                    // Obtain price, ensuring it is 0 or more
                    pos = 1;                    
                    while (pos != 0) {
                        printf("Enter price: ");
                        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                            Trim(buffer);
                            size_t posCheck = isPos(buffer);
                            if (posCheck == 0) {
                                newItem->price = atof(buffer);
                                pos = 0;
                                break;
                            } else {
                                puts("Please enter zero or positive values.");
                                continue;
                            }
                        }
                    }

                    puts("Item added successfully!");
                    Stock.totalNum++; // Increment number of items in inventory
                }
                break;
            case 2:
                // Check if inventory is empty
                if (Stock.totalNum == 0) {
                    puts("\nInventory is empty.");
                } else {
                    char *inStock = "In stock";
                    char *noStock = "Out of stock";
                    char status[strlen(noStock)];
                    puts("\nInventory:");
                    for (int i = 0; i < Stock.totalNum; i++) {
                        // Check if items are in stock
                        if (Stock.items[i].quant == 0) {
                            Stock.items[i].inStock = false;
                        } else {
                            Stock.items[i].inStock = true;
                        }
                        if (Stock.items[i].inStock == true) {
                            strcpy(status, inStock);
                        } else {
                            strcpy(status, noStock);
                        }
                        printf("Item %d\nName: %s\nCategory: %s\nQuantity: %d\nPrice: %.2f\nStatus: %s\n", i + 1, Stock.items[i].name, Stock.items[i].cate, Stock.items[i].quant, Stock.items[i].price, status);
                    }
                }
                break;
            case 3:
                // Search for item
                printf("Enter name of item of which quantity to update: ");
                if (fgets(updtName, MAX_NAME, stdin) != NULL) {
                    Trim(updtName);
                }
                int found = 0;
                for (int i = 0; i < Stock.totalNum; i++) {
                    // Compare names insensitive to case
                    if (strcasecmp(Stock.items[i].name, updtName) == 0) {
                        found = 1;
                        char buffer[10];
                        int pos = 1;                    
                        while (pos != 0) {
                            printf("Enter new quantity: ");
                            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                                Trim(buffer);
                                size_t posCheck = isPos(buffer);
                                if (posCheck == 0) {
                                    Stock.items[i].quant = atoi(buffer);
                                    pos = 0;
                                    break;
                                } else {
                                    puts("Please enter zero or positive values.");
                                    continue;
                                }
                            }
                        }
                        puts("\nStock updated.");
                        break;
                    } 
                }
                if (!found) {
                    puts("Item not found.");
                }
                break;
            case 4:
                // Delete item
                printf("Enter name of item to delete: ");
                if (fgets(deleName, MAX_NAME, stdin) != NULL) {
                    Trim(deleName);
                }
                found = 0;
                for (int i = 0; i < Stock.totalNum; i++) {
                    if (strcasecmp(Stock.items[i].name, deleName) == 0) {
                        found = 1;
                        // Shift inventory to the left from j + 1 to j
                        for (int j = i; j < Stock.totalNum - 1; j++) {
                            Stock.items[j] = Stock.items[j + 1];
                        }
                        Stock.totalNum--; // Decrement stock number
                        puts("Item deleted successfully.");
                        break;
                    } 
                }
                if (!found) {
                    puts("Item not found.");
                }
                break;
            case 5:
                puts("\nExiting...");
                run = 0;
                break;
            default:
                puts("\nInvalid option.");
                break;
        }
        continue;
    }
}

// Trim function to remove newline character
void Trim(char *str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

// Function to ensure input is only positive number
size_t isPos(char *message) {
    while (*message != '\0') {
        if ((*message < '0' || *message > '9') && *message != '.') {
            return 1;
            break;
        }
        message++;
    }
    return 0;
}