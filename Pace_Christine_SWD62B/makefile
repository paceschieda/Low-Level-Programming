all: clean client honeypot honeypot_full

client:
	gcc -Wall -o client client.c

honeypot:
	gcc -Wall -o honeypot honeypot.c

honeypot_full:
	gcc -Wall -o honeypot_full honeypot_full.c -lpthread

clean:
	-rm client honeypot honeypot_full

