#pragma once

#include "../sead/heap/seadDisposer.h"

namespace UISys{
	class ManipulateInterface {
		~ManipulateInterface();

		class SingletonDisposer_ : public sead::IDisposer {
			~SingletonDisposer_() override;
		};

		long long __vftable;
		SingletonDisposer_ sStaticDisposer;
		int unk1;
	};
	static_assert(sizeof(ManipulateInterface) == 0x30);
}