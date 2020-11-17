main: main.cpp pareja.o
	g++ -o $@ -I. $^

pareja.o: pareja.cpp pareja.h
	g++ -o $@ -I. -c $<

clean:
	rm -rf main *.o