
// checkeq is a function that checks if the equation is valid along side checkbrackets and it has various cases that are wrong
int checkeq(char *s)
 {
    int validity =1 ;
    if  ( ((s[strlen(s)-1] == '(') || (isoperation(s[strlen(s)-1] ))) ||  (s[strlen(s)-1] == '[' ||s[strlen(s)-1] == '-'  ) )
            validity =0 ;

    if ( s[0]== ')' || isoperation(s[0]))
    {
        validity =  0 ;

    }
    else if (s[0]=='-' && !isunary(s,0) )
         validity =  0 ;


    else {
    int i ;

    for (i=0 ; i<strlen(s) ; i++)
    {
        if (isdigit(s[i]))
        {
            if (  (s[i+1]=='(' || s[i+1] == '[') )
            {
                validity =  0 ;
                break ;


            }

        }
        else if (isoperation(s[i]))
        {
            if ( isoperation(s[i+1]) || s[i+1]==')'  || s[i+1] ==']')
            {
                validity =  0 ;
                break ;

            }


        }
        else if (s[i]=='(')
        {

            if (isoperation(s[i+1]) ||   (s[i+1]==']'||s[i+1]==')'))
            {
                validity =  0 ;
                break ;

            }
        }
        else if (s[i]==')')
        {
            if (isdigit(s[i+1])  ||  ( s[i+1] == '(' ||  s[i+1]== '[') )
            {
                validity =  0 ;
                break ;

            }
        }
         else if (s[i]==']')
        {
            if (isdigit(s[i+1])  || ( s[i+1] == '(' ||  s[i+1]== '['))
            {
                validity =  0 ;
                break ;

            }
        }

 else if (s[i]=='[')
        {

            if (isoperation(s[i+1]) ||  (s[i+1]==']'||s[i+1]==')')){
                validity =  0 ;
                break ;
            }
            }
        }



    }


return validity ;

}
void showMassage () {



    printf(


        "\t\t                    |1. Get the expressions and the equations from the file  \n"
        "\t\t                    |2. Distinguish the invalid equations                    \n"
        "\t\t                    |3. Check the valid equations in expressions             \n"
        "\t\t                    |4. Write the Equations to a file                        \n"
        "\t\t                    |5. Clear Screen                                         \n"
        "\t\t                    |6. Postfix Converter                                    \n"
        "\t\t                    |7. Postfix Calculator                                   \n"
        "\t\t                    |8. Exit                                                 \n"


);


}





