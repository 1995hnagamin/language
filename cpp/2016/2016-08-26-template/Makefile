.PHONY: clean

CXX = clang++

OBJS = library.o main.o

point: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o point

clean:
	rm $(OBJS)
