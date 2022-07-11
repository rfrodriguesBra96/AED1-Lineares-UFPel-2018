#include "ls.h"
#include <stdio.h>
#include <stdlib.h>

/* Aqui devem ser implementadas as funções definidas em ls.h */

struct list * create(int max)
{
	/* I can not allocate */
	if(max <= 0 || max > 5){
		return NULL;
	}
	
	struct list *ptr_list = NULL;
	
	ptr_list = (struct list*) malloc(sizeof(struct list));
	
	if(ptr_list == NULL){
		/* Allocation error. */
		return NULL;
	}
	
	/* starts list */
	ptr_list->tam = 0;
	ptr_list->max = max;
	ptr_list->arm = malloc(max * sizeof(int));
	
	return ptr_list;
}

/* complecity: O(n) */
int insert(struct list *desc, int pos, elem item)
{
	int index;
	
	/* pos == 3 <=> 2 */
	pos -= 1;
	
	/* full lists, use of (TAD)*/
	if(full(desc)){
		return 0;
	}
	
	/* use of (TAD) */
	if(pos < 0 || pos > length(desc)){
		return 0;
	}
	
	/* first form */
	for(index = length(desc); index > pos; index--){
		desc[index] = desc[index-1];
	}
	
	/* second form */
	/* for(index = length(desc); index > pos; index--){
		desc[index+1] = desc[index];
	}*/
	
	/* update list */ 
	desc->arm[pos] = item;
	desc->tam += 1;
	
	return 1;
}

/* complecity: O(n) */
int delete(struct list *desc, int pos)
{
	int i;
	pos -= 1;
	
	/* I can not remove from an empty list*/
	if(length(desc) == 0){
		return 0;
	}
	
	if(pos < 0 || pos > length(desc)){
		return 0;
	}
	
	for(i = pos; i > length(desc)-1; i--){
		desc[i] = desc[i+1];
	}
	desc->tam -= 1;
	return 1;
}

/* complecity: O(1) */
elem get(struct list *desc, int pos)
{
	pos -= 1;
	
	/* invalid positon */
	if(pos < 0 || pos > desc->tam){
		return 0;
	}
	
		return desc->arm[pos];
}

/* complecity: O(1) */
int set(struct list *desc, int pos, elem item)
{
	pos -= 1;
	
	// size equal -> 5 <=> 4 last element in list
	   
	if(pos < 0 || pos >= desc->tam){
		return 0;
	}
	
	desc->arm[pos] = item;
	return 1;
}

/* complecity: O(n) */
int locate(struct list *desc, int pos, elem item)
{
	int i;
	pos -= 1;
	
	for(i = pos; i < length(desc); i++){
		if(desc->arm[i] == item){
			return i+1; /* returns the user number */
		}
	}
		return 0;
}

/* complecity: O(1) */
int length(struct list *desc)
{
	return desc->tam;
}

/* complecity: O(1) */
int max(struct list *desc)
{
	return desc->max;
}

/* complecity: O(1) */
int full(struct list *desc)
{
	/* is full*/
	if(length(desc) == max(desc)){
		return 1;
	}
	/* not full */
		return 0;
}

/* complecity: O(1)*/
void destroy(struct list *desc)
{
	/* free list */
	free(desc);
}
