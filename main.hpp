//main.hpp

#pragma once

//************ �w�b�_�[�t�@�C���ǂݍ��� ***********
#include "DxLib.h"

//************ �}�N����` ***************
#define GAME_WIDTH	1000		//��ʂ̉��̑傫��
#define GAME_HEIGHT	600			//��ʂ̏c�̑傫��
#define Q_ERIA_WIDTH	960		//����`�悷���ʂ̑傫��
#define Q_ERIA_HEIGHT	450		//����`�悷���ʂ̑傫��
#define GAME_COLOR	32			//��ʂ̃J���[�r�b�g

#define GAME_WINDOW_NAME	"Missing Numbers"		//�E�B���h�E�̃^�C�g��
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE�F�E�B���h�E���[�h / FALSE�F�t���X�N���[��

#define SET_WINDOW_ST_MODE_DEFAULT			0	//�f�t�H���g
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//�^�C�g���o�[�Ȃ�
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//�^�C�g���o�[�ƃt���[���Ȃ�
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//�t���[���Ȃ�

#define GAME_FPS_SPEED	60						//FPS���x

#define POINT_MAX_KETA	2	//�f�[�^�̓��_��MAX����

#define ZERO_IMAGE		"NUMBER\\zero.png"			//0�̉摜
#define ONE_IMAGE		"NUMBER\\one.png"			//1�̉摜
#define TWO_IMAGE		"NUMBER\\two.png"			//2�̉摜
#define THREE_IMAGE		"NUMBER\\three.png"			//3�̉摜
#define FOUR_IMAGE		"NUMBER\\four.png"			//4�̉摜
#define FIVE_IMAGE		"NUMBER\\five.png"			//5�̉摜
#define SIX_IMAGE		"NUMBER\\six.png"			//6�̉摜
#define SEVEN_IMAGE		"NUMBER\\seven.png"			//7�̉摜
#define EIGHT_IMAGE		"NUMBER\\eight.png"			//8�̉摜
#define NINE_IMAGE		"NUMBER\\nine.png"			//9�̉摜
#define NUMBER_IMAGE	"NUMBER\\num.png"			//�����̉摜

#define END_IMAGE		"ENDIMAGE\\end.png"			//�I���̉摜
#define CONTINUE_IMAGE	"ENDIMAGE\\continue.png"	//���s�̉摜
#define START_IMAGE		"STARTIMAGE\\start.png"		//�X�^�[�g�̉摜
#define END_IMAGE2		"STARTIMAGE\\end.png"		//�X�^�[�g�I����ʂ̏I���̉摜
#define TITLE_IMAGE     "STARTIMAGE\\title.png"		//�^�C�g���̉摜

#define YES_IMAGE		"SELECTIMAGE\\yes.png"		//�͂��̉摜
#define NO_IMAGE		"SELECTIMAGE\\no.png"		//�������̉摜

#define TITLE_BACKIMAGE "BACKIMAGE\\back5.jpg"		//�^�C�g����ʂ̔w�i�摜
#define SELECT_BACKIMAGE "BACKIMAGE\\back3.jpg"		//��Փx�I����ʂ̔w�i�摜
#define PLAY_BACKIMAGE	"BACKIMAGE\\back6.jpg"		//�v���C��ʂ̔w�i�摜
#define RESULT_BACKIMAGE "BACKIMAGE\\back2.jpg"		//���U���g��ʂ̔w�i�摜
#define	END_BACKIMAGE	"BACKIMAGE\\back6.jpg"		//�G���h��ʂ̔w�i�摜

#define SETUMEI_IMAGE	"SETUMEI\\setumei.png"				//���߂��̉摜
#define SETUMEI_LEVLEIMAGE "SETUMEI\\level_image.png"		//���x���̐����摜
#define SETUMEI_PLAYIMAGE	"SETUMEI\\play_image.png"		//�v���C��ʂ̐����摜
#define SETUMEI_NEXT		"SETUMEI\\next.png"				//���̉摜

#define RETIRE_IMAGE	"RETIREIMAGE\\retire.png"			//�r���ł�߂�̉摜


#define MUSIC_SE_TRUE	"SE\\true.mp3"				//�����������̌��ʉ�
#define MUSIC_SE_FALSE	"SE\\false.mp3"				//�s�������������̌��ʉ�
#define MUSIC_SE_CLICK	"SE\\click.mp3"				//�N���b�N�����Ƃ��̌��ʉ�
#define MUSIC_SE_CLICK2	"SE\\kettei.mp3"			//�I�������N���b�N�����Ƃ��̌��ʉ�
#define MUSIC_SE_COUNTDOWN	"SE\\countdown.mp3"		//�J�E���g�_�E���̌��ʉ�

#define MUSIC_BGM		"BGM\\cyber42.mp3"			//BGM

#define SAVE_DATA		"C:\\Missing Numbers_SAVE\\Save.dat"		//�Z�[�u�f�[�^
#define GAME_DATA		"C:\\Missing Numbers_SAVE"					//�Z�[�u�f�[�^������t�H���_�̃p�X

#define GAZOU_SPACE		50				//�摜�Ɖ摜�̊Ԋu

#define LEVEL_KIND	3					//�Q�[����Փx�̐�
#define QUESTION_KAZU 10				//��萔
#define END_KIND 2						//�I���̐�
#define START_KIND 3					//�X�^�[�g��ʂɕ\������摜�̐�
#define SELECT_KIND 2					//�I�����̐��i�͂��A�������j
#define BACKIMAGE_KIND 5				//�w�i�摜�̎��
#define DIRECTION_KIND 8				//�ړ������̎��
#define SETUMEI_KIND   2				//������ʂŎg�p����摜�̎��
#define SETU_KIND	   2				//������ʂŎg�����Ȃǂ̉摜�̎��

#define FONT_SIZE 140					//�t�H���g�̃T�C�Y
#define FONT_BOLD 3						//�t�H���g�̑���

#define NUMBER_KIND 10					//���̎��

#define PI 3.141592654					//�ʓx�@�Ŏg�p
#define EXPANSION 1.0					//�g�嗦

#define NUMBER_KAZU 1					//�����̉摜�̐�

#define RECT_TATE_SIZE 147				//�񓚗p�̐����̗̈�̏c�T�C�Y
#define RECT_YOKO_SIZE 100				//�񓚗p�̐����̗̈�̉��T�C�Y
#define RECT_CNT  10					//�񓚗p�̐����̗̈�̐�

#define RANKING_NUM	5					//�����L���O�̕`�悷�鐔�i��ʂT�܂ŕ`��j

#define GAMETIME 30						//�Q�[���̐�������

#define REVERSE_TYPE 1					//���]�����邩�ǂ������t���O�Ŏg�p����ۂɂ���

#define TOUKA_MIN	80					//���ߗ��̍Œ�l

//########## �񋓌^ ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,	//�^�C�g�����
	GAME_SCENE_SETUMEI,	//�������
	GAME_SCENE_CHECK,	//�͂����������̑I������`�悷����
	GAME_SCENE_SET,		//�ݒ���
	GAME_SCENE_PLAY,	//�v���C���
	GAME_SCENE_RESULT,	//���ʕ\�����
	GAME_SCENE_RANKING,	//�����L���O�\�����
};

enum GAME_LEVEL {
	GAME_LEVEL_EASY,	//�ȒP
	GAME_LEVEL_NORMAL,	//����
	GAME_LEVEL_HARD		//���
};

enum END_TYPE {
	GAME_CONTINUE,	//���s
	GAME_END		//�I��
};

enum START_TYPE {
	GAME_START,	//�X�^�[�g
	GAME_SETUMEI,//����
	GAME_END2	//�I��
};

enum SELECT {
	SELECT_YES,	//�͂�
	SELECT_NO	//������
};

enum BACKIMAGE_SCENE {
	BACKIMAGE_TITLE,	//�^�C�g����ʂ̔w�i
	BACKIMAGE_SELECT,	//�Z���N�g��ʂ̔w�i
	BACKIMAGE_PLAY,		//�v���C��ʂ̔w�i
	BACKIMAGE_RESULT,	//���U���g��ʂ̔w�i
	BACKIMAGE_END		//�G���h��ʂ̔w�i
};

enum SETUMEI {
	BACKIMAGE_SETULEVEL,//������ʂ̃��x������
	BACKIMAGE_SETUPLAY,	//������ʂ̃v���C����
};

enum MOVE_DIRECTION {
	DIRECTION_UP,		//�ړ������A��
	DIRECTION_DOWN,		//�ړ������A��
	DIRECTION_LEFT,		//�ړ������A��
	DIRECTION_RIGHT,	//�ړ������A�E
	DIRECTION_LEFTUP,	//�ړ������A����
	DIRECTION_LEFTDOWN,	//�ړ������A����
	DIRECTION_RIGHTUP,	//�ړ������A�E��
	DIRECTION_RIGHTDOWN	//�ړ������A�E��
};//�ړ�����

//########## �\���� ##########
struct STRUCT_GAZOU {
	int Handle;				//�摜�̃n���h��
	char FilePath[128];		//�t�@�C���̃p�X
	int X;					//���̈ʒu
	int Y;					//�c�̈ʒu
	int Width;				//���̃T�C�Y	
	int Height;				//�c�̃T�C�Y
	int C_Width;			//���̒��S�ʒu
	int C_Height;			//�c�̒��S�ʒu
	int Direction;			//�摜�̈ړ�����
	BOOL Num_flg;			//�����p�t���O
	BOOL Positon_flg;		//���W�ݒ芮���p�t���O
	BOOL Reverse_flg;		//���E���]�t���O
	BOOL IsDraw;			//�`�悵�Ă悢��
	BOOL SetIsDraw_flg;		//�`�悵�Ă悢����ݒ肵����
	int Color;				//�F
	int touka;				//���ߗ�
};

struct STRUCT_MOUSE {
	int X;		//�}�E�X��x���W
	int Y;		//�}�E�X��Y���W
	int Mouse_Input;	//�}�E�X�̃N���b�N���
	int Mouse_Click_Num;//�}�E�X���N���b�N���ꂽ�摜�̔ԍ�������
	int Mouse_Click_Cnt;//�}�E�X���N���b�N����Ă���ԃJ�E���g����
	BOOL Mouse_hover_flg;	//�摜�̏�Ƀ}�E�X������Ă����Ԃ��m�F����t���O
	BOOL Mouse_LeftClick_flg;	//���N���b�N���ꂽ���m�F����t���O
};

struct STRUCT_MUSIC
{
	int Handle;			//���̃n���h��
	char FilePath[128];	//�t�@�C���̃p�X
	int Playtype;		//���̍Đ����@
};	//���\����

struct STRUCT_SAVE {
	int point;	//���_
	int year;	//�N
	int mounth;	//��
	int day;	//��
};	//�Z�[�u�f�[�^�\����

//****************���O�̍Ē�`********************
typedef STRUCT_GAZOU GAZOU;
typedef STRUCT_MOUSE MOUSE;
typedef STRUCT_MUSIC MUSIC;
typedef STRUCT_SAVE SAVE;

//########## �O���[�o���ϐ� ##########

//�E�B���h�E�֌W
WNDPROC WndProc;						//�E�B���h�E�v���V�[�W���̃A�h���X
BOOL IsWM_CREATE = FALSE;				//WM_CREATE������ɓ��삵�������f����

//�L�[�{�[�h�֘A
char AllKeyState[256];			//���ׂẴL�[�̏�Ԃ���

//�}�E�X�֘A
MOUSE Mouse_Date;		//�}�E�X�̏��

//�V�[���֘A
int GameSceneNow = (int)GAME_SCENE_SETUMEI;	//�ŏ��̃Q�[����ʂ��^�C�g���ɐݒ�

//���֘A
int Player_Anser = 0;								//�v���C���[�̉񓚂�����ϐ�
int True_Kazu = 0;									//�v���C���[�̐��𐔂�����ϐ�
int Q_Sum = 0;										//���������̍��v��
int Speed = 1;										//���̈ړ����x

//�摜�֘A
GAZOU Number_Image[NUMBER_KIND];					//���̉摜
GAZOU Num_Image;									//�񓚗p�̐����̉摜
GAZOU End_Image[END_KIND];							//�I���̑I�����̉摜
GAZOU Start_Image[START_KIND];						//�X�^�[�g�̉摜
GAZOU Back_Image[BACKIMAGE_KIND];					//�w�i�摜
GAZOU Select_Image[SELECT_KIND];					//�I�����̉摜�i�͂��A�������j
GAZOU Setumei_Image[SETUMEI_KIND];					//������ʂŎg�p����摜
GAZOU Setu_Image;									//������ʂ̏����摜(���Ȃ�)
GAZOU Title_Image;									//�^�C�g���̉摜
GAZOU Retire_Image;									//�r���ł�߂�̉摜
int BackImageNow = BACKIMAGE_TITLE;					//���݂̔w�i�摜�̎��
int Setu_Now = BACKIMAGE_SETULEVEL;					//���݂̐����i�K

//�̈�֘A
RECT Q_rect[QUESTION_KAZU];							//���̗̈�
RECT A_num[RECT_CNT];								//�񓚂̑I�����̗̈�
RECT End_rect[END_KIND];							//�I���̑I�����̗̈�
RECT Start_rect[START_KIND];						//�X�^�[�g�̑I�����̗̈�
RECT Select_rect[SELECT_KIND];						//�I�����̗̈�i�͂��A������)
RECT Setu_rect;										//������ʂ̏����摜(���Ȃ�)�̗̈�
RECT Retire_rect;									//�r���ł�߂�̗̈�

//��Փx�֘A
int Game_Level_Now;									//���݂̃Q�[���̓�Փx������ϐ�

//�t���O�֘A
BOOL True_flg = FALSE;								//�v���C���[�̉񓚂������̎�
BOOL False_flg = FALSE;								//�v���C���[�̉񓚂��s�����̎�
BOOL End_flg = FALSE;								//�Q�[���I���̎�
BOOL Setumei_flg = TRUE;							//�����t���O
BOOL Continue_flg = FALSE;							//�Q�[�����s�̎�
BOOL Start_flg = FALSE;								//�Q�[���X�^�[�g�t���O
BOOL Yes_flg = FALSE;								//�͂��̃t���O
BOOL No_flg = FALSE;								//�������̃t���O
BOOL GameEnd_flg = FALSE;							//�Q�[���I���̃t���O
BOOL Write_flg = FALSE;								//�f�[�^�̏������݂������ǂ����̃t���O
BOOL Sort_flg = FALSE;								//�\�[�g�t���O
BOOL Read_flg = FALSE;								//�ǂݍ��݃t���O
BOOL Delete_flg = FALSE;							//�Z�[�u�f�[�^�폜�t���O
BOOL WaitTime_flg = FALSE;							//���Ԃ�҂��߂̃t���O
BOOL First_flg = TRUE;								//�ŏ��̖��
BOOL CountDownStart_flg = FALSE;					//�J�E���g�_�E���X�^�[�g�̃t���O
BOOL Retire_flg = FALSE;							//���^�C�A�t���O
BOOL Flashing_flg = FALSE;							//�_�Ńt���O


//���Ԋ֘A
double StartTime = 0;	//�v���J�n����
double NokoriTime = 0;	//�c�莞��
double LostTimeStart = 0;//���f���n�߂�����
double LostTimeEnd = 0;	//���f���I���������
double LostTime = 0;	//���f���Ă�������
double DrawTime = 0;	//�`�悵�Ă��鎞��
double DrawStartTime = 0;	//�`��J�n����
int Time_Draw_X = 300;	//���ԕ\����X���W
int Time_Draw_Y = 0;	//���ԕ\����Y���W
int LimitTime = 30;		//��������
DATEDATA Date;			//���t

//���֘A
MUSIC SE_TRUE;			//�����������ɖ鉹
MUSIC SE_FALSE;			//�s�����������ɖ鉹
MUSIC SE_CLICK;			//�N���b�N�����Ƃ��̌��ʉ�
MUSIC SE_KETTEI;		//�I�������N���b�N�����Ƃ��̌��ʉ�
MUSIC SE_COUNTDOWN;		//�J�E���g�_�E���̎��̌��ʉ�
MUSIC BGM;				//BGM

//�Z�[�u�f�[�^�֘A
SAVE SaveData[128] = { 0 };		//�Z�[�u�f�[�^������z��
int SaveNowCnt = 0;				//�Z�[�u�f�[�^���������Ă��邩�J�E���g����ϐ�
int SaveMaxNum = 0;				//�Z�[�u�f�[�^�̒��̍ő�l
int SaveMinNum = 0;				//�Z�[�u�f�[�^�̒��̍ŏ��l

//########## �v���g�^�C�v�錾 ##########
//LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);	//����E�B���h�E�v���V�[�W��

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����֐�

VOID MY_GAME_TITLE(VOID);			//�^�C�g����ʂ̊֐�
VOID MY_GAME_SETUMEI(VOID);			//������ʂ̊֐�
VOID MY_GAME_CHECK(VOID);			//�m�F��ʂ̊֐�
VOID MY_GAME_SET(VOID);				//�ݒ��ʂ̊֐�
VOID MY_GAME_PLAY(VOID);			//�v���C��ʂ̊֐�
VOID MY_GAME_RESULT(VOID);			//���U���g��ʂ̊֐�
VOID MY_GAME_RANKING(VOID);			//�����L���O��ʂ̊֐�

VOID MY_DRAW_STRING_CENTER_CENTER(char[][128], int, char *, int);	//��ʒ����ɕ�����`�悷��֐�
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL);								//�������f�t�H���g�t�H���g�ɐݒ肷��֐�
int CREATE_FONT(int);												//�t�H���g�n���h�����쐬����֐�

BOOL MY_GAZOU_LOAD(GAZOU *, int, int, const char *);				//�摜��ǂݍ��ފ֐�

VOID MY_CREATE_QUESTION(VOID);		//���𐶐�����֐�

BOOL MY_INIT(VOID);					//�������֐�

VOID GAMELEVEL_IMAGE_DRAW(VOID);	//��Փx��`�悷��֐�
VOID STATE_DRAW(VOID);				//����`�悷��֐�
VOID DRAW_START(VOID);				//�X�^�[�g��ʂ̕`�������֐�
VOID DRAW_SELECT(VOID);				//�͂��Ƃ������̉摜��`�悷��֐�
VOID DRAW_QUESTION(VOID);			//����`�悷��֐�
VOID DRAW_ANSER_NUM(VOID);			//�񓚗p�̑I������`�悷��֐�
VOID DRAW_RESULET(VOID);			//���ʂ�`�悷��֐�
VOID DRAW_END_IMAGE(VOID);			//�I���̑I������`�悷��֐�
VOID DRAW_BACKIMAGE(GAZOU *);		//�w�肵���w�i�摜��`�悷��֐�
VOID DRAW_TIME(VOID);				//���Ԃ�`�悷��֐�
VOID DRAW_RANKING(SAVE, int);		//�����L���O��`�悷��֐�
VOID DRAW_WAIT_TIME(int wait);		//�҂����Ԃ�`�悷��֐�
VOID DRAW_SETU(VOID);				//�������Ɏg�p���鏬���i���Ȃǁj��`�悷��֐�
VOID Draw_Retire();					//��߂�̉摜��`�悷��֐�

VOID RECT_SETTING(RECT *, int, int, int, int);	//�̈��ݒ肷��֐�
VOID RECT_RESET(RECT *);						//�̈������������֐�
BOOL MY_CHECK_RECT_ATARI(RECT, RECT);			//�̈�Ɨ̈�̓����蔻�������֐�

VOID GET_MOUSE_STATE(RECT *, int);	//�}�E�X�̏����擾����֐�
VOID RESET_MOUSE_DATE(VOID);		//�}�E�X�̏������Z�b�g����֐�
BOOL CHECK_RECT_ATARI(RECT, MOUSE);	//�}�E�X���摜�̗̈�����ǂ������f����֐�

VOID SET_SELECT_IMAGE(VOID);		//�͂��Ƃ������̉摜�`��̐ݒ������֐�
VOID SET_START_IMAGE(VOID);			//�X�^�[�g��ʂ̐ݒ������֐�
VOID SET_ANSER_NUM(VOID);			//�񓚗p�̐����̐ݒ������֐�
VOID GET_PLAYER_ANSER(int);			//�v���C���[�̉񓚂��擾����֐�
VOID SET_END_IMAGE(VOID);			//�I���̑I�����̉摜�̐ݒ������֐�
VOID SET_END_SETU(VOID);			//�����Ŏg�p���鏬���i���Ȃǁj�̐ݒ������֐�
BOOL MY_MUSIC_LOAD(MUSIC *, const char *);	//����ǂݍ��ސݒ������֐�
VOID SetLevel();					//�Q�[�����x���������_���ɐݒ肷��֐�

VOID CHECK_GAME_CONTINUE(int);			//�Q�[�����s���I�������肷��֐�
VOID CHECK_GAME_START(int);				//�Q�[���J�n���I�������肷��֐�
BOOL CHECK_SELECT(int num);				//�͂��������������肷��֐��A�͂��̏ꍇ�ATRUE��Ԃ�
VOID MOVE_QUESTION(GAZOU *, RECT *);	//���̕`��ʒu���ړ�������֐�

int WRITE_SAVEDATA(int);				//�Z�[�u�f�[�^���������ފ֐�
int READ_SAVEDATA(SAVE[]);				//�Z�[�u�f�[�^��ǂݍ��ފ֐�
VOID SAVEDATA_MAX(SAVE[], int);			//�Z�[�u�f�[�^�̍ő�l���擾����֐�
VOID SAVEDATA_MIN(SAVE[], int);			//�Z�[�u�f�[�^�̍ŏ��l���擾����֐�
int DELETE_DATA(SAVE);					//�Z�[�u�f�[�^�폜�֐�

VOID SWAP(int *, int*);					//�l�����ւ���֐�
int PARTITION(SAVE[], int, int);			//pivot�����߁Apivot�����ڂɐU�蕪������֐�
VOID QUICK_SORT(SAVE[], int, int);		//�N�C�b�N�\�[�g�֐�
VOID SORT_SAVEDATA(SAVE[]);				//�Z�[�u�f�[�^���~���ɕ��בւ���֐�

VOID GET_DATEDATA();					//���t���擾����֐�

BOOL CHENGE_COLOR(int,int);					//�`��F��ύX����֐�

VOID FLASHING(int);				//�_�ŕ`��
