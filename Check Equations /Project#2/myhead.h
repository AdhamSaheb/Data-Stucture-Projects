


double stack[50]   ;
int top = -1;

// this header file includes simple functions such as pop and push and so


int isoperation(char a) {
    switch (a) {
    case '+' : return 1 ;

    case '*' : return 1 ;
  case '/' : return 1 ;
    default : return 0 ;

    }

}
int isoperation2(char *a) {
    // used to know if a split token is an operation

     if (strcmp(a,"+")==0)       return 1 ;
     else if (strcmp(a,"-")==0)  return 1 ;
     else if (strcmp(a,"*")==0)  return 1 ;
     else if (strcmp(a,"/")==0)  return 1 ;

    else return 0 ;



}



int precedence (char operation ) {
    int priority ;
    // the precedence of the operations function

switch (operation){
    case '+' : {priority =1 ; break ; }
      case '-' : {priority =1 ; break ; }
        case '*' : {priority =2 ; break ; }
          case '/' : {priority =2 ; break ; }
            case '(' : {priority =0 ; break ; }
              case '[' : {priority =0 ; break ; }


}
return priority ;

}
void push(double  x)
{
    stack[++top] = x;
}

double pop()
{
    if(top == -1)
        return -1 ;
    else
        return stack[top--];

}

void append (char *s , char p ) {
    int len = strlen(s) ;
       s[len]=p;
        s[len+1]='\0';


}
// used to append a character to a string

int isunary ( char *s , int i ) {

    if ( i == 0 && isdigit(s[1])) return 1 ;

    if (isoperation(s[i-1]) && isdigit(s[i+1])) return 1 ;

    if (s[i-1]== '(' && isdigit( s[i+1] ) ) return 1 ;
    if ( s[i-1] == '-' && isdigit(s[i+1])) return 1 ;


        else return 0;




}
// checks if the - is unary or an operation

