/*--+----1----+----2----+----3----+----4----+----5--//-+----6----+----7----+----8----+----9----+---*/
/* hinagata.cpp     																					   */

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "main.hpp"
#include "FPS.hpp"
#include <direct.h>

//*********** グローバルオブジェクト ***********
FPS *fps = new FPS(GAME_FPS_SPEED);

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


	//途中でやめるの画像
	if (MY_GAZOU_LOAD(&Retire_Image, 0, 0, RETIRE_IMAGE) == FALSE) { MessageBox(NULL, RETIRE_IMAGE, "NotFound", MB_OK); return -1; }	//やめるの画像を読み込む

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
	
	DeleteGraph(Retire_Image.Handle);	//やめるの画像のハンドルを削除

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
	else if (End_flg == TRUE || Retire_flg == TRUE)
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
			DELETE_DATA(SaveData[0]);		//簡単、のデータ削除
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
	 else if (Retire_flg == TRUE)	//リタイアフラグが立っていたら
	 {
		 GameSceneNow = (int)GAME_SCENE_PLAY;//ゲームシーンをプレイ画面に変える
		 LostTimeEnd = GetNowCount();			//中断時間をカウント終了
		 LostTime = LostTimeEnd - LostTimeStart;	//中断時間を計算
		 StartTime += LostTime;					//中断していた時間をプラスする
		 No_flg = FALSE;
	 }
	 else
	 {
		 GameSceneNow = (int)GAME_SCENE_TITLE;//ゲームシーンをタイトル画面に変える
		 No_flg = FALSE;
	 }

	}

	return;
}

//########## 設定画面の関数 ############
VOID MY_GAME_SET(VOID)
{
	//問題の初期化
	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{
		Number_Image[cnt].Num_flg = FALSE;	//問題が入っているかどうかのフラグを初期化
		Number_Image[cnt].Positon_flg = FALSE;
		Number_Image[cnt].IsDraw = TRUE;
		Number_Image[cnt].SetIsDraw_flg = FALSE;
		Number_Image[cnt].X = 0;
		Number_Image[cnt].Y = 0;
	}

	SetLevel();			//ゲームレベルをランダムに変更

	RESET_MOUSE_DATE();	//マウス情報リセット

	MY_CREATE_QUESTION();	//問題を生成

	True_flg = FALSE;	//正解フラグをリセット
	False_flg = FALSE;	//不正解フラグをリセット

	DrawTime = 0;		//描画時間0秒

	DrawStartTime = GetNowCount();	//描画開始時間取得

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

		Draw_Retire();			//「やめる」の描画
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

		Draw_Retire();			//「やめる」の描画

		GetMousePoint(&Mouse_Date.X, &Mouse_Date.Y);	//マウスの座標を取得

		if (Mouse_Date.Y < GAME_HEIGHT / 3)			//マウスの座標が画面の1/3より上だったら
		{
			GET_MOUSE_STATE(&Retire_rect, 1);	//マウスの情報を取得(やめるの画像内か)

		//「やめる」をクリックされた時
			if (Mouse_Date.Mouse_LeftClick_flg == TRUE &&
				Mouse_Date.Mouse_hover_flg == TRUE)
			{
				Retire_flg = TRUE;							//リタイアフラグ
				LostTimeStart = GetNowCount();			//中断時間をカウントスタート
				GameSceneNow = (int)GAME_SCENE_CHECK;		//確認画面へ変更
			}
		}

		

		RESET_MOUSE_DATE();	//マウス情報リセット

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
		GET_DATEDATA();				//現在時刻の取得
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

		SORT_SAVEDATA(SaveData);		//セーブデータを読み込んで、降順に並び替える
		Sort_flg = TRUE;				//ソートフラグを立てる
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
			DRAW_RANKING(SaveData[cnt], cnt);	//セーブデータの描画

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
				cnt--;												//cntの値をマイナスして、座標を設定しなおす
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
			int num2 = GetRand(REVERSE_TYPE);		//0,1のどちらかで乱数を生成
			Number_Image[num].Reverse_flg = num2;	//反転させるかどうか
			Number_Image[num].Color = GetRand(360);	//色設定
			CHENGE_COLOR(Number_Image[num].Handle,Number_Image[num].Color);//色変更
			Number_Image[num].IsDraw = TRUE;		//描画してよい
			cnt++;								//cntをインクリメント
		}
		
	}
	Flashing_flg = GetRand(1);				//点滅フラグ
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
		Number_Image[cnt].IsDraw = FALSE;	//最初は描画してはいけない
		Number_Image[cnt].SetIsDraw_flg = FALSE;
		Number_Image[cnt].X = 0;
		Number_Image[cnt].Y = 0;
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

	DrawTime = (GetNowCount() - DrawStartTime) / 1000;	//描画時間の更新

	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{
		if (Number_Image[cnt].Num_flg == TRUE)
		{
			switch (Game_Level_Now)
			{
			case (int)GAME_LEVEL_EASY:	//難易度かんたんの処理

				if (Flashing_flg)	//点滅フラグが立っていれば
				{
					DRAW_FLASHING(cnt);		//点滅描画
				}

				if (Number_Image[cnt].IsDraw)		//描画してよい時
				{
					if (Number_Image[cnt].Reverse_flg)	//反転フラグが立っているとき
					{
						DrawTurnGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE); //左右反転描画
					}
					else
					{
						DrawGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE);	//問題を描画
					}
				}

				break;

			case (int)GAME_LEVEL_NORMAL:	//難易度普通の処理

				//回転角度の処理
				if (cnt % 2 == 0)		//偶数の時
				{
					rote = cnt + 2;			//右回転
				}
				else if (cnt % 2 == 1)	//奇数の時
				{
					rote = -cnt + 2;		//左回転
				}

				if (Flashing_flg)	//点滅フラグが立っていれば
				{
					DRAW_FLASHING(cnt);		//点滅描画
				}

				if (Number_Image[cnt].IsDraw)		//描画してよい時
				{
					//角度を変えて描画
					DrawRotaGraph(Number_Image[cnt].X + Number_Image[cnt].C_Width,
						Number_Image[cnt].Y + Number_Image[cnt].C_Height,
						EXPANSION,	//拡大率
						PI / rote,	//回転角度
						Number_Image[cnt].Handle, TRUE);
				}

			break;

			case (int)GAME_LEVEL_HARD: //難易度難しいの処理

				if (Flashing_flg)	//点滅フラグが立っていれば
				{
					DRAW_FLASHING(cnt);		//点滅描画
				}

				if (Number_Image[cnt].IsDraw)		//描画してよい時
				{
					MOVE_QUESTION(&Number_Image[cnt], &Q_rect[cnt]);	//問題の描画位置を移動

					if (Number_Image[cnt].Reverse_flg)	//反転フラグが立っているとき
						DrawTurnGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE); //左右反転描画
					else
						DrawGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE);	//問題を描画

				}

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
VOID DRAW_RANKING(SAVE data,int cnt)
{
	int Font = CREATE_FONT(60);	//フォントハンドル作成
	char Str_Ranking[128] = { 0 };

	sprintf(&Str_Ranking[0], "%2d位:%d年%d月%d日%2d問",cnt + 1,data.year,data.mounth,data.day,data.point);

	int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Ranking[0]);	//デフォルトのフォントの横幅を取得

	DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
		100 + cnt*60,
		&Str_Ranking[0],
		GetColor(255, 255, 255),
		Font);	//ランキングの描画

	DeleteFontToHandle(Font);	//フォントハンドル削除
}

//########### やめるの画像を描画する関数 ###############
VOID Draw_Retire()
{

	//描画位置設定
	Retire_Image.X = GAME_WIDTH - Retire_Image.Width;	//右端に設定

	//領域再設定
	RECT_SETTING(&Retire_rect,
		Retire_Image.X,
		Retire_Image.Y,
		Retire_Image.Width,
		Retire_Image.Height);


	//画像描画
	DrawGraph(
		Retire_Image.X,
		Retire_Image.Y,
		Retire_Image.Handle, FALSE);	//画像描画

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
		GameSceneNow = (int)GAME_SCENE_SET;//ゲームシーンを設定画面に変える
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

	fp = fopen(SAVE_DATA, "a");//バイナリファイルを開く
	if (fp == NULL) {//エラーが起きたら-1を返す
		return -1;
	}
	fprintf(fp, "%d,%d,%d,%d\n",Date.Year,Date.Mon,Date.Day, data);
	fclose(fp);//ファイルを閉じる

	return 0;
}

//############## セーブデータを読み込む関数 #####################
int READ_SAVEDATA(SAVE data[])
{
	SaveNowCnt = 0;

	FILE *fp;

	fp = fopen(SAVE_DATA, "r");
	if (fp == NULL) {
		return -1;	//エラーが発生したら、-1を返す
	}

	while (fscanf(fp, "%d,%d,%d,%d", &data[SaveNowCnt].year, &data[SaveNowCnt].mounth, &data[SaveNowCnt].day, &data[SaveNowCnt].point)
		!= EOF)
	{
		SaveNowCnt++;
	}

	fclose(fp);

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
int PARTITION(SAVE array[], int left, int right)
{
	int i = 0, j = 0, pivot = 0;
	i = left;
	j = right + 1;
	pivot = left;   // 先頭要素をpivotとする

	do {
		do { i++; } while (array[i].point > array[pivot].point);
		do { j--; } while (array[pivot].point > array[j].point);
		// pivotより小さいものを左へ、大きいものを右へ
		if (i < j) { SWAP(&array[i].point, &array[j].point); }
	} while (i < j);

	SWAP(&array[pivot].point, &array[j].point);   //pivotを更新

	return j;
}

//############## クイックソート関数 ##############################
VOID QUICK_SORT(SAVE array[], int left, int right)
{
	int pivot;

	if (left < right) {
		pivot = PARTITION(array, left, right);
		QUICK_SORT(array, left, pivot - 1);   // pivotを境に再帰的にクイックソート
		QUICK_SORT(array, pivot + 1, right);
	}
}

//############## セーブデータを降順に並べ替える関数 #################
VOID SORT_SAVEDATA(SAVE array[])
{
	READ_SAVEDATA(array);	//セーブデータの読み込み

	SAVEDATA_MAX(array, SaveNowCnt);	//最大値取得

	SAVEDATA_MIN(array, SaveNowCnt);	//最小値取得

	QUICK_SORT(array, SaveMinNum, SaveMaxNum);	//クイックソート

	return;
}

//############ セーブデータの最大値を取得する関数 ################
VOID SAVEDATA_MAX(SAVE array[],int num)
{
	int tempmax = 0;	//最大値を入れる変数

	for (int cnt = 0; cnt < num; cnt++)
	{
		if (array[cnt].point > tempmax)	//現在の最大値より大きかったら
		{
			tempmax = array[cnt].point;	//最大値更新
		}
	}

	SaveMaxNum = tempmax;	//作業用に入っている最大値を入れる

	return;
}

//############ セーブデータの最小値を取得する関数 ################
VOID SAVEDATA_MIN(SAVE array[],int num)
{
	int tempmin = 0;	//最小値を入れる変数

	for (int cnt = 0; cnt < num; cnt++)
	{
		if (array[cnt].point < tempmin)	//現在の最小値より大きかったら
		{
			tempmin = array[cnt].point;	//最小値更新
		}
	}

	SaveMinNum = tempmin;	//作業用に入っている最小値を入れる

	return;
}

//########### セーブデータを削除する関数 ####################
int DELETE_DATA(SAVE data)
{
	FILE *fp;

	fp = fopen(SAVE_DATA, "w");//バイナリファイルを開く
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

//############ 日付を取得する関数 ########################
VOID GET_DATEDATA()
{
	GetDateTime(&Date);		//日付取得
	return;
}

//************ 問題レベルをランダムに設定する関数 *****************
VOID SetLevel()
{
	int rand = 0;	//乱数を入れる変数

	rand = GetRand(LEVEL_KIND - 1);	//ゲームレベルの数内で乱数を生成

	Game_Level_Now = rand;		//生成した乱数を現在のゲームレベルに設定

	return;

}

//*********** 描画色を変更する関数 ********************
BOOL CHENGE_COLOR(int handle,int color)
{

	if (GraphFilter(handle,DX_GRAPH_FILTER_HSB,1, color,0,0)==0)	//色を変更
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}


}

//*********** 点滅描画 *******************
VOID DRAW_FLASHING(int cnt)
{
	if (DrawTime >= 2 && (int)DrawTime % 2 == 0)		//2秒置きに
	{
		if (Number_Image[cnt].SetIsDraw_flg == FALSE)		//描画設定完了してないときは
		{
			if (Number_Image[cnt].IsDraw)	//描画してよい時
			{
				Number_Image[cnt].IsDraw = FALSE;	//描画してはいけない
				Number_Image[cnt].SetIsDraw_flg = TRUE;	//設定完了
			}
			else
			{
				Number_Image[cnt].IsDraw = TRUE;	//描画してよい
				Number_Image[cnt].SetIsDraw_flg = TRUE;	//設定完了
			}
		}
	}
	else
	{
		Number_Image[cnt].SetIsDraw_flg = FALSE;	//設定完了してない
	}

	return;

}
