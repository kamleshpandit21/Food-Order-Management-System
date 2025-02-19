#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//------------structure to save food items in menu---------//
 typedef struct menu 
{
    char dish_name[50];
     int dish_price;
}foodItem;
foodItem f1;
// ---------------structure to maintain details of user and admin------------//
typedef struct 
{
   int id;
   char name[50];
   int password;
   long int phone_number;

}membar;
membar m1;


//----------------------- function prototyps -------------------//
void order();
void add_menu();
void show_menu();
void user_mode();
void admin_mode();
void remove_menu();
void add_admin_member();
void user_registration();
void user_authentication();
void admin_authentication();
 void registerd_person();

int main()
{
    int n;
    do{
    printf("\n-------------- Choose Your Option ------------------\n");    
    printf("Enter 1 For Admin  \n");
    printf("Enter 2 For User  \n");
    printf("Enter 3 For EXit \n");
    printf("Enter Your Choice Here :- ");
    scanf("%d",&n);                                                    
    printf("----------------------------------------------------\n");
    switch (n)
    {
    case 1:
     {  
         admin_mode();
        break;
    }
    case 2:
    {
        user_mode();
        break;
    }

    default:
        break;
    }
    }while (n!=3);
    
    return 0;
}

//-----------------------function for user mode -----------------------------//
void user_mode()
{
 int a;
  do{
    printf("\n-------------- WELCOME TO USER ZONE ------------------\n");    
    printf("Enter 1 For User Login \n");
    printf("Enter 2 For User Registration\n");
    printf("Enter 3 For EXit \n");
    printf("Enter Your Choice Here :- ");
    scanf("%d",&a);                                                    
    printf("-------------------------------------------------------\n");
    switch (a)
    {
    case 1:
    {
        user_authentication();
        break;
    }
    case 2:
    {
         user_registration(m1);
         break;
    }   
    default:
        break;
    }
  }while(a != 3);
}
//--------------function definition for user registration--------------------//
void user_registration(membar m1)
{
printf("\n----------------- User Registration -----------------\n");
printf("Enter Your Id              :- ");   
scanf("%d",&m1.id);
printf("Enter Your Name            :- ");
scanf("%s",&m1.name);
printf("Enter Four Digit Password  :- ");
scanf("%d",&m1.password);
printf("Enter Your Phone number    :- ");
scanf("%ld",&m1.phone_number);
printf("----------------------------------------------------\n");
FILE *ptr;
ptr=fopen("users.txt","a");
if(ptr==NULL){
    printf("Error In Opening File");
}
else
{
fwrite(&m1,sizeof(membar),1,ptr);
}
fclose(ptr);
}

//-----------------------function definition of user authentication-----------------//
 void user_authentication()
{
char name[50]; 
int password,n,id,flag=0;
printf("\n-------------------- User Login ---------------------\n");
printf("Enter Your Id              :- ");   
scanf("%d",&id);
printf("Enter Your Name            :- ");
scanf("%s",&name);
printf("Enter Four Digit Password  :- ");
scanf("%d",&password);                                       
printf("----------------------------------------------------\n");
FILE *ptr;
ptr=fopen("users.txt","r+");
if(ptr==NULL)
{
    printf("Error in Operning File");
}
else
{
     while(fread(&m1,sizeof(membar),1,ptr)==1){
    if(m1.id ==id && m1.password ==password && strcmp(m1.name,name)==0){
     flag=1;
    }
     }
}
fclose(ptr);
if(flag==1)
{    
do{
printf("Enter 1 For Menu\n");
printf("Enter 2 For Order\n");
printf("Enter 3 For EXit\n");
printf("Enter Your Choice Here :- ");
scanf("%d",&n);
switch (n)
{
case 1:
{
    show_menu();
    break;
}
case 2:
{
 order();
}

default:
    break;
}
}while(n !=3);

}
else{
    printf("\n User Not Registerd \n");
}

}
//-------------function definition for order--------------------//
void order()
{
    int choice, quantity;
    float total = 0;
    FILE *ptr;
    ptr = fopen("food_menu.txt", "r");
    if (ptr == NULL)
    {
        printf("Error In Opening File\n");
    }
    else
    {
        printf("\n----------------- Food Items In Our Menu ------------------\n");
        int i = 1;
        while (fread(&f1, sizeof(foodItem), 1, ptr) == 1)
        {
            printf("%d. %s            : -      %d Rs\n", i, f1.dish_name, f1.dish_price);
            i++;
        }
        printf("\n----------------------------------------------------------\n");
        printf("Enter the number of the dish you want to order: ");
        scanf("%d", &choice);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        rewind(ptr);
        int j = 1;
        while (fread(&f1, sizeof(foodItem), 1, ptr) == 1)
        {
            if (j == choice)
            {
                total += f1.dish_price * quantity;
                printf("You have ordered %s x %d = %f Rs\n", f1.dish_name, quantity, total);
                break;
            }
            j++;
        }
    }
    fclose(ptr);
}

//-------------------------fuction for admin mode-----------------------------//
void admin_mode()
{
int n;
   do{
    printf("\n-------------- WELCOME TO ADMIN ZONE ------------------\n");    
    printf("Enter 1 For Admin Login \n");
    printf("Enter 2 For Add Admin Member\n");
    printf("Enter 3 For EXit \n");
    printf("Enter Your Choice Here :- ");
    scanf("%d",&n);                                                    
    printf("\n-------------------------------------------------------\n");
     switch (n)
    {
    case 1:
     {  
      admin_authentication();
        break;
    }
    case 2:
    {
       add_admin_member(m1);
        break;
    }
   
    default:
        break;
    }
    }while (n!=3);
}
//-------------function declration for adding admin member----------------//
 void add_admin_member(membar m1)
{
printf("Enter Your Id              :- ");   
scanf("%d",&m1.id);
printf("Enter Your Name            :- ");
scanf("%s",&m1.name);
printf("Enter Four Digit Password  :- ");
scanf("%d",&m1.password);
printf("Enter Your Phone number    :- ");
scanf("%ld",&m1.phone_number);
FILE *ptr;
ptr=fopen("admin_membar.txt","a+");
if(ptr==NULL)
{
    printf("Error in Operning File");
}
else
{
     fwrite(&m1,sizeof(membar),1,ptr);
}

fclose(ptr);

}
//--------------------function for admin authentication----------------//
 void admin_authentication()
 {
 char name[50]; 
 int password,id,n,flag=0;
printf("\n-------------------- Admin Login -------------------\n");
printf("Enter Your Id              :- ");   
scanf("%d",&id);
printf("Enter Your Name            :- ");
scanf("%s",&name);
printf("Enter Four Digit Password  :- ");
scanf("%d",&password);                                       //
printf("\n----------------------------------------------------\n");
FILE *ptr;
ptr=fopen("admin_membar.txt","r+");
if(ptr==NULL)
{
    printf("Error in Operning File");
}
else
{
 while(fread(&m1,sizeof(membar),1,ptr)==1)
{
 if(m1.id ==id && m1.password ==password && strcmp(m1.name,name)==0)
{
 flag=1;
}
}
}
fclose(ptr);
if(flag==1){
    do
    {
    printf("\n-------------------- Admin Controls ------------------\n");
    printf("Enter 1 To ADD Dish in Menu\n");
    printf("Enter 2 To REMOVE Dish From Menu\n");
    printf("Enter 3 To See Menu\n");
    printf("Enter 4 To See All registed User\n");
    printf("Enter 5 To See All Registerd Staff\n");
    printf("Enter 6 To Exit\n");
    printf("Enter Your Choice Here :- ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
     {
        Add_menu();
        break;
     }
    case 2:
    {
       remove_menu();
        break;
    }
    case 3: 
    {
        show_menu();
    }
    case 4:
    {
       registerd_person(n);
    }
    case 5:
    {
      registerd_person(n);
    }
    default:
        break;
    }
    }while(n!=6);
}
else{
    printf("\n You Are Not A Staff Membar\n");
}
 }
 //----------function declaration for see all registed user & and Staff----------//
 void registerd_person( int a){
FILE *ptr;
if(a==4)
{
ptr=fopen("users.txt","r");
printf("\n------------------ All Registerd User -------------------\n");
}
if(a==5){
    
ptr=fopen("admin_membar.txt","r");
printf("\n------------------ All Registerd Staff -------------------\n");
}
if(ptr==NULL)
{
    printf("Error in Operning File");
}
else
{
 while(fread(&m1,sizeof(membar),1,ptr)==1)
 {                                                            
printf("\n----------------------------------------------------\n");
  printf("Id             :  %d\n",m1.id);
  printf("Name           :  %s\n",m1.name);
  printf("Phone Number   :  %lld\n",m1.phone_number);
printf("----------------------------------------------------\n");
 }

}
fclose(ptr);
}
//-------------------------------- function for  Add_menu -----------------------//
void Add_menu()
{
   
    printf("\n---------------- ADD Dish IN Menu ----------------\n");
    char foodname[50];
    while (getchar() != '\n');
        printf("Enter Dish Name: ");
    fgets(foodname, sizeof(foodname), stdin);
    foodname[strcspn(foodname, "\n")] = 0;
    strcpy(f1.dish_name, foodname);
    printf("Enter The Price: ");
    scanf("%d", &f1.dish_price);
    
    FILE *ptr;
    ptr = fopen("food_menu.txt", "a+");
    if(ptr == NULL)
    {
        printf("Error In Opening The File\n");
    }
    else
    {
        fwrite(&f1, sizeof(foodItem), 1, ptr);
    }
    fclose(ptr);
}
//------------------------------function for Remove_menu---------------------//
void remove_menu(){
    char dishaname[50];
printf("\n---------------- Remove Dish IN Menu ----------------\n");
printf("Enter Dish Name -: ");
scanf("%s",&dishaname);
FILE *orignal;
FILE *temp;
orignal=fopen("food_menu.txt","r");
temp=fopen("temp_menu.txt","a+");
if(orignal==NULL && temp ==NULL){
  printf("Error In Opening Menu File\n");
}
else
{
while(fread(&f1,sizeof(foodItem),1,orignal)==1)
{
    if(strcmp(f1.dish_name,dishaname)!=1)
    {
        fwrite(&f1,sizeof(foodItem),1,temp);
    }
}
}
fclose(orignal);
fclose(temp);
remove("food_menu.txt");
rename("temp_menu.txt","food_menu.txt");

}
//-----------------------------function for show menu-----------------//
void show_menu()
{
    int i = 1;
    FILE *ptr;
    ptr = fopen("food_menu.txt", "r");
    if (ptr == NULL)
    {
        printf("Error In Opening File\n");
    }
    else
    {
        printf("\n----------------- Food Items In Our Menu ------------------\n");
        while (fread(&f1, sizeof(foodItem), 1, ptr) == 1)
        {
            printf("%d. %s            : -      %d Rs\n", i, f1.dish_name, f1.dish_price);
            i++;
        }
        printf("\n----------------------------------------------------------\n");
    }
    fclose(ptr);
}