int maximum(int a, int b)
{
    return (a > b)? a : b;
}
 // return a maximum of 2 intergers

int is_prime(int n ){

    int i ;
    int flag =0 ;

 for(i=2; i<=n/2; ++i)
    {
        // condition for nonprime number
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0){
        return  1 ;
    }
    else
       return 0  ;


}
// get prime and is prime are functions to get the first prime number after n*2 number of elements
int getprime (int n ) {

    int a = n*2 ;
    int i ;

   for(i=a+1 ; i<a*2;i++){


    if(is_prime(i) && i!=1 ){

        return i ;
    }
   }

    return 0;
}
//=================================//
void showMassage () {



    printf(


        "\t\t                    |1. Get the cities and the countries from the file       \n"
        "\t\t                    |2. Print the cities in a Hashtable                      \n"
        "\t\t                    |3. Insert a new city to the hashtable                   \n"
        "\t\t                    |4. Delete a city from the hashtable                     \n"
        "\t\t                    |5. Write the table to a file                            \n"
        "\t\t                    |6. Print The Countries sorted (inoder)                  \n"
        "\t\t                    |7. Delete a country                                     \n"
        "\t\t                    |8. Exit                                                 \n"


);


}
