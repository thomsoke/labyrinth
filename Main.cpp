/*********************************************************************
** program name: labyrinth / main.cpp
** author: kelly thomson
** date: 12-10-2019
** description: main
*********************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Menu.hpp"
#include "Game.hpp"

using namespace std;

int main()
{
srand(time(NULL));

  Menu m;
  m.display_menu();

return 0;
}
