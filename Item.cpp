/*********************************************************************
** program name: labyrinth / item.cpp
** author: kelly thomson
** date: 12-10-2019
** description: item source
*********************************************************************/
#include "Item.hpp"

/*********************************************************************
** function: parameterized constructor
*********************************************************************/
Item::Item(string name, string description, string art)
{
  item_name = name;
  item_description = description;
  item_art = art;
}

/*********************************************************************
** function: gets item name
** arguments: *
** returns: item name
*********************************************************************/
string Item::get_name()
{
  return item_name;
}

/*********************************************************************
** function: gets item description
** arguments: *
** returns: item description
*********************************************************************/
string Item::get_description()
{
  return item_description;
}

/*********************************************************************
** function: gets item art
** arguments: *
** returns: item art
*********************************************************************/
string Item::get_art()
{
  return item_art;
}
