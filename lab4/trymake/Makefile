CC = gcc
CFLAGS = -g
DEPS = readwrite.h sort.h
OBJ = readwrite.o sort.o tryit.o
    
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
      
tryit: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^




