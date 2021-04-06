# Alejandro Armas
# 915110085

CXX=g++
CXXFLAGS=-Wall
execs = robot


all: $(execs)

robot: robot.o Angle.o
	$(CXX) -o $@ $^

robot.o: robot.cpp
	$(CXX) -o $@ -c $^

Angle.o: Angle.cpp
	$(CXX) -o $@ -c $^

clean:
	rm -f $(execs) *.o
