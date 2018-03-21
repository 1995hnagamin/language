all: sym

CXX = clang++
CC = clang++
CXXFLAGS += -std=c++11 -I.

sym: extern.s inst.s

clean:
	rm -rf *.s

%.s: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -S $<
