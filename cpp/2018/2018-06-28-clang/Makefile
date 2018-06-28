.PHONY: all clean

all: ast.cc

clean:
	rm -rf ast.cc

%.cc: %.cpp
	clang++ $(CXXFLAGS) -E $^ | sed '/^$$/d; /^#/d' > $@

CXXFLAGS = \
	-std=c++11 \
	-D__STDC_LIMIT_MACROS \
	-D__STDC_CONSTANT_MACROS
