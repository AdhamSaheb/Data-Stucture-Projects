typedef struct node * ptr ;
struct node {
int rank ;
char name[20] ;
double population ;
ptr next ;

};
typedef struct node * city ;

// struct for the city
//======================
typedef struct node2 * ptr2 ;
struct node2  {
int height;
char cname[20] ;
double total ;
ptr2 left ;
ptr2 right ;
city cities ;

};
typedef struct node2 * country ;
typedef struct node2 * Tree ;
// struct for the tree

//================================//
// this function is a pre-order reading function used to check how correct the other functions are
void preOrder(Tree T)
{
    if(T != NULL)
    {
        printf("%s --> %f (M)\n", T->cname,T->total );
        preOrder(T->left);
        preOrder(T->right);
    }
}
//===========================//
// this function is a in-order reading function used to check how correct the other functions are
void inOrder(Tree T)
{
    if(T != NULL)
    {
        inOrder(T->left);
         printf("%s --> %f (M)\n", T->cname,T->total );
        inOrder(T->right);
    }
}
//===========================//

// A utility function to get height of the tree
int getheight(country N)
{
    if (N == NULL)
        return -1 ;
    return N->height;
}
//=================================//

// a function used to find the maximum node at the left sub tree
country max_left(country T) {

if(T == NULL)return NULL ;
if(T->right == NULL )return T ;
else{
    max_left(T->right);
}
}

// insertion codes
void addFirst(city list , double pop ,int rank , char * name ){
    ptr temp = (struct node*) malloc (sizeof (struct node));
    temp->population = pop;
    strcpy(temp->name,name) ;
    temp ->rank = rank ;
   temp ->next = list->next;
   list->next = temp ;

   }
//==============================//
void printlist (city c ) {
    if (c == NULL )
        puts("Empty");
    else {

        ptr current = c->next;
        while (current != NULL) {

     printf( "%d - %s\n" , current->rank , current->name ) ;
        current = current->next ;
        }

    }
}
// printlist function for cities


// finding a city or a country
int search(ptr head, char * name )
{
    ptr current = head;  // Initialize current
    while (current != NULL)
    {
        if (strcmp(current->name,name))
            return 1;
        current = current->next;
    }
    return 0 ;
}
//==================================//
// finding a country node based on the countrys name .
   ptr2 find( ptr tree, char * name  ) {
	ptr2 current = tree ;
	while (current!= NULL ) {
	if (strcmp(current->cname,name) == 0  )
	return current ;
	else if (strcmp(current->cname,name) < 0  )
        current = current ->right ;
    else if (strcmp(current->cname,name) > 0  )
        current = current ->left ;


   }
   return current ;
   }
   //===================================//
   ptr2 alloc(char * name)
{
    ptr2 node = (ptr2)malloc(sizeof(struct node2));
    strcpy(node->cname,name) ;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 0 ;  // new node is initially added at leaf
    return  node;
}
//============================================//
// both left and right rotation functions
ptr2 rightRotate(country  y)
{
    ptr2 x = y->left;

    ptr2 T2 = y->left->right;



    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = maximum(getheight(y->left), getheight(y->right))+1;
    x->height = maximum(getheight(x->left), getheight(x->right))+1;

    // Return new root
    return x;
}
//=================================================//
ptr2 leftRotate(country x)
{
    ptr2 y = x->right;
    ptr2 T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = maximum(getheight(x->left), getheight(x->right))+1;
    y->height = maximum(getheight(y->left), getheight(y->right))+1;

    // Return new root
    return y;
}
//===========================================================//
int getBalance(country N)
{

    if (N == NULL)
        return 0;

    return getheight(N->left) - getheight(N->right)  ;
}
// the function of balance is needed because if the balance is < -1 or >1 we need to do a rotation depending on the place of the imbalanced node
//==========================================================//
Tree balance(Tree root ){
    int bc = getBalance(root);
if(bc == 2 ){
    if(getBalance(root->left) == -1) //left right case
        root->left = leftRotate(root->left);
        root = rightRotate(root);

}else if(bc == -2){
 if(getBalance(root->right) == 1)
        root->right = rightRotate(root->right); // tight left case
        root = leftRotate(root);

}
root->height = maximum(getheight(root->left),getheight(root->right)) +1 ; // update height
return root ;
}
//======================================================//
// the next function is an insertion function to the AVL tree
ptr2 insert(Tree T, char* name  )
{
    //  normal BST insertion , since the AVL tree is also a binary search tree with country name as key

    if (T == NULL)
        return( alloc(name) );

    if ( strcmp(T->cname , name ) > 0 )
        T->left  = insert(T->left , name);
    else if (strcmp(T->cname , name ) < 0 )
        T->right = insert(T->right, name);
    else  // Equal keys are not allowed in BST
        return T;
//===========================================
// setting a new height to the inserted node
T->height = 1 + maximum(getheight(T->left),getheight(T->right));
//=========================================

 int balancefactor = getBalance(T);
 // getting the balance of the tree to check if a rotation is needed


 T = balance(T); // balacing the tree if an imbalacement happens

        return T;

}
Tree delete_node(Tree root , char* name ){
    // this function is used to delete a node from the tree
       if(root == NULL)
    return NULL ;
else {

       if (strcmp(root->cname,name) < 0  )
        root->right= delete_node(root->right,name);
     else if (strcmp(root->cname,name) > 0  )
        root->left= delete_node(root->left,name);
// the recursion above is to find the node to be deleted at stop at its parent

        else {
                // this case if the node has both right and left nodes , we find the maximum node at the left sub-tree and swap it

            if(root->right != NULL && root->left != NULL){

            country temp = max_left(root->left);


             strcpy(root->cname , temp->cname);

            root->total =   temp->total;
            root->left = delete_node(root->left,name);
            root->height = 1 + maximum(root->left,root->right);
            root = balance(root);
                        return root;
        // after all cases we need to re-balance the tree just like we did in the insertion function
        }
        else{

            // this case is the one or zero child case , we just need to swap the node and its parent
            Tree temp = NULL ; // temp is the child
            if(root->left!= NULL)
                temp = root->left;
            if(root->right != NULL)
                temp = root->right;

            free(root);
             temp-> height = 1 + maximum(root->left , root->right);
            temp =  balance(temp);
            return temp ;
        }


        }

}
}
//===================== // a function needed to count the number of cities in the AVL tree
int numofcities(Tree root) {
 if (root == NULL ) return 0 ;
 else {

    int number = 0 ;
    city temp = root->cities->next ;
    while(temp != NULL){
        number ++ ;
        temp = temp->next ;

    }

    return number + numofcities(root->left) + numofcities(root->right) ;

 }

 }

// ==============================
