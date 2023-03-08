#include "Draw.h"
#include "Sprite.h"
#include "SDL_ttf.h"

Draw::Draw()
{
}

void Draw::DrawRouter(Router* router)
{
	Sprite sprite(router->GetAssetPath(), SDL_ScaleMode::SDL_ScaleModeBest);
	SDL_Rect rect = { router->GetRect().X, router->GetRect().Y, router->GetRect().W, router->GetRect().H };
	SDL_RenderCopy(Renderer::GetRenderer(), sprite.tex, NULL, &rect);
	Renderer::SetColor(255, 0, 0, 255);
	SDL_RenderDrawRect(Renderer::GetRenderer(), &rect);

	//DrawPorts(router);
	DrawPowerLight(router);
}

void Draw::DrawTextbox(Textbox* textbox)
{
	SDL_Rect rect = textbox->GetRect();
	SDL_RenderDrawRect(Renderer::GetRenderer(), &rect);
	DrawText(textbox);
}

void Draw::DrawText(Textbox* textbox)
{
	for (int i = 0; i < textbox->GetText().size(); i++) {

		SDL_Surface* surface = TTF_RenderText_Blended(textbox->GetFont(), &textbox->GetText()[i].Letter, textbox->GetText()[i].Color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer::GetRenderer(), surface);
		SDL_SetTextureScaleMode(texture, SDL_ScaleMode::SDL_ScaleModeBest);
		SDL_RenderCopy(Renderer::GetRenderer(), texture, NULL, &textbox->GetText()[i].Rect);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}
}

void Draw::DrawCombobox(Combobox<std::string*>* combobox)
{
	combobox->Draw();
}

void Draw::DrawPorts(Router* router)
{
	for (int i = 0; i < router->GetPorts().size(); i++) {
		SDL_Rect rect = { router->GetPorts()[i]->GetRect().X, router->GetPorts()[i]->GetRect().Y, router->GetPorts()[i]->GetRect().W, router->GetPorts()[i]->GetRect().H };
		SDL_RenderDrawRect(Renderer::GetRenderer(), &rect);
	}
}

void Draw::DrawPowerLight(Router* router)
{
	SDL_Color color = { 255, 0, 0, 255 };
	if (router->GetPower()) {
		color = { 0, 255, 0, 255 };
	}
	SDL_Rect rect = { 98, 116, 15, 15 };
	Renderer::SetColor(color);
	SDL_RenderFillRect(Renderer::GetRenderer(), &rect);
	Renderer::SetDefaultColor();
}
