/*********************************************************************
** program name: labyrinth / itemspace.hpp
** author: kelly thomson
** date: 12-10-2019
** description: item space header - child
*********************************************************************/
#ifndef ITEMSPACE_HPP
#define ITEMSPACE_HPP

#include <iostream>

#include "Space.hpp"
#include "Player.hpp"

using namespace std;

class ItemSpace : public Space
{
  public:
    ItemSpace(string description);
    virtual bool do_menu(Player* player);

  protected:

  private:

};


#endif
