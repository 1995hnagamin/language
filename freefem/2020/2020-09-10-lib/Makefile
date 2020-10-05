TARGET = supercalifragilisticexpialidocious.dylib \
	 supercalifragilisticexpialidocious.o

all: $(TARGET)

%.o %.dylib: %.cpp
	ff-c++ $<

.PHONY: clean

clean:
	rm -rf $(TARGET)
