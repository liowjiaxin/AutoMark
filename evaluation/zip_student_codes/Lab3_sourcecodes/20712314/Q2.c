//Import libraries 
#include <stdio.h>
#include <ctype.h>
#include <string.h>



int i=0;                                                //Declaring global variable to for the indexing of struct variables(eg:if i is 5,it means there are 5 grocery items in the list,from index 0 till 4)

typedef struct Groceries                                //Creating struct for storing data
{
    char name[100];
    char category[50];
    int quantity;
    float price;
}groceries;

typedef union  Grocery_verification                     //Creating union for some verification and copying purposes later
{
    char Name[100];
}verification;

//Write up function prototypes
void Add(verification verify,groceries grocery[]);
void List(groceries grocery[]);
void Update(verification verify,groceries grocery[]);
void Remove(verification verify,groceries grocery[]);
int Availability();



int main(){

    //Initializing variables
    verification verify;
    groceries grocery[100];
    int choice=0;

    while(choice!=5){                                       //Repeating the pop up of the management system until the user chooses to exit
        printf("\nGrocery Inventory Management System");    //Menu
        printf("\n1.Add Grocery Item");
        printf("\n2.List All Grocery Items");
        printf("\n3.Update Quantity");
        printf("\n4.Remove Grocery Item");
        printf("\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);                                
        while (getchar() != '\n');                             //Clearing up buffer in case it stores the new line character
        switch(choice){
            case 1:
                Add(verify,grocery);                           //Entering the necessary parameters for the Add function
                break;
        
            case 2:
                List(grocery);                                  //Entering the necessary parameters for the list function
                break;

            case 3:
                Update(verify,grocery);                         //Entering the necessary parameters for the update function
                break;

            case 4:
                Remove(verify,grocery);                         //Entering the necessary parameters for the remove function
                break;

            case 5:
                printf("\nExiting...");                         
                return 0;

            default:
                printf("\nYou have not entered a valid choice");  //When user chooses some choice that's not listed
                break;   
        }
    }
    

    return 0;
}



void Add(verification verify,groceries grocery[]){
    int u=i;                                                //Declaring local variable for indexing in later steps of this function
    if(i<100){                                              //index 99 is the 100th item,hence i<100
        printf("\nEnter Item Name:");
        fgets(verify.Name,100,stdin);                       //Store user input in union variable so we can make verification later
        verify.Name[strcspn(verify.Name, "\n")] = '\0';     //Remove new line character and replace with NULL character
        for(int j=0;j<i;j++){                               //Loop until every existing struct variable has been looped through
            if(strcmp(grocery[j].name,verify.Name)==0){     //When the user's input is something that already exists in the grocery list,we just inform and stop the function there
                printf("\nItem is already in list!");
                return;                                       
            }
        }
    //Copying the user's input just now to the respective struct variable and getting new inputs for the item's related info,since the latest index is i-1,by making u=i,we can ensure that we're expanding the list
        strcpy(grocery[u].name,verify.Name);
        printf("\nEnter Category:");
        fgets(grocery[u].category,50,stdin);
        grocery[u].category[strcspn(grocery[u].category,"\n")]=0;
        printf("\nEnter Quantity:");
        scanf("%d",&grocery[i].quantity);
        while (getchar() != '\n');
        printf("\nEnter Price:");
        scanf("%f",&grocery[i].price);
        while (getchar() != '\n');
        printf("\nGrocery item added successfully!\n");
        i++;                                                            //When we add an item,the global variable should be updated so when we wanna access the struct later,we can use the newest index count 
        return;
    }
        else{
            printf("Item list has reached max capacity");           //Because the max capacity for grocery item entries is 100
            return;
        }
}

void List(groceries grocery[]){
    if(i==0){                                                   //When the global variable for indexing has the value of 0,it means there are no items in the list
        printf("No grocery items in the inventory.");
    }
        else{
            for(int z=0;z<i;z++){                               //Looping through every single variable from index 0 till the last one available so nothing is missed in the list
                printf("\nName:%s",grocery[z].name);
                printf("\nCategory:%s",grocery[z].category);
                printf("\nQuantity:%d",grocery[z].quantity);
                printf("\nPrice:$%.2f",grocery[z].price);
                Availability(grocery[z].name,grocery);          //Calling the availability function 
            }
        }
}

void Update(verification verify,groceries grocery[]){                   
    printf("\nEnter name of the grocery item to update quantity:");
    fgets(verify.Name,100,stdin);                                       //Receives user input
    verify.Name[strcspn(verify.Name, "\n")] = '\0';
    for(int y=0;y<i;y++){                                               //For loop to find the respective struct variable that matches the user's input
        if (strcmp(grocery[y].name,verify.Name)==0){                    //Only allow updating when there exists a string that matches the user's input
            printf("\nEnter new quantity for %s:",grocery[y].name);
            scanf("%d",&grocery[y].quantity);                           //Receiving input for updating then stroring it in the quantity variable of the match case(eg: if grocery2.name is a match,we'll change for grocery2.quantity)
            while (getchar() != '\n');
            printf("\nQuantity updated successfully!\n");
        }
            else{
                printf("\nNo such item in inventory\n");                //When there isn't an item on the list that matches the user's input
            }
    }
}

void Remove(verification verify,groceries grocery[]){
    printf("\nEnter name of the grocery item to remove:");
    fgets(verify.Name,100,stdin);                                               //Receiving user's input for items to remove
    verify.Name[strcspn(verify.Name, "\n")] = '\0';
    for(int w=0;w<i;w++){                                                       //For loop to find the struct name variable(grocery item) that matches the user's input
        if(strcmp(grocery[w].name,verify.Name)==0){
            for(int l=w;l<i-1;l++){
                grocery[l]=grocery[l+1];                                        //Assigning the values of the item to the one the match case,essentially removing the match case's value
            }
            i--;                                                                //The global variable for indexing the grocery list should decrease in size when one of it's items is removed
            printf("\nGrocery item %s removed successfully!\n",verify.Name);
        }
            else{
                printf("\nNo such item in inventory.\n");                       //When nothing in the list matches the user's input
            }
    }
}

int Availability(char target[],groceries grocery[]){        //Target is the item that we wish to check for it's availability
    for(int o=0;o<i;o++){                                   //Looping through the list to find the item that is to be checked for
        if (strcmp(grocery[o].name,target)==0){             //Case where we find the item in the list
            if(grocery[o].quantity<1){                      //When quantity<1,it means there's no stock or there's stock loss,both result in the out of stock status
                printf("\nOut of Stock\n");
                return 1;                                   //Stop function if we already generated a result
            }
                else {
                    printf("\nIn Stock\n");                 //When quantity>=1,it means we have stock
                    return 0;                               //Stop function if we already generated a result
                }
        }
    }
    printf("\nNo such item in inventory.\n");               //Not really necessary when this function is only called in this program when we already know the "target" variable is something existing in the list,but in case we need to use it for items that aren't next time,we put this else statement
    return 0;
}