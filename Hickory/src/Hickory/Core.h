#pragma once

#include <memory>

#ifdef HCK_PLATFORM_WINDOWS
#if HCK_DYNAMIC_LINK
	#ifdef HCK_BUILD_DLL
		#define HCK_API __declspec(dllexport)
	#else
		#define HCK_API __declspec(dllimport)
	#endif
#else
	#define HCK_API
#endif
#else
	#error HICKORY ONLY SUPPORT WINDOWS NOW!
#endif

#ifdef HZ_DEBUG
	#define HZ_ENABLE_ASSERTS
#endif

#ifdef HCK_ENABLE_ASSERTS
	#define HCK_ASSERT(x, ...) { if(!(x)) { HCK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HCK_CORE_ASSERT(x, ...) { if(!(x)) { HCK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HCK_ASSERT(x, ...)
	#define HCK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
#define HCK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Hickory {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}