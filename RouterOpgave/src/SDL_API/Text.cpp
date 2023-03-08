#include "Text.h"
static TTF_Font* font = nullptr;
void Text::Init()
{
	font = TTF_OpenFont("assets/Font/arial.ttf", 20);
}

void Text::DrawText(std::string text, Rect rect, Color color)
{
	SDL_Rect r = { rect.X, rect.Y, rect.W, rect.H };
	SDL_Color c = { color.R, color.G, color.B, color.A };
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), c);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer::GetRenderer(), surface);
	SDL_SetTextureScaleMode(texture, SDL_ScaleMode::SDL_ScaleModeBest);
	SDL_RenderCopy(Renderer::GetRenderer(), texture, NULL, &r);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
