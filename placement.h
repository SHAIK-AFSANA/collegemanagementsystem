/*-----------gotoxyp() PROTOTYTPE----------*/
void gotoxyp(int ,int );
/*----------PLACEMENT OPERATIONS PROTOTYPES---------*/
void cmenu();
void cadd();
void cview();
void csearch();
void cmodify();
void cdelete();
/*------------PLACEMENT STRUCTURE----------*/
struct company
{
    char name[20];
    char package[10];
    int count;
};
/*----------------------------------------------------PLACEMENT DATA SECTION-----------------------------------------------------*/
void cmenu()
{
  int choice;
  system("cls");
  gotoxyp(64,1);
  printf("<----------:WELCOME TO PLACEMENT SECTION:---------->");
  gotoxyp(64,3);
  printf("==================================================");
  gotoxyp(64,5);
  printf("	      MANAGE PLACEMENT DATA");
  gotoxyp(64,7);
  printf("==================================================");
  gotoxyp(64,10);
  printf("1. Add Company(ies) Details");
  gotoxyp(64,12);
  printf("2. Delete Company(ies) Details");
  gotoxyp(64,14);
  printf("3. Modify Compnany(ies) Details");
  gotoxyp(64,16);
  printf("4. Search Company(ies) Details");
  gotoxyp(64,18);
  printf("5. Display Company(ies) Details");
  gotoxyp(64,20);
  printf("6. Go To Home");
  gotoxyp(64,22);
  printf("7. Exit");
  gotoxyp(64,24);
  printf("==================================================");
  gotoxyp(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    cadd();
    break;
  case 2:
    cdelete();
    break;
  case 3:
    cmodify();
    break;
  case 4:
    csearch();
    break;
  case 5:
    cview();
    break;
  case 6:
    main();
    break;
  case 7:
  	exit(1);
  default:
        gotoxyp(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void cadd()
{
    FILE *fp;
    struct company std;
    char another ='y';
    system("cls");

    fp = fopen("company.txt","ab+");
    if(fp == NULL){
        gotoxyp(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxyp(64,3);
        printf("<---------------:ADD STUDENT DETAILS:--------------->");
        gotoxyp(64,6);
        printf("-----------------------------------------------------");
        gotoxyp(64,9);
        printf("NAME OF THE COMPANY\t: ");
        gets(std.name);
        gotoxyp(64,11);
        printf("PACKAGE OFFERED\t\t: ");
        gets(std.package);
        gotoxyp(64,13);
        printf("No.of SELECTIONS\t: ");
        scanf("%d",&std.count);
        gotoxyp(64,16);
        printf("-----------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      	gotoxyp(64,18);
        printf("Want to add of another record?");
        gotoxyp(64,19);
        printf("if YES enter 'y' ");
        gotoxyp(64,20);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyp(69,1);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void cview()
{
    FILE *fp;
    int i=1,j;
    struct company std;
    system("cls");
    gotoxyp(65,3);
    printf("< :COMPANIES DETAILS: >");
    gotoxyp(32,5);
    printf("------------------------------------------------------------------------------------------");
    gotoxyp(40,8);
    printf("S.No \t   COMPANY NAME\t\tPACKAGE OFFERED \t STUDENTS SELECTED");
    gotoxyp(32,11);
    printf("------------------------------------------------------------------------------------------");
    fp = fopen("company.txt","rb+");
    if(fp == NULL){
        gotoxyp(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyp(40,j);
        printf("%-13d%-24s%-25s%-20d",i,std.name,std.package,std.count);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyp(65,j+3);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void csearch()
{
	int p=0;
    FILE *fp;
    struct company std;
    char cname[20];
    system("cls");
    gotoxyp(69,3);
    printf("< :SEARCH COMPANY RECORD: >");
    gotoxyp(60,5);
    printf("-----------------------------------------------------");
    gotoxyp(69,7);
    printf("Enter name of company : ");
    fflush(stdin);
    gets(cname);
    fp = fopen("company.txt","rb+");
    if(fp == NULL){
        gotoxyp(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyp(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(cname),strlwr(std.name)) == 0){
            gotoxyp(60,11);
            printf("COMPANY NAME\t: %s",std.name);
            gotoxyp(60,13);
            printf("PACKAGE OFFERED\t: %s",std.package);
            gotoxyp(60,15);
            printf("STUDENTS SELECTED\t: %d",std.count);
			p=1;
        }
    }
    fclose(fp);
    
    if(p==0){
    gotoxyp(69,13);
      printf("Sorry, Company Not Found With Name: %s\n",cname);
  	}
      gotoxyp(60,18);
            printf("=====================================================");
    gotoxyp(69,23);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void cmodify()
{
    int p=0;
    char cname[20];
    FILE *fp;
    struct company std;
    system("cls");
    gotoxyp(69,3);
    printf("< :MODIFY COMPANY RECORD: >");
    gotoxyp(60,5);
    printf("-----------------------------------------------------");
    gotoxyp(64,7);
    printf("Enter Company Name to Modify Details: ");
    fflush(stdin);
    gets(cname);
    fp = fopen("company.txt","rb+");
    if(fp == NULL){
        gotoxyp(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyp(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(cname),strlwr(std.name)) == 0){
            p=1;
            gotoxyp(60,11);
            printf("COMPANY NAME\t: ");
            gets(std.name);
            gotoxyp(60,13);
            printf("PACKAGE OFFERED\t: ");
            gets(std.package);
            gotoxyp(60,15);
            printf("No.of SELECTIONS\t: ");
            scanf("%d",&std.count);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
   if(p==0)
    {
    	gotoxyp(67,12);
    	printf("Company Data Not Found With Name %s",cname);
	}
    gotoxyp(60,17);
            printf("=====================================================");

    fclose(fp);
    gotoxyp(69,20);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void cdelete()
{
    int p=0;
    char cname[20];
    FILE *fp,*ft;
    struct company std;
    system("cls");
    gotoxyp(69,3);
    printf("< :DELETE COMPANY RECORD: >");
    gotoxyp(60,5);
    printf("-----------------------------------------------------");
    gotoxyp(69,7);
    printf("Enter Company to Delete: ");
    fflush(stdin);
    gets(cname);
    fp = fopen("company.txt","rb+");
    if(fp == NULL){
        gotoxyp(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyp(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(strlwr(cname),strlwr(std.name))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("company.txt");
    rename("temp.txt","company.txt");
    gotoxyp(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyp(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyp(69,14);
        printf("No Company Found With Name:%s",cname);
    }
    gotoxyp(60,18);
    printf("=====================================================");
    gotoxyp(69,20);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyp(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
