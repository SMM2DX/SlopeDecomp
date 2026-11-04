#include "lib.hpp"

namespace Lp {
	namespace UI {
		struct BtnPartsCtrl;
	} // namespace UI
} // namespace Lp

namespace sead {
	struct SafeString {
		void *__vftable;
		const char *mStringTop;
	};
} // namespace sead

struct ButtonNameStruct {
	void *__vftable;
	const char *mStringTop;
	int int_10;
	int gap_14;
	long long qword_18;
	int int_20;
	signed int int_24;
};

struct struct_UIEditMainPage {
	u8 _0[0x770];
	u32 m_BtnPartsCtrlBuffer;
};

struct ButtonActionCallbackArg {
	void *viewPage;
	void *btnPartsCtrl;
	unsigned int buttonIndex;
	unsigned int dword14;
	unsigned int dword18;
	unsigned int dword1C;
	unsigned int dword20;
	unsigned int dword24;
	unsigned long long qword28;
};

struct struct_v20 {
  u8 _0[84];
  int8_t byte54;
};

struct struct_v19 {
  u8 _0[528];
  struct_v20 *pstruct_v20;
};

struct temp_9_t {
	u8 _0[0x238];
	struct_v19 *qword_238;
	u8 _1[0xB0];
	uintptr_t qword_2F0;
	u8 _2[0x13CC];
	int32_t dword16C4;
	int32_t dword16C8;
	int32_t dword16CC;
	int32_t dword16D0;
	int32_t dword16D4;
	int32_t dword16D8;
};

struct SequenceBase {
	u8 _0[0x48];
	temp_9_t *temp_9;
};

static constexpr u16 s_BtnPartsCtrlBufferSize		= 0x68;
static constexpr u16 s_NewBtnPartsCtrlBufferSize	= 0x6A;
static std::array<ButtonNameStruct, s_NewBtnPartsCtrlBufferSize> s_NewBtnPartsCtrlBuffer;

class Difference final {
	public:
		constexpr Difference(uintptr_t source, uintptr_t destination) noexcept
			: m_Source{source}, m_Destination{destination} {}
		[[nodiscard]] constexpr uintptr_t GetPage() const noexcept {
			return static_cast<intptr_t>(m_Destination & s_PageMask) - static_cast<intptr_t>(m_Source & s_PageMask);
		}
		[[nodiscard]] constexpr uintptr_t GetOffset() const noexcept {
			return m_Destination & s_OffsetMask;
		}
	private:
		static constexpr uintptr_t s_PageMask = ~(static_cast<uintptr_t>(PAGE_SIZE) - 1);
		static constexpr uintptr_t s_OffsetMask = static_cast<uintptr_t>(PAGE_SIZE) - 1;
		uintptr_t m_Source;
		uintptr_t m_Destination;
};

class CodePatcher final : public exl::patch::CodePatcher {
	public:
		inline void WriteAdrlInst(exl::armv8::reg::Register reg, uintptr_t destination) {
			Difference difference = Difference(RoFromAddr(m_Current), destination);
			WriteInst(exl::armv8::inst::Adrp(reg, difference.GetPage()));
			WriteInst(exl::armv8::inst::AddImmediate(reg, reg, difference.GetOffset()));
		}
};

void WriteAdrlInst(exl::armv8::reg::Register reg, uintptr_t source, uintptr_t destination) {
	CodePatcher s_CodePatcher = CodePatcher(source);
	s_CodePatcher.WriteAdrlInst(reg, destination);
}

void patchGetButton() {
	exl::patch::CodePatcher codePatcher(0x18CC450);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::W1, s_NewBtnPartsCtrlBufferSize - 1));
}

void patchGetButtonIndex() {
	exl::patch::CodePatcher codePatcher(0x18CC514);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X0, s_NewBtnPartsCtrlBufferSize));
}

#pragma region BtnPartsCtrlBuffer

void patchBtnPartsCtrlBufferSize() {
	exl::patch::CodePatcher codePatcher(0x18CBAD8);
	codePatcher.WriteInst(exl::armv8::inst::Movz(exl::armv8::reg::W0, sizeof(Lp::UI::BtnPartsCtrl *) * s_NewBtnPartsCtrlBufferSize));
	codePatcher.Seek(0x18CBB68);
	codePatcher.WriteInst(exl::armv8::inst::Movz(exl::armv8::reg::X8, s_NewBtnPartsCtrlBufferSize % 4));
	codePatcher.WriteInst(exl::armv8::inst::Movz(exl::armv8::reg::W10, s_NewBtnPartsCtrlBufferSize));
}

void patchPopulateBtnPartsCtrlBuffer() {
	exl::patch::CodePatcher codePatcher(0x18D02C0);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X24, s_NewBtnPartsCtrlBufferSize));
	codePatcher.Seek(0x18D0548);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X23, s_NewBtnPartsCtrlBufferSize));
}

void patchBtnPartsCtrlBuffer() {
	auto s_BtnPartsCtrlBuffer = exl::util::pointer_path::Follow<std::array<ButtonNameStruct, s_BtnPartsCtrlBufferSize>, 0x2CD99A8>();
	for (auto i = 0; i < s_BtnPartsCtrlBufferSize; ++i) {
		s_NewBtnPartsCtrlBuffer[i] = s_BtnPartsCtrlBuffer[i];
	}
	for (auto i = s_BtnPartsCtrlBufferSize; i < s_NewBtnPartsCtrlBufferSize; ++i) {
		s_NewBtnPartsCtrlBuffer[i] = s_BtnPartsCtrlBuffer[0x4E];
		if (i == 0x68) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_10";
		if (i == 0x69) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_11";
		Logging.Log("patchBtnPartsCtrlBuffer: %d %s", i, s_NewBtnPartsCtrlBuffer[i].mStringTop);
	}

	WriteAdrlInst(exl::armv8::reg::X23, 0x18CF7B4, reinterpret_cast<uintptr_t>(s_NewBtnPartsCtrlBuffer.data()));
	WriteAdrlInst(exl::armv8::reg::X23, 0x18CFA14, reinterpret_cast<uintptr_t>(s_NewBtnPartsCtrlBuffer.data()));
	WriteAdrlInst(exl::armv8::reg::X23, 0x18D0158, reinterpret_cast<uintptr_t>(s_NewBtnPartsCtrlBuffer.data()));
}

#pragma endregion

HOOK_DEFINE_TRAMPOLINE(Init) {
	static void Callback() {
		Orig();
		patchBtnPartsCtrlBuffer();
	}
};

HOOK_DEFINE_REPLACE(ThemeIndexSub) {
	static void Callback(SequenceBase *thisPtr, ButtonActionCallbackArg *buttonActionCallbackArg) {
		using sub_71018C7C10_t = void (void *);
		sub_71018C7C10_t *sub_71018C7C10 = reinterpret_cast<sub_71018C7C10_t *>(exl::util::modules::GetTargetOffset(0x18C7C10));
		
		Logging.Log("ThemeIndexSub: %u", buttonActionCallbackArg->buttonIndex);

		uint32_t button_index = buttonActionCallbackArg->buttonIndex;
		temp_9_t *temp_9 = thisPtr->temp_9;

		if ( button_index - 0x59 > 4) {
			uint32_t new_theme_index = 0;
			if (button_index >= s_BtnPartsCtrlBufferSize) {
				uint32_t custom_button_index = button_index - s_BtnPartsCtrlBufferSize;
				new_theme_index = custom_button_index + 10;
			}
			else {
				uint32_t theme_button_index = button_index - 0x4E;
				if (theme_button_index >= 10){
					return;
				}
				new_theme_index = theme_button_index; // TEMP
				//new_theme_index = button_index_theme_to_theme_index[theme_button_index]; // UNFINISHED
			}

			uint32_t previous_theme_index = 0;
			if (temp_9) // temp_9.checkDerivedRuntimeTypeInfo(Slope::EditUIClasssDerived::getRuntimeTypeInfoStatic(void)::typeInfo)
				previous_theme_index = temp_9->dword16CC;
			
			Logging.Log("Theme was: %d", previous_theme_index);
			Logging.Log("Changing theme to: %d", new_theme_index);

			if (previous_theme_index != new_theme_index) {
				if (temp_9) { // temp_9.checkDerivedRuntimeTypeInfo(Slope::EditUIClasssDerived::getRuntimeTypeInfoStatic(void)::typeInfo)
					temp_9->dword16D8 = temp_9->dword16D0;
					uintptr_t v17 = temp_9->qword_2F0 | 0x40000LL;
					temp_9->dword16D4 = new_theme_index;
					// JUMP TO LABEL 37
					temp_9->qword_2F0 = v17;
				}
			} else {
				if (temp_9) { // temp_9.checkDerivedRuntimeTypeInfo(Slope::EditUIClasssDerived::getRuntimeTypeInfoStatic(void)::typeInfo)
					struct_v19 *v19 = temp_9->qword_238;
					if (v19) {
						struct_v20 *v20 = v19->pstruct_v20;
						if (v20) {
							v20->byte54 = 0;
						}
					}
				}
			}
		} else {
			uint32_t new_style_index = button_index - 0x59;
			uint32_t previous_style_index = 0;
			if (temp_9) // temp_9.checkDerivedRuntimeTypeInfo(Slope::EditUIClasssDerived::getRuntimeTypeInfoStatic(void)::typeInfo)
				previous_style_index = temp_9->dword16C4;
			
			if (previous_style_index != new_style_index) {
				if (temp_9) { // temp_9.checkDerivedRuntimeTypeInfo(Slope::EditUIClasssDerived::getRuntimeTypeInfoStatic(void)::typeInfo)
					uintptr_t v16 = temp_9->qword_2F0;
					temp_9->dword16C8 = new_style_index;
					uintptr_t v17 = v16 | 0x10000;
					temp_9->qword_2F0 = v17;
				}
			}
		}

		Logging.Log("Calling sub_71018C7C10");
		sub_71018C7C10(thisPtr);
	}
};


extern "C" void exl_main(void *x0, void *x1) {
	exl::patch::CodePatcher codePatcher(0);
	exl::hook::Initialize();

	patchGetButton();
	patchGetButtonIndex();
	patchBtnPartsCtrlBufferSize();
	patchPopulateBtnPartsCtrlBuffer();

	Init::InstallAtOffset(0x30);
	ThemeIndexSub::InstallAtOffset(0x18CA930);

	codePatcher.Seek(0x00DA0B00); // Remap Theme Indexes
	codePatcher.Write(0x5280004A);
	codePatcher.Seek(0x00DA0B04);
	codePatcher.Write(0x1B0A2502);
	codePatcher.Seek(0x00DA1D58);
	codePatcher.Write(0x5280004A);
	codePatcher.Seek(0x00DA1D5C);
	codePatcher.Write(0x1B0A2502);

	codePatcher.Seek(0x017A60E0); // Prevent indexing play song type arrays
	codePatcher.Write(0xF9400129);
	codePatcher.Seek(0x017A603C); // Prevent indexing edit song type arrays
	codePatcher.Write(0xF9400149);
}

extern "C" NORETURN void exl_exception_entry() {
	EXL_ABORT("Default exception handler called!");
}
