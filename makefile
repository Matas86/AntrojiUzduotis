main: functions.o
	g++ -o main main.cpp functions.o
test: functions.o
	g++ -o main test.cpp functions.o
functions:
	g++ -c functions.cpp
clean:
	rm *.o main