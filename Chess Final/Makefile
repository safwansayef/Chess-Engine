
CXX = g++ -std=c++14
CXXFLAGS = -ggdb -Wall -MMD -Wextra
OBJECTS = board.o tiles.o view.o textDisplay.o graphicsDisplay.o window.o  pawn.o rook.o knight.o bishop.o king.o queen.o piece.o computer.o computer1.o computer2.o computer3.o main.o
DEPENDS = ${OBJECTS:.o=.d}
				EXEC = chess -lX11

${EXEC} : ${OBJECTS}
					${CXX} -ggdb ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
				clean :
											rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

rebuild : clean ${EXEC}
