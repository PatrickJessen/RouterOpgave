#pragma once
#define SDL_MAIN_HANDLED
#include "../../../core/Window.h"
#include "SDL.h"
#include "SDL_ttf.h"

class WindowsWindow : public Window
{
public:
	WindowsWindow(const WindowProps& props);
	~WindowsWindow();

public:
	virtual void OnUpdate() override;
	virtual void Clear() override;
	virtual void Clean() override;
	virtual unsigned int GetWidth() const { return data.Width; }
	virtual unsigned int GetHeight() const { return data.Height; }

	SDL_Window* GetWindow() { return window; }

private:
	void Init(const WindowProps& props);

private:
	SDL_Window* window;
	SDL_GLContext context;

	struct WindowData
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		bool Fullscreen;
	};

	WindowData data;
};