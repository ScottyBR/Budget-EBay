CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: main

clean:
	rm main BidToBuy.o User.o Sale.o

main: main.cpp BidToBuy.o User.o Sale.o
	$(CXX) $(CXXFLAGS) main.cpp BidToBuy.o User.o Sale.o -o main

BidToBuy.o: BidToBuy.cpp
	$(CXX) $(CXXFLAGS) -c BidToBuy.cpp

User.o: User.cpp
	$(CXX) $(CXXFLAGS) -c User.cpp

Sale.o: Sale.cpp
	$(CXX) $(CXXFLAGS) -c Sale.cpp