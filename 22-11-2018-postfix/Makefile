all: postfix

calculator.o: calculator.cxx calculator.hpp
	g++ -c calculator.cxx

postfix.o: postfix.cxx calculator.hpp
	g++ -c postfix.cxx

postfix: postfix.o calculator.o
	g++ -o postfix postfix.o calculator.o

clean:
	rm -rf *.o
	rm -f postfix

