#pragma once
#ifdef HCK_PLATFORM_WINDOWS

extern Hickory::Application* Hickory::CreateApplication();

int main() {

	auto app = Hickory::CreateApplication();
	app->run();
	delete app;
}

#endif
