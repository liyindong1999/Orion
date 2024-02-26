#pragma once

#include "Orion/Window.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

using namespace std;

namespace Orion
{
	class WindowsWindow : public Window
	{
	private:
		GLFWwindow* m_Window;
	
		struct WindowData
		{
			string Title;
			unsigned int Width, Height;
			bool VSync;
	
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//¥∞ø⁄ Ù–‘
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	};
}

