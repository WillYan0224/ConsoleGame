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


	if(player[0].status != PLAYER_NAMED)
	{
		printf("���l��A�����O�́H���@");
		(void)scanf("%s", player[0].name);
		player[0].status = PLAYER_NAMED;
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
	}

	Sleep(1500);
	player[0].status = ERROR_NO;
}
// �v���C���[�̏I������
void UninitPlayer(void) {

}
// �v���C���[�̍X�V����
void UpdatePlayer(void) {
	ENTITY* entity = GetEntity();
	CAMERA* camera = GetCamera();

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

	

	// �ړ���̏ꏊ���`�F�b�N����
	if(GetMode() == GAME_FIELD)
	{
		switch (key) {
		case 'w':
		case 0x48:
			player[0].y--;
			break;
		case 'a':
		case 0x4b:
			player[0].x--;
			break;
		case 's':
		case 0x50:
			player[0].y++;
			break;
		case 'd':
		case 0x4d:
			player[0].x++;
			break;
		}
		switch (GetFieldData(player->y, player->x)) {
			case 0:
				break;
			case 1:
				player->y = opy;
				player->x = opx;
				break;
			case 2:
				entity->X++;
				SetFieldData(player->y, player->x, 0);
				break;
			case 3:
				entity->key++;
				SetFieldData(player->y, player->x, 0);
				break;
			case 4:
				if (entity->key <= 0) {
					player->status = ERROR_KEY;
					player->y = opy;
					player->x = opx;
				}
				else{
					entity->key--;
					SetFieldData(player->y, player->x, 0);
				}
				break;
			default:
				printf("$");
				break;
		}
	}

	if(GetMode() == GAME_TITLE)
	{
		switch (key) {
		case 'd':
		case 0x4d:
			player[0].x++;
			player[0].y++;
			break;
		}
		switch (GetTitleData(player->y, player->x)) {
			case 0:

				break;
			case 1:
				player->y = opy;
				camera->X++;
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				
				SetTitleData(player->y, player->x, 0);
				break;
			case 5:
				break;
			default:
				printf("$");
				break;
		}
	}
	// title


}
// �v���C���[�̕`�揈��
void DrawPlayer(void) {
	printf("P");
}

PLAYER* GetPlayer(void) {
	return player;
}



