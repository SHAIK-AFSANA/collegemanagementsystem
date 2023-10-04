/*-----------gotoxye() PROTOTYTPE----------*/
void gotoxye(int ,int );
/*----------EVENT OPERATIONS PROTOTYPES---------*/
void eventtype();
void techev();
void nontechev();
void eadd();
void eview();
void esearch();
void emodify();
void edelete();
/*------------EVENT STRUCTURE----------*/
struct event
{
    char name[20];
    char timing[10];
    float fee;
    char location[20];
    char branch[200];
};

int r;
/*----------------------------------------------------EVENT DATA SECTION-----------------------------------------------------*/
void eventtype()
{
	int choice;
  system("cls");
  gotoxye(64,1);
  printf("<----------:WELCOME TO EVENTS SECTION:---------->");
  gotoxye(64,3);
  printf("==================================================");
  gotoxye(64,5);
  printf("	      MANAGE EVENTS DATA");
  gotoxye(64,7);
  printf("==================================================");
  gotoxye(64,10);
  printf("1. TECHNICAL EVENT MANAGEMENT");
  gotoxye(64,12);
  printf("2. NON-TECHNICAL EVENT MANAGEMENT");
  gotoxye(64,14);
  printf("3. GO TO HOME");
	gotoxye(64,16);
	printf("4. EXIT");
	gotoxye(64,19);
	printf("==================================================");
	gotoxye(69,21);
    printf("ENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    	r=1;
        techev();
        break;

    case 2:
    	r=0;
        nontechev();
        break;
    case 3:
        main();
        break;
    case 4:
        exit(1);
	default:
        gotoxye(10,17);
        printf("Invalid Choice.");
	}
}
/*---------------------------------TECHNICAL EVENT SECTION------------------------------*/
void techev()
{
	
	int choice;
  system("cls");
  gotoxye(64,1);
  printf("<----------:WELCOME TO TECHNICAL EVENTS SECTION:---------->");
  gotoxye(64,3);
  printf("===========================================================");
  gotoxye(64,5);
  printf("	      MANAGE TECHNICAL EVENTS DATA");
  gotoxye(64,7);
  printf("===========================================================");
  gotoxye(64,10);
  printf("1. Add Event(s) Details");
  gotoxye(64,12);
  printf("2. Delete Event(s) Details");
  gotoxye(64,14);
  printf("3. Modify Event(s) Details");
  gotoxye(64,16);
  printf("4. Search Event(s) Details");
  gotoxye(64,18);
  printf("5. Display Event(s) Details");
  gotoxye(64,20);
  printf("6. Go Back");
  gotoxye(64,22);
  printf("7. Exit");
  gotoxye(64,24);
  printf("===========================================================");
  gotoxye(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    eadd();
    break;
  case 2:
    edelete();
    break;
  case 3:
    emodify();
    break;
  case 4:
    esearch();
    break;
  case 5:
    eview();
    break;
  case 6:
    eventtype();
    break;
  case 7:
  	exit(1);
  default:
        gotoxye(69,5);
        printf("Invalid Choice.");
  }
    
}
/*----------------------------NON TECHNICAL EVENT-----------------------------*/
void nontechev()
{
		int choice;
  system("cls");
  gotoxye(64,1);
  printf("<----------:WELCOME TO NON TECHNICAL EVENTS SECTION:---------->");
  gotoxye(64,3);
  printf("===========================================================");
  gotoxye(64,5);
  printf("	      MANAGE NON TECHNICAL EVENTS DATA");
  gotoxye(64,7);
  printf("===========================================================");
  gotoxye(64,10);
  printf("1. Add Event(s) Details");
  gotoxye(64,12);
  printf("2. Delete Event(s) Details");
  gotoxye(64,14);
  printf("3. Modify Event(s) Details");
  gotoxye(64,16);
  printf("4. Search Event(s) Details");
  gotoxye(64,18);
  printf("5. Display Event(s) Details");
  gotoxye(64,20);
  printf("6. Go Back");
  gotoxye(64,22);
  printf("7. Exit");
  gotoxye(64,24);
  printf("===========================================================");
  gotoxye(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    eadd();
    break;
  case 2:
    edelete();
    break;
  case 3:
    emodify();
    break;
  case 4:
    esearch();
    break;
  case 5:
    eview();
    break;
  case 6:
    eventtype();
    break;
  case 7:
  	exit(1);
  default:
        gotoxye(69,5);
        printf("Invalid Choice.");
  }
    
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void eadd()
{
    FILE *fp;
    struct event std;
    char another ='y';
    system("cls");
  	if(r==1)
    	fp = fopen("techev.txt","ab+");
	else
		fp = fopen("nontechev.txt","ab+");
	if(fp == NULL){
	        gotoxye(10,5);
    	printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxye(69,3);
        printf("<---------------:ADD EVENT DETAILS:--------------->");
        gotoxye(69,6);
        printf("---------------------------------------------------");
        gotoxye(69,9);
        printf("NAME OF THE EVENT\t: ");
        gets(std.name);
        gotoxye(69,11);
        printf("TIMING[HH:MM]\t: ");
        gets(std.timing);
        gotoxye(69,13);
        fflush(stdin);
        printf("FEE\t\t: ");
       	scanf("%f",&std.fee);
       	fflush(stdin);
       	gotoxye(69,15);
        printf("VENUE\t\t: ");
       	gets(std.location);
        gotoxye(69,17);
        printf("BRANCH\t\t: ");
       	gets(std.branch);
        fflush(stdin);
        gotoxye(69,20);
        printf("---------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      gotoxye(69,22);
        printf("Want to add of another record?");
        gotoxye(69,23);
        printf("if YES enter 'y' ");
        gotoxye(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxye(69,1);
    printf("Press any key to continue.");
    getch();
    if(r==1)
    	techev();
    else
    	nontechev();

}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void eview()
{
	FILE *fp;
    int i=1,j;
    struct event std;
    system("cls");
    gotoxye(69,3);
    printf("< :EVENT VIEW RECORD: >\n");
    gotoxye(29,5);
    printf("----------------------------------------------------------------------------------------------------");
   gotoxye(30,8);
    printf("S.No \t EVENT NAME\t\tEVENT TIMING \t   FEE \t\t VENUE\t\tBRANCHES");
    gotoxye(29,11);
    printf("----------------------------------------------------------------------------------------------------");
     if(r==1)
    	fp = fopen("techev.txt","rb+");
    else
    	fp = fopen("nontechev.txt","rb+");
    if(fp == NULL){
        gotoxye(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxye(31,j);
        printf("%-10d%-24s%-17s%-14f%-18s%-20s",i,std.name,std.timing,std.fee,std.location,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    gotoxye(69,j+3);
    printf("Press any key to continue.");
    getch();
    if(r==1)
    	techev();
    else
    	nontechev();

}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void esearch()
{
	int p=0;
    FILE *fp;
    struct event std;
    char evname[20];
    system("cls");
    gotoxye(69,3);
    printf("< :SEARCH EVENT RECORD: >");
    gotoxye(60,5);
    printf("-----------------------------------------------------");
    gotoxye(69,7);
    printf("Enter Event Name to Search: ");
    fflush(stdin);
    gets(evname);
    if(r==1)
    	fp = fopen("techev.txt","rb+");
    else
    	fp = fopen("nontechev.txt","rb+");
    if(fp == NULL){
        gotoxye(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxye(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(evname),strlwr(std.name)) == 0){
             gotoxye(60,11);
            printf("EVENT NAME\t\t: %s",std.name);
            gotoxye(60,13);
            printf("EVENT TIMING[HH:MM]\t: %s",std.timing);
            gotoxye(60,15);
            printf("FEE\t\t\t: %f",std.fee);
            gotoxye(60,17);
            printf("VENUE\t\t: %s",std.location);
            gotoxye(60,19);
            printf("BRANCH\t\t: %s",std.branch);
            
            p=1;
        }
    }
    fclose(fp);
    gotoxye(69,16);
    if(p==0){
    gotoxye(69,16);
      printf("Sorry, Data Not Found With Name: %s\n",evname);
  	}
      gotoxye(60,21);
            printf("=====================================================");
    gotoxye(69,23);
    printf("Press any key to continue.");
    getch();
   if(r==1)
    	techev();
    else
    	nontechev();

}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void emodify()
{
	int p=0;
    char evname[20];
    FILE *fp;
    struct event std;
    system("cls");
    gotoxye(69,3);
    printf("< :MODIFY EVENT RECORD: >");
    gotoxye(60,5);
    printf("-----------------------------------------------------");
    gotoxye(64,7);
    printf("Enter Event Name to Modify Details: ");
    fflush(stdin);
    gets(evname);
    if(r==1)
    	fp = fopen("techev.txt","rb+");
    else
    	fp = fopen("nontechev.txt","rb+");
    if(fp == NULL){
        gotoxye(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxye(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(evname),strlwr(std.name))== 0){
           p=1;
            gotoxye(60,11);
            printf("EVENT NAME\t\t: ");
            gets(std.name);
            gotoxye(60,13);
            printf("EVENT TIMING[HH:MM]\t: ");
            gets(std.timing);
            gotoxye(60,15);
            printf("FEE\t\t\t: ");
            scanf("%f",&std.fee);
            gotoxye(60,17);
            fflush(stdin);
            printf("VENUE\t\t: ");
            gets(std.location);
            gotoxye(60,19);
            printf("BRANCHES\t\t: ");
            gets(std.branch);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxye(67,15);
    	printf("Event Data Not Found With Name %s",evname);
	}
	gotoxye(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxye(69,23);
    printf("Press any key to continue.");
    getch();
   if(r==1)
    	techev();
    else
    	nontechev();

}
/*--------------------------------------------DELETE------------------------------------------*/
void edelete()
{
	int p=0;
    char evname[20];
    FILE *fp,*ft;
    struct event std;
    system("cls");
    gotoxye(69,3);
    printf("< :DELETE EVENT RECORD: >");
    gotoxye(60,5);
    printf("-----------------------------------------------------");
    gotoxye(69,7);
    printf("Enter Event Name to Delete: ");
    fflush(stdin);
    gets(evname);
    strlwr(evname);
    if(r==1){
    	fp = fopen("techev.txt","rb+");
	    	if(fp == NULL){
	        gotoxye(10,6);
	        printf("Error opening file");
	        exit(1);
		    }
	    ft = fopen("temp.txt","wb+");
		    if(ft == NULL){
		        gotoxye(10,6);
		        printf("Error opening file");
		        exit(1);
		    }
	    while(fread(&std,sizeof(std),1,fp) == 1){
	        if(strcmp(evname,strlwr(std.name))!=0)
	            fwrite(&std,sizeof(std),1,ft);
	        else
	        	p=1;
	    }
	    fclose(fp);
	    fclose(ft);
	    remove("techev.txt");
	    rename("temp.txt","techev.txt");
	    
	}
    else{
    	fp = fopen("nontechev.txt","rb+");
	    	if(fp == NULL){
	        gotoxye(10,6);
	        printf("Error opening file");
	        exit(1);
	    	}
    	ft = fopen("temp1.txt","wb+");
		    if(ft == NULL){
		        gotoxye(10,6);
		        printf("Error opening file");
		        exit(1);
		    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(evname,strlwr(std.name))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        	p=1;
    }
    fclose(fp);
    fclose(ft);
    remove("nontechev.txt");
    rename("temp1.txt","nontechev.txt");

	}
	gotoxye(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxye(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxye(69,14);
        printf("No Event Found With Name:%s",evname);
    }
    gotoxye(60,18);
    printf("=====================================================");
    gotoxye(69,20);
    printf("Press any key to continue.");
    getch();
   if(r==1)
    	techev();
    else
    	nontechev();

}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxye(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

