#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct employee
{
    int id;
    char name[30];
    float salary;
};

typedef struct employee employee;
employee emp[5];

// * * * * * * * * * * *  * * * * * * * * * * *
void display( int emp_num)
{
    printf("emp id = : %d \n",emp[emp_num].id);
    printf("emp name = : %s \n",emp[emp_num].name);
    printf("emp salary = : %f \n",emp[emp_num].salary);
}

// * * * * * * * * * * *  * * * * * * * * * * *
void add_emp(int emp_num)
{
    printf("please enter emp id :");
    scanf("%d",&emp[emp_num].id);
    printf("please enter emp name :");
    scanf("%s",&emp[emp_num].name);
    printf("please enter emp salary :");
    scanf("%f",&emp[emp_num].salary);
}

// * * * * * * * * * * *  * * * * * * * * * * *
void display_all()
{
    int i=0;
     for(i=0;i<5;i++)
    {
    if(emp[i].id ==0)
    {

    }else
    {
    printf("Employee id = : %d \n",emp[i].id);
    printf("Employee name = : %s \n",emp[i].name);
    printf("Employee salary = : %f \n",emp[i].salary);
    printf(" * * * * * * * * * * *  * * * * * * * * * * * \n");
    }
    }
}

// * * * * * * * * * * *  * * * * * * * * * * *
void remove_emp(int emp_num)
{

    if(emp[emp_num].id ==0)
    {
     printf("No Employee has this num \n");
    }else
    {

    emp[emp_num].id=0;
    //char rname[]={'\0'};
    //emp[emp_num].name=rname;
    //emp[emp_num].salary=0.0;
    printf(" Employee Removed successfully \n");
    }

}

// * * * * * * * * * * *  * * * * * * * * * * *
void edit_emp( int emp_num)
{

    add_emp(emp_num);

}
// * * * * * * * * * * *  * * * * * * * * * * *

void displaynewoptions(int cur2,int emp_num)
{
  int i;
  for(i=0;i<3;i++)
    {
         gotoxy(10,i);

           if(i==cur2)
           {
                SetColor(9);

           }else
           {
               SetColor(15);

           }
           system("cls");
          // printf("%s",newoptions[i]);
           //display(emp_num);
           gotoxy(20,i);
          // getche();



    }
}



int main()
{
    char menu[6][10] ={"New","Display","DisAll" ,"Edit","Remove","Exit"};
    char newoptions[3][10]={"ID","Name","Salary"};
    int i=0,cursor=0,flag=0,emp_num=0,cur2=0;
    char button=' ';

    //print menu
    do{

    system("cls");
    //print menu and color first element
    for(i=0;i<6;i++)
    {
         gotoxy(30,i);

           if(i==cursor)
           {
                SetColor(12);
              //printf("%s",menu[i]);
           }else
           {
               SetColor(15);
             //printf("%s",menu[i]);
           }
        printf("%s",menu[i]);
    }

 //press button
 button=getch();

//check for key type
  if(button >0)    //normal
  {

      if(button== 13)
      {


           switch(cursor)
           {
           case 0:
            system("cls");
             printf("Add New Employee \n where you want to add employee :");
             scanf("%d",&emp_num);

             if(emp[emp_num].id ==0)
             {
                       system("cls");

                        int m;
                        for(m=0;m<3;m++)
                       {
                           gotoxy(10,m);
                           printf(" %s ",newoptions[m]);
                       }



                    gotoxy(20,0);
                    cur2=0;
                    scanf("%d",&emp[emp_num].id);
                   // button=getch();

                    gotoxy(20,1);
                    cur2=1;
                    scanf("%s",&emp[emp_num].name);
                   // button=getch();

                    gotoxy(20,2);
                    cur2=2;
                    scanf("%f",&emp[emp_num].salary);
                   // button=getch();

                   //88888888888888888888888888888

                        // button=getch();

                          switch(button)
                          {

                           case 72:  //up
                               if(cur2 >2)
                               {
                                  cur2=0;
                               }else if(cur2 <=0)
                               {
                                   cur2=2;
                               }
                               else{
                                cur2--;

                               }

                            break;

                            case 80: //down
                                 if(cur2 >=2)
                               {
                                  cur2=0;
                               }else if(cur2 <0)
                               {
                                   cur2=2;
                               }
                               else{
                                cur2++;

                               }

                            break;

                            default:
                                cur2=0;
                                break;


                          }

                  //add_emp(emp_num);

             }else
             {
             printf("sorry this place is occupied \n");
             }

             button=getch();
            break;

            case 1:
                system("cls");
            printf("Display ");
            printf("Display Employee data  \n what is employee num  :");
             scanf("%d",&emp_num);
             if(emp[emp_num].id !=0)
             {
                 //cursor2(cur2,emp_num);
                  display(emp_num);
             }else
             {
             printf("sorry no employee has this num \n");
             }
             button=getch();
            break;

            case 2:
                 system("cls");
                 printf("Display All Employees \n");
                 display_all();
                 button=getch();
            break;

            case 3:
                     system("cls");

            printf("Edit Employee data  \n what is employee num  :");
             scanf("%d",&emp_num);
             if(emp[emp_num].id !=0)
             {
                  edit_emp(emp_num);
             }else
             {
             printf("sorry no employee has this num \n");
             }
             button=getch();
            break;

            case 4:
             system("cls");
             printf("Remove Employee \n Enter employee num :  ");
             scanf("%d",&emp_num);
             remove_emp(emp_num);
             button=getch();
            break;

            case 5:
                // printf("Exit ");
                 system("cls");
                 flag=1;
            break;

            default :
                cursor=0;
           }

      }


  }else    //extended
  {
      button=getch();

      switch(button)
      {

       case 72:  //up
           if(cursor >5)
           {
              cursor=0;
           }else if(cursor <=0)
           {
               cursor=5;
           }
           else{
            cursor--;

           }



        break;

        case 80: //down
             if(cursor >=5)
           {
              cursor=0;
           }else if(cursor <0)
           {
               cursor=5;
           }
           else{
            cursor++;

           }

        break;

        case 71:
            cursor=0;  //home

        break;

        case 79:  //end
            cursor=2;
            flag=1;

        break;

        default:
            cursor=0;


      }
      }


     } while(flag !=1);




    return 0;

    }


