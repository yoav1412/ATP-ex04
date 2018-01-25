COMP = g++-5.3.0
#put all your object files here
OBJS = BooleanMasks.o Groups.o PuzzlePiece.o main.o #objects should be placed here!
#The executabel filename DON'T CHANGE
EXEC = ex4
CPP_COMP_FLAG = -std=c++14 -Wall -Wextra -Werror -pedantic-errors -DNDEBUG

$(EXEC): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -o $@
BooleanMasks.o: BooleanMasks.cpp
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
Groups.o: Groups.cpp
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
PuzzlePiece.o: PuzzlePiece.cpp
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
main.o: main.cpp ex4headers.h #put dependencies here!
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
clean:
	rm -f $(OBJS) $(EXEC)
