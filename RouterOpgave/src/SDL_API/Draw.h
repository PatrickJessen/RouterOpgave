#pragma once
#include "Renderer.h"
#include "../Router/Router.h"
#include "Textbox.h"

class Draw
{
public:
	Draw();
public:
	void DrawRouter(Router* router);
	void DrawTextbox(Textbox* textbox);

private:
	void DrawPorts(Router* router);
};
