/*********************************************************************
** program name: labyrinth / menu.cpp
** author: kelly thomson
** date: 12-10-19
** description: menu source
*********************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Menu.hpp"

using namespace std;

/*********************************************************************
** function: default constructor
*********************************************************************/
Menu::Menu()
{
}

/*********************************************************************
** function: destructor
*********************************************************************/
Menu::~Menu()
{
}

/*********************************************************************
** function: display menu
** arguments: *
** returns: *
*********************************************************************/
void Menu::display_menu()
{
  Game g;
  string get_input;
  int temp;

  quit = false;

  do
  {
    cout << endl;
    cout << "______________________________________________" << endl;
    cout << "-------------------- MENU --------------------" << endl;
    cout << "   1 --- play game" << endl;
    cout << "   2 --- quit game" << endl;
    cout << "______________________________________________" << endl;

    do
    {
      cout << "make selection: " << endl;
      getline(cin, get_input);
    } while(get_input != "1" && get_input != "2");
    temp = atoi(get_input.c_str());

    switch (temp)
    {
      case 1:
        cout << "entering game" << endl;
        g.run();
        break;

      case 2:
        quit = true;
        cout << "quitting game" << endl;
        break;

      default:
        cout << "invalid" << endl;
        break;
    }
  } while (!quit);

}
