#pragma once

#include "ActorBase.hxx"
#include "Lp/Utl/StateMachine.hpp"
#include "model_objects.hxx"

struct ThingWithAttrInfo
{
	char gap0[48];
	unsigned long long mAttrNum;
	char gap1[9];
	bool mIsValidChangeAttr;
};

struct ThingWithParentFlag
{
	char gap0[8];
	float temp__1;
	float temp__2;
	char gap_0[4];
	int temp_1;
	int temp_2;
	unsigned int mParentFlag;
	char gap1[232];
	ThingWithAttrInfo *thingWithAttrInfo;
	char gap2[4000];
};

class EditActor : public ActorBase {
	SEAD_RTTI_OVERRIDE(EditActor, ActorBase)
	char* getClassName() override;
	~EditActor() override;

	virtual void sub_37();
	virtual void sub_38();
	virtual void sub_39();
	virtual void sub_40();
	virtual void sub_41();
	virtual void changeDir();
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
	virtual void set_dir_bits();
	virtual void sub_56();
	virtual void sub_57();
	virtual void sub_58();
	virtual void sub_59();
	virtual void sub_60();
	virtual void get_wallhang_bits();
	virtual void sub_62();
	virtual void sub_63();
	virtual void sub_64();
	virtual void sub_65();
	virtual void sub_66();
	virtual void sub_67();
	virtual void sub_68();
	virtual void sub_69();
	virtual void sub_70();
	virtual void sub_71();
	virtual void sub_72();
	virtual void sub_73();
	virtual void sub_74();
	virtual void sub_75();
	virtual void sub_76();
	virtual void sub_77();
	virtual void sub_78();
	virtual void sub_79();
	virtual void sub_80();
	virtual void sub_81();
	virtual void sub_82();
	virtual void sub_83();
	virtual void sub_84();
	virtual void sub_85();
	virtual void sub_86();
	virtual void sub_87();
	virtual void sub_88();
	virtual void sub_89();
	virtual void sub_90();
	virtual void sub_91();
	virtual void sub_92();
	virtual void sub_93();
	virtual void sub_94();
	virtual void sub_95();
	virtual void sub_96();
	virtual void sub_97();
	virtual void sub_98();
	virtual void sub_99();
	virtual void sub_100();
	virtual void sub_101();
	virtual void sub_102();
	virtual void sub_103();
	virtual void sub_104();
	virtual void sub_105();
	virtual void sub_106();
	virtual void sub_107();
	virtual void sub_108();
	virtual void sub_109();
	virtual void sub_110();
	virtual void sub_111();
	virtual void sub_112();
	virtual void sub_113();
	virtual void sub_114();
	virtual void sub_115();
	virtual void sub_116();
	virtual void sub_117();
	virtual void sub_118();
	virtual void sub_119();
	virtual void sub_120();
	virtual void sub_121();
	virtual void sub_122();
	virtual void sub_123();
	virtual void sub_124();
	virtual void sub_125();
	virtual void sub_126();
	virtual void sub_127();
	virtual void sub_128();
	virtual void sub_129();
	virtual void sub_130();
	virtual void sub_131();
	virtual void sub_132();
	virtual void sub_133();
	virtual void sub_134();
	virtual void sub_135();
	virtual void sub_136();
	virtual void sub_137();
	virtual void sub_138();
	virtual void sub_139();
	virtual void sub_140();
	virtual void sub_141();
	virtual void sub_142();
	virtual void sub_143();
	virtual void sub_144();
	virtual void sub_145();
	virtual void sub_146();
	virtual void sub_147();
	virtual void sub_148();
	virtual void sub_149();
	virtual void sub_150();
	virtual void sub_151();
	virtual void sub_152();
	virtual void sub_153();
	virtual void sub_154();
	virtual void sub_155();
	virtual void sub_156();
	virtual void sub_157();
	virtual void sub_158();
	virtual void sub_159();
	virtual void sub_160();
	virtual void sub_161();
	virtual void sub_162();
	virtual void sub_163();
	virtual void sub_164();
	virtual void sub_165();
	virtual void sub_166();
	virtual void sub_167();
	virtual void sub_168();
	virtual void sub_169();
	virtual void sub_170();
	virtual void sub_171();
	virtual void sub_172();
	virtual void sub_173();
	virtual void sub_174();
	virtual void sub_175();
	virtual void sub_176();
	virtual void sub_177();
	virtual void sub_178();
	virtual void sub_179();
	virtual void sub_180();
	virtual void sub_181();
	virtual void get_attr_2();
	virtual void sub_183();
	virtual void sub_184();
	virtual void sub_185();
	virtual void sub_186();
	virtual void sub_187();
	virtual void getAttr();
	virtual void getAttrNum();
	virtual void sub_190();
	virtual void sub_191();
	virtual void changeAttr(char *);
	virtual void sub_193();
	virtual void sub_EditWait();
	virtual void sub_EditDokanIn();
	virtual void sub_EditDokanIn_EditDrag();
	virtual void sub_197();
	virtual void sub_198();

	using StateMachine = Lp::Utl::StateMachine<EditActor>;
	struct InnerClass1 {
		EditActor *editActor;
	};
	enum EditState : int {
		EditState_cWait = 0,
		EditState_cDragCheck = 2,
		EditState_cDrag = 3,
		EditState_cDrawPut = 6,
		EditState_cScaling = 5,
		EditState_cRotate = 7,
		EditState_cHandling = 17,
		EditState_COUNT = 18,
	};
	enum DemoState : int {
		cDemoState_None = 0,
		cDemoState_DokanIn = 1,
		cDemoState_DokanOut = 2,
		cDemoState_DragNormal = 3,
		cDemoState_DropShake = 4,
		cDemoState_COUNT = 5,
	};

	char gap1[32];
	InnerClass1 *editActor_InnerClass;
	char gap1A[56];
	long long temp_1;
	int temp_2;
	int temp_3;
	char gap2[16];
	int temp_4;
	char gap3[212];
	long long temp_5;
	char gap4[24];
	long long temp_6;
	long long temp_7;
	long long temp_8;
	char gap5[40];
	long long temp_9;
	char gap6[24];
	long long temp_10;
	char gap7[8];
	long long temp_11;
	char gap8[8];
	long long temp_12;
	char gap9[8];
	char gap10[48];
	EditActor_model_object *active_model_object;
	EditActor_model_object *model_objects[4];
	char gap11[92];
	int temp_A;
	int temp_B;
	int temp_C;
	float temp_D;
	int temp_E;
	int temp_F;
	int temp_G;
	char gap12[64];
	ThingWithParentFlag *thingWithParentFlag;
	char gap13[4];
	int temp_13;
	char gap14[40];
	StateMachine stateMachine1;
	char gap14a[8];
	StateMachine stateMachine2;
	char gap14b[216];
	bool flag_257_1;
	bool flag_257_2;
	char gap15[4006];
	EditState bullshit;
	DemoState bullshit_two;
};
