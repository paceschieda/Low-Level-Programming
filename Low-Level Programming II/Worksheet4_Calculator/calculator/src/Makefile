all: calc_demo calc_full

calc_demo: calculator_demo.o
	gcc calculator.o -o calc_demo

calc_full: calculator_full.o
	gcc calculator.o -o calc_full

calculator_demo.o: calculator.c
	gcc -Wall -c -DDEMO calculator.c

calculator_full.o: calculator.c
	gcc -Wall -c -DFULL calculator.c

clean:
	-rm *.o calc_demo calc_full





