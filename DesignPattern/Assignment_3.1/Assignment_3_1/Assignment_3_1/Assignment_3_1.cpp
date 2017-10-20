// Assignment_3_1.cpp
#include <vld.h>
#include "World.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
//---------------------------------------------------------------------------------------------------------------------
// Game Design:
// 
// Player:
// The game is a grid-based world where the player is represented by the '@' symbol.  The player moves around with 
// WASD.  You can quit the game by pressing 'q'.  The player starts with 10 hit points.
// 
// Bombs:
// Scattered in the world are bombs, which are shown with an asterisk (*).  Touching one of this tiles will cause it 
// explode, damaging the player, and change its icon to a pound sign (#).  The bomb will now be destroyed, so touching
// it further won't do anything.
// 
// Treasure Chests:
// Treasure chests are shown with a dollar sign ($).  Collecting a treasure chest treasure will add a random amount 
// of gold to the player's inventory and cause the object to disappear.  Be careful!  Some treasure chests are 
// actually mimics and will explode just like a bomb!  There is guaranteed to be at least one mimic in each level.
// 
// Exit:
// At the bottom right is the exit, show with a capital H.  Entering this tile will end the game and give you your 
// score.
// 
// Win/Lose:
// The object of the game is to rack up as many points as possible.  You lose points when your hit points drop and 
// for every move you make.  You gain points for collecting gold.  If you can make it to the exit tile, you win.  If 
// your hit points drop to 0 or you fall off the edge of the map, you die and the game is over.
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// Assignment:
// 
// ***8) Add a teleporter tile.  It should work like this:
//        a) Teleporter tiles always come in pairs.
//        b) This pair is linked.  When the player steps onto one, he will be teleported to the other.
//        c) There is a small chance you will get one or more teleporter pairs when the world is first generated.
//           Play with the probability to make it feel right.
//        d) Their symbol should be an ampersand (&).
//        e) For this feature, you will be graded HEAVILY on how clean the teleporter's architecture has been 
//           implemented.  If it works but the code is super messy and/or hacky, you might as well have not done at 
//           all.
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// Your notes go here:
// 
//  No memory leak!
//---------------------------------------------------------------------------------------------------------------------

int main()
{
	srand((unsigned int)time(nullptr));
	World* pWorld = World::GetInstance();

	// create the world
	pWorld->Init(k_worldWidth, k_worldHeight);

	// create the player
	pWorld->CreatePlayer();

	// now that the player has been placed, generate the world
	pWorld->GenerateWorld();

    // main game loop
    while (!pWorld->IsGameOver())
    {
		pWorld->Draw();
		pWorld->Update();
    }

	pWorld->FreeInstance();

	return 0;
}

