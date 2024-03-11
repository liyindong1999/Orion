#pragma once

#include "Orion/Core.h"
#include "Orion/Events/Event.h"

using namespace std;

namespace Orion
{
	struct WindowProps 
	{
		string Title;
		unsigned int Width, Height;

		WindowProps(const string& title = "Orion Engine", unsigned int width = 1280, unsigned int height = 720)
		: Title(title), Width(width), Height(height) {}
	};

	//窗口接口
	class ORION_API Window
	{
	public:
		using EventCallbackFn = function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//窗口属性
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}