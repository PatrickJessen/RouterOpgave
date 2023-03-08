#pragma once
#include "Renderer.h"
#include "../Router/Router.h"
#include "Textbox.h"
#include "Combobox.h"

class Draw
{
public:
	Draw();
public:
	void DrawRouter(Router* router);
	void DrawTextbox(Textbox* textbox);
	void DrawText(Textbox* textbox);
	void DrawCombobox(Combobox<std::string*>* combobox);

private:
	void DrawPorts(Router* router);
	void DrawPowerLight(Router* router);
};
