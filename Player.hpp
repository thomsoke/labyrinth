/*********************************************************************
** program name: labyrinth / player.hpp
** author: kelly thomson
** date: 12-10-2019
** description: player header
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "Space.hpp"
#include "Item.hpp"

using namespace std;


class Player
{
  public:
    Player();
    ~Player();
    int get_step_count();
    Space* get_current_room();
    void set_current_room(Space* room);
    bool has_item(string item);
    bool has_items();
    void add_item(Item* item);
    void move(int direction);
    bool get_torch_lit();
    void reset_torch();
    void print_inventory();
    Item* drop_item();
    int get_available_inventory_slot();
  protected:

  private:
    int step_count;
    Space* current_room;
    Item* inventory[4];
    bool torch_lit;
    int torch_steps;
};


#endif
