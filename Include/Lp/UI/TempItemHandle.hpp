#pragma once

namespace Lp::UI {
	template <typename T> struct ID {
		virtual char* getName() const;
		virtual char* getIDText();

		T index;
	};

	enum ItemPropertyID_ : int {
		IPID_cTargetName,
		IPID_cTargetFullName,
		IPID_cLayoutName,
		IPID_cBodyLayoutName,
		IPID_cChildLayoutName,
		IPID_cInfluencedAlpha,
		IPID_cLocationAdjust,
		IPID_cVisible,
		IPID_cTranslate,
		IPID_cRotate,
		IPID_cScale,
		IPID_cSize,
		IPID_cBasePositionX,
		IPID_cBasePositionY,
		IPID_cParentRelativePositionX,
		IPID_cParentRelativePositionY,
		IPID_cMtx,
		IPID_cGlobalMtx,
		IPID_cRect,
		IPID_cVertexColor,
		IPID_cAlpha,
		IPID_cGlobalAlpha,
		IPID_cExtUserDataNum,
		IPID_cExtUserData,
		IPID_cExtUserDataByName,
		IPID_cMaterialCount,
		IPID_cMaterialColor,
		IPID_cMaterialShadowColorBlack,
		IPID_cMaterialShadowColorWhite,
		IPID_cMaterialConstantColor,
		IPID_cTexMapCount,
		IPID_cTextureInfo,
		IPID_cResTextureInfo,
		IPID_cTexSrtCount,
		IPID_cTexSrt,
		IPID_cTexCoordGenCount,
		IPID_cProjectionTexGenCount,
		IPID_cProjectionTexGenParameters,
		IPID_cGlobalVisible,
		IPID_cLayoutItemUniqueName,
		IPID_cCalcWorldMtx,
		IPID_cCalcWorldTranslate,
		IPID_cCalcWorldScale,
		IPID_cCalcGlobalSize,
		IPID_cCalcGlobalAlpha,
		IPID_cIsBelongToCapture,
		IPID_cIsBelongToDynamicCapture,
		IPID_cIsBelongToAlign,
		IPID_cTextID,
		IPID_cTextColor,
		IPID_cFontSize,
		IPID_cLineSpace,
		IPID_cCharSpace,
		IPID_cTextPositionX,
		IPID_cTextPositionY,
		IPID_cTextAlignment,
		IPID_cWidthLimitEnabled,
		IPID_cItalicRatio,
		IPID_cShadowOffset,
		IPID_cShadowScale,
		IPID_cShadowColor,
		IPID_cShadowItalicRatio,
		IPID_cTextDrawRect,
		IPID_cFontScaleX,
		IPID_cFontScaleY,
		IPID_cStringBufferLength,
		IPID_cPerCharacterTransform,
		IPID_cCenterCeilingEnabled,
		IPID_cBeforeAdjustFontWidth,
		IPID_cString,
		IPID_cMessagePageIdx,
		IPID_cMessagePageNum,
		IPID_cMessageDispLetterNum,
		IPID_cMessageLetterNum,
		IPID_cLetterStepEnabled,
		IPID_cVisibleLetter,
		IPID_cTexCoordCount,
		IPID_cTexCoord,
		IPID_cCaptureRequestDone,
		IPID_cCaptureOnce,
		IPID_cCaptureEveryFrame,
		IPID_cCaptureTextureInfo,
		IPID_cCaptureTextureData,
		IPID_cIsCaptureDoneOnDraw,
		IPID_cTotalLength,
	};
	struct ItemPropertyID : public ID<ItemPropertyID_> {};

	enum ItemMethodID_ : int {
		IMID_cAdjustPaneSizeToTextSize,
		IMID_cAdjustPaneSizeToTextSizeAll,
		IMID_cRequestCaptureWithParent,
		IMID_cRequestAlignWithParent,
		IMID_cAglTextureDataConv,
		IMID_cKerning,
		IMID_cLineFeed,
		IMID_cSetStringWithSize,
		IMID_cSetStringNoPreprocess,
		IMID_cSetStringNoPreprocessWithSize,
		IMID_cSetMessageString,
		IMID_cSetMessageStringWithParam,
		IMID_cFindTextBoxWidthOverPosition,
		IMID_cCalcWordWrapping,
		IMID_cRegisterGlyph,
		IMID_cRegisterGlyphWithText,
		IMID_cUpdateDispString,
		IMID_cCalcFrameSize,
		IMID_cHitTest,
		IMID_cRequestCapture,
		IMID_cRequestAlign,
		IMID_cRequestScroll,
	};
	struct ItemMethodID : public ID<ItemMethodID_> {};

	enum AnimPropertyID_ : int {
		APID_cTargetName,
		APID_cTargetFullName,
		APID_cEnable,
		APID_cPlaying,
		APID_cLoopData,
		APID_cWaitData,
		APID_cSkipAtFirstFrame,
		APID_cFrame,
		APID_cFrameSize,
		APID_cFrameMax,
		APID_cFrameRate,
		APID_cIsMinFrame,
		APID_cIsMaxFrame,
		APID_cIsFrameMidway,
		APID_cIsTurnedMaxTrigger,
		APID_cIsTurnedMinTrigger,
		APID_cIsEndTrigger,
		APID_cIsEndNextTrigger,
		APID_cPlayType,
		APID_cSpeed,
		APID_cStop,
		APID_cStopRate,
		APID_cBeatCount,
	};
	struct AnimPropertyID : public ID<AnimPropertyID_> {};

	enum AnimMethodID_ : int {
		AMID_cTargetName,
		AMID_cTargetFullName,
		AMID_cEnable,
		AMID_cPlaying,
		AMID_cLoopData,
		AMID_cWaitData,
		AMID_cSkipAtFirstFrame,
		AMID_cFrame,
		AMID_cFrameSize,
		AMID_cFrameMax,
		AMID_cFrameRate,
		AMID_cIsMinFrame,
		AMID_cIsMaxFrame,
		AMID_cIsFrameMidway,
		AMID_cIsTurnedMaxTrigger,
		AMID_cIsTurnedMinTrigger,
		AMID_cIsEndTrigger,
		AMID_cIsEndNextTrigger,
		AMID_cPlayType,
		AMID_cSpeed,
		AMID_cStop,
		AMID_cStopRate,
		AMID_cBeatCount,
	};
	struct AnimMethodID : public ID<AnimMethodID_> {};

	struct TempItemHandleSubClass {
		virtual void sub_1();

		char _0[0x1000];
	};

	#ifndef		LP_UI_TEMPITEMHANDLE_HPP
	#define		LP_UI_TEMPITEMHANDLE_HPP
	struct TempItemHandle {
		virtual ~TempItemHandle();
		virtual void sub_3();
		virtual void getSetter(ID<int>);
		virtual void getGetter(ID<int>);

		void* gottenObj; // ?
		char _0[0x8];
		TempItemHandleSubClass* temp2;
		char _1[0x1000];
	};
	#endif	//	LP_UI_TEMPITEMHANDLE_HPP
}