all: derle bagla calistir
derle:
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o	
	g++ -I "./include" -c ./src/Avl.cpp -o ./lib/Avl.o	
	g++ -I "./include" -c ./src/AvlDugum.cpp -o ./lib/AvlDugum.o	
	g++ -I "./include" -c ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -I "./include" -c ./src/nokta.cpp -o ./lib/nokta.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
bagla:
	g++ -o ./bin/Program ./lib/Kuyruk.o ./lib/Dugum.o ./lib/nokta.o ./lib/Avl.o ./lib/AvlDugum.o ./lib/main.o
calistir:
	./bin/Program