#include <stdio.h>
#include <stdlib.h>
#include "fatpointer.h"

struct node {
   int data;
   fatp *next;
};
 
//struct node *head = NULL;
fatp *head = NULL;

void insert_node(int);
void traverse(int *s);
 
int main (int argc, char *argv[]) {
	//int option = atoll(argv[1]);
	srand(2015);
	region_base = rand()%100000000;
	int iter = 0;
	int num_nodes = 30000000;
	long elapsed_seconds;
	long elapsed_useconds;
	long elapsed_utime;
	struct timeval tempo, tempo1;
	FILE *pfp = fopen("list_fatp.txt", "a");
	gettimeofday(&tempo, NULL);
	insert_node(num_nodes);
	gettimeofday(&tempo1, NULL);
	elapsed_seconds = tempo1.tv_sec - tempo.tv_sec;
	elapsed_useconds = tempo1.tv_usec - tempo.tv_usec;
	elapsed_utime = (elapsed_seconds) * 1000000 + elapsed_useconds;
	fprintf(pfp, "%ld\n", elapsed_utime);
	printf("insert time: %fs\n", elapsed_utime/1e6);
	gettimeofday(&tempo, NULL);
	iter = 0;
	int *s = (int *)calloc(1, sizeof(int));
	while(iter < 10){
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
 

void insert_node(int num_nodes) {
	//struct node *t, *temp;
	fatp *t, *temp;
 
	head = FATP_MALLOC(sizeof(struct node)) ;
	R_FAT(head, struct node)->data = 0;
	int i;
	t = head;
	for(i = 1; i < num_nodes; i++){
		temp = FATP_MALLOC(sizeof(struct node)) ;
		R_FAT(temp, struct node)->data = i;
		R_FAT(t, struct node)->next = temp;
		t = temp;
	}
	R_FAT(t, struct node)->next = NULL;
 
}
 
void traverse(int *s) {
	//struct node *t;
	fatp *t;
 
	t = head;
 
	if (t == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	while (t != NULL) {
		t = R_FAT(t, struct node)->next;
		(*s)++;
	}
}
 
