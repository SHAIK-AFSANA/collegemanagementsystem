/*-----------gotoxyh() PROTOTYTPE----------*/
void gotoxyh(int ,int );
/*----------HOSTEL OPERATIONS PROTOTYPES---------*/
void hmenu();
void hadd();
void hview();
void hsearch();
void hmodify();
void hdelete();
void hrules();
void hfood_menu();
/*------------HOSTEL STRUCTURE----------*/
struct hstudent {
    char name[50];
    char id[20];
    char mobile[20];
	float sfee;
    float ffee;
    float tfee;
};
/*----------------------------------------------------HOSTEL STUDENT DATA SECTION-----------------------------------------------------*/
void hmenu()
{
    int choice;
  system("cls");
  gotoxyh(64,1);
  printf("<----------:WELCOME TO HOSTEL SECTION:---------->");
  gotoxyh(64,3);
  printf("==================================================");
  gotoxyh(64,5);
  printf("	      MANAGE HOSTEL DATA");
  gotoxyh(64,7);
  printf("==================================================");
  gotoxyh(64,10);
  printf("1. Add Hostel Student(s) Details");
  gotoxyh(64,12);
  printf("2. Delete Hostel Student(s) Details");
  gotoxyh(64,14);
  printf("3. Modify Hostel Student(s) Details");
  gotoxyh(64,16);
  printf("4. Search Hostel Student(s) Details");
  gotoxyh(64,18);
  printf("5. Display Hostel Student(s) Details");
  gotoxyh(64,20);
  printf("6. HOSTEL RULES");
  gotoxyh(64,22);
  printf("7. FOOD MENU");
  gotoxyh(64,24);
  printf("8. GO TO HOME");
  gotoxyh(64,26);
  printf("9. EXIT");
  gotoxyh(64,28);
  printf("==================================================");
  gotoxyh(64,31);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    hadd();
    break;
  case 2:
    hdelete();
    break;
  case 3:
    hmodify();
    break;
  case 4:
    hsearch();
    break;
  case 5:
    hview();
    break;
  case 6:
    hrules();
    break;
  case 7:
    hfood_menu();
    break;
  case 8:
  	main();
  	break;
  case 9:
	exit(1);
  default:
        gotoxyh(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void hadd()
{
    FILE *fp;
    struct hstudent std;
    char another ='y';
    system("cls");
	fp = fopen("hostel.txt","ab+");
    if(fp == NULL){
        gotoxyh(10,5);
        printf("Error opening file");
        exit(0);
    }
    fflush(stdin);
    while(another == 'y')
    {
         gotoxyh(66,3);
        printf("<---------------:ADD HOSTEL STUDENT DETAILS:--------------->");
        gotoxyh(66,6);
        printf("------------------------------------------------------------");
        gotoxyh(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxyh(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxyh(69,13);
        printf("MOBILE NUMBER\t\t: ");
       	gets(std.mobile);
       	gotoxyh(69,15);
        printf("SEAT FEE\t\t\t: ");
       	scanf("%f",&std.sfee);
        gotoxyh(69,17);
        printf("FOOD FEE\t\t\t: ");
       	scanf("%f",&std.ffee);
       	std.tfee=std.sfee+std.ffee;
        gotoxyh(66,20);
        printf("-----------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
        gotoxyh(69,22);
        printf("Want to add of another record?");
        gotoxyh(69,23);
        printf("if YES enter 'y' ");
        gotoxyh(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyh(69,1);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void hview()
{
     FILE *fp;
    int i=1,j;
    struct hstudent std;
    system("cls");
    gotoxyh(69,3);
    printf("< :HOSTEL STUDENT VIEW RECORD: >\n");
    gotoxyh(29,5);
    printf("----------------------------------------------------------------------------------------------------");
   gotoxyh(30,8);
    printf("S.No \t STUDENT NAME\t\tREGISTRATION NUMBER \t MOBILE No.\t  TOTAL FEE (seat+food)");
    gotoxyh(29,11);
    printf("----------------------------------------------------------------------------------------------------");
    fp = fopen("hostel.txt","rb+");
    if(fp == NULL){
        gotoxyh(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyh(31,j);
        printf("%-11d%-25s%-22s%-19s%-15f",i,std.name,std.id,std.mobile,std.tfee);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyh(69,j+3);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void hsearch()
{
	 int p=0;
    FILE *fp;
    struct hstudent std;
    char stid[20];
    system("cls");
    gotoxyh(69,3);
    printf("< :SEARCH HOSTEL STUDENT RECORD: >");
    gotoxyh(60,5);
    printf("-----------------------------------------------------");
    gotoxyh(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("hostel.txt","rb+");
    if(fp == NULL){
        gotoxyh(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyh(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
            gotoxyh(60,11);
            printf("STUDENT NAME\t: %s",std.name);
            gotoxyh(60,13);
            printf("REGISTRATION NUMBER\t: %s",std.id);
            gotoxyh(60,15);
            printf("MOBILE No.\t\t: %s",std.mobile);
            gotoxyh(60,17);
            printf("TOTAL FEE\t\t: %f",std.tfee);
            p=1;
        }
    }
    fclose(fp);
    
    if(p==0){
    gotoxyh(69,14);
      printf("Sorry, Data Not Found With ID: %s\n",stid);
	}
      gotoxyh(60,19);
            printf("=====================================================");
    gotoxyh(69,21);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void hmodify()
{
    int p=0;
    char stid[20];
    FILE *fp;
    struct hstudent std;
    system("cls");
    gotoxyh(69,3);
    printf("< :MODIFY HOSTEL STUDENT RECORD: >");
    gotoxyh(60,5);
    printf("-----------------------------------------------------");
    gotoxyh(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("hostel.txt","rb+");
    if(fp == NULL){
        gotoxyh(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyh(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxyh(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxyh(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            fflush(stdin);
            gotoxyh(60,15);
            printf("MOBILE No.\t\t: ");
            gets(std.mobile);
            fflush(stdin);
            gotoxyh(60,17);
            printf("SEAT FEE\t\t: ");
            scanf("%f",&std.sfee);
            gotoxyh(60,19);
            printf("FOOD FEE\t\t: ");
            scanf("%f",&std.ffee);
            std.tfee=std.sfee+std.ffee;
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxyh(69,15);
    	printf("Student Data Not Found With ID %s",stid);
	}
    gotoxyh(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxyh(69,23);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void hdelete()
{
	int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct hstudent std;
    system("cls");
    gotoxyh(69,3);
    printf("< :DELETE HOSTEL STUDENT RECORD: >");
    gotoxyh(60,5);
    printf("-----------------------------------------------------");
    gotoxyh(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("hostel.txt","rb+");
    if(fp == NULL){
        gotoxyh(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyh(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(strlwr(stid),strlwr(std.id))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("hostel.txt");
    rename("temp.txt","hostel.txt");
    gotoxyh(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyh(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyh(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxyh(60,18);
    printf("=====================================================");
    gotoxyh(69,20);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*-----------------------------------------------------HOSTEL RULES------------------------------------------------*/
void hrules()
{
	system("cls");
	gotoxyh(71,1);
	printf("<: HOSTEL RULES :>");
	gotoxyh(38,3);
	printf("========================================================================================================");
    gotoxyh(50,5);
	printf("1. You have to pay hostel charge every month within first 10 days.");
    gotoxyh(50,7);
	printf("**After 10 day you have to pay 20tk for each day & 200tk for each month.");
    gotoxyh(50,9);
	printf("2. You have to back in hostel in due time. \n\n\t\t\t\t\t\t\t\tsummer: last time 7.00pm\n\n\t\t\t\t\t\t\t\twinter: last time 6.00pm.");
    gotoxyh(50,15);
	printf("3. Before 6 month you cant leave the hostel.");
    gotoxyh(50,17);
	printf("4. If you want to leave this hostel you have to inform the hostel authority before 2 month.");
    gotoxyh(50,19);
	printf("5. If you have computer or laptop, we have to pay 100tk as fee.");
    gotoxyh(50,21);
	printf("6. Only your two local guardian can come to meet with you.");
    gotoxyh(38,23);
    printf("==========================================================================================================");
	gotoxyh(69,25);
	printf("Press Any Key To Continue...");
	getch();
    hmenu();
}
/*-----------------------------------------------HOSTEL FOOD MENU----------------------------------------------------------------*/
void hfood_menu()
{
	system("cls");
	gotoxyh(69,1);
	printf("<: HOSTEL FOOD MENU :>");
    gotoxyh(65,5);
    printf("\n");
    printf("\t\t\t\t\t| Day |     Breakfast       |          Lunch           |            Dinner         |\n");
    printf("\t\t\t\t\t=====================================================================================\n");
    printf("\t\t\t\t\t| Sat |   Ruti, Vegetable   | Rice, Chicken, Lentil    | Rice, Vegetable, Vorta    |\n");
    printf("\t\t\t\t\t| Sun |   Rice, Vegetable   | Rice, Fish, Lentil       | Rice, Vegetable, Egg      |\n");
    printf("\t\t\t\t\t| Mon |   Ruti, Egg         | Rice, Chicken, Lentil    | Rice, Fish, Lentil        |\n");
    printf("\t\t\t\t\t| Tue |   Khichuri, Egg     | Rice, Meat, Lentil       | Rice, Fish, Lentil        |\n");
    printf("\t\t\t\t\t| Wed |   Rice, Vorta       | Rice, Chicken, Lentil    | Rice, Egg, Lentil         |\n");
    printf("\t\t\t\t\t| Thu |   Ruti, Vegetable   | Rice, Fish, Lentil       | Rice, Vegetable, Egg      |\n");
    printf("\t\t\t\t\t| Fri |   Khichuri, Egg     | Rice, Chicken, Lentil    | Rice, Fish, Lentil        |\n");
    printf("\t\t\t\t\t=====================================================================================\n");
	gotoxyh(69,18);
	printf("Press Any Key To Continue...");
	getch();
    hmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyh(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
