#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 5

/*Pilha implementada sem usar um lista */

struct pilha * create(){
	struct pilha *s = NULL;
	s = (struct pilha*)malloc(sizeof(struct pilha));
	if(s == NULL){
		return NULL;
	}
		s->topo = 0;
		return s;
}

int makenull(struct pilha * p){
	if(p == NULL){
		return 0;
	}
	if(vazia(p) == 1){
		return 0;
	}
	while(p->topo > 0){
		pop(p);
	}
		return 1;
}


int top(struct pilha * p){
	int top = 0;
	
	if(p == NULL){
		return 0;
	}
	if(vazia(p) == 1){
		return 0;
	}
	top = p->array[p->topo];
	
	return top;
}

int pop(struct pilha * p){
	if(vazia(p) == 1 || p == NULL){
		return 0;
	}
	p->topo -= 1;
	return 1;
}

int push(struct pilha * p, int val){
	if(p == NULL){
		return 0;
	}
	if(p->topo == MAX){
		/* Overflow */
		return 0;
	}
	p->topo += 1;
	p->array[p->topo] = val;
		return 1;
}

 int vazia(struct pilha *p){
	 if(p == NULL){
		 return 0;
	 }
	 if(p->topo == 0){
		 return 1;
	 }
	 else{
		 return 0;
	 }
 }
 
 void destroy(struct pilha * p){
	 if(p == NULL){
		 return;
	 }
		free(p);
 }

