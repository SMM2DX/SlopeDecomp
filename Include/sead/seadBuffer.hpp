#pragma once

namespace sead {
	#ifndef		SEAD_BUFFER_HPP
	#define		SEAD_BUFFER_HPP
	template <typename T> struct Buffer {
		int mSize;
		T* mBuffer;
	};
	#endif	//	SEAD_BUFFER_HPP
}

