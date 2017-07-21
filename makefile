# Makefile HELLO
 
# Paths
DSRC = src
DINC = lib
DOBJ = obj
DEXE = bin

# Compiler flags
CFLAGS = -Wall -g

# Commands
CC = gcc 
LK = ld
RM = del

# Project list

#Rebuild all target
all:Recursivedir.c
	$(CC)  main.c $(CFLAGS) $(DOBJ)/$(subst .c,.o,$^)

Recursivedir.c:
	$(CC) -c lib/$@ $(CFLAGS) -o $(DOBJ)/$(subst .c,.o,$@)

clean:
	cd $(DOBJ) && \
	$(RM) *.o
	cd $(DEXE) && \
	$(RM) *.* 