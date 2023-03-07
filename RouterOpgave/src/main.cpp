#include "SDL_API/platform/Windows/WindowsWindow.h"
#include "SDL_API/Draw.h"
#include "RouterManager.h"

int main()
{
	Window* window = WindowsWindow::Create({ "Cisco" });
	RouterManager* m = new RouterManager();
	Draw draw;
	while (true)
	{
		draw.DrawRouter(m->GetRouter());
		window->OnUpdate();
		window->Clear();
	}

	window->Clean();

	return 0;
}