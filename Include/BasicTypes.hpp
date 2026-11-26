#pragma once

#ifndef		BASIC_TYPES_HPP
#define		BASIC_TYPES_HPP

using ptr_t		= void*;

using int64		= long int;
using uint64	= unsigned long int;
using int32		= int;
using uint32	= unsigned int;
using int16		= short int;
using uint16	= unsigned short int;
using int8		= char;
using uint8		= unsigned char;

#define ARRAY_LENGTH(ARRAY)																		\
	sizeof(ARRAY) / sizeof(ARRAY[0])

#define DEFINE_TARGET_FUNCTION(NAME, OFFSET, RETURN, ...)										\
    using NAME##_t = RETURN (__VA_ARGS__);														\
    NAME##_t *NAME = reinterpret_cast<NAME##_t*>(exl::util::modules::GetTargetOffset(OFFSET));	\

#endif	//	BASIC_TYPES_HPP
