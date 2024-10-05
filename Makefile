PRG=gnu.exe
PRG=gcc0.exe

GCC=g++
GCCFLAGS=-Wall -Wextra -ansi -pedantic -Wunused
DRIVER0=driver.c
OBJECTS0=spvector.c


VALGRIND_OPTIONS=-q --leak-check=full
DIFF_OPTIONS=-y --strip-trailing-cr --suppress-common-lines


gcc0:
	$(GCC) -o $@.exe $(DRIVER0) $(OBJECTS0) $(GCCFLAGS) 
0 1 2 3 4 5 6 7 8 9 10 11 12 :
	@echo "should run in less than 500 ms"
	./$(PRG) $@  > studentout$@
	@echo "lines after the next are mismatches with master output -- see out$@"
	diff $(DIFF_OPTIONS) studentout$@ out$@
mem0 mem1 mem2 mem3 mem4 mem5 mem6 mem7 mem8 mem9 mem10 mem11 mem12:
	@echo "should run in less than 3000 ms"
	valgrind $(VALGRIND_OPTIONS) ./$(PRG) $(subst mem,,$@) 1>/dev/null 2> difference$@
	@echo "lines after this are memory errors"; cat difference$@
clean:
	rm -f *.exe *.o 
