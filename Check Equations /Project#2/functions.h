
//========================================//
char if_closed(char ch )
{
    if(ch == ']')
        return '[' ;
    if(ch == ')')
        return '(' ;

}
// the previous function checks if the right type of bracket was popped from the stack in checkbrackets//

//=============================//
void intopost( char *s, char  *result ){
// this is the function that coverts to postfix following the original rules//

    double  temp ;
 // this will be the unary - so it has to be appended (the equation will be checked if valid first)//
    if (s[0]=='-')
        append(result,s[0])  ;
    else if (s[0]=='(')
        push(s[0]) ;
    else
        append(result,s[0]) ;


    int i = 1 ;

    while ( s[i] != '\0')
    {

        if(isalnum(s[i]))
        {


            append(result,s[i]);



        }


        //========================================================//
        else if(s[i] == '(')
        {
            push(s[i]);


        }
        // =========================================================//
        else if(s[i] == '[')
        {
            push(s[i]);


        }
        //===========================================================//
        else if(s[i] == ')')
        {
            while( ( temp= pop() )  != '(')
            {
                append(result,',');
                append(result,(char)(temp));


            }


        }


        // ==========================================================//
        else if(s[i] == ']')
        {
            while( ( temp= pop() )  != '[')
            {
                append(result,',');
                append(result,(char)(temp));
            }

        }

        //===========================================================//


        else if (s[i]== '-' && isunary(s,i))
        {

            append(result,s[i])  ;
        }

        //===========================================================//
        else

        {

            append(result,',');



            while(1)
            {

                if(precedence(stack[top]) >= precedence(s[i]) && top != -1 )
                {

                    append(result, (char ) (pop()));
                    append(result,',');


                }

                else
                {
                    break ;
                }



            }

            push(s[i]);


        }


// ============================================================//


        i ++ ;

    }
// after last operation is pushed //

    while(top != -1)
    {
        append(result,',');
        append(result,(char)(pop())) ;


    }


}

double evalute (char *expressiont)
{
    char  expression[50] ;
    strcpy(expression,expressiont); // making a copy of the string to split so that i dont lost it

    char *token ;
    token = strtok(expression,",") ;




    while (token != NULL )
    {


        if ( !isoperation2(token) )
        {

            push ( atof(token) );

        }

        else if ( isoperation2(token) )
        {

            double l1  = pop();

            double l2 = pop() ;



            double l3 ;


            if (strcmp(token,"+")==0)


                l3 = l2 + l1 ;


            else if (strcmp(token,"-")==0)

                l3 = l2 - l1;


            else if (strcmp(token,"*")==0)

                l3 = l2* l1;


            else if (strcmp(token,"/")==0)
            {

                l3 =( l2 / l1 );
                 if (l1 == 0 ) {

                    printf("(division by zero)\n") ;
                    top  = -1 ;
                    // to embty the stack2
                    return  0 ;


                 }




            }



            push(l3);





        }

        token = strtok(NULL,",") ;

    }








    return pop() ;




}




int checkbrackets (char *s)
{
    // checking if the equation has the right number of brackets and closed properly
    int i =0 ;
    while ( i<strlen(s) )
    {
        if (s[i]=='(' || s[i]=='[')
            push(s[i]);
        else if (s[i]==')' || s[i] == ']' )
        {

            int a =   pop() ;

            if (a!=if_closed(s[i]))
            {
                return 0 ;

            }


        }
        i++ ;
    }
    if (top==-1)
        return 1 ;
    else
        return 0 ;
}










