#include "lib.hpp"

#include <sead/seadSafeString.hpp>
#include <sead/seadPtrArray.hpp>

#include <Lp/UI/BtnPartsCtrl.hpp>
#include <Lp/UI/TextSetter.hpp>

//#include <UISys/ButtonActionCallbackArg.hpp>
#include <UISys/SequenceBase.hpp>

#include <Slope/CustomEnums.hpp>
//#include <Slope/UIEditMainPage.hpp>

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

static constexpr u16 s_NewButtonIndexMax					= 0x72;
static constexpr u16 s_NewSceneCount						= 0x14;

void patchGetButton() {
	exl::patch::CodePatcher codePatcher(0x18CC450);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::W1, s_NewButtonIndexMax - 1));
}

void patchGetButtonIndex() {
	exl::patch::CodePatcher codePatcher(0x18CC514);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X0, s_NewButtonIndexMax));
}

void patchGetButtonIconLoop() {
	exl::patch::CodePatcher codePatcher(0x18C90D4);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X28, s_NewSceneCount));
	codePatcher.Seek(0x18C8F80);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::W23, s_NewSceneCount));
}

void patchGetButtonLabelLoop() {
	exl::patch::CodePatcher codePatcher(0x18C9168);
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X20, s_NewSceneCount));
}

#pragma region BtnPartsCtrlBuffer

static constexpr u16 s_BtnPartsCtrlBufferSize				= 0x68;
static constexpr u16 s_NewBtnPartsCtrlBufferSize			= s_NewButtonIndexMax;
static std::array<ButtonNameStruct, s_NewBtnPartsCtrlBufferSize> s_NewBtnPartsCtrlBuffer;

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
	auto BtnPartsCtrlBuffer = exl::util::pointer_path::Follow<std::array<ButtonNameStruct, s_BtnPartsCtrlBufferSize>, 0x2CD99A8>();
	for (auto i = 0; i < s_BtnPartsCtrlBufferSize; ++i) {
		s_NewBtnPartsCtrlBuffer[i] = BtnPartsCtrlBuffer[i];
		//Logging.Log("[patchBtnPartsCtrlBuffer] %d: %s", i, s_NewBtnPartsCtrlBuffer[i].mStringTop);
	}
	for (auto i = s_BtnPartsCtrlBufferSize; i < s_NewBtnPartsCtrlBufferSize; ++i) {
		s_NewBtnPartsCtrlBuffer[i] = BtnPartsCtrlBuffer[L_LeftParts_00__L_SceneListBtn_00];
		if (i == 0x68) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_10";
		if (i == 0x69) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_11";
		if (i == 0x6A) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_12";
		if (i == 0x6B) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_13";
		if (i == 0x6C) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_14";
		if (i == 0x6D) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_15";
		if (i == 0x6E) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_16";
		if (i == 0x6F) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_17";
		if (i == 0x70) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_18";
		if (i == 0x71) s_NewBtnPartsCtrlBuffer[i].mStringTop = "/L_LeftParts_00/L_SceneListBtn_19";
		Logging.Log("[patchBtnPartsCtrlBuffer] %d: %s", i, s_NewBtnPartsCtrlBuffer[i].mStringTop);
	}

	WriteAdrlInst(exl::armv8::reg::X23, 0x18CF7B4, reinterpret_cast<uintptr_t>(s_NewBtnPartsCtrlBuffer.data()));
	WriteAdrlInst(exl::armv8::reg::X23, 0x18CFA14, reinterpret_cast<uintptr_t>(s_NewBtnPartsCtrlBuffer.data()));
	WriteAdrlInst(exl::armv8::reg::X23, 0x18D0158, reinterpret_cast<uintptr_t>(s_NewBtnPartsCtrlBuffer.data()));
}

#pragma endregion
#pragma region IconPtrArray

static constexpr u16 s_NewIconPtrArraySize					= s_NewSceneCount;

void patchIconPtrArraySize() {
	exl::patch::CodePatcher codePatcher(0x18CBFBC);
	codePatcher.WriteInst(exl::armv8::inst::Movz(exl::armv8::reg::W1, s_NewIconPtrArraySize));
}

#pragma endregion
#pragma region TextSetterPtrArray

static constexpr u16 s_NewTextSetterPtrArraySize			= s_NewSceneCount;

void patchTextSetterPtrArraySize() {
	exl::patch::CodePatcher codePatcher(0x18CBFD0);
	codePatcher.WriteInst(exl::armv8::inst::Movz(exl::armv8::reg::W1, s_NewTextSetterPtrArraySize));
}

#pragma endregion
#pragma region ButtonIndexToSceneSetArray

static constexpr u16 s_ButtonIndexToSceneSetArraySize		= 0x0A;
static constexpr u16 s_NewButtonIndexToSceneSetArraySize	= 0x14;
static std::array<SceneSet, s_NewButtonIndexToSceneSetArraySize> s_NewButtonIndexToSceneSetArray;

void patchButtonIndexToSceneSetArray() {
	auto ButtonIndexToSceneSetArray = exl::util::pointer_path::Follow<std::array<SceneSet, s_ButtonIndexToSceneSetArraySize>, 0x2CEA780>();
	for (auto i = 0; i < s_ButtonIndexToSceneSetArraySize; ++i) {
		s_NewButtonIndexToSceneSetArray[i] = ButtonIndexToSceneSetArray[i];
		//Logging.Log("[patchButtonIndexToSceneSetArray] %02d: %02d", i, s_NewButtonIndexToSceneSetArray[i]);
	}
	for (auto i = s_ButtonIndexToSceneSetArraySize; i < s_NewButtonIndexToSceneSetArraySize; ++i) {
		//s_NewButtonIndexToSceneSetArray[i] = (SceneSet)i;
		s_NewButtonIndexToSceneSetArray[i] = (SceneSet)0;
		Logging.Log("[patchButtonIndexToSceneSetArray] %02d: %02d", i, s_NewButtonIndexToSceneSetArray[i]);
	}

	WriteAdrlInst(exl::armv8::reg::X27, 0x18C8F20, reinterpret_cast<uintptr_t>(s_NewButtonIndexToSceneSetArray.data()));
}

#pragma endregion
#pragma region SceneSetToSceneNameArray

static constexpr u16 s_SceneSetToSceneNameArraySize		= 0x0A;
static constexpr u16 s_NewSceneSetToSceneNameArraySize	= 0x14;
static std::array<sead::SafeString, s_NewSceneSetToSceneNameArraySize> s_NewSceneSetToSceneNameArray;

void patchSceneSetToSceneNameArray() {
	auto SceneSetToSceneNameArray = exl::util::pointer_path::Follow<std::array<sead::SafeString, s_SceneSetToSceneNameArraySize>, 0x2CDAF28>();
	for (auto i = 0; i < s_SceneSetToSceneNameArraySize; ++i) {
		s_NewSceneSetToSceneNameArray[i] = SceneSetToSceneNameArray[i];
		//Logging.Log("[patchSceneSetToSceneNameArray] %02d: %s", i, s_NewSceneSetToSceneNameArray[i].mStringTop);
	}
	for (auto i = s_SceneSetToSceneNameArraySize; i < s_NewSceneSetToSceneNameArraySize; ++i) {
		s_NewSceneSetToSceneNameArray[i] = SceneSetToSceneNameArray[0];
		if (i == 0x0A) s_NewSceneSetToSceneNameArray[i].mStringTop = "SceneName_Sewer";
		Logging.Log("[patchSceneSetToSceneNameArray] %02d: %s", i, s_NewSceneSetToSceneNameArray[i].mStringTop);
	}

	WriteAdrlInst(exl::armv8::reg::X22, 0x18C90F4, reinterpret_cast<uintptr_t>(s_NewSceneSetToSceneNameArray.data()));
}

#pragma endregion

HOOK_DEFINE_TRAMPOLINE(Init) {
	static void Callback() {
		Orig();
		patchBtnPartsCtrlBuffer();
		patchButtonIndexToSceneSetArray();
		//patchSceneSetEnum();
		patchSceneSetToSceneNameArray();
	}
};

HOOK_DEFINE_TRAMPOLINE(printFromStartTime) {
	static void Callback(sead::SafeString *a1) {
		Orig(a1);
		Logging.Log("[printFromStartTime] %s", a1->mStringTop);
	}
};

HOOK_DEFINE_TRAMPOLINE(UIEditLeftMenuSeq_sub_67) {
	static void Callback(UISys::SequenceBase *thisPtr, ButtonActionCallbackArg *buttonActionCallbackArg) {
		Logging.Log("[UIEditLeftMenuSeq_sub_67] %u", buttonActionCallbackArg->buttonIndex);
		
		Orig(thisPtr, buttonActionCallbackArg);
	}
};

HOOK_DEFINE_TRAMPOLINE(UIEditLeftMenuSeq_sub_68) {
	static void Callback(UISys::SequenceBase *thisPtr, ButtonActionCallbackArg *buttonActionCallbackArg) {
		using sub_71018C7C10_t = void (void *);
		sub_71018C7C10_t *sub_71018C7C10 = reinterpret_cast<sub_71018C7C10_t *>(exl::util::modules::GetTargetOffset(0x18C7C10));

		Logging.Log("[UIEditLeftMenuSeq_sub_68] %u", buttonActionCallbackArg->buttonIndex);
		
		if (buttonActionCallbackArg->buttonIndex == L_LeftParts_00__L_ChangeHourBtn_00) {
			temp_9_t *temp_9 = thisPtr->temp_09;

			if (temp_9) { // temp_9.checkDerivedRuntimeTypeInfo(Slope::EditUIClasssDerived::getRuntimeTypeInfoStatic(void)::typeInfo)
				temp_9->nextSceneHour = (SceneHour)(temp_9->prevSceneHour ^ 1);
				temp_9->nextSceneSet = temp_9->prevSceneSet;
				temp_9->changeBitFlag = temp_9->changeBitFlag | LeftPartsState_ChangeSceneHour;
			}

			sub_71018C7C10(thisPtr);
		} else {
			Orig(thisPtr, buttonActionCallbackArg);
		}
	}
};

HOOK_DEFINE_TRAMPOLINE(UIEditLeftMenuSeq_sub_74) {
	static void Callback(UISys::SequenceBase *thisPtr, ButtonActionCallbackArg *buttonActionCallbackArg) {
		using sub_71018C7C10_t = void (void *);
		sub_71018C7C10_t *sub_71018C7C10 = reinterpret_cast<sub_71018C7C10_t *>(exl::util::modules::GetTargetOffset(0x18C7C10));

		Logging.Log("[UIEditLeftMenuSeq_sub_74] %u", buttonActionCallbackArg->buttonIndex);
		
		if (buttonActionCallbackArg->buttonIndex >= s_BtnPartsCtrlBufferSize) {
			temp_9_t *temp_9 = thisPtr->temp_09;

			if (temp_9) { // temp_9.checkDerivedRuntimeTypeInfo(Slope::EditUIClasssDerived::getRuntimeTypeInfoStatic(void)::typeInfo)
				SceneSet new_theme_index = s_NewButtonIndexToSceneSetArray[buttonActionCallbackArg->buttonIndex - s_BtnPartsCtrlBufferSize + 0xA];
				
				if (temp_9->prevSceneSet != new_theme_index) {
					temp_9->nextSceneHour = temp_9->prevSceneHour;
					temp_9->nextSceneSet = new_theme_index;
					temp_9->changeBitFlag = temp_9->changeBitFlag | LeftPartsState_ChangeSceneSet;
				} else {
					// CLOSE MENU
					struct_v19 *v19 = temp_9->qword_238;
					if (v19) {
						struct_v20 *v20 = v19->pstruct_v20;
						if (v20) {
							v20->byte54 = 0;
						}
					}
				}
			}

			sub_71018C7C10(thisPtr);
		} else {
			Orig(thisPtr, buttonActionCallbackArg);
		}
	}
};

HOOK_DEFINE_INLINE(DisgustingTextSetterHook) {
	static void Callback(exl::hook::InlineCtx* ctx) {
		std::string str = (char *)ctx->X[10];
		if (str.contains("L_SceneListBtn_")) {
			//Logging.Log("[DisgustingTextSetterHook]	YEP!	%s", ctx->X[10]);
			ctx->X[22] = true;
		} else {
			//Logging.Log("[DisgustingTextSetterHook]	NOPE!	%s", ctx->X[10]);
			ctx->X[22] = false;
		}
	}
};
void DisgustingTextSetterPatch() {
	//	CMP		x19,	#0x1
	exl::patch::CodePatcher codePatcher(0x18D3CA4);
	// \x7f\x06\x00\xf1
	codePatcher.WriteInst(exl::armv8::inst::CmpImmediate(exl::armv8::reg::X22, true));
	//	B.LO	#0x18D38D8
	codePatcher.Seek(0x18D3CA8);
	// \x83\xe1\xff\x54
	codePatcher.Write(0x54FFE183); // exlaunch usess bytes in reverse order?
	//	B		#0x18D3D64
	codePatcher.Seek(0x18D3CAC);
	// \x2e\x00\x00\x14
	codePatcher.BranchInst(0x18D3D64);
}

HOOK_DEFINE_INLINE(DebugHook) {
	static void Callback(exl::hook::InlineCtx* ctx) {
		sead::PtrArrayImpl* iconPtrArray = reinterpret_cast<sead::PtrArrayImpl*>(ctx->X[0]+0x998);
		sead::PtrArrayImpl* textSetterPtrArray = reinterpret_cast<sead::PtrArrayImpl*>(ctx->X[0]+0x9A8);
		Logging.Log("[DebugHook]\
			\nicons?:		mPtrNum: %d, mPtrNumMax: %d, mPtrs: %d\
			\ntextSetter:	mPtrNum: %d, mPtrNumMax: %d, mPtrs: %d", 
			iconPtrArray->mPtrNum,			iconPtrArray->mPtrNumMax,		iconPtrArray->mPtrs, 
			textSetterPtrArray->mPtrNum,	textSetterPtrArray->mPtrNumMax,	textSetterPtrArray->mPtrs);
	}
};
HOOK_DEFINE_INLINE(DebugHook1) {
	static void Callback(exl::hook::InlineCtx* ctx) {
		Logging.Log("[DebugHook 1]		%s", ctx->X[10]);
	}
};
HOOK_DEFINE_INLINE(DebugHook2) {
	static void Callback(exl::hook::InlineCtx* ctx) {
		Logging.Log("[DebugHook 2]		%s", ctx->X[10]);
	}
};

extern "C" void exl_main(void *x0, void *x1) {
	exl::patch::CodePatcher codePatcher(0);
	exl::hook::Initialize();

	patchGetButton();
	patchGetButtonIndex();

	patchGetButtonIconLoop();
	patchGetButtonLabelLoop();

	patchBtnPartsCtrlBufferSize();
	patchPopulateBtnPartsCtrlBuffer();

	patchIconPtrArraySize();
	patchTextSetterPtrArraySize();

	Init::InstallAtOffset(0x30);
	printFromStartTime::InstallAtOffset(0x620B90);
	UIEditLeftMenuSeq_sub_67::InstallAtOffset(0x18C9280);
	UIEditLeftMenuSeq_sub_68::InstallAtOffset(0x18C9E30);
	UIEditLeftMenuSeq_sub_74::InstallAtOffset(0x18CA930);

	DisgustingTextSetterHook::InstallAtOffset(0x18D3CA0);
	DisgustingTextSetterPatch();

	DebugHook::InstallAtOffset(0x18C911C);
	//DebugHook1::InstallAtOffset(0x18D3D64);
	//DebugHook2::InstallAtOffset(0x18D3E74);

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
