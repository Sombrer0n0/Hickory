#pragma once
#include "Core.h"

namespace Hickory{
	class HCK_API Application
	{
	public:

		Application();
		virtual ~Application();

		void run();
	};

	Application* CreateApplication();
}
