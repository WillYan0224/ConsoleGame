/*******************************************************************************
* �^�C�g��:		2D�t�B�[���h
* �v���O������:	main.cpp
* �쐬��:		GP11A132 17 �ߐ��u
* �쐬��:		2022/06/05
*******************************************************************************/


/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include "main.h"
#include "Title.h"
#include "Player.h"
#include "Enemy.h"
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

// �V�[���J�ڗp�̕ϐ�
int mode = 0; // 0: Title 1: Field 2:

/*******************************************************************************
 �֐���:	int main (void)
 ����:		void
 �߂�l:		0
 ����:		���C��
*******************************************************************************/


int main(void)
{
/*
	***************************************
	*�@�@�@�����ݒ�                          *
	*�@�@�@Game Loop                       *
	*�@�@�@�@�P�@�A�b�v�f�[�g                 *
	*�@�@�@�@�Q�@�`��                        *
	***************************************
*/
	Init(); // ����������
	while (1) {
		Update();		// �X�V����
		Draw();			// �`�揈��
	}
	Uninit();
	
	/* �I�� */
	return 0;
}

// �t�B�[���h�̕\������
void UpdateField(void) {

	// �v���C���[���W�̍X�V����
	UpdatePlayer();
	
	// �G�l�~�[���W�̍X�V����
	UpdateEnemy();

	//if ((player[0].x == enemy[0].x && player[0].y == enemy[0].y) || (player[0].x == enemy[1].x && player[0].y == enemy[1].y)) {
	//	printf("�퓬�J�n�I�I\n\n");
	//}
}

// ����������
void Init(void) {

	// �����_���̏���������
	srand((unsigned)time(NULL));

	InitField();	//�@�t�B�[���h�̏���������
	InitTitle();	//�@�^�C�g���̏���������



	// �J�n���b�Z�[�W�̕\��
	printf("�Q�[���J�n�I\n");
	printf("���������ňړ����܂�\n");
	// printf("WASD�ňړ����܂�\n");

}

// �I������
void Uninit(void) {

	UninitField();	//�@�t�B�[���h�̏I������
	UninitTitle();	//�@�^�C�g���̏I������
	
	// �L�[���͑҂�
	rewind(stdin);
	(void)_getch();

}

// �X�V����
void Update(void) {
	switch (GetMode()){
	case GAME_TITLE:
		// �^�C�g���̍X�V����
		UpdateTitle();
		break;
	case GAME_FIELD:
		// �t�B�[���h�̍X�V����
		UpdateField();
		break;
	default:
		printf("[Error]: Mode out of range: %d\n", mode);
	}
}

// �`�揈��
void Draw(void) {
	switch (GetMode()) {
	case GAME_TITLE:
		// �^�C�g���̕\������
		DrawTitle();
		break;
	case GAME_FIELD:
		// �t�B�[���h�̕\������
		DrawField();
		break;
	default:
		printf("[Error]: Mode out of range: %d\n", mode);
	}
}

// �V�[���J�ڗp�̊֐�
// �Z�b�^�[
void SetMode(int no) {
	mode = no;
}
// �Q�b�^�[
int GetMode(void) {
	return mode;
}


