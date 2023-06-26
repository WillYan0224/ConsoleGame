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
	player[0].x = 1;
	player[0].y = 1;
	player[0].HP = 30;

	printf("���l��A�����O�́H���@");
	scanf("%s", player[0].name);
	Sleep(1500);

	player[0].log = ERROR_NO;
}
// �v���C���[�̏I������
void UninitPlayer(void) {

}
// �v���C���[�̍X�V����
void UpdatePlayer(void) {
	ENTITY* entity = getLigth();

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

	// �ړ���̏ꏊ���`�F�b�N����
	switch (getFieldData(player->y, player->x)) {
		case 0:
			break;
		case 1:
			player->y = opy;
			player->x = opx;
			break;
		case 2:
			entity->X++;
			setFieldData(player->y, player->x, 0);
			break;
		case 3:
			entity->key++;
			setFieldData(player->y, player->x, 0);
		case 4:
			if (entity->key <= 0) {
				player->log = ERROR_KEY;
				player->y = opy;
				player->x = opx;
			}
			else{
				entity->key--;
				setFieldData(player->y, player->x, 0);
			}
			break;
		default:
			printf("$");
			break;
	}
}
// �v���C���[�̕`�揈��
void DrawPlayer(void) {
	printf("P");
}

PLAYER* getPlayer(void) {
	return player;
}



