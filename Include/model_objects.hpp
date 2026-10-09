#pragma

#include "Custom_Enums.hxx"

struct object_base {
	virtual ~object_base();
	virtual void checkDerivedRuntimeTypeInfo();
	virtual void getRuntimeTypeInfo();
};

struct multi_tile_object_info {
	char padding[100];
	int width;
	int height;
};

struct tile_object : object_base {
	~tile_object() override;
	void checkDerivedRuntimeTypeInfo() override;
	void getRuntimeTypeInfo() override;
	virtual void sub_5();
	virtual void sub_6_3D_something();
	virtual void sub_7();
	virtual void get_tilemap_indices(int tile_offset_x, int tile_offset_y);
	virtual void sub_9();
	virtual void get_collision_flags(int tile_offset_x, int tile_offset_y);
	virtual void get_tile_name();
	virtual void sub_12();
	virtual void sub_13();
	virtual void sub_14();
	virtual void sub_15();
	virtual void sub_16();
	virtual void sub_17();
	virtual void sub_18(int tile_offset_x, int tile_offset_y);
	char gap_0[24];
	multi_tile_object_info *pMulti_tile_object_info;
	TilemapIndex temp_1;
	int temp_2;
	char gap_1[24];
	int temp_3;
	char temp_4A;
	char temp_4B;
	char temp_4C;
	char temp_4D;
};

struct tile_object_x58 : tile_object {
	~tile_object_x58() override;
	void checkDerivedRuntimeTypeInfo() override;
	void getRuntimeTypeInfo() override;
	int temp_5;
	int temp_6;
};

struct tile_object_x78 : tile_object_x58 {
	~tile_object_x78() override;
	void checkDerivedRuntimeTypeInfo() override;
	void getRuntimeTypeInfo() override;
	long long temp_7;
	long long temp_8;
	long long temp_9;
	long long temp_10;
};

struct EditActor_model_object : object_base {
	~EditActor_model_object() override;
	void checkDerivedRuntimeTypeInfo() override;
	void getRuntimeTypeInfo() override;
	virtual void sub_5();
	virtual void sub_6();
	virtual void sub_7();
	virtual void sub_8();
	virtual void sub_9();
	virtual void sub_10();
	virtual void sub_11();
	virtual void sub_12();
	virtual void sub_13();
	virtual void sub_14();
	virtual void sub_15();
	virtual void sub_16();
	virtual void sub_17();
	virtual void sub_18();
	virtual void sub_19();
	virtual void sub_20();
	virtual void sub_21();
	virtual void sub_22();
	virtual void sub_23();
	virtual void sub_24();
	virtual void sub_25();
	virtual void sub_26();
	virtual void sub_27();
	virtual void sub_28();
	virtual void sub_29();
	virtual void sub_30();
	virtual void sub_31();
	virtual void sub_32();
	virtual void sub_33();
	virtual void sub_34();
	virtual void sub_35();
	virtual void sub_36();
	virtual void sub_37();
	virtual void sub_38();
	virtual void sub_39();
	virtual void sub_40();
	virtual void sub_41();
	virtual void sub_42();
	virtual void sub_43();
	virtual void sub_44();
	virtual void sub_45();
	virtual void sub_46();
	virtual void sub_47();
	virtual void sub_48();
	virtual void sub_49();
	virtual void sub_50();
	virtual void sub_51();
	virtual void sub_52();
	virtual void sub_53();
	virtual void sub_54();
	virtual void sub_55();
	virtual void sub_56();
	virtual void sub_57();
	virtual void sub_58();
	virtual void sub_59();
	virtual void sub_60();
	char gap0[24];
	void *parent_object;
	char gap1[84];
	int size_index;
	char gap2[116];
	Skin mSkin;
	char gap3[136];
};

struct EditActor_3d_model_object : EditActor_model_object  {
	~EditActor_3d_model_object() override;
	void checkDerivedRuntimeTypeInfo() override;
	void getRuntimeTypeInfo() override;
	char gap4[8];
};
