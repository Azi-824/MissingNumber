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

#define POINT_MAX_KETA	2	//データの得点のMAX桁数

#define ZERO_IMAGE		"NUMBER\\zero.png"			//0の画像
#define ONE_IMAGE		"NUMBER\\one.png"			//1の画像
#define TWO_IMAGE		"NUMBER\\two.png"			//2の画像
#define THREE_IMAGE		"NUMBER\\three.png"			//3の画像
#define FOUR_IMAGE		"NUMBER\\four.png"			//4の画像
#define FIVE_IMAGE		"NUMBER\\five.png"			//5の画像
#define SIX_IMAGE		"NUMBER\\six.png"			//6の画像
#define SEVEN_IMAGE		"NUMBER\\seven.png"			//7の画像
#define EIGHT_IMAGE		"NUMBER\\eight.png"			//8の画像
#define NINE_IMAGE		"NUMBER\\nine.png"			//9の画像
#define NUMBER_IMAGE	"NUMBER\\num.png"			//数字の画像

#define END_IMAGE		"ENDIMAGE\\end.png"			//終了の画像
#define CONTINUE_IMAGE	"ENDIMAGE\\continue.png"	//続行の画像
#define START_IMAGE		"STARTIMAGE\\start.png"		//スタートの画像
#define END_IMAGE2		"STARTIMAGE\\end.png"		//スタート選択画面の終了の画像
#define TITLE_IMAGE     "STARTIMAGE\\title.png"		//タイトルの画像

#define YES_IMAGE		"SELECTIMAGE\\yes.png"		//はいの画像
#define NO_IMAGE		"SELECTIMAGE\\no.png"		//いいえの画像

#define TITLE_BACKIMAGE "BACKIMAGE\\back5.jpg"		//タイトル画面の背景画像
#define SELECT_BACKIMAGE "BACKIMAGE\\back3.jpg"		//難易度選択画面の背景画像
#define PLAY_BACKIMAGE	"BACKIMAGE\\back6.jpg"		//プレイ画面の背景画像
#define RESULT_BACKIMAGE "BACKIMAGE\\back2.jpg"		//リザルト画面の背景画像
#define	END_BACKIMAGE	"BACKIMAGE\\back6.jpg"		//エンド画面の背景画像

#define SETUMEI_IMAGE	"SETUMEI\\setumei.png"				//せつめいの画像
#define SETUMEI_LEVLEIMAGE "SETUMEI\\level_image.png"		//レベルの説明画像
#define SETUMEI_PLAYIMAGE	"SETUMEI\\play_image.png"		//プレイ画面の説明画像
#define SETUMEI_NEXT		"SETUMEI\\next.png"				//矢印の画像

#define RETIRE_IMAGE	"RETIREIMAGE\\retire.png"			//途中でやめるの画像


#define MUSIC_SE_TRUE	"SE\\true.mp3"				//正解した時の効果音
#define MUSIC_SE_FALSE	"SE\\false.mp3"				//不正解だった時の効果音
#define MUSIC_SE_CLICK	"SE\\click.mp3"				//クリックしたときの効果音
#define MUSIC_SE_CLICK2	"SE\\kettei.mp3"			//選択肢をクリックしたときの効果音
#define MUSIC_SE_COUNTDOWN	"SE\\countdown.mp3"		//カウントダウンの効果音

#define MUSIC_BGM		"BGM\\cyber42.mp3"			//BGM

#define SAVE_DATA		"C:\\Missing Numbers_SAVE\\Save.dat"		//セーブデータ
#define GAME_DATA		"C:\\Missing Numbers_SAVE"					//セーブデータを入れるフォルダのパス

#define GAZOU_SPACE		50				//画像と画像の間隔

#define LEVEL_KIND	3					//ゲーム難易度の数
#define QUESTION_KAZU 10				//問題数
#define END_KIND 2						//終了の数
#define START_KIND 3					//スタート画面に表示する画像の数
#define SELECT_KIND 2					//選択肢の数（はい、いいえ）
#define BACKIMAGE_KIND 5				//背景画像の種類
#define DIRECTION_KIND 8				//移動方向の種類
#define SETUMEI_KIND   2				//説明画面で使用する画像の種類
#define SETU_KIND	   2				//説明画面で使う矢印などの画像の種類

#define FONT_SIZE 140					//フォントのサイズ
#define FONT_BOLD 3						//フォントの太さ

#define NUMBER_KIND 10					//数の種類

#define PI 3.141592654					//弧度法で使用
#define EXPANSION 1.0					//拡大率

#define NUMBER_KAZU 1					//数字の画像の数

#define RECT_TATE_SIZE 147				//回答用の数字の領域の縦サイズ
#define RECT_YOKO_SIZE 100				//回答用の数字の領域の横サイズ
#define RECT_CNT  10					//回答用の数字の領域の数

#define RANKING_NUM	5					//ランキングの描画する数（上位５個まで描画）

#define GAMETIME 30						//ゲームの制限時間

#define REVERSE_TYPE 1					//反転させるかどうかをフラグで使用する際につかう

#define TOUKA_MIN	80					//透過率の最低値

//########## 列挙型 ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,	//タイトル画面
	GAME_SCENE_SETUMEI,	//説明画面
	GAME_SCENE_CHECK,	//はいかいいえの選択肢を描画する画面
	GAME_SCENE_SET,		//設定画面
	GAME_SCENE_PLAY,	//プレイ画面
	GAME_SCENE_RESULT,	//結果表示画面
	GAME_SCENE_RANKING,	//ランキング表示画面
};

enum GAME_LEVEL {
	GAME_LEVEL_EASY,	//簡単
	GAME_LEVEL_NORMAL,	//普通
	GAME_LEVEL_HARD		//難しい
};

enum END_TYPE {
	GAME_CONTINUE,	//続行
	GAME_END		//終了
};

enum START_TYPE {
	GAME_START,	//スタート
	GAME_SETUMEI,//説明
	GAME_END2	//終了
};

enum SELECT {
	SELECT_YES,	//はい
	SELECT_NO	//いいえ
};

enum BACKIMAGE_SCENE {
	BACKIMAGE_TITLE,	//タイトル画面の背景
	BACKIMAGE_SELECT,	//セレクト画面の背景
	BACKIMAGE_PLAY,		//プレイ画面の背景
	BACKIMAGE_RESULT,	//リザルト画面の背景
	BACKIMAGE_END		//エンド画面の背景
};

enum SETUMEI {
	BACKIMAGE_SETULEVEL,//説明画面のレベル説明
	BACKIMAGE_SETUPLAY,	//説明画面のプレイ説明
};

enum MOVE_DIRECTION {
	DIRECTION_UP,		//移動方向、上
	DIRECTION_DOWN,		//移動方向、下
	DIRECTION_LEFT,		//移動方向、左
	DIRECTION_RIGHT,	//移動方向、右
	DIRECTION_LEFTUP,	//移動方向、左上
	DIRECTION_LEFTDOWN,	//移動方向、左下
	DIRECTION_RIGHTUP,	//移動方向、右上
	DIRECTION_RIGHTDOWN	//移動方向、右下
};//移動方向

//########## 構造体 ##########
struct STRUCT_GAZOU {
	int Handle;				//画像のハンドル
	char FilePath[128];		//ファイルのパス
	int X;					//横の位置
	int Y;					//縦の位置
	int Width;				//横のサイズ	
	int Height;				//縦のサイズ
	int C_Width;			//横の中心位置
	int C_Height;			//縦の中心位置
	int Direction;			//画像の移動向き
	BOOL Num_flg;			//数字用フラグ
	BOOL Positon_flg;		//座標設定完了用フラグ
	BOOL Reverse_flg;		//左右反転フラグ
	BOOL IsDraw;			//描画してよいか
	BOOL SetIsDraw_flg;		//描画してよいかを設定したか
	int Color;				//色
	int touka;				//透過率
};

struct STRUCT_MOUSE {
	int X;		//マウスのx座標
	int Y;		//マウスのY座標
	int Mouse_Input;	//マウスのクリック情報
	int Mouse_Click_Num;//マウスがクリックされた画像の番号を入れる
	int Mouse_Click_Cnt;//マウスがクリックされている間カウントする
	BOOL Mouse_hover_flg;	//画像の上にマウスが乗っている状態か確認するフラグ
	BOOL Mouse_LeftClick_flg;	//左クリックされたか確認するフラグ
};

struct STRUCT_MUSIC
{
	int Handle;			//音のハンドル
	char FilePath[128];	//ファイルのパス
	int Playtype;		//音の再生方法
};	//音構造体

struct STRUCT_SAVE {
	int point;	//得点
	int year;	//年
	int mounth;	//月
	int day;	//日
};	//セーブデータ構造体

//****************名前の再定義********************
typedef STRUCT_GAZOU GAZOU;
typedef STRUCT_MOUSE MOUSE;
typedef STRUCT_MUSIC MUSIC;
typedef STRUCT_SAVE SAVE;

//########## グローバル変数 ##########

//ウィンドウ関係
WNDPROC WndProc;						//ウィンドウプロシージャのアドレス
BOOL IsWM_CREATE = FALSE;				//WM_CREATEが正常に動作したか判断する

//キーボード関連
char AllKeyState[256];			//すべてのキーの状態が入

//マウス関連
MOUSE Mouse_Date;		//マウスの情報

//シーン関連
int GameSceneNow = (int)GAME_SCENE_SETUMEI;	//最初のゲーム画面をタイトルに設定

//問題関連
int Player_Anser = 0;								//プレイヤーの回答を入れる変数
int True_Kazu = 0;									//プレイヤーの正解数を入れる変数
int Q_Sum = 0;										//答えた問題の合計数
int Speed = 1;										//問題の移動速度

//画像関連
GAZOU Number_Image[NUMBER_KIND];					//数の画像
GAZOU Num_Image;									//回答用の数字の画像
GAZOU End_Image[END_KIND];							//終了の選択肢の画像
GAZOU Start_Image[START_KIND];						//スタートの画像
GAZOU Back_Image[BACKIMAGE_KIND];					//背景画像
GAZOU Select_Image[SELECT_KIND];					//選択肢の画像（はい、いいえ）
GAZOU Setumei_Image[SETUMEI_KIND];					//説明画面で使用する画像
GAZOU Setu_Image;									//説明画面の小物画像(矢印など)
GAZOU Title_Image;									//タイトルの画像
GAZOU Retire_Image;									//途中でやめるの画像
int BackImageNow = BACKIMAGE_TITLE;					//現在の背景画像の種類
int Setu_Now = BACKIMAGE_SETULEVEL;					//現在の説明段階

//領域関連
RECT Q_rect[QUESTION_KAZU];							//問題の領域
RECT A_num[RECT_CNT];								//回答の選択肢の領域
RECT End_rect[END_KIND];							//終了の選択肢の領域
RECT Start_rect[START_KIND];						//スタートの選択肢の領域
RECT Select_rect[SELECT_KIND];						//選択肢の領域（はい、いいえ)
RECT Setu_rect;										//説明画面の小物画像(矢印など)の領域
RECT Retire_rect;									//途中でやめるの領域

//難易度関連
int Game_Level_Now;									//現在のゲームの難易度を入れる変数

//フラグ関連
BOOL True_flg = FALSE;								//プレイヤーの回答が正解の時
BOOL False_flg = FALSE;								//プレイヤーの回答が不正解の時
BOOL End_flg = FALSE;								//ゲーム終了の時
BOOL Setumei_flg = TRUE;							//説明フラグ
BOOL Continue_flg = FALSE;							//ゲーム続行の時
BOOL Start_flg = FALSE;								//ゲームスタートフラグ
BOOL Yes_flg = FALSE;								//はいのフラグ
BOOL No_flg = FALSE;								//いいえのフラグ
BOOL GameEnd_flg = FALSE;							//ゲーム終了のフラグ
BOOL Write_flg = FALSE;								//データの書き込みを下かどうかのフラグ
BOOL Sort_flg = FALSE;								//ソートフラグ
BOOL Read_flg = FALSE;								//読み込みフラグ
BOOL Delete_flg = FALSE;							//セーブデータ削除フラグ
BOOL WaitTime_flg = FALSE;							//時間を待つためのフラグ
BOOL First_flg = TRUE;								//最初の問題
BOOL CountDownStart_flg = FALSE;					//カウントダウンスタートのフラグ
BOOL Retire_flg = FALSE;							//リタイアフラグ
BOOL Flashing_flg = FALSE;							//点滅フラグ


//時間関連
double StartTime = 0;	//計測開始時間
double NokoriTime = 0;	//残り時間
double LostTimeStart = 0;//中断し始めた時間
double LostTimeEnd = 0;	//中断し終わった時間
double LostTime = 0;	//中断していた時間
double DrawTime = 0;	//描画している時間
double DrawStartTime = 0;	//描画開始時間
int Time_Draw_X = 300;	//時間表示のX座標
int Time_Draw_Y = 0;	//時間表示のY座標
int LimitTime = 30;		//制限時間
DATEDATA Date;			//日付

//音関連
MUSIC SE_TRUE;			//正解した時に鳴る音
MUSIC SE_FALSE;			//不正解した時に鳴る音
MUSIC SE_CLICK;			//クリックしたときの効果音
MUSIC SE_KETTEI;		//選択肢をクリックしたときの効果音
MUSIC SE_COUNTDOWN;		//カウントダウンの時の効果音
MUSIC BGM;				//BGM

//セーブデータ関連
SAVE SaveData[128] = { 0 };		//セーブデータを入れる配列
int SaveNowCnt = 0;				//セーブデータが何個入っているかカウントする変数
int SaveMaxNum = 0;				//セーブデータの中の最大値
int SaveMinNum = 0;				//セーブデータの中の最小値

//########## プロトタイプ宣言 ##########
//LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);	//自作ウィンドウプロシージャ

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する関数

VOID MY_GAME_TITLE(VOID);			//タイトル画面の関数
VOID MY_GAME_SETUMEI(VOID);			//説明画面の関数
VOID MY_GAME_CHECK(VOID);			//確認画面の関数
VOID MY_GAME_SET(VOID);				//設定画面の関数
VOID MY_GAME_PLAY(VOID);			//プレイ画面の関数
VOID MY_GAME_RESULT(VOID);			//リザルト画面の関数
VOID MY_GAME_RANKING(VOID);			//ランキング画面の関数

VOID MY_DRAW_STRING_CENTER_CENTER(char[][128], int, char *, int);	//画面中央に文字を描画する関数
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL);								//文字をデフォルトフォントに設定する関数
int CREATE_FONT(int);												//フォントハンドルを作成する関数

BOOL MY_GAZOU_LOAD(GAZOU *, int, int, const char *);				//画像を読み込む関数

VOID MY_CREATE_QUESTION(VOID);		//問題を生成する関数

BOOL MY_INIT(VOID);					//初期化関数

VOID GAMELEVEL_IMAGE_DRAW(VOID);	//難易度を描画する関数
VOID STATE_DRAW(VOID);				//情報を描画する関数
VOID DRAW_START(VOID);				//スタート画面の描画をする関数
VOID DRAW_SELECT(VOID);				//はいといいえの画像を描画する関数
VOID DRAW_QUESTION(VOID);			//問題を描画する関数
VOID DRAW_ANSER_NUM(VOID);			//回答用の選択肢を描画する関数
VOID DRAW_RESULET(VOID);			//結果を描画する関数
VOID DRAW_END_IMAGE(VOID);			//終了の選択肢を描画する関数
VOID DRAW_BACKIMAGE(GAZOU *);		//指定した背景画像を描画する関数
VOID DRAW_TIME(VOID);				//時間を描画する関数
VOID DRAW_RANKING(SAVE, int);		//ランキングを描画する関数
VOID DRAW_WAIT_TIME(int wait);		//待ち時間を描画する関数
VOID DRAW_SETU(VOID);				//説明時に使用する小物（矢印など）を描画する関数
VOID Draw_Retire();					//やめるの画像を描画する関数

VOID RECT_SETTING(RECT *, int, int, int, int);	//領域を設定する関数
VOID RECT_RESET(RECT *);						//領域を初期化する関数
BOOL MY_CHECK_RECT_ATARI(RECT, RECT);			//領域と領域の当たり判定をする関数

VOID GET_MOUSE_STATE(RECT *, int);	//マウスの情報を取得する関数
VOID RESET_MOUSE_DATE(VOID);		//マウスの情報をリセットする関数
BOOL CHECK_RECT_ATARI(RECT, MOUSE);	//マウスが画像の領域内かどうか判断する関数

VOID SET_SELECT_IMAGE(VOID);		//はいといいえの画像描画の設定をする関数
VOID SET_START_IMAGE(VOID);			//スタート画面の設定をする関数
VOID SET_ANSER_NUM(VOID);			//回答用の数字の設定をする関数
VOID GET_PLAYER_ANSER(int);			//プレイヤーの回答を取得する関数
VOID SET_END_IMAGE(VOID);			//終了の選択肢の画像の設定をする関数
VOID SET_END_SETU(VOID);			//説明で使用する小物（矢印など）の設定をする関数
BOOL MY_MUSIC_LOAD(MUSIC *, const char *);	//音を読み込む設定をする関数
VOID SetLevel();					//ゲームレベルをランダムに設定する関数

VOID CHECK_GAME_CONTINUE(int);			//ゲーム続行か終了か判定する関数
VOID CHECK_GAME_START(int);				//ゲーム開始か終了か判定する関数
BOOL CHECK_SELECT(int num);				//はいかいいえか判定する関数、はいの場合、TRUEを返す
VOID MOVE_QUESTION(GAZOU *, RECT *);	//問題の描画位置を移動させる関数

int WRITE_SAVEDATA(int);				//セーブデータを書き込む関数
int READ_SAVEDATA(SAVE[]);				//セーブデータを読み込む関数
VOID SAVEDATA_MAX(SAVE[], int);			//セーブデータの最大値を取得する関数
VOID SAVEDATA_MIN(SAVE[], int);			//セーブデータの最小値を取得する関数
int DELETE_DATA(SAVE);					//セーブデータ削除関数

VOID SWAP(int *, int*);					//値を入れ替える関数
int PARTITION(SAVE[], int, int);			//pivotを決め、pivotを境目に振り分けする関数
VOID QUICK_SORT(SAVE[], int, int);		//クイックソート関数
VOID SORT_SAVEDATA(SAVE[]);				//セーブデータを降順に並べ替える関数

VOID GET_DATEDATA();					//日付を取得する関数

BOOL CHENGE_COLOR(int,int);					//描画色を変更する関数

VOID FLASHING(int);				//点滅描画
