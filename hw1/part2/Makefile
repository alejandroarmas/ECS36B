# Alejandro Armas
# 915110085
CXX=g++
CXXFLAGS=-Wall
execs = calculator useFraction

all: $(execs)


calculator: calculator.o fraction.o
	$(CXX) -o $@ $^

useFraction: useFraction.o fraction.o
	$(CXX) -o $@ $^

fraction.o: fraction.cpp
	$(CXX) -o $@ -c $^

useFraction.o: useFraction.cpp
	$(CXX) -o $@ -c $^

calculator.o: calculator.cpp
	$(CXX) -o $@ -c $^

clean:
	rm -f $(execs) *.o
