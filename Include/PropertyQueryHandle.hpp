#pragma once

#include <BasicTypes.hpp>

struct PropertyQueryHandle {
	virtual ~PropertyQueryHandle();

	int64 index;
};