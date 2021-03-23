
CXX = g++ 
CXXFLAGS = -Wall -g -O0 
LDLIBS = $(shell pkg-config --cflags --libs sdl2) -lm
SRC = *.cpp


all: $(OBJS)
	$(CXX) -o xcollide ${SRC}  ${CXXFLAGS} ${LDLIBS}

clean:
	rm -f *.o *~xcollide

