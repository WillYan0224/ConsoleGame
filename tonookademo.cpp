/*******************************************************************************
* �^�C�g��:		���C���v���O����
* �v���O������:	main.cpp
* �쐬��:		GP11A132 99 �O������
* �쐬��:		2022/05/16
*******************************************************************************/

/*******************************************************************************
* scanf ��warning�h�~
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

/*******************************************************************************
* �}�N����`
*******************************************************************************/


/*******************************************************************************
* �\���̒�`
*******************************************************************************/


/*******************************************************************************
* �v���g�^�C�v�錾(�֐��̎��)
*******************************************************************************/

// Main OBJ
void Init(void);
void Uninit(void);
void Update(void);
void Draw(void);

// Field OBJ
void InitField(void);
void UninitField(void);
void UpdateField(void);
void DrawField(void);

// Player OBJ
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

// Enemy OBJ
void InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);





/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
int field[20][20] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};


// �v���C���[�̍��W
int px;
int py;

// �G�l�~�[�̍��W
int ex;
int ey;



/*******************************************************************************
 �֐���:	int main( void )
 ����:		void
 �߂�l:	����I��: int�^�� 0
 ����:		���C���֐�
*******************************************************************************/
int main( void )
{	
	
	Init();			// ����������

	while (1)
	{
		Update();	// �X�V����

		Draw();		// �`�揈��
	}

	Uninit();		// �I������
	
	/* �I�� */
	return 0;
}


// ����������
void Init(void)
{
	// �����_���̏���������
	srand((unsigned)time(NULL));

	InitField();	// Field�̏���������

	// �J�n���b�Z�[�W�̕\��
	printf("�Q�[���J�n�I\n");
	printf("AWDS�ňړ����܂�\n");

}


// �I������
void Uninit(void)
{
	UninitField();	// Field�̏I������

	// �L�[���͑҂�
	rewind(stdin);
	(void)_getch();

}


// �X�V����
void Update(void)
{
	// �t�B�[���h�̍X�V����
	UpdateField();

}


// �`�揈��
void Draw(void)
{
	// �t�B�[���h�̕\������
	DrawField();

}








// Field�̏���������
void InitField(void)
{
	// �v���C���[�̏�����
	InitPlayer();


	// �G�l�~�[�̏�����
	InitEnemy();

}


// Field�̏I������
void UninitField(void)
{
	UninitPlayer();
	UninitEnemy();

}


// �t�B�[���h�̍X�V����
void UpdateField(void)
{
	// �v���C���[�̍X�V����
	UpdatePlayer();



	// �G�l�~�[�̍X�V����
	UpdateEnemy();



}



// �t�B�[���h�̕\������
void DrawField(void)
{
	for (int y = 0; y < 20; y++)
	{
		// �P�s�\��
		for (int x = 0; x < 20; x++)
		{	
			// Y�s�ڂ�X��ڂ��v���C���[���W�Ɠ�����������
			if ((y == py) && (x == px))
			{	// P��\������
				DrawPlayer();
			}
			else if ((y == ey) && (x == ex))
			{	// P��\������
				DrawEnemy();
			}
			else
			{	// �z��̒��g�ɏ]���ĕ\������
				switch (field[y][x])
				{
				case 0:	// �ʂ��
					printf(" ");
					break;

				case 1:	// ��Q��
					printf("#");
					break;
				}
			}
		}
		printf("\n");	// ���̍s�։��s����
	}

	Sleep(200);			// Wait 1000 = 1�b
}






// �v���C���[�̏�����
void InitPlayer(void)
{
	// �v���C���[���W�̃Z�b�g
	px = 5;
	py = 5;

}


// �v���C���[�̏I������
void UninitPlayer(void)
{


}


// �v���C���[�̍X�V����
void UpdatePlayer(void)
{
	// �L�[���͂���ĂȂ��H
	if (_kbhit() == 0)
	{
		system("cls");	// ��ʃN���A
		return;
	}

	// ���݂̍��W��ۑ����Ă���
	int opx = px;
	int opy = py;

	// �L�[���͂��擾����
	rewind(stdin);
	int key = _getch();

	// ����L�[�H
	if ((key == 0) || (key == 0xe0))
	{	// �����P�x���s����ƃL�[�f�[�^���擾�ł���
		key = _getch();
	}

	system("cls");	// ��ʃN���A

	switch (key)
	{
	case 'a':		// ���ֈړ�����
	case 0x4b:		// ��
		px--;
		break;

	case 'd':		// �E�ֈړ�����
	case 0x4d:		// ��
		px++;
		break;

	case 'w':		// ��ֈړ�����
	case 0x48:		// ��
		py--;
		break;

	case 's':		// ���ֈړ�����
	case 0x50:		// ��
		py++;
		break;

	}

	// �ړ���̏ꏊ���`�F�b�N����
	switch (field[py][px])
	{
	case 0:
		break;

	case 1:
		px = opx;
		py = opy;
		break;
	}

}


// �v���C���[�̕`�揈��
void DrawPlayer(void)
{
	printf("P");

}





// �G�l�~�[�̏�����
void InitEnemy(void)
{
	// �v���C���[���W�̃Z�b�g
	ex = 10;
	ey = 10;

}


// �G�l�~�[�̏I������
void UninitEnemy(void)
{


}



void UpdateEnemy(void)
{
	// ���݂̍��W��ۑ����Ă���
	int oex = ex;
	int oey = ey;

	//// �L�[���͂��擾����
	//rewind(stdin);
	//int key = _getch();

	int key = rand() % 12;

	switch (key)
	{
	case 0:		// ���ֈړ�����
		ex--;
		break;

	case 1:		// �E�ֈړ�����
		ex++;
		break;

	case 2:		// ��ֈړ�����
		ey--;
		break;

	case 3:		// ���ֈړ�����
		ey++;
		break;

		// �V��
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
		break;

	}

	// �ړ���̏ꏊ���`�F�b�N����
	switch (field[ey][ex])
	{
	case 0:
		break;

	case 1:
		ex = oex;
		ey = oey;
		break;
	}

}


void DrawEnemy(void)
{
	printf("E");

}



