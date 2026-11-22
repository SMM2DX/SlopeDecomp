#pragma once

#include <BasicTypes.hpp>

#ifndef		CUSTOMENUMS_HPP
#define		CUSTOMENUMS_HPP

enum Skin : uint32 {
	Skin_M1											=	0x0,
	Skin_M3											=	0x1,
	Skin_MW											=	0x2,
	Skin_WU											=	0x3,
	Skin_3W											=	0x4,
	Skin_COUNT										=	0x5,
};

enum seadSkin : uint32 {
	sSkin_Invalid									=	0x0,
	sSkin_M1										=	0x1,
	sSkin_M3										=	0x2,
	sSkin_MW										=	0x3,
	sSkin_WU										=	0x4,
	sSkin_3W										=	0x5,
	sSkin_COUNT										=	0x6,
};

enum SceneHour : uint32 {
	SceneHour_Day									=	0x0,
	SceneHour_Night									=	0x1,
};

enum MyWorldSceneSkin : uint32 {
	MyWorldSceneSkin_Plain							=	0x0,
	MyWorldSceneSkin_Athletic						=	0x1,
	MyWorldSceneSkin_Underground					=	0x2,
	MyWorldSceneSkin_Woods							=	0x3,
	MyWorldSceneSkin_Desert							=	0x4,
	MyWorldSceneSkin_Magma							=	0x5,
	MyWorldSceneSkin_Snow							=	0x6,
	MyWorldSceneSkin_Night							=	0x7,
	MyWorldSceneSkin_COUNT							=	0x8,
};

enum SceneSet : uint32 {
	SceneSet_Plain									=	0x0,
	SceneSet_Underground							=	0x1,
	SceneSet_Castle									=	0x2,
	SceneSet_Airship								=	0x3,
	SceneSet_Water									=	0x4,
	SceneSet_HauntedHouse							=	0x5,
	SceneSet_Snow									=	0x6,
	SceneSet_Desert									=	0x7,
	SceneSet_Athletic								=	0x8,
	SceneSet_Woods									=	0x9,
	SceneSet_COUNT									=	0xA,
};

enum SceneButtonIndex : uint32 {
	ButtonIndexScene_Plain							=	0x0,
	ButtonIndexScene_Underground					=	0x1,
	ButtonIndexScene_Water							=	0x2,
	ButtonIndexScene_Desert							=	0x3,
	ButtonIndexScene_Snow							=	0x4,
	ButtonIndexScene_Athletic						=	0x5,
	ButtonIndexScene_Forest							=	0x6,
	ButtonIndexScene_GhostHouse						=	0x7,
	ButtonIndexScene_Airship						=	0x8,
	ButtonIndexScene_Castle							=	0x9,
};

enum ButtonIndex : uint32 {
	L_Btn_00										=	0x00,
	L_Btn_01										=	0x01,
	L_Btn_02										=	0x02,
	L_Btn_03										=	0x03,
	L_Btn_04										=	0x04,
	L_Btn_05										=	0x05,
	L_Btn_06										=	0x06,
	L_Btn_07										=	0x07,
	L_Btn_08										=	0x08,
	L_Btn_09										=	0x09,
	L_Btn_10										=	0x0A,
	L_BdBalloon_00									=	0x0B,
	L_BdBalloon_00_2								=	0x0C,
	L_RingMenu_00__L_BdRingIconSet_00				=	0x0D,
	L_RingMenu_00__L_BdRingIconSet_01				=	0x0E,
	L_RingMenu_00__L_BdRingIconSet_02				=	0x0F,
	L_RingMenu_00__L_Category_00__L_BdBase_00		=	0x10,
	L_RingMenu_00__L_Category_00__L_BdBase_01		=	0x11,
	L_RingMenu_00__L_Category_00__L_BdBase_02		=	0x12,
	L_RingMenu_00__L_Category_00__L_BdBase_03		=	0x13,
	L_RingMenu_00__L_Category_01__L_BdBase_00		=	0x14,
	L_RingMenu_00__L_Category_01__L_BdBase_01		=	0x15,
	L_RingMenu_00__L_Category_01__L_BdBase_02		=	0x16,
	L_RingMenu_00__L_Category_01__L_BdBase_03		=	0x17,
	L_RingMenu_00__L_Category_01__L_BdBase_04		=	0x18,
	L_RingMenu_00__L_CloseBtn_00					=	0x19,
	L_PaletteSet_00__L_SoundBtn_00					=	0x1A,
	L_PaletteSet_00__L_SearchBtn_00					=	0x1B,
	L_PaletteSet_00__L_PaletteBtn_00				=	0x1C,
	L_PaletteSet_00__L_PaletteBtn_01				=	0x1D,
	L_PaletteSet_00__L_PaletteBtn_02				=	0x1E,
	L_PaletteSet_00__L_PaletteBtn_03				=	0x1F,
	L_PaletteSet_00__L_PaletteBtn_04				=	0x20,
	L_PaletteSet_00__L_PaletteBtn_05				=	0x21,
	L_PaletteSet_00__L_PaletteBtn_06				=	0x22,
	L_PaletteSet_00__L_PaletteBtn_07				=	0x23,
	L_PaletteSet_00__L_PaletteBtn_08				=	0x24,
	L_PaletteSet_00__L_PaletteBtn_09				=	0x25,
	L_PaletteSet_00__L_PaletteBtn_10				=	0x26,
	L_PaletteSet_00__L_PaletteBtn_11				=	0x27,
	L_PaletteSet_00__L_BdPaletteSet_00				=	0x28,
	L_Play_00__L_PlayBtn_00							=	0x29,
	L_Slider_00__L_AreaBtn_01						=	0x2A,
	L_Slider_00__L_VerticalBtn_01					=	0x2B,
	L_Slider_00__L_SlideBarV_00						=	0x2C,
	L_Slider_00__L_BtnG_01							=	0x2D,
	L_Slider_00__L_BtnS_01							=	0x2E,
	L_Slider_00__L_AreaBtn_00						=	0x2F,
	L_Slider_00__L_VerticalBtn_00					=	0x30,
	L_Slider_00__L_SlideBarH_00						=	0x31,
	L_Slider_00__L_BtnG_00							=	0x32,
	L_Slider_00__L_BtnS_00							=	0x33,
	L_Slider_00__L_BdSlideBarV_00					=	0x34,
	L_Slider_00__L_BdSlideBarH_00					=	0x35,
	L_LeftParts_00__L_SkinBtn_00					=	0x36,
	L_LeftParts_00__L_SceneBtn_00					=	0x37,
	L_LeftParts_00__L_WaterLevelBtn_00				=	0x38,
	L_LeftParts_00__L_ScrollBtn_00					=	0x39,
	L_LeftParts_00__L_ScrollEditBtn_00				=	0x3A,
	L_LeftParts_00__L_TimerBtn_00					=	0x3B,
	L_LeftParts_00__L_MissionBtn_00					=	0x3C,
	L_LeftParts_00__L_MultiEditBtn_00				=	0x3D,
	L_LeftParts_00__L_ZanzoBtn_00					=	0x3E,
	L_LeftParts_00__L_NoAutoScrollBtn_00			=	0x3F,
	L_LeftParts_00__L_AutoScrollBtn_00				=	0x40,
	L_LeftParts_00__L_AutoScrollBtn_01				=	0x41,
	L_LeftParts_00__L_AutoScrollBtn_02				=	0x42,
	L_LeftParts_00__L_AutoScrollBtn_06				=	0x43,
	L_LeftParts_00__L_AutoScrollBtn_03				=	0x44,
	L_LeftParts_00__L_AutoScrollBtn_04				=	0x45,
	L_LeftParts_00__L_AutoScrollBtn_05				=	0x46,
	L_LeftParts_00__L_ScrollUpBtn_00				=	0x47,
	L_LeftParts_00__L_ScrollDownBtn_00				=	0x48,
	L_LeftParts_00__L_ScrollDecideBtn_00			=	0x49,
	L_LeftParts_00__L_Timer_00__L_UpBtn_00			=	0x4A,
	L_LeftParts_00__L_Timer_00__L_DownBtn_00		=	0x4B,
	L_LeftParts_00__L_Timer_00__L_CenterButton_00	=	0x4C,
	L_LeftParts_00__L_TimerDecideBtn_00				=	0x4D,
	L_LeftParts_00__L_SceneListBtn_00				=	0x4E,
	L_LeftParts_00__L_SceneListBtn_01				=	0x4F,
	L_LeftParts_00__L_SceneListBtn_02				=	0x50,
	L_LeftParts_00__L_SceneListBtn_03				=	0x51,
	L_LeftParts_00__L_SceneListBtn_04				=	0x52,
	L_LeftParts_00__L_SceneListBtn_05				=	0x53,
	L_LeftParts_00__L_SceneListBtn_06				=	0x54,
	L_LeftParts_00__L_SceneListBtn_07				=	0x55,
	L_LeftParts_00__L_SceneListBtn_08				=	0x56,
	L_LeftParts_00__L_SceneListBtn_09				=	0x57,
	L_LeftParts_00__L_ChangeHourBtn_00				=	0x58,
	L_LeftParts_00__L_SkinListBtn_00				=	0x59,
	L_LeftParts_00__L_SkinListBtn_01				=	0x5A,
	L_LeftParts_00__L_SkinListBtn_02				=	0x5B,
	L_LeftParts_00__L_SkinListBtn_03				=	0x5C,
	L_LeftParts_00__L_SkinListBtn_04				=	0x5D,
	L_LeftParts_00__L_CloseBtn_00					=	0x5E,
	L_LeftParts_00__L_BdLeftParts_00				=	0x5F,
	L_RightParts_00__L_MenuBtn_00					=	0x60,
	L_RightParts_00__L_SaveBtn_00					=	0x61,
	L_RightParts_00__L_EraserBtn_00					=	0x62,
	L_RightParts_00__L_UndoBtn_00					=	0x63,
	L_RightParts_00__L_ResetBtn_00					=	0x64,
	L_RightParts_00__L_BdRightSet_00				=	0x65,
	L_PullBtnSlider_00								=	0x66,
	L_BdEdit_00										=	0x67,
};

enum TilemapIndex : uint32 {						//	Not Exhaustive.
	TilemapIndex_Empty								=	0x000,
	TilemapIndex_Block								=	0x001,
	TilemapIndex_QuestionBlock						=	0x002,
	TilemapIndex_InvisibleBlock						=	0x003,
	TilemapIndex_NoteBlock							=	0x004,
	TilemapIndex_EmptyBlock							=	0x005,
	TilemapIndex_HardBlock							=	0x006,
	TilemapIndex_Coin								=	0x007,

	TilemapIndex_DonutBlock1						=	0x040,
	TilemapIndex_DonutBlock2						=	0x041,
	TilemapIndex_SpikeBlock							=	0x042,

	TilemapIndex_MusicNoteBlock						=	0x056,

	TilemapIndex_CloudBlock							=	0x066,

	TilemapIndex_IceBlock							=	0x078,

	TilemapIndex_PinkCoin							=	0x100,
	TilemapIndex_TurnBlockFrame1					=	0x101,
	TilemapIndex_TurnBlockFrame2					=	0x102,
	TilemapIndex_TurnBlockFrame3					=	0x103,

	TilemapIndex_FrozenCoin							=	0x110,

	TilemapIndex_SolidOnBlock						=	0x152,
	TilemapIndex_SolidOffBlock						=	0x153,

	TilemapIndex_DottedOnBlock						=	0x162,
	TilemapIndex_DottedOffBlock						=	0x163,

	TilemapIndex_OnSwitch							=	0x172,
	TilemapIndex_OffSwitch							=	0x173,

	TilemapIndex_SolidPBlock						=	0x2B0,
	TilemapIndex_DottedPBlock						=	0x2B1,
	TilemapIndex_FrozenBlock						=	0x2B2,
};

enum Actor_Flag : uint32 {
	Flag_AltVariant									=	0x00000004,
	Flag_AltVariant_Mask							=	0xFFFFFFFB,
	Flag_Size_Medium								=	0x00002000,
	Flag_Size_Large									=	0x00004000,
	Flag_Size_Mask									=	0xFFFF3FFF,
	Flag_TriVariant_1								=	0x00040000,
	Flag_TriVariant_2								=	0x00080000,
	Flag_TriVariant_Mask							=	0xFFF3FFFF,
};

enum Collision_Flag : uint32 {
	Flag_CatClimb									=	(1 << 4),
	Flag_Solid										=	(1 << 20),
	Flag_Vertical_OneWay							=	(1 << 21),
};

enum LeftPartsState : uint32 {
	LeftPartsState_ChangeSkin						=	0x10000,
	LeftPartsState_ChangeSceneSet					=	0x40000,
	LeftPartsState_ChangeSceneHour					=	0x80000,
};

enum EditorObjectID : uint32 {
	EditorObjectID_Ground,							//	Ground
	EditorObjectID_slope_l30,						//	Gentle Slope
	EditorObjectID_slope_l45,						//	Steep Slope
	EditorObjectID_Dokan,							//	Pipe
	EditorObjectID_Toge,							//	Spike
	EditorObjectID_GroundMushroom,					//	Mushroom Platform
	EditorObjectID_GroundBox,						//	Semi-Solid
	EditorObjectID_Bridge,							//	Bridge
	EditorObjectID_HatenaBlock,						//	Brick Block
	EditorObjectID_RengaBlock,						//	? Block
	EditorObjectID_HardBlock,						//	Hard Block
	EditorObjectID_ClearBlock,						//	Kaizo Block
	EditorObjectID_ChikuwaBlock,					//	Donut Block
	EditorObjectID_OnpuBlock,						//	Note Block
	EditorObjectID_KumoBlock,						//	Cloud Block
	EditorObjectID_IceBlock,						//	Ice Block
	EditorObjectID_Coin,							//	Coin
	EditorObjectID_BigCoin,							//	10/30/50 Coin
	EditorObjectID_PinkCoin,						//	Key Coin
	EditorObjectID_SuperKinoko,						//	Super Mushroom
	EditorObjectID_FireFlower,						//	Fire Flower
	EditorObjectID_SuperStar,						//	Super Star
	EditorObjectID_OneUpKinoko,						//	1-Up Mushroom
	EditorObjectID_SpecialItem,						//	Style PowerUp 1
	EditorObjectID_Kuribo,							//	Goomba
	EditorObjectID_Nokonoko,						//	Koopa
	EditorObjectID_Met,								//	Buzzy Bettle
	EditorObjectID_TogeMet,							//	Spike Top
	EditorObjectID_Togezo,							//	Spiny
	EditorObjectID_Gesso,							//	Blooper
	EditorObjectID_Pukupuku,						//	Cheep Cheep
	EditorObjectID_Pakkun,							//	Piranha Plant
	EditorObjectID_BlackPakkun,						//	Muncher
	EditorObjectID_Dossun,							//	Thwomp
	EditorObjectID_ChoroPoo,						//	Monty Mole
	EditorObjectID_Poo,								//	Rocky Wrench
	EditorObjectID_Bros,							//	Hammer Bro
	EditorObjectID_Wanwan,							//	Chain-Chomp
	EditorObjectID_SunMoon,							//	Sun/Moon
	EditorObjectID_Hanachan,						//	Wiggler
	EditorObjectID_Teresa,							//	Boo
	EditorObjectID_Bubble,							//	Poboboo
	EditorObjectID_Bombhei,							//	Bomb-Omb
	EditorObjectID_Karon,							//	Dry Bones
	EditorObjectID_FishBone,						//	Fish Bone
	EditorObjectID_Kameck,							//	Kamek
	EditorObjectID_KoopaClown,						//	Clown Car
	EditorObjectID_KutsuKuribo,						//	Kuribo's Shoe
	EditorObjectID_Jugem,							//	Lakitu
	EditorObjectID_Bunbun,							//	Boom-Boom
	EditorObjectID_Koopa,							//	Bowser
	EditorObjectID_KoopaJr,							//	Bowser Jr.
	EditorObjectID_PSwitch,							//	P-Switch
	EditorObjectID_PowBlock,						//	POW Block
	EditorObjectID_JumpStep,						//	Spring
	EditorObjectID_Key,								//	Key
	EditorObjectID_Door,							//	Door
	EditorObjectID_TsutaBlock,						//	Vine ?
	EditorObjectID_Yajirushi,						//	Arrow Sign
	EditorObjectID_MiddleFlag,						//	Checkpoint
	EditorObjectID_Lift,							//	Lift
	EditorObjectID_YouganLift,						//	Lava Lift
	EditorObjectID_Seesaw,							//	Seesaw
	EditorObjectID_Saw,								//	Saw
	EditorObjectID_Marumaru,						//	Bumper
	EditorObjectID_TogeKonbo,						//	Skewer
	EditorObjectID_BurankoCrane,					//	Swinging Claw
	EditorObjectID_Burner,							//	Burner
	EditorObjectID_KillerHoudai,					//	Bullet-Bill Launcher
	EditorObjectID_MagnumKiller,					//	Bonzai-Bill
	EditorObjectID_Houdai,							//	Cannon
	EditorObjectID_Icicle,							//	Icicle
	EditorObjectID_Tornado,							//	Twister
	EditorObjectID_OnOffSwitch,						//	On/Off Switch
	EditorObjectID_OnOffBlock,						//	On/Off Block
	EditorObjectID_SnakeBlock,						//	Snake Block
	EditorObjectID_FireBar,							//	Fire Bar
	EditorObjectID_Hanatari,						//	One-Way Platform
	EditorObjectID_BeltConveyor,					//	Conveyor Belt
	EditorObjectID_SlopeConveyor,					//	Sloped Conveyor Belt
	EditorObjectID_Rail,							//	Rail
	EditorObjectID_ToumeiDokan,						//	Clear Pipe
	EditorObjectID_TogeBlock,						//	Spike Block (3DW)
	EditorObjectID_GroundBox_3W,					//	Semi-Solid (3DW)
	EditorObjectID_SuperHammer,						//	Super Hammer
	EditorObjectID_Arihei,							//	Ant Trooper
	EditorObjectID_Fugumannen,						//	Porcupuffer
	EditorObjectID_PackunPipe,						//	Piranha Creeper
	EditorObjectID_Pyonchu,							//	Skipsqeak
	EditorObjectID_Hacchin,							//	Stingby
	EditorObjectID_Hopper,							//	Hop-Chop
	EditorObjectID_Donketsu,						//	Bully
	EditorObjectID_KoopaCar,						//	Car
	EditorObjectID_MagmaFish,						//	Charvaargh ?
	EditorObjectID_WarpBox,							//	Warp Box
	EditorObjectID_WoodBox,							//	Crate
	EditorObjectID_BikkuriBlock,					//	! Block
	EditorObjectID_OrbitBlock,						//	Track Block ?
	EditorObjectID_Chikachika,						//	Blinking Block
	EditorObjectID_BellTree,						//	Tree
	EditorObjectID_Trampoline,						//	Trampoline
	EditorObjectID_Gabon,							//	Spike
	EditorObjectID_Sambo,							//	Pokey
	EditorObjectID_PBlock,							//	P-Block
	EditorObjectID_DashBlock,						//	Dash Block
	EditorObjectID_SpecialItemExtra,				//	Style PowerUp 2
	EditorObjectID_KoopaMecha,						//	Mechakoopa
	EditorObjectID_Lemmy,							//	Lemmy
	EditorObjectID_Morton,							//	Morton
	EditorObjectID_Larry,							//	Larry
	EditorObjectID_Wendy,							//	Wendy
	EditorObjectID_Iggy,							//	Iggy
	EditorObjectID_Roy,								//	Roy
	EditorObjectID_Ludwig,							//	Ludwig
	EditorObjectID_BoxKiller,						//	Cannon Headdress (Bullet-Bill?)
	EditorObjectID_BoxPropeller,					//	Propeller Headdress
	EditorObjectID_BoxKuribo,						//	Goomba Headdress
	EditorObjectID_BoxKillerPlayer,					//	Bullet-Bill Headdress (Cannon?)
	EditorObjectID_BoxPow,							//	POW Headdress
	EditorObjectID_OnOffTrampoline,					//	On/Off Trampoline
	EditorObjectID_MegaBros,						//	Standalone Sledge Bro (Crashes)
	EditorObjectID_DokuKinoko,						//	Standalone Rotten Mushroom (Crashes)
	EditorObjectID_NokonokoShell,					//	Standalone Koopa Shell (Crashes)
	EditorObjectID_Killer,							//	Standalone Bullet-Bill (Crashes)
	EditorObjectID_Stone,							//	Stone (Crashes)
	EditorObjectID_Kinopio,							//	Toad (Crashes)
	EditorObjectID_Wing,							//	Wing?
	EditorObjectID_parachute,						//	Parachute?
	EditorObjectID_WaterSpeed,						//	Water Speed?
};

enum SoundEffectID : uint32 {
	SoundEffectID_Shock,							//	Shock
	SoundEffectID_Scream,							//	Scream
	SoundEffectID_Laughter,							//	Laughter
	SoundEffectID_LoudLaughter,						//	Guffaw
	SoundEffectID_Applause,							//	Applause
	SoundEffectID_Cheer,							//	Cheer
	SoundEffectID_Baby,								//	Baby
	SoundEffectID_Cracker,							//	Party Popper
	SoundEffectID_Boo,								//	Booo
	SoundEffectID_Incident,							//	NearMiss
	SoundEffectID_Clatter,							//	Clatter
	SoundEffectID_Drama,							//	Drama
	SoundEffectID_Kick,								//	Kick
	SoundEffectID_Jump,								//	Jump
	SoundEffectID_Honk,								//	HonkHonk
	SoundEffectID_Punch,							//	Punch
	SoundEffectID_Whoopee,							//	Oink
	SoundEffectID_Focus,							//	Kuh-Thunk
	SoundEffectID_Glitch,							//	Beep
	SoundEffectID_Uproar,							//	Ninja Attack
	SoundEffectID_Ding,								//	DingDong
	SoundEffectID_Bzzzt,							//	Bzzzt
	SoundEffectID_Glory,							//	Glory
	SoundEffectID_Doom,								//	Doom
	SoundEffectID_Discord,							//	Zap
	SoundEffectID_Halo,								//	Flash
	SoundEffectID_Admiration,						//	Yeah
	SoundEffectID_Anguish,							//	Aww
	SoundEffectID_Fireworks,						//	Fireworks
	SoundEffectID_Audience,							//	Audience
	SoundEffectID_Scat,								//	Scatting
	SoundEffectID_Firecracker,						//	Spark
	SoundEffectID_Ohayasi,							//	Traditional
	SoundEffectID_ElectricGuitar,					//	ElectricGuitar
	SoundEffectID_Boss,								//	Boss Music
	SoundEffectID_Bonus,							//	Bonus Music
	SoundEffectID_Heartbeat,						//	Heartbeat
	SoundEffectID_Silence,							//	Silence
	SoundEffectID_LastBoss,							//	FinalBoss
	SoundEffectID_Calm,								//	Peaceful
	SoundEffectID_Unrest,							//	Horror
	SoundEffectID_Mario00,							//	Super Mario Galaxy
	SoundEffectID_Mario01,							//	Super Mario 64
	SoundEffectID_Mario02,							//	Super Mario Sunshine
	SoundEffectID_Mario03,							//	Super Mario Kart
	SoundEffectID_Filter,							//	Twisty Turny
	SoundEffectID_Woozy,							//	???
};

enum PowerUpID : uint32 {
	PowerUpID_DekaKinoko,							//	Big Mushroom
	PowerUpID_SuperKonoha,							//	Super Leaf
	PowerUpID_MantleWing,							//	Cape Feather
	PowerUpID_PowerUpID_PropellerKinoko,			//	Propeller Mushroom
	PowerUpID_SuperBell,							//	Super Bell
	PowerUpID_KinokoUSA,							//	SMB2 Mushroom
	PowerUpID_FrogSuit,								//	Frog Suit
	PowerUpID_PowerBalloon,							//	Power Balloon
	PowerUpID_SuperDonguri,							//	Super Acorn
	PowerUpID_BoomerangFlower,						//	Boomerang Flower
};

enum LocalCourseLocation : uint32 {
	LocalCourseLocation_cSave01,
	LocalCourseLocation_cSave02,
	LocalCourseLocation_cSave03,
	LocalCourseLocation_cSave04,
	LocalCourseLocation_cSave05,
	LocalCourseLocation_cSave06,
	LocalCourseLocation_cSave07,
	LocalCourseLocation_cSave08,
	LocalCourseLocation_cSave09,
	LocalCourseLocation_cSave10,
	LocalCourseLocation_cSave11,
	LocalCourseLocation_cSave12,
	LocalCourseLocation_cSave13,
	LocalCourseLocation_cSave14,
	LocalCourseLocation_cSave15,
	LocalCourseLocation_cSave16,
	LocalCourseLocation_cSave17,
	LocalCourseLocation_cSave18,
	LocalCourseLocation_cSave19,
	LocalCourseLocation_cSave20,
	LocalCourseLocation_cSave21,
	LocalCourseLocation_cSave22,
	LocalCourseLocation_cSave23,
	LocalCourseLocation_cSave24,
	LocalCourseLocation_cSave25,
	LocalCourseLocation_cSave26,
	LocalCourseLocation_cSave27,
	LocalCourseLocation_cSave28,
	LocalCourseLocation_cSave29,
	LocalCourseLocation_cSave30,
	LocalCourseLocation_cSave31,
	LocalCourseLocation_cSave32,
	LocalCourseLocation_cSave33,
	LocalCourseLocation_cSave34,
	LocalCourseLocation_cSave35,
	LocalCourseLocation_cSave36,
	LocalCourseLocation_cSave37,
	LocalCourseLocation_cSave38,
	LocalCourseLocation_cSave39,
	LocalCourseLocation_cSave40,
	LocalCourseLocation_cSave41,
	LocalCourseLocation_cSave42,
	LocalCourseLocation_cSave43,
	LocalCourseLocation_cSave44,
	LocalCourseLocation_cSave45,
	LocalCourseLocation_cSave46,
	LocalCourseLocation_cSave47,
	LocalCourseLocation_cSave48,
	LocalCourseLocation_cSave49,
	LocalCourseLocation_cSave50,
	LocalCourseLocation_cSave51,
	LocalCourseLocation_cSave52,
	LocalCourseLocation_cSave53,
	LocalCourseLocation_cSave54,
	LocalCourseLocation_cSave55,
	LocalCourseLocation_cSave56,
	LocalCourseLocation_cSave57,
	LocalCourseLocation_cSave58,
	LocalCourseLocation_cSave59,
	LocalCourseLocation_cSave60,
	LocalCourseLocation_cSave61,
	LocalCourseLocation_cSave62,
	LocalCourseLocation_cSave63,
	LocalCourseLocation_cSave64,
	LocalCourseLocation_cSave65,
	LocalCourseLocation_cSave66,
	LocalCourseLocation_cSave67,
	LocalCourseLocation_cSave68,
	LocalCourseLocation_cSave69,
	LocalCourseLocation_cSave70,
	LocalCourseLocation_cSave71,
	LocalCourseLocation_cSave72,
	LocalCourseLocation_cSave73,
	LocalCourseLocation_cSave74,
	LocalCourseLocation_cSave75,
	LocalCourseLocation_cSave76,
	LocalCourseLocation_cSave77,
	LocalCourseLocation_cSave78,
	LocalCourseLocation_cSave79,
	LocalCourseLocation_cSave80,
	LocalCourseLocation_cSave81,
	LocalCourseLocation_cSave82,
	LocalCourseLocation_cSave83,
	LocalCourseLocation_cSave84,
	LocalCourseLocation_cSave85,
	LocalCourseLocation_cSave86,
	LocalCourseLocation_cSave87,
	LocalCourseLocation_cSave88,
	LocalCourseLocation_cSave89,
	LocalCourseLocation_cSave90,
	LocalCourseLocation_cSave91,
	LocalCourseLocation_cSave92,
	LocalCourseLocation_cSave93,
	LocalCourseLocation_cSave94,
	LocalCourseLocation_cSave95,
	LocalCourseLocation_cSave96,
	LocalCourseLocation_cSave97,
	LocalCourseLocation_cSave98,
	LocalCourseLocation_cSave99,
	LocalCourseLocation_cSave100,
	LocalCourseLocation_cSave101,
	LocalCourseLocation_cSave102,
	LocalCourseLocation_cSave103,
	LocalCourseLocation_cSave104,
	LocalCourseLocation_cSave105,
	LocalCourseLocation_cSave106,
	LocalCourseLocation_cSave107,
	LocalCourseLocation_cSave108,
	LocalCourseLocation_cSave109,
	LocalCourseLocation_cSave110,
	LocalCourseLocation_cSave111,
	LocalCourseLocation_cSave112,
	LocalCourseLocation_cSave113,
	LocalCourseLocation_cSave114,
	LocalCourseLocation_cSave115,
	LocalCourseLocation_cSave116,
	LocalCourseLocation_cSave117,
	LocalCourseLocation_cSave118,
	LocalCourseLocation_cSave119,
	LocalCourseLocation_cSave120,
	LocalCourseLocation_cDLSave001,
	LocalCourseLocation_cDLSave002,
	LocalCourseLocation_cDLSave003,
	LocalCourseLocation_cDLSave004,
	LocalCourseLocation_cDLSave005,
	LocalCourseLocation_cDLSave006,
	LocalCourseLocation_cDLSave007,
	LocalCourseLocation_cDLSave008,
	LocalCourseLocation_cDLSave009,
	LocalCourseLocation_cDLSave010,
	LocalCourseLocation_cDLSave011,
	LocalCourseLocation_cDLSave012,
	LocalCourseLocation_cDLSave013,
	LocalCourseLocation_cDLSave014,
	LocalCourseLocation_cDLSave015,
	LocalCourseLocation_cDLSave016,
	LocalCourseLocation_cDLSave017,
	LocalCourseLocation_cDLSave018,
	LocalCourseLocation_cDLSave019,
	LocalCourseLocation_cDLSave020,
	LocalCourseLocation_cDLSave021,
	LocalCourseLocation_cDLSave022,
	LocalCourseLocation_cDLSave023,
	LocalCourseLocation_cDLSave024,
	LocalCourseLocation_cDLSave025,
	LocalCourseLocation_cDLSave026,
	LocalCourseLocation_cDLSave027,
	LocalCourseLocation_cDLSave028,
	LocalCourseLocation_cDLSave029,
	LocalCourseLocation_cDLSave030,
	LocalCourseLocation_cDLSave031,
	LocalCourseLocation_cDLSave032,
	LocalCourseLocation_cDLSave033,
	LocalCourseLocation_cDLSave034,
	LocalCourseLocation_cDLSave035,
	LocalCourseLocation_cDLSave036,
	LocalCourseLocation_cDLSave037,
	LocalCourseLocation_cDLSave038,
	LocalCourseLocation_cDLSave039,
	LocalCourseLocation_cDLSave040,
	LocalCourseLocation_cDLSave041,
	LocalCourseLocation_cDLSave042,
	LocalCourseLocation_cDLSave043,
	LocalCourseLocation_cDLSave044,
	LocalCourseLocation_cDLSave045,
	LocalCourseLocation_cDLSave046,
	LocalCourseLocation_cDLSave047,
	LocalCourseLocation_cDLSave048,
	LocalCourseLocation_cDLSave049,
	LocalCourseLocation_cDLSave050,
	LocalCourseLocation_cDLSave051,
	LocalCourseLocation_cDLSave052,
	LocalCourseLocation_cDLSave053,
	LocalCourseLocation_cDLSave054,
	LocalCourseLocation_cDLSave055,
	LocalCourseLocation_cDLSave056,
	LocalCourseLocation_cDLSave057,
	LocalCourseLocation_cDLSave058,
	LocalCourseLocation_cDLSave059,
	LocalCourseLocation_cDLSave060,
	LocalCourseLocation_cMem,
	LocalCourseLocation_cNew,
	LocalCourseLocation_cTitle,
	LocalCourseLocation_cQuest1,
	LocalCourseLocation_cQuest2,
	LocalCourseLocation_cQuest3,
	LocalCourseLocation_cQuest4,
	LocalCourseLocation_cQuest5,
	LocalCourseLocation_cQuest6,
	LocalCourseLocation_cQuest7,
	LocalCourseLocation_cQuest8,
	LocalCourseLocation_cQuest9,
	LocalCourseLocation_cQuest10,
	LocalCourseLocation_cQuest11,
	LocalCourseLocation_cQuest12,
	LocalCourseLocation_cQuest13,
	LocalCourseLocation_cQuest14,
	LocalCourseLocation_cQuest15,
	LocalCourseLocation_cQuest16,
	LocalCourseLocation_cQuest17,
	LocalCourseLocation_cQuest18,
	LocalCourseLocation_cQuest19,
	LocalCourseLocation_cQuest20,
	LocalCourseLocation_cQuest21,
	LocalCourseLocation_cQuest22,
	LocalCourseLocation_cQuest23,
	LocalCourseLocation_cQuest24,
	LocalCourseLocation_cQuest25,
	LocalCourseLocation_cQuest26,
	LocalCourseLocation_cQuest27,
	LocalCourseLocation_cQuest28,
	LocalCourseLocation_cQuest29,
	LocalCourseLocation_cQuest30,
	LocalCourseLocation_cQuest31,
	LocalCourseLocation_cQuest32,
	LocalCourseLocation_cQuest33,
	LocalCourseLocation_cQuest34,
	LocalCourseLocation_cQuest35,
	LocalCourseLocation_cQuest36,
	LocalCourseLocation_cQuest37,
	LocalCourseLocation_cQuest38,
	LocalCourseLocation_cQuest39,
	LocalCourseLocation_cQuest40,
	LocalCourseLocation_cQuest41,
	LocalCourseLocation_cQuest42,
	LocalCourseLocation_cQuest43,
	LocalCourseLocation_cQuest44,
	LocalCourseLocation_cQuest45,
	LocalCourseLocation_cQuest46,
	LocalCourseLocation_cQuest47,
	LocalCourseLocation_cQuest48,
	LocalCourseLocation_cQuest49,
	LocalCourseLocation_cQuest50,
	LocalCourseLocation_cQuest51,
	LocalCourseLocation_cQuest52,
	LocalCourseLocation_cQuest53,
	LocalCourseLocation_cQuest54,
	LocalCourseLocation_cQuest55,
	LocalCourseLocation_cQuest56,
	LocalCourseLocation_cQuest57,
	LocalCourseLocation_cQuest58,
	LocalCourseLocation_cQuest59,
	LocalCourseLocation_cQuest60,
	LocalCourseLocation_cQuest61,
	LocalCourseLocation_cQuest62,
	LocalCourseLocation_cQuest63,
	LocalCourseLocation_cQuest64,
	LocalCourseLocation_cQuest65,
	LocalCourseLocation_cQuest66,
	LocalCourseLocation_cQuest67,
	LocalCourseLocation_cQuest68,
	LocalCourseLocation_cQuest69,
	LocalCourseLocation_cQuest70,
	LocalCourseLocation_cQuest71,
	LocalCourseLocation_cQuest72,
	LocalCourseLocation_cQuest73,
	LocalCourseLocation_cQuest74,
	LocalCourseLocation_cQuest75,
	LocalCourseLocation_cQuest76,
	LocalCourseLocation_cQuest77,
	LocalCourseLocation_cQuest78,
	LocalCourseLocation_cQuest79,
	LocalCourseLocation_cQuest80,
	LocalCourseLocation_cQuest81,
	LocalCourseLocation_cQuest82,
	LocalCourseLocation_cQuest83,
	LocalCourseLocation_cQuest84,
	LocalCourseLocation_cQuest85,
	LocalCourseLocation_cQuest86,
	LocalCourseLocation_cQuest87,
	LocalCourseLocation_cQuest88,
	LocalCourseLocation_cQuest89,
	LocalCourseLocation_cQuest90,
	LocalCourseLocation_cQuest91,
	LocalCourseLocation_cQuest92,
	LocalCourseLocation_cQuest93,
	LocalCourseLocation_cQuest94,
	LocalCourseLocation_cQuest95,
	LocalCourseLocation_cQuest96,
	LocalCourseLocation_cQuest97,
	LocalCourseLocation_cQuest98,
	LocalCourseLocation_cQuest99,
	LocalCourseLocation_cQuest100,
	LocalCourseLocation_cQuest101,
	LocalCourseLocation_cQuest102,
	LocalCourseLocation_cQuest103,
	LocalCourseLocation_cQuest104,
	LocalCourseLocation_cQuest105,
	LocalCourseLocation_cQuest106,
	LocalCourseLocation_cQuest107,
	LocalCourseLocation_cQuest108,
	LocalCourseLocation_cQuest109,
	LocalCourseLocation_cQuest110,
	LocalCourseLocation_cQuest111,
	LocalCourseLocation_cQuest112,
	LocalCourseLocation_cQuest113,
	LocalCourseLocation_cQuest114,
	LocalCourseLocation_cQuest115,
	LocalCourseLocation_cQuest116,
	LocalCourseLocation_cQuest117,
	LocalCourseLocation_cQuest118,
	LocalCourseLocation_cQuest119,
	LocalCourseLocation_cQuest120,
	LocalCourseLocation_cLesson1,
	LocalCourseLocation_cLesson2,
	LocalCourseLocation_cLesson3,
	LocalCourseLocation_cLesson4,
	LocalCourseLocation_cLesson5,
	LocalCourseLocation_cLesson6,
	LocalCourseLocation_cLesson7,
	LocalCourseLocation_cLesson8,
	LocalCourseLocation_cLesson9,
	LocalCourseLocation_cLesson10,
	LocalCourseLocation_cLesson11,
	LocalCourseLocation_cLesson12,
	LocalCourseLocation_cLesson13,
	LocalCourseLocation_cLesson14,
	LocalCourseLocation_cLesson15,
	LocalCourseLocation_cLesson16,
	LocalCourseLocation_cLesson17,
	LocalCourseLocation_cLesson18,
	LocalCourseLocation_cLesson19,
	LocalCourseLocation_cLesson20,
	LocalCourseLocation_cLesson21,
	LocalCourseLocation_cLesson22,
	LocalCourseLocation_cLesson23,
	LocalCourseLocation_cLesson24,
	LocalCourseLocation_cLesson25,
	LocalCourseLocation_cLesson26,
	LocalCourseLocation_cLesson27,
	LocalCourseLocation_cLesson28,
	LocalCourseLocation_cLesson29,
	LocalCourseLocation_cLesson30,
	LocalCourseLocation_cLesson31,
	LocalCourseLocation_cLesson32,
	LocalCourseLocation_cLesson33,
	LocalCourseLocation_cLesson34,
	LocalCourseLocation_cLesson35,
	LocalCourseLocation_cLesson36,
	LocalCourseLocation_cLesson37,
	LocalCourseLocation_cLesson38,
	LocalCourseLocation_cLesson39,
	LocalCourseLocation_cLesson40,
	LocalCourseLocation_cLesson41,
	LocalCourseLocation_cLesson42,
	LocalCourseLocation_cLesson43,
	LocalCourseLocation_cLesson44,
	LocalCourseLocation_cLesson45,
	LocalCourseLocation_cLesson46,
	LocalCourseLocation_cLesson47,
	LocalCourseLocation_cLesson48,
	LocalCourseLocation_cLesson49,
	LocalCourseLocation_cLesson50,
	LocalCourseLocation_cLesson51,
	LocalCourseLocation_cLesson52,
	LocalCourseLocation_cLesson53,
	LocalCourseLocation_cLesson54,
	LocalCourseLocation_cLesson55,
	LocalCourseLocation_cLesson56,
	LocalCourseLocation_cLesson57,
	LocalCourseLocation_cLesson58,
	LocalCourseLocation_cLesson59,
	LocalCourseLocation_cLesson60,
	LocalCourseLocation_cLesson61,
	LocalCourseLocation_cLesson62,
	LocalCourseLocation_cLesson63,
	LocalCourseLocation_cLesson64,
	LocalCourseLocation_cLesson65,
	LocalCourseLocation_cLesson66,
	LocalCourseLocation_cLesson67,
	LocalCourseLocation_cLesson68,
	LocalCourseLocation_cLesson69,
	LocalCourseLocation_cLesson70,
	LocalCourseLocation_cLesson71,
	LocalCourseLocation_cLesson72,
	LocalCourseLocation_cLesson73,
	LocalCourseLocation_cLesson74,
	LocalCourseLocation_cLesson75,
	LocalCourseLocation_cLesson76,
	LocalCourseLocation_cLesson77,
	LocalCourseLocation_cLesson78,
	LocalCourseLocation_cLesson79,
	LocalCourseLocation_cLesson80,
	LocalCourseLocation_cLesson81,
	LocalCourseLocation_cLesson82,
	LocalCourseLocation_cLesson83,
	LocalCourseLocation_cLesson84,
	LocalCourseLocation_cLesson85,
	LocalCourseLocation_cLesson86,
	LocalCourseLocation_cLesson87,
	LocalCourseLocation_cLesson88,
	LocalCourseLocation_cLesson89,
	LocalCourseLocation_cLesson90,
	LocalCourseLocation_cLesson91,
	LocalCourseLocation_cLesson92,
	LocalCourseLocation_cLesson93,
	LocalCourseLocation_cLesson94,
	LocalCourseLocation_cLesson95,
	LocalCourseLocation_cLesson96,
	LocalCourseLocation_cLesson97,
	LocalCourseLocation_cLesson98,
	LocalCourseLocation_cLesson99,
	LocalCourseLocation_cLesson100,
	LocalCourseLocation_MAX,
};

#endif	//	CUSTOMENUMS_HPP