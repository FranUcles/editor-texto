salida.out: main.o ConjuntoPalabras.o InterpreteComandos.o Tokens.o
	g++ main.o ConjuntoPalabras.o InterpreteComandos.o Tokens.o
main.o: main.cpp InterpreteComandos.h Tokens.h ConjuntoPalabras.h
	g++ -c main.cpp
ConjuntoPalabras.o: ConjuntoPalabras.cpp ConjuntoPalabras.h
	g++ -c ConjuntoPalabras.cpp
InterpreteComandos.o: InterpreteComandos.cpp InterpreteComandos.h ConjuntoPalabras.h
	g++ -c InterpreteComandos.cpp
Tokens.o: Tokens.cpp Tokens.h
	g++ -c Tokens.cpp