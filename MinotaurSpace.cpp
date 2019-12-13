/*********************************************************************
** program name: labyrinth / minotaurspace.cpp
** author: kelly thomson
** date: 12-10-2019
** description: minotaur space source - child
*********************************************************************/
#include "MinotaurSpace.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

/*********************************************************************
** function: parameterized constructor
*********************************************************************/
MinotaurSpace::MinotaurSpace(string description)
{
  this->description = description;
  clear_exits();
  clear_items();
  player_health = 0;
  minotaur_health = 0;
  player_roll = 0;
  minotaur_roll = 0;
  dead = false;
}


/*********************************************************************
** function: do menu
** arguments: player pointer
** returns: menu of options player can do in this room
*********************************************************************/
bool MinotaurSpace::do_menu(Player* player)
{
  bool gotInput = false;
  char input = ' ';


  while (gotInput == false)
  {
    if (player->get_torch_lit())
    {
      print_lit_torch();

      cout << description << endl << endl;

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
//      if (player->has_items())
//      {
//        cout << "enter i to view your items" << endl;
//      }

      if (player->has_item("shield") && player->has_item("bow") && player->has_item("arrows"))
      {
        cout << "enter f to fight the minotaur" << endl;
      }
      else
      {
        cout << "you must be able to protect and defend yourself" << endl;
        cout << "before you fight the minotaur..." << endl;
        cout << "continue searching the labyrinth for items that might help you" << endl;
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

      case 'i':
        if (player->has_items())
        {
          player->print_inventory();
        }
        break;

      case 'f':
        if (player->has_items())
        {
          // checks to see if player has all items needed to fight minotaur
          if (player->has_item("shield") && player->has_item("bow") && player->has_item("arrows"))
          {
            // fight
            cout << "you have collected the shield, bow, and arrows..." << endl;
            cout << "you are ready to take on the minotaur" << endl;
            print_minotaur();
              if (player->has_item("potion"))     // fight with player advantage
              {
                cout << "you have a bottle of health potion in your inventory" << endl;
                cout << "this gives you the ability to revive yourself and" << endl;
                cout << "continue fighting the first time you are injured" << endl;
                print_potion();

              // ACTUAL FIGHT SEQUENCE
                player_health = 20;
                minotaur_health = 10;

                cout << "you arm yourself with your weapons and enter the minotaur's lair" << endl;
                cout << "hopefully you make it through this alive..." << endl;
                cout << endl;
                cout << endl;
                cout << "** at start of fight player health is " << player_health << endl;
                cout << "** at start of fight minotaur health is " << minotaur_health << endl;

                do
                {
                  if (player_health <= 0)
                  {
                    dead = true;
                    cout << endl;
                    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
                    cout << "the minotaur killed you, your soul is stuck here forever" << endl;
                    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
                    cout << endl;
                  }
                  else if (minotaur_health <= 0)
                  {
                    dead = true;
                    cout << endl;
                    cout << "****************************************************************" << endl;
                    cout << "you killed the minotaur and get to escape the labyrinth!" << endl;
                    cout << "****************************************************************" << endl;
                    cout << endl;
                  }
                  else
                  {
                    for (int i = 0; i < 5; i++)
                    {
                      player_roll = (rand() % 5);
                    }
                    for (int i = 0; i < 5; i++)
                    {
                      minotaur_roll = (rand() % 7);
                    }

                    player_health = player_health - player_roll;
                    minotaur_health = minotaur_health - minotaur_roll;

                    // sets to zero if health becomes negative number
                      if (player_health <= 0)
                      {
                        player_health = 0;
                      }
                      if (minotaur_health <= 0)
                      {
                        minotaur_health = 0;
                      }

                  // prints health at end of each round
                    cout << "player health is " << player_health << endl;
                    cout << "minotaur health is " << minotaur_health << endl;
                  }
                } while (dead == false);      // repeats until one is dead
                return 0;
              }

              else      // regular fight
              {
              // ACTUAL FIGHT SEQUENCE
                minotaur_health = 20;
                player_health = 20;

                cout << "you arm yourself with your weapons and enter the minotaur's lair" << endl;
                cout << "hopefully you make it through this alive..." << endl;
                cout << endl;
                cout << endl;
                cout << "** at start of fight player health is " << player_health << endl;
                cout << "** at start of fight minotaur health is " << minotaur_health << endl;

                do
                {
                  if (player_health <= 0)
                  {
                    dead = true;
                    cout << endl;
                    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
                    cout << "the minotaur killed you, your soul is stuck here forever" << endl;
                    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
                    cout << endl;
                  }
                  else if (minotaur_health <= 0)
                  {
                    dead = true;
                    cout << endl;
                    cout << "****************************************************************" << endl;
                    cout << "you killed the minotaur and get to escape the labyrinth!" << endl;
                    cout << "****************************************************************" << endl;
                    cout << endl;
                  }
                  else
                  {
                    for (int i = 0; i < 5; i++)
                    {
                      player_roll = (rand() % 5);
                    }
                    for (int i = 0; i < 5; i++)
                    {
                      minotaur_roll = (rand() % 7);
                    }

                    player_health = player_health - player_roll;
                    minotaur_health = minotaur_health - minotaur_roll;

                    // sets to zero if health becomes negative number
                      if (player_health <= 0)
                      {
                        player_health = 0;
                      }
                      if (minotaur_health <= 0)
                      {
                        minotaur_health = 0;
                      }

                  // prints health at end of each round
                    cout << "player health is " << player_health << endl;
                    cout << "minotaur health is " << minotaur_health << endl;
                  }
                } while (dead == false);      // repeats until one is dead
                return 0;
              }

          }
          else
          {
            cout << "you must be able to protect and defend yourself" << endl;
            cout << "before you fight the minotaur..." << endl;
            cout << "continue searching the labyrinth for items that might help you" << endl;
            break;
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








































//
