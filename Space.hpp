/*********************************************************************
** program name: labyrinth / space.hpp
** author: kelly thomson
** date: 12-10-2019
** description: space header - abstract parent
*********************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>

#include "Item.hpp"

using namespace std;

class Player;

class Space
{
  public:
    virtual bool do_menu(Player* player) = 0;
    Space* exits[4];
    Item* items[5];
    void add_item(Item* item);
    void remove_item(string name);
    void clear_exits();
    void clear_items();
    bool has_items();
    string art;
    void print_potion();
    void print_lit_torch();
    void print_unlit_torch();
    void print_minotaur();

  protected:
    string description;

  private:

};


#endif
