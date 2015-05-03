#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "JAM/Texture.h"

int main(int argc, char *argv[])
{
	/*Initialise SDL needed for desktop*/
	/*
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Check SDL initialisation
	{
		//Failed initialisation
		SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Failed to initialise SDL");
		return -1;
	}
	*/
	
	/*Initialise SDL_ttf*/
	if (TTF_Init() < 0) /*Check SDL_ttf initialisation*/
	{
		/*Failed initialisation*/		
		SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Failed to initialise SDL_ttf");
		return -1;
	}

	/*Initialise SDL_mixer*/
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		/*Failed initialisation*/		
		SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "Failed to initialise SDL_Mixer");
		return -1;
	}
	
	/*Initialize PNG loading*/
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
		/*Failed initialisation*/		
		SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "Failed to initialise SDL_image");
		return -1;
	}
	
    SDL_Window *window;
    SDL_Renderer *renderer;

    if(SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer) < 0)
        exit(2);

	JAM_Texture sprite("img/JAM.png", renderer);

    /* Main render loop */
    Uint8 done = 0;
    SDL_Event event;
    while(!done)
	{
        /* Check for events */
        while(SDL_PollEvent(&event))
		{
            if(event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_FINGERDOWN)
			{
				SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR, "Exiting Main Loop");
                done = 1;
            }
        }
				
		/* Draw a gray background */
		SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
		SDL_RenderClear(renderer);
		
		sprite.pushToScreen(renderer, 0, 0, 32, 32);
	
		/* Update the screen! */
		SDL_RenderPresent(renderer);
		
		SDL_Delay(10);
    }

    exit(0);
}