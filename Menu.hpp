/*********************************************************************
** program name: labyrinth / menu.hpp
** author: kelly thomson
** date: 12-10-2019
** description: menu header
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

#include "Game.hpp"

using namespace std;

class Menu
{
  protected:
    bool quit;

  public:
    Menu();
    ~Menu();
    void display_menu();

};

#endif
