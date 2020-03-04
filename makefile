main: functions.o
	g++ -O3 -o main main.cpp functions.o
test: functions_test.o
	g++ -O3 -o main test.cpp functions_test.o
functions:
	g++ -c functions.cpp
functions_test:
	g++ -c functions_test.cpp
clean:
	rm *.o main