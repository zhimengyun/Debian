cc = g++ -g -Wall -std=c++11
OBJS = static.o include_static.o
verifyStatic:${OBJS}
	${cc} ${OBJS} -o verifyStatic
static.o:static.cpp include_static.h
	${cc} -c static.cpp
include_static.o:include_static.cpp include_static.h
	${cc} -c include_static.cpp
.PHONY clean:
	rm -f verifyStatic ${OBJS}
