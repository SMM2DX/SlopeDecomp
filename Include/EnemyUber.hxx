#pragma once

#include "Actor.hxx"
#include "Lp/Utl/StateMachine.hpp"

class EnemyUber : public Actor {
	SEAD_RTTI_OVERRIDE(EnemyUber, Actor)
	char* getClassName() override;
	~EnemyUber() override;

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
	virtual void sub_can_enter_clear_pipe();
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
	virtual void sub_182();
	virtual void sub_183();

	using StateMachine = Lp::Utl::StateMachine<EnemyUber>;
	struct InnerClass1 {
		char gap_0[3800];
		char *enable_drawdokan;
	};
	enum EnemySysState : int {
		cEnemySysState_Basic = 0,
		cEnemySysState_Wing = 1,
		cEnemySysState_Parachute = 2,
		cEnemySysState_Tower = 3,
		cEnemySysState_Die = 4,
		cEnemySysState_Dokan = 5,
		cEnemySysState_Shell = 6,
		cEnemySysState_Carried = 7,
		cEnemySysState_Killer = 8,
		cEnemySysState_Block = 9,
		cEnemySysState_Jugem = 10,
		cEnemySysState_Cloud = 11,
		cEnemySysState_CapBound = 12,
		cEnemySysState_Clown = 13,
		cEnemySysState_Rail = 14,
		cEnemySysState_DrawDokan = 15,
		cEnemySysState_Crane = 16,
		cEnemySysState_Night = 17,
		cEnemySysState_ThrownUSA = 18,
		cEnemySysState_COUNT = 19,
	};

	char gap_0[80];
	unsigned int mParentFlag;
	char gap_1[916];
	InnerClass1 *enemyUber_InnerClass;
	StateMachine stateMachine;
	char gap_2[3000];
	EnemySysState bullshit;
};
