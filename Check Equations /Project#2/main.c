#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "myhead.h"
#include"utilities.h"
#include"functions.h"


int main()
{


    int num ; // num and n and just counter//
    int n ;
    int number =0 ; // number of expressions in the file , used to create the arrays//

//======================//
// whats needed for reading the file
    char filename[10] ;
    char filename2[10] ;
    char s[50] ;
    FILE * file ;
//==========================//
    printf("Hello , First , enter the name of the file to be read \n") ;
    scanf("%s",filename) ;


    file = fopen(filename,"r") ;

    strcpy(filename2,filename) ;



    while( fgets(s,50,file ) != NULL  )
    {

        number ++  ;

    }
// getting the name of the file and counting the number of lines



    // the arrays needed for the equations
    char  equations[number][50];
    char  eq[number*2][50] ;
    //===============================================//
    printf("number of Expressions is %d\n",number) ;



// defining a location to return to after the switch
location :
    showMassage() ;
    scanf("%d",&n) ;


    while (n-8)
    {


        switch(n)
        {
        //=================================================================//
        case 1 :
        {




            file = fopen(filename2,"r") ; // returning the pointer to the start of the file

            int  i = 0 ;


            while( fgets(s,50,file ) != NULL  )
            {

                strcpy(equations[i],s) ;
                i ++ ;
            }
// moving the expressions to the array

            int j ;
            printf("Expressions : \n\n") ;
            for (j=0; j<number; j++)

                printf(" Expression  -> %d :  %s \n",j+1, equations[j] ) ;


            num =0 ;
            char *token;

            i = 0 ;

            for (num=0; num<number; num ++ )
            {
                token = strtok(equations[num],"=") ;
                strcpy(eq[i],token) ;

                token = strtok(NULL, "\n");
                strcpy(eq[i+1],token) ;
                i +=2 ;


            }
            printf( "Equations : \n\n" );
// splitting the expressions to the left and right side
            for (i=0; i<number*2; i++ )
                printf("Equation %d --- >  %s\n",i+1,eq[i]) ;
            break ;
        }

//=======================================================================//

        case 2 :
        {

            num =0;
            for (num=0; num<number*2 ; num ++ )
            {


                if ( checkbrackets(eq[num]) && checkeq(eq[num]) )
                {
                    char result[25] ;
                    strcpy(result,"") ;
                    intopost(eq[num],result) ;

                    printf("EQ%d) - > %s - >  Valid ", num +1, eq[num]) ;
                    printf( " Postfix : %s ", result ) ;
                    printf(" Answer : %f\n\n ",evalute(result) ) ;
                }

                else
                    printf("EQ%d) -> %s --> invalid \n\n ", num+1, eq[num] );

            }

            // if valid print result if not print invalid

            printf("\n") ;
            printf("\t\t\t\t\t Select The Next Operation to be done : \n" ) ;
            break ;

        }
//=================================================================//
        case 3 :
        {
// checking if the left side of the equation is equal to the right one

            for ( num=0 ; num<number*2 ; num +=2 )
            {
                char RS[50] ;
                char LS[50] ;
                strcpy(RS, "") ;
                strcpy(LS, "") ;
                // each expression is split into 2 equations in a row in the eq array
                if (  (checkeq(eq[num]) &&  checkbrackets(eq[num]))  && (checkbrackets(eq[num+1]) && checkeq(eq[num+1]))  )
                {


                    intopost(eq[num],RS)  ;


                    intopost(eq[num+1],LS)  ;
                    double ans1 = evalute(RS) ;

                    double ans2= evalute(LS) ;

                    if (ans1 == ans2)
                        printf(" Expression  -> %d -- > [ %s = %3f ] =? [ %s =%3f ]  --- >  True \n\n ", (num/2)+1,RS,ans1, LS,ans2   ) ;
                    else

                        printf(" Expression %d ->[ %s = %f ] =? [%s = %f ]  --- >  False \n\n ",(num/2)+1, RS, ans1, LS, ans2  ) ;


                }







            }
            printf("\t\t\t\t\t Select The Next Operation to be done : \n" ) ;
            break ;

        }
//===================================================================//
        case  5  :
        {
            system("cls") ;
// clearing the console
            break ;
        }

//======================================================================//
        case 4 :
        {

// repeating the same steps of case 2 but in a file

            FILE * outfile ;
            char filename[10] ;

            puts("what do you want your file to be named ? ") ;
            gets(filename) ;
            gets(filename) ;
            outfile = fopen(filename,"w") ;










            for (num=0; num<number*2 ; num ++ )
            {
                char result[25] ;
                strcpy(result,"\0") ;






                if (checkbrackets(eq[num]) && checkeq(eq[num]))
                {
                    intopost(eq[num],result) ;
                    fprintf(outfile,"EQ%d) -> %s --> valid --> postfix : %s --> result : %f \n\n", num+1,eq[num],result,evalute(result));

                }
                else
                    fprintf(outfile,"EQ%d) -> %s --> invalid \n\n ", num+1,eq[num]);


            }
            fprintf(outfile, "\n") ;

            fclose(outfile) ;
            printf("Equations have been successfully written on file\n\n");
            break ;


        }

//========================================================================//
        case 6 :
        {
            // getting an expression from the user and converting it with intopost
            char expression[50] ;
            char result2[50] ;
            strcpy(result2,"\0") ;

            printf( " Enter the expression \n") ;

            gets(expression) ;
            gets(expression) ;

            if (checkbrackets(expression) && checkeq(expression))
            {
                intopost(expression,result2 ) ;
                printf("The result is : %s\n", result2 ) ;



            }

            else
            {


                puts("invalid expression!\n") ;
            }
            break ;
        }
//=======================================================================//
        case 7 :
        {

            // evaluating an equation from the user
            char expression2[20] ;

            printf("Enter the postfix expression \n") ;
            gets(expression2) ;
            gets(expression2) ;
            printf("result is  :  %f \n",evalute(expression2)) ;
            break ;



        }


//========================================================================//
        default :
            puts("please enter a valid input :) ") ;


        }




        goto location ;

    }
    printf("\t\t\t-------------------------------------BYE BYE -------------------------------- \n\n\n") ;


}











