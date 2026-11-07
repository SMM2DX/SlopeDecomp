#pragma once

#include "../seadOG/math/seadMatrix.h"
#include "../seadOG/gfx/seadCamera.h"
#include <sead/seadDisposer.hpp>

namespace UISys{
	class LayoutCanvasMgr {
		~LayoutCanvasMgr();

		class SingletonDisposer_ : public sead::IDisposer {
			~SingletonDisposer_() override;
		};

		long long __vftable;
		SingletonDisposer_ sStaticDisposer;
		sead::Matrix44f matrix;
		char camera[0x38];
		//sead::Camera camera;
	};
	static_assert(sizeof(LayoutCanvasMgr) == 0xA0);
}