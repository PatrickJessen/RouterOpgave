#pragma once
#include "UI.h"
#include <vector>
#include "Text.h"
#include "../core/Collision.h"
#include "../core/Input.h"


template <typename V>
class Item
{
public:
	Item(V* item, std::string name, Rect vec)
		: item(item), name(name), vec(vec) {}
public:
	V* item = nullptr;
	std::string name{};
	Rect vec{};
};


template <typename T>
class Combobox : public UI
{
public:
	Combobox(std::string text, Rect vec, Color color)
	{
		this->text = text;
		this->vec = vec;
		this->color = color;
		renderText = new Text();
	}
public:
	virtual void Draw() override 
	{
		itemChanged = false;
		DrawBox();
		if (items.size() < 1)
			renderText->DrawText("fffff", vec, color);
		else if (selectedItem == nullptr)
			renderText->DrawText(items[0]->name, vec, color);
		else
			renderText->DrawText(selectedItem->name, vec, color);

		for (int i = 0; i < items.size(); i++)
		{
			if (isOpen)
			{
				renderText->DrawText(items[i]->name, items[i]->vec, color);
			}
		}
		//OpenClose();
	}
	const bool& OnItemChanged() { return itemChanged; }
	Item<T>* GetSelectedItem() { return selectedItem; }
	void AddItem(std::string name, T& item)
	{
		counter += 40;
		Rect vec4 = { vec.X, vec.Y + counter, vec.W, vec.H };
		Item<T>* newItem = new Item<T>(&item, name, vec4);
		items.push_back(newItem);
	}

	void DrawBox()
	{
		Renderer::SetColor(255, 255, 255, 255);
		SDL_Rect rect = { vec.X - 10, vec.Y, vec.W + 20, vec.H };
		SDL_RenderFillRect(Renderer::GetRenderer(), &rect);
		Renderer::SetColor(0, 0, 0, 255);
		SDL_RenderDrawRect(Renderer::GetRenderer(), &rect);
	}
	void OpenClose()
	{
		if (Collision::InRect(vec, Input::MouseX(), Input::MouseY()))
			isOpen = !isOpen;
	}
	void SelectItem()
	{
		if (isOpen) 
		{
			for (int i = 0; i < items.size(); i++)
			{
				if (Collision::InRect(items[i]->vec, Input::MouseX(), Input::MouseY()))
				{
					selectedItem = items[i];
					isOpen = false;
					itemChanged = true;
				}
			}
		}
	}
private:
	Item<T>* selectedItem = nullptr;
	std::vector<Item<T>*> items;
	std::string text;
	Text* renderText = nullptr;
	bool isOpen = false;
	int counter = 0;
	bool itemChanged = false;
};
