/*******************************************************************************
* タイトル:		メインプログラム
* プログラム名:	main.cpp
* 作成者:		GP11A132 99 外岡高明
* 作成日:		2022/05/16
*******************************************************************************/

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言(関数の取説)
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
* グローバル変数
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


// プレイヤーの座標
int px;
int py;

// エネミーの座標
int ex;
int ey;



/*******************************************************************************
 関数名:	int main( void )
 引数:		void
 戻り値:	正常終了: int型の 0
 説明:		メイン関数
*******************************************************************************/
int main( void )
{	
	
	Init();			// 初期化処理

	while (1)
	{
		Update();	// 更新処理

		Draw();		// 描画処理
	}

	Uninit();		// 終了処理
	
	/* 終了 */
	return 0;
}


// 初期化処理
void Init(void)
{
	// ランダムの初期化処理
	srand((unsigned)time(NULL));

	InitField();	// Fieldの初期化処理

	// 開始メッセージの表示
	printf("ゲーム開始！\n");
	printf("AWDSで移動します\n");

}


// 終了処理
void Uninit(void)
{
	UninitField();	// Fieldの終了処理

	// キー入力待ち
	rewind(stdin);
	(void)_getch();

}


// 更新処理
void Update(void)
{
	// フィールドの更新処理
	UpdateField();

}


// 描画処理
void Draw(void)
{
	// フィールドの表示処理
	DrawField();

}








// Fieldの初期化処理
void InitField(void)
{
	// プレイヤーの初期化
	InitPlayer();


	// エネミーの初期化
	InitEnemy();

}


// Fieldの終了処理
void UninitField(void)
{
	UninitPlayer();
	UninitEnemy();

}


// フィールドの更新処理
void UpdateField(void)
{
	// プレイヤーの更新処理
	UpdatePlayer();



	// エネミーの更新処理
	UpdateEnemy();



}



// フィールドの表示処理
void DrawField(void)
{
	for (int y = 0; y < 20; y++)
	{
		// １行表示
		for (int x = 0; x < 20; x++)
		{	
			// Y行目のX列目がプレイヤー座標と同じだったら
			if ((y == py) && (x == px))
			{	// Pを表示する
				DrawPlayer();
			}
			else if ((y == ey) && (x == ex))
			{	// Pを表示する
				DrawEnemy();
			}
			else
			{	// 配列の中身に従って表示する
				switch (field[y][x])
				{
				case 0:	// 通れる
					printf(" ");
					break;

				case 1:	// 障害物
					printf("#");
					break;
				}
			}
		}
		printf("\n");	// 次の行へ改行する
	}

	Sleep(200);			// Wait 1000 = 1秒
}






// プレイヤーの初期化
void InitPlayer(void)
{
	// プレイヤー座標のセット
	px = 5;
	py = 5;

}


// プレイヤーの終了処理
void UninitPlayer(void)
{


}


// プレイヤーの更新処理
void UpdatePlayer(void)
{
	// キー入力されてない？
	if (_kbhit() == 0)
	{
		system("cls");	// 画面クリア
		return;
	}

	// 現在の座標を保存しておく
	int opx = px;
	int opy = py;

	// キー入力を取得する
	rewind(stdin);
	int key = _getch();

	// 特殊キー？
	if ((key == 0) || (key == 0xe0))
	{	// もう１度実行するとキーデータが取得できる
		key = _getch();
	}

	system("cls");	// 画面クリア

	switch (key)
	{
	case 'a':		// 左へ移動する
	case 0x4b:		// ←
		px--;
		break;

	case 'd':		// 右へ移動する
	case 0x4d:		// →
		px++;
		break;

	case 'w':		// 上へ移動する
	case 0x48:		// ↑
		py--;
		break;

	case 's':		// 下へ移動する
	case 0x50:		// ↓
		py++;
		break;

	}

	// 移動後の場所をチェックする
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


// プレイヤーの描画処理
void DrawPlayer(void)
{
	printf("P");

}





// エネミーの初期化
void InitEnemy(void)
{
	// プレイヤー座標のセット
	ex = 10;
	ey = 10;

}


// エネミーの終了処理
void UninitEnemy(void)
{


}



void UpdateEnemy(void)
{
	// 現在の座標を保存しておく
	int oex = ex;
	int oey = ey;

	//// キー入力を取得する
	//rewind(stdin);
	//int key = _getch();

	int key = rand() % 12;

	switch (key)
	{
	case 0:		// 左へ移動する
		ex--;
		break;

	case 1:		// 右へ移動する
		ex++;
		break;

	case 2:		// 上へ移動する
		ey--;
		break;

	case 3:		// 下へ移動する
		ey++;
		break;

		// 遊び
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

	// 移動後の場所をチェックする
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



