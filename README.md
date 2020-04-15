# Enter the Labyrinth

:skull_and_crossbones: :flashlight: :candle: :dagger: :bow_and_arrow: :door: :boar:
***

#### PURPOSE:
This text-based game uses pointer-linked spaces to create spaces/rooms for a user to move through and interact with.
Utilizes class inheritance and polymorphism to create spaces/rooms of different types, with unique features.


#### GAMEPLAY:
User must navigate through the labyrinth's rooms, eventually coming to the final room which contains a minotaur. In order to fight the minotaur, the user must have successfully collected 3 items that are found in the various rooms. Additionally, there is an optional item that increases the user's likelihood of winning the minotaur fight if they add it to their inventory. There is no map displayed to user, to increase the labyrinthian feel of the game without making it unnecessarily complex. The required items are also not directly communicated to the user, with the intent of sending the user back out into the labyrinth and increasing the game's difficulty. A time limit is imposed on the user in the form of a torch that goes out every 4 steps, which must be lit for the user to continue. At the start of the game, the user is provided with an item to relight the torch, but the user has the ability to drop this item to make room for others. If the item is dropped, the torch will not be relit and the user loses. The final fight with the minotaur requires no user input, and returns randomized damage points for user and minotaur until one reaches 0, returning winner.

