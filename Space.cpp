#include "Space.hpp"

/*********************************************************************
** function: add item
** arguments: item pointer
** returns: the item at index
*********************************************************************/
void Space::add_item(Item* item)
{
  for (int i= 0; i < 5; i++ )
  {
    if (items[i] == NULL)
    {
      items[i] = item;
      return;
    }
  }
}

/*********************************************************************
** function: clear exits
** arguments: *
** returns: clears room exits
*********************************************************************/
void Space::clear_exits()
{
  for (int i= 0; i < 4; i++ )
  {
    exits[i] = NULL;
  }
}

/*********************************************************************
** function: clear items
** arguments: *
** returns: clears items
*********************************************************************/
void Space::clear_items()
{
  for (int i= 0; i < 5; i++ )
  {
    items[i] = NULL;
  }
}

/*********************************************************************
** function: remove item
** arguments: item name
** returns: removes item from player's inventory
*********************************************************************/
void Space::remove_item(string name)
{
 for (int i= 0; i < 5; i++ )
 {
   if (items[i] != NULL)
   {
     if ( items[i]->get_name() == name)
     {
       items[i] = NULL;
       return;
     }
   }
 }
}

 /*********************************************************************
 ** function: has items
 ** arguments: *
 ** returns: if player has items or not
 *********************************************************************/
bool Space::has_items()
{
  for (int i= 0; i < 5; i++ )
  {
    if (items[i] != NULL)
    {
      return true;
    }
  }
  return false;
}

/*********************************************************************
** function: print potion
** arguments: *
** returns: prints potion ascii art
*********************************************************************/
void Space::print_potion()
{
  cout << endl;
  cout << "   [___ ]" << endl;
  cout << "    |  |" << endl;
  cout << ".-'------'-." << endl;
  cout << "|-........-|" << endl;
  cout << "|          |" << endl;
  cout << "|  health  |" << endl;
  cout << "|  potion  |" << endl;
  cout << "|          |" << endl;
  cout << "|;:       _|" << endl;
  cout << "`-.______.-'" << endl;
  cout << endl;
}

/*********************************************************************
** function: print lit torch
** arguments: *
** returns: prints lit torch ascii art
*********************************************************************/
void Space::print_lit_torch()
{
  cout << endl;
  cout << "   /|" << endl;
  cout << " /";
  cout << (char)92;
  cout << "/ /";
  cout << (char)92 << endl;
  cout << " ";
  cout << (char)92;
  cout << "  ^ /";
  cout << (char)92 << endl;
  cout << "(";
  cout << (char)92;
  cout << "/ / ^)" << endl;
  cout << "(  ^ ^  )" << endl;
  cout << " ";
  cout << (char)92;
  cout << "___/_/" << endl;
  cout << " [____]" << endl;
  cout << "  |__|" << endl;
  cout << "   ||" << endl;
  cout << "   ||" << endl;
  cout << "   ||" << endl;
  cout << endl;
}

/*********************************************************************
** function: print unlit torch
** arguments: *
** returns: prints unlit torch ascii art
*********************************************************************/
void Space::print_unlit_torch()
{
  cout << endl;
  cout << "        " << endl;
  cout << "        " << endl;
  cout << "        " << endl;
  cout << " [____]" << endl;
  cout << "  |__|" << endl;
  cout << "   ||" << endl;
  cout << "   ||" << endl;
  cout << "   ||" << endl;
  cout << endl;
}

/*********************************************************************
** function: print minotaur
** arguments: *
** returns: prints minotaur ascii art
*********************************************************************/
void Space::print_minotaur()
{
  cout << endl;
  cout << "     .   ." << endl;
  cout << "    /)  /)" << endl;
  cout << ".-.((,~,)).-," << endl;
  cout << "`-,  ";
  cout << (char)92;
  cout << " /  ,-'" << endl;
  cout << "  ( @   @ )" << endl;
  cout << "   ";
  cout << (char)92;
  cout << "     /" << endl;
  cout << "    -o.o-" << endl;
  cout << "    () ()" << endl;
  cout << "   ()()()()" << endl;
  cout << endl;
}
