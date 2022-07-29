#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct Product
{
        int P_Id;
        char Name[20];
        float Sales_Price;
        float Purchase_Price;
        int Stock;
};



void add()
{

    system("cls");
    FILE *fp,*ft;
    fp=fopen("abc.txt","rb+");
    ft=fopen("teabc.txt","ab+");
    int flag=0 ,id ;
    printf("Enter the id :");
    scanf("%d",&id);
    struct Product a;
    while(fread(&a , sizeof(a),1,fp)==1)
    {
        if(id==a.P_Id)
        {
             int New_Stock = 0;

            printf("\n--------------------------------------------\n");
            printf("\n Product Details are => \n ID = %d. \n Name = %s. \n Available Stock = %d\n", a.P_Id,a.Name,a.Stock);
            printf("\n--------------------------------------------\n");

            printf("\n Enter Number Of Stock To Add : ");
            scanf("%d",&New_Stock);

            a.Stock += New_Stock;


        }
        fwrite(&a ,sizeof(a),1,ft);
    }

    fclose(fp);
    fclose(ft);
    remove("abc.txt");
    rename("teabc.txt","abc.txt");
    printf("\n\n\tthe record is added sucessfully..... ");
    printf("\n\n\n\t\tPress any key to continue.........");
    getch();
}

void Add_New_Product()
{
            system("cls");
             printf("\n\n Accepting Product Details => \n");
            struct Product a;
            FILE *fp ;
            fp=fopen("abc.txt","ab+");
            if(fp==NULL)
            {
                printf("File cant open....");
            }
            fflush(stdin);
            printf("\n Enter  Product Name = ");
            scanf("%s",&a.Name);
            fflush(stdin);
            printf("\n Enter  Product Id = ");
            scanf("%d",&a.P_Id);

            printf("\n Enter  Product Sales Price = ");
            scanf("%f",&a.Sales_Price);

            printf("\n Enter Product Purchase Price = ");
            scanf("%f",&a.Purchase_Price);
            a.Stock=0 ;
            fwrite(&a , sizeof(a) , 1, fp);
            fclose(fp);
            printf("Record added sucessfully......");
            getch();
            return;
}

void Update_Product()
{
    system("cls");
    FILE *fp,*ft;
    fp=fopen("abc.txt","rb+");
    ft=fopen("teabc.txt","ab+");
    int flag=0 ,id ;
    printf("Enter the id :");
    scanf("%d",&id);
    struct Product a;
    while(fread(&a , sizeof(a),1,fp)==1)
    {
        if(id==a.P_Id)
        {


            flag==1;
              system("cls");
                        int Choice = 0 ;
                            printf("\n-------------------------------------\n");
                            printf("\n Product Details are => \n ID = %d. \n Name = %s. \n Sales Price = %0.2f. \n Purchase Price = %0.2f.\n Stock = %d. \n", a.P_Id,a.Name,a.Sales_Price,a.Purchase_Price,a.Stock);
                            printf("\n-------------------------------------\n");

                            printf("\n Select Choice =>\n\t\t 1. Update Product Name \n\t\t 2. Update Purchase Price \n\t\t 3. Update Selling Price \n\t\t 4. Update Stock  \n\t\t 5. Back");

                            printf("\n\n==========================================\n");

                            printf("\n Enter Your Choice : ");
                            scanf("%d", &Choice);

                            if(Choice==1)
                            {

                                            fflush(stdin);
                                            printf("\n Old Product Name = %s\n",a.Name);
                                            printf(" New Product Name : ");
                                            scanf("%s",a.Name);
                                            fflush(stdin);
                                            printf("\n Updated Successfully, Press Any Key To Continue !\n");
                                            getch();
                            }else if(Choice==2)
                            {




                                            printf("\n Old Purchase Price = %f\n",a.Purchase_Price);
                                            printf(" New Purchase Price : ");
                                            scanf("%f",&a.Purchase_Price);

                                            printf("\n Updated Successfully, Press Any Key To Continue !\n");
                                            getch();
                            }
                            else if(Choice==3){

                                              printf("\n Old Selling Price = %f\n",a.Sales_Price);
                                            printf(" New Selling Price : ");
                                            scanf("%f",&a.Sales_Price);

                                            printf("\n Updated Successfully, Press Any Key To Continue !\n");
                                            getch();


                            }
                            else if(Choice==4)
                            {


                                            printf("\n Old Stock = %d\n",a.Stock);
                                            printf(" New Stock : ");
                                            scanf("%d",&a.Stock);

                                            printf("\n Updated Successfully, Press Any Key To Continue !\n");
                                            getch();


                            }


                            else{
                                            printf("\n Invalid Choice Please Select a Valid Choice");
                                            getch();
                            }
                }

                        system("cls");

        fwrite(&a ,sizeof(a),1,ft);
                     //   printf("\n %d Product Details => \n ID = %d. \n Name = %s. \n Sales Price = %0.2f. \n Purchase Price = %0.2f.\n Stock = %d. \n",1, a.P_Id,a.Name,a.Sales_Price,a.Purchase_Price,a.Stock);
    }

    if(flag==0)
    {
        printf("Record not found\n\n");
    }
    fclose(fp);
    fclose(ft);
    fflush(stdin);
    remove("abc.txt");
    fflush(stdin);
    rename("teabc.txt","abc.txt");
}


void Search_Product()
{
    system("cls");
    FILE *fp ,*ft ;
    fp=fopen("abc.txt","rb+");
    int flag=0 ,id ;
    printf("Enter the id :");
    scanf("%d",&id);
    struct Product a;
    while(fread(&a , sizeof(a),1,fp)==1)
    {
        if(id==a.P_Id)
        {
            flag=1 ;
            printf("\n\n===============*****=================\n");
            printf("\n Product Details are => \n ID = %d. \n Name = %s. \n Sales Price = %0.2f. \n Purchase Price = %0.2f.\n Stock = %d. \n", a.P_Id,a.Name,a.Sales_Price,a.Purchase_Price,a.Stock);
            printf("\n\n===============*****=================\n");
            return;


        }
    }
    if(flag==0)
    {
        printf("ID not found.......");
    }

        fclose(fp);

}


void Display_Product_List()
{
    system("cls");
                FILE *fp=fopen("abc.txt","rb+");
                struct Product a ;
                printf("\n\n===============*****=================\n");

                printf("\n Display Product Details =>\n");
                int i=0;
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                        printf("\n--------------------------------------------\n");
                        printf("\n %d Product Details => \n ID = %d. \n Name = %s. \n Sales Price = %0.2f. \n Purchase Price = %0.2f.\n Stock = %d. \n",i+1, a.P_Id,a.Name,a.Sales_Price,a.Purchase_Price,a.Stock);
                        i++;
                }
                printf("\n--------------------------------------------\n");
                printf("\n\n===============*****=================\n");
                printf("Press any key to continue .........");
                fclose(fp);

}

void View_Product_Stock()
{
    system("cls");
                FILE *fp=fopen("abc.txt","rb+");
                struct Product a ;
                printf("\n +=======================+=====================+\n");
                printf("\n |        PRODUCT        |        Stock        |\n");
                printf("\n +=======================+=====================+\n");

                while(fread(&a,sizeof(a),1,fp)==1)
                {
                        printf("\n |    %-19s|       %-14d|\n", a.Name,a.Stock);
                        printf("\n +-----------------------+---------------------+\n");
                }
                fclose(fp);
}


int main()
{
            int Choice = 0;

            for(;;)                                                              // Unconditional For Loop
            {
                            printf("\n==========***  Product Inventory System  ***========== \n");
                            printf("\n==========================*****==========================\n");

                            printf("\n Select Choice =>\n\t\t 1. Add Product \n\t\t 2. Update Product \n\t\t 3. Search Product \n\t\t 4. Display Product List \n\t\t 5. Add Product Stock \n\t\t 6. View Product Stock \n\t\t 7. Exit");

                            printf("\n==========================*****==========================\n");

                            printf("\n Enter Your Choice : ");
                            scanf("%d", &Choice);

                            switch(Choice)
                            {
                                    case 1 :
                                                Add_New_Product();

                                                getch();
                                                system("cls");
                                                break;

                                    case 2 :
                                                Update_Product();


                                                system("cls");
                                                break;

                                    case 3 :
                                                Search_Product();

                                                getch();
                                                system("cls");
                                                break;

                                    case 4 :
                                                Display_Product_List();

                                                getch();
                                                system("cls");
                                                break;

                                    case 5 :
                                                add();

                                                getch();
                                                system("cls");
                                                break;

                                    case 6 :
                                                View_Product_Stock();

                                                getch();
                                                system("cls");
                                                break;

                                    case 7 :
                                                goto DOWN;

                                    default :
                                                printf("\n Invalid Choice Please Select a Valid Choice");
                                                getch();
                                                system("cls");
                                                break;
                            }
            }

            DOWN:
                printf("\n\n Thanks For Working Product Inventory System!!!");
                printf("\n Press Any Key To Exit");

                getch();
                return 0;
}
