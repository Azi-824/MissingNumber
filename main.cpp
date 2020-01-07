/*--+----1----+----2----+----3----+----4----+----5--//-+----6----+----7----+----8----+----9----+---*/
/* hinagata.cpp     																					   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include "main.hpp"
#include "FPS.hpp"
#include <direct.h>

//*********** �O���[�o���I�u�W�F�N�g ***********
FPS *fps = new FPS(GAME_FPS_SPEED);

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//�^�C�g���o�[����

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	SetWindowIconID(333);										//�E�C���h�E�̃A�C�R���ύX

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	//���������������������������������������� �摜�̓ǂݍ��� ����������������������������������������
	//���p�̐����摜�̓ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[0], 0, 0, ZERO_IMAGE) == FALSE) { MessageBox(NULL, ZERO_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[1], 0, 0, ONE_IMAGE) == FALSE) { MessageBox(NULL, ONE_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[2], 0, 0, TWO_IMAGE) == FALSE) { MessageBox(NULL, TWO_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[3], 0, 0, THREE_IMAGE) == FALSE) { MessageBox(NULL, THREE_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[4], 0, 0, FOUR_IMAGE) == FALSE) { MessageBox(NULL, FOUR_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[5], 0, 0, FIVE_IMAGE) == FALSE) { MessageBox(NULL, FIVE_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[6], 0, 0, SIX_IMAGE) == FALSE) { MessageBox(NULL, SIX_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[7], 0, 0, SEVEN_IMAGE) == FALSE) { MessageBox(NULL, SEVEN_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[8], 0, 0, EIGHT_IMAGE) == FALSE) { MessageBox(NULL, EIGHT_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Number_Image[9], 0, 0, NINE_IMAGE) == FALSE) { MessageBox(NULL, NINE_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���

	//�񓚗p�̐����摜�̓ǂݍ���
	if (MY_GAZOU_LOAD(&Num_Image, 0, 0, NUMBER_IMAGE) == FALSE) { MessageBox(NULL, NUMBER_IMAGE, "NotFound", MB_OK); return -1; }	//���̉摜��ǂݍ���

	//�͂��Ƃ������̉摜�̓ǂݍ���
	if (MY_GAZOU_LOAD(&Select_Image[0], 0, 0, YES_IMAGE) == FALSE) { MessageBox(NULL, YES_IMAGE, "NotFound", MB_OK); return -1; }	//�͂��̑I�����摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Select_Image[1], 0, 0, NO_IMAGE) == FALSE) { MessageBox(NULL, NO_IMAGE, "NotFound", MB_OK); return -1; }	//�������̑I�����摜��ǂݍ���

	//�I���̑I�����摜�̓ǂݍ���
	if (MY_GAZOU_LOAD(&End_Image[0], 0, 0, CONTINUE_IMAGE) == FALSE) { MessageBox(NULL, CONTINUE_IMAGE, "NotFound", MB_OK); return -1; }	//�I���̑I�����摜��ǂݍ���
	if (MY_GAZOU_LOAD(&End_Image[1], 0, 0, END_IMAGE) == FALSE) { MessageBox(NULL, END_IMAGE, "NotFound", MB_OK); return -1; }	//�I���̑I�����摜��ǂݍ���
	
	//�J�n�̑I�����摜�̓ǂݍ���
	if (MY_GAZOU_LOAD(&Start_Image[0], 0, 0, START_IMAGE) == FALSE) { MessageBox(NULL, START_IMAGE, "NotFound", MB_OK); return -1; }	//�J�n�̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Start_Image[1], 0, 0, SETUMEI_IMAGE) == FALSE) { MessageBox(NULL, SETUMEI_IMAGE, "NotFound", MB_OK); return -1; }	//�J�n�̉摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Start_Image[2], 0, 0, END_IMAGE2) == FALSE) { MessageBox(NULL, END_IMAGE2, "NotFound", MB_OK); return -1; }	//�J�n�̉摜��ǂݍ���
	//�^�C�g���摜�̓ǂݍ���
	if (MY_GAZOU_LOAD(&Title_Image, 0, 0, TITLE_IMAGE) == FALSE) { MessageBox(NULL, TITLE_IMAGE, "NotFound", MB_OK); return -1; }	//�J�n�̉摜��ǂݍ���

	//�w�i�摜�̓ǂݍ���
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_TITLE], 0, 0, TITLE_BACKIMAGE) == FALSE) { MessageBox(NULL, TITLE_BACKIMAGE, "NotFound", MB_OK); return -1; }		//�^�C�g����ʂ̔w�i�摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_SELECT], 0, 0, SELECT_BACKIMAGE) == FALSE) { MessageBox(NULL, SELECT_BACKIMAGE, "NotFound", MB_OK); return -1; }	//�Z���N�g��ʂ̔w�i�摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_PLAY], 0, 0, PLAY_BACKIMAGE) == FALSE) { MessageBox(NULL, PLAY_BACKIMAGE, "NotFound", MB_OK); return -1; }			//�v���C��ʂ̔w�i�摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_RESULT], 0, 0, RESULT_BACKIMAGE) == FALSE) { MessageBox(NULL, RESULT_BACKIMAGE, "NotFound", MB_OK); return -1; }	//���U���g��ʂ̔w�i�摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Back_Image[BACKIMAGE_END], 0, 0, END_BACKIMAGE) == FALSE) { MessageBox(NULL, END_BACKIMAGE, "NotFound", MB_OK); return -1; }				//�G���h��ʂ̔w�i�摜��ǂݍ���

	//������ʂŎg�p����摜�̓ǂݍ���
	if (MY_GAZOU_LOAD(&Setumei_Image[0], 0, 0, SETUMEI_LEVLEIMAGE) == FALSE) { MessageBox(NULL, SETUMEI_LEVLEIMAGE, "NotFound", MB_OK); return -1; }	//�I���̑I�����摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Setumei_Image[1], 0, 0, SETUMEI_PLAYIMAGE) == FALSE) { MessageBox(NULL, SETUMEI_PLAYIMAGE, "NotFound", MB_OK); return -1; }	//�I���̑I�����摜��ǂݍ���
	if (MY_GAZOU_LOAD(&Setu_Image, 0, 0, SETUMEI_NEXT) == FALSE) { MessageBox(NULL, SETUMEI_NEXT, "NotFound", MB_OK); return -1; }	//�I���̑I�����摜��ǂݍ���


	//�r���ł�߂�̉摜
	if (MY_GAZOU_LOAD(&Retire_Image, 0, 0, RETIRE_IMAGE) == FALSE) { MessageBox(NULL, RETIRE_IMAGE, "NotFound", MB_OK); return -1; }	//��߂�̉摜��ǂݍ���

	//�������������������������������������������������������������� �摜�̓ǂݍ��� ��������������������������������������������������������������


	//����ǂݍ���
	MY_MUSIC_LOAD(&SE_TRUE, MUSIC_SE_TRUE);			//�����������̌��ʉ���ǂݍ���
	MY_MUSIC_LOAD(&SE_FALSE, MUSIC_SE_FALSE);		//�s�������������̌��ʉ���ǂݍ���
	MY_MUSIC_LOAD(&SE_CLICK, MUSIC_SE_CLICK);		//�N���b�N�����Ƃ��̌��ʉ���ǂݍ���
	MY_MUSIC_LOAD(&SE_KETTEI, MUSIC_SE_CLICK2);		//�I�������N���b�N�����Ƃ��̌��ʉ���ǂݍ���
	MY_MUSIC_LOAD(&SE_COUNTDOWN, MUSIC_SE_COUNTDOWN);//�J�E���g�_�E���̎��̌��ʉ���ǂݍ���
	MY_MUSIC_LOAD(&BGM, MUSIC_BGM);					//BGM��ǂݍ���

	//�������[�v
	while (TRUE)
	{
		if (GameEnd_flg == TRUE)	//�I���ł͂����������Ƃ�
			break;					//�������[�v�𔲂��āA�Q�[���I��

		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		MY_ALL_KEYDOWN_UPDATE();				//�L�[�̏�Ԃ��擾

		//STATE_DRAW();							//���̕`��

		fps->Update();		//FPS�̏���[�X�V]

		//�V�[���I��
		switch (GameSceneNow)
		{
		case (int)GAME_SCENE_TITLE:	//�^�C�g����ʂ̏�����������

			MY_GAME_TITLE();	//�^�C�g����ʂ̏���

			break;	//�^�C�g����ʂ̏��������܂�

		case (int)GAME_SCENE_SETUMEI:	//������ʂ̏�����������

			MY_GAME_SETUMEI();	//������ʂ̏���

			break;	//������ʂ̏��������܂�

		case (int)GAME_SCENE_CHECK:	//�m�F��ʂ̏�����������

			MY_GAME_CHECK();	//�m�F��ʂ̏���

			break;	//�m�F��ʂ̏��������܂�

		case (int)GAME_SCENE_SET://�ݒ��ʂ̏�����������

			MY_GAME_SET();		//�ݒ��ʂ̏���

			break;	//�ݒ��ʂ̏��������܂�

		case (int)GAME_SCENE_PLAY:	//�v���C��ʂ̏�����������

			MY_GAME_PLAY();		//�v���C��ʂ̏���

			break;	//�v���C��ʂ̏��������܂�

		case (int)GAME_SCENE_RESULT:	//���U���g��ʂ̏�����������

			MY_GAME_RESULT();	//���U���g��ʂ̏���

			break;	//���U���g��ʂ̏��������܂�

		case (int)GAME_SCENE_RANKING:	//�����L���O��ʂ̏�����������

			MY_GAME_RANKING();	//�����L���O��ʂ̏���

			break;	//�����L���O��ʂ̏��������܂�

		default:

			break;

		}

		ScreenFlip();					//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		fps->Wait();					//FPS�̏���(�҂�)
	}

	//���������������������������������������� �摜�̃n���h���̍폜 ����������������������������������������
	for (int cnt = 0; cnt < NUMBER_KIND; cnt++)
	{
		DeleteGraph(Number_Image[cnt].Handle);		//���̉摜�̃n���h�����폜
	}

	for (int cnt = 0; cnt < NUMBER_KAZU; cnt++)
	{
		DeleteGraph(Num_Image.Handle);	//�񓚗p�̐��̉摜�̃n���h�����폜
	}

	for (int cnt = 0; cnt < SELECT_KIND; cnt++)
	{
		DeleteGraph(Select_Image[cnt].Handle);	//�͂��Ƃ������̑I�����摜�̃n���h�����폜
	}

	for (int cnt = 0; cnt < END_KIND; cnt++)
	{
		DeleteGraph(End_Image[cnt].Handle);	//�I���̑I�����摜�̃n���h�����폜
	}

	for (int cnt = 0; cnt < START_KIND; cnt++)
	{
		DeleteGraph(Start_Image[cnt].Handle);	//�J�n�̑I�����摜�̃n���h�����폜
	}

	for (int cnt = 0; cnt < SETUMEI_KIND;cnt++)
	{
		DeleteGraph(Setumei_Image[cnt].Handle);	//������ʂŎg�p����摜�̃n���h�����폜
	}

	for (int cnt = 0; cnt < BACKIMAGE_KIND; cnt++)
	{
		DeleteGraph(Back_Image[cnt].Handle);	//�w�i�摜�̃n���h�����폜
	}

	DeleteGraph(Setu_Image.Handle);		//������ʂŎg�p���鏬���̉摜�̃n���h�����폜
	DeleteGraph(Title_Image.Handle);	//�^�C�g���̑I�����摜�̃n���h�����폜
	
	DeleteGraph(Retire_Image.Handle);	//��߂�̉摜�̃n���h�����폜

	//�������������������������������������������� �摜�̃n���h���̍폜 ��������������������������������������������


	//�������������������������������������������� ���̃n���h���̍폜 ����������������������������������������������
	DeleteMusicMem(SE_TRUE.Handle);		//���̃n���h�����폜
	DeleteMusicMem(SE_FALSE.Handle);	//���̃n���h�����폜
	DeleteMusicMem(SE_CLICK.Handle);	//���̃n���h�����폜
	DeleteMusicMem(SE_KETTEI.Handle);	//���̃n���h�����폜
	DeleteMusicMem(SE_COUNTDOWN.Handle);//���̃n���h�����폜
	//�������������������������������������������� ���̃n���h���̍폜 ����������������������������������������������

	delete fps;				//fps��j��

	DxLib_End();		//�c�w���C�u�����g�p�̏I������

	return 0;
}


//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];			//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//########## �^�C�g����ʂ̊֐� ##########
VOID MY_GAME_TITLE(VOID)
{
	MY_INIT();		//�������֐�

	

	if (AllKeyState[KEY_INPUT_DELETE] != 0)	//�f���[�g�L�[�������ꂽ�Ă�����
	{
		Delete_flg = TRUE;
		GameSceneNow = (int)GAME_SCENE_CHECK;	//�V�[�����m�F��ʂɂ���
	}

	DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//�w�i�̕`��

	GET_MOUSE_STATE(&Start_rect[0], START_KIND);	//�}�E�X�̏����擾

	SET_START_IMAGE();		//�X�^�[�g�̑I�����̐ݒ�

	DRAW_START();			//�X�^�[�g�̑I�����̕`��

	//�������������������������������� �����̕`�� ��������������������������������������������������
	int Font = CREATE_FONT(36);	//�t�H���g�n���h���쐬
	char Str_Ranking[128] = { "��Delete�L�[�������ƃ����L���O�������Z�b�g�ł��܂�" };

	DrawStringToHandle(0,
		0,
		&Str_Ranking[0],
		GetColor(255, 0, 0),
		Font);

	DeleteFontToHandle(Font);	//�t�H���g�n���h���폜
	//���������������������������������� �����̕`�� ��������������������������������������������������

	//�������������������� �^�C�g���̕`�� ��������������������
	Title_Image.X = GAME_WIDTH / 2 - Title_Image.C_Width;		//�`��ʒu����
	Title_Image.Y = GAME_HEIGHT / 2 - Title_Image.C_Height;		//�`��ʒu����

	DrawGraph(Title_Image.X, Title_Image.Y, Title_Image.Handle, TRUE);	//�^�C�g���摜�̕`��

	//�������������������� �^�C�g���̕`�� ��������������������

	//�̈���ŃN���b�N���ꂽ��
	if (Mouse_Date.Mouse_hover_flg == TRUE &&
		Mouse_Date.Mouse_LeftClick_flg == TRUE)
	{
		//�}�E�X���ǂ̉摜���N���b�N����������
		CHECK_GAME_START(Mouse_Date.Mouse_Click_Num);
	}

	return;
}

//########## ������ʂ̊֐� ############
VOID MY_GAME_SETUMEI(VOID)
{

	//BGM������Ă��Ȃ��Ƃ�
	if (CheckSoundMem(BGM.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 30 / 100, BGM.Handle);	//BGM�̉��ʂ�50���ɂ���
		PlaySoundMem(BGM.Handle, DX_PLAYTYPE_LOOP);			//BGM�𗬂�
	}

	GET_MOUSE_STATE(&Setu_rect, 1);	//�}�E�X�̏����擾

	DRAW_BACKIMAGE(&Setumei_Image[Setu_Now]);	//���x�������̕`��

	if (Setu_Now == BACKIMAGE_SETULEVEL)	
	{
		//�������������������������������� �����̕`�� ��������������������������������������������������
		SET_END_SETU();		//�����Ŏg�p���鏬���i���Ȃǁj�̐ݒ�

		DRAW_SETU();	//�����Ŏg�p���鏬���i���Ȃǁj�̕`��
		//���������������������������������� �����̕`�� ��������������������������������������������������


		if (Mouse_Date.Mouse_hover_flg == TRUE && 
			Mouse_Date.Mouse_LeftClick_flg == TRUE)	//���x�������i�K�ŃN���b�N���ꂽ��A
		{
			Setu_Now = BACKIMAGE_SETUPLAY;	//�����i�K���v���C��ʂɕύX
		}
	} 
	else if (Setu_Now == BACKIMAGE_SETUPLAY)
		{
			
		//�������������������������������� �����̕`�� ��������������������������������������������������
		SET_END_SETU();		//�����Ŏg�p���鏬���i���Ȃǁj�̐ݒ�

		DRAW_SETU();	//�����Ŏg�p���鏬���i���Ȃǁj�̕`��
		//���������������������������������� �����̕`�� ��������������������������������������������������
			
			if (Mouse_Date.Mouse_hover_flg == TRUE && 
				Mouse_Date.Mouse_LeftClick_flg == TRUE)	//�v���C�����i�K�ŃN���b�N���ꂽ��A
			{
				GameSceneNow = GAME_SCENE_CHECK;	//�m�F��ʂɕύX
			}
		}

}

//########## �m�F��ʂ̊֐� ################
VOID MY_GAME_CHECK(VOID)
{
	if (Setumei_flg == TRUE)	//�����t���O�������Ă�����
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 40);     //�w�i���Â�����
		DRAW_BACKIMAGE(&Setumei_Image[Setu_Now]);	//�w�i�̕`��
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);     //�u�����h���[�h�����Z�b�g����B
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 40);     //�w�i���Â�����
		DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//�w�i�̕`��
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);     //�u�����h���[�h�����Z�b�g����B
	}
	
	//�I����I�񂾎��̏���
	GET_MOUSE_STATE(&Select_rect[0], SELECT_KIND);	//�}�E�X�̏����擾

	SET_SELECT_IMAGE();		//�͂��Ƃ������̉摜�̐ݒ�

	DRAW_SELECT();			//�͂��Ƃ������̉摜�̕`��

	//�����`��
	if (Delete_flg == TRUE)	//�f�[�^�폜�t���O�������Ă�����A
	{
		int Font = CREATE_FONT(60);	//�t�H���g�n���h���쐬
		char Str_Time[128] = { 0 };

		sprintf(&Str_Time[0], "�f�[�^���폜���Ă�낵���ł����H\n���S�Ă̓�Փx�̃f�[�^�������܂�");

		int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Time[0]);	//�f�t�H���g�̃t�H���g�̉������擾

		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			80,
			&Str_Time[0],
			GetColor(255, 0, 0),
			Font);	//�m�F�����̕`��

		DeleteFontToHandle(Font);	//�t�H���g�n���h���폜

	}
	else if (End_flg == TRUE || Retire_flg == TRUE)
	{
		int Font = CREATE_FONT(64);	//�t�H���g�n���h���쐬
		char Str_Time[128] = { 0 };

		sprintf(&Str_Time[0], "�Q�[�����I�����܂����H");

		int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Time[0]);	//�f�t�H���g�̃t�H���g�̉������擾

		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			150,
			&Str_Time[0],
			GetColor(255, 255, 255),
			Font);	//�m�F�����̕`��

		DeleteFontToHandle(Font);	//�t�H���g�n���h���폜

	}
	else if (Setumei_flg == TRUE)	//�����t���O�������Ă�����
	{
		int Font = CREATE_FONT(60);	//�t�H���g�n���h���쐬
		char Str_Time[128] = { 0 };

		sprintf(&Str_Time[0], "�������I�����Ă���낵���ł����H");

		int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Time[0]);	//�f�t�H���g�̃t�H���g�̉������擾

		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			150,
			&Str_Time[0],
			GetColor(255, 0, 0),
			Font);	//�m�F�����̕`��

		DeleteFontToHandle(Font);	//�t�H���g�n���h���폜
	}

	//�̈���ŃN���b�N���ꂽ��
	if (Mouse_Date.Mouse_hover_flg == TRUE &&
		Mouse_Date.Mouse_LeftClick_flg == TRUE)
	{
		//�}�E�X���ǂ̉摜���N���b�N����������
		if (CHECK_SELECT(Mouse_Date.Mouse_Click_Num) == TRUE)	//�͂����N���b�N�����ꍇ
		{
			Yes_flg = TRUE;	//�͂��̃t���O
		}
		else
		{
			No_flg = TRUE;		//�������̃t���O
		}
	}

	//�͂��A���������A���ŏ�����ς���
	if (Yes_flg == TRUE)
	{
		//�������������������������������� �f�[�^�폜���� ��������������������������������
		if (Delete_flg == TRUE)	//�Z�[�u�f�[�^�폜�t���O�������Ă�����A
		{
			//�Z�[�u�f�[�^�폜�̏���
			DELETE_DATA(SaveData[0]);		//�ȒP�A�̃f�[�^�폜
			Delete_flg = FALSE;		//�폜�t���O�����Z�b�g
			Yes_flg = FALSE;

			GameSceneNow = (int)GAME_SCENE_TITLE;//�Q�[���V�[�����^�C�g����ʂɕς���

		}
		//������������������������������ �f�[�^�폜���� ��������������������������������
		else if (Setumei_flg == TRUE)	//�����t���O�������Ă�����
		{
			Yes_flg = FALSE;
			GameSceneNow = (int)GAME_SCENE_TITLE;//�Q�[���V�[�����^�C�g����ʂɕς���
		}
		else
		{
			GameEnd_flg = TRUE;	//�Q�[���I���t���O�𗧂Ă�
			Yes_flg = FALSE;
		}

	}
	else if (No_flg == TRUE)
	{
	 if (Setumei_flg == TRUE)	//�����t���O�������Ă�����A
		{
			Setu_Now = BACKIMAGE_SETULEVEL;//�����i�K�����x���ɂ���
			No_flg = FALSE;
			GameSceneNow = (int)GAME_SCENE_SETUMEI;	//������ʂɂ���
		}
	 else if (Retire_flg == TRUE)	//���^�C�A�t���O�������Ă�����
	 {
		 GameSceneNow = (int)GAME_SCENE_PLAY;//�Q�[���V�[�����v���C��ʂɕς���
		 LostTimeEnd = GetNowCount();			//���f���Ԃ��J�E���g�I��
		 LostTime = LostTimeEnd - LostTimeStart;	//���f���Ԃ��v�Z
		 StartTime += LostTime;					//���f���Ă������Ԃ��v���X����
		 No_flg = FALSE;
	 }
	 else
	 {
		 GameSceneNow = (int)GAME_SCENE_TITLE;//�Q�[���V�[�����^�C�g����ʂɕς���
		 No_flg = FALSE;
	 }

	}

	return;
}

//########## �ݒ��ʂ̊֐� ############
VOID MY_GAME_SET(VOID)
{
	//���̏�����
	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{
		Number_Image[cnt].Num_flg = FALSE;	//��肪�����Ă��邩�ǂ����̃t���O��������
		Number_Image[cnt].Positon_flg = FALSE;
		Number_Image[cnt].IsDraw = TRUE;
		Number_Image[cnt].SetIsDraw_flg = FALSE;
		Number_Image[cnt].X = 0;
		Number_Image[cnt].Y = 0;
	}

	SetLevel();			//�Q�[�����x���������_���ɕύX

	RESET_MOUSE_DATE();	//�}�E�X��񃊃Z�b�g

	MY_CREATE_QUESTION();	//���𐶐�

	True_flg = FALSE;	//�����t���O�����Z�b�g
	False_flg = FALSE;	//�s�����t���O�����Z�b�g

	DrawTime = 0;		//�`�掞��0�b

	DrawStartTime = GetNowCount();	//�`��J�n���Ԏ擾

	if (Q_Sum == 0)	//�ŏ��̏����̎������A�v���J�n���Ԃ�ݒ�
	{
		StartTime = GetNowCount();	//�v���J�n
	}

	NokoriTime = (LimitTime - (GetNowCount() - StartTime) / 1000);	//�c�莞�Ԃ̍X�V

	SET_ANSER_NUM();		//�񓚗p�̐����̐ݒ������֐�

	BackImageNow = BACKIMAGE_PLAY;	//�w�i�摜�̎�ނ��v���C��ʂɕύX

	if (First_flg == FALSE)	//�ŏ��̓Q�[���J�n�̃J�E���g�_�E����`�悷�邽�߁A
	{
		DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//�w�i�̕`��

		DRAW_QUESTION();		//����`��

		DRAW_TIME();			//�c�莞�Ԃ̕`��

		DRAW_ANSER_NUM();		//�񓚗p�̑I������`��

		Draw_Retire();			//�u��߂�v�̕`��
	}

	GameSceneNow = (int)GAME_SCENE_PLAY;	//�v���C��ʂɂ���

}

//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{
	DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//�w�i�̕`��

	DRAW_ANSER_NUM();		//�񓚗p�̑I������`��

	//������������������������������������ �Q�[���J�n�̃J�E���g�_�E���i3�b�j���s������ ��������������������������������������
	if (First_flg == TRUE)
	{

		if (CountDownStart_flg == FALSE)	//�J�E���g�_�E���̉���炷
		{
			CountDownStart_flg = TRUE;	//�J�E���g�_�E���X�^�[�g
			ChangeVolumeSoundMem(255 * 80 / 100, SE_COUNTDOWN.Handle);	//SE�̉��ʂ�50���ɂ���
			PlaySoundMem(SE_COUNTDOWN.Handle, DX_PLAYTYPE_BACK);		//�J�E���g�_�E���̉���炷
		}

		LimitTime = 3;		//�J�E���g�_�E���̎��Ԃ�ݒ�
		NokoriTime = (LimitTime - (GetNowCount() - StartTime) / 1000);	//�c�莞�Ԃ̍X�V

		DRAW_WAIT_TIME(NokoriTime);	//���Ԃ̕`��

			//3�b��������A�Q�[���X�^�[�g
			if (NokoriTime <= 0)
			{
				StartTime = GetNowCount();	//�X�^�[�g���Ԃ����Z�b�g
				LimitTime = GAMETIME;				//�������Ԃ��Q�[���̎��Ԃɐݒ�
				First_flg = FALSE;			//�ŏ��̃t���O
			}
	}
	//���������������������������������������� �Q�[���J�n�̃J�E���g�_�E���i3�b�j���s������ ����������������������������������������
	
	//������������������������������������ �Q�[����ʂ̏��� ��������������������������������������
	else
	{
		NokoriTime = (LimitTime - (GetNowCount() - StartTime) / 1000);	//�c�莞�Ԃ̍X�V

	//30�b��������A���U���g��ʂɐ؂�ւ���
		if (NokoriTime <= 0)
		{
			GameSceneNow = (int)GAME_SCENE_RESULT;
		}

		DRAW_QUESTION();		//����`��

		DRAW_TIME();			//�c�莞�Ԃ̕`��

		Draw_Retire();			//�u��߂�v�̕`��

		GetMousePoint(&Mouse_Date.X, &Mouse_Date.Y);	//�}�E�X�̍��W���擾

		if (Mouse_Date.Y < GAME_HEIGHT / 3)			//�}�E�X�̍��W����ʂ�1/3���ゾ������
		{
			GET_MOUSE_STATE(&Retire_rect, 1);	//�}�E�X�̏����擾(��߂�̉摜����)

		//�u��߂�v���N���b�N���ꂽ��
			if (Mouse_Date.Mouse_LeftClick_flg == TRUE &&
				Mouse_Date.Mouse_hover_flg == TRUE)
			{
				Retire_flg = TRUE;							//���^�C�A�t���O
				LostTimeStart = GetNowCount();			//���f���Ԃ��J�E���g�X�^�[�g
				GameSceneNow = (int)GAME_SCENE_CHECK;		//�m�F��ʂ֕ύX
			}
		}

		

		RESET_MOUSE_DATE();	//�}�E�X��񃊃Z�b�g

		GET_MOUSE_STATE(&A_num[0], RECT_CNT);	//�}�E�X�̏����擾

		//�̈�����N���b�N���ꂽ��
		if (Mouse_Date.Mouse_LeftClick_flg == TRUE &&
			Mouse_Date.Mouse_hover_flg == TRUE)
		{
			GET_PLAYER_ANSER(Mouse_Date.Mouse_Click_Num);	//�v���C���[�̉񓚂��������s����������

		}
	}
	//���������������������������������������� �Q�[����ʂ̏��� ����������������������������������������
	
	return;
	
}

//########## ���U���g��ʂ̊֐� #########
VOID MY_GAME_RESULT(VOID)
{
	BackImageNow = BACKIMAGE_RESULT;	//�w�i�摜�̎�ނ����U���g��ʂɕύX

	DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//�w�i�̕`��

	DRAW_RESULET();//���ʂ̕`��

	GET_MOUSE_STATE(&End_rect[0], END_KIND);	//�}�E�X�̏����擾

	if (Write_flg == FALSE)	//�Z�[�u�f�[�^�̏������݂��s���Ă��Ȃ�������
	{
		GET_DATEDATA();				//���ݎ����̎擾
		WRITE_SAVEDATA(True_Kazu);	//�Z�[�u�f�[�^�̏�������
		Write_flg = TRUE;			//�������݃t���O�𗧂Ă�
		WaitTime_flg = TRUE;		//���Ԃ�҂��߂̃t���O�𗧂Ă�
		StartTime = GetNowCount();	//�v���J�n
	}

	//������������������������������ 3�b��������A�����I�Ƀ����L���O��ʂɕύX���鏈�� ������������������������������
	if (WaitTime_flg == TRUE)
	{
		LimitTime = 3;		//�J�E���g�_�E���̎��Ԃ�ݒ�
		NokoriTime = (LimitTime - (GetNowCount() - StartTime) / 1000);	//�c�莞�Ԃ̍X�V

		DRAW_WAIT_TIME(NokoriTime);	//���Ԃ̕`��

		//3�b��������A�����L���O��ʂɕύX
		if (NokoriTime <= 0)
		{
			StartTime = GetNowCount();	//�X�^�[�g���Ԃ����Z�b�g
			WaitTime_flg = FALSE;		//���Ԃ�҂��߂̃t���O
			GameSceneNow = (int)GAME_SCENE_RANKING;	//�Q�[���V�[���������L���O��ʂ�
		}
	}
	//������������������������������ 3�b��������A�����I�Ƀ����L���O��ʂɕύX���鏈�� ������������������������������

	return;
}

//########## �����L���O��ʂ̊֐� ########
VOID MY_GAME_RANKING(VOID)
{
	RESET_MOUSE_DATE();	//�}�E�X���̃��Z�b�g

	GET_MOUSE_STATE(&End_rect[0], END_KIND);	//�}�E�X�̏����擾

	DRAW_BACKIMAGE(&Back_Image[BackImageNow]);	//�w�i�̕`��

	//�Z�[�u�f�[�^���\�[�g���ēǂݍ���
	if (Sort_flg == FALSE)
	{

		SORT_SAVEDATA(SaveData);		//�Z�[�u�f�[�^��ǂݍ���ŁA�~���ɕ��ёւ���
		Sort_flg = TRUE;				//�\�[�g�t���O�𗧂Ă�
	}

		//"�����L���O"�̕����̕`��
		int Font = CREATE_FONT(100);	//�t�H���g�n���h���쐬
		char Str_Ranking[128] = { "�����L���O" };

		int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Ranking[0]);	//�f�t�H���g�̃t�H���g�̉������擾

		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			0,
			&Str_Ranking[0],
			GetColor(255, 0, 0),
			Font);	//�����L���O�̕`��

		DeleteFontToHandle(Font);	//�t�H���g�n���h���폜



		//��Փx���Ƃɏ����𕪂���
		for (int cnt = 0; cnt < RANKING_NUM; cnt++)
		{
			DRAW_RANKING(SaveData[cnt], cnt);	//�Z�[�u�f�[�^�̕`��

		}

		SET_END_IMAGE();	//�I���̑I�����̐ݒ�

		DRAW_END_IMAGE();	//�I���̑I�����̕`��

		//�̈���ŃN���b�N���ꂽ��
		if (Mouse_Date.Mouse_hover_flg == TRUE &&
			Mouse_Date.Mouse_LeftClick_flg == TRUE)
		{
			//�Q�[���I�����A�Q�[�����s������
			CHECK_GAME_CONTINUE(Mouse_Date.Mouse_Click_Num);
		}

}

//########## �������f�t�H���g�t�H���g�ɐݒ肷��֐� ##########
//���@���FBOOL�F�A���`�G�C���A�X������
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL anti)
{
	//�f�t�H���g�͈ȉ��̃t�H���g�T�C�Y�ł���ƁA�ݒ肷��
	ChangeFont("MS �S�V�b�N", DX_CHARSET_DEFAULT);
	SetFontSize(16);

	if (anti)
	{
		ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	}
	return;
}
//########## �t�H���g�n���h�����쐬����֐� #############
int CREATE_FONT(int size)
{
	int Font;
	Font = CreateFontToHandle("�l�r �S�V�b�N", size, FONT_BOLD, DX_FONTTYPE_ANTIALIASING_EDGE);
	return Font;
}

//########## ��ʒ����ɕ�����`�悷��֐� ##########
//���@���Fchar [][]�F�\�����镶����̐擪�A�h���X
//���@���Fint�@ �@ �F�\������s��
//���@���Fchar *�@ �F�t�H���g�̖��O
//���@���Fint�@ �@ �F�����̑傫��
//�߂�l�F�Ȃ�
VOID MY_DRAW_STRING_CENTER_CENTER(char str[][128], int row, char *fontname, int size)
{
	ChangeFont(fontname, DX_CHARSET_DEFAULT);		//�f�t�H���g�̃t�H���g��ύX����
	SetFontSize(size);								//�f�t�H���g�̃t�H���g�T�C�Y��ς���
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);	//�t�H���g�����ꂢ�ɂ݂���

	int StrHeightSum = 0;
	for (int sum = 0; sum < row; sum++)	//�s�S�̂̍������W�v
	{
		StrHeightSum += GetFontSize();	//�f�t�H���g�̃t�H���g�̍������擾
	}

	for (int rCnt = 0; rCnt < row; rCnt++)	//�t�H���g��`��
	{
		int StrWidth = GetDrawFormatStringWidth(&str[rCnt][0]);	//�f�t�H���g�̃t�H���g�̉������擾
		int StrHeight = GetFontSize();

		DrawFormatString(
			GAME_WIDTH / 2 - StrWidth / 2,
			GAME_HEIGHT / 2 - StrHeightSum + StrHeight * rCnt,	//��ʂ̒��S�@-�@�s�S�̂̕����̍����@+�@�P�s�̍���
			GetColor(255, 0, 0), &str[rCnt][0]);			//�f�t�H���g�̃t�H���g�ŕ`��
	}

	MY_DRAW_SET_DEFAULT_FONT(TRUE);	//�f�t�H���g�t�H���g�ɐݒ肷��

	return;

}

//########## �摜��ǂݍ��ސݒ������֐� ##########

//���@���F�摜�\���́@�F�ݒ肷��摜�\���̂̕ϐ�
//���@���Fint�@�F�摜�̉��̈ʒu
//���@���Fint�@�F�摜�̏c�̈ʒu
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_GAZOU_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);					//�t�@�C���p�X���R�s�[
	g->Handle = LoadGraph(g->FilePath);				//�摜���������ɓǂݍ��݁A�n���h�����擾

	if (g->Handle == -1) { return FALSE; }			//�摜�ǂݍ��݃G���[

	GetGraphSize(g->Handle, &g->Width, &g->Height);	//�摜�T�C�Y���擾
	g->X = x;
	g->Y = y;
	g->C_Width = g->Width / 2;						//�摜�̉��T�C�Y�̒��S���擾
	g->C_Height = g->Height / 2;					//�摜�̏c�T�C�Y�̒��S���擾

	return TRUE;

}

//########## ���𐶐�����֐� ##################
VOID MY_CREATE_QUESTION(VOID)
{

	int num = 0;			//������������������p�̕ϐ�
	
	
	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{

		Number_Image[cnt].Direction = GetRand(DIRECTION_KIND - 1);	//�ړ������𗐐��Ō��߂�

		//������������������ ���̍��W�𐶐� ������������������
		num = GetRand(Q_ERIA_WIDTH);		//����`�悷��X���W����ʓ��̒l�Ő���

		if ((num + FONT_SIZE) > 150 &&
			num < (Q_ERIA_WIDTH - Number_Image[cnt].Width))
		{
			Number_Image[cnt].X = num;		//����x���W�ɑ��
		}
		else
		{
			cnt--;
			continue;
		}

		num = GetRand(Q_ERIA_HEIGHT);		//����`�悷��Y���W����ʓ��̒l�Ő���

		if (num > Time_Draw_Y + 130 &&
			num < (Q_ERIA_HEIGHT - Number_Image[cnt].Height))
		{
			Number_Image[cnt].Y= num;		//����y���W�ɑ��
		}
		else
		{
			cnt--;
			continue;
		}
		//�������������������� ���̍��W�𐶐� ��������������������


		//���̗̈��ݒ�
		RECT_SETTING(&Q_rect[cnt],
			Number_Image[cnt].X,
			Number_Image[cnt].Y,
			Number_Image[cnt].Width,
			Number_Image[cnt].Height);

		Number_Image[cnt].Positon_flg = TRUE;		//���W�ݒ芮���̃t���O

		//�������������������� ���̗̈悪����Ă��邩���� ��������������������
		for (int cnt_r = 0;cnt_r < cnt; cnt_r++)
		{
			if (MY_CHECK_RECT_ATARI(Q_rect[cnt], Q_rect[cnt_r]) == TRUE)		//�̈悪����Ă�����
			{
				cnt--;												//cnt�̒l���}�C�i�X���āA���W��ݒ肵�Ȃ���
				Number_Image[cnt + cnt_r].Positon_flg = FALSE;		//���W�ݒ�̃t���O��FALSE�ɂ���
				break;
			}
		}
		//���������������������� ���̗̈悪����Ă��邩���� ������������������������

	}
	



	//������������������ ���𐶐� ������������������
	for (int cnt = 0; cnt < QUESTION_KAZU - 1;)
	{

		num = GetRand(QUESTION_KAZU - 1);		//0�`9�܂ł̊Ԃŗ����𐶐�

		if (Number_Image[num].Num_flg != TRUE)		//���p�̔z��ɗ����Ő������������������Ă��Ȃ������ꍇ
		{
			Number_Image[num].Num_flg = TRUE;		//�t���O�𗧂Ă�
			int num2 = GetRand(REVERSE_TYPE);		//0,1�̂ǂ��炩�ŗ����𐶐�
			Number_Image[num].Reverse_flg = num2;	//���]�����邩�ǂ���
			Number_Image[num].Color = GetRand(360);	//�F�ݒ�
			CHENGE_COLOR(Number_Image[num].Handle,Number_Image[num].Color);//�F�ύX
			Number_Image[num].IsDraw = TRUE;		//�`�悵�Ă悢
			cnt++;								//cnt���C���N�������g
		}
		
	}
	Flashing_flg = GetRand(1);				//�_�Ńt���O
	//�������������������� ���𐶐� ��������������������
}

//**********�������֐�**************
BOOL MY_INIT(VOID)
{

	_mkdir(GAME_DATA);	//�Z�[�u�f�[�^������t�H���_���쐬

	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{
		Number_Image[cnt].Num_flg = FALSE;	//��肪�����Ă��邩�ǂ����̃t���O��������
		Number_Image[cnt].Positon_flg = FALSE;
		Number_Image[cnt].IsDraw = FALSE;	//�ŏ��͕`�悵�Ă͂����Ȃ�
		Number_Image[cnt].SetIsDraw_flg = FALSE;
		Number_Image[cnt].X = 0;
		Number_Image[cnt].Y = 0;
	}

	RESET_MOUSE_DATE();		//�}�E�X�������Z�b�g

	Q_Sum = 0;		//��萔��������
	True_Kazu = 0;	//���𐔂�������
	Player_Anser = 0;//�v���C���[�̉񓚂�������

	StartTime = 0;	//�v�����Ԃ�������
	NokoriTime = 0;	//�c�莞�Ԃ�������
	LimitTime = GAMETIME;//�������Ԃ̐ݒ�

	SaveNowCnt = 0;	
	SaveMaxNum = 0;
	SaveMinNum = 0;

	BackImageNow = BACKIMAGE_TITLE;	//�w�i�摜�̎�ނ�������
	Setu_Now = BACKIMAGE_SETULEVEL;//�����i�K�����x���ɂ���

	//�t���O�֘A��������
	True_flg = FALSE;								
	False_flg = FALSE;								
	End_flg = FALSE;								
	Continue_flg = FALSE;
	Write_flg = FALSE;				//�f�[�^�̏������݂������ǂ����̃t���O
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

//############ �v���C���[�̉񓚂��擾���A�������s���������肷��֐� ############
VOID GET_PLAYER_ANSER(int num)
{
	Player_Anser = 0;	//�v���C���[�̉񓚂�����ϐ���������

	Player_Anser = num;	//�v���C���[�̉񓚂�ϐ��ɓ����

	//�������������������������� �v���C���[�̉񓚂����������肷�� ����������������������������������
	if (Number_Image[Player_Anser].Num_flg == FALSE)	//�v���C���[�̉񓚂�������������A
	{
		True_flg = TRUE;		//�����t���O

		ChangeVolumeSoundMem(255 * 50 / 100, SE_TRUE.Handle);	//SE�̉��ʂ�50���ɂ���
		PlaySoundMem(SE_TRUE.Handle, DX_PLAYTYPE_BACK);	//�����̌��ʉ���炷

		RESET_MOUSE_DATE();
	}
	else if (Number_Image[Player_Anser].Num_flg == TRUE)//�v���C���[�̉񓚂��s������������A
	{
		False_flg = TRUE;		//�s�����t���O

		ChangeVolumeSoundMem(255 * 50 / 100, SE_FALSE.Handle);	//SE�̉��ʂ�50���ɂ���
		PlaySoundMem(SE_FALSE.Handle, DX_PLAYTYPE_BACK);	//�s�����̌��ʉ���炷

		RESET_MOUSE_DATE();
	}

	//�������s�������ŏ�����ς���
	if (True_flg == TRUE)	//�����̏ꍇ
	{
		True_Kazu++;		//���𐔂��v���X
		Q_Sum++;			//��葍�����v���X
		LimitTime += 1;		//�c�莞�Ԃ𑝂₷
		GameSceneNow = (int)GAME_SCENE_SET;	//�Q�[���V�[����ݒ��ʂɕύX
	}
	else if (False_flg == TRUE)	//�s�����̏ꍇ
	{
		Q_Sum++;			//��葍�����v���X
		LimitTime -= 1;		//�c�莞�Ԃ����炷
		GameSceneNow = (int)GAME_SCENE_SET;	//�Q�[���V�[����ݒ��ʂɕύX
	}
	//�������������������������� �v���C���[�̉񓚂����������肷�� ����������������������������������

	return;

}

//############ �̈�̐ݒ������֐� ############
VOID RECT_SETTING(RECT *rect,int x,int y,int width,int height)
{
	rect->left = x;
	rect->top = y;
	rect->right = x + width;
	rect->bottom = y + height;
}

//############ �̈������������֐� ############
VOID RECT_RESET(RECT *a)
{
	//�摜�̗̈�̏�����
		a->left = 0;	//�摜�̍���(X)
		a->top = 0;	//�摜�̍���(Y)
		a->right = 0;	//�摜�̉E��(X)
		a->bottom = 0;//�摜�̉E��(Y)

}

//########## �̈�̓����蔻�������֐� ##########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left<b.right&&
		a.top<b.bottom&&
		a.right>b.left&&
		a.bottom>b.top)
	{
		return TRUE;	//�������Ă���
	}

	return FALSE;		//�������ĂȂ�

}

//########### �}�E�X�̏����擾����֐� ############
VOID GET_MOUSE_STATE(RECT *rect ,int num)
{
	GetMousePoint(&Mouse_Date.X, &Mouse_Date.Y);	//�}�E�X�̍��W���擾

	Mouse_Date.Mouse_Input = GetMouseInput();		//�}�E�X�̃N���b�N�����擾

		//�}�E�X���摜�̗̈�����ǂ�������
	for (int cnt = 0; cnt < num; cnt++)
	{
		if (CHECK_RECT_ATARI(rect[cnt], Mouse_Date) == TRUE)	//�}�E�X���摜�̗̈���������Ƃ�
		{
			Mouse_Date.Mouse_hover_flg = TRUE;
			break;
		}
		else	//�}�E�X���摜�̗̈�O��������
		{
			Mouse_Date.Mouse_hover_flg = FALSE;
		}
	}
	

	//�������������������� �}�E�X���N���b�N�������̏��� ��������������������

	//���N���b�N���ꂽ��
	if ((Mouse_Date.Mouse_Input & MOUSE_INPUT_LEFT)!= 0)
	{
		Mouse_Date.Mouse_Click_Cnt++;	//�}�E�X��������Ă���ԃJ�E���g����
	}
	else
	{
		Mouse_Date.Mouse_Click_Cnt = 0;	//�}�E�X�̃J�E���g�����Z�b�g
	}

	//�}�E�X���N���b�N�����u�Ԃ����A�t���O�𗧂Ă�
	if (Mouse_Date.Mouse_Click_Cnt == 1)
	{
		if (Mouse_Date.Mouse_hover_flg != TRUE)	//�I�����ȊO�̏ꏊ�ŃN���b�N���ꂽ��
		{
			ChangeVolumeSoundMem(255 * 80 / 100, SE_CLICK.Handle);	//SE�̉��ʂ�50���ɂ���
			PlaySoundMem(SE_CLICK.Handle, DX_PLAYTYPE_BACK);	//�N���b�N�̌��ʉ���炷
		}
		Mouse_Date.Mouse_LeftClick_flg = TRUE;//�N���b�N�t���O
	}
	else
	{
		Mouse_Date.Mouse_LeftClick_flg = FALSE;//�N���b�N�t���O
	}

	//�}�E�X���摜�̗̈�����ǂ������擾
	//�}�E�X���̈���ŃN���b�N���ꂽ���m�F
	for (int cnt = 0; cnt < num; cnt++)
	{
		if (CHECK_RECT_ATARI(rect[cnt], Mouse_Date) == TRUE)	//�}�E�X���摜�̗̈���������Ƃ�
		{
			//�̈���ŃN���b�N���ꂽ��
			if (Mouse_Date.Mouse_hover_flg == TRUE &&
				Mouse_Date.Mouse_LeftClick_flg == TRUE)
			{
				if (GameSceneNow != GAME_SCENE_PLAY)	//�v���C���ȊO��
				{
					ChangeVolumeSoundMem(255 * 80 / 100, SE_KETTEI.Handle);	//SE�̉��ʂ�50���ɂ���
					PlaySoundMem(SE_KETTEI.Handle, DX_PLAYTYPE_BACK);	//�N���b�N�̌��ʉ���炷
				}
				
				Mouse_Date.Mouse_Click_Num = cnt;		//�}�E�X���N���b�N���ꂽ�摜�̔ԍ����擾
				break;
			}
		}

	}
	//�������������������� �}�E�X���N���b�N�����Ƃ��̏��� ��������������������

	return;

}

//########### �}�E�X�̏������Z�b�g����֐� ###########
VOID RESET_MOUSE_DATE(VOID)
{
	Mouse_Date.Mouse_Click_Num = -1;	//�N���b�N�����̈�̔ԍ���������
	Mouse_Date.Mouse_hover_flg = FALSE;	//�z�o�[�t���O�����Z�b�g
	Mouse_Date.Mouse_LeftClick_flg = FALSE;//���N���b�N�̏������Z�b�g
	return;
}

//############# �}�E�X���摜�̗̈�����ǂ������f����֐� ##################
BOOL CHECK_RECT_ATARI(RECT a, MOUSE b)
{
	if (a.left < b.X && 
		a.top < b.Y &&
		a.right > b.X &&
		a.bottom > b.Y)
	{
		return TRUE;	//�������Ă���
	}

	return FALSE;		//�������ĂȂ�
}

//############# ����`�悷��֐� #############
VOID STATE_DRAW(VOID)
{
	//������������������������ �}�E�X�̏���`�� ��������������������������

	DrawFormatString(0, 20, GetColor(255, 255, 255), "�}�E�XX:%d", Mouse_Date.X);	//�}�E�X��X���W
	DrawFormatString(0, 40, GetColor(255, 255, 255), "�}�E�XY:%d", Mouse_Date.Y);	//�}�E�X��Y���W

	if (Mouse_Date.Mouse_hover_flg == TRUE)//�}�E�X���摜�̗̈���ɂ���Ƃ�
	{
		DrawString(0, 60, "�}�E�X�z�o�[�t���O:ON", GetColor(255, 255, 255));				//�}�E�X�z�o�[�t���O�̕`��
	}
	else
	{
		DrawString(0, 60, "�}�E�X�z�o�[�t���O:OFF", GetColor(255, 255, 255));				//�}�E�X�z�o�[�t���O�̕`��
	}

	//�̈���ŃN���b�N���ꂽ��
	if (Mouse_Date.Mouse_hover_flg == TRUE &&
		Mouse_Date.Mouse_LeftClick_flg == TRUE)
	{
		DrawString(0, 80, "���N���b�N����܂���", GetColor(255, 255, 255));
	}

	//DrawFormatString(0, 120, GetColor(255, 255, 255), "����:%d", True_Kazu);				//���𐔂̕`��
	//DrawFormatString(0, 140, GetColor(255, 255, 255), "�s����:%d", Q_Sum - True_Kazu);	//�s���𐔂̕`��

	
	//�������������������������� �}�E�X�̏���`�� ����������������������������������

	if (GameSceneNow == (int)GAME_SCENE_PLAY)
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "�c��%d�b", 30 - (GetNowCount() - StartTime) / 1000);//�c�莞�Ԃ̕`��
	}

	return;
}

//############ �X�^�[�g�̑I������`�悷��֐� ##############
VOID DRAW_START(VOID)
{
	for (int num = 0; num < START_KIND; num++)
	{
		DrawGraph(
			Start_Image[num].X,
			Start_Image[num].Y,
			Start_Image[num].Handle, FALSE);	//�摜�`��

	}
}

//############ �͂��Ƃ������̉摜��`�悷��֐� ############
VOID DRAW_SELECT(VOID)
{
	for (int num = 0; num < SELECT_KIND; num++)
	{
		DrawGraph(
			Select_Image[num].X,
			Select_Image[num].Y,
			Select_Image[num].Handle, FALSE);	//�摜�`��

	}

}

//############ �������Ɏg�p���鏬���i���Ȃǁj��`�悷��֐� ############
VOID DRAW_SETU(VOID)
{
		DrawGraph(
			Setu_Image.X,
			Setu_Image.Y,
			Setu_Image.Handle, FALSE);	//�摜�`��

}

//############ ����`�悷��֐� #############
VOID DRAW_QUESTION(VOID)
{
	int rote = 1;	//��]�p�x

	DrawTime = (GetNowCount() - DrawStartTime) / 1000;	//�`�掞�Ԃ̍X�V

	for (int cnt = 0; cnt < QUESTION_KAZU; cnt++)
	{
		if (Number_Image[cnt].Num_flg == TRUE)
		{
			switch (Game_Level_Now)
			{
			case (int)GAME_LEVEL_EASY:	//��Փx���񂽂�̏���

				if (Flashing_flg)	//�_�Ńt���O�������Ă����
				{
					DRAW_FLASHING(cnt);		//�_�ŕ`��
				}

				if (Number_Image[cnt].IsDraw)		//�`�悵�Ă悢��
				{
					if (Number_Image[cnt].Reverse_flg)	//���]�t���O�������Ă���Ƃ�
					{
						DrawTurnGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE); //���E���]�`��
					}
					else
					{
						DrawGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE);	//����`��
					}
				}

				break;

			case (int)GAME_LEVEL_NORMAL:	//��Փx���ʂ̏���

				//��]�p�x�̏���
				if (cnt % 2 == 0)		//�����̎�
				{
					rote = cnt + 2;			//�E��]
				}
				else if (cnt % 2 == 1)	//��̎�
				{
					rote = -cnt + 2;		//����]
				}

				if (Flashing_flg)	//�_�Ńt���O�������Ă����
				{
					DRAW_FLASHING(cnt);		//�_�ŕ`��
				}

				if (Number_Image[cnt].IsDraw)		//�`�悵�Ă悢��
				{
					//�p�x��ς��ĕ`��
					DrawRotaGraph(Number_Image[cnt].X + Number_Image[cnt].C_Width,
						Number_Image[cnt].Y + Number_Image[cnt].C_Height,
						EXPANSION,	//�g�嗦
						PI / rote,	//��]�p�x
						Number_Image[cnt].Handle, TRUE);
				}

			break;

			case (int)GAME_LEVEL_HARD: //��Փx����̏���

				if (Flashing_flg)	//�_�Ńt���O�������Ă����
				{
					DRAW_FLASHING(cnt);		//�_�ŕ`��
				}

				if (Number_Image[cnt].IsDraw)		//�`�悵�Ă悢��
				{
					MOVE_QUESTION(&Number_Image[cnt], &Q_rect[cnt]);	//���̕`��ʒu���ړ�

					if (Number_Image[cnt].Reverse_flg)	//���]�t���O�������Ă���Ƃ�
						DrawTurnGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE); //���E���]�`��
					else
						DrawGraph(Number_Image[cnt].X, Number_Image[cnt].Y, Number_Image[cnt].Handle, TRUE);	//����`��

				}

				break;
			}
		}

		//DrawBox(Q_rect[cnt].left,
		//	Q_rect[cnt].top,
		//	Q_rect[cnt].right,
		//	Q_rect[cnt].bottom,
		//	GetColor(255, 255, 255), FALSE);//���̗̈��`��
	}

	return;
}

//############ �񓚗p�̐�����`�悷��֐� ############
VOID DRAW_ANSER_NUM(VOID)
{
	DrawGraph(Num_Image.X, Num_Image.Y, Num_Image.Handle, TRUE);	//�񓚗p�̐�����`��

	for (int cnt = 0; cnt < RECT_CNT; cnt++)
	{
		DrawBox(A_num[cnt].left, A_num[cnt].top, A_num[cnt].right, A_num[cnt].bottom, GetColor(255, 255, 255), FALSE);//�̈��`��
	}

}

//############ ���ʂ�`�悷��֐� #################
VOID DRAW_RESULET(VOID)
{
	char StrGameZanki[2][128] = { "\0" };
	char StrFontZanki[128] = { "MS �S�V�b�N" };

	sprintf(&StrGameZanki[0][0], "%d�⒆%d�␳��", Q_Sum, True_Kazu);	//��萔�Ɛ��𐔂�`��

	MY_DRAW_STRING_CENTER_CENTER(&StrGameZanki[0], 1, StrFontZanki, 80);	//��ʒ����ɕ`��

}

//############ �I���̑I������`�悷��֐� ############
VOID DRAW_END_IMAGE(VOID)
{
	for (int num = 0; num < END_KIND; num++)
	{
		DrawGraph(
			End_Image[num].X,
			End_Image[num].Y,
			End_Image[num].Handle, FALSE);	//�摜�`��

	}
}

//########### �w�肵���w�i�摜��`�悷��֐� ###########
VOID DRAW_BACKIMAGE(GAZOU *back)
{
	DrawGraph(back->X, back->Y, back->Handle, FALSE);	//�w�i�̕`��
}

//########### �����L���O��`�悷��֐� #################
VOID DRAW_RANKING(SAVE data,int cnt)
{
	int Font = CREATE_FONT(60);	//�t�H���g�n���h���쐬
	char Str_Ranking[128] = { 0 };

	sprintf(&Str_Ranking[0], "%2d��:%d�N%d��%d��%2d��",cnt + 1,data.year,data.mounth,data.day,data.point);

	int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Ranking[0]);	//�f�t�H���g�̃t�H���g�̉������擾

	DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
		100 + cnt*60,
		&Str_Ranking[0],
		GetColor(255, 255, 255),
		Font);	//�����L���O�̕`��

	DeleteFontToHandle(Font);	//�t�H���g�n���h���폜
}

//########### ��߂�̉摜��`�悷��֐� ###############
VOID Draw_Retire()
{

	//�`��ʒu�ݒ�
	Retire_Image.X = GAME_WIDTH - Retire_Image.Width;	//�E�[�ɐݒ�

	//�̈�Đݒ�
	RECT_SETTING(&Retire_rect,
		Retire_Image.X,
		Retire_Image.Y,
		Retire_Image.Width,
		Retire_Image.Height);


	//�摜�`��
	DrawGraph(
		Retire_Image.X,
		Retire_Image.Y,
		Retire_Image.Handle, FALSE);	//�摜�`��

}

//########### �X�^�[�g�̉摜�̐ݒ������֐� ##########
VOID SET_START_IMAGE(VOID)
{
	//���������������������� �摜�̈ʒu�𒲐� ����������������������
	Start_Image[0].X = GAZOU_SPACE * 1.5;
	Start_Image[0].Y = 400;

	Start_Image[1].X = Start_Image[0].X + Start_Image[0].Width + GAZOU_SPACE * 1.5;
	Start_Image[1].Y = 400;

	Start_Image[2].X = Start_Image[1].X + Start_Image[1].Width + GAZOU_SPACE * 1.5;
	Start_Image[2].Y = 400;
	//���������������������� �摜�̈ʒu�𒲐� ����������������������



	//���������������������� �摜�̗̈��ݒ� ����������������������
	for (int cnt = 0; cnt < START_KIND; cnt++)
	{
		RECT_SETTING(&Start_rect[cnt],
			Start_Image[cnt].X,
			Start_Image[cnt].Y,
			Start_Image[cnt].Width,
			Start_Image[cnt].Height);
	}
	//���������������������� �摜�̗̈��ݒ� ����������������������

}

//########### �͂��Ƃ������̉摜�`��̐ݒ������֐� ##########
VOID SET_SELECT_IMAGE(VOID)
{
	//���������������������� �摜�̈ʒu�𒲐� ����������������������
	Select_Image[0].X = GAZOU_SPACE * 2;
	Select_Image[0].Y = GAME_HEIGHT / 2 - Select_Image[0].C_Height;

	Select_Image[1].X = Select_Image[0].X + Select_Image[0].Width + GAZOU_SPACE * 2;
	Select_Image[1].Y = GAME_HEIGHT / 2 - Select_Image[1].C_Height;
	//���������������������� �摜�̈ʒu�𒲐� ����������������������



	//���������������������� �摜�̗̈��ݒ� ����������������������
	for (int cnt = 0; cnt < SELECT_KIND; cnt++)
	{
		RECT_SETTING(&Select_rect[cnt],
			Select_Image[cnt].X,
			Select_Image[cnt].Y,
			Select_Image[cnt].Width,
			Select_Image[cnt].Height);
	}
	//���������������������� �摜�̗̈��ݒ� ����������������������

}

//############ �񓚗p�̐����̐ݒ������֐� ###########
VOID SET_ANSER_NUM(VOID)
{
	//�摜�̕`��ʒu��ݒ�
	Num_Image.X = 0;
	Num_Image.Y = Q_ERIA_HEIGHT;

	for (int cnt = 0; cnt < RECT_CNT; cnt++)
	{
		RECT_SETTING(&A_num[cnt],
			cnt * RECT_YOKO_SIZE,
			Num_Image.Y,
			RECT_YOKO_SIZE,
			RECT_TATE_SIZE);	//�̈���Z�b�g
	}
}

//########### �I���̑I�����̉摜�̐ݒ������֐� ############
VOID SET_END_IMAGE(VOID)
{
	//���������������������� �摜�̈ʒu�𒲐� ����������������������
	End_Image[0].X = GAZOU_SPACE * 3.5;
	End_Image[0].Y = 450;

	End_Image[1].X = End_Image[0].X + End_Image[0].Width + GAZOU_SPACE * 3.5;
	End_Image[1].Y = 450;
	//���������������������� �摜�̈ʒu�𒲐� ����������������������




	//���������������������� �摜�̗̈��ݒ� ����������������������
	for (int cnt = 0; cnt < END_KIND; cnt++)
	{
		RECT_SETTING(&End_rect[cnt],
			End_Image[cnt].X,
			End_Image[cnt].Y,
			End_Image[cnt].Width,
			End_Image[cnt].Height);
	}
	//���������������������� �摜�̗̈��ݒ� ����������������������

	return;
}

//########### ������ʂŎg�p���鏬���i���Ȃǁj�̉摜�̐ݒ������֐� ############
VOID SET_END_SETU(VOID)
{
	//���������������������� �摜�̈ʒu�𒲐� ����������������������
	Setu_Image.X = 880;
	Setu_Image.Y = 0;
	//���������������������� �摜�̈ʒu�𒲐� ����������������������




	//���������������������� �摜�̗̈��ݒ� ����������������������
		RECT_SETTING(&Setu_rect,
			Setu_Image.X,
			Setu_Image.Y,
			Setu_Image.Width,
			Setu_Image.Height);
	//���������������������� �摜�̗̈��ݒ� ����������������������

	return;
}

//########## ����ǂݍ��ސݒ������֐� ##########
//���@���F���\���́@	:�ݒ肷�鉹�\���̂̕ϐ�
//���@���Fconst char *	:�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL			:TRUE:���� / FALSE:�ُ�
BOOL MY_MUSIC_LOAD(MUSIC *m, const char *path)
{
	//����ǂݍ���
	m->Handle = LoadSoundMem(path);

	if (m->Handle == -1) { return FALSE; }

	return TRUE;
}

//############ �Q�[�����s���I�������肷��֐� #############
VOID CHECK_GAME_CONTINUE(int num)
{

	End_flg = FALSE;		//�I���t���O��������
	Continue_flg = FALSE;	//���s�t���O��������

	switch (num)
	{
	case (int)GAME_CONTINUE:
		Continue_flg = TRUE;	//���s�t���O
		break;

	case (int)GAME_END:
		End_flg = TRUE;		//�I���t���O
		break;

	default:
		break;
	}

	//�I�������s���ŏ�����ς���
	if (End_flg == TRUE)
	{
		//GameSceneNow = (int)GAME_SCENE_END;	//�Q�[���V�[�����G���h��ʂɕς���
		GameSceneNow = (int)GAME_SCENE_CHECK;	//�Q�[���V�[�����m�F��ʂɕς���
	}
	else if (Continue_flg == TRUE)
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;//�Q�[���V�[�����^�C�g����ʂɕς���
	}

	return;
}

//############## �Q�[���J�n���I�������肷��֐� #############
VOID CHECK_GAME_START(int num)
{
	End_flg = FALSE;		//�I���t���O��������
	Start_flg = FALSE;		//�J�n�t���O��������

	switch (num)
	{
	case (int)GAME_START:
		Start_flg = TRUE;	//�J�n�t���O
		break;

	case (int)GAME_SETUMEI:
		Setumei_flg = TRUE;//�����t���O
		break;

	case (int)GAME_END2:
		End_flg = TRUE;		//�I���t���O
		break;

	default:
		break;
	}

	//�J�n�A�I���A�������ŏ�����ς���
	if (End_flg == TRUE)
	{
		GameSceneNow = (int)GAME_SCENE_CHECK;	//�Q�[���V�[�����m�F��ʂɕς���
	}
	else if (Setumei_flg == TRUE)
	{
		GameSceneNow = (int)GAME_SCENE_SETUMEI;	//�Q�[���V�[���������ʂɕς���
	}
	else if (Start_flg == TRUE)
	{
		GameSceneNow = (int)GAME_SCENE_SET;//�Q�[���V�[����ݒ��ʂɕς���
	}

	return;
}

//############## �͂����������̂ǂ����I�񂾂����肷��֐� #############
BOOL CHECK_SELECT(int num)
{
	Yes_flg = FALSE;		//�͂��̃t���O��������
	No_flg = FALSE;			//�������̃t���O��������

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

//############## ���Ԃ�`�悷��֐� ######################
VOID DRAW_TIME(VOID)
{
	int Font = CREATE_FONT(80);	//�t�H���g�n���h���쐬
	char Str_Time[128] = {0};

	sprintf(&Str_Time[0], "�c�莞��:%.2f", NokoriTime);

	int StrWidth = GetDrawFormatStringWidthToHandle(Font,&Str_Time[0]);	//�f�t�H���g�̃t�H���g�̉������擾
	
	if (NokoriTime <= 10 && NokoriTime > 0)	//10�b��؂�����A�ԐF�ŕ`�悷��
	{
		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			0,
			&Str_Time[0],
			GetColor(255, 0, 0),
			Font);	//���Ԃ̕`��
	}
	else if(NokoriTime>0)
	{
		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			0,
			&Str_Time[0],
			GetColor(255, 255, 255),
			Font);	//���Ԃ̕`��
	}

	DeleteFontToHandle(Font);	//�t�H���g�n���h���폜

	return;
}

//############## ���̕`��ʒu���ړ�������֐� #################
VOID MOVE_QUESTION(GAZOU *g, RECT *rect)
{

	switch (g->Direction)		//�摜�̈ړ�����
	{
	case DIRECTION_UP:			//������̏���

		if (g->Y - Speed > 0)	//��ʓ��̂Ƃ���
		{
			g->Y -= Speed;			//�摜��������ֈړ�

			rect->top -= Speed;		//�̈��������ֈړ�
			rect->bottom -= Speed;	//�̈��������ֈړ�
		}
		else  //��ʂ̒[�ɓ���������
		{
			g->Direction = DIRECTION_DOWN;	//�ړ����������ɕς���
		}
		break;

	case DIRECTION_DOWN:			//�������̏���

		if (g->Y + g->Height + Speed < Q_ERIA_HEIGHT)	//���̗̈���̎���
		{
			g->Y += Speed;			//�摜���������ֈړ�

			rect->top += Speed;		//�̈���������ֈړ�
			rect->bottom += Speed;	//�̈���������ֈړ�
		}
		else  //�[�ɓ���������
		{
			g->Direction = DIRECTION_UP;	//�ړ���������ɕς���
		}
		break;

	case DIRECTION_LEFT:			//�������̏���

		if (g->X - Speed > 0)	//��ʓ��̎���
		{
			g->X -= Speed;			//�摜���������ֈړ�

			rect->left -= Speed;	//�̈���������ֈړ�
			rect->right -= Speed;	//�̈���������ֈړ�
		}
		else  //�[�ɓ���������
		{
			g->Direction = DIRECTION_RIGHT;	//�ړ��������E�ɂ���
		}
		break;

	case DIRECTION_RIGHT:			//�E�����̏���

		if (g->X + g->Width + Speed < GAME_WIDTH)	//��ʓ��̂Ƃ���
		{
			g->X += Speed;			//�摜���E�����ֈړ�

			rect->left += Speed;	//�̈���E�����ֈړ�
			rect->right += Speed;	//�̈���E�����ֈړ�
		}
		else  //�E�[�ɓ���������
		{
			g->Direction = DIRECTION_LEFT;	//�ړ����������ɂ���
		}
		break;

	case DIRECTION_LEFTUP:			//��������̏���

		if (g->X - Speed > 0)		//��ʓ��̎�
		{
			g->X -= Speed;			//�摜����������ֈړ�

			rect->left -= Speed;	//�̈����������ֈړ�
			rect->right -= Speed;	//�̈����������ֈړ�
		}
		else  //���[�ɓ���������
		{
			g->Direction = DIRECTION_RIGHTUP;		//�ړ��������E��ɂ���
			break;
		}

		if (g->Y - Speed > 0)		//��ʓ��̎�
		{
			g->Y -= Speed;			//�摜����������ֈړ�

			rect->top -= Speed;		//�̈����������ֈړ�
			rect->bottom -= Speed;	//�̈����������ֈړ�
		}
		else  //��ɓ���������
		{
			g->Direction = DIRECTION_LEFTDOWN;	//�ړ������������ɂ���
			break;
		}
		break;

	case DIRECTION_LEFTDOWN:			//���������̏���

		if (g->X - Speed > 0)		//��ʓ��̎�
		{
			g->X -= Speed;			//�摜�������ֈړ�

			rect->left -= Speed;	//�̈�������ֈړ�
			rect->right -= Speed;	//�̈�������ֈړ�
		}
		else  //���[�ɓ���������
		{
			g->Direction = DIRECTION_RIGHTDOWN;
			break;
		}

		if (g->Y + g->Height + Speed < Q_ERIA_HEIGHT)	//��ʓ��̎�
		{
			g->Y += Speed;			//�摜�������ֈړ�

			rect->top += Speed;		//�̈�������ֈړ�
			rect->bottom += Speed;	//�̈�������ֈړ�
		}
		else  //���ɓ���������
		{
			g->Direction = DIRECTION_LEFTUP;	//�ړ�����������ɂ���
			break;
		}
		break;

	case DIRECTION_RIGHTUP:			//�E������̏���

		if (g->X + g->Width + Speed < GAME_WIDTH)	//��ʓ��̂Ƃ�
		{
			g->X += Speed;			//�摜���E��ֈړ�

			rect->left += Speed;	//�̈���E��ֈړ�
			rect->right += Speed;	//�̈���E��ֈړ�
		}
		else  //�E�[�ɓ���������
		{
			g->Direction = DIRECTION_LEFTUP;	//�ړ�����������ɂ���
			break;
		}

		if (g->Y - Speed > 0)		//��ʓ��̎�
		{
			g->Y -= Speed;			//�摜���E��ֈړ�

			rect->top -= Speed;		//�̈���E��ֈړ�
			rect->bottom -= Speed;	//�̈���E��ֈړ�
		}
		else  //��ɓ���������
		{
			g->Direction = DIRECTION_RIGHTDOWN;	//�ړ��������E���ɂ���
			break;
		}
		
		break;

	case DIRECTION_RIGHTDOWN:			//�E�������̏���

		if (g->X + g->Width + Speed < GAME_WIDTH)	//��ʓ��̎�
		{
			g->X += Speed;			//�摜���E���ֈړ�

			rect->left += Speed;	//�̈���E���ֈړ�
			rect->right += Speed;	//�̈���E���ֈړ�
		}
		else
		{
			g->Direction = DIRECTION_LEFTDOWN;	//�ړ������������ɂ���
			break;
		}

		if (g->Y + g->Height + Speed < Q_ERIA_HEIGHT)	//�̈���̎�
		{
			g->Y += Speed;			//�摜���E���ֈړ�

			rect->top += Speed;		//�̈���E���ֈړ�
			rect->bottom += Speed;	//�̈���E���ֈړ�
		}
		else  //���ɓ��������Ƃ�
		{
			g->Direction = DIRECTION_RIGHTUP;	//�ړ��������E��ɂ���
			break;
		}

		break;

	default:
		break;

	}

	return;

}

//############## �Z�[�u�f�[�^���X�V����֐� #####################
int WRITE_SAVEDATA(int data)
{

	FILE *fp;

	fp = fopen(SAVE_DATA, "a");//�o�C�i���t�@�C�����J��
	if (fp == NULL) {//�G���[���N������-1��Ԃ�
		return -1;
	}
	fprintf(fp, "%d,%d,%d,%d\n",Date.Year,Date.Mon,Date.Day, data);
	fclose(fp);//�t�@�C�������

	return 0;
}

//############## �Z�[�u�f�[�^��ǂݍ��ފ֐� #####################
int READ_SAVEDATA(SAVE data[])
{
	SaveNowCnt = 0;

	FILE *fp;

	fp = fopen(SAVE_DATA, "r");
	if (fp == NULL) {
		return -1;	//�G���[������������A-1��Ԃ�
	}

	while (fscanf(fp, "%d,%d,%d,%d", &data[SaveNowCnt].year, &data[SaveNowCnt].mounth, &data[SaveNowCnt].day, &data[SaveNowCnt].point)
		!= EOF)
	{
		SaveNowCnt++;
	}

	fclose(fp);

	return 0;
}

//############## �l�����ւ���֐� #############################
VOID SWAP(int *x, int *y)
{
	int temp;    // �l���ꎞ�ۑ�����ϐ�

	temp = *x;
	*x = *y;
	*y = temp;
}

//############## pivot�����߁Apivot�����ڂɐU�蕪������֐� ################
int PARTITION(SAVE array[], int left, int right)
{
	int i = 0, j = 0, pivot = 0;
	i = left;
	j = right + 1;
	pivot = left;   // �擪�v�f��pivot�Ƃ���

	do {
		do { i++; } while (array[i].point > array[pivot].point);
		do { j--; } while (array[pivot].point > array[j].point);
		// pivot��菬�������̂����ցA�傫�����̂��E��
		if (i < j) { SWAP(&array[i].point, &array[j].point); }
	} while (i < j);

	SWAP(&array[pivot].point, &array[j].point);   //pivot���X�V

	return j;
}

//############## �N�C�b�N�\�[�g�֐� ##############################
VOID QUICK_SORT(SAVE array[], int left, int right)
{
	int pivot;

	if (left < right) {
		pivot = PARTITION(array, left, right);
		QUICK_SORT(array, left, pivot - 1);   // pivot�����ɍċA�I�ɃN�C�b�N�\�[�g
		QUICK_SORT(array, pivot + 1, right);
	}
}

//############## �Z�[�u�f�[�^���~���ɕ��בւ���֐� #################
VOID SORT_SAVEDATA(SAVE array[])
{
	READ_SAVEDATA(array);	//�Z�[�u�f�[�^�̓ǂݍ���

	SAVEDATA_MAX(array, SaveNowCnt);	//�ő�l�擾

	SAVEDATA_MIN(array, SaveNowCnt);	//�ŏ��l�擾

	QUICK_SORT(array, SaveMinNum, SaveMaxNum);	//�N�C�b�N�\�[�g

	return;
}

//############ �Z�[�u�f�[�^�̍ő�l���擾����֐� ################
VOID SAVEDATA_MAX(SAVE array[],int num)
{
	int tempmax = 0;	//�ő�l������ϐ�

	for (int cnt = 0; cnt < num; cnt++)
	{
		if (array[cnt].point > tempmax)	//���݂̍ő�l���傫��������
		{
			tempmax = array[cnt].point;	//�ő�l�X�V
		}
	}

	SaveMaxNum = tempmax;	//��Ɨp�ɓ����Ă���ő�l������

	return;
}

//############ �Z�[�u�f�[�^�̍ŏ��l���擾����֐� ################
VOID SAVEDATA_MIN(SAVE array[],int num)
{
	int tempmin = 0;	//�ŏ��l������ϐ�

	for (int cnt = 0; cnt < num; cnt++)
	{
		if (array[cnt].point < tempmin)	//���݂̍ŏ��l���傫��������
		{
			tempmin = array[cnt].point;	//�ŏ��l�X�V
		}
	}

	SaveMinNum = tempmin;	//��Ɨp�ɓ����Ă���ŏ��l������

	return;
}

//########### �Z�[�u�f�[�^���폜����֐� ####################
int DELETE_DATA(SAVE data)
{
	FILE *fp;

	fp = fopen(SAVE_DATA, "w");//�o�C�i���t�@�C�����J��
	if (fp == NULL) {//�G���[���N������-1��Ԃ�
		return -1;
	}
	fclose(fp);//�t�@�C�������

	return 0;

}

//############ �҂����Ԃ�`�悷��֐� ####################
VOID DRAW_WAIT_TIME(int wait)
{
	int Font = CREATE_FONT(FONT_SIZE);	//�t�H���g�n���h���쐬
	char Str_Time[128] = { 0 };

	sprintf(&Str_Time[0], "%.0f", NokoriTime);

	int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Time[0]);	//�f�t�H���g�̃t�H���g�̉������擾

	if (NokoriTime > 1)
	{
		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			300,
			&Str_Time[0],
			GetColor(255, 0, 255),
			Font);	//���Ԃ̕`��
		
	}
	else if (First_flg==TRUE &&
		NokoriTime < 0.3)	//�v���C��ʂ̃J�E���g�_�E���̍Ō��"START"�̕`�������
	{
		int Font = CREATE_FONT(100);	//�t�H���g�n���h���쐬
		char Str_Ranking[128] = { "START" };

		int StrWidth = GetDrawFormatStringWidthToHandle(Font, &Str_Ranking[0]);	//�f�t�H���g�̃t�H���g�̉������擾

		DrawStringToHandle(GAME_WIDTH / 2 - StrWidth / 2,
			300,
			&Str_Ranking[0],
			GetColor(255, 0, 0),
			Font);	//START�̕`��

		DeleteFontToHandle(Font);	//�t�H���g�n���h���폜
	}
	
	DeleteFontToHandle(Font);	//�t�H���g�n���h���폜

	return;
}

//############ ���t���擾����֐� ########################
VOID GET_DATEDATA()
{
	GetDateTime(&Date);		//���t�擾
	return;
}

//************ ��背�x���������_���ɐݒ肷��֐� *****************
VOID SetLevel()
{
	int rand = 0;	//����������ϐ�

	rand = GetRand(LEVEL_KIND - 1);	//�Q�[�����x���̐����ŗ����𐶐�

	Game_Level_Now = rand;		//�����������������݂̃Q�[�����x���ɐݒ�

	return;

}

//*********** �`��F��ύX����֐� ********************
BOOL CHENGE_COLOR(int handle,int color)
{

	if (GraphFilter(handle,DX_GRAPH_FILTER_HSB,1, color,0,0)==0)	//�F��ύX
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}


}

//*********** �_�ŕ`�� *******************
VOID DRAW_FLASHING(int cnt)
{
	if (DrawTime >= 2 && (int)DrawTime % 2 == 0)		//2�b�u����
	{
		if (Number_Image[cnt].SetIsDraw_flg == FALSE)		//�`��ݒ芮�����ĂȂ��Ƃ���
		{
			if (Number_Image[cnt].IsDraw)	//�`�悵�Ă悢��
			{
				Number_Image[cnt].IsDraw = FALSE;	//�`�悵�Ă͂����Ȃ�
				Number_Image[cnt].SetIsDraw_flg = TRUE;	//�ݒ芮��
			}
			else
			{
				Number_Image[cnt].IsDraw = TRUE;	//�`�悵�Ă悢
				Number_Image[cnt].SetIsDraw_flg = TRUE;	//�ݒ芮��
			}
		}
	}
	else
	{
		Number_Image[cnt].SetIsDraw_flg = FALSE;	//�ݒ芮�����ĂȂ�
	}

	return;

}
