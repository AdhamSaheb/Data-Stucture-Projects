

void  sortlist(char strings[128][51] )
{int i ;
    int max = 0 ;
    int count =0  ;
    // calculating the number of strings



      for (i=0 ; i<100;i++) {
        if (strings[i][0]!='\0') count ++ ;


      }
// calculating the maximum length of the names
printf("%d\n",count) ;

    for (i=0;i<count;i++){
    if (my_strlen(strings[i])>max)

                    max = my_strlen(strings[i]) ;


    }

    List bucket[27] ; // buckets in the cursor
    struct node cursor[128];

    int y ;
    int key ;
// key is the index of the bucket added to
    createCursor(cursor);
// initializing the cursor
    for (i=0; i<27; i++)
    {
        bucket[i]=cursoralloc(cursor);

    }
    //allocating the buckets



    for(i= (max-2) ; i>=0 ; i--)
    {





        for(y=0 ; y < count ; y++)
        {
            if ( my_strlen(strings[y])< i || strings[y][i]==32 )
            {
                addlast(cursor,bucket[0],strings[y]);

            }
            // if its shorter than the compared index directly add it to the space bucket
            else
            {
                int value = (int)strings[y][i] ;
                if ((value >= 65) && (value<91) )
                    key = abs((65-value))+1;
                else if ((value >= 97 )&& (value<123))
                    key = abs((97-value))+1 ;



                addlast(cursor,bucket[key],strings[y]);


            }
            // getting the key and adding to the needed bucket

        }
        int  temp =0 ;
        int counter ;
        for (counter=0 ; counter<27; counter++)
        {


            position p = cursor[bucket[counter]].next ;

            while ( p )
            {

                my_strcpy(strings[temp], cursor[p].name ) ;


                p = cursor[p].next;
                temp ++ ;

            }
            cursorfree(cursor,p);

        }

        createCursor(cursor) ;
        int j;
        for (j=0; j<27; j++)
        {
            bucket[j]=cursoralloc(cursor);
        }
    }
// emptying the buckets into the array to compare the next letter and allocating the buckets again







}
