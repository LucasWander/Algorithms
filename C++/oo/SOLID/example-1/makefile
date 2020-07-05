run: example1
	./example1

example1: main.o ContratoClt.o Estagio.o FolhaDePagamento.o ContratoPj.o
	g++ main.o ContratoClt.o Estagio.o FolhaDePagamento.o ContratoPj.o -o example1.out

main.o: main.cpp
	g++ -c main.cpp -o main.o

FolhaDePagamento.o: FolhaDePagamento.cpp FolhaDePagamento.hpp
	g++ -c FolhaDePagamento.cpp -o FolhaDePagamento.o

ContratoClt.o: ContratoClt.cpp ContratoClt.hpp
	g++ -c ContratoClt.cpp -o ContratoClt.o

ContratoPj.o: ContratoPj.cpp ContratoPj.hpp
	g++ -c ContratoPj.cpp -o ContratoPj.o

Estagio.o: Estagio.cpp Estagio.hpp
	g++ -c Estagio.cpp -o Estagio.o
