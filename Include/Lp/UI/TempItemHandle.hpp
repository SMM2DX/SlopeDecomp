#pragma once

struct ItemPropertyID {
	virtual char* getClassName() const;
	virtual char* getItemPropertyIDText(int);

	enum IPID_Enum : int {
		cTargetName					= 0,
		cTargetFullName				= 1,
		cLayoutName					= 2,
		cBodyLayoutName				= 3,
		cChildLayoutName			= 4,
		cInfluencedAlpha			= 5,
		cLocationAdjust				= 6,
		cVisible					= 7,
		cTranslate					= 8,
		cRotate						= 9,
		cScale						= 10,
		cSize						= 11,
		cBasePositionX				= 12,
		cBasePositionY				= 13,
		cParentRelativePositionX	= 14,
		cParentRelativePositionY	= 15,
		cMtx						= 16,
		cGlobalMtx					= 17,
		cRect						= 18,
		cVertexColor				= 19,
		cAlpha						= 20,
		cGlobalAlpha				= 21,
		cExtUserDataNum				= 22,
		cExtUserData				= 23,
		cExtUserDataByName			= 24,
		cMaterialCount				= 25,
		cMaterialColor				= 26,
		cMaterialShadowColorBlack	= 27,
		cMaterialShadowColorWhite	= 28,
		cMaterialConstantColor		= 29,
		cTexMapCount				= 30,
		cTextureInfo				= 31,
		cResTextureInfo				= 32,
		cTexSrtCount				= 33,
		cTexSrt						= 34,
		cTexCoordGenCount			= 35,
		cProjectionTexGenCount		= 36,
		cProjectionTexGenParameters	= 37,
		cGlobalVisible				= 38,
		cLayoutItemUniqueName		= 39,
		cCalcWorldMtx				= 40,
		cCalcWorldTranslate			= 41,
		cCalcWorldScale				= 42,
		cCalcGlobalSize				= 43,
		cCalcGlobalAlpha			= 44,
		cIsBelongToCapture			= 45,
		cIsBelongToDynamicCapture	= 46,
		cIsBelongToAlign			= 47,
		cTextID						= 48,
		cTextColor					= 49,
		cFontSize					= 50,
		cLineSpace					= 51,
		cCharSpace					= 52,
		cTextPositionX				= 53,
		cTextPositionY				= 54,
		cTextAlignment				= 55,
		cWidthLimitEnabled			= 56,
		cItalicRatio				= 57,
		cShadowOffset				= 58,
		cShadowScale				= 59,
		cShadowColor				= 60,
		cShadowItalicRatio			= 61,
		cTextDrawRect				= 62,
		cFontScaleX					= 63,
		cFontScaleY					= 64,
		cStringBufferLength			= 65,
		cPerCharacterTransform		= 66,
		cCenterCeilingEnabled		= 67,
		cBeforeAdjustFontWidth		= 68,
		cString						= 69,
		cMessagePageIdx				= 70,
		cMessagePageNum				= 71,
		cMessageDispLetterNum		= 72,
		cMessageLetterNum			= 73,
		cLetterStepEnabled			= 74,
		cVisibleLetter				= 75,
		cTexCoordCount				= 76,
		cTexCoord					= 77,
		cCaptureRequestDone			= 78,
		cCaptureOnce				= 79,
		cCaptureEveryFrame			= 80,
		cCaptureTextureInfo			= 81,
		cCaptureTextureData			= 82,
		cIsCaptureDoneOnDraw		= 83,
		cTotalLength				= 84,
	};

	IPID_Enum index;
};

namespace Lp::UI {
	struct TempItemHandleSubClass {
		virtual void sub_1();

		char _0[0x1000];
	};

	#ifndef		LP_UI_TEMPITEMHANDLE_HPP
	#define		LP_UI_TEMPITEMHANDLE_HPP
	struct TempItemHandle {
		virtual ~TempItemHandle();
		virtual void sub_3();
		virtual void getSetter(ItemPropertyID);
		virtual void getGetter(ItemPropertyID);

		void* gottenObj; // ?
		char _0[0x8];
		TempItemHandleSubClass* temp2;
		char _1[0x1000];
	};
	#endif	//	LP_UI_TEMPITEMHANDLE_HPP
}