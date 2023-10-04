/*-----------gotoxyg() PROTOTYTPE----------*/
void gotoxyg(int ,int );
/*----------GRADING OPERATIONS PROTOTYPES---------*/
void gmenu();
void gadd();
void gview();
void gsearch();
void gmodify();
void gdelete();
/*------------STUDENT GRADING STRUCTURE----------*/
struct gstudent
{
    char name[20];
    char id[20];
    char course[20];
    char branch[20];
    float percentage;
    char grade;
};
/*----------------------------------------------------STUDENT GRADING SECTION-----------------------------------------------------*/
void gmenu()
{
    int choice;
    system("cls"); //clrscr()
     gotoxyg(64,1);
  printf("<----------:WELCOME TO GRADING SECTION:---------->");
  gotoxyg(64,3);
  printf("==================================================");
  gotoxyg(62,5);
  printf("	      MANAGE STUDENT PROGRESS CARD");
  gotoxyg(64,7);
  printf("==================================================");
  gotoxyg(64,10);
  printf("1. Add Student(s) Marks Details");
  gotoxyg(64,12);
  printf("2. Delete Student(s) Marks Details");
  gotoxyg(64,14);
  printf("3. Modify Student(s) Marks Details");
  gotoxyg(64,16);
  printf("4. Search Student(s) Marks Details");
  gotoxyg(64,18);
  printf("5. Display Student(s) Marks Details");
  gotoxyg(64,20);
  printf("6. Go To Home");
  gotoxyg(64,22);
  printf("7. Exit");
  gotoxyg(64,24);
  printf("==================================================");
  gotoxyg(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
    switch(choice)
    {
    case 1:
        gadd();
        break;

    case 2:
        gdelete();
        break;

    case 3:
       gmodify();
        break;

    case 4:
        
        gsearch();
        break;


    case 5:
    	gview();
        break;
       

    case 6:
        main();
        break;
	case 7:
        exit(0);
    default:
        gotoxyg(69,5);
        printf("Invalid Choice.");
    }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void gadd()
{
    FILE *fp;
    struct gstudent std;
    char another ='y';
    system("cls");

    fp = fopen("grade.txt","ab+");
    if(fp == NULL){
        gotoxyg(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxyg(69,3);
        printf("<---------------:ADD STUDENT MARKS DETAILS:--------------->");
        gotoxyg(69,6);
        printf("-----------------------------------------------------");
        gotoxyg(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxyg(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxyg(69,13);
        printf("COURSE\t\t\t: ");
       	gets(std.course);
       	gotoxyg(69,15);
        printf("BRANCH\t\t\t: ");
       	gets(std.branch);
        gotoxyg(69,17);
        printf("ENTER PERCENTAGE\t\t: ");
        scanf("%f",&std.percentage);
        if(std.percentage>=85.0)
			std.grade=65;
		else if(std.percentage>=75.0)
			std.grade=66;
		else if(std.percentage>=65.0)
			std.grade=67;
		else if(std.percentage>=55.0)
			std.grade=68;
		else
			std.grade=69;
        gotoxyg(69,20);
        printf("-----------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      	gotoxyg(69,22);
        printf("Want to add of another record?");
        gotoxyg(69,23);
        printf("if YES enter 'y' ");
        gotoxyg(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyg(69,1);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void gview()
{
    FILE *fp;
    int i=1,j;
    struct gstudent std;
    system("cls");
    gotoxyg(64,3);
    printf("< :STUDENT(s) PROGRESS RECORD: >\n");
    gotoxyg(20,5);
    printf("------------------------------------------------------------------------------------------------------------------------");
   gotoxyg(25,8);
    printf("S.No \t   STUDENT NAME\t\tREGISTRATION NUMBER \t COURSE\t\tBRANCH\t\tPERCENTAGE\tGRADE");
    gotoxyg(20,11);
    printf("------------------------------------------------------------------------------------------------------------------------");
    fp = fopen("grade.txt","rb+");
    if(fp == NULL){
        gotoxyg(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyg(26,j);
        printf("%-9d%-25s%-22s%-15s%-16s%-18f%-10c",i,std.name,std.id,std.course,std.branch,std.percentage,std.grade);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyg(69,j+3);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void gsearch()
{
   int p=0;
    FILE *fp;
    struct gstudent std;
    char stid[20];
    system("cls");
    gotoxyg(69,3);
    printf("< :SEARCH STUDENT PROGRESS RECORD: >");
    gotoxyg(60,5);
    printf("-----------------------------------------------------");
    gotoxyg(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("grade.txt","rb+");
    if(fp == NULL){
        gotoxyg(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyg(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	
            gotoxyg(60,11);
            printf("STUDENT NAME\t: %s",std.name);
            gotoxyg(60,13);
            printf("REGISTRATION NUMBER\t: %s",std.id);
            gotoxyg(60,15);
            printf("COURSE\t\t: %s",std.course);
            gotoxyg(60,17);
            printf("BRANCH\t\t: %s",std.branch);
            gotoxyg(60,19);
            printf("PERCENTAGE\t\t: %f",std.percentage);
            gotoxyg(60,21);
            printf("GRADE\t\t: %c",std.grade);
            p=1;
        }
    }
    fclose(fp);
    gotoxyg(69,16);
    if(p==0){
	gotoxyg(69,16);
      printf("Sorry, Data Not Found With ID: %s\n",stid);
  }
    gotoxyg(60,23);
    printf("=====================================================");
    gotoxyg(69,25);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void gmodify()
{
	int p=0;
    char stid[20];
    FILE *fp;
    struct gstudent std;
    system("cls");
    gotoxyg(69,3);
    printf("< :MODIFY STUDENT PROGRESS RECORD: >");
    gotoxyg(60,5);
    printf("-----------------------------------------------------");
    gotoxyg(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("grade.txt","rb+");
    if(fp == NULL){
        gotoxyg(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyg(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxyg(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxyg(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            gotoxyg(60,15);
            printf("COURSE\t\t: ");
            gets(std.course);
            gotoxyg(60,17);
            printf("BRANCH\t\t: ");
            gets(std.branch);
            gotoxyg(60,19);
            printf("PERCENTAGE\t\t: ");
            scanf("%f",&std.percentage);
            if(std.percentage>=85.0)
				std.grade=65;
			else if(std.percentage>=75.0)
				std.grade=66;
			else if(std.percentage>=65.0)
				std.grade=67;
			else if(std.percentage>=55.0)
				std.grade=68;
			else
				std.grade=69;
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxyg(60,15);
    	printf("Student Data Not Found With ID %s",stid);
	}
    gotoxyg(60,21);
    printf("=====================================================");

    fclose(fp);
    gotoxyg(69,23);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void gdelete()
{
     int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct gstudent std;
    system("cls");
    gotoxyg(69,3);
    printf("< :DELETE STUDENT PROGRESS RECORD: >");
    gotoxyg(60,5);
    printf("-----------------------------------------------------");
    gotoxyg(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("grade.txt","rb+");
    if(fp == NULL){
        gotoxyg(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyg(69,6);
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
    remove("grade.txt");
    rename("temp.txt","grade.txt");
    gotoxyg(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyg(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyg(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxyg(60,18);
    printf("=====================================================");
    gotoxyg(69,20);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyg(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
