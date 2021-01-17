CC=gcc
AR=ar
OBJECTS_F=frequency.o
OBJECTS_FR=trie.o
FLAGS= -Wall -g

all: frequency
frequency: $(OBJECTS_F) frequency.a
	$(CC) $(FLAGS) -o frequency $(OBJECTS_F) frequency.a 
frequency.a: $(OBJECTS_FR)
	$(AR) -rcs frequency.a $(OBJECTS_FR)
frequency.o: frequency.c trie.h
	$(CC) $(FLAGS) -c frequency.c
trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c 
clean:
	rm -f *.o *.a *.so frequency
