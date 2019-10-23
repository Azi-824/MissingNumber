//main.hpp

#pragma once

//************ ヘッダーファイル読み込み ***********
#include "DxLib.h"

//************ マクロ定義 ***************
#define GAME_WIDTH	1000		//画面の横の大きさ
#define GAME_HEIGHT	600			//画面の縦の大きさ
#define Q_ERIA_WIDTH	960		//問題を描画する画面の大きさ
#define Q_ERIA_HEIGHT	450		//問題を描画する画面の大きさ
#define GAME_COLOR	32			//画面のカラービット

#define GAME_WINDOW_NAME	"Missing Numbers"		//ウィンドウのタイトル
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE：ウィンドウモード / FALSE：フルスクリーン

#define SET_WINDOW_ST_MODE_DEFAULT			0	//デフォルト
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//タイトルバーなし
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//タイトルバーとフレームなし
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//フレームなし

#define GAME_FPS_SPEED	60						//FPS速度

