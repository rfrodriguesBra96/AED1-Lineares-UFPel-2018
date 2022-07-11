#include <stdio.h>
#include <stdlib.h>
#include "le.h"
 
/* Complexidade O(1) */
struct llist * create_l()
{
	struct llist *desc = NULL;
	desc = (struct llist*) malloc(sizeof(struct llist));
	
	if(desc == NULL)
	{
		return NULL;
	}
	
	desc->head = NULL;
	desc->tam = 0;
	
	return desc;
}

/* Complexidade O(1) */
 elem * create_node(int val)
 {
	 struct elem *myNodo = NULL;
	 myNodo = (struct elem*)malloc(sizeof(struct elem));
	 
	 if(myNodo == NULL)
	 {
		 return NULL;
	 }
	 
	 myNodo->val = val;
	 myNodo->next = NULL;
	 
	 return myNodo;
 }
 
 /* Insere um nodo na lista vinculada */
 int insert_l(struct llist *desc, elem * prev, elem * item){
	 if(desc == NULL || item == NULL){
		 return 0;
	 }
	 
	 /* Já recebo o nodo item */
	 /* Inserção no começo */
	 /* Complexidade O(1) */
	 if(prev == NULL){
		 item->next = desc->head;
		 desc->head = item;
		 desc->tam += 1;
		 return 1;
	 }
		/* Insere depois de um nodo */
		/*  Complexidade O(1) */
		item->next = prev->next;
		prev->next = item;
		desc->tam += 1;
		return 1;
 }

int delete_l(struct llist *desc, elem * prev)
{
	if(desc == NULL || prev == NULL){
		return 0;
	}
	
	elem *tmp = NULL;
	
	/* Exclui sempre do começo */
	tmp = desc->head;
	desc->head = desc->head->next;
	free(tmp);
	
	desc->tam -= 1;
	
	return 1;
}

elem * get_l(struct llist *desc, int pos){
	if((desc == NULL) || ((pos-1) < 0) || ((pos-1) > length_l(desc)))
	{
		return NULL;
	}
	
	int i;
	struct elem *node = NULL;
	
	node = desc->head;
	
	for(i = 0; i < (pos-1); i++){
		node = node->next;
	}
		return node;
}

int set_l(struct llist *desc, int pos, int val)
{
	
	if(desc == NULL || (pos-1) < 0 || (pos-1) > (length_l(desc)-1)){
		return 0;
	}
	
	int i;
	struct elem *node = NULL;
	
	node = desc->head;
	
	for(i = 0; i < (pos-1); i++){
		node = node->next;
	}
		node->val = val;
		
		return 1;
}

elem * locate_l(struct llist *desc, elem * prev, int val)
{
	if(desc == NULL){
		return NULL;
	}
	
	struct elem *temp = NULL;
	
	if(prev == NULL){
		temp = desc->head;
		while(temp != NULL){
			if(temp->val == val){
				return temp;
			}
			temp = temp->next;
		}
	}
	
	return NULL;
}

int length_l(struct llist *desc)
{
	return desc->tam;
}

void destroy_l(struct llist *desc){
	struct elem * tmp = NULL;
	struct elem * prox = NULL;
	
	tmp = desc->head;
	/* Complexiade O(n) */
	while(tmp != NULL){
		prox = tmp->next;
		free(tmp);
		tmp = prox;
	}
	desc->head = NULL;
}