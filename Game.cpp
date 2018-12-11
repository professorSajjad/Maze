#include "Game.h"

Game::Game(Map *map, Avatar* avatar){
	this->map = map;
	this->avatar = avatar;
}
Game::~Game(){
}
void Game::listenToInputKey(){
	while (true){
		while(kbhit() > 0){
			int pressedKey = getch();
			if(pressedKey == 224)
				continue;
			//after here pressedKey is usable
			map->draw();
			avatar->move(pressedKey);
			avatar->draw();
		}
	}
}
void Game::start(){
	map->build();
	map->draw();
	ConsoleController::goTo(0,0);
	cout << Avatar::ANDICATOR;
	listenToInputKey();
}
