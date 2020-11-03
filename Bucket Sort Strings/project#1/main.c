#include <stdio.h>
#include <stdlib.h>
#include "myhead.h"
#include<math.h>
#include<string.h>
#include  "radix.h"



int main()
{

    char strings[100][51] ;
    int number ;
    int i ;
    int maxLength ;
    // max length is the longest name length
    int input ;
    // the menu input


    for (i=0;i<100;i++)
        strings[i][0] = '\0' ;

        //initializing the array to be able to count the added names later

// location to return to instead of writing the menu in each case
Location :
    // showmassage shows the menu
    showmassage() ;

    scanf("%d",&input);
    while (input - 9) // same as while input != 9
    {


//============================================================================
        if (input==1 )
        {
            FILE * file ;
            char filename[10] ;

            puts("Type in the name of the file to be read : ") ;

            gets(filename);
            gets(filename);

            printf("reading %s ......  \n",filename);


            file = fopen(filename,"r") ;


            char s[50] ;

            i = 0 ;





            while( fgets(s,51,file ) != NULL  )
            {




                del(s); // del delets the added \n by the fgets function
                //addspaces(s);
                my_strcpy(strings[i],s);


                i++ ;

            }
            // reading names and adding them to the array

            number = i ;
            // number is the number of strings


            printf("file : %s successfully read \n",filename);
            printf("number of names is %d\n ",number) ;




        }
        //==========================================================================//
        else if (input ==3 )
        {

            puts("Type in the name to be  added ");
            char  name[51] ;

            gets(name);
            gets(name);

            strcpy(strings[number],name) ;


            printf("%s was added to the list :) \n ", name  ) ;
            number ++ ;
            printf("the number of names now is %d\n",number )  ;
            sortlist(strings) ;





        }
//just adding a name to the array and sorting it again
        // ===================================
        else if (input ==2 )
        {

            sortlist(strings) ;
            puts("Names have been sorted ;) ");
// sortlist is the radix sort
        }

        //=============================================//

        else if (input==5)
        {
            sortlist(strings) ;
            int temp = 65 ;
            int last =0 ;

            while ( last < number)
            {

                printf("\t%c : \n\n",temp);
                for (i =last ; i < number ; i++ )
                {

                    if (     ((strings[i][0]==temp) ||    (strings[i][0] == (temp+32)))  ||  (strings[i][0]== (temp-32))  )
                    {
                        printf("%s\n",strings[i]);

                        last ++ ;
                    }
                    else
                        break ;

                }
                temp = strings[i][0];
            }
        }
        // writing the sorted names as an alphabetical list
        //========================================================//

        else if (input==6)
        {
            clrscr() ;
            // clearing the screen

        }
        //===============================================================//
        else if (input==4)
        {
            FILE * outfile ;
            char filename[10] ;

            puts("what do you want your file to be named ? ") ;
            gets(filename) ;
            gets(filename) ;
            outfile = fopen(filename,"w") ;
            sortlist(strings) ;
            int temp = 65 ;
            int last =0 ;

            while ( last < number)
            {

                fprintf(outfile,"\t%c : \n\n",temp);
                for (i =last ; i < number ; i++ )
                {

                    if (     ((strings[i][0]==temp) ||    (strings[i][0] == (temp+32)))  ||  (strings[i][0]== (temp-32))  )
                    {
                        fprintf(outfile,"%s\n",strings[i]);

                        last ++ ;
                    }
                    else
                        break ;

                }
                temp = strings[i][0];




            }


            fclose(outfile) ;
            printf("Names have been successfully written on %s\n",filename);

        }
        // same as case 5 but with fprintf
        //============================

        else if (input==7) {
                char character ;
                printf("Enter the letter : \n") ;
        scanf( "%c",&character) ;
        scanf( "%c",&character) ;
        int i ;
        for (i=0;i<number;i++) {
            if (  strings[i][0] == character )
                puts(strings[i]) ;


        }



        }
        //===========================


        else if (input==8) {
                sortlist(strings) ;
                char name[50] ;
                printf("Enter the Name : \n") ;
        gets(name) ;
        gets(name) ;

        int i =0;
        while (i<number){

            if (  strcmp(strings[i] , name ) == 0 )
            {

printf( "name %s is at position %d in the sorted list \n", name , i+1) ;
break ;
            }
i ++ ;

        }
        if ( i == number)
            puts("not found !") ;



        }
        //===============================

        else if ((input >9) || (input<1) )
        {
            puts("please enter a valid input :) ") ;



        }
//=====================================================
        goto Location ;
    }


    puts("\t\t\t-------------------------------Thank you :) ----------------------\n"
         "\t\t\t--------------------------------ByeBye ---------------------------");




    return 0 ;

}

















