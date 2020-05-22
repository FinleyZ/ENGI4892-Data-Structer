CXXFLAGS=   -std=c++11 -Wall
SRCS=       factorial.cpp bubbleSortTemplate.cpp
OBJS=       ${SRCS:.cpp=.o}

all: factorial
factorial: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o factorial

factorial.o: factorial.cpp
bubbleSortTemplate.o: bubbleSortTemplate.cpp

clean:
	rm -f ${OBJS} factorial
