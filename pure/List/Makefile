PROGS = list list_fatp list_based list_offholder list_riv list_copy_based list_riv_hash list_riv3
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
list_riv3:list_riv3.o
list_copy_based:list_copy_based.o
list_riv_hash:
	g++ -O3 -I../include list_riv_hash.cpp -o list_riv_hash -std=c++11

clean:
	rm *.o $(PROGS)
