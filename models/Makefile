CXX = g++ 
CFLAGS = -std=c++11 -Wall
OBJECTS = main.o display.o RandomDataGen.o utility.o

.PHONY = all display.o random_data_gen.o utility.o
.DEFAULT_GOAL := all

all: $(OBJECTS)
	@$(CXX) $(CFLAGS) -o maylib $(OBJECTS) -lreadline

# these commands are not suppressed so that the files being recompiled are listed

main.o: main.cpp RandomDataGen/RandomDataGen.hpp
	$(CXX) $(CFLAGS) -c main.cpp

display.o: display.cpp display.hpp
	$(CXX) $(CFLAGS) -c display.cpp

RandomDataGen.o: RandomDataGen/RandomDataGen.cpp RandomDataGen/RandomDataGen.hpp
	$(CXX) $(CFLAGS) -c RandomDataGen/RandomDataGen.cpp 

utility.o: Extra/utility.cpp Extra/utility.hpp
	$(CXX) $(CFLAGS) -c Extra/utility.cpp

clean: 
	@rm maylib $(OBJECTS)
