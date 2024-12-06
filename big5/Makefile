CXX = g++
CXXFLAGS = -std=c++14 -Wall -fPIE
LDFLAGS = -pie

EXEC = bst
OBJECTS = main.o BST.o BST-impl.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} ${LDFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
