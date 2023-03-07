#include "Textbox.h"
#include "../core/Collision.h"
#include "../core/Input.h"

Textbox::Textbox(SDL_Rect rect, uint32_t textSize)
	: rect(rect), textSize(textSize)
{
	onclickThread = std::thread(&Textbox::OnClick, this);
	font = TTF_OpenFont("Assets/Font/arialbd.ttf", textSize);
}

Textbox::~Textbox()
{
	onclickThread.join();
}

void Textbox::Write()
{
	if (inFocus) {

	}
}

void Textbox::OnClick()
{
	while (true)
	{
		if (Input::MousePressed(MouseButton::LEFT)) {
			if (Collision::InRect(rect, Input::MouseX(), Input::MouseY())) {
				inFocus = true;
			}
			else {
				inFocus = false;
			}
		}
	}
}
