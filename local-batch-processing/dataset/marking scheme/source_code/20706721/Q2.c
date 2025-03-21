#include<stdio.h>
#include<string.h>



#define NAME_LEN 100//define the name max length
#define CATG_LEN 50//define the category max length
#define MAX_LIST_SIZE 100//max List number


int n = 0;//n current amount of people,t to gitemtrol while loop
//function declaretion
void menu();//main menu function
void add();//add data function
void list();//list data 
void update();//update data
void removeData();//remove date
// void quit();//quit system


//define data struct 
struct GroceryItem
{
    char name[NAME_LEN];
    char category[CATG_LEN];
    int  quantity;
    float price;
    int status;

}gitem[MAX_LIST_SIZE],tmp[MAX_LIST_SIZE];

int main()
{
    int t=1;
    // load();
    int num;//num is menu options
    while (t)//t is global variable
    {
       
        menu();//output mene
        printf("Please enter the menu number:");
        scanf("%d", &num);
        switch (num)
        {
        case 1: add(); break;
        case 2: list(); break;
        case 3: update(); break;
        case 4: removeData(); break;
        case 5: t=0; break;
        default:printf("Inputs the mistake,please input again!");
        }
        
    }
    
    return 0;
}


void menu()
{
    printf("\n\n");    
    printf("1.Add Grocery Item\n");
    printf("2.List All Grocey Items\n");
    printf("3.Update Quanltity\n");
    printf("4.Remove Grocery Item\n");
    printf("5.Exit\n");
}

/**
 * @brief 
 * Add data
 */

void add()
{
    int i = n, j, flag, m = 0;
    char str[NAME_LEN];
    //Enter Item Name
    printf("Enter Item Name :");
    getchar();
    fgets(str, sizeof(str), stdin);
    strncpy(gitem[i].name,str,strlen(str)-1);

    // Enter Category
    printf("Enter Category :");
    // getchar();
    fgets(str, sizeof(str), stdin);
    strncpy(gitem[i].category,str,strlen(str)-1);

    //enter quantity
    printf("Enter quantity :");
    scanf("%d", &gitem[i].quantity);

    // Enter price 
    printf("Enter price :");
    scanf("%f", &gitem[i].price);
    
    //Set the inventory status to true;
    if(gitem[i].quantity<=0){
        gitem[i].status=0;
    }
    else{ 
        gitem[i].status=1;
    }

    n=n+1;
    printf("Grocery item added successfully!");
    
}


/**
 * @brief 
 * display all data 
 */
void list(){

    int i=0;
    // If no data exists, return immediately
    if(n<=0){
        printf("No grocery items in the inventory.\n");
        return;
    }

    //Output data one by one
    for(i=0;i<n;i++){
        
        printf("-------------item: %d--------------\n",i);
        printf("Name: %s\n", gitem[i].name);
        printf("Category: %s\n", gitem[i].category);
        printf("Quantity: %d\n", gitem[i].quantity);
        printf("Price: %.2f\n", gitem[i].price);

        //Output the inventory status based on the value of 0 or 1
        if(gitem[i].status)
            printf("Status: %s\n", "In Stock");
        else
            printf("Status: %s\n", "Out of Stock");
        
    }
    printf("Amount %d\n",n);

}

void update(){

    char itemName[NAME_LEN],str[NAME_LEN];
    int newQuantity;
    printf("Enter name of the grocery item to update quantity:");        
    getchar();
    fgets(itemName, sizeof(itemName), stdin);

    // Remove newline character if present
    size_t len = strlen(itemName);
     if (len > 0 && itemName[len - 1] == '\n') {
        itemName[len - 1] = '\0';
    }
    printf("Enter new quantity for %s:",itemName);
    scanf("%d",&newQuantity);

    int i=0,findflag=0;
    //Match names one by one, and if found, update the quantity
    for(i=0;i<n;i++){
        if(strcmp(gitem[i].name,itemName)==0){
            gitem[i].quantity=newQuantity;
            if(newQuantity==0){
                gitem[i].status=0;
            }
            findflag=1;
            break;
        }
    }
    //If found, output "update successful"; otherwise, output "update failed"
    if(findflag)
        printf("Quantity updated successfully!");
    else
        printf("Couldn't find the name,Quantity updated failed!");
}

void removeData(){
    int j=0, flag=0;
    char s1[NAME_LEN];
    char sure[2];
   
    printf("Enter name of the grocery item to remove:");
    getchar();
    fgets(s1, sizeof(s1), stdin);

     // Remove newline character if present
     size_t len = strlen(s1);
     if (len > 0 && s1[len - 1] == '\n') {
        s1[len - 1] = '\0';
    }

    //find the data first
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(s1, gitem[i].name) == 0)
        {
            ++flag ;
            for (j = i; j < n - 1; j++)
            {
                gitem[j] = gitem[j + 1];//Move all the students behind forward one position
            }
            break;
        }
        // if (flag == 1) break;//find the name for delete ,end loop 
    }

    if (flag>0)
    {
        n=n-1;    
        printf("item \"%s\" removed successfully!!\n",s1);
        
    }

}