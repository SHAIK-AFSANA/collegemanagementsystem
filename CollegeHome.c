#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "staff.h"
#include "student.h"
#include "courses.h"
#include "attendance.h"
#include "grading.h"
#include "hostel.h"
#include "placement.h"
#include "transport.h"
#include "event.h"
/*-----------GOTOXY() PROTOTYTPE----------*/
void gotoxy(int,int);
/*-------------------------MAIN FUNCTION HOME PAGE---------------------------------*/
int main()
{
    int choice;
  system("cls");
  gotoxy(69,1);
  printf("<-----COLLEGE MANAGEMENT SYSTEM----->");
  gotoxy(50,3);
  printf("=========================================================================");
  gotoxy(67,5);
  printf("EXPLORE DIFFERENT SECTIONS OF COLLEGE");
  gotoxy(50,7);
  printf("=========================================================================");
  gotoxy(65,9);
  printf("1. STUDENT(s) DATA SECTION");
  gotoxy(65,11);
  printf("2. COURSES PROVIDED");
  gotoxy(65,13);
  printf("3. STAFF DATA SECTION");
  gotoxy(65,15);
  printf("4. HOSTEL DATA SECTION");
  gotoxy(65,17);
  printf("5. TRANSPORTATION SECTION");
  gotoxy(65,19);
  printf("6. PLACEMENT SECTION");
  gotoxy(65,21);
  printf("7. EVENT MANAGEMENT SECTION");
  gotoxy(65,23);
  printf("8. STUDENT ATTENDANCE SECTION");
  gotoxy(65,25);
  printf("9. STUDENT GRADING SECTION");
  gotoxy(65,27);
  printf("10. Exit");
  gotoxy(50,29);
  printf("=========================================================================");
  gotoxy(69,32);
  printf("ENTER YOUR CHOICE:");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
    case 1:
    	//STUDENTS SECTION
        studentmenu();
        break;
    case 2:
    	//COURSE DETAILS
        coursedetails();
        break;
    case 3:
    	//STAFF SECTION
        staffmenu();
        break;
    case 4:
    	//HOSTEL SECTION
        hmenu();
        break;
    case 5:
    	//TRANSPORTATION SECTION
        tmenu();
        break;
    case 6:
    	//PLACEMENT SECTION
        cmenu();
        break;
    case 7:
    	//EVENT SECTION
        eventtype();
        break; 
    case 8:
    	//ATTENDANCE
        atmenu();
        break;  
	case 9:
		//GRADING
        gmenu();
        break;  
    case 10:
        exit(0);
        break;
    default:
          gotoxy(69,5);
          printf("Invalid Choice.");
  }
}

/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
