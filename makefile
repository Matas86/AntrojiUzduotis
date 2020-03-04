main: functions.o
	g++ -o main main.cpp functions.o
test: functions_test.o
	g++ -o main test.cpp functions_test.o
functions:
	g++ -c functions.cpp
functions_test:
	g++ -c functions_test.cpp
clean:
	rm *.o main