

output: Func.o testFunc.o
	g++ Func.o testFunc.o  -o output

functions.o: Func.cpp prog.h
	g++ -c Func.cpp

main.o: testFunc.cpp
	g++ -c testFunc.cpp

clean:
	rm *.o output

