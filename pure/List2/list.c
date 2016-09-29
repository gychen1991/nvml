#include <stdio.h>
#include <stdlib.h>
 
struct node {
   int data;
   struct node *next;
};
 
struct node *head = NULL;

void insert_node(int);
void traverse(int *s);
 
int main (int argc, char *argv[]) {
	int iter = 0;
	int num_nodes = 30000000;
	long elapsed_seconds;
	long elapsed_useconds;
	long elapsed_utime;
	struct timeval tempo, tempo1;
	FILE *pfp = fopen("list.txt", "a");
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
	fprintf(pfp, "total elements traversed %d %ld\n", (*s)/10000,elapsed_utime);
	printf("traverse time: %fs\n", elapsed_utime/1e6);
	return 0;
}
 

void insert_node(int num_nodes) {
	struct node *t = NULL, *temp = NULL;
	int i;
	head = (struct node *)malloc(sizeof(struct node));
	head->data = 0;
	t = head;
	for(i = 1; i < num_nodes; i++){
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = i;
		t->next = temp;
		t = temp;
	} 
	t->next = NULL;
}
 
void traverse(int *s) {
	struct node *t;
 
	t = head;
 
	if (t == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
 
	while (t != NULL) {
		t = t->next;
		(*s)++;
	}
}
 
