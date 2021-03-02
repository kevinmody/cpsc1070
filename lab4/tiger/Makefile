CC = gcc
NAME = tiger

 # Assumes you have a directory ezdraw at the top of your directory structure
 # that contains the ezdraw.h and libezdraw.a files
IDIR = ~/ezdraw/
LDIR = ~/ezdraw/
    
    # Libraries to load
LIBS = -lezdraw -lm

    # Warnings frequently signal any errors
    # Choose compiler flags for SDL2, and tell where to find the SDL2 include files
CFLAGS = `sdl2-config --cflags` -g -W -Wall -Wextra -pedantic -O0 -I `sdl2-config --prefix`/include/
    
    # Tell where the SDL2 libraries are and request them to be loaded
LDFLAGS = `sdl2-config --libs`
    
OBJS = $(NAME).o
    
$(NAME): $(OBJS) $(LDIR)libezdraw.a
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L $(LDIR) $(LIBS) $(LDFLAGS)

%.o: %.c $(IDIR)ezdraw.h
	$(CC) $(CFLAGS) -I $(IDIR) -c $< -o $@
      

    
clean:
	rm -f *.o
	rm -f *~
	rm -f $(NAME)
