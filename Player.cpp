/*******************************************************************************
* �^�C�g��:		�v���C���[�v���O����
* �v���O������:	Player.cpp
* �쐬��:		GP11A132 17 �ߐ��u
* �쐬��:		2023/06/19
*******************************************************************************/



/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "Player.h"


#include "Field.h"
#include "Title.h"
#include "ScrollBG.h"


/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/

/*******************************************************************************
* �v���g�^�C�v�錾
*******************************************************************************/

/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
PLAYER player[PLAYER_MAX];


/*******************************************************************************
 �֐���:	
 �����@:	
 �߂�l:	
 �����@:	
*******************************************************************************/

// �v���C���[�̏�����
void InitPlayer(void) {


	if(player[0].isNamed != PLAYER_NAMED)
	{
		printf("���l��A�����O�́H���@");
		(void)scanf("%s", player[0].name);
		player[0].isNamed = PLAYER_NAMED;
	}
	
	switch (GetMode())
	{
	case GAME_FIELD:
		player[0].x = 1;
		player[0].y = 1;
		player[0].HP = 30;
		player[0].str = 30;
		break;
	case GAME_TITLE:
		player[0].x = 4;
		player[0].y = 3;
		break;
	case GAME_SCROLL:
		player[0].x = 2;
		player[0].y = 7;
	}

	Sleep(200);
	player[0].status = ERROR_NO;
}
// �v���C���[�̏I������
void UninitPlayer(void) {

}
// �v���C���[�̍X�V����
void UpdatePlayer(void) {

	if (_kbhit() == 0) {
		system("cls");
		return;
	}

	// ���݂̍��W��ۑ����Ă���
	int opx = player[0].x;
	int opy = player[0].y;

	// �L�[���͂��擾����
	rewind(stdin);
	int key = _getch();
	if (key == 0 || key == 0xe0) {
		key = _getch(); // �߂�l�FASCII�R�[�h
	}
	system("cls");

	// printf("key: %d\n\n", key);

	// �L�[�{�[�h����ǂݍ��� 0x�Ƃ�16�i�� \0�Ƃ�8�i��

	

	// �t�B�[���h����
	if(GetMode() == GAME_FIELD)
	{
		ENTITY* entity = GetEntity();
		switch (key) {
		case 'w':
			player[0].y--;
			break;
		case 'a':
			player[0].x--;
			break;
		case 's':
			player[0].y++;
			break;
		case 'd':
			player[0].x++;
			break;
		}
		switch (GetFieldData(player[0].y, player[0].x)) {
			case 0:
				break;
			case 1:
				player[0].y = opy;
				player[0].x = opx;
				break;
			case 2:
				entity->X++;
				SetFieldData(player[0].y, player[0].x, 0);
				break;
			case 3:
				entity->key++;
				SetFieldData(player[0].y, player[0].x, 0);
				break;
			case 4:
				if (entity->key <= 0) {
					player[0].status = ERROR_KEY;
					player[0].y = opy;
					player[0].x = opx;
				}
				else{
					entity->key--;
					SetFieldData(player[0].y, player[0].x, 0);
				}
				break;
			default:
				printf("$");
				break;
		}
	}
	// ���X�N���[���t�B�[���h����
	if(GetMode() == GAME_SCROLL)
	{
		LIGHT* light = GetLight();

		switch (key) {
		case 'a':
			player[0].x--;
			break;
		case 'd':
			player[0].x++;
			break;
		}

		switch (GetScrollBGData(player[0].y, player[0].x)) {
			case g: // �d��
				player[0].y++;
				break;
			case N:
				break;
			case F: // ��
				player[0].y = opy ;
				break;
			case B: // �������ʂ�Ȃ�
			case K:
				player[0].x = opx;
				break;
			case T:
				SetMode(GAME_OVER);
				system("cls");
				break;
			case M:
				SetMode(GAME_FIELD);
				Init();
				system("cls");
		}
	}

	// TITLE����
	if (GetMode() == GAME_TITLE)
	{
		CAMERA* camera = GetCamera();
		switch (key) {
		case 'd':
			player[0].x++;
			break;
		}
		switch (GetTitleData(player[0].y, player[0].x)) {
		case 0:
			break;
		case 1:
			player[0].y = opy;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			camera->X++;
			SetTitleData(player[0].y, player[0].x, 0);
			break;
		case 5:
			break;
		case 7:
			if (key == 'd' || key == 0x4d)
			{
				player[0].x = opx;
				player[0].y++;
			}
			break;
		case 8:
			Sleep(500);
			SetMode(GAME_SCROLL);
			InitPlayer();
			break;
		case 9:
			SetTitleData(10, 13, iC);
			SetTitleData(10, 14, iH);
			SetTitleData(10, 15, iU);
			SetTitleData(10, 16, iN);
			SetTitleData(10, 17, iG);
			SetTitleData(10, 19, iC);
			SetTitleData(10, 20, iH);
			SetTitleData(10, 21, iI);
			SetTitleData(10, 22, iN);
			SetTitleData(10, 23, iG);
			SetTitleData(10, 24, iY);
			SetTitleData(10, 25, iA);
			SetTitleData(10, 26, iN);
			break;
		case 10:
			SetTitleData(10, 27, 0);
			SetTitleData(10, 28, 5);
			SetTitleData(10, 29, 0);

			SetTitleData(10, 30, iH);
			SetTitleData(10, 31, iA);
			SetTitleData(10, 32, iL);
			SetTitleData(10, 34, iT);
			SetTitleData(10, 35, iO);
			SetTitleData(10, 36, iK);
			SetTitleData(10, 37, iY);
			SetTitleData(10, 38, iO);

			SetTitleData(10, 39, 0);
			SetTitleData(10, 40, 5);
			SetTitleData(10, 41, 0);

			SetTitleData(10, 42, i2);
			SetTitleData(10, 43, i0);
			SetTitleData(10, 44, i2);
			SetTitleData(10, 45, i3);
			break;
		default:
			printf("$");
			break;
		}
	}
}
// �v���C���[�̕`�揈��
void DrawPlayer(void) {
	printf("P");
}

PLAYER* GetPlayer(void) {
	return player;
}



