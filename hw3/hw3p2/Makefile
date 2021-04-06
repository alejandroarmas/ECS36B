# Alejandro Armas
# 915110085

CXX=g++
CXXFLAGS=-Wall
execs = testPoint testShape checkpack


all: $(execs)


checkpack: checkpack.o domain.o Rectangle.o Circle.o Point.o 
	$(CXX) -o $@ $^

testPoint: testPoint.o Point.o
	$(CXX) -o $@ $^

testShape: testShape.o Rectangle.o Circle.o Point.o 
	$(CXX) -o $@ $^

testPoint.o: testPoint.cpp
	$(CXX) -o $@ -c $^

domain.o: domain.cpp
	$(CXX) -o $@ -c $^

Point.o: Point.cpp
	$(CXX) -o $@ -c $^

Rectangle.o: Rectangle.cpp
	$(CXX) -o $@ -c $^

Circle.o: Circle.cpp
	$(CXX) -o $@ -c $^

clean:
	rm -f $(execs) *.o test_alejandro_armas_*.svg
