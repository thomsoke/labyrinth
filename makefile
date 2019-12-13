final: Main.o Game.o Menu.o Space.o EmptySpace.o ItemSpace.o MinotaurSpace.o Player.o Item.o Map.o
	g++ Main.o Game.o Menu.o Space.o EmptySpace.o ItemSpace.o MinotaurSpace.o Player.o Item.o Map.o -o final

Main.o: Main.cpp
	g++ -c Main.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

Menu.o: Menu.cpp
	g++ -c Menu.cpp

Space.o: Space.cpp
	g++ -c Space.cpp

EmptySpace.o: EmptySpace.cpp
	g++ -c EmptySpace.cpp

ItemSpace.o: ItemSpace.cpp
	g++ -c ItemSpace.cpp

MinotaurSpace.o: MinotaurSpace.cpp
	g++ -c MinotaurSpace.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Item.o: Item.cpp
	g++ -c Item.cpp

Map.o: Map.cpp
	g++ -c Map.cpp

clean:
	rm *.o final
