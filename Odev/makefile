all: derle bagla calistir
derle:
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -I "./include" -c ./src/Bagliliste.cpp -o ./lib/Bagliliste.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
bagla:
	g++ -o ./bin/Program ./lib/Bagliliste.o ./lib/Dugum.o ./lib/main.o
calistir:
	./bin/Program