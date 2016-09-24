PROGS = list list_fatp list_based list_offholder list_riv list_copy_based
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
list_riv:list_riv.o
list_copy_based:list_copy_based.o

clean:
	rm *.o $(PROGS)
