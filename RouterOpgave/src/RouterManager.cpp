#include "RouterManager.h"
#include "core/Input.h"
#include "core/Collision.h"

RouterManager::RouterManager()
{
	router = new Router("assets/router.png", { 50, 50, 900, 200 }, 16);
	t = std::thread(&RouterManager::OnPortClick, this);
}

RouterManager::~RouterManager()
{
	t.join();
	delete router;
	delete activePort;
}

void RouterManager::CommunicateThroughPort(const std::string& command, std::string& response)
{
	if (activePort != nullptr) {
		activePort->Communicate(command, response);
	}
}

void RouterManager::OnPortClick()
{
	while (true)
	{
		for (int i = 0; i < router->GetPorts().size(); i++) {
			if (Collision::InRect(router->GetPorts()[i]->GetRect(), Input::MouseX(), Input::MouseY()) && Input::MousePressed(MouseButton::LEFT)) {
				activePort = router->GetPorts()[i];
				std::cout << router->GetPorts()[i]->GetComPort() << std::endl;
			}
		}
	}
}
