all: rebuild

rebuild: clean mkdirs honeypot port_scanner

mkdirs:
	-mkdir debug
	-mkdir release

honeypot: mkdirs
	gcc -Wall -O0 -g -DHONEYPOT -o debug/honeypot cp_assignment.c
	gcc -Wall -DHONEYPOT -o release/honeypot cp_assignment.c

port_scanner: mkdirs
	gcc -Wall -O0 -g -DSCANNER -o debug/scanner cp_assignment.c
	gcc -Wall -DSCANNER -o release/scanner cp_assignment.c

clean:
	-rm debug/* release/*

