/*-----------gotoxysu() PROTOTYTPE----------*/
void gotoxyat(int,int);
/*----------STUDENT ATTENDANCE OPERATIONS PROTOTYPES---------*/
void atmenu();
void atadd();
void atview();
void atsearch();
void atmodify();
void atdelete();
/*------------STUDENT ATTENDANCE STRUCTURE----------*/
struct atstudent
{
    char name[20];
    char id[20];
    char course[20];
    char branch[20];
    int total;
    int present;
    float percentage;
};
/*----------------------------------------------------STUDENT ATTENDANCE DATA SECTION-----------------------------------------------------*/
void atmenu()
{
  int choice;
  system("cls");
  gotoxyat(64,1);
  printf("<----------:WELCOME TO ATTENDANCE SECTION:---------->");
  gotoxyat(64,3);
  printf("==================================================");
  gotoxyat(64,5);
  printf("	      MANAGE STUDENT ATTENDANCE DATA");
  gotoxyat(64,7);
  printf("==================================================");
  gotoxyat(64,10);
  printf("1. Add Student(s) Attendance");
  gotoxyat(64,12);
  printf("2. Delete a Student(s) Details");
  gotoxyat(64,14);
  printf("3. Modify a Student(s) Details");
  gotoxyat(64,16);
  printf("4. Search for a Particular Student(s) Attendance");
  gotoxyat(64,18);
  printf("5. Display All Students Attendance Percentage");
  gotoxyat(64,20);
  printf("6. Go To Home");
  gotoxyat(64,22);
  printf("7. Exit");
  gotoxyat(64,24);
  printf("==================================================");
  gotoxyat(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    atadd();
    break;
  case 2:
    atdelete();
    break;
  case 3:
    atupdate();
    break;
  case 4:
    atsearch();
    break;
  case 5:
    atview();
    break;
  case 6:
    main();
    break;
  case 7:
  	exit(1);
  default:
        gotoxyat(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD RECORD----------------------------------------------------------*/
void atadd()
{
    FILE *fp;
    struct atstudent std;
    char another ='y';
    system("cls");

    fp = fopen("attendance.txt","ab+");
    if(fp == NULL){
        gotoxyat(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxyat(69,3);
        printf("<---------------:ADD STUDENT DETAILS:--------------->");
        gotoxyat(69,6);
        printf("-----------------------------------------------------");
        gotoxyat(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxyat(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxyat(69,13);
        printf("COURSE\t\t\t: ");
       	gets(std.course);
       	gotoxyat(69,15);
        printf("BRANCH\t\t\t: ");
       	gets(std.branch);
        gotoxyat(69,17);
        fflush(stdin);
        printf("TOTAL WORKING DAYS\t\t: ");
        scanf("%d",&std.total);
        gotoxyat(69,19);
        printf("STUDENT ATTENDED\t\t: ");
        scanf("%d",&std.present);
        std.percentage=(std.present*100)/std.total;
        fwrite(&std,sizeof(std),1,fp);
        gotoxyat(69,21);
        printf("-----------------------------------------------------");
        gotoxyat(69,23);
        printf("Want to add of another record?");
        gotoxyat(69,24);
        printf("if YES enter 'y' ");
        gotoxyat(69,25);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyat(69,1);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void atview()
{
    FILE *fp;
    int i=1,j;
    struct atstudent std;
    system("cls");
    gotoxyat(69,3);
    printf("< :ATTENDANCE PROGRESS: >\n");
    gotoxyat(25,5);
    printf("-------------------------------------------------------------------------------------------------------------------------");
   gotoxyat(30,8);
    printf("S.No \t STUDENT NAME\t\tREGISTRATION NUMBER \t COURSE\t\tBRANCH\t\tATTENDANCE PERCENTAGE");
    gotoxyat(25,11);
    printf("-------------------------------------------------------------------------------------------------------------------------");
    fp = fopen("attendance.txt","rb+");
    if(fp == NULL){
        gotoxyat(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyat(31,j);
        printf("%-11d%-25s%-22s%-15s%-20s%-11f",i,std.name,std.id,std.course,std.branch,std.percentage);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyat(69,j+3);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void atsearch()
{
    int p=0;
    FILE *fp;
    struct atstudent std;
    char stid[20];
    system("cls");
    gotoxyat(69,3);
    printf("< :SEARCH STUDENT ATTENDANCE: >");
    gotoxyat(60,5);
    printf("-----------------------------------------------------");
    gotoxyat(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("attendance.txt","rb+");
    if(fp == NULL){
        gotoxyat(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyat(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	
            gotoxyat(60,11);
            printf("STUDENT NAME\t  : %s",std.name);
            gotoxyat(60,13);
            printf("REGISTRATION NUMBER\t  : %s",std.id);
            gotoxyat(60,15);
            printf("COURSE\t\t  : %s",std.course);
            gotoxyat(60,17);
            printf("BRANCH\t\t  : %s",std.branch);
            gotoxyat(60,19);
            printf("ATTENDANCE PERCENTAGE : %f",std.percentage);
            
            p=1;
        }
    }
    fclose(fp);
    gotoxyat(69,16);
    if(p==0)
      printf("Sorry, Data Not Found With ID: %s\n",stid);
      gotoxyat(60,21);
            printf("=====================================================");
    gotoxyat(69,23);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void atupdate()
{
	int p=0;
   char stid[20];
    FILE *fp;
    struct atstudent std;
    system("cls");
    gotoxyat(69,3);
    printf("< :MODIFY STUDENT ATTENDANCE: >");
    gotoxyat(60,5);
    printf("-----------------------------------------------------");
    gotoxyat(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("attendance.txt","rb+");
    if(fp == NULL){
        gotoxyat(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyat(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxyat(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxyat(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            gotoxyat(60,15);
            printf("COURSE\t\t: ");
            gets(std.course);
            gotoxyat(60,17);
            printf("BRANCH\t\t: ");
            gets(std.branch);
            gotoxyat(60,19);
            printf("TOTAL WORKING DAYS\t: ");
            scanf("%d",&std.total);
            gotoxyat(60,21);
        	printf("ATTENDED DAYS\t: ");
        	scanf("%d",&std.present);
        	std.percentage=(std.present*100)/std.total;
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0){
    gotoxyat(69,15);
      printf("Sorry, Data Not Found With ID: %s\n",stid);
	}
     gotoxyat(60,23);
    printf("=====================================================");

    fclose(fp);
    gotoxyat(69,25);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void atdelete()
{
    int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct atstudent std;
    system("cls");
    gotoxyat(69,3);
    printf("< :DELETE STUDENT ATTENDANCE REPORT: >");
    gotoxyat(60,5);
    printf("-----------------------------------------------------");
    gotoxyat(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("attendance.txt","rb+");
    if(fp == NULL){
        gotoxyat(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyat(69,6);
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
    remove("attendance.txt");
    rename("temp.txt","attendance.txt");
    gotoxyat(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyat(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyat(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxyat(60,18);
    printf("=====================================================");
    gotoxyat(69,20);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyat(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
