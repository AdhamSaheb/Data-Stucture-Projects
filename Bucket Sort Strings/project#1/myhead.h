// this header file contains utility functions and cursor functions



typedef int ptr ;
typedef int position ;
typedef int List ;

typedef struct node
{

    char name[50] ;

    ptr next ;


};
//=================================================================


void createCursor( struct node cursor[128] )
{


    int i  ;
    for (i = 0 ; i<127 ; i++ )
    {
        cursor[i].next = i+1 ;

    }

    cursor[127].next = 0;

}





void my_strcpy(char* dest, char* src )
{


    unsigned i;
    for (i=0; src[i] != '\0'; i++)
        dest[i] = src[i];


    dest[i]= '\0';
}
int my_strlen (char *a)
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    return i;
}
// del removes the \n added by fgetss
void del(char a[51])

{
    int i =0 ;
    while (i<my_strlen(a))
    {
        if (a[i]=='\n')
            a[i]= '\0';
        i++;
    }
}
 // unused function
void addspaces (char  s[51] )
{
    int t ;
    for (t=my_strlen(s); t<50; t++)
        s[t]= ' ' ;

    s[50] = 0;

}

void showmassage()
{

    printf(
        "\t\t\t\t\t*|1. Read names from a file               *|\n"
        "\t\t\t\t\t*|2. Sort the names Alphabetically        *|\n"
        "\t\t\t\t\t*|3. Add a name to the list               *|\n"
        "\t\t\t\t\t*|4. Write the names to a file            *|\n"
        "\t\t\t\t\t*|5. Write the names to the screen        *|\n"
        "\t\t\t\t\t*|6. Clear Screen                         *|\n"
        "\t\t\t\t\t*|7. Find names staring with a character  *|\n"
        "\t\t\t\t\t*|8. Find a specific name in the list     *|\n"
        "\t\t\t\t\t*|9. Exit                                 *|\n"
        "\t\t\t\t\t -------------------------------------------\n ") ;


}






void clrscr()
{
    system("cls");
}

ptr cursoralloc( struct node cursor[128])
{
    position p ;
    p=cursor[0].next ;
    cursor[0].next = cursor[p].next ;
    cursor[p].next = 0 ;
    return p ;

}



void addfirst (struct node cursor[128],List L, char s[51] )
{

    position temp = cursoralloc(cursor);
    my_strcpy(cursor[temp].name,s ) ;

    cursor[temp].next = cursor[L].next;
    cursor[L].next = temp ;

}

void cursorfree(struct node cursor[128],position p )
{

    cursor[p].next = cursor[0].next ;
    cursor[0].next = p ;


}
void addlast (struct node cursor[128],List L, char s[51])
{
    position temp, p ;

    temp = cursoralloc(cursor) ;
    my_strcpy(cursor[temp].name,s ) ;
    p = L;


    while (cursor[p].next != 0 )
        p = cursor[p].next ;


    cursor[p].next=temp ;



}
// prints a list in the cursor
void printlist (struct node cursor[128],List a )
{
    position p ;
    p = cursor[a].next ;
    while (p!=0 )
    {
        puts(cursor[p].name) ;
        p = cursor[p].next ;




    }


}
int  isempty(struct node cursor[128],List a )
{
    if (cursor[a].next ==0)
    {
        return 1 ;
    }
    else
        return 0 ;
}


int my_strcmp (char * st1, char* st2) {
    int i ;


    for ( i = 0; ; i++)
    {
        if (st1[i] != st2[i])
        {
            return st1[i] < st2[i] ? -1 : 1;
        }

        if (st1[i] == '\0')
        {
            return 0;
        }
    }

}


