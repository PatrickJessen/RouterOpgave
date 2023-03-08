#include "Textbox.h"
#include "../core/Collision.h"
#include "../core/Input.h"

Textbox::Textbox(const std::string& fontType, SDL_Rect rect, uint32_t textSize)
	: rect(rect), textSize(textSize)
{
	//onclickThread = std::thread(&Textbox::OnClick, this);
	font = TTF_OpenFont(fontType.c_str(), textSize);
}

Textbox::~Textbox()
{
	onclickThread.join();
}

void Textbox::Write()
{
	if (inFocus) {
		
		if (Input::AnyKeyPressed())
			std::cout << Input::GetKeyPressed() << std::endl;
	}
	//SDL_StopTextInput();
}

void Textbox::OnClick()
{
	while (true)
	{
		if (Input::MousePressed(MouseButton::LEFT)) {
			if (Collision::InRect(rect, Input::MouseX(), Input::MouseY())) {
				std::cout << "InFocus\n";
				inFocus = true;
			}
			else {
				std::cout << "Not InFocus\n";
				inFocus = false;
			}
		}
		Write();
	}
}
