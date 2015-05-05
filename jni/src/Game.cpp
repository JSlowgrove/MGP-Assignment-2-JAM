#include "Game.h"
#include "SDL.h"

/**************************************************************************************************************/

/*Constructs the game object*/
Game::Game(JAM_StateManager * stateManager, SDL_Renderer* renderer, int screenWidth, int screenHeight)
	: JAM_State(stateManager, renderer, screenWidth, screenHeight)
{
	/*initialise the texture*/
	texture = new JAM_Texture("img/JAM.png", renderer);

	/*initialise the music*/
	music = new JAM_Audio("aud/Cipher.ogg", true);
}

/**************************************************************************************************************/

/*Destructs the game object*/
Game::~Game()
{
	/*stop music*/
	music->stopAudio();
	/*delete audio pointers*/
	delete music;
	/*delete pointers*/
	delete texture;
}

/**************************************************************************************************************/

/*handles inputs*/
bool Game::input()
{
	/*Check for user input*/
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{
		switch (incomingEvent.type)
		{
		case SDL_QUIT: /*If player closes the window, end the game loop*/

			SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "Exiting Main Loop");
			return false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			if (incomingEvent.button.button == SDL_TOUCH_MOUSEID || incomingEvent.button.button == SDL_BUTTON_LEFT)
				SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Touch/Click");
			break;
		case SDL_KEYDOWN:

			switch (incomingEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE: /*If Escape is pressed, end the game loop*/

				SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "Exiting Main Loop");
				return false;
				break;

#ifdef __ANDROID__

			case SDLK_AC_BACK: /*If Back is pressed on the phone, end the game loop*/

				SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "Exiting Main Loop");
				return false;
				break;

#endif

			}
			break;
		}
	}
	return true;
}

/**************************************************************************************************************/

/*updates the game*/
void Game::update(float dt)
{
	/*keep the music playing*/
	music->startAudio();
}

/**************************************************************************************************************/

/*draws the game*/
void Game::draw()
{
	/*draw the texture*/
	texture->pushToScreen(renderer, 200, 180, 100, 100);
}