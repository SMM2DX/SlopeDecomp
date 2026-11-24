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

#define ARRAY_LENGTH(ARRAY)				\
	sizeof(ARRAY) / sizeof(ARRAY[0])

#endif	//	BASIC_TYPES_HPP