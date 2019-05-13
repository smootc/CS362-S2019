CFLAGS = -Wall -fpic -coverage -lm

testme:
	gcc -o testme -g testme.c $(CFLAGS)
	./testme

clean: 
	rm -f *.gcov *.gcno *.gcda *.exe testme
