# "Debug" build - no optimization, and debugging symbols
DBG_FLAGS= -Wall -O0 -g

# "Release" build - optimization, and no debug symbols
REL_FLAGS = -Wall


rebuild: clean mkdirs build

# Create the files
mkdirs:
	-mkdir debug
	-mkdir release

build: normal extended


normal:
	gcc $(DBG_FLAGS) -DNRM -o debug/counter lo1.c
	gcc $(REL_FLAGS) -DNRM -o release/counter lo1.c

extended: 
	gcc $(DBG_FLAGS) -DEXT -o debug/counter2 lo1.c
	gcc $(REL_FLAGS) -DEXT -o release/counter2 lo1.c

clean:
	-rm debug/* release/*


#nrm_version: normal.o
#	gcc lo1.o -o counter

#ext_version: extended.o
#	gcc lo1.o -o counter2

#normal.o: 
#	gcc -Wall -c -DNRM lo1.c

#extended.o:
#	gcc -Wall -c -DEXT lo1.c

#clean:
#	-rm debug/* release/* *.o lo1








