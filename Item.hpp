/*********************************************************************
** program name: labyrinth / item.hpp
** author: kelly thomson
** date: 12-10-2019
** description: item header
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item
{
  public:
    Item(string name, string description, string art);
    string get_name();
    string get_description();
    string get_art();

  protected:

  private:
    string item_name;
    string item_description;
    string item_art;

};


#endif
