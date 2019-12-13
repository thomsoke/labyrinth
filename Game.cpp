/*********************************************************************
** program name: labyrinth / game.cpp
** author: kelly thomson
** date: 12-10-2019
** description: game source
*********************************************************************/
#include "Game.hpp"

/*********************************************************************
** function: parameterized constructor
*********************************************************************/
Game::Game()
{
}

/*********************************************************************
** function: runs the game
** arguments: *
** returns: the game
*********************************************************************/
void Game::run()
{
  Map* map = new Map();
  Player* player = new Player();
  Item* startingItem = new Item("matches","box of matches",
  "_________\n"
  "\\        \\ \n"
  " \\        \\ \n"
  "  \\        \\ \n"
  "   \\        \\ \n"
  "    )--------)\n"
  "   /        /\n"
  "  /        /\n"
  " /......../\n"
  "/____<()_/\n"
  "      ||\n"
  "      ||\n"
  "      ||\n"
  "      ||\n"
  "      ||");


  print_start_message();

  map->print_left_forward_right_room();     // prints the initial room

  player->set_current_room( map->get_start_space() );
  player->add_item(startingItem);


    while (player->get_current_room()->do_menu(player))
    {
    // prints the ascii art corresponding to each room
      if (player->get_current_room() == map->get_space(0) || player->get_current_room() == map->get_space(2) || player->get_current_room() == map->get_space(4))
      {

        map->print_left_forward_right_room();
      }
      else if (player->get_current_room() == map->get_space(7))
      {
        map->print_left_right_room();
      }
      else if (player->get_current_room() == map->get_space(3) || player->get_current_room() == map->get_space(6))
      {
        map->print_left_forward_room();
      }
      else if (player->get_current_room() == map->get_space(1) || player->get_current_room() == map->get_space(5))
      {
        map->print_forward_right_room();
      }
    }

// frees memory
  delete startingItem;
  delete map;
  delete player;
}


/*********************************************************************
** function: print start message
** arguments: *
** returns: prints initial message to user explaining the game
*********************************************************************/
void Game::print_start_message()
{
  cout << endl;
  cout << "*****************************************************************************" << endl;
  cout << "*****************************************************************************" << endl;
  cout << "      LOST IN A LABYRINTH..." << endl;
  cout << endl;
  cout << "you find yourself inside of a huge labyrinth" << endl;
  cout << "the rooms are dark and damp and made of solid stone" << endl;
  cout << "the only way out is through..." << endl;
  cout << endl;
  cout << "you are armed only with a torch, and matches to relight the torch" << endl;
  cout << "you must enter the labyrinth and fight the minotaur to escape" << endl;
  cout << "there may be items you encounter along the way that are necessary" << endl;
  cout << "or required to win this fight" << endl;
  cout << endl;
  cout << "choose your path wisely, or you may end up lost in the labyrinth forever..." << endl;
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
  cout << "*****************************************************************************" << endl;
  cout << "*****************************************************************************" << endl;
  cout << endl;
}
