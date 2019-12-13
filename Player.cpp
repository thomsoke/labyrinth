/*********************************************************************
** program name: labyrinth / player.cpp
** author: kelly thomson
** date: 12-10-2019
** description: player source
*********************************************************************/
#include "Player.hpp"

/*********************************************************************
** function: parameterized constructor
*********************************************************************/
Player::Player()
{
  //instance = NULL;
  step_count = 0;
  current_room = NULL;
  for (int i = 0; i < 4; i++)
  {
    inventory[i] = NULL;
  }
  torch_lit = true;
  torch_steps = 0;

}

/*********************************************************************
** function: destructor
*********************************************************************/
Player::~Player()
{
}

/*********************************************************************
** function: adds item
** arguments: item pointer
** returns: adds item into player's inventory
*********************************************************************/
void Player::add_item(Item* item)
{
  int inventorySlot = get_available_inventory_slot();
  if (inventorySlot != -1)
  {
    inventory[inventorySlot] = item;
  }
  else
    cout << "no available inventory space" << endl;
}

/*********************************************************************
** function: has item
** arguments: string item
** returns: true if there is item with natching name is found, false
if no match found
*********************************************************************/
bool Player::has_item(string item)
{
  for (int i = 0; i < 4; i++)
  {
    if (inventory[i] != NULL)
    {
      if (inventory[i]->get_name() == item)
      {
        return true;
      }
    }
  }
  return false;
}

/*********************************************************************
** function:
** arguments:
** returns: return the index of the first empty inventory space if
there is one. returns -1 if there is no available space
*********************************************************************/
int Player::get_available_inventory_slot()
{
  for (int i = 0; i < 4; i++)
  {
    if (inventory[i] == NULL)
    {
      return i;
    }
  }
  return -1;
}

/*********************************************************************
** function: gets current step count
** arguments: *
** returns: current step count
*********************************************************************/
int Player::get_step_count()
{
  return step_count;
}

/*********************************************************************
** function: gets the current room player is in
** arguments: *
** returns: current room
*********************************************************************/
Space* Player::get_current_room()
{
  return current_room;
}

/*********************************************************************
** function: sets the current room
** arguments: Space ptr
** returns: *
*********************************************************************/
void Player::set_current_room(Space* room)
{
  current_room = room;
}

/*********************************************************************
** function: get torch_lit
** arguments: *
** returns: torch_lit bool
*********************************************************************/
bool Player::get_torch_lit()
{
  return torch_lit;
}

/*********************************************************************
** function: resets torch
** arguments: *
** returns: resets torch_steps and torch_lit
*********************************************************************/
void Player::reset_torch()
{
   torch_steps = step_count;
   torch_lit = true;
}

/*********************************************************************
** function: has items
** arguments: *
** returns: if player hs items in their inventory
*********************************************************************/
bool Player::has_items()
{
  for (int i =0; i<4; i++)
  {
    if (inventory[i] != NULL)
    {
      return true;
    }
  }
  return false;
}

/*********************************************************************
** function: prints inventory
** arguments: *
** returns: prints items in player's inventory
*********************************************************************/
void Player::print_inventory()
{
  cout << "you are currently carrying:" << endl;
  for (int i =0; i < 4; i++)
  {
    if (inventory[i] != NULL)
    {
      cout << "item " << i + 1 << " is:" << endl;
      cout << inventory[i]->get_description() << endl;
      cout << inventory[i]->get_art() << endl;
      cout << endl;
    }
  }

}

/*********************************************************************
** function: drop item
** arguments: *
** returns: allows player to choose to drop item, and choose which
item to drop
*********************************************************************/
Item* Player::drop_item()
{

  char input = ' ';
  Item* returnItem = NULL;
  while(true)
  {
    cout << "what are you going to drop?" << endl;
    for (int i = 0; i<4; i++)
    {
      if(inventory[i] != NULL)
      {
        cout << "enter " << i + 1 << " to drop " << inventory[i]->get_description() << endl;
        cout << inventory[i]->get_art() << endl;
        cout << endl;
      }
    }
    cout << "enter x to cancel dropping" << endl;
    cin >> input;
    switch(input)
    {
      case '1':
        if (inventory[0]!=NULL)
        {
          returnItem = inventory[0];
          inventory[0] = NULL;
          return returnItem;
        }
        break;
      case '2':
        if (inventory[1]!=NULL)
        {
          returnItem = inventory[1];
          inventory[1] = NULL;
          return returnItem;
        }
        break;
      case '3':
        if (inventory[2]!=NULL)
        {
          returnItem = inventory[2];
          inventory[2] = NULL;
          return returnItem;
        }
        break;
      case '4':
        if (inventory[3]!=NULL)
        {
          returnItem = inventory[3];
          inventory[3] = NULL;
          return returnItem;
        }
        break;
      case 'x':
        return NULL;
        break;

    }
  }
  return NULL;
}

/*********************************************************************
** function: move
** arguments: direction
** returns: allows player to choose which exit to use, updates step
count, updates current room, updates torch_lit
*********************************************************************/
void Player::move(int direction)
{
  if (current_room->exits[direction] == NULL)
  {
    cout << "there's no exit in that direction" << endl;
    return;
  }
if (!torch_lit)
{
  cout << "you stumble around in the darkness" << endl;
  return;
}

  set_current_room(get_current_room()->exits[direction]);
  step_count++;

  if (step_count - torch_steps >= 4)
  {
    torch_lit = false;
    cout << "your torch has gone out" << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << "        " << endl;
    cout << " [____]" << endl;
    cout << "  |__|" << endl;
    cout << "   ||" << endl;
    cout << "   ||" << endl;
    cout << "   ||" << endl;
    cout << "   ||" << endl;
    cout << endl;
  }

}
