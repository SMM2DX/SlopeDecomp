#pragma once

#ifndef		ITEMPROPERTYID_HPP
#define		ITEMPROPERTYID_HPP
struct ItemPropertyID {
	virtual char* getClassName();
	virtual char* getItemPropertyIDText();
	int index;
};
#endif	//	ITEMPROPERTYID_HPP


