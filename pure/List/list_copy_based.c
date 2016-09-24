#include <stdio.h>
#include <stdlib.h>
#include "copy_based.h"

struct node {
   int data;
   Based *next;
};
 
static inline void ToAbsolute(Based **orig)
{
	Based **orig_temp = orig;
	while(*orig_temp!=NULL){
		*orig_temp = (Based *)((intptr_t)(*orig_temp) + base);
		orig_temp = &(((struct node *)(*orig_temp))->next);
	}
}

static inline void ToBased(Based **newhead)
{
	Based **newhead_temp = newhead;
	while(*newhead_temp!=NULL){
		Based **next = &(((struct node *)(*newhead_temp))->next);
		*newhead_temp = (Based *)((intptr_t)(*newhead_temp) - base);
		newhead_temp = next;
	}
}
//struct node *head = NULL;
Based *head = NULL;

void insert_node(int);
void insert_node_Absolute(int);
void traverse(int *s);
void traverse_Absolute(int *s);
 
int main (int argc, char *argv[]) {
	int data; 
   //int option = atoll(argv[1]);
	srand(2015);
	base = rand()%100000000;
	data = atoll(argv[1]);
	int iter = 0;
	int num_nodes = 30000;
	long elapsed_seconds;
	long elapsed_useconds;
	long elapsed_utime;
	struct timeval tempo, tempo1;
	FILE *pfp = fopen("list_copy_based.txt", "a");
	gettimeofday(&tempo, NULL);
	while(iter < num_nodes){
		ToAbsolute(&head);
		insert_node_Absolute(data);
		ToBased(&head);
		data++; 
		iter++;
	}
	gettimeofday(&tempo1, NULL);
	elapsed_seconds = tempo1.tv_sec - tempo.tv_sec;
	elapsed_useconds = tempo1.tv_usec - tempo.tv_usec;
	elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
	fprintf(pfp, "%ld\n", elapsed_utime);
	printf("insert time: %fs\n", elapsed_utime/1e6);


	gettimeofday(&tempo, NULL);
	iter = 0;
	int *s = (int *)calloc(1, sizeof(int));
	while(iter < 10000){
		ToAbsolute(&head);
		traverse_Absolute(s);  
		iter++;
		ToBased(&head);
	}
	gettimeofday(&tempo1, NULL);
	elapsed_seconds = tempo1.tv_sec - tempo.tv_sec;
	elapsed_useconds = tempo1.tv_usec - tempo.tv_usec;
	elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
	fprintf(pfp, "total elements traversed %d %ld\n", (*s)/10000, elapsed_utime);
	printf("traverse time: %fs\n", elapsed_utime/1e6);
	return 0;
}
 

void insert_node(int x) {

   //struct node *t, *temp;
	Based *t, *temp;
 
	t = BASED_MALLOC(sizeof(struct node), struct node) ;

 
	if (head == NULL) {
		head = t;
		R_Based(head, struct node)->data = x;
		R_Based(head, struct node)->next = NULL;
		return;
	}
 
	temp = head;
	while (R_Based(temp, struct node)->next != NULL)
		temp = R_Based(temp, struct node)->next;   
	R_Based(temp, struct node)->next = t;
	R_Based(t, struct node)->data    = x;
	R_Based(t, struct node)->next    = NULL;
}

void insert_node_Absolute(int x) {

   //struct node *t, *temp;
	Based *t, *temp;
 
	//t = BASED_MALLOC(sizeof(struct node), struct node) ;
	t = malloc(sizeof(struct node));

 
	if (head == NULL) {
		head = t;
		//R_Based(head, struct node)->data = x;
		//R_Based(head, struct node)->next = NULL;
		((struct node *)head)->data = x;
		((struct node *)head)->next = NULL;
		return;
	}
 
	temp = head;
	while (((struct node *)temp)->next != NULL)
		temp = ((struct node *)temp)->next;   
	((struct node *)temp)->next = t;
	((struct node *)t)->data = x;
	((struct node *)t)->next = NULL;
}
 
void traverse(int *s) {
   //struct node *t;
	Based *t;
 
	t = head;
 
	if (t == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	while (t != NULL) {
		t = R_Based(t, struct node)->next;
		(*s)++;
	}
}
 
void traverse_Absolute(int *s) {
   //struct node *t;
	Based *t;
 
	t = head;
 
	if (t == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	while (t != NULL) {
		t = ((struct node *)t)->next;
		(*s)++;
	}
}
