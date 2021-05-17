CC=g++
STD=c++11
FLAGS= -O3 -DNDEBUG
INCLUDE_DIR=/home/tanneen/sdsl/sdsl-fork/include/
LIB_DIR=/home/tanneen/sdsl/sdsl-fork/lib/
LIBS= -lsdsl -ldivsufsort -ldivsufsort64
TARGETS= sa0 cst0 cst1 cst2 jatest intvector0

all: ${TARGETS}

sa0: sa-0.cpp
	${CC} -std=${STD} ${FLAGS} -I ${INCLUDE_DIR} -L ${LIB_DIR} $^ -o $@ ${LIBS}

cst0: cst-0.cpp
	${CC} -std=${STD} ${FLAGS} -I ${INCLUDE_DIR} -L ${LIB_DIR} $^ -o $@ ${LIBS}

cst1: cst-1.cpp
	${CC} -std=${STD} ${FLAGS} -I ${INCLUDE_DIR} -L ${LIB_DIR} $^ -o $@ ${LIBS}

cst2: cst-2.cpp
	${CC} -std=${STD} ${FLAGS} -I ${INCLUDE_DIR} -L ${LIB_DIR} $^ -o $@ ${LIBS}

jatest: ja-test.cpp
	${CC} -std=${STD} ${FLAGS} -I ${INCLUDE_DIR} -L ${LIB_DIR} $^ -o $@ ${LIBS}

debug_cst2: cst-2.cpp
	${CC} -std=${STD} ${FLAGS} -I ${INCLUDE_DIR} -L ${LIB_DIR} $^ -g -o $@ ${LIBS}

intvector0: int-vector-0.cpp
	${CC} -std=${STD} ${FLAGS} -I ${INCLUDE_DIR} -L ${LIB_DIR} $^ -o $@ ${LIBS}

.PHONY: clean
clean: 
	rm ${TARGETS}
