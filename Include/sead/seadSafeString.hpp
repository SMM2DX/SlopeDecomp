#pragma once

#include <IDAClangDestructorFix.hpp>

namespace sead {
	#ifndef		SEAD_SAFESTRING_HPP
	#define		SEAD_SAFESTRING_HPP
	template <typename T> struct SafeStringBase {
		static const T cNullChar;
		virtual ~SafeStringBase() = default;
		#ifndef		IDACLANG_DESTRUCTOR_FIX
		virtual void destructor_2();
		#endif	//	IDACLANG_DESTRUCTOR_FIX
		virtual SafeStringBase<T>& operator=(const SafeStringBase<T>& other);
		virtual void assureTerminationImpl_() const {};
		
		const T* mStringTop;

		SafeStringBase() : mStringTop(&cNullChar) {
			*reinterpret_cast<uintptr_t *>(this) = exl::util::modules::GetTargetOffset(0x28522B0);
		}
		
		explicit SafeStringBase(const T* stringTop) : mStringTop(stringTop) {
			*reinterpret_cast<uintptr_t *>(this) = exl::util::modules::GetTargetOffset(0x28522B0);
		}
	};
	using SafeString = SafeStringBase<char>;
	#endif	//	SEAD_SAFESTRING_HPP

	#ifndef		SEAD_BUFFEREDSAFESTRING_HPP
	#define		SEAD_BUFFEREDSAFESTRING_HPP
	template <typename T> struct BufferedSafeStringBase : public SafeStringBase<T> {
		~BufferedSafeStringBase() override = default;
		BufferedSafeStringBase<T>& operator=(const SafeStringBase<T>& other) override;
		
		int mBufferSize;

		BufferedSafeStringBase() : SafeStringBase<T>(), mBufferSize(0) {
			*reinterpret_cast<uintptr_t *>(this) = exl::util::modules::GetTargetOffset(0x2852830);
		}

		explicit BufferedSafeStringBase(const T* stringTop, int bufferSize) : SafeStringBase<T>(stringTop), mBufferSize(bufferSize) {
			*reinterpret_cast<uintptr_t *>(this) = exl::util::modules::GetTargetOffset(0x2852830);
		}
	};
	using BufferedSafeString = BufferedSafeStringBase<char>;
	#endif	//	SEAD_BUFFEREDSAFESTRING_HPP

	#ifndef		SEAD_FIXEDSAFESTRING_HPP
	#define		SEAD_FIXEDSAFESTRING_HPP
	template <typename T> struct FixedSafeStringBase_32 : public BufferedSafeStringBase<T> {
		char mBuffer[32];
	};
	using FixedSafeString_32 = FixedSafeStringBase_32<char>;
	template <typename T> struct FixedSafeStringBase_64 : public BufferedSafeStringBase<T> {
		char mBuffer[64];
	};
	using FixedSafeString_64 = FixedSafeStringBase_64<char>;
	#endif	//	SEAD_FIXEDSAFESTRING_HPP

	#ifndef		SEAD_HEAPSAFESTRING_HPP
	#define		SEAD_HEAPSAFESTRING_HPP
	template <typename T> struct HeapSafeStringBase : public BufferedSafeStringBase<T> {
	};
	using HeapSafeString = HeapSafeStringBase<char>;
	#endif	//	SEAD_HEAPSAFESTRING_HPP
}

