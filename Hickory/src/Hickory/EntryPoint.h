#pragma once
#ifdef HCK_PLATFORM_WINDOWS

extern Hickory::Application* Hickory::CreateApplication();

int main(int argc,char** argv) {

	Hickory::Log::Init();

	HCK_CORE_WARN("Initialized Log!");
	int a = 5;
	HCK_INFO("Hello! Var={0}", a);

	auto app = Hickory::CreateApplication();
	app->run();
	delete app;
}


#endif
