CC=g++ 

all:						chessXterm
chessXterm:	  	main.o generate.o piece.o interface.o interpreter.o save.o
						  	$(CC) -o chessXterm main.o generate.o piece.o interface.o interpreter.o save.o
main.o:			  	main.cpp
						  	$(CC) -c main.cpp
generate.o:	  	generate.cpp
						  	$(CC) -c generate.cpp
piece.o:		  	piece.cpp
						  	$(CC) -c piece.cpp
interface.o:		interface.cpp
								$(CC) -c interface.cpp
interpreter.o:	interpreter.cpp
								$(CC) -c interpreter.cpp
save.o:					save.cpp
								$(CC) -c save.cpp 
clean:
								rm -rf *.o
cleanall:				clean
								rm -rf chessXterm
