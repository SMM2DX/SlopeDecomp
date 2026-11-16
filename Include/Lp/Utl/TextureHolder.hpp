#pragma once

namespace nn::gfx{
	#ifndef		NN_GFX_RESTEXTURE_HPP
	#define		NN_GFX_RESTEXTURE_HPP
	struct ResTexture{
	};
	#endif	//	NN_GFX_RESTEXTURE_HPP
}

namespace agl{
	#ifndef		AGL_TEXTUREDATA_HPP
	#define		AGL_TEXTUREDATA_HPP
	struct TextureData{
	};
	#endif	//	AGL_TEXTUREDATA_HPP
}

namespace Lp::Utl{
	#ifndef		LP_UI_TEXTUREHOLDER_HPP
	#define		LP_UI_TEXTUREHOLDER_HPP
	struct TextureHolder{
		char _0[0x20];
		bool bool_20;
		long long int qword_28;
		char _1[0x2D8];
		agl::TextureData* textureData;
		char _2[0x180];
	};
	#endif	//	LP_UI_TEXTUREHOLDER_HPP
}