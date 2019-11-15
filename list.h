#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include "status.h"

typedef struct Node {
  void* val;
  struct Node* next;
} Node;

/** Comparison function for list elements.
 * Must follow the "strcmp" convention: result is negative if e1 is less
 * than e2, null if they are equal, and positive otherwise.
 */
typedef int (*compFun)(void* e1, void* e2); 

/** Display function for list elements */
typedef void (*prFun)(void*);    

typedef struct List {
  int nelts;
  Node* head;
  compFun comp;	
  prFun pr;
} List;


/** Empty List creation by dynamic memory allocation (O(1)).
 * @param comp comparison function between elements (ala strcmp())
 * @param pr display function for list elements
 * @return a new (empty) list if memory allocation OK
 * @return 0 otherwise
 */
List* newList(compFun,prFun);	

/** destroy the list by deallocating used memory (O(N)).
 * @param l the list to destroy */
void delList(List*);		

/** get the Nth element of the list (O(N)).
 * @param l the list
 * @param n the index of the element in list
 * @param e (out) the searched element
 * @return OK if element found
 * @return ERRINDEX if index out of list bounds
 */
status nthInList(List* l,int n,void** res);	

/** Insert element at a given position in the list (O(N)).
 * @param l the list to store the element in
 * @param p the position of the insertion point
 * @param e the element to insert
 * @return ERRINDEX if position is out of list bounds
 * @return ERRALLOC if memory allocation failed
 * @return OK otherwise
 */
status addListAt(List* l,int n,void* e);	

/** remove the element located at a given position in list (O(N)).
 * @param l the list to remove the element from
 * @param p the position of the element to remove
 * @param e (out) the removed element
 * @return ERRINDEX if position is out of list bounds
 * @return OK otherwise
 */
status remFromListAt(List* l,int n,void** res);	

/** remove given element from given list (O(N)).
 * @param l the list to remove the element from
 * @param e the element to remove
 * @return ERRABSENT if element is not found in list
 * @return OK otherwise
 */
status remFromList(List* l,void* e);	

/** display list elements as "[ e1 ... eN ]" (O(N)).
 * The display of the element is delegated to the prFun function
 * @param l the list to display.
 */
status displayList(List* l);		

/** sequencially call given function with each element of given list (O(NxF)).
 * @param l the list
 * @param f the function
 */

void forEach(List* l,void(*f)(void*));	

/** compute and return the number of elements in given list (O(1)).
 * @param l the list
 * @return the number of elements in given list
 */
int lengthList(List* l);	

/** add given element to given list according to compFun function (O(N)).
 * @param l the list (supposedly sorted according to compFun function)
 * @param e the element to add
 * @return ERRALLOC if memory allocation failed
 * @return OK otherwise
 */
status addList(List* l,void* e);	
 
/** tests whether the list contains given element (O(N)).
 * @param l the list
 * @param e the searched element
 * @return 0 if element is not found in list
 * @return 1 if element is at the head of the list (no predecessor)
 * @return (a pointer to) the predecessor of the search element otherwise
 */
Node* isInList(List* l,void* e);	

#endif // _LIST_H
