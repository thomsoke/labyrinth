/*********************************************************************
** program name: labyrinth / minotaurspace.hpp
** author: kelly thomson
** date: 12-10-2019
** description: minotaur space header - child
*********************************************************************/
#ifndef MINOTAURSPACE_HPP
#define MINOTAURSPACE_HPP

#include <iostream>

#include "Space.hpp"
#include "Player.hpp"

using namespace std;

class MinotaurSpace : public Space
{
  public:
    MinotaurSpace(string description);
    virtual bool do_menu(Player* player);

  protected:
    int player_health;
    int minotaur_health;
    int player_roll;
    int minotaur_roll;
    bool dead;

  private:

};


#endif
