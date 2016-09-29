#include <stdio.h>
#include <stdlib.h>
#include "offholder.h"

struct node {
   int data;
   OFF *next;
};

 
//struct node *head = NULL;
struct list{
	OFF *head;
};

struct list *hlist = NULL;
void insert_node(int);
void traverse(int *s);
 
int main (int argc, char *argv[]) {
	//int option = atoll(argv[1]);
	hlist = malloc(sizeof(struct list)); //allocate on pmem
	int iter = 0;
	int num_nodes = 30000000;
	long elapsed_seconds;
	long elapsed_useconds;
	long elapsed_utime;
	struct timeval tempo, tempo1;
	FILE *pfp = fopen("list_offholder.txt", "a");
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
	OFF *t, **temp;
	
	hlist->head = OFF_MALLOC(sizeof(struct node), struct node) ;
	writeoh(&hlist->head, hlist->head);
	readoh(hlist->head, struct node)->data = 0;
	int i;
	temp = &hlist->head;
	for(i = 1; i < num_nodes; i++){
		t = OFF_MALLOC(sizeof(struct node), struct node);
		readoh(*temp, struct node)->next = t;
		writeoh(&readoh(*temp, struct node)->next, t);
		temp = &readoh(*temp, struct node)->next;	
		readoh(*temp, struct node)->data = i;
	}
	readoh(*temp, struct node)->next = NULL;
	
}
 
void traverse(int *s) {
	//struct node *t;
	OFF **t;
 
	t = &hlist->head;
 
	if (*t == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
 
	while (*t != NULL) {
		t = &readoh(*t, struct node)->next;
		(*s)++;	
	}
}
 
