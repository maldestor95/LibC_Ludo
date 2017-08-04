#----------------Makefile for Unit Testing ------------

# Destination file
EXE=test

# Sources file

# Paths
DSRC = src
DINC = ../lib
DOBJ = ../obj
DEXE = ../bin

# Compiler flags
CFLAGS = -Wall -g
LFLAGS =-L$(CMOCKA) -I$(CMOCKAHEADER) -l cmocka.dll

#libraries
CMOCKA="C:\Program Files (x86)\cmocka\lib"
CMOCKAHEADER="C:\Program Files (x86)\cmocka\include"

# Commands
CC = gcc 
LK = ld
RM = del

#------------------------ Project list----------------------

#Rebuild all target

.PHONY: RecursivedirTest.c	
RecursivedirTest.c:Recursivedir.c
	@echo -----------------------------------
	@echo Building $@
	@echo -----------------------------------
	$(CC)  $@ $(CFLAGS) $(LFLAGS) $(DOBJ)/$(subst .c,.o,$^) -o $(DEXE)/subst($a,.c,.exe)
	
	@echo -----------------------------------
	@echo Executing $@
	$(DEXE)/subst($a,.c,.exe)
	@echo -----------------------------------

Recursivedir.c:
	$(CC) -c $(DINC)/$@ $(CFLAGS) -o $(DOBJ)/$(subst .c,.o,$@)

.PHONY: clean
clean:
	cd $(DOBJ) && \
	$(RM) *.o
	cd $(DEXE) && \
	$(RM) *.* /S /F