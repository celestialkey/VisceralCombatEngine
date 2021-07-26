#pragma once

#include "VCE/Core.h"
#include "VCE/Input.h"

namespace VCE {
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int keycode) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
	};
}