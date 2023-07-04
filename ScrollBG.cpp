/*******************************************************************************
* �^�C�g��:		���X�N���[���t�B�[���h�v���O����
* �v���O������:	Field.cpp
* �쐬��:		GPBBAB32 B7 �ߐ��u
* �쐬��:		2023/06/B9
*******************************************************************************/



/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/

#include "Player.h"
#include "Enemy.h"
#include "ScrollBG.h"
#include "main.h"
#include "Block.h"

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
LIGHT light;


// 2D�t�B�[���h�@80 * B0
int scrollBG[bg_HEIGHT][bg_WIDTH] =
{ 
	B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B,
	B, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g,	g, K, g, g, g, T, T, T, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, B,
	B, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g,	g, K, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, M, M, M, M, g, g, g, g, B,
	B, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g, g,	g, g, g, g, g, g, g, g, N, N, N, g, g, g, g, g, N, N, N, N, J, N, N, N, N, N, N, N, N, N, N, N, N, J, g, g, g, g, g, g, g, g, g, g, g, g, N, g, g, g, g, M, M, M, M, g, g, g, g, B,
	B, g, g, g, g, g, g, g, g, g, g, g, g, g, J, N, N, N, J, g,	g, g, N, N, N, g, K, g, B, B, B, g, N, N, N, g, B, B, B, B, g, B, B, B, B, B, B, B, B, B, B, B, B, g, g, g, g, g, g, g, g, g, g, g, N, g, B, g, g, g, g, M, M, M, M, g, g, g, g, B,
	B, g, g, g, g, g, g, g, g, g, g, g, g, g, g, B, B, B, N, N,	N, g, B, B, B, g, K, g, N, N, N, g, g, g, g, g, g, g, g, g, g, B, B, B, B, B, B, B, B, B, B, B, B, g, g, g, g, g, g, g, g, g, N, g, B, g, B, g, N, N, N, M, M, M, M, g, g, g, g, B,
	B, g, g, g, g, g, g, g, g, J, N, N, N, J, g, B, B, B, B, B,	B, g, N, N, N, g, K, g, g, g, g, g, B, B, B, g, g, g, g, g, g, B, B, B, B, B, B, B, B, B, B, B, B, g, g, g, g, g, g, g, N, N, B, g, B, g, B, g, B, B, B, B, B, B, B, B, g, g, g, B,
	B, N, N, N, N, N, N, g, g, g, B, B, B, g, g, g, g, g, B, B, B, N, T, g, g, g, K, g, B, B, B, g, N, N, N, N, N, N, N, N, g, B, B, B, B, B, B, B, B, B, B, B, B, g, N, N, N, N, N, N, B, B, B, g, B, g, B, g, B, B, B, B, B, B, B, B, g, g, g, B,
	B, B, B, B, B, B, B, g, g, g, B, B, B, g, g, g, g, g, B, B, B, B, T, T, T, g, K, g, g, g, g, g, B, B, B, B, B, B, B, B, g, g, g, g, g, g, g, g, g, g, g, g, g, g, B, B, B, B, B, B, B, B, B, g, B, g, B, g, B, B, B, B, B, B, B, B, g, g, g, B,
	B, g, g, g, g, g, g, T, T, T, B, B, B, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, B, T, T, T, T, T, T, T, T, T, T, T, T, T, T, B,
};

// # / - O 

/*******************************************************************************
 �֐���:	
 �����@:	
 �߂�l:	
 �����@:	
*******************************************************************************/

// �t�B�[���h�̏���������
void InitScrollBG(void) {
	light.X = 6;
	// �v���C���[�̏����� 
	InitPlayer();
	// �u���b�N�̏�����
	InitBlock();

	// �G�l�~�[�̏�����
	InitEnemy();
}

void UpdateScrollBG(void) {
	//�@�A�j���[�V�����J�E���^�[��i�߂�


	UpdatePlayer();
	UpdateEnemy();
	UpdateBlock();
	// ���[�h�؂�ւ�

	// SetMode(GAME_FIELD); // �t�B�[���h�֑J��

}

// �t�B�[���h�̏I������

// �t�B�[���h�\������
void DrawScrollBG(void) {
	
	PLAYER* player = GetPlayer();
	ENEMY* enemy = GetEnemy();
	BLOCK* block = GetBlock();
		printf("\n     ");
		for (int y = player->y - bg_uPOV; y < player->y + bg_dPOV; y++) {
			// B�s�\��
			for (int x = player->x - bg_lPOV; x < player->x + bg_rPOV + light.X; x++) {
				if (y < 0 || y >= bg_HEIGHT || x < 0 || x >= bg_WIDTH) {
					printf(" ");
				}
				// Y�s�ڂ�X��ڂ��v���C���[�̍��W�ƈ�v������
				else if (x == player->x && y == player->y) {
					// P��\��
					DrawPlayer();
				}
				else if (x == block->x && y == block->y) {
					// B��\��
					DrawBlock();
				}
				else if ((x == enemy->x && y == enemy->y))
				{
					// M��\��
					DrawEnemy();
				}
				else if((x == block->bx && y == block->y))
				{
					// :��\��
					DrawBullet();
				}
				else { 
					// �z��̒��g�ɂ��������ĕ\������
					switch (scrollBG[y][x]) {
					case g: // �d��
						printf(" ");
						break;
					case N: // �����Ȃ�
						printf(" ");
						break;
					case T: // �g���b�v
						printf("/");
						break;
					case B: // ����
						printf("#");
						break;
					case K: // ��
						printf("!");
						break;
					case M: // �S�[��
						printf("O");
						break;
					case J:
						printf("J");
						break;
					default: // �G���[���m
						printf("$");
						break;
					}
				}
			}
			printf("\n     ");
		}
		printf("\n\n A: �v���C���[���ړ�\tD: �v���C���[�E�ړ�\n ��: �u���b�N���ړ�\t��: �u���b�N�E�ړ�\n r: �u���b�N�̈ʒu�܂Ńe���|�[�g\n c: ���@�̒ǔ��ʔ���\n");

		switch (player->status)
		{
		case SCROLL_TUTORIAL:
			printf("\n\n  ///��M������Ȃ���I�_�܂ōs�����I");
			break;
		case SCROLL_GOAL:
			printf("\n\n �悭�����ɂ��ǂ蒅�����ȁI������A��������Ǝv���Ă����̂��I");
			break;
		}
		Sleep(150);
}


void UninitScrollBG(void) {
	UninitPlayer();
	UninitEnemy();
}

// �w�肳�ꂽXY���W��Ԃ�
int GetScrollBGData(int y, int x) {
	return scrollBG[y][x];
}
void SetScrollBGData(int y, int x, int num)
{
	scrollBG[y][x] = num;
}

LIGHT* GetLight()
{
	return &light;
}




