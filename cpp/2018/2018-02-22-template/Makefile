all: app

CXX = clang++
CC = clang++
CXXFLAGS += -std=c++11 -I.
OBJS = func.o main.o

app: $(OBJS)
	$(CXX) -o app $(OBJS)

clean:
	rm -rf *.o app
