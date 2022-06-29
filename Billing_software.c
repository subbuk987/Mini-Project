//This Project is made by Subramanyam (RA2111030010199)
//            Restaurant Billing Software
//This Program generates a bill and saves it in a file.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dishes{
    char item[20];
    int qty;
    float price;
};

struct orders{
    char customer[50];
    char date[30];
    int numOfItems;
    struct dishes dish[];
};

void RestaurantDetails(char name[50],char date[30]){
    printf("\n\n");
        printf("\t    SRM  RESTARUANT");
        printf("\n\t----------------------");
        printf("\nDate: %s",date);
        printf("\nInvoice To: %s",name);
        printf("\n");
        printf("--------------------------------------\n");
        printf("Items\t  ");
        printf("Qty\t  ");
        printf("Price\t  ");
        printf("\tTotal");
        printf("\n--------------------------------------\n");
        printf("\n\n");
}
void billDetails(char item[20],int qty,float price,float total){
    printf("%s\t  ",item);
    printf("%d\t  ",qty);
    printf("%.2f\t",price);
    printf("%.2f\t\t",total);
    printf("\n");
}

void billEnding(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal = total - dis;
    float cgst = 0.05*netTotal,grandTotal = netTotal + 2*cgst;
    printf("--------------------------------------\n");
    printf("Sub Total\t\t\t%.2f\n",total);
    printf("Discount @10%s \t\t\t-%.2f\n","%",dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f\n",netTotal);
    printf("CGST @5%s \t\t\t%.2f\n","%",cgst);
    printf("SGST @5%s \t\t\t%.2f\n","%",cgst);
    printf("---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f\n",grandTotal);
    printf("---------------------------------------\n");
    printf("\tThank You, Visit Again\n\n\n");
}
int main(){
    FILE *fptr;
    fptr = (FILE*)malloc(100000*sizeof(char));
    int option;
    struct orders ord;
    int n,i;
    float total = 0;
    char savebill;
   

    //Dashboard Creation 
    printf("\t=============SRM RESTAURANT============\n");
    printf("\n1.Generate Inovice\n");
    printf("2.Exit Menu\n");
    printf("\n");
    printf("Pleasen Select any option:\t");
    scanf("%d",&option);
    fgetc(stdin);
    switch(option){
        case 1:
        printf("\nEnter The Name of The Customer:\t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1]='\0';
        strcpy(ord.date,__DATE__);
        printf("\nEnter The Number of Items:\t");
        scanf("%d",&n);
        for(i=0;i<n;i++){
            fgetc(stdin);
            printf("\n");
            printf("Please Enter the item %d: \t\t",i+1);
            fgets(ord.dish[i].item,20,stdin);
            ord.dish[i].item[strlen(ord.dish[i].item)-1]='\0';
            printf("Please Enter the Quantity of Item:\t");
            scanf("%d",&ord.dish[i].qty);
            printf("Please Enter the Cost of Item:  \t");
            scanf("%f",&ord.dish[i].price);
            total += ord.dish[i].price*ord.dish[i].qty;
        }
        system("clear");
        RestaurantDetails(ord.customer,ord.date);
        for(i=0;i<n;i++){
            billDetails(ord.dish[i].item,ord.dish[i].qty,ord.dish[i].price,ord.dish[i].price*ord.dish[i].qty);
        } 
        billEnding(total);
        fptr = fopen("invoices.txt","a+");
            fprintf(fptr,"\n\n");
            fprintf(fptr,"\t    SRM  RESTARUANT");
            fprintf(fptr,"\n\t----------------------");
            fprintf(fptr,"\nDate: %s",ord.date);
            fprintf(fptr,"\nInvoice To: %s",ord.customer);
            fprintf(fptr,"\n");
            fprintf(fptr,"--------------------------------------\n");
            fprintf(fptr,"Items\t  ");
            fprintf(fptr,"Qty\t  ");
            fprintf(fptr,"Price\t  ");
            fprintf(fptr,"\tTotal");
            fprintf(fptr,"\n--------------------------------------\n");
            fprintf(fptr,"\n\n");
            for(i=0;i<n;i++){
                fprintf(fptr,"%s\t  ",ord.dish[i].item);
                fprintf(fptr,"%d\t     ",ord.dish[i].qty);
                fprintf(fptr,"%.2f\t    ",ord.dish[i].price);
                fprintf(fptr,"%.2f\t\t",total);
                fprintf(fptr,"\n");
            }
            fprintf(fptr,"\n--------------------------------------\n");
            float dis = 0.1*total;
            float netTotal = total - dis;
            float cgst = 0.05*netTotal,grandTotal = netTotal + 2*cgst;
            fprintf(fptr,"Sub Total\t\t\t        %.2f\n",total);
            fprintf(fptr,"Discount @10%s \t\t\t    -%.2f\n","%",dis);
            fprintf(fptr,"\t\t\t\t            -------");
            fprintf(fptr,"\nNet Total\t\t\t        %.2f\n",netTotal);
            fprintf(fptr,"CGST @5%s \t\t\t        %.2f\n","%",cgst);
            fprintf(fptr,"SGST @5%s \t\t\t        %.2f\n","%",cgst);
            fprintf(fptr,"---------------------------------------");
            fprintf(fptr,"\nGrand Total\t\t\t        %.2f\n",grandTotal);
            fprintf(fptr,"---------------------------------------\n");
            fprintf(fptr,"\tThank You, Visit Again\n\n\n");
            fclose(fptr);
        break;
        case 2:
        printf("\nThank You, Visit Again\n");
        break;
        default:
        printf("\nInvalid Option\n");
        break;
    }
    return 0;



}
