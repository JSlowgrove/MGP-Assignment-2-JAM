#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

/**
@brief Creates a Text Texture for use with a renderer
Creates a Text Texture from an image file, this can then be used with a renderer.
DISCLAMER ~ This is a modified version of my AI Assignment 1 Text class.
*/
class JAM_Text
{
private:
	/**Font*/
	TTF_Font* font;
	/**Font colour*/
	SDL_Color fontColour;
	/**The Texture data*/
	SDL_Texture* textureData;
	/**A pointer to the render*/
	SDL_Renderer* renderer;
	/**Font size*/
	int fontSize;
	/**The text*/
	std::string text;
	/**The font location*/
	std::string fontLocation;
	/**The texture width*/
	int textureWidth;
	/**The texture height*/
	int textureHeight;

	/**
	Creates a Text Texture using the text data.
	*/
	void createTextTexture();

public:

	/**
	Constructs a Text Texture.
	Creates a Text Texture using an image location and a renderer. Font size and colour will be default (size 10 and black).
	@param std::string The text to display.
	@param std::string The location of the font file.
	@param SDL_Renderer* The renderer.
	*/
	JAM_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer);

	/**
	Constructs a Text Texture.
	Creates a Text Texture using an image location and a renderer. Font colour will be default (black). Font size will be set to the input.
	@param std::string The text to display.
	@param std::string The location of the font file.
	@param int The size of the font.
	@param SDL_Renderer* The renderer.
	*/
	JAM_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer);

	/**
	Constructs a Text Texture.
	Creates a Text Texture using an image location and a renderer. Font size will be default (size 10). Colour will be set to the input.
	@param std::string The text to display.
	@param std::string The location of the font file.
	@param SDL_Renderer* The renderer.
	@param int The value of red. (0-255)
	@param int The value of green. (0-255)
	@param int The value of blue. (0-255)
	*/
	JAM_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer, int r, int g, int b);

	/**
	Constructs a Text Texture.
	Creates a Text Texture using an image location and a renderer.
	@param std::string The text to display.
	@param std::string The location of the font file.
	@param int The size of the font.
	@param SDL_Renderer* The renderer.
	@param int The value of red. (0-255)
	@param int The value of green. (0-255)
	@param int The value of blue. (0-255)
	*/
	JAM_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer, int r, int g, int b);

	/**
	Destructs the Text Texture.
	*/
	~JAM_Text();

	/**
	Pushes the image to the Renderer, to the XY Coordinates. This is scaled to the width and height	inputed.
	@param int x coordinate of the image.
	@param int y coordinate of the image.
	*/
	void pushToScreen(int x, int y);

	/**
	Sets the colour of the text.
	@param int The value of red. (0-255)
	@param int The value of green. (0-255)
	@param int The value of blue. (0-255)
	*/
	void setColour(int r, int g, int b);

	/**
	Sets the font size of the text.
	@param int The font size of the text.
	*/
	void setFontSize(int fontSize);

	/**
	Sets the font of the text.
	@param std::string The location of the font file.
	*/
	void setFont(std::string fontLocation);

	/**
	Sets the text.
	@param std::string The text to display.
	*/
	void setText(std::string text);
};