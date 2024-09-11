PROJECT_DIR=.

ifeq ($(OS),Windows_NT)
	# You are using Windows
	MINGW_BIN=C:/mingw64/bin
	OPENCV_DIR=C:/opencv/build/install
	CC=${MINGW_BIN}/gcc.exe
	CXX=${MINGW_BIN}/g++.exe
else
	# You are using Linux or MacOS
	CC=gcc
	CXX=g++
endif

CFLAGS=-I${PROJECT_DIR}/include/ -std=c++11

# Using OpenCV for Visualization
OPENCV=1
OPENCV4=1
ifeq ($(OS),Windows_NT)
	ifeq ($(OPENCV), 1)
		CFLAGS+= -DOPENCV=1 -I${OPENCV_DIR}/include -std=c++11
		LDFLAGS+= -L${OPENCV_DIR}/x64/mingw/bin -lopencv_imgcodecs3413 -lopencv_core3413 -lopencv_highgui3413 -lopencv_imgproc3413
	endif
else
	ifeq ($(OPENCV), 1)
		ifeq ($(OPENCV4), 0)
			LDFLAGS+=  `pkg-config --libs opencv`
			CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv`
		else
			LDFLAGS+= `pkg-config --libs opencv4`
			CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv4`
		endif
	endif
endif



SRC_DIR=${PROJECT_DIR}/src

all: 
	@echo "You need to type either 'make data_structure' to test data structures or 'make search' to test searching algorithms"


search: ${SRC_DIR}/linked_list.cpp ${SRC_DIR}/queue.cpp ${SRC_DIR}/stack.cpp ${SRC_DIR}/graph.cpp ${SRC_DIR}/bfs.cpp ${SRC_DIR}/rdfs.cpp ${SRC_DIR}/dfs.cpp ${SRC_DIR}/articulation_and_bridge.cpp ${SRC_DIR}/main.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/search
	./bin/search

data_structure: ${SRC_DIR}/linked_list.cpp ${SRC_DIR}/stack.cpp ${SRC_DIR}/data_structure_test.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/data_structure
	./bin/data_structure

