#include <stdio.h>

int main() {
    // Initialize product info variables
    int amount = 0;
    float weight = 0.0, price = 0.0, discount = 0.0, cost = 0.0;

    // Program loop with exit flag
    int exit = 0;
    int choice = 0;
    while (1) {
        // Initialize valid input flag
        int valid = 1;

        // Print menu and prompt for user choice
        printf("List of Product Codes\n"
               "Fruit: 1\n"
               "Vegetable: 2\n"
               "Dairy Product: 3\n"
               "Canned Goods: 4\n"
               "Enter product code (0 to exit): ");
        scanf("%d", &choice);

        // Product switch cases (by weight/per item)
        switch (choice) {
            case 0: // Exit
                exit = 1;
                puts("Have a nice day!");
                break;
            case 1: // Fruits
                // Prompt for weight
                printf("Enter weight of fruit (kg): ");
                scanf("%f", &weight);

                // Prompt for price per kg
                printf("Enter price per kg of fruit ($): ");
                scanf("%f", &price);

                // Calculate cost
                cost = weight * price;

                break;
            case 2: // Vegetables
                // Prompt for weight
                printf("Enter weight of vegetable (kg): ");
                scanf("%f", &weight);

                // Prompt for price per kg
                printf("Enter price per kg of vegetable ($): ");
                scanf("%f", &price);

                // Calculate cost
                cost = weight * price;

                break;
            case 3: // Dairy Products
                // Prompt for amount
                printf("Enter amount of dairy products: ");
                scanf("%d", &amount);
                
                // Prompt for price per item
                printf("Enter price per item of dairy product ($): ");
                scanf("%f", &price);

                // Calculate Cost
                cost = amount * price;

                break;
            case 4: // Canned Good
                // Prompt for amount
                printf("Enter amount of canned goods: ");
                scanf("%d", &amount);
                
                // Prompt for price per item
                printf("Enter price per item of canned good ($): ");
                scanf("%f", &price);

                // Calculate Cost
                cost = amount * price;

                break;
            default: // Invalid input
                puts("Invalid choice\n");
                valid = 0;
                break;
        }

        // Handle exit of program
        if (exit) {
            break;
        }

        // Check for valid input
        if (valid) {
            // Prompt for discount
            printf("Enter discount amount (0 for no discount): ");
            scanf("%f", &discount);

            // Display total cost
            printf("Total cost: $%.2f\n", cost);

            // Calculate and display final cost with discount
            cost = cost * (1-discount/100);
            printf("Final cost with discount: $%.2f\n", cost);
            puts("");
        }
    }

    return 0;
}