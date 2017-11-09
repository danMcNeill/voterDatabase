#
# Specifiy the target
all:	Voter

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Voter:	Voter.o VoterDatabase.o main.o
	g++  Voter.o VoterDatabase.o main.o -o Voter

# Specify how the object files should be created from source files
Voter.o: Voter.cpp
	g++ -c Voter.cpp
VoterDatabase.o: VoterDatabase.cpp
	g++ -c VoterDatabase.cpp
main.o: main.cpp
	g++ -c main.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Voter

