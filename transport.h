/*-----------gotoxyt() PROTOTYTPE----------*/
void gotoxyt(int x, int y);
/*----------TRANSPORT OPERATIONS PROTOTYPES---------*/
void tmenu();
void tadd();
void tview();
void tsearch();
void tmodify();
void tdelete();
void trules();
/*------------TRANSPORT STRUCTURE----------*/
struct transport{
    char name[50];
    char id[20];
    char busno[20];
    char area[50];
    float fee;
};
/*----------------------------------------------------TRANSPORT DATA SECTION-----------------------------------------------------*/
void tmenu() {
    int choice;
  system("cls");
  gotoxyt(64,1);
  printf("<----------:WELCOME TO TRANSPORTATION SECTION:---------->");
  gotoxyt(64,3);
  printf("=========================================================");
  gotoxyt(64,5);
  printf("	      MANAGE TRANSPORTATION DATA");
  gotoxyt(64,7);
  printf("=========================================================");
  gotoxyt(64,10);
  printf("1. Add Student(s) Transport Details");
  gotoxyt(64,12);
  printf("2. Delete Student(s) Transport Details");
  gotoxyt(64,14);
  printf("3. Modify Student(s) Transport Details");
  gotoxyt(64,16);
  printf("4. Search Student(s) Transport Details");
  gotoxyt(64,18);
  printf("5. Display Student(s) Transport Details");
  gotoxyt(64,20);
  printf("6. TRANSPORTATION RULES");
  gotoxyt(64,22);
  printf("7. GO TO HOME");
  gotoxyt(64,24);
  printf("8. EXIT");
  gotoxyt(64,26);
  printf("=========================================================");
  gotoxyt(64,29);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    tadd();
    break;
  case 2:
    tdelete();
    break;
  case 3:
    tmodify();
    break;
  case 4:
    tsearch();
    break;
  case 5:
    tview();
    break;
  case 6:
    trules();
    break;
  case 7:
    main();
    break;
  case 8:
  	exit(1);
  default:
        gotoxyt(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void tadd() {
    FILE *fp;
    struct transport std;
    char another ='y';
    system("cls");
    fp = fopen("transport.txt","ab+");
    if(fp == NULL){
        gotoxyt(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxyt(63,3);
        printf("<---------------:ADD STUDENT TRANSPORT DETAILS:--------------->");
        gotoxyt(63,6);
        printf("---------------------------------------------------------------");
        gotoxyt(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxyt(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxyt(69,13);
        printf("BUS NUMBER\t\t\t: ");
       	gets(std.busno);
       	gotoxyt(69,15);
        printf("AREA OF STUDENT\t\t: ");
       	gets(std.area);
        gotoxyt(69,17);
        printf("TRANSPORT FEE\t\t: ");
       	scanf("%f",&std.fee);
        fflush(stdin);
        gotoxyt(63,20);
        printf("----------------------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      	gotoxyt(69,22);
        printf("Want to add of another record?");
        gotoxyt(69,23);
        printf("if YES enter 'y' ");
        gotoxyt(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyt(69,1);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void tview() {
    FILE *fp;
    int i=1,j;
    struct transport std;
    system("cls");
    gotoxyt(65,3);
    printf("< :STUDENT(s) TRANSPORT RECORD: >\n");
    gotoxyt(25,5);
    printf("--------------------------------------------------------------------------------------------------------------------");
    gotoxyt(27,8);
    printf("S.No \t STUDENT NAME\t\tREGISTRATION NUMBER \tBUS No.\t\tLOCATION\t    TRANSPORT FEE");
    gotoxyt(25,11);
    printf("--------------------------------------------------------------------------------------------------------------------");
    fp = fopen("transport.txt","rb+");
    if(fp == NULL){
        gotoxyt(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyt(30,j);
        printf("%-11d%-25s%-22s%-16s%-21s%-11f",i,std.name,std.id,std.busno,std.area,std.fee);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyt(69,j+3);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void tsearch() {
    int p=0;
    FILE *fp;
    struct transport std;
    char stid[20];
    system("cls");
    gotoxyt(69,3);
    printf("< :SEARCH STUDENT TRANSPORT RECORD: >");
    gotoxyt(60,5);
    printf("-----------------------------------------------------");
    gotoxyt(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("transport.txt","rb+");
    if(fp == NULL){
        gotoxyt(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyt(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	
            gotoxyt(60,11);
            printf("STUDENT NAME\t: %s",std.name);
            gotoxyt(60,13);
            printf("REGISTRATION NUMBER\t: %s",std.id);
            gotoxyt(60,15);
            printf("BUS No.\t\t: %s",std.busno);
            gotoxyt(60,17);
            printf("LOCATION\t\t: %s",std.area);
            gotoxyt(60,19);
            printf("TRANSPORT FEE\t: %f",std.fee);
            
            p=1;
        }
    }
    fclose(fp);
    gotoxyt(69,16);
    if(p==0)
      printf("Sorry, Data Not Found With ID: %s\n",stid);
      gotoxyt(60,21);
            printf("=====================================================");
    gotoxyt(69,23);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void tmodify() {
    int p=0;
    char stid[20];
    FILE *fp;
    struct transport std;
    system("cls");
    gotoxyt(69,3);
    printf("< :MODIFY STUDENT TRANSPORT RECORD: >");
    gotoxyt(60,5);
    printf("-----------------------------------------------------");
    gotoxyt(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("transport.txt","rb+");
    if(fp == NULL){
        gotoxyt(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyt(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxyt(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxyt(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            gotoxyt(60,15);
            printf("BUS No.\t\t: ");
            gets(std.busno);
            gotoxyt(60,17);
            printf("LOCATION\t\t: ");
            gets(std.area);
            gotoxyt(60,19);
            printf("TRANSPORT FEE\t: ");
            scanf("%f",&std.fee);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxyt(67,15);
    	printf("Student Data Not Found With ID %s",stid);
	}
    gotoxyt(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxyt(69,23);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void tdelete() {
    int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct transport std;
    system("cls");
    gotoxyt(69,3);
    printf("< :DELETE STUDENT TRANSPORT RECORD: >");
    gotoxyt(60,5);
    printf("-----------------------------------------------------");
    gotoxyt(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("transport.txt","rb+");
    if(fp == NULL){
        gotoxyt(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyt(69,6);
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
    remove("transport.txt");
    rename("temp.txt","transport.txt");
    gotoxyt(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyt(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyt(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxyt(60,18);
    printf("=====================================================");
    gotoxyt(69,20);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*-----------------------------------------------TRANSPORT RULES and REGULATIONS---------------------------------------------*/
void trules() {
	gotoxyt(69,1);
	printf("<: RULES AND REGULATIONS :>");
	gotoxyt(50,3);
	printf("=================================================================================");
	gotoxyt(56,5);
    printf("1. Students are required to pay transportation fees on a monthly basis.");
    gotoxyt(56,7);
    printf("2. Timely arrival at designated pickup points is mandatory.");
    gotoxyt(56,9);
    printf("3. Any changes in transportation details must be notified in advance.");
    gotoxyt(50,11);
    printf("=================================================================================");
    gotoxyt(69,13);
    printf("Press any key to enter..");
    getch();
    tmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyt(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
