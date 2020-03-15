main: functions.o
	g++ -O3 -o main main.cpp functions.o
test: functions_test.o
	g++ -O3 -o main test.cpp functions_test.o
test2: functions_test2.o
	g++ -O3 -o main test2.cpp functions_test2.o
functions:
	g++ -c functions.cpp
functions_test:
	g++ -c functions_test.
functions_test2:
	g++ -c functions_test2.cpp
clean:
	rm *.o main