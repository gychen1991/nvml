PROGS = list list_fatp list_based list_offholder
CC = gcc -O3 -I../include

all: $(PROGS)
.c.o:
	$(CC) -c -o $@ $<

$(PRGOS):
	$(CC) -o $@ $<

list:list.o
list_fatp:list_fatp.o
list_based:list_based.o
#list_based2:list_based2
list_offholder:list_offholder.c
