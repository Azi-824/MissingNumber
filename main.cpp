/*--+----1----+----2----+----3----+----4----+----5--//-+----6----+----7----+----8----+----9----+---*/
/* hinagata.cpp     																					   */

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "main.hpp"
#include "FPS.hpp"
#include <direct.h>

//*********** グローバルオブジェクト ***********
FPS *fps = new FPS(GAME_FPS_SPEED);


//########## マクロ定義 ##########
#define EASY_IMAGE		"LEVELIMAGE\\easy.png"		//難易度簡単の画像
#define NORMAL_IMAGE	"LEVELIMAGE\\normal.png"	//難易度普通の画像
#define HARD_IMAGE		"LEVELIMAGE\\hard.png"		//難易度難しいの画像

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


#define MUSIC_SE_TRUE	"SE\\true.mp3"				//正解した時の効果音
#define MUSIC_SE_FALSE	"SE\\false.mp3"				//不正解だった時の効果音
#define MUSIC_SE_CLICK	"SE\\click.mp3"				//クリックしたときの効果音
#define MUSIC_SE_CLICK2	"SE\\kettei.mp3"			//選択肢をクリックしたときの効果音
#define MUSIC_SE_COUNTDOWN	"SE\\countdown.mp3"		//カウントダウンの効果音

#define MUSIC_BGM		"BGM\\cyber42.mp3"			//BGM

#define DATA_EASY		"C:\\Missing Numbers_SAVE\\easy.dat"		//「かんたん」のセーブデータ
#define DATA_NORMAL		"C:\\Missing Numbers_SAVE\\normal.dat"		//「ふつう」のセーブデータ
#define DATA_HARD		"C:\\Missing Numbers_SAVE\\hard.dat"		//「難しい」のセーブデータ
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



//########## 列挙型 ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,	//タイトル画面
	GAME_SCENE_SETUMEI,	//説明画面
	GAME_SCENE_CHECK,	//はいかいいえの選択肢を描画する画面
	GAME_SCENE_SELECT,	//レベル選択画面
	GAME_SCENE_SET,		//設定画面
	GAME_SCENE_PLAY,	//プレイ画面
	GAME_SCENE_RESULT,	//結果表示画面
	GAME_SCENE_RANKING,	//ランキング表示画面
	GAME_SCENE_END		//エンド画面
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

//****************名前の再定義********************
typedef STRUCT_GAZOU GAZOU;
typedef STRUCT_MOUSE MOUSE;
typedef STRUCT_MUSIC MUSIC;

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
GAZOU GameLevel_Image[LEVEL_KIND];					//難易度選択用の画像
GAZOU Number_Image[NUMBER_KIND];					//数の画像
GAZOU Num_Image;									//回答用の数字の画像
GAZOU End_Image[END_KIND];							//終了の選択肢の画像
GAZOU Start_Image[START_KIND];						//スタートの画像
GAZOU Back_Image[BACKIMAGE_KIND];					//背景画像
GAZOU Select_Image[SELECT_KIND];					//選択肢の画像（はい、いいえ）
GAZOU Setumei_Image[SETUMEI_KIND];					//説明画面で使用する画像
GAZOU Setu_Image;									//説明画面の小物画像(矢印など)
GAZOU Title_Image;									//タイトルの画像
int BackImageNow = BACKIMAGE_TITLE;					//現在の背景画像の種類
int Setu_Now = BACKIMAGE_SETULEVEL;					//現在の説明段階

//領域関連
RECT Level_Image_rect[LEVEL_KIND];					//難易度画像の領域
RECT Q_rect[QUESTION_KAZU];							//問題の領域
RECT A_num[RECT_CNT];								//回答の選択肢の領域
RECT End_rect[END_KIND];							//終了の選択肢の領域
RECT Start_rect[START_KIND];						//スタートの選択肢の領域
RECT Select_rect[SELECT_KIND];						//選択肢の領域（はい、いいえ)
RECT Setu_rect;										//説明画面の小物画像(矢印など)の領域

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


//時間関連
double StartTime = 0;	//計測開始時間
double NokoriTime = 0;	//残り時間
int Time_Draw_X = 300;	//時間表示のX座標
int Time_Draw_Y = 0;	//時間表示のY座標
int LimitTime = 30;		//制限時間

//音関連
MUSIC SE_TRUE;			//正解した時に鳴る音
MUSIC SE_FALSE;			//不正解した時に鳴る音
MUSIC SE_CLICK;			//クリックしたときの効果音
MUSIC SE_KETTEI;		//選択肢をクリックしたときの効果音
MUSIC SE_COUNTDOWN;		//カウントダウンの時の効果音
MUSIC BGM;				//BGM

//セーブデータ関連
int SaveData_Easy[128] = {0};		//簡単のセーブデータを入れる配列
int SaveData_Normal[128] = { 0 };	//普通のセーブデータを入れる配列
int SaveData_Hard[128] = { 0 };		//難しいのセーブデータを入れる配列
int SaveNowCnt = 0;		//セーブデータが何個入っているかカウントする変数
int SaveMaxNum = 0;		//セーブデータの中の最大値
int SaveMinNum = 0;		//セーブデータの中の最小値

//########## プロトタイプ宣言 ##########
//LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);	//自作ウィンドウプロシージャ

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する関数

VOID MY_GAME_TITLE(VOID);			//タイトル画面の関数
VOID MY_GAME_SETUMEI(VOID);			//説明画面の関数
VOID MY_GAME_CHECK(VOID);			//確認画面の関数
VOID MY_GAME_SELECT(VOID);			//レベル選択画面の関数
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
VOID DRAW_RANKING(int,int);			//ランキングを描画する関数
VOID DRAW_WAIT_TIME(int wait);		//待ち時間を描画する関数
VOID DRAW_SETU(VOID);				//説明時に使用する小物（矢印など）を描画する関数

VOID RECT_SETTING(RECT *, int, int, int, int);	//領域を設定する関数
VOID RECT_RESET(RECT *);						//領域を初期化する関数
BOOL MY_CHECK_RECT_ATARI(RECT, RECT);			//領域と領域の当たり判定をする関数

VOID GET_MOUSE_STATE(RECT *,int);	//マウスの情報を取得する関数
VOID RESET_MOUSE_DATE(VOID);		//マウスの情報をリセットする関数
BOOL CHECK_RECT_ATARI(RECT, MOUSE);	//マウスが画像の領域内かどうか判断する関数

VOID SET_SELECT_IMAGE(VOID);		//はいといいえの画像描画の設定をする関数
VOID SET_START_IMAGE(VOID);			//スタート画面の設定をする関数
VOID SET_ANSER_NUM(VOID);			//回答用の数字の設定をする関数
VOID SET_GAME_LEVEL(int);			//ゲームレベルを設定する関数
VOID GET_PLAYER_ANSER(int);			//プレイヤーの回答を取得する関数
VOID SET_END_IMAGE(VOID);			//終了の選択肢の画像の設定をする関数
VOID SET_END_SETU(VOID);			//説明で使用する小物（矢印など）の設定をする関数
BOOL MY_MUSIC_LOAD(MUSIC *, const char *);	//音を読み込む設定をする関数

VOID CHECK_GAME_CONTINUE(int);			//ゲーム続行か終了か判定する関数
VOID CHECK_GAME_START(int);				//ゲーム開始か終了か判定する関数
BOOL CHECK_SELECT(int num);				//はいかいいえか判定する関数、はいの場合、TRUEを返す
VOID MOVE_QUESTION(GAZOU *, RECT *);	//問題の描画位置を移動させる関数

int WRITE_SAVEDATA(int);				//セーブデータを書き込む関数
int READ_SAVEDATA(int []);				//セーブデータを読み込む関数
VOID SAVEDATA_MAX(int [],int);			//セーブデータの最大値を取得する関数
VOID SAVEDATA_MIN(int [],int);			//セーブデータの最小値を取得する関数
int DELETE_DATA(int);					//セーブデータ削除関数

VOID SWAP(int *, int*);					//値を入れ替える関数
int PARTITION(int[], int, int);			//pivotを決め、pivotを境目に振り分けする関数
VOID QUICK_SORT(int[], int, int);		//クイックソート関数
VOID SORT_SAVEDATA(int[]);				//セーブデータを降順に並べ替える関数

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//タイトルバーあり

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//タイトルの文字

	SetWindowIconID(333);										//ウインドウのアイコン変更

	if (DxLib_Init() == -1) { return -1; }						//ＤＸライブラリ初期化処理

	SetDrawScreen(DX_SCREEN_BACK);								//Draw系関数は裏画面に描画

	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 画像の読み込み ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	//難易度画像の読み込み
	if (MY_GAZOU_LOAD(&GameLevel_Image[0], 0, 0, EASY_IMAGE) == FALSE) { MessageBox(NULL, EASY_IMAGE, "NotFound", MB_OK); return -1; }	//難易度画像を読み込む
	if (MY_GAZOU_LOAD(&GameLevel_Image[1], 0, 0, NORMAL_IMAGE) == FALSE) { MessageBox(NULL, NORMAL_IMAGE, "NotFound", MB_OK); return -1; }	//難易度画像を読み込む
	if (MY_GAZOU_LOAD(&GameLevel_Image[2], 0, 0, HARD_IMAGE) == FALSE) { MessageBox(NULL, HARD_IMAGE, "NotFound", MB_OK); return -1; }	//難易度画像を読み込む

	//問題用の数字画像の読み込み
	if (MY_GAZOU_LOAD(&Number_Image[0], 0, 0, ZERO_IMAGE) == FALSE) { MessageBox(NULL, ZERO_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む
	if (MY_GAZOU_LOAD(&Number_Image[1], 0, 0, ONE_IMAGE) == FALSE) { MessageBox(NULL, ONE_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む
	if (MY_GAZOU_LOAD(&Number_Image[2], 0, 0, TWO_IMAGE) == FALSE) { MessageBox(NULL, TWO_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む
	if (MY_GAZOU_LOAD(&Number_Image[3], 0, 0, THREE_IMAGE) == FALSE) { MessageBox(NULL, THREE_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む
	if (MY_GAZOU_LOAD(&Number_Image[4], 0, 0, FOUR_IMAGE) == FALSE) { MessageBox(NULL, FOUR_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む
	if (MY_GAZOU_LOAD(&Number_Image[5], 0, 0, FIVE_IMAGE) == FALSE) { MessageBox(NULL, FIVE_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む
	if (MY_GAZOU_LOAD(&Number_Image[6], 0, 0, SIX_IMAGE) == FALSE) { MessageBox(NULL, SIX_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む
	if (MY_GAZOU_LOAD(&Number_Image[7], 0, 0, SEVEN_IMAGE) == FALSE) { MessageBox(NULL, SEVEN_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む
	if (MY_GAZOU_LOAD(&Number_Image[8], 0, 0, EIGHT_IMAGE) == FALSE) { MessageBox(NULL, EIGHT_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む
	if (MY_GAZOU_LOAD(&Number_Image[9], 0, 0, NINE_IMAGE) == FALSE) { MessageBox(NULL, NINE_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む

	//回答用の数字画像の読み込み
	if (MY_GAZOU_LOAD(&Num_Image, 0, 0, NUMBER_IMAGE) == FALSE) { MessageBox(NULL, NUMBER_IMAGE, "NotFound", MB_OK); return -1; }	//数の画像を読み込む

	//はいといいえの画像の読み込み
	if (MY_GAZOU_LOAD(&Select_Image[0], 0, 0, YES_IMAGE) == FALSE) { MessageBox(NULL, YES_IMAGE, "NotFound", MB_OK); return -1; }	//はいの選択肢画像を読み込む
	if (MY_GAZOU_LOAD(&Select_Image[1], 0, 0, NO_IMAGE) == FALSE) { MessageBox(NULL, NO_IMAGE, "NotFound", MB_OK); return -1; }	//いいえの選択肢画像を読み込む

	//終了の選択肢画像の読み込み
	if (MY_GAZOU_LOAD(&End_Image[0], 0, 0, CONTINUE_IMAGE) == FALSE) { MessageBox(NULL, CONTINUE_IMAGE, "NotFound", MB_OK); return -1; }	//終了の選択肢画像を読み込む
	if (MY_GAZOU_LOAD(&End_Image[1], 0, 0, END_IMAGE) == FALSE) { MessageBox(NULL, END_IMAGE, "NotFound", MB_OK); return -1; }	//終了の選択肢画像を読み込む
	
	//開始の選択肢画像の読み込み
	if (MY_GAZOU_LOAD(&Start_Image[0], 0, 0, START_IMAGE) == FALSE) { MessageBox(NULL, START_IMAGE, "NotFound", MB_OK); return -1; }	//開始の画像を読み込む
	if (MY_GAZOU_LOAD(&Start_Image[1], 0, 0, SETUMEI_IMAGE) == FALSE) { MessageBox(NULL, SETUMEI_IMAGE, "NotFound", MB_OK); return -1; }	//開始の画像を読み込む
	if (MY_GAZOU_LOAD(&Start_Image[2], 0, 0, END_IMAGE2) == FALSE) { MessageBox(NULL, END_IMAGE2, "NotFound", MB_OK); return -1; }	//開始の画像を読み込む
	//タイトル画像の読み込み
	if (MY_GAZOU_LOAD(&Title_Image, 0, 0, TITLE_IMAGE) == FALSE) { MessageBox(NULL, TITLE_IMAGE, "NotFound", MB_OK); return -1; }	//開始の画像を読み込む

	//背景画像の読み込み
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_TITLE], 0, 0, TITLE_BACKIMAGE) == FALSE) { MessageBox(NULL, TITLE_BACKIMAGE, "NotFound", MB_OK); return -1; }		//タイトル画面の背景画像を読み込む
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_SELECT], 0, 0, SELECT_BACKIMAGE) == FALSE) { MessageBox(NULL, SELECT_BACKIMAGE, "NotFound", MB_OK); return -1; }	//セレクト画面の背景画像を読み込む
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_PLAY], 0, 0, PLAY_BACKIMAGE) == FALSE) { MessageBox(NULL, PLAY_BACKIMAGE, "NotFound", MB_OK); return -1; }			//プレイ画面の背景画像を読み込む
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_RESULT], 0, 0, RESULT_BACKIMAGE) == FALSE) { MessageBox(NULL, RESULT_BACKIMAGE, "NotFound", MB_OK); return -1; }	//リザルト画面の背景画像を読み込む
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_END], 0, 0, END_BACKIMAGE) == FALSE) { MessageBox(NULL, END_BACKIMAGE, "NotFound", MB_OK); return -1; }				//エンド画面の背景画像を読み込む

	//説明画面で使用する画像の読み込み
	if (MY_GAZOU_LOAD(&Setumei_Image[0], 0, 0, SETUMEI_LEVLEIMAGE) == FALSE) { MessageBox(NULL, SETUMEI_LEVLEIMAGE, "NotFound", MB_OK); return -1; }	//終了の選択肢画像を読み込む
	if (MY_GAZOU_LOAD(&Setumei_Image[1], 0, 0, SETUMEI_PLAYIMAGE) == FALSE) { MessageBox(NULL, SETUMEI_PLAYIMAGE, "NotFound", MB_OK); return -1; }	//終了の選択肢画像を読み込む
	if (MY_GAZOU_LOAD(&Setu_Image, 0, 0, SETUMEI_NEXT) == FALSE) { MessageBox(NULL, SETUMEI_NEXT, "NotFound", MB_OK); return -1; }	//終了の選択肢画像を読み込む


	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 画像の読み込み ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲


	//音を読み込む
	MY_MUSIC_LOAD(&SE_TRUE, MUSIC_SE_TRUE);			//正解した時の効果音を読み込む
	MY_MUSIC_LOAD(&SE_FALSE, MUSIC_SE_FALSE);		//不正解だった時の効果音を読み込む
	MY_MUSIC_LOAD(&SE_CLICK, MUSIC_SE_CLICK);		//クリックしたときの効果音を読み込む
	MY_MUSIC_LOAD(&SE_KETTEI, MUSIC_SE_CLICK2);		//選択肢をクリックしたときの効果音を読み込む
	MY_MUSIC_LOAD(&SE_COUNTDOWN, MUSIC_SE_COUNTDOWN);//カウントダウンの時の効果音を読み込む
	MY_MUSIC_LOAD(&BGM, MUSIC_BGM);					//BGMを読み込む

	//無限ループ
	while (TRUE)
	{
		if (GameEnd_flg == TRUE)	//終了ではいを押したとき
			break;					//無限ループを抜けて、ゲーム終了

		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		MY_ALL_KEYDOWN_UPDATE();				//キーの状態を取得

		//STATE_DRAW();							//情報の描画

		fps->Update();		//FPSの処理[更新]

		//シーン選択
		switch (GameSceneNow)
		{
		case (int)GAME_SCENE_TITLE:	//タイトル画面の処理ここから

			MY_GAME_TITLE();	//タイトル画面の処理

			break;	//タイトル画面の処理ここまで

		case (int)GAME_SCENE_SETUMEI:	//説明画面の処理ここから

			MY_GAME_SETUMEI();	//説明画面の処理

			break;	//説明画面の処理ここまで

		case (int)GAME_SCENE_CHECK:	//確認画面の処理ここから

			MY_GAME_CHECK();	//確認画面の処理

			break;	//確認画面の処理ここまで

		case (int)GAME_SCENE_SELECT:	//レベル選択画面の処理ここから

			MY_GAME_SELECT();	//レベル選択画面の処理ここから

			break; //レベル選択画面の処理ここまで

		case (int)GAME_SCENE_SET://設定画面の処理ここから

			MY_GAME_SET();		//設定画面の処理

			break;	//設定画面の処理ここまで

		case (int)GAME_SCENE_PLAY:	//プレイ画面の処理ここから

			MY_GAME_PLAY();		//プレイ画面の処理

			break;	//プレイ画面の処理ここまで

		case (int)GAME_SCENE_RESULT:	//リザルト画面の処理ここから

			MY_GAME_RESULT();	//リザルト画面の処理

			break;	//リザルト画面の処理ここまで

		case (int)GAME_SCENE_RANKING:	//ランキング画面の処理ここから

			MY_GAME_RANKING();	//ランキング画面の処理

			break;	//ランキング画面の処理ここまで

		default:

			break;

		}

		ScreenFlip();					//モニタのリフレッシュレートの速さで裏画面を再描画

		fps->Wait();					//FPSの処理(待つ)
	}

	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 画像のハンドルの削除 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	for (int cnt = 0; cnt < LEVEL_KIND; cnt++)
	{
		DeleteGraph(GameLevel_Image[cnt].Handle);	//難易度画像のハンドルを削除
	}

	for (int cnt = 0; cnt < NUMBER_KIND; cnt++)
	{
		DeleteGraph(Number_Image[cnt].Handle);		//数の画像のハンドルを削除
	}

	for (int cnt = 0; cnt < NUMBER_KAZU; cnt++)
	{
		DeleteGraph(Num_Image.Handle);	//回答用の数の画像のハンドルを削除
	}

	for (int cnt = 0; cnt < SELECT_KIND; cnt++)
	{
		DeleteGraph(Select_Image[cnt].Handle);	//はいといいえの選択肢画像のハンドルを削除
	}

	for (int cnt = 0; cnt < END_KIND; cnt++)
	{
		DeleteGraph(End_Image[cnt].Handle);	//終了の選択肢画像のハンドルを削除
	}

	for (int cnt = 0; cnt < START_KIND; cnt++)
	{
		DeleteGraph(Start_Image[cnt].Handle);	//開始の選択肢画像のハンドルを削除
	}

	for (int cnt = 0; cnt < SETUMEI_KIND;cnt++)
	{
		DeleteGraph(Setumei_Image[cnt].Handle);	//説明画面で使用する画像のハンドルを削除
	}

	for (int cnt = 0; cnt < BACKIMAGE_KIND; cnt++)
	{
		DeleteGraph(Back_Image[cnt].Handle);	//背景画像のハンドルを削除
	}

	DeleteGraph(Setu_Image.Handle);		//説明画面で使用する小物の画像のハンドルを削除
	DeleteGraph(Title_Image.Handle);	//タイトルの選択肢画像のハンドルを削除
	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 画像のハンドルの削除 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲


	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 音のハンドルの削除 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	DeleteMusicMem(SE_TRUE.Handle);		//音のハンドルを削除
	DeleteMusicMem(SE_FALSE.Handle);	//音のハンドルを削除
	DeleteMusicMem(SE_CLICK.Handle);	//音のハンドルを削除
	DeleteMusicMem(SE_KETTEI.Handle);	//音のハンドルを削除
	DeleteMusicMem(SE_COUNTDOWN.Handle);//音のハンドルを削除
	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 音のハンドルの削除 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

	delete fps;				//fpsを破棄

	DxLib_End();		//ＤＸライブラリ使用の終了処理

	return 0;
}


//########## キーの入力状態を更新する関数 ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];			//一時的に、現在のキーの入力状態を格納する

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//########## タイトル画面の関数 ##########
VOID MY_GAME_TITLE(VOID)
{
	MY_INIT();		//初期化関数

	

	if (AllKeyState[KEY_INPUT_DELETE] != 0)	//デリートキーが押されたていた時
	{
		Delete_flg = TRUE;
		GameSceneNow = (int)GAME_SCENE_CHECK;	//シーンを確認画面にする
	}

	DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//背景の描画

	GET_MOUSE_STATE(&Start_rect[0], START_KIND);	//マウスの情報を取得

	SET_START_IMAGE();		//スタートの選択肢の設定

	DRAW_START();			//スタートの選択肢の描画

	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 文字の描画 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	int Font = CREATE_FONT(36);	//フォントハンドル作成
	char Str_Ranking[128] = { "※Deleteキーを押すとランキング情報をリセットできます" };

	DrawStringToHandle(0,
		0,
		&Str_Ranking[0],
		GetColor(255, 0, 0),
		Font);

	DeleteFontToHandle(Font);	//フォントハンドル削除
	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 文字の描画 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

	//▼▼▼▼▼▼▼▼▼▼ タイトルの描画 ▼▼▼▼▼▼▼▼▼▼
	Title_Image.X = GAME_WIDTH / 2 - Title_Image.C_Width;		//描画位置調整
	Title_Image.Y = GAME_HEIGHT / 2 - Title_Image.C_Height;		//描画位置調整

	DrawGraph(Title_Image.X, Title_Image.Y, Title_Image.Handle, TRUE);	//タイトル画像の描画

	//▲▲▲▲▲▲▲▲▲▲ タイトルの描画 ▲▲▲▲▲▲▲▲▲▲

	//領域内でクリックされた時
	if (Mouse_Date.Mouse_hover_flg == TRUE &&
		Mouse_Date.Mouse_LeftClick_flg == TRUE)
	{
		//マウスがどの画像をクリックしたか判定
		CHECK_GAME_START(Mouse_Date.Mouse_Click_Num);
	}

	return;
}

//########## 説明画面の関数 ############
VOID MY_GAME_SETUMEI(VOID)
{

	//BGMが流れていないとき
	if (CheckSoundMem(BGM.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 30 / 100, BGM.Handle);	//BGMの音量を50％にする
		PlaySoundMem(BGM.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
	}

	GET_MOUSE_STATE(&Setu_rect, 1);	//マウスの情報を取得

	DRAW_BACKIMAGE(&Setumei_Image[Setu_Now]);	//レベル説明の描画

	if (Setu_Now == BACKIMAGE_SETULEVEL)	
	{
		//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 文字の描画 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		SET_END_SETU();		//説明で使用する小物（矢印など）の設定

		DRAW_SETU();	//説明で使用する小物（矢印など）の描画
		//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 文字の描画 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲


		if (Mouse_Date.Mouse_hover_flg == TRUE && 
			Mouse_Date.Mouse_LeftClick_flg == TRUE)	//レベル説明段階でクリックされたら、
		{
			Setu_Now = BACKIMAGE_SETUPLAY;	//説明段階をプレイ画面に変更
		}
	} 
	else if (Setu_Now == BACKIMAGE_SETUPLAY)
		{
			
		//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 文字の描画 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		SET_END_SETU();		//説明で使用する小物（矢印など）の設定

		DRAW_SETU();	//説明で使用する小物（矢印など）の描画
		//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 文字の描画 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
			
			if (Mouse_Date.Mouse_hover_flg == TRUE && 
				Mouse_Date.Mouse_LeftClick_flg == TRUE)	//プレイ説明段階でクリックされたら、
			{
				GameSceneNow = GAME_SCENE_CHECK;	//確認画面に変更
			}
		}

}

//########## 確認画面の関数 ################
VOID MY_GAME_CHECK(VOID)
{
	if (Setumei_flg == TRUE)	//説明フラグがたっていたら
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 40);     //背景を暗くする
		DRAW_BACKIMAGE(&Setumei_Image[Setu_Now]);	//背景の描画
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);     //ブレンドモードをリセットする。
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 40);     //背景を暗くする
		DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//背景の描画
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);     //ブレンドモードをリセットする。
	}
	
	//終わるを選んだ時の処理
	GET_MOUSE_STATE(&Select_rect[0], SELECT_KIND);	//マウスの情報を取得

	SET_SELECT_IMAGE();		//はいといいえの画像の設定

	DRAW_SELECT();			//はいといいえの画像の描画

	//文字描画
	if (Delete_flg == TRUE)	//データ削除フラグが立っていたら、
	{
		int Font = CREATE_FONT(60);	//フォントハンドル作成
		char Str_Time[128] = { 0 };

		sprintf(&Str_Time[0], "データを削除してよろしいですか？\n※全ての難易度のデータが消えます");

		int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Time[0]);	//デフォルトのフォントの横幅を取得

		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			80,
			&Str_Time[0],
			GetColor(255, 0, 0),
			Font);	//確認文字の描画

		DeleteFontToHandle(Font);	//フォントハンドル削除

	}
	else if (End_flg == TRUE) 
	{
		int Font = CREATE_FONT(64);	//フォントハンドル作成
		char Str_Time[128] = { 0 };

		sprintf(&Str_Time[0], "ゲームを終了しますか？");

		int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Time[0]);	//デフォルトのフォントの横幅を取得

		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			150,
			&Str_Time[0],
			GetColor(255, 255, 255),
			Font);	//確認文字の描画

		DeleteFontToHandle(Font);	//フォントハンドル削除

	}
	else if (Setumei_flg == TRUE)	//説明フラグが立っていたら
	{
		int Font = CREATE_FONT(60);	//フォントハンドル作成
		char Str_Time[128] = { 0 };

		sprintf(&Str_Time[0], "説明を終了してもよろしいですか？");

		int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Time[0]);	//デフォルトのフォントの横幅を取得

		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			150,
			&Str_Time[0],
			GetColor(255, 0, 0),
			Font);	//確認文字の描画

		DeleteFontToHandle(Font);	//フォントハンドル削除
	}

	//領域内でクリックされた時
	if (Mouse_Date.Mouse_hover_flg == TRUE &&
		Mouse_Date.Mouse_LeftClick_flg == TRUE)
	{
		//マウスがどの画像をクリックしたか判定
		if (CHECK_SELECT(Mouse_Date.Mouse_Click_Num) == TRUE)	//はいをクリックした場合
		{
			Yes_flg = TRUE;	//はいのフラグ
		}
		else
		{
			No_flg = TRUE;		//いいえのフラグ
		}
	}

	//はい、かいいえ、かで処理を変える
	if (Yes_flg == TRUE)
	{
		//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ データ削除処理 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		if (Delete_flg == TRUE)	//セーブデータ削除フラグが立っていたら、
		{
			//セーブデータ削除の処理
			DELETE_DATA(SaveData_Easy[0]);		//簡単、のデータ削除
			DELETE_DATA(SaveData_Normal[0]);	//普通、のデータ削除
			DELETE_DATA(SaveData_Hard[0]);		//難しい、のデータ削除

			Delete_flg = FALSE;		//削除フラグをリセット
			Yes_flg = FALSE;

			GameSceneNow = (int)GAME_SCENE_TITLE;//ゲームシーンをタイトル画面に変える

		}
		//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ データ削除処理 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
		else if (Setumei_flg == TRUE)	//説明フラグが立っていたら
		{
			Yes_flg = FALSE;
			GameSceneNow = (int)GAME_SCENE_TITLE;//ゲームシーンをタイトル画面に変える
		}
		else
		{
			GameEnd_flg = TRUE;	//ゲーム終了フラグを立てる
			Yes_flg = FALSE;
		}

	}
	else if (No_flg == TRUE)
	{
	 if (Setumei_flg == TRUE)	//説明フラグが立っていたら、
		{
			Setu_Now = BACKIMAGE_SETULEVEL;//説明段階をレベルにする
			No_flg = FALSE;
			GameSceneNow = (int)GAME_SCENE_SETUMEI;	//説明画面にする
		}
	 else
	 {
		 GameSceneNow = (int)GAME_SCENE_TITLE;//ゲームシーンをタイトル画面に変える
		 No_flg = FALSE;
	 }

	}

	return;
}

//########## レベル選択画面の関数 ##########
VOID MY_GAME_SELECT(VOID)
{

	BackImageNow = BACKIMAGE_SELECT;	//背景画像の種類をセレクト画面に変更

	DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//背景の描画

	//画像の領域を設定
	for (int cnt = 0; cnt < LEVEL_KIND; cnt++)
	{
		RECT_SETTING(&Level_Image_rect[cnt],
			GameLevel_Image[cnt].X,
			GameLevel_Image[cnt].Y,
			GameLevel_Image[cnt].Width,
			GameLevel_Image[cnt].Height);
	}

	GET_MOUSE_STATE(&Level_Image_rect[0], LEVEL_KIND);	//マウスの情報を取得

	GAMELEVEL_IMAGE_DRAW();		//難易度画像の描画

	//▼▼▼▼▼▼▼▼▼▼ タイトルの描画 ▼▼▼▼▼▼▼▼▼▼
	char StrGameTitle[1][128] = { "難易度を選んでね" };
	char StrFontTitle[128] = { "MS ゴシック" };	//大文字半角「MS」、半角「空白」、全角「ゴシック」

	MY_DRAW_STRING_CENTER_CENTER(&StrGameTitle[0], 1, StrFontTitle, 64);		//画面中央に描画
	//▲▲▲▲▲▲▲▲▲▲ タイトルの描画 ▲▲▲▲▲▲▲▲▲▲


	//領域内でクリックされた時
	if (Mouse_Date.Mouse_hover_flg == TRUE &&
		Mouse_Date.Mouse_LeftClick_flg == TRUE)
	{
		//マウスがどの画像をクリックしたか判定
		SET_GAME_LEVEL(Mouse_Date.Mouse_Click_Num);
	}

}

//########## 設定画面の関数 ############
VOID MY_GAME_SET(VOID)
{
	//問題の初期化
	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{
		Number_Image[cnt].Num_flg = FALSE;	//問題が入っているかどうかのフラグを初期化
		Number_Image[cnt].Positon_flg = FALSE;
		Number_Image[cnt].X = 0;
		Number_Image[cnt].Y = 0;
	}

	RESET_MOUSE_DATE();	//マウス情報リセット

	MY_CREATE_QUESTION();	//問題を生成

	True_flg = FALSE;	//正解フラグをリセット
	False_flg = FALSE;	//不正解フラグをリセット

	if (Q_Sum == 0)	//最初の処理の時だけ、計測開始時間を設定
	{
		StartTime = GetNowCount();	//計測開始
	}

	NokoriTime = (LimitTime - (GetNowCount() - StartTime) / 1000);	//残り時間の更新

	SET_ANSER_NUM();		//回答用の数字の設定をする関数

	BackImageNow = BACKIMAGE_PLAY;	//背景画像の種類をプレイ画面に変更

	if (First_flg == FALSE)	//最初はゲーム開始のカウントダウンを描画するため、
	{
		DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//背景の描画

		DRAW_QUESTION();		//問題を描画

		DRAW_TIME();			//残り時間の描画

		DRAW_ANSER_NUM();		//回答用の選択肢を描画
	}

	GameSceneNow = (int)GAME_SCENE_PLAY;	//プレイ画面にする

}

//########## プレイ画面の関数 ##########
VOID MY_GAME_PLAY(VOID)
{
	DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//背景の描画

	DRAW_ANSER_NUM();		//回答用の選択肢を描画

	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ ゲーム開始のカウントダウン（3秒）を行う処理 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	if (First_flg == TRUE)
	{

		if (CountDownStart_flg == FALSE)	//カウントダウンの音を鳴らす
		{
			CountDownStart_flg = TRUE;	//カウントダウンスタート
			ChangeVolumeSoundMem(255 * 80 / 100, SE_COUNTDOWN.Handle);	//SEの音量を50％にする
			PlaySoundMem(SE_COUNTDOWN.Handle, DX_PLAYTYPE_BACK);		//カウントダウンの音を鳴らす
		}

		LimitTime = 3;		//カウントダウンの時間を設定
		NokoriTime = (LimitTime - (GetNowCount() - StartTime) / 1000);	//残り時間の更新

		DRAW_WAIT_TIME(NokoriTime);	//時間の描画

			//3秒たったら、ゲームスタート
			if (NokoriTime <= 0)
			{
				StartTime = GetNowCount();	//スタート時間をリセット
				LimitTime = GAMETIME;				//制限時間をゲームの時間に設定
				First_flg = FALSE;			//最初のフラグ
			}
	}
	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ ゲーム開始のカウントダウン（3秒）を行う処理 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
	
	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ ゲーム画面の処理 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	else
	{
		NokoriTime = (LimitTime - (GetNowCount() - StartTime) / 1000);	//残り時間の更新

	//30秒たったら、リザルト画面に切り替える
		if (NokoriTime <= 0)
		{
			GameSceneNow = (int)GAME_SCENE_RESULT;
		}

		DRAW_QUESTION();		//問題を描画

		DRAW_TIME();			//残り時間の描画

		GET_MOUSE_STATE(&A_num[0], RECT_CNT);	//マウスの情報を取得

		//領域内をクリックされた時
		if (Mouse_Date.Mouse_LeftClick_flg == TRUE &&
			Mouse_Date.Mouse_hover_flg == TRUE)
		{
			GET_PLAYER_ANSER(Mouse_Date.Mouse_Click_Num);	//プレイヤーの回答が正解か不正解か判定

		}
	}
	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ ゲーム画面の処理 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
	
	return;
	
}

//########## リザルト画面の関数 #########
VOID MY_GAME_RESULT(VOID)
{
	BackImageNow = BACKIMAGE_RESULT;	//背景画像の種類をリザルト画面に変更

	DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//背景の描画

	DRAW_RESULET();//結果の描画

	GET_MOUSE_STATE(&End_rect[0], END_KIND);	//マウスの情報を取得

	if (Write_flg == FALSE)	//セーブデータの書き込みが行われていなかったら
	{
		WRITE_SAVEDATA(True_Kazu);	//セーブデータの書き込み
		Write_flg = TRUE;			//書き込みフラグを立てる
		WaitTime_flg = TRUE;		//時間を待つためのフラグを立てる
		StartTime = GetNowCount();	//計測開始
	}

	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 3秒たったら、自動的にランキング画面に変更する処理 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	if (WaitTime_flg == TRUE)
	{
		LimitTime = 3;		//カウントダウンの時間を設定
		NokoriTime = (LimitTime - (GetNowCount() - StartTime) / 1000);	//残り時間の更新

		DRAW_WAIT_TIME(NokoriTime);	//時間の描画

		//3秒たったら、ランキング画面に変更
		if (NokoriTime <= 0)
		{
			StartTime = GetNowCount();	//スタート時間をリセット
			WaitTime_flg = FALSE;		//時間を待つためのフラグ
			GameSceneNow = (int)GAME_SCENE_RANKING;	//ゲームシーンをランキング画面に
		}
	}
	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 3秒たったら、自動的にランキング画面に変更する処理 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

	return;
}

//########## ランキング画面の関数 ########
VOID MY_GAME_RANKING(VOID)
{
	RESET_MOUSE_DATE();	//マウス情報のリセット

	GET_MOUSE_STATE(&End_rect[0], END_KIND);	//マウスの情報を取得

	DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//背景の描画

	//セーブデータをソートして読み込む
	if (Sort_flg == FALSE)
	{
		//難易度ごとに処理を分ける
		switch (Game_Level_Now)
		{
		case (int)GAME_LEVEL_EASY:	//難易度、簡単のとき

			SORT_SAVEDATA(SaveData_Easy);	//「簡単」のセーブデータを読み込んで、降順に並び替える
			Sort_flg = TRUE;				//ソートフラグを立てる

			break;

		case (int)GAME_LEVEL_NORMAL: //難易度、普通のとき

			SORT_SAVEDATA(SaveData_Normal);	//「普通」のセーブデータを読み込んで、降順に並び替える
			Sort_flg = TRUE;				//ソートフラグを立てる

			break;

		case (int)GAME_LEVEL_HARD:	//難易度、難しいのとき

			SORT_SAVEDATA(SaveData_Hard);	//「難しい」のセーブデータを読み込んで、降順に並び替える
			Sort_flg = TRUE;				//ソートフラグを立てる

			break;

		default:
			break;

		}

	}

	//"ランキング"の文字の描画
	int Font = CREATE_FONT(100);	//フォントハンドル作成
	char Str_Ranking[128] = { "ランキング" };

	int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Ranking[0]);	//デフォルトのフォントの横幅を取得

	DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
		0,
		&Str_Ranking[0],
		GetColor(255, 0, 0),
		Font);	//ランキングの描画

	DeleteFontToHandle(Font);	//フォントハンドル削除



	//難易度ごとに処理を分ける
	for (int cnt = 0; cnt < RANKING_NUM; cnt++)
	{

		switch (Game_Level_Now)
		{
		case (int)GAME_LEVEL_EASY:	//難易度、簡単のとき

			DRAW_RANKING(SaveData_Easy[cnt],cnt);	//セーブデータの描画

			break;

		case (int)GAME_LEVEL_NORMAL: //難易度、普通のとき

			DRAW_RANKING(SaveData_Normal[cnt], cnt);	//セーブデータの描画

			break;

		case (int)GAME_LEVEL_HARD:	//難易度、難しいのとき

			DRAW_RANKING(SaveData_Hard[cnt], cnt);	//セーブデータの描画

			break;

		default:
			break;

		}

	}

	SET_END_IMAGE();	//終了の選択肢の設定

	DRAW_END_IMAGE();	//終了の選択肢の描画

	//領域内でクリックされた時
	if (Mouse_Date.Mouse_hover_flg == TRUE &&
		Mouse_Date.Mouse_LeftClick_flg == TRUE)
	{
		//ゲーム終了か、ゲーム続行か判定
		CHECK_GAME_CONTINUE(Mouse_Date.Mouse_Click_Num);
	}

}

//########## 文字をデフォルトフォントに設定する関数 ##########
//引　数：BOOL：アンチエイリアスをする
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL anti)
{
	//デフォルトは以下のフォントサイズであると、設定する
	ChangeFont("MS ゴシック", DX_CHARSET_DEFAULT);
	SetFontSize(16);

	if (anti)
	{
		ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	}
	return;
}
//########## フォントハンドルを作成する関数 #############
int CREATE_FONT(int size)
{
	int Font;
	Font = CreateFontToHandle("ＭＳ ゴシック", size, FONT_BOLD, DX_FONTTYPE_ANTIALIASING_EDGE);
	return Font;
}

//########## 画面中央に文字を描画する関数 ##########
//引　数：char [][]：表示する文字列の先頭アドレス
//引　数：int　 　 ：表示する行数
//引　数：char *　 ：フォントの名前
//引　数：int　 　 ：文字の大きさ
//戻り値：なし
VOID MY_DRAW_STRING_CENTER_CENTER(char str[][128], int row, char *fontname, int size)
{
	ChangeFont(fontname, DX_CHARSET_DEFAULT);		//デフォルトのフォントを変更する
	SetFontSize(size);								//デフォルトのフォントサイズを変える
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);	//フォントをきれいにみせる

	int StrHeightSum = 0;
	for (int sum = 0; sum < row; sum++)	//行全体の高さを集計
	{
		StrHeightSum += GetFontSize();	//デフォルトのフォントの高さを取得
	}

	for (int rCnt = 0; rCnt < row; rCnt++)	//フォントを描画
	{
		int StrWidth = GetDrawFormatStringWidth(&str[rCnt][0]);	//デフォルトのフォントの横幅を取得
		int StrHeight = GetFontSize();

		DrawFormatString(
			GAME_WIDTH / 2 - StrWidth / 2,
			GAME_HEIGHT / 2 - StrHeightSum + StrHeight * rCnt,	//画面の中心　-　行全体の文字の高さ　+　１行の高さ
			GetColor(255, 0, 0), &str[rCnt][0]);			//デフォルトのフォントで描画
	}

	MY_DRAW_SET_DEFAULT_FONT(TRUE);	//デフォルトフォントに設定する

	return;

}

//########## 画像を読み込む設定をする関数 ##########

//引　数：画像構造体　：設定する画像構造体の変数
//引　数：int　：画像の横の位置
//引　数：int　：画像の縦の位置
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_GAZOU_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);					//ファイルパスをコピー
	g->Handle = LoadGraph(g->FilePath);				//画像をメモリに読み込み、ハンドルを取得

	if (g->Handle == -1) { return FALSE; }			//画像読み込みエラー

	GetGraphSize(g->Handle, &g->Width, &g->Height);	//画像サイズを取得
	g->X = x;
	g->Y = y;
	g->C_Width = g->Width / 2;						//画像の横サイズの中心を取得
	g->C_Height = g->Height / 2;					//画像の縦サイズの中心を取得

	return TRUE;

}

//########## 問題を生成する関数 ##################
VOID MY_CREATE_QUESTION(VOID)
{

	int num = 0;			//生成した乱数を入れる用の変数
	
	
	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{

		Number_Image[cnt].Direction = GetRand(DIRECTION_KIND - 1);	//移動方向を乱数で決める

		//▼▼▼▼▼▼▼▼▼ 問題の座標を生成 ▼▼▼▼▼▼▼▼▼
		num = GetRand(Q_ERIA_WIDTH);		//問題を描画するX座標を画面内の値で生成

		if ((num + FONT_SIZE) > 150 &&
			num < (Q_ERIA_WIDTH - Number_Image[cnt].Width))
		{
			Number_Image[cnt].X = num;		//問題のx座標に代入
		}
		else
		{
			cnt--;
			continue;
		}

		num = GetRand(Q_ERIA_HEIGHT);		//問題を描画するY座標を画面内の値で生成

		if (num > Time_Draw_Y + 130 &&
			num < (Q_ERIA_HEIGHT - Number_Image[cnt].Height))
		{
			Number_Image[cnt].Y= num;		//問題のy座標に代入
		}
		else
		{
			cnt--;
			continue;
		}
		//▲▲▲▲▲▲▲▲▲▲ 問題の座標を生成 ▲▲▲▲▲▲▲▲▲▲


		//問題の領域を設定
		RECT_SETTING(&Q_rect[cnt],
			Number_Image[cnt].X,
			Number_Image[cnt].Y,
			Number_Image[cnt].Width,
			Number_Image[cnt].Height);

		Number_Image[cnt].Positon_flg = TRUE;		//座標設定完了のフラグ

		//▼▼▼▼▼▼▼▼▼▼ 問題の領域が被っているか判定 ▼▼▼▼▼▼▼▼▼▼
		for (int cnt_r = 0;cnt_r < cnt; cnt_r++)
		{
			if (MY_CHECK_RECT_ATARI(Q_rect[cnt], Q_rect[cnt_r]) == TRUE)		//領域が被っていたら
			{
				cnt--;											//cntの値をマイナスして、座標を設定しなおす
				Number_Image[cnt + cnt_r].Positon_flg = FALSE;		//座標設定のフラグをFALSEにする
				break;
			}
		}
		//▲▲▲▲▲▲▲▲▲▲▲ 問題の領域が被っているか判定 ▲▲▲▲▲▲▲▲▲▲▲▲

	}
	



	//▼▼▼▼▼▼▼▼▼ 問題を生成 ▼▼▼▼▼▼▼▼▼
	for (int cnt = 0; cnt < QUESTION_KAZU - 1;)
	{

		num = GetRand(QUESTION_KAZU - 1);		//0～9までの間で乱数を生成

		if (Number_Image[num].Num_flg != TRUE)		//問題用の配列に乱数で生成した数字が入っていなかった場合
		{
			Number_Image[num].Num_flg = TRUE;		//フラグを立てる
			cnt++;								//cntをインクリメント
		}
		
	}
	//▲▲▲▲▲▲▲▲▲▲ 問題を生成 ▲▲▲▲▲▲▲▲▲▲
}

//**********初期化関数**************
BOOL MY_INIT(VOID)
{

	_mkdir(GAME_DATA);	//セーブデータを入れるフォルダを作成

	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{
		Number_Image[cnt].Num_flg = FALSE;	//問題が入っているかどうかのフラグを初期化
		Number_Image[cnt].Positon_flg = FALSE;
		Number_Image[cnt].X = 0;
		Number_Image[cnt].Y = 0;
	}

	for (int cnt = 0; cnt < LEVEL_KIND; cnt++)
	{
		RECT_RESET(&Level_Image_rect[cnt]);
	}

	RESET_MOUSE_DATE();		//マウス情報をリセット

	Q_Sum = 0;		//問題数を初期化
	True_Kazu = 0;	//正解数を初期化
	Player_Anser = 0;//プレイヤーの回答を初期化

	StartTime = 0;	//計測時間を初期化
	NokoriTime = 0;	//残り時間を初期化
	LimitTime = GAMETIME;//制限時間の設定

	SaveNowCnt = 0;	
	SaveMaxNum = 0;
	SaveMinNum = 0;

	BackImageNow = BACKIMAGE_TITLE;	//背景画像の種類を初期化
	Setu_Now = BACKIMAGE_SETULEVEL;//説明段階をレベルにする

	//フラグ関連を初期化
	True_flg = FALSE;								
	False_flg = FALSE;								
	End_flg = FALSE;								
	Continue_flg = FALSE;
	Write_flg = FALSE;				//データの書き込みを下かどうかのフラグ
	Sort_flg = FALSE;
	Read_flg = FALSE;
	Delete_flg = FALSE;
	GameEnd_flg = FALSE;
	WaitTime_flg = FALSE;
	Setumei_flg = FALSE;
	First_flg = TRUE;
	CountDownStart_flg = FALSE;

	return TRUE;
}

//############ プレイヤーの回答を取得し、正解か不正解か判定する関数 ############
VOID GET_PLAYER_ANSER(int num)
{
	Player_Anser = 0;	//プレイヤーの回答を入れる変数を初期化

	Player_Anser = num;	//プレイヤーの回答を変数に入れる

	//▼▼▼▼▼▼▼▼▼▼▼▼▼ プレイヤーの回答が正解か判定する ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	if (Number_Image[Player_Anser].Num_flg == FALSE)	//プレイヤーの回答が正解だったら、
	{
		True_flg = TRUE;		//正解フラグ

		ChangeVolumeSoundMem(255 * 50 / 100, SE_TRUE.Handle);	//SEの音量を50％にする
		PlaySoundMem(SE_TRUE.Handle, DX_PLAYTYPE_BACK);	//正解の効果音を鳴らす

		RESET_MOUSE_DATE();
	}
	else if (Number_Image[Player_Anser].Num_flg == TRUE)//プレイヤーの回答が不正解だったら、
	{
		False_flg = TRUE;		//不正解フラグ

		ChangeVolumeSoundMem(255 * 50 / 100, SE_FALSE.Handle);	//SEの音量を50％にする
		PlaySoundMem(SE_FALSE.Handle, DX_PLAYTYPE_BACK);	//不正解の効果音を鳴らす

		RESET_MOUSE_DATE();
	}

	//正解か不正解かで処理を変える
	if (True_flg == TRUE)	//正解の場合
	{
		True_Kazu++;		//正解数をプラス
		Q_Sum++;			//問題総数をプラス
		LimitTime += 1;		//残り時間を増やす
		GameSceneNow = (int)GAME_SCENE_SET;	//ゲームシーンを設定画面に変更
	}
	else if (False_flg == TRUE)	//不正解の場合
	{
		Q_Sum++;			//問題総数をプラス
		LimitTime -= 1;		//残り時間を減らす
		GameSceneNow = (int)GAME_SCENE_SET;	//ゲームシーンを設定画面に変更
	}
	//▲▲▲▲▲▲▲▲▲▲▲▲▲ プレイヤーの回答が正解か判定する ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

	return;

}

//############ 難易度の画像を描画する関数 ############
VOID GAMELEVEL_IMAGE_DRAW(VOID)
{
	//画像の位置調節
	GameLevel_Image[GAME_LEVEL_EASY].X = GAZOU_SPACE * 1.5;
	GameLevel_Image[GAME_LEVEL_EASY].Y = 400;										    		
	GameLevel_Image[GAME_LEVEL_NORMAL].X = GameLevel_Image[GAME_LEVEL_EASY].X + GameLevel_Image[GAME_LEVEL_EASY].Width + GAZOU_SPACE;
	GameLevel_Image[GAME_LEVEL_NORMAL].Y = 400;
	GameLevel_Image[GAME_LEVEL_HARD].X = GameLevel_Image[GAME_LEVEL_NORMAL].X + GameLevel_Image[GAME_LEVEL_NORMAL].Width + GAZOU_SPACE;
	GameLevel_Image[GAME_LEVEL_HARD].Y = 400;

	for (int num = 0; num < LEVEL_KIND; num++)
	{
		DrawGraph(
			GameLevel_Image[num].X,
			GameLevel_Image[num].Y,
			GameLevel_Image[num].Handle, FALSE);	//画像描画

	}

	return;
}

//############ 領域の設定をする関数 ############
VOID RECT_SETTING(RECT *rect,int x,int y,int width,int height)
{
	rect->left = x;
	rect->top = y;
	rect->right = x + width;
	rect->bottom = y + height;
}

//############ 領域を初期化する関数 ############
VOID RECT_RESET(RECT *a)
{
	//画像の領域の初期化
		a->left = 0;	//画像の左上(X)
		a->top = 0;	//画像の左上(Y)
		a->right = 0;	//画像の右下(X)
		a->bottom = 0;//画像の右下(Y)

}

//########## 領域の当たり判定をする関数 ##########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left<b.right&&
		a.top<b.bottom&&
		a.right>b.left&&
		a.bottom>b.top)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たってない

}

//########### マウスの情報を取得する関数 ############
VOID GET_MOUSE_STATE(RECT *rect ,int num)
{
	GetMousePoint(&Mouse_Date.X, &Mouse_Date.Y);	//マウスの座標を取得

	Mouse_Date.Mouse_Input = GetMouseInput();		//マウスのクリック情報を取得

		//マウスが画像の領域内かどうか判定
	for (int cnt = 0; cnt < num; cnt++)
	{
		if (CHECK_RECT_ATARI(rect[cnt], Mouse_Date) == TRUE)	//マウスが画像の領域内だったとき
		{
			Mouse_Date.Mouse_hover_flg = TRUE;
			break;
		}
		else	//マウスが画像の領域外だった時
		{
			Mouse_Date.Mouse_hover_flg = FALSE;
		}
	}
	

	//▼▼▼▼▼▼▼▼▼▼ マウスをクリックした時の処理 ▼▼▼▼▼▼▼▼▼▼

	//左クリックされたら
	if ((Mouse_Date.Mouse_Input & MOUSE_INPUT_LEFT)!= 0)
	{
		Mouse_Date.Mouse_Click_Cnt++;	//マウスが推されている間カウントする
	}
	else
	{
		Mouse_Date.Mouse_Click_Cnt = 0;	//マウスのカウントをリセット
	}

	//マウスをクリックした瞬間だけ、フラグを立てる
	if (Mouse_Date.Mouse_Click_Cnt == 1)
	{
		if (Mouse_Date.Mouse_hover_flg != TRUE)	//選択肢以外の場所でクリックされたら
		{
			ChangeVolumeSoundMem(255 * 80 / 100, SE_CLICK.Handle);	//SEの音量を50％にする
			PlaySoundMem(SE_CLICK.Handle, DX_PLAYTYPE_BACK);	//クリックの効果音を鳴らす
		}
		Mouse_Date.Mouse_LeftClick_flg = TRUE;//クリックフラグ
	}
	else
	{
		Mouse_Date.Mouse_LeftClick_flg = FALSE;//クリックフラグ
	}

	//マウスが画像の領域内かどうかを取得
	//マウスが領域内でクリックされたか確認
	for (int cnt = 0; cnt < num; cnt++)
	{
		if (CHECK_RECT_ATARI(rect[cnt], Mouse_Date) == TRUE)	//マウスが画像の領域内だったとき
		{
			//領域内でクリックされたら
			if (Mouse_Date.Mouse_hover_flg == TRUE &&
				Mouse_Date.Mouse_LeftClick_flg == TRUE)
			{
				if (GameSceneNow != GAME_SCENE_PLAY)	//プレイ中以外は
				{
					ChangeVolumeSoundMem(255 * 80 / 100, SE_KETTEI.Handle);	//SEの音量を50％にする
					PlaySoundMem(SE_KETTEI.Handle, DX_PLAYTYPE_BACK);	//クリックの効果音を鳴らす
				}
				
				Mouse_Date.Mouse_Click_Num = cnt;		//マウスがクリックされた画像の番号を取得
				break;
			}
		}

	}
	//▲▲▲▲▲▲▲▲▲▲ マウスをクリックしたときの処理 ▲▲▲▲▲▲▲▲▲▲

	return;

}

//########### マウスの情報をリセットする関数 ###########
VOID RESET_MOUSE_DATE(VOID)
{
	Mouse_Date.Mouse_Click_Num = -1;	//クリックした領域の番号を初期化
	Mouse_Date.Mouse_hover_flg = FALSE;	//ホバーフラグをリセット
	Mouse_Date.Mouse_LeftClick_flg = FALSE;//左クリックの情報をリセット
	return;
}

//############# マウスが画像の領域内かどうか判断する関数 ##################
BOOL CHECK_RECT_ATARI(RECT a, MOUSE b)
{
	if (a.left < b.X && 
		a.top < b.Y &&
		a.right > b.X &&
		a.bottom > b.Y)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たってない
}

//############# 情報を描画する関数 #############
VOID STATE_DRAW(VOID)
{
	//▼▼▼▼▼▼▼▼▼▼▼▼ マウスの情報を描画 ▼▼▼▼▼▼▼▼▼▼▼▼▼

	DrawFormatString(0, 20, GetColor(255, 255, 255), "マウスX:%d", Mouse_Date.X);	//マウスのX座標
	DrawFormatString(0, 40, GetColor(255, 255, 255), "マウスY:%d", Mouse_Date.Y);	//マウスのY座標

	if (Mouse_Date.Mouse_hover_flg == TRUE)//マウスが画像の領域内にいるとき
	{
		DrawString(0, 60, "マウスホバーフラグ:ON", GetColor(255, 255, 255));				//マウスホバーフラグの描画
	}
	else
	{
		DrawString(0, 60, "マウスホバーフラグ:OFF", GetColor(255, 255, 255));				//マウスホバーフラグの描画
	}

	//領域内でクリックされたら
	if (Mouse_Date.Mouse_hover_flg == TRUE &&
		Mouse_Date.Mouse_LeftClick_flg == TRUE)
	{
		DrawString(0, 80, "左クリックされました", GetColor(255, 255, 255));
	}

	//DrawFormatString(0, 120, GetColor(255, 255, 255), "正解数:%d", True_Kazu);				//正解数の描画
	//DrawFormatString(0, 140, GetColor(255, 255, 255), "不正解数:%d", Q_Sum - True_Kazu);	//不正解数の描画

	
	//▲▲▲▲▲▲▲▲▲▲▲▲▲ マウスの情報を描画 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

	if (GameSceneNow == (int)GAME_SCENE_PLAY)
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "残り%d秒", 30 - (GetNowCount() - StartTime) / 1000);//残り時間の描画
	}

	return;
}

//############ スタートの選択肢を描画する関数 ##############
VOID DRAW_START(VOID)
{
	for (int num = 0; num < START_KIND; num++)
	{
		DrawGraph(
			Start_Image[num].X,
			Start_Image[num].Y,
			Start_Image[num].Handle, FALSE);	//画像描画

	}
}

//############ はいといいえの画像を描画する関数 ############
VOID DRAW_SELECT(VOID)
{
	for (int num = 0; num < SELECT_KIND; num++)
	{
		DrawGraph(
			Select_Image[num].X,
			Select_Image[num].Y,
			Select_Image[num].Handle, FALSE);	//画像描画

	}

}

//############ 説明時に使用する小物（矢印など）を描画する関数 ############
VOID DRAW_SETU(VOID)
{
		DrawGraph(
			Setu_Image.X,
			Setu_Image.Y,
			Setu_Image.Handle, FALSE);	//画像描画

}

//############ 問題を描画する関数 #############
VOID DRAW_QUESTION(VOID)
{
	int rote = 1;	//回転角度

	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{
		if (Number_Image[cnt].Num_flg == TRUE)
		{
			switch (Game_Level_Now)
			{
			case GAME_LEVEL_EASY:	//難易度かんたんの処理

				DrawGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE);	//問題を描画
				
				break;

			case GAME_LEVEL_NORMAL:	//難易度普通の処理

				//回転角度の処理
				if (cnt % 2 == 0)		//偶数の時
				{
					rote = cnt + 2;			//右回転
				}
				else if (cnt % 2 == 1)	//奇数の時
				{
					rote = -cnt + 2;		//左回転
				}

				//角度を変えて描画
				DrawRotaGraph(Number_Image[cnt].X + Number_Image[cnt].C_Width,
					Number_Image[cnt].Y + Number_Image[cnt].C_Height,
					EXPANSION,	//拡大率
					PI/ rote,	//回転角度
					Number_Image[cnt].Handle, TRUE);

			break;

			case GAME_LEVEL_HARD: //難易度難しいの処理

				MOVE_QUESTION(&Number_Image[cnt], &Q_rect[cnt]);	//問題の描画位置を移動

				DrawGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE);	//問題を移動させながら描画

				break;
			}
		}

		//DrawBox(Q_rect[cnt].left,
		//	Q_rect[cnt].top,
		//	Q_rect[cnt].right,
		//	Q_rect[cnt].bottom,
		//	GetColor(255, 255, 255), FALSE);//問題の領域を描画
	}

	return;
}

//############ 回答用の数字を描画する関数 ############
VOID DRAW_ANSER_NUM(VOID)
{
	DrawGraph(Num_Image.X, Num_Image.Y, Num_Image.Handle, TRUE);	//回答用の数字を描画

	for (int cnt = 0; cnt < RECT_CNT; cnt++)
	{
		DrawBox(A_num[cnt].left, A_num[cnt].top, A_num[cnt].right, A_num[cnt].bottom, GetColor(255, 255, 255), FALSE);//領域を描画
	}

}

//############ 結果を描画する関数 #################
VOID DRAW_RESULET(VOID)
{
	char StrGameZanki[2][128] = { "\0" };
	char StrFontZanki[128] = { "MS ゴシック" };

	sprintf(&StrGameZanki[0][0], "%d問中%d問正解", Q_Sum, True_Kazu);	//問題数と正解数を描画

	MY_DRAW_STRING_CENTER_CENTER(&StrGameZanki[0], 1, StrFontZanki, 80);	//画面中央に描画

}

//############ 終了の選択肢を描画する関数 ############
VOID DRAW_END_IMAGE(VOID)
{
	for (int num = 0; num < END_KIND; num++)
	{
		DrawGraph(
			End_Image[num].X,
			End_Image[num].Y,
			End_Image[num].Handle, FALSE);	//画像描画

	}
}

//########### 指定した背景画像を描画する関数 ###########
VOID DRAW_BACKIMAGE(GAZOU *back)
{
	DrawGraph(back->X, back->Y, back->Handle, FALSE);	//背景の描画
}

//########### ランキングを描画する関数 #################
VOID DRAW_RANKING(int data,int cnt)
{
	int Font = CREATE_FONT(60);	//フォントハンドル作成
	char Str_Ranking[128] = { 0 };

	sprintf(&Str_Ranking[0], "%2d位:%2d問",cnt + 1,data);

	int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Ranking[0]);	//デフォルトのフォントの横幅を取得

	DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
		100 + cnt*60,
		&Str_Ranking[0],
		GetColor(255, 255, 255),
		Font);	//ランキングの描画

	DeleteFontToHandle(Font);	//フォントハンドル削除
}

//########### スタートの画像の設定をする関数 ##########
VOID SET_START_IMAGE(VOID)
{
	//▼▼▼▼▼▼▼▼▼▼▼ 画像の位置を調節 ▼▼▼▼▼▼▼▼▼▼▼
	Start_Image[0].X = GAZOU_SPACE * 1.5;
	Start_Image[0].Y = 400;

	Start_Image[1].X = Start_Image[0].X + Start_Image[0].Width + GAZOU_SPACE * 1.5;
	Start_Image[1].Y = 400;

	Start_Image[2].X = Start_Image[1].X + Start_Image[1].Width + GAZOU_SPACE * 1.5;
	Start_Image[2].Y = 400;
	//▲▲▲▲▲▲▲▲▲▲▲ 画像の位置を調節 ▲▲▲▲▲▲▲▲▲▲▲



	//▼▼▼▼▼▼▼▼▼▼▼ 画像の領域を設定 ▼▼▼▼▼▼▼▼▼▼▼
	for (int cnt = 0; cnt < START_KIND; cnt++)
	{
		RECT_SETTING(&Start_rect[cnt],
			Start_Image[cnt].X,
			Start_Image[cnt].Y,
			Start_Image[cnt].Width,
			Start_Image[cnt].Height);
	}
	//▲▲▲▲▲▲▲▲▲▲▲ 画像の領域を設定 ▲▲▲▲▲▲▲▲▲▲▲

}

//########### はいといいえの画像描画の設定をする関数 ##########
VOID SET_SELECT_IMAGE(VOID)
{
	//▼▼▼▼▼▼▼▼▼▼▼ 画像の位置を調節 ▼▼▼▼▼▼▼▼▼▼▼
	Select_Image[0].X = GAZOU_SPACE * 2;
	Select_Image[0].Y = GAME_HEIGHT / 2 - Select_Image[0].C_Height;

	Select_Image[1].X = Select_Image[0].X + Select_Image[0].Width + GAZOU_SPACE * 2;
	Select_Image[1].Y = GAME_HEIGHT / 2 - Select_Image[1].C_Height;
	//▲▲▲▲▲▲▲▲▲▲▲ 画像の位置を調節 ▲▲▲▲▲▲▲▲▲▲▲



	//▼▼▼▼▼▼▼▼▼▼▼ 画像の領域を設定 ▼▼▼▼▼▼▼▼▼▼▼
	for (int cnt = 0; cnt < SELECT_KIND; cnt++)
	{
		RECT_SETTING(&Select_rect[cnt],
			Select_Image[cnt].X,
			Select_Image[cnt].Y,
			Select_Image[cnt].Width,
			Select_Image[cnt].Height);
	}
	//▲▲▲▲▲▲▲▲▲▲▲ 画像の領域を設定 ▲▲▲▲▲▲▲▲▲▲▲

}

//############ 回答用の数字の設定をする関数 ###########
VOID SET_ANSER_NUM(VOID)
{
	//画像の描画位置を設定
	Num_Image.X = 0;
	Num_Image.Y = Q_ERIA_HEIGHT;

	for (int cnt = 0; cnt < RECT_CNT; cnt++)
	{
		RECT_SETTING(&A_num[cnt],
			cnt * RECT_YOKO_SIZE,
			Num_Image.Y,
			RECT_YOKO_SIZE,
			RECT_TATE_SIZE);	//領域をセット
	}
}

//############ ゲームレベルを設定する関数 ############
VOID SET_GAME_LEVEL(int num)
{

	Game_Level_Now = -1;	//ゲームレベルを-1で初期化

	switch (num)
	{
	case (int)GAME_LEVEL_EASY:	//簡単の画像の領域内だった時
		Game_Level_Now = GAME_LEVEL_EASY;	//ゲーム難易度を簡単に設定
		GameSceneNow = (int)GAME_SCENE_SET;	//シーンを設定画面にする

		break;

	case (int)GAME_LEVEL_NORMAL: //普通の画像の領域内だった時
		Game_Level_Now = GAME_LEVEL_NORMAL;	//ゲーム難易度を普通に設定
		GameSceneNow = (int)GAME_SCENE_SET;	//シーンを設定画面にする

		break;

	case (int)GAME_LEVEL_HARD:	//難しいの画像の領域内だった時
		Game_Level_Now = GAME_LEVEL_HARD;	//ゲーム難易度を難しいに設定
		GameSceneNow = (int)GAME_SCENE_SET;	//シーンを設定画面にする

		break;

	default:
		break;

	}
}

//########### 終了の選択肢の画像の設定をする関数 ############
VOID SET_END_IMAGE(VOID)
{
	//▼▼▼▼▼▼▼▼▼▼▼ 画像の位置を調節 ▼▼▼▼▼▼▼▼▼▼▼
	End_Image[0].X = GAZOU_SPACE * 3.5;
	End_Image[0].Y = 450;

	End_Image[1].X = End_Image[0].X + End_Image[0].Width + GAZOU_SPACE * 3.5;
	End_Image[1].Y = 450;
	//▲▲▲▲▲▲▲▲▲▲▲ 画像の位置を調節 ▲▲▲▲▲▲▲▲▲▲▲




	//▼▼▼▼▼▼▼▼▼▼▼ 画像の領域を設定 ▼▼▼▼▼▼▼▼▼▼▼
	for (int cnt = 0; cnt < END_KIND; cnt++)
	{
		RECT_SETTING(&End_rect[cnt],
			End_Image[cnt].X,
			End_Image[cnt].Y,
			End_Image[cnt].Width,
			End_Image[cnt].Height);
	}
	//▲▲▲▲▲▲▲▲▲▲▲ 画像の領域を設定 ▲▲▲▲▲▲▲▲▲▲▲

	return;
}

//########### 説明画面で使用する小物（矢印など）の画像の設定をする関数 ############
VOID SET_END_SETU(VOID)
{
	//▼▼▼▼▼▼▼▼▼▼▼ 画像の位置を調節 ▼▼▼▼▼▼▼▼▼▼▼
	Setu_Image.X = 880;
	Setu_Image.Y = 0;
	//▲▲▲▲▲▲▲▲▲▲▲ 画像の位置を調節 ▲▲▲▲▲▲▲▲▲▲▲




	//▼▼▼▼▼▼▼▼▼▼▼ 画像の領域を設定 ▼▼▼▼▼▼▼▼▼▼▼
		RECT_SETTING(&Setu_rect,
			Setu_Image.X,
			Setu_Image.Y,
			Setu_Image.Width,
			Setu_Image.Height);
	//▲▲▲▲▲▲▲▲▲▲▲ 画像の領域を設定 ▲▲▲▲▲▲▲▲▲▲▲

	return;
}

//########## 音を読み込む設定をする関数 ##########
//引　数：音構造体　	:設定する音構造体の変数
//引　数：const char *	:読み込む画像のファイルパス
//戻り値：BOOL			:TRUE:正常 / FALSE:異常
BOOL MY_MUSIC_LOAD(MUSIC *m, const char *path)
{
	//音を読み込む
	m->Handle = LoadSoundMem(path);

	if (m->Handle == -1) { return FALSE; }

	return TRUE;
}

//############ ゲーム続行か終了か判定する関数 #############
VOID CHECK_GAME_CONTINUE(int num)
{

	End_flg = FALSE;		//終了フラグを初期化
	Continue_flg = FALSE;	//続行フラグを初期化

	switch (num)
	{
	case (int)GAME_CONTINUE:
		Continue_flg = TRUE;	//続行フラグ
		break;

	case (int)GAME_END:
		End_flg = TRUE;		//終了フラグ
		break;

	default:
		break;
	}

	//終了か続行かで処理を変える
	if (End_flg == TRUE)
	{
		//GameSceneNow = (int)GAME_SCENE_END;	//ゲームシーンをエンド画面に変える
		GameSceneNow = (int)GAME_SCENE_CHECK;	//ゲームシーンを確認画面に変える
	}
	else if (Continue_flg == TRUE)
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;//ゲームシーンをタイトル画面に変える
	}

	return;
}

//############## ゲーム開始か終了か判定する関数 #############
VOID CHECK_GAME_START(int num)
{
	End_flg = FALSE;		//終了フラグを初期化
	Start_flg = FALSE;		//開始フラグを初期化

	switch (num)
	{
	case (int)GAME_START:
		Start_flg = TRUE;	//開始フラグ
		break;

	case (int)GAME_SETUMEI:
		Setumei_flg = TRUE;//説明フラグ
		break;

	case (int)GAME_END2:
		End_flg = TRUE;		//終了フラグ
		break;

	default:
		break;
	}

	//開始、終了、説明かで処理を変える
	if (End_flg == TRUE)
	{
		GameSceneNow = (int)GAME_SCENE_CHECK;	//ゲームシーンを確認画面に変える
	}
	else if (Setumei_flg == TRUE)
	{
		GameSceneNow = (int)GAME_SCENE_SETUMEI;	//ゲームシーンを説明画面に変える
	}
	else if (Start_flg == TRUE)
	{
		GameSceneNow = (int)GAME_SCENE_SELECT;//ゲームシーンをレベル選択画面に変える
	}

	return;
}

//############## はいかいいえのどちらを選んだか判定する関数 #############
BOOL CHECK_SELECT(int num)
{
	Yes_flg = FALSE;		//はいのフラグを初期化
	No_flg = FALSE;			//いいえのフラグを初期化

	switch (num)
	{
	case (int)SELECT_YES:
		return TRUE;

	case (int)SELECT_NO:
		return FALSE;
		break;

	default:
		break;
	}

}

//############## 時間を描画する関数 ######################
VOID DRAW_TIME(VOID)
{
	int Font = CREATE_FONT(80);	//フォントハンドル作成
	char Str_Time[128] = {0};

	sprintf(&Str_Time[0], "残り時間:%.2f", NokoriTime);

	int StrWidth = GetDrawFormatStringWidthToHandle(Font,&Str_Time[0]);	//デフォルトのフォントの横幅を取得
	
	if (NokoriTime <= 10 && NokoriTime > 0)	//10秒を切ったら、赤色で描画する
	{
		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			0,
			&Str_Time[0],
			GetColor(255, 0, 0),
			Font);	//時間の描画
	}
	else if(NokoriTime>0)
	{
		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			0,
			&Str_Time[0],
			GetColor(255, 255, 255),
			Font);	//時間の描画
	}

	DeleteFontToHandle(Font);	//フォントハンドル削除

	return;
}

//############## 問題の描画位置を移動させる関数 #################
VOID MOVE_QUESTION(GAZOU *g, RECT *rect)
{

	switch (g->Direction)		//画像の移動方向
	{
	case DIRECTION_UP:			//上方向の処理

		if (g->Y - Speed > 0)	//画面内のときは
		{
			g->Y -= Speed;			//画像を上方向へ移動

			rect->top -= Speed;		//領域を上方向へ移動
			rect->bottom -= Speed;	//領域を上方向へ移動
		}
		else  //画面の端に当たったら
		{
			g->Direction = DIRECTION_DOWN;	//移動方向を下に変える
		}
		break;

	case DIRECTION_DOWN:			//下方向の処理

		if (g->Y + g->Height + Speed < Q_ERIA_HEIGHT)	//問題の領域内の時は
		{
			g->Y += Speed;			//画像を下方向へ移動

			rect->top += Speed;		//領域を下方向へ移動
			rect->bottom += Speed;	//領域を下方向へ移動
		}
		else  //端に当たったら
		{
			g->Direction = DIRECTION_UP;	//移動方向を上に変える
		}
		break;

	case DIRECTION_LEFT:			//左方向の処理

		if (g->X - Speed > 0)	//画面内の時は
		{
			g->X -= Speed;			//画像を左方向へ移動

			rect->left -= Speed;	//領域を左方向へ移動
			rect->right -= Speed;	//領域を左方向へ移動
		}
		else  //端に当たったら
		{
			g->Direction = DIRECTION_RIGHT;	//移動方向を右にする
		}
		break;

	case DIRECTION_RIGHT:			//右方向の処理

		if (g->X + g->Width + Speed < GAME_WIDTH)	//画面内のときは
		{
			g->X += Speed;			//画像を右方向へ移動

			rect->left += Speed;	//領域を右方向へ移動
			rect->right += Speed;	//領域を右方向へ移動
		}
		else  //右端に当たった時
		{
			g->Direction = DIRECTION_LEFT;	//移動方向を左にする
		}
		break;

	case DIRECTION_LEFTUP:			//左上方向の処理

		if (g->X - Speed > 0)		//画面内の時
		{
			g->X -= Speed;			//画像を左上方向へ移動

			rect->left -= Speed;	//領域を左上方向へ移動
			rect->right -= Speed;	//領域を左上方向へ移動
		}
		else  //左端に当たった時
		{
			g->Direction = DIRECTION_RIGHTUP;		//移動方向を右上にする
			break;
		}

		if (g->Y - Speed > 0)		//画面内の時
		{
			g->Y -= Speed;			//画像を左上方向へ移動

			rect->top -= Speed;		//領域を左上方向へ移動
			rect->bottom -= Speed;	//領域を左上方向へ移動
		}
		else  //上に当たった時
		{
			g->Direction = DIRECTION_LEFTDOWN;	//移動方向を左下にする
			break;
		}
		break;

	case DIRECTION_LEFTDOWN:			//左下方向の処理

		if (g->X - Speed > 0)		//画面内の時
		{
			g->X -= Speed;			//画像を左下へ移動

			rect->left -= Speed;	//領域を左下へ移動
			rect->right -= Speed;	//領域を左下へ移動
		}
		else  //左端に当たった時
		{
			g->Direction = DIRECTION_RIGHTDOWN;
			break;
		}

		if (g->Y + g->Height + Speed < Q_ERIA_HEIGHT)	//画面内の時
		{
			g->Y += Speed;			//画像を左下へ移動

			rect->top += Speed;		//領域を左下へ移動
			rect->bottom += Speed;	//領域を左下へ移動
		}
		else  //下に当たった時
		{
			g->Direction = DIRECTION_LEFTUP;	//移動方向を左上にする
			break;
		}
		break;

	case DIRECTION_RIGHTUP:			//右上方向の処理

		if (g->X + g->Width + Speed < GAME_WIDTH)	//画面内のとき
		{
			g->X += Speed;			//画像を右上へ移動

			rect->left += Speed;	//領域を右上へ移動
			rect->right += Speed;	//領域を右上へ移動
		}
		else  //右端に当たった時
		{
			g->Direction = DIRECTION_LEFTUP;	//移動方向を左上にする
			break;
		}

		if (g->Y - Speed > 0)		//画面内の時
		{
			g->Y -= Speed;			//画像を右上へ移動

			rect->top -= Speed;		//領域を右上へ移動
			rect->bottom -= Speed;	//領域を右上へ移動
		}
		else  //上に当たった時
		{
			g->Direction = DIRECTION_RIGHTDOWN;	//移動方向を右下にする
			break;
		}
		
		break;

	case DIRECTION_RIGHTDOWN:			//右下方向の処理

		if (g->X + g->Width + Speed < GAME_WIDTH)	//画面内の時
		{
			g->X += Speed;			//画像を右下へ移動

			rect->left += Speed;	//領域を右下へ移動
			rect->right += Speed;	//領域を右下へ移動
		}
		else
		{
			g->Direction = DIRECTION_LEFTDOWN;	//移動方向を左下にする
			break;
		}

		if (g->Y + g->Height + Speed < Q_ERIA_HEIGHT)	//領域内の時
		{
			g->Y += Speed;			//画像を右下へ移動

			rect->top += Speed;		//領域を右下へ移動
			rect->bottom += Speed;	//領域を右下へ移動
		}
		else  //下に当たったとき
		{
			g->Direction = DIRECTION_RIGHTUP;	//移動方向を右上にする
			break;
		}

		break;

	default:
		break;

	}

	return;

}

//############## セーブデータを更新する関数 #####################
int WRITE_SAVEDATA(int data)
{

	FILE *fp;

	switch (Game_Level_Now)
	{
	case (int)GAME_LEVEL_EASY:	//難易度、簡単のとき
		
		fp = fopen(DATA_EASY, "ab");//バイナリファイルを開く
		if (fp == NULL) {//エラーが起きたら-1を返す
			return -1;
		}
		fwrite(&data, sizeof(int), 1, fp); // dataを出力
		fclose(fp);//ファイルを閉じる

		break;

	case (int)GAME_LEVEL_NORMAL: //難易度、普通のとき
		
		fp = fopen(DATA_NORMAL , "ab");//バイナリファイルを開く
		if (fp == NULL) {//エラーが起きたら-1を返す
			return -1;
		}
		fwrite(&data, sizeof(int), 1, fp); // dataを出力
		fclose(fp);//ファイルを閉じる

		break;

	case (int)GAME_LEVEL_HARD:	//難易度、難しいのとき
		
		fp = fopen(DATA_HARD, "ab");//バイナリファイルを開く
		if (fp == NULL) {//エラーが起きたら-1を返す
			return -1;
		}
		fwrite(&data, sizeof(int), 1, fp); // dataを出力
		fclose(fp);//ファイルを閉じる

		break;

	default:
		break;

	}

	return 0;
}

//############## セーブデータを読み込む関数 #####################
int READ_SAVEDATA(int data[])
{
	SaveNowCnt = 0;

	FILE *fp;

	switch (Game_Level_Now)
	{
	case (int)GAME_LEVEL_EASY:	//難易度、簡単のとき

		fp = fopen(DATA_EASY, "rb");
		if (fp == NULL) {
			return -1;	//エラーが発生したら、-1を返す
		}

		while (!feof(fp)) {		//ファイルの終端になるまで読み込み
			fread(&data[SaveNowCnt], sizeof(data), 1, fp);
			SaveNowCnt++;
		}

		SaveNowCnt--;

		fclose(fp);
		break;

	case (int)GAME_LEVEL_NORMAL: //難易度、普通のとき

		fp = fopen(DATA_NORMAL, "rb");
		if (fp == NULL) {
			return -1;	//エラーが発生したら、-1を返す
		}

		while (!feof(fp)) {		//ファイルの終端になるまで読み込み
			fread(&data[SaveNowCnt], sizeof(data), 1, fp);
			SaveNowCnt++;
		}

		SaveNowCnt--;

		fclose(fp);

		break;

	case (int)GAME_LEVEL_HARD:	//難易度、難しいのとき

		fp = fopen(DATA_HARD, "rb");
		if (fp == NULL) {
			return -1;	//エラーが発生したら、-1を返す
		}

		while (!feof(fp)) {		//ファイルの終端になるまで読み込み
			fread(&data[SaveNowCnt], sizeof(data), 1, fp);
			SaveNowCnt++;
		}

		SaveNowCnt--;

		fclose(fp);
		break;

	default:
		break;

	}

	return 0;
}

//############## 値を入れ替える関数 #############################
VOID SWAP(int *x, int *y)
{
	int temp;    // 値を一時保存する変数

	temp = *x;
	*x = *y;
	*y = temp;
}

//############## pivotを決め、pivotを境目に振り分けする関数 ################
int PARTITION(int array[], int left, int right)
{
	int i, j, pivot;
	i = left;
	j = right + 1;
	pivot = left;   // 先頭要素をpivotとする

	do {
		do { i++; } while (array[i] > array[pivot]);
		do { j--; } while (array[pivot] > array[j]);
		// pivotより小さいものを左へ、大きいものを右へ
		if (i < j) { SWAP(&array[i], &array[j]); }
	} while (i < j);

	SWAP(&array[pivot], &array[j]);   //pivotを更新

	return j;
}

//############## クイックソート関数 ##############################
VOID QUICK_SORT(int array[], int left, int right)
{
	int pivot;

	if (left < right) {
		pivot = PARTITION(array, left, right);
		QUICK_SORT(array, left, pivot - 1);   // pivotを境に再帰的にクイックソート
		QUICK_SORT(array, pivot + 1, right);
	}
}

//############## セーブデータを降順に並べ替える関数 #################
VOID SORT_SAVEDATA(int array[])
{
	READ_SAVEDATA(array);	//セーブデータの読み込み

	SAVEDATA_MAX(array, SaveNowCnt);	//最大値取得

	SAVEDATA_MIN(array, SaveNowCnt);	//最小値取得

	QUICK_SORT(array, SaveMinNum, SaveMaxNum);	//クイックソート

	return;
}

//############ セーブデータの最大値を取得する関数 ################
VOID SAVEDATA_MAX(int array[],int num)
{
	int tempmax = 0;	//最大値を入れる変数

	for (int cnt = 0; cnt < num; cnt++)
	{
		if (array[cnt] > tempmax)	//現在の最大値より大きかったら
		{
			tempmax = array[cnt];	//最大値更新
		}
	}

	SaveMaxNum = tempmax;	//作業用に入っている最大値を入れる

	return;
}

//############ セーブデータの最小値を取得する関数 ################
VOID SAVEDATA_MIN(int array[],int num)
{
	int tempmin = 0;	//最小値を入れる変数

	for (int cnt = 0; cnt < num; cnt++)
	{
		if (array[cnt] < tempmin)	//現在の最小値より大きかったら
		{
			tempmin = array[cnt];	//最小値更新
		}
	}

	SaveMinNum = tempmin;	//作業用に入っている最小値を入れる

	return;
}

//########### セーブデータを削除する関数 ####################
int DELETE_DATA(int data)
{
	FILE *fp;

	fp = fopen(DATA_EASY, "wb");//バイナリファイルを開く
	if (fp == NULL) {//エラーが起きたら-1を返す
		return -1;
	}
	fclose(fp);//ファイルを閉じる

	fp = fopen(DATA_NORMAL, "wb");//バイナリファイルを開く
	if (fp == NULL) {//エラーが起きたら-1を返す
		return -1;
	}
	fclose(fp);//ファイルを閉じる

	fp = fopen(DATA_HARD, "wb");//バイナリファイルを開く
	if (fp == NULL) {//エラーが起きたら-1を返す
		return -1;
	}
	fclose(fp);//ファイルを閉じる

	return 0;

}

//############ 待ち時間を描画する関数 ####################
VOID DRAW_WAIT_TIME(int wait)
{
	int Font = CREATE_FONT(FONT_SIZE);	//フォントハンドル作成
	char Str_Time[128] = { 0 };

	sprintf(&Str_Time[0], "%.0f", NokoriTime);

	int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Time[0]);	//デフォルトのフォントの横幅を取得

	if (NokoriTime > 1)
	{
		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			300,
			&Str_Time[0],
			GetColor(255, 0, 255),
			Font);	//時間の描画
		
	}
	else if (First_flg==TRUE &&
		NokoriTime < 0.3)	//プレイ画面のカウントダウンの最後に"START"の描画をする
	{
		int Font = CREATE_FONT(100);	//フォントハンドル作成
		char Str_Ranking[128] = { "START" };

		int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Ranking[0]);	//デフォルトのフォントの横幅を取得

		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			300,
			&Str_Ranking[0],
			GetColor(255, 0, 0),
			Font);	//STARTの描画

		DeleteFontToHandle(Font);	//フォントハンドル削除
	}
	
	DeleteFontToHandle(Font);	//フォントハンドル削除

	return;
}
