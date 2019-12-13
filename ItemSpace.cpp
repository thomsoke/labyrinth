/*********************************************************************
** program name: labyrinth / emptyspace.cpp
** author: kelly thomson
** date: 12-10-2019
** description: item space source - child
*********************************************************************/
#include "ItemSpace.hpp"

/*********************************************************************
** function: parameterized constructor
*********************************************************************/
ItemSpace::ItemSpace(string description)
{
  this->description = description;
  clear_exits();
  clear_items();
}

/*********************************************************************
** function: do menu
** arguments: player pointer
** returns: menu of options player can do in this room
*********************************************************************/
bool ItemSpace::do_menu(Player* player)
{
  bool gotInput = false;
  char input = ' ';
  //int temp = 0;

  while (gotInput == false)
  {
    cout << description << endl << endl;

    if (player->get_torch_lit())
    {
      print_lit_torch();

      if( has_items() )
      {
        cout << "there are items on the ground" << endl;
        cout << "it really seems like something from this room is going to be very important" << endl;
        for (int i =0; i<5; i++)
        {
          if (items[i] != NULL)
          {
            cout << items[i]->get_description() << endl;
            cout << items[i]->get_art() << endl;
            cout << endl;
          }
        }
        cout << "enter 0 to pick up the items" << endl;
      }

      for (int i = 0; i < 4; i++ )
      {
        if (exits[i] != NULL)
        {
          switch(i)
          {
            case 0:
              cout << "enter 1 to exit to the top" << endl;
              break;
            case 1:
              cout << "enter 2 to exit to the right" << endl;
              break;
            case 2:
              cout << "enter 3 to exit to the bottom" << endl;
              break;
            case 3:
              cout << "enter 4 to exit to the left" << endl;
              break;
            default:
              cout << "default" << endl;
              break;
          }
        }
      }
      cout << endl;

      if (player->has_items())
      {
        cout << "enter i to view your items" << endl;
        cout << "enter d to drop an item" << endl;
      }

      cout << "enter q to quit game" << endl;

    }
    else
    {
      if (player->has_item("matches"))
      {
        cout << "good thing you have some matches!" << endl;
        cout << "enter 5 to relight your torch" << endl;

      }
      else
      {
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "without a lit torch you can't do anything and now you lose" << endl;
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << endl;

        return 0;
      }
    }

    cin >> input;
    switch(input)
    {
      case '1':
        player->move(0);
        gotInput = true;
        break;
      case '2':
        player->move(1);
        gotInput = true;
        break;
      case '3':
        player->move(2);
        gotInput = true;
        break;
      case '4':
        player->move(3);
        gotInput = true;
        break;
      case '5':
        if (player->get_torch_lit() == false && player->has_item("matches"))
        player->reset_torch();
        gotInput = true;
        break;
      case '0':
        if ( has_items() )
          {
            bool gotAll = true;
            for (int i=0; i <5; i++)
            {
              if (items[i] != NULL)
              {
                if (player->get_available_inventory_slot() != -1)
                {

                  player->add_item(items[i]);
                  remove_item(items[i]->get_name());
                }
                else
                {
                  gotAll = false;
                  cout << "you don't have any more room in your inventory! you might need to leave something behind" << endl;
                }
              }
            }
            if (gotAll)
              cout << "you picked up all the items" << endl;
            gotInput = true;
          }
          break;
      case 'i':
        if (player->has_items())
        {
          player->print_inventory();
        }
        break;
      case 'd':
        if (player->has_items())
        {
          Item* droppedItem = player->drop_item();
          if (droppedItem != NULL)
          {
            add_item(droppedItem);
          }
        }
        break;
      case 'q':
        return false;
        break;
    }

  }
return true;

}
