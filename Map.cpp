/*********************************************************************
** program name: labyrinth / map.cpp
** author: kelly thomson
** date: 12-10-2019
** description: map source
*********************************************************************/
#include "Map.hpp"
#include "Space.hpp"
#include "EmptySpace.hpp"
#include "ItemSpace.hpp"
#include "MinotaurSpace.hpp"

/*********************************************************************
** function: parameterized constructor
** defines all of the different rooms and their exit options
*********************************************************************/
Map::Map()
{
// define all the map pieces
  spaces[0] = new EmptySpace("Starting Room");
  spaces[1] = new ItemSpace("Room 1");
  spaces[2] = new EmptySpace("Room 2");
  spaces[3] = new ItemSpace("Room 3");
  spaces[4] = new ItemSpace("Room 4");
  spaces[5] = new EmptySpace("Room 5");
  spaces[6] = new ItemSpace("Room 6");
  spaces[7] = new MinotaurSpace("Final Room");


////// STARTING ROOM //////
  spaces[0]->exits[0] = spaces[1];
  spaces[0]->exits[1] = spaces[2];
  spaces[0]->exits[2] = spaces[4];
  spaces[0]->exits[3] = spaces[5];
  //spaces[0]->art = ":) \n hewofuewf";

////// ROOM 1 //////
  spaces[1]->exits[1] = spaces[3];
  spaces[1]->exits[2] = spaces[0];
  spaces[1]->add_item(new Item("arrows","a bundle of arrows",
  ">>>-------------->\n >>>-------------->\n"
  ">>>-------------->"));

////// ROOM 2 //////
  spaces[2]->exits[0] = spaces[3];
  spaces[2]->exits[2] = spaces[6];
  spaces[2]->exits[3] = spaces[0];

////// ROOM 3 //////
  spaces[3]->exits[2] = spaces[2];
  spaces[3]->exits[3] = spaces[1];
  spaces[3]->add_item(new Item("shield","old rusty shield",
  "      _._\n"
  "  _.-`   `-._\n"
  "|`     |     `|\n"
  "|      |      |\n"
  "|    - | -    |\n"
  "\\      |      /\n"
  " \\     |     /\n"
  "  \\.   |   ./\n"
  "   \\.     ./\n"
  "    \\.___./"
  ));

////// ROOM 4 //////
  spaces[4]->exits[0] = spaces[0];
  spaces[4]->exits[1] = spaces[6];
  spaces[4]->exits[3] = spaces[7];
  spaces[4]->add_item(new Item("potion","bottle of health potion",
  "   [___ ]\n"
  "    |  |\n"
  ".-'------'-.\n"
  "|-........-|\n"
  "|          |\n"
  "|  health  |\n"
  "|  potion  |\n"
  "|          |\n"
  "|;:       _|\n"
  "`-.______.-'"
  ));

////// ROOM 5 //////
  spaces[5]->exits[1] = spaces[0];
  spaces[5]->exits[2] = spaces[7];

////// ROOM 6 //////
  spaces[6]->exits[0] = spaces[2];
  spaces[6]->exits[3] = spaces[4];
  spaces[6]->add_item(new Item("bow","wooden longbow",
  "(\n"
  "((\n"
  "| \\\n"
  "| \\\\\n"
  "|  \\\\\n"
  "|   \\\\\n"
  "|    \\\\\n"
  "|     ))\n"
  "|     ||\n"
  "|     ))\n"
  "|    //\n"
  "|   //\n"
  "|  //\n"
  "| //\n"
  "| /\n"
  "((\n"
  "("
  ));

////// FINAL ROOM //////
  spaces[7]->exits[0] = spaces[5];
  spaces[7]->exits[1] = spaces[4];

}

/*********************************************************************
** function: get start space
** arguments: *
** returns: starting room (always index 0)
*********************************************************************/
Space* Map::get_start_space()
{
  return spaces[0];
}

/*********************************************************************
** function: get space
** arguments: index
** returns: space at index
*********************************************************************/
Space* Map::get_space(int i)
{
  return spaces[i];
}

/*********************************************************************
** function: prints room
** arguments: *
** returns: prints room exits - left & forward & right
*********************************************************************/
void Map::print_left_forward_right_room()
{
  cout << "\\                           /" << endl;
  cout << ".\\                         /." << endl;
  cout << "..\\                       /.." << endl;
  cout << "...]                     [..." << endl;
  cout << "...]___               ___[..." << endl;
  cout << "...]  ]\\             /[  [..." << endl;
  cout << "...]  ].\\           /.[  [..." << endl;
  cout << "...]  ]..\\ _______ /..[  [..." << endl;
  cout << "...]  ]...]       [...[  [..." << endl;
  cout << "...]  ]...]       [...[  [..." << endl;
  cout << "...]  ]...]       [...[  [..." << endl;
  cout << "...]  ]...]       [...[  [..." << endl;
  cout << "...]  ]../         \\..[  [..." << endl;
  cout << "...]  ]./           \\.[  [..." << endl;
  cout << "...]__]/             \\[__[..." << endl;
  cout << "...]                     [..." << endl;
  cout << "...]                     [..." << endl;
  cout << "../                       \\.." << endl;
  cout << "./                         \\." << endl;
  cout << "/                           \\" << endl;

}

/*********************************************************************
** function: prints room
** arguments: *
** returns: prints room exits - left & right
*********************************************************************/
void Map::print_left_right_room()
{
  cout << "\\                           /" << endl;
  cout << ".\\                         /." << endl;
  cout << "..\\                       /.." << endl;
  cout << "...]                     [..." << endl;
  cout << "...]_____________________[..." << endl;
  cout << "...]  ]...............[  [..." << endl;
  cout << "...]  ]...............[  [..." << endl;
  cout << "...]  ]...............[  [..." << endl;
  cout << "...]  ]...............[  [..." << endl;
  cout << "...]  ]...............[  [..." << endl;
  cout << "...]  ]...............[  [..." << endl;
  cout << "...]  ]...............[  [..." << endl;
  cout << "...]  ]...............[  [..." << endl;
  cout << "...]  ]...............[  [..." << endl;
  cout << "...]__]...............[__[..." << endl;
  cout << "...]                     [..." << endl;
  cout << "...]                     [..." << endl;
  cout << "../                       \\.." << endl;
  cout << "./                         \\." << endl;
  cout << "/                           \\" << endl;
}

/*********************************************************************
** function: prints room
** arguments: *
** returns: prints room exits - left & forward
*********************************************************************/
void Map::print_left_forward_room()
{
  cout << "\\                         /" << endl;
  cout << ".\\                       /." << endl;
  cout << "..\\                     /.." << endl;
  cout << "...]                   /..." << endl;
  cout << "...]___               /...." << endl;
  cout << "...]  ]\\             /....." << endl;
  cout << "...]  ].\\           /......" << endl;
  cout << "...]  ]..\\ _______ /......." << endl;
  cout << "...]  ]...]       [........" << endl;
  cout << "...]  ]...]       [........" << endl;
  cout << "...]  ]...]       [........" << endl;
  cout << "...]  ]...]       [........" << endl;
  cout << "...]  ]../         \\......." << endl;
  cout << "...]  ]./           \\......" << endl;
  cout << "...]__]/             \\....." << endl;
  cout << "...]                  \\...." << endl;
  cout << "...]                   \\..." << endl;
  cout << "../                     \\.." << endl;
  cout << "./                       \\." << endl;
  cout << "/                         \\" << endl;
}

/*********************************************************************
** function: prints room
** arguments: *
** returns: prints room exits - forward & right
*********************************************************************/
void Map::print_forward_right_room()
{
  cout << "\\                         /" << endl;
  cout << ".\\                       /." << endl;
  cout << "..\\                     /.." << endl;
  cout << "...\\                   [..." << endl;
  cout << "....\\               ___[..." << endl;
  cout << ".....\\             /[  [..." << endl;
  cout << "......\\           /.[  [..." << endl;
  cout << ".......\\ _______ /..[  [..." << endl;
  cout << "........]       [...[  [..." << endl;
  cout << "........]       [...[  [..." << endl;
  cout << "........]       [...[  [..." << endl;
  cout << "........]       [...[  [..." << endl;
  cout << "......./         \\..[  [..." << endl;
  cout << "....../           \\.[  [..." << endl;
  cout << "...../             \\[__[..." << endl;
  cout << "..../                  [..." << endl;
  cout << ".../                   [..." << endl;
  cout << "../                     \\.." << endl;
  cout << "./                       \\." << endl;
  cout << "/                         \\" << endl;
}
