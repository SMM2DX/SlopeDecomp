#include "lib.hpp"

void WriteInst(uintptr_t address, exl::armv8::InstBitSet inst) {
	static exl::patch::CodePatcher sCodePatcher(0);
	sCodePatcher.Seek(address);
	sCodePatcher.WriteInst(inst);
}

static constexpr u16 s_BtnPartsCtrlBufferSize = 0x68;
static constexpr u16 s_BtnPartsCtrlBufferNewSize = 0x6A;


namespace Lp {
	namespace UI {
		struct BtnPartsCtrl;
	} // namespace UI
} // namespace Lp

struct Difference {
	uintptr_t m_Page;
	uintptr_t m_Offset;
};

Difference GetDifference(uintptr_t source, uintptr_t destination) {
	constexpr uintptr_t pageMask	= ~(PAGE_SIZE - 1);
	constexpr uintptr_t offsetMask	=  (PAGE_SIZE - 1);
	uintptr_t page		= (destination & pageMask) - (source & pageMask);
	uintptr_t offset	= (destination & offsetMask);
	return {page, offset};
}

struct ButtonNameStruct {
	void *__vftable;
	const char *mStringTop;
	int int_10;
	int gap_14;
	long long qword_18;
	int int_20;
	signed int int_24;
};

static std::array<ButtonNameStruct, s_BtnPartsCtrlBufferNewSize> s_NewArray;

struct struct_UIEditMainPage {
	u8 _0[0x770];
	u32 m_BtnPartsCtrlBuffer;
};

struct struct_BtnPartsCtrl {
	u8 _0[0x10];
	u32 m_ButtonIndex;
};

struct SafeString {
	void *__vftable;
	const char *mStringTop;
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

struct struct_v20
{
  u8 _0[84];
  int8_t byte54;
};

struct struct_v19
{
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

void patchBtnPartsCtrlBufferSize() {
	exl::patch::CodePatcher codePatcher(0x18CBAD8);
	codePatcher.WriteInst(exl::armv8::inst::Movz(exl::armv8::reg::W0, sizeof(Lp::UI::BtnPartsCtrl *) * s_BtnPartsCtrlBufferNewSize));
	codePatcher.Seek(0x18CBB68);
	codePatcher.WriteInst(exl::armv8::inst::Movz(exl::armv8::reg::X8, s_BtnPartsCtrlBufferNewSize % 4));
	codePatcher.WriteInst(exl::armv8::inst::Movz(exl::armv8::reg::W10, s_BtnPartsCtrlBufferNewSize));
}

void patchGetButton() {
	exl::patch::CodePatcher codePatcher(0x18CC450);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::W1, s_BtnPartsCtrlBufferNewSize - 1));
}

void patchGetButtonIndex() {
	exl::patch::CodePatcher codePatcher(0x18CC514);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X0, s_BtnPartsCtrlBufferNewSize));
}

void patchPopulateBtnPartsCtrlBuffer() {
	exl::patch::CodePatcher codePatcher(0x18D02C0);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X24, s_BtnPartsCtrlBufferNewSize));
	codePatcher.Seek(0x18D0548);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X23, s_BtnPartsCtrlBufferNewSize));
}

void patchArray() {
	auto s_Array = exl::util::pointer_path::Follow<std::array<ButtonNameStruct, s_BtnPartsCtrlBufferSize>, 0x2CD99A8>();
	for (auto i = 0; i < s_BtnPartsCtrlBufferSize; ++i) {
		s_NewArray[i] = s_Array[i];
	}
	for (auto i = s_BtnPartsCtrlBufferSize; i < s_BtnPartsCtrlBufferNewSize; ++i) {
		s_NewArray[i] = s_Array[0x4E];
		if (i == 0x68)
			s_NewArray[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_10";
		if (i == 0x69)
			s_NewArray[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_11";
		Logging.Log("patchArray: %d %s", i, s_NewArray[i].mStringTop);
	}

	exl::patch::CodePatcher codePatcher(0x18CF7B4);
	Difference difference = GetDifference(exl::util::modules::GetTargetOffset(0x18CF7B4), reinterpret_cast<uintptr_t>(s_NewArray.data()));
	codePatcher.WriteInst(exl::armv8::inst::Adrp(exl::armv8::reg::X23, difference.m_Page));
	codePatcher.WriteInst(exl::armv8::inst::AddImmediate(exl::armv8::reg::X23, exl::armv8::reg::X23, difference.m_Offset));

	codePatcher.Seek(0x18CFA14);
	difference = GetDifference(exl::util::modules::GetTargetOffset(0x18CFA14), reinterpret_cast<uintptr_t>(s_NewArray.data()));
	codePatcher.WriteInst(exl::armv8::inst::Adrp(exl::armv8::reg::X23, difference.m_Page));
	codePatcher.WriteInst(exl::armv8::inst::AddImmediate(exl::armv8::reg::X23, exl::armv8::reg::X23, difference.m_Offset));

	codePatcher.Seek(0x18D0158);
	difference = GetDifference(exl::util::modules::GetTargetOffset(0x18D0158), reinterpret_cast<uintptr_t>(s_NewArray.data()));
	codePatcher.WriteInst(exl::armv8::inst::Adrp(exl::armv8::reg::X23, difference.m_Page));
	codePatcher.WriteInst(exl::armv8::inst::AddImmediate(exl::armv8::reg::X23, exl::armv8::reg::X23, difference.m_Offset));
}

HOOK_DEFINE_TRAMPOLINE(Init) {
	static void Callback() {
		Orig();
		patchArray();
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
			Logging.Log("Button index is not a Skin button");
			uint32_t new_theme_index = 0;
			if (button_index >= s_BtnPartsCtrlBufferSize) {
				Logging.Log("Button index is within Custom range");
				uint32_t custom_button_index = button_index - s_BtnPartsCtrlBufferSize;
				new_theme_index = custom_button_index + 10;
			}
			else {
				uint32_t theme_button_index = button_index - 0x4E;
				if (theme_button_index >= 10){
					Logging.Log("Button index is not a theme button");
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
	exl::hook::Initialize();
	patchBtnPartsCtrlBufferSize();
	patchGetButton();
	patchGetButtonIndex();
	patchPopulateBtnPartsCtrlBuffer();
	Init::InstallAtOffset(0x30);


	ThemeIndexSub::InstallAtOffset(0x18CA930);


	exl::patch::CodePatcher codePatcher(0x00DA0B00); // Remap Theme Indexes
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
