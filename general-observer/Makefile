CXX = g++-11
CXXFLAGS = -std=c++20 -Wall -MMD -g
EXEC = obs
OBJECTS = observer.o concreteobserver.o subject.o concretesubject.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS}
