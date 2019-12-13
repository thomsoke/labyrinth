/*********************************************************************
** program name: labyrinth / emptyspace.hpp
** author: kelly thomson
** date: 12-10-2019
** description: empty space header - child
*********************************************************************/
#ifndef EMPTYSPACE_HPP
#define EMPTYSPACE_HPP

#include <iostream>

#include "Space.hpp"
#include "Player.hpp"

using namespace std;

class EmptySpace : public Space
{
  public:
    EmptySpace(string description);
    virtual bool do_menu(Player* player);

  protected:

  private:

};


#endif
