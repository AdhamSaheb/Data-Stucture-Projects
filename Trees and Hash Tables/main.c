#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include "utility.h"
#include "tree.h"
#include "hashtable.h"


int main()
{
    int citiesnumber ;




    Tree T = NULL ;
    hashtable table ;
    int n ;
    location :
    showMassage() ;
    scanf("%d",&n) ;



    while (n-8)
    {


        switch(n)
        {
        //=================================================================//
        case 1 :
        {   table = createtable(1) ; // creating a table
            initializetable(table);

            // whats needed for reading the file
            char filename[10] ;
            char s[50] ;
            FILE * file ;
            char  *token;
            char  tokens[4][15] ;
//==========================//


            printf("Enter the name of the file to be read \n") ;
            scanf("%s",filename) ;
            file = fopen(filename,"r") ;
// we will read the line , cut it to country city and number
            while( fgets(s,50,file ) != NULL  )
            {

                token = strtok( s, "*\n") ;
                strcpy( tokens[0], token ) ;
                int i = 1 ;

                while (token != NULL && i<4)
                {

                    token =  strtok(NULL, "*\n") ;

                    strcpy( tokens[i], token ) ;
                    i++ ;

                }
                // we have the node with us , if it exists we only add the city if not we insert it

                country c = find(T, tokens[2]) ;
                if (c!=NULL)
                { // if there is a matching country
                    addFirst(c->cities,atof(tokens[3]),atoi(tokens[0]),tokens[1]) ;
                    c->total += atof(tokens[3]) ; // adding the number of tourists to the country
                  table =   table_insert(table , c->cities->next) ; // inserting the city to the hash table

                }
                else
                {

                    T = insert(T,tokens[2]) ; // inserting the country to the tree if it does not exist
                    c = find(T, tokens[2])  ; // finding the country in the tree so we could edit its cities list
                    c->cities = (city)malloc(sizeof(struct node) ) ;
                    c->cities->next = NULL;

                    addFirst(c->cities,atof(tokens[3]),atoi(tokens[0]),tokens[1]) ; // inserting the city to the country node
                    c->total += atof(tokens[3]) ;
                   table = table_insert(table , c->cities->next) ; // inserting the city to the hash table

                }

            }

            citiesnumber = numofcities(T) ; // storing how many cities we initally have





            break ;
        }



//========================================================================//
case 2 : {

print_table(table) ;

break ;
}
//========================================================================//

case 3 : {
    char name[10] ;
    int rank ;
    char h[5] ;
    double number ;
    int trash ;
// reading the data of the city from the user then inserting it into the table
printf("Enter city name\n ") ;

scanf("%s" , name) ;


printf("Now enter its Rank \n") ;

scanf("%d" , &rank) ;



printf("Now enter its Tourist Number \n") ;
gets(h) ;
gets(h) ;

number = atof(h);


city temp = (city) malloc (sizeof (struct node)) ;
strcpy(temp->name,name);
temp->rank = rank ;
temp->population = number ; // moving the elements read to the elements of the node .
temp->next = NULL ;
table = table_insert(table,temp) ; // inserting the node to the table
puts("Succefully Added");
break ;
}
//========================================================================//
case 4 : {
    // getting the name of the city to be deleted
char  name[10] ;
puts( "Enter to be deleted city name") ;
gets(name) ;
gets(name) ;
table = table_remove(table , name) ; // using the normal table delete function
puts("Deleted") ;
break ;


}
//========================================================================//
case 5 : {
 FILE *outfile ;
char filename[10] ;
puts("Enter the name of the file ") ;
gets(filename) ;
gets(filename) ;
outfile = fopen(filename,"w") ; // getting the name of the file that the user wants to write on
// next , i will just  copy the function of printtable but to the file ...
 fprintf(outfile, "Table size : %d \n" , table->size ) ;
 fprintf(outfile, "Table Maximum index : %d\n" , table->capacity) ;
 int  i ;
 fprintf(outfile,"Rank\t   Name\t   Tourists(M)\n");
 fprintf(outfile,"================================================\n");
 for ( i=0 ; i < table->capacity ; i ++ ) {
    if (table->array[i].status == 1 )// if there is data in this index
    {

        fprintf(outfile,"%d\t%s\t%f\n" , table->array[i].rank ,table->array[i].name,table->array[i].population ) ;
        fprintf(outfile,"---------------------------------\n") ;

    }
    else {fprintf(outfile,"EMPTY INDEX\n");
    fprintf(outfile,"---------------------------------\n") ;

 }



}
fclose(outfile) ;
break ;
}
//========================================================================//
case 6 : {
    inOrder(T) ; // printing the tree inorder will print it sorted
    break ;
}
//========================================================================//
case 7 : {
    char name [10] ;
    char answer ;
puts ("Enter the Country you want to delete from the Tree") ;

gets(name) ;
gets (name ) ;
puts("Are you sure you want to delete this country and all of its cities ? (Y/N) ") ;
scanf("%c" , &answer) ; // asking the user if he really wants to delete the whole tree
if (answer == 'Y' ||answer == 'y' ) {
T = delete_node(T,name) ; // deleting the node
puts("Deleted");
}
else
    puts("Not deleted");

    break ;
}
//===================================================
        default :
        { // any other input
            puts("please enter a valid input :) ") ;
            break ;
        }

        }

        goto location ; // go back to the label


    }
    puts ("GoodBye") ;


    return 0 ;

}
