.PHONY: build clean run

build:
	gcc -c *.c
	gcc *.o -o velha

clean:
	rm *.o
	rm velha

run:
	./velha