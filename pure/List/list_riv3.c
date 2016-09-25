#include <stdio.h>
#include <stdlib.h>
#include "riv3.h"

struct node {
   int data;
   RIV *next;
};
 
//struct node *head = NULL;
RIV *head = NULL;

void insert_node(int);
void traverse(int *s);
 
int main (int argc, char *argv[]) {
	int data; 
	//int option = atoll(argv[1]);
	srand(2015);
	base = rand()%100000000;
	RIV_REGION = 917373;//rand()%100;

	add_RIV_entry(base, RIV_REGION);
	data = atoll(argv[1]);

	int iter = 0;
	int num_nodes = 30000;
	long elapsed_seconds;
	long elapsed_useconds;
	long elapsed_utime;
	struct timeval tempo, tempo1;
	FILE *pfp = fopen("list_riv.txt", "a");
	gettimeofday(&tempo, NULL);
	while(iter < num_nodes){
		insert_node(data);
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
		traverse(s);  
		iter++;
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
	RIV *t, *temp;
	t = RIV_MALLOC(sizeof(struct node), struct node) ;

 
	if (head == NULL) {
		head = t;
		R_RIV(head, struct node)->data = x;
		R_RIV(head, struct node)->next = NULL;
		return;
	}
 
	temp = head;
 
	while (R_RIV(temp, struct node)->next != NULL)
		temp = R_RIV(temp, struct node)->next;   
	R_RIV(temp, struct node)->next = t;
	R_RIV(t, struct node)->data    = x;
	R_RIV(t, struct node)->next    = NULL;
}
 
void traverse(int *s) {
	//struct node *t;
	RIV *t;
	t = head;
 
	if (t == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
 
	while (t != NULL) {
		t = R_RIV(t, struct node)->next;
		(*s)++;
	}
}
 
