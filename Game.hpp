/*********************************************************************
** program name: labyrinth / game.hpp
** author: kelly thomson
** date: 12-10-2019
** description: game header
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <string>

#include "Space.hpp"
#include "EmptySpace.hpp"
#include "Player.hpp"
#include "Map.hpp"

using namespace std;

class Game
{
  public:
    Game();
    void run();
    void print_start_message();

  protected:

  private:

};


#endif
