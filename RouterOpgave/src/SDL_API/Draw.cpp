#include "Draw.h"
#include "Sprite.h"
#include "SDL_ttf.h"

Draw::Draw()
{
	TTF_Init();
}

void Draw::DrawRouter(Router* router)
{
	Sprite sprite(router->GetAssetPath(), SDL_ScaleMode::SDL_ScaleModeBest);
	SDL_Rect rect = { router->GetRect().X, router->GetRect().Y, router->GetRect().W, router->GetRect().H };
	SDL_RenderCopy(Renderer::GetRenderer(), sprite.tex, NULL, &rect);
	Renderer::SetColor(255, 0, 0, 255);
	SDL_RenderDrawRect(Renderer::GetRenderer(), &rect);

	DrawPorts(router);
}

void Draw::DrawTextbox(Textbox* textbox)
{
	SDL_RenderDrawRect(Renderer::GetRenderer(), &textbox->GetRect());
	SDL_Surface* surface = TTF_RenderText_Blended(textbox->GetFont(), textbox->GetText().Text.c_str(), textbox->GetText().Color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer::GetRenderer(), surface);
	SDL_SetTextureScaleMode(texture, SDL_ScaleMode::SDL_ScaleModeBest);
	SDL_RenderCopy(Renderer::GetRenderer(), texture, NULL, &textbox->GetRect());
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Draw::DrawPorts(Router* router)
{
	for (int i = 0; i < router->GetPorts().size(); i++) {
		SDL_Rect rect = { router->GetPorts()[i]->GetRect().X, router->GetPorts()[i]->GetRect().Y, router->GetPorts()[i]->GetRect().W, router->GetPorts()[i]->GetRect().H };
		SDL_RenderDrawRect(Renderer::GetRenderer(), &rect);
	}
}
