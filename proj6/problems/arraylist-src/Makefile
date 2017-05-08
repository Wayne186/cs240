all: mytest

mytest: mytest.cpp
	g++ --std=c++11 -g -c ArrayList.cpp -o ArrayList.o
	g++ --std=c++11 -g mytest.cpp ArrayList.o -o mytest

clean:
	rm -f *.out *.o mytest total.txt
