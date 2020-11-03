struct node3
{

	int status;
	/*
	 * status= 0 : this index is free to insert in
	 * status = 1 : there is data in this index
	 * status = 2 : data was present at least once
	*/
	int rank ;
	char  name[20] ;
	double population  ;

};
typedef struct node3 hashitem ;
// the struct above is for the item stored in the hashtable ;
// the struct below is a struct for the table iteself ;
struct node4 {

int size ;
int capacity ;
hashitem * array ;



};
typedef struct node4* hashtable ;


//hashcode is the function used to give index H(x)
long long hashcode(char *name , int size )
{

  long long sum =0 ;
  while ( *name != '\0' )

    sum = (sum << 5 ) + *name++ ;

    return abs (sum%size) ;


}
//==============
hashtable createtable (int number ) {

int index = getprime(number) ;

hashtable table = (hashtable)malloc(sizeof(struct node4)) ;
table->size = 0 ;
table->capacity = index ;
table->array = (hashitem*) malloc (sizeof (hashitem)*index);


return table ;
}
//==============
void initializetable (hashtable table ) { // setting all status variables to "available "
    int i ;
    for (i=0 ; i<table->capacity ; i++)
    {
        table->array[i].status = 0 ;

    }

}
//=============



int tablesize( hashtable table ) {


return table->size ; // returns the size of the table (how many cities )

}

//=================//function to insert in a hashtable

hashitem* table_insert ( hashtable table  ,   city c   ){
    int number = tablesize(table) ;

    int temp2 = getprime (number+1 ) ;
// if no rehashing is needed
if (temp2 <= table->capacity ) {

int index = hashcode(c->name,table->capacity) ;
int h = 1 ;
// going through the table until an empty index is found
       while (table->array[index].status == 1)
        {

		index = (index + (h * h)) % (table->capacity); // this is the quadratic brobing rule
		h++;

	     }

strcpy(table->array[index].name , c->name )  ; // moving the elements to the index
table->array[index].population = c->population  ;
table->array[index].rank = c->rank  ;
table->array[index].status = 1 ;
table->size ++ ; // increasing the size of the table by one (one more city added )
return table ;

}
else {

hashtable newtable = createtable((table->size )+1) ; // here we have to rehash the table because the new size has a new next prime
initializetable(newtable); // initialize the new table
int i ;
for (i=0;i<table->capacity;i++) { //moving the old elements of the table to the new one
if (table-> array[i].status==1) {
     int index = hashcode(table->array[i].name , newtable->capacity) ;
     int h = 1 ;
// going through the table until an empty index is found
       while (newtable->array[index].status == 1)
        {

		index = (index + (h * h)) % (newtable->capacity); // getting the new index to the old elements based on hashtable and quadratic probign
		h++;

        }
        // moving the elements of the city to its new index

strcpy(newtable->array[index].name , table->array[i].name) ;
newtable->array[index].population = table->array[i].population;
newtable->array[index].rank = table->array[i].rank;

newtable->array[index].status = 1 ;
}

}
// moving the members of the old table to the new one
// creating a new hashable city

int index = hashcode(c->name,newtable->capacity) ;
int h = 1 ;
// going through the table until an empty index is found
       while (newtable->array[index].status == 1)
        {

		index = (index + (h * h)) % newtable->capacity;
		h++;

	}
strcpy(newtable->array[index].name , c->name )  ;
newtable->array[index].population = c->population  ;
newtable->array[index].rank = c->rank  ;
newtable->array[index].status = 1 ;
newtable->size = table->size +1  ;
free(table) ;
return newtable ;

}// adding the new member



}


// the next function is used to remove a city from the hash table


hashtable table_remove (hashtable table , char * c  ) {

int index = hashcode(c,table->capacity) ;
int temp = index ;
// trying to find the element based on H(x)
int h = 1 ;
while (table->array[index].status !=0 ){
    if (table->array[index].status == 1 && (strcmp(c , table->array[index].name) ==0  ) ) {
            // case where data exists at the location and its key matches to the given key
			table->array[index].status = 2;
			table->array[index].rank = 0  ;
            table->array[index].population = 0  ;

			table->size -- ;
            return table ;

    }

    index = (index + (h * h)) % table->capacity ;
		h++;
if (index == temp)
                {
			break;
		}

}

puts("No such element in the table ") ;



}
// ==================

// the following function is a function used to print out the hashtable
void print_table (hashtable table )  {
 printf( "Table size : %d \n" , table->size ) ;
 printf( "Table Maximum index : %d\n" , table->capacity) ;
 int  i ;
 printf("Rank\t   Name\t   Tourists(M)\n");
 puts("================================================");
 for ( i=0 ; i < table->capacity ; i ++ ) {
    if (table->array[i].status == 1 )// if there is data in this index
    {

        printf("%d\t%s\t%f\n" , table->array[i].rank ,table->array[i].name,table->array[i].population ) ;
        puts("---------------------------------") ;

    }
    else puts("EMPTY INDEX");
    puts("---------------------------------") ;

 }



}
