#pragma once

#include <IDAClangDestructorFix.hpp>

namespace sead {
	#ifndef		SEAD_SAFESTRING_HPP
	#define		SEAD_SAFESTRING_HPP
	template <typename T> struct SafeStringBase {
		virtual ~SafeStringBase() = default;
		#ifndef		IDACLANG_DESTRUCTOR_FIX
		virtual void destructor_2();
		#endif	//	IDACLANG_DESTRUCTOR_FIX
		virtual SafeStringBase &operator=(const SafeStringBase &) = default;
		virtual void assureTerminationImpl_() const {};
		
		const T* mStringTop;
	};
	using SafeString = SafeStringBase<char>;
	#endif	//	SEAD_SAFESTRING_HPP

	#ifndef		SEAD_BUFFEREDSAFESTRING_HPP
	#define		SEAD_BUFFEREDSAFESTRING_HPP
	template <typename T> struct BufferedSafeStringBase : public SafeStringBase<T> {
		~BufferedSafeStringBase() override;
		BufferedSafeStringBase &operator=(const BufferedSafeStringBase &) override;
		
		int mBufferSize;
	};
	using BufferedSafeString = BufferedSafeStringBase<char>;
	#endif	//	SEAD_BUFFEREDSAFESTRING_HPP

	#ifndef		SEAD_FIXEDSAFESTRING_HPP
	#define		SEAD_FIXEDSAFESTRING_HPP
	template <typename T> struct FixedSafeStringBase_32 : public BufferedSafeStringBase<T> {
		~FixedSafeStringBase_32() override;
		FixedSafeStringBase_32 &operator=(const FixedSafeStringBase_32 &) override;
		
		char mBuffer[32];
	};
	using FixedSafeString_32 = FixedSafeStringBase_32<char>;
	#endif	//	SEAD_FIXEDSAFESTRING_HPP

	#ifndef		SEAD_HEAPSAFESTRING_HPP
	#define		SEAD_HEAPSAFESTRING_HPP
	template <typename T> struct HeapSafeStringBase : public BufferedSafeStringBase<T> {
		~HeapSafeStringBase() override;
		HeapSafeStringBase &operator=(const HeapSafeStringBase &) override;
	};
	using HeapSafeString = HeapSafeStringBase<char>;
	#endif	//	SEAD_HEAPSAFESTRING_HPP
}

