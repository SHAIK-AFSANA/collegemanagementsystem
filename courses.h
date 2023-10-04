/*-----------COURSEs() PROTOTYPE-----------*/
void coursedetails();
/*-----------GOTOXYC() PROTOTYTPE----------*/
void gotoxyc(int,int);
/*-------------------------------------COURSES SECTION---------------------------------------------------------------*/
void coursedetails()
{
	system("cls");
    gotoxyc(69,1);
    printf("< :HERE ARE OUR PROGRAMS: >");
    gotoxyc(40,3);
    printf("========================================================================================");
    gotoxyc(70,5);
    printf("Bachelor of Technology (B.Tech)");
    gotoxyc(40,7);
    printf("========================================================================================");
    gotoxyc(63,9);
    printf("BRANCH\t\t\t\t\t\t\tFEES\n");
    gotoxyc(40,10);
    printf("----------------------------------------------------------------------------------------");
    gotoxyc(43,12);
    printf("Computer Science and Engineering (CSE)\t\t\t\t\t100000");
    gotoxyc(43,14);
    printf("Computer Science and Engineering - Artificial Intelligence (CSE-AI)\t\t150000");
    gotoxyc(43,16);
    printf("Computer Science and Engineering - Internet of Things (CSE-IOT)\t\t130000");
    gotoxyc(43,18);
    printf("Electronics and Communication Engineering (ECE)\t\t\t\t75000");
    gotoxyc(43,20);
    printf("Electrical and Electronics Engineering (EEE)\t\t\t\t\t50000"); 
    gotoxyc(43,22);
    printf("Civil Engineering\t\t\t\t\t\t\t\t48000");
    gotoxyc(40,24);
    printf("----------------------------------------------------------------------------------------");
    gotoxyc(69,27);
    printf("Press Any Key To Continue");
    getch();
    main();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyc(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
