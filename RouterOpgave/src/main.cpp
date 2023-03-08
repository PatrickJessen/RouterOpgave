#include "SDL_API/platform/Windows/WindowsWindow.h"
#include "SDL_API/Draw.h"
#include "RouterManager.h"

int main()
{
	Window* window = WindowsWindow::Create({ "Cisco" });
	Text::Init();
	RouterManager* m = new RouterManager();
	Textbox* textbox = new Textbox("assets/Font/arialbd.ttf", { 50, 300, 900, 75 }, 100);
	Combobox<std::string*>* combobox = new Combobox<std::string*>("Com ports", { 1000, 10, 50, 30 }, { 255, 0, 0, 255 });
	std::string* f;
	combobox->AddItem("COM1", f);
	combobox->AddItem("COM2", f);
	combobox->AddItem("COM3", f);
	combobox->AddItem("COM4", f);
	combobox->AddItem("COM5", f);
	combobox->AddItem("COM6", f);
	combobox->AddItem("COM7", f);
	combobox->AddItem("COM8", f);
	combobox->AddItem("COM9", f);
	combobox->AddItem("COM10", f);
	combobox->AddItem("COM11", f);
	combobox->AddItem("COM12", f);
	combobox->AddItem("COM13", f);
	Draw draw;
	while (true)
	{
		if (combobox->OnItemChanged()) {
			m->OpenCommunication(combobox->GetSelectedItem()->name);
		}
		textbox->Write();
		draw.DrawRouter(m->GetRouter());
		draw.DrawTextbox(textbox);
		draw.DrawCombobox(combobox);
		window->OnUpdate();
		window->Clear();
	}

	window->Clean();

	return 0;
}