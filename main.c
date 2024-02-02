//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {

    int z=5;
    struct node a,b,*head ;
    a.value = z;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8

/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
    4. print by using head
 */
    struct node c ;
    head -> next -> next = &c ;    //b.next = &c
    head -> next -> next -> value = 11 ;   //c.value = 11
    head -> next -> next -> next = NULL ;  //c.next = NULL
    printf("%d\n",head -> next -> next -> value) ;

/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
*/
    struct node d ; 
    head = &d ;
    head -> value = 2 ;
    head -> next = &a ;
    printf("%d\n",head->value);


   
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
    //Exercise 3
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
     int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp = tmp -> next ;
        }
    printf("\n") ;
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */
    //Exercise 4
    tmp = head ;
    while(tmp!=NULL){
        printf("%3d", tmp->value);
        tmp = tmp -> next ;
    }
    printf("\n") ;


 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
         2 5 8 11
     */
    //Exercise 5
    typedef struct node* nodeptr ;
    
    head = (nodeptr)malloc(sizeof(nodeptr)) ;
    tmp = head ;
    
    for(i = 2;i<=11;i+=3){
        
        tmp -> value = i ;
        if(i!=11)tmp -> next = (nodeptr)malloc(sizeof(nodeptr)) ;
        else tmp -> next = NULL ;
        tmp = tmp -> next ;
    }    
    
    //print
    tmp = head ;
    while(tmp!=NULL){
        printf("%3d", tmp->value);
        tmp = tmp -> next ;
    }
    printf("\n") ;

    /*  Exercise VI Free all node !!
         //use a loop to help
     */
    //Exercise 6

    while(head!=NULL){
        tmp = head ;
        head = head -> next ;
        printf("free :%3d\n",tmp->value) ;
        free(tmp) ;
        
    }
    return 0;
}
