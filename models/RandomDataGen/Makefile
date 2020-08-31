
CXX = g++ 
CFLAGS = -std=c++11 -Wall

.PHONY = test test_make
.DEFAULT_GOAL := test

test: RandomDataGen.cpp RandomDataGenUnitTests.cpp RandomDataGen.hpp 
	@${CXX} ${CFLAGS} -o RandomDataGenUnitTests RandomDataGenUnitTests.cpp RandomDataGen.cpp

clean: 
	rm RandomDataGenUnitTests

