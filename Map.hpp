/*********************************************************************
** program name: labyrinth / map.hpp
** author: kelly thomson
** date: 12-10-2019
** description: map header
*********************************************************************/
#ifndef MAP_HPP
#define MAP_HPP

#include "Space.hpp"
#include "EmptySpace.hpp"
#include "ItemSpace.hpp"
#include "MinotaurSpace.hpp"

class Map
{
  public:
    Map();
    Space* get_start_space();
    void print_left_forward_right_room();
    void print_left_right_room();
    void print_left_forward_room();
    void print_forward_right_room();
    Space* get_space(int i);

  protected:

  private:
    Space* spaces[8];

};


#endif
