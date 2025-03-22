#include "hckpch.h"
#include <Hazel.h>

class Sandbox :public Hickory::Application {
public:
	Sandbox() {

	}
	~Sandbox() {
		 
	}
	
};

Hickory::Application* Hickory::CreateApplication() {
	return new Sandbox();	
}