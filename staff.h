/*----------EMPLOYEE OPERATIONS PROTOTYPES---------*/
void sadd();
void stdelete();
void supdate();
void ssearch();
void sview();
void staffmenu();
/*-----------gotoxy1() PROTOTYTPE----------*/
void gotoxy1(int,int);
/*------------STAFF STRUCTURE----------*/
struct staff
{
    char id[10];
    char name[50];
    char dept[50];
    float sal;
    char mobile[20];
};
/*----------------------------------------------------STAFF DATA SECTION-----------------------------------------------------*/
void staffmenu()
{
   int choice;
  system("cls");
  gotoxy1(64,1);
  printf("<----------:WELCOME TO EMPLOYEE SECTION:---------->");
  gotoxy1(64,3);
  printf("==================================================");
  gotoxy1(64,5);
  printf("	      MANAGE EMPLOYEE DATA");
  gotoxy1(64,7);
  printf("==================================================");
  gotoxy1(64,10);
  printf("1. Add Employee(s) Details");
  gotoxy1(64,12);
  printf("2. Delete Employee(s) Details");
  gotoxy1(64,14);
  printf("3. Modify Employee(s) Details");
  gotoxy1(64,16);
  printf("4. Search Employee(s) Details");
  gotoxy1(64,18);
  printf("5. Display Employee(s) Details");
  gotoxy1(64,20);
  printf("6. Go To Home");
  gotoxy1(64,22);
  printf("7. Exit");
  gotoxy1(64,24);
  printf("==================================================");
  gotoxy1(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    sadd();
    break;
  case 2:
    stdelete();
    break;
  case 3:
    supdate();
    break;
  case 4:
    ssearch();
    break;
  case 5:
    sview();
    break;
  case 6:
    main();
    break;
  case 7:
  	exit(1);
  default:
        gotoxy1(69,5);
        printf("Invalid Choice.");
  }
}
/*-------------------------------------------------------------------------ADD-----------------------------------------*/
void sadd()
{
    FILE *fp;
    struct staff st;
    char another ='y';
    system("cls");
    fp = fopen("staff.txt","ab+");
    if(fp == NULL){
        gotoxy1(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy1(69,3);
        printf("<---------------:ADD EMPLOYEE DETAILS:--------------->");
        gotoxy1(69,6);
        printf("-----------------------------------------------------");
        gotoxy1(69,9);
        printf("NAME OF THE EMPLOYEE\t: ");
        gets(st.name);
        gotoxy1(69,11);
        printf("STAFF ID\t\t\t: ");
        gets(st.id);
        gotoxy1(69,13);
        printf("ENTER DEPARTMENT\t\t: ");
        gets(st.dept);
        gotoxy1(69,15);
        printf("ENTER SALARY\t\t: ");
        scanf("%f",&st.sal);
		fflush(stdin);
        gotoxy1(69,17);
        printf("MOBILE No.\t\t\t: ");
        gets(st.mobile);
        fflush(stdin);
        gotoxy1(69,20);
        printf("-----------------------------------------------------");
        fwrite(&st,sizeof(st),1,fp);
        gotoxy1(69,22);
        printf("Want to add of another record?");
        gotoxy1(69,23);
        printf("if YES enter 'y' ");
        gotoxy1(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy1(69,1);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*---------------------------------------------DELETE----------------------------------------------------------------*/
void stdelete()
{
    int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct staff st;
    system("cls");
    gotoxy1(69,3);
    printf("< :DELETE EMPLOYEE RECORD: >");
    gotoxy1(60,5);
    printf("-----------------------------------------------------");
    gotoxy1(69,7);
    printf("Enter Employee ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("staff.txt","rb+");
    if(fp == NULL){
        gotoxy1(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy1(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&st,sizeof(st),1,fp) == 1){
        if(strcmp(strlwr(stid),strlwr(st.id))!=0)
            fwrite(&st,sizeof(st),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("staff.txt");
    rename("temp.txt","staff.txt");
    gotoxy1(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxy1(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxy1(69,14);
        printf("No Employee Found With ID:%s",stid);
    }
    gotoxy1(60,18);
    printf("=====================================================");
    gotoxy1(69,20);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*---------------------------------------------UPDATE/MODIFY---------------------------------------------*/
void supdate()
{
	int p=0;
    char stid[20];
    FILE *fp;
    struct staff st;
    system("cls");
    gotoxy1(69,3);
    printf("< :MODIFY EMPLOYEE RECORD: >");
    gotoxy1(60,5);
    printf("-----------------------------------------------------");
    gotoxy1(64,7);
    printf("Enter Employee ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("staff.txt","rb+");
    if(fp == NULL){
        gotoxy1(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxy1(60,9);
    printf("=====================================================");
    while(fread(&st,sizeof(st),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((st.id)))== 0){
        	p=1;
            gotoxy1(60,11);
            printf("EMPLOYEE NAME\t: ");
            gets(st.name);
            gotoxy1(60,13);
            printf("EMPLOYEE ID\t\t: ");
            gets(st.id);
            gotoxy1(60,15);
            printf("DEPARTMENT\t\t: ");
            gets(st.dept);
            gotoxy1(60,17);
            printf("SALARY\t\t: ");
            scanf("%f",&st.sal);
            fflush(stdin);
            gotoxy1(60,19);
            printf("MOBILE No.\t\t: ");
            gets(st.mobile);
            fseek(fp,-sizeof(st),SEEK_CUR);
            fwrite(&st,sizeof(st),1,fp);
            break;
        }
    }
    if(!p){
		gotoxy1(69,15);
    	printf("Employee Not Found With Id %s",stid);
	}
    gotoxy1(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxy1(69,23);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*--------------------------------------------------SEARCH---------------------------------------------------*/
void ssearch()
{
    int p=0;
    FILE *fp;
    struct staff st;
    char stid[20];
    system("cls");
    gotoxy1(69,3);
    printf("< :SEARCH EMPLOYEE RECORD: >");
    gotoxy1(60,5);
    printf("-----------------------------------------------------");
    gotoxy1(69,7);
    printf("Enter Employee ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("staff.txt","rb+");
    if(fp == NULL){
        gotoxy1(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxy1(60,9);
        	printf("=====================================================");
    while(fread(&st,sizeof(st),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((st.id)))== 0){
        	
            gotoxy1(60,11);
            printf("EMPLOYEE NAME\t: %s",st.name);
            gotoxy1(60,13);
            printf("EMPLOYEE ID\t\t: %s",st.id);
            gotoxy1(60,15);
            printf("DEPARTMENT\t\t: %s",st.dept);
            gotoxy1(60,17);
            printf("SALARY\t\t: %f",st.sal);
            gotoxy1(60,19);
            printf("MOBILE No.\t\t: %s",st.mobile);
            
            p=1;
        }
    }
    fclose(fp);
    gotoxy1(69,16);
    if(p==0)
      printf("Sorry, Data Not Found With Name: %s\n",stid);
      gotoxy1(60,21);
            printf("=====================================================");
    gotoxy1(69,23);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*-------------------------------VIEW--------------------------*/
void sview()
{
    FILE *fp;
    int i=1,j;
    struct staff st;
    system("cls");
    gotoxy1(62,3);
    printf("< :EMPLOYEE VIEW RECORD: >\n");
    gotoxy1(25,5);
    printf("--------------------------------------------------------------------------------------------------------------");
   gotoxy1(30,8);
    printf("S.No \t EMPLOYEE NAME\t\tEMPLOYEE ID \t DEPARTMENT\t\tSALARY\t\tMOBILE No.");
    gotoxy1(25,11);
    printf("--------------------------------------------------------------------------------------------------------------");
    fp = fopen("staff.txt","rb+");
    if(fp == NULL){
        gotoxy1(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&st,sizeof(st),1,fp) == 1){
        gotoxy1(31,j);
        printf("%-11d%-22s%-20s%-17s%-19f%-13s",i,st.name,st.id,st.dept,st.sal,st.mobile);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy1(69,j+3);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxy1(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
