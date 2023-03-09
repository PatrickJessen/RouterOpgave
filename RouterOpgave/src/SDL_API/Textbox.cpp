#include "Textbox.h"
#include "../core/Collision.h"
#include "../core/Input.h"
#include <Windows.h>

Textbox::Textbox(const std::string& fontType, SDL_Rect rect, uint32_t textSize)
	: rect(rect), textSize(textSize)
{
	font = TTF_OpenFont(fontType.c_str(), textSize);
}

Textbox::~Textbox()
{
	
}

void Textbox::Write()
{
	if (inFocus) {
		
		char ch = Input::GetKeyPressed();
		SingleLetterText slt;
		slt.Letter = ch;
		slt.Rect = { rect.x + 5 + margin, rect.y + 50, 20, 20 };
		slt.Color = { 0, 0, 0, 255 };
		text.push_back(slt);
		margin += 18;
	}
}

std::string Textbox::GetTextAsString()
{
	std::string fulltext;
	for (int i = 0; i < text.size(); i++) {
		fulltext.push_back(text[i].Letter);
	}
	return fulltext;
}

void Textbox::Clear()
{
	margin = 0;
	text.clear();
}

void Textbox::OnClick()
{
	if (Collision::InRect(rect, Input::MouseX(), Input::MouseY())) {
		std::cout << "InFocus\n";
		inFocus = true;
	}
	else {
		std::cout << "Not InFocus\n";
		inFocus = false;
	}
}

void Textbox::OnBackSpace()
{
	if (text.size() > 0) {
		text.pop_back();
		margin -= 18;
	}
}

void Textbox::OnPaste()
{
	/*if (Input::KeyPressed(Key::LCTRL)) {
		char* f = SDL_GetClipboardText();
		if (f == "") {

		}
	}*/
}
