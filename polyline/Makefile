CXX = gcc
NAME = polyline

# Warnings frequently signal eventual errors:
CXXFLAGS=`sdl2-config --cflags` -g -W -Wall -Wextra -pedantic -O0 -I `sdl2-config --prefix`/include/

LDFLAGS = `sdl2-config --libs` -lm

OBJS = $(NAME).o

polygon: $(OBJS) libezdraw.a
	$(CXX) -o $(NAME) $(NAME).o $(CXXFLAGS) -L. -lezdraw $(LDFLAGS)

$(NAME).o: $(NAME).c ezdraw.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f *~
	rm -f $(NAME)
