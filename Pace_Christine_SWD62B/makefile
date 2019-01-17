all: clean mkdirs debug release

mkdirs:
	-mkdir debug
	-mkdir release

debug: mkdirs
	gcc -Wall -O0 -g -DHONEYPOT -o debug/honeypot_lite honeypot.c
	gcc -Wall -O0 -g -DHONEYPOT -DFULL -o debug/honeypot_full honeypot.c
	gcc -Wall -O0 -g -DSCANNER -o debug/scanner client.c

release: mkdirs	
	gcc -Wall -DHONEYPOT -o release/honeypot_lite honeypot.c
	gcc -Wall -DHONEYPOT -DFULL -o release/honeypot_full honeypot.c
	gcc -Wall -DSCANNER -o release/scanner client.c

clean:
	-rm debug/* release/*

