#Makefile

OBJS = main.o ship.o green.o sfmlview.o board.o collisions.o menu.o
CXX = clang++
CXXFLAGS = -Wall -std=c++11
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

MS: $(OBJS)
	$(CXX) -o space $(OBJS) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) space $(OBJS)
