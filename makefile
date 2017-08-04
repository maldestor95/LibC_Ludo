# Makefile RecursiveDIR

# Destination file
EXE=exou
# Sources file

# Paths
DSRC = src
DINC = lib
DOBJ = obj
DEXE = bin

# Compiler flags
CFLAGS = -Wall -g
LFLAGS =-I$(CMOCKA) -I$(CMOCKAHEADER)

#libraries
CMOCKA="C:\Program Files (x86)\cmocka\lib"
CMOCKAHEADER="C:\Program Files (x86)\cmocka\include"

# Commands
CC = gcc 
LK = ld
RM = del

# Project list

#Rebuild all target
all:Recursivedir.c
#	$(CC)  main.c $(CFLAGS) $(DOBJ)/$(subst .c,.o,$^) -o $(DEXE)/$(EXE)
	$(CC)  main.c $(CFLAGS) $(LFLAGS) $(DOBJ)/$(subst .c,.o,$^) -o $(DEXE)/$(EXE)

Recursivedir.c:
	$(CC) -c lib/$@ $(CFLAGS) -o $(DOBJ)/$(subst .c,.o,$@)

Test:
	$(DEXE)/$(EXE)

.PHONY: clean

clean:
	cd $(DOBJ) && \
	$(RM) *.o
	cd $(DEXE) && \
	$(RM) *.* /S /F