CXXFLAGS = -Wall

all: assigntables

assigntables: assigntables.o Restaurant.cpp Table.cpp
	$(CXX) -o $@ $^

clean:
	rm -f assigntables *.o