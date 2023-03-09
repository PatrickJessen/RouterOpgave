#pragma once
#include "Text.h"
#include "Renderer.h"
#include "SDL_ttf.h"
#include <vector>

class Textbox
{
public:
	Textbox(const std::string& fontType, SDL_Rect rect, uint32_t textSize);
	~Textbox();

public:
	void Write();
	const std::vector<SingleLetterText>& GetText() { return text; }
	TTF_Font* GetFont() { return font; }
	SDL_Rect GetRect() { return rect; }
	std::string GetTextAsString();
	const bool& InFocus() { return inFocus; }
	void Clear();
	void OnClick();
	void OnBackSpace();
private:
	void OnPaste();
private:
	std::vector<SingleLetterText> text = {};
	SDL_Rect rect = {};
	uint32_t textSize = 0;
	TTF_Font* font;
	bool inFocus = false;
	int margin = 0;
};