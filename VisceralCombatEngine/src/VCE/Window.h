#pragma once

#include "vcepch.h"
#include "VCE/Core.h"
#include "VCE/Events/Event.h"

namespace VCE {
	struct WindowProperties {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "Visceral Combat Engine",
						unsigned int width = 1280,
						unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	// Interface representing a desktop system based window
	class VCE_API Window
	{
	public:
		// Template a function ptr that returns void and accepts an Event arg
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& cb) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}