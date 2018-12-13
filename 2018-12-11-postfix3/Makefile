all: postfix

calculator.o: calculator.cc operation.hh calculator.hh

unary.o: unary.cc unary.hh operation.hh
binary.o: binary.cc binary.hh operation.hh

negate.o: negate.cc negate.hh operation.hh
plus.o: plus.cc plus.hh operation.hh
minus.o: minus.cc minus.hh operation.hh
sqrt.o: sqrt.cc sqrt.hh operation.hh
divide.o: divide.cc divide.hh operation.hh
drop.o: drop.cc drop.hh operation.hh
duplicate.o: duplicate.cc duplicate.hh operation.hh
swap.o: swap.cc swap.hh operation.hh

postfix.o: postfix.cc calculator.hh binary.hh operation.hh composite.hh

postfix: postfix.o calculator.o unary.o negate.o binary.o plus.o multiply.o sqrt.o swap.o drop.o duplicate.o
	g++ -o postfix postfix.o calculator.o unary.o negate.o binary.o plus.o multiply.o sqrt.o swap.o drop.o duplicate.o

clean:
	rm -fr *.o
	rm -fr postfix
