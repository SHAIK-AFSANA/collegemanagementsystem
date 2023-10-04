/*----------STUDENT OPERATIONS PROTOTYPES---------*/
void add();
void sdelete();
void update();
void search();
void view();
void studentmenu();
/*------------STUDENT STRUCTURE----------*/
struct student
{
    char id[20];
    char name[50];
    char mobile[20];
    char course[50];
    char branch[50];
};
/*-----------gotoxysu() PROTOTYTPE----------*/
void gotoxysu(int,int);
/*----------------------------------------------------STUDENT DATA SECTION-----------------------------------------------------*/
void studentmenu()
{
  int choice;
  system("cls");
  gotoxysu(64,1);
  printf("<----------:WELCOME TO STUDENT SECTION:---------->");
  gotoxysu(64,3);
  printf("==================================================");
  gotoxysu(64,5);
  printf("	      MANAGE STUDENT DATA");
  gotoxysu(64,7);
  printf("==================================================");
  gotoxysu(64,10);
  printf("1. Add Student(s) Details");
  gotoxysu(64,12);
  printf("2. Delete Student(s) Details");
  gotoxysu(64,14);
  printf("3. Modify Student(s) Details");
  gotoxysu(64,16);
  printf("4. Search Student(s) Details");
  gotoxysu(64,18);
  printf("5. Display Student(s) Details");
  gotoxysu(64,20);
  printf("6. Go To Home");
  gotoxysu(64,22);
  printf("7. Exit");
  gotoxysu(64,24);
  printf("==================================================");
  gotoxysu(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    add();
    break;
  case 2:
    sdelete();
    break;
  case 3:
    update();
    break;
  case 4:
    search();
    break;
  case 5:
    view();
    break;
  case 6:
    main();
    break;
  case 7:
  	exit(1);
  default:
        gotoxysu(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void add()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");
    fp = fopen("student.txt","ab+");
    if(fp == NULL){
        gotoxysu(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxysu(69,3);
        printf("<---------------:ADD STUDENT DETAILS:--------------->");
        gotoxysu(69,6);
        printf("-----------------------------------------------------");
        gotoxysu(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxysu(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxysu(69,13);
        printf("COURSE\t\t\t: ");
       	gets(std.course);
       	gotoxysu(69,15);
        printf("BRANCH\t\t\t: ");
       	gets(std.branch);
        gotoxysu(69,17);
        printf("MOBILE NUMBER\t\t: ");
       	gets(std.mobile);
        fflush(stdin);
        gotoxysu(69,20);
        printf("-----------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      gotoxysu(69,22);
        printf("Want to add of another record?");
        gotoxysu(69,23);
        printf("if YES enter 'y' ");
        gotoxysu(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxysu(69,1);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxysu(69,3);
    printf("< :STUDENT VIEW RECORD: >\n");
    gotoxysu(29,5);
    printf("----------------------------------------------------------------------------------------------------");
   gotoxysu(30,8);
    printf("S.No \t STUDENT NAME\t\tREGISTRATION NUMBER \t COURSE\t\tBRANCH\t\tMOBILE No.");
    gotoxysu(29,11);
    printf("----------------------------------------------------------------------------------------------------");
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        gotoxysu(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxysu(31,j);
        printf("%-11d%-25s%-22s%-15s%-15s%-11s",i,std.name,std.id,std.course,std.branch,std.mobile);
        i++;
        j++;
    }
    fclose(fp);
    gotoxysu(69,j+3);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void search()
{
    int p=0;
    FILE *fp;
    struct student std;
    char stid[20];
    system("cls");
    gotoxysu(69,3);
    printf("< :SEARCH STUDENT RECORD: >");
    gotoxysu(60,5);
    printf("-----------------------------------------------------");
    gotoxysu(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        gotoxysu(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxysu(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	
            gotoxysu(60,11);
            printf("STUDENT NAME\t: %s",std.name);
            gotoxysu(60,13);
            printf("REGISTRATION NUMBER\t: %s",std.id);
            gotoxysu(60,15);
            printf("COURSE\t\t: %s",std.course);
            gotoxysu(60,17);
            printf("BRANCH\t\t: %s",std.branch);
            gotoxysu(60,19);
            printf("MOBILE No.\t\t: %s",std.mobile);
            
            p=1;
        }
    }
    fclose(fp);
    gotoxysu(69,16);
    if(p==0)
      printf("Sorry, Data Not Found With ID: %s\n",stid);
      gotoxysu(60,21);
            printf("=====================================================");
    gotoxysu(69,23);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void sdelete()
{
    int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    gotoxysu(69,3);
    printf("< :DELETE STUDENT RECORD: >");
    gotoxysu(60,5);
    printf("-----------------------------------------------------");
    gotoxysu(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        gotoxysu(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxysu(69,6);
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
    remove("student.txt");
    rename("temp.txt","student.txt");
    gotoxysu(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxysu(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxysu(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxysu(60,18);
    printf("=====================================================");
    gotoxysu(69,20);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void update()
{
	int p=0;
    char stid[20];
    FILE *fp;
    struct student std;
    system("cls");
    gotoxysu(69,3);
    printf("< :MODIFY STUDENT RECORD: >");
    gotoxysu(60,5);
    printf("-----------------------------------------------------");
    gotoxysu(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        gotoxysu(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxysu(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxysu(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxysu(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            gotoxysu(60,15);
            printf("COURSE\t\t: ");
            gets(std.course);
            gotoxysu(60,17);
            printf("BRANCH\t\t: ");
            gets(std.branch);
            gotoxysu(60,19);
            printf("MOBILE No.\t\t: ");
            gets(std.mobile);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxysu(60,15);
    	printf("Student Data Not Found With ID %s",stid);
	}
    gotoxysu(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxysu(69,23);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxysu(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
