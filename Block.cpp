/*******************************************************************************
* タイトル:		横スクロールフィールドプログラム
* プログラム名:	Field.cpp
* 作成者:		GP11A132 17 鍾政殷
* 作成日:		2023/06/19
*******************************************************************************/



/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "Block.h"
#include "ScrollBG.h"
#include "main.h"
#include "Player.h"
#include "Enemy.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/


/*******************************************************************************
* グローバル変数
*******************************************************************************/
BLOCK block[BLOCK_MAX];


/*******************************************************************************
 関数名:
 引数　:
 戻り値:
 説明　:
*******************************************************************************/

// フィールドの初期化処理
void InitBlock(void) {

	PLAYER* p = GetPlayer();
	block[0].x = p->x + 1;
	block[0].y = p->y - 3;
}

// フィールドの終了処理
void UninitBlock(void) {

}
void UpdateBlock(void)
{
	PLAYER* p = GetPlayer();
	ENEMY* e = GetEnemy();

	if (_kbhit() == 0) {
		system("cls");
		return;
	}

	// 現在の座標を保存しておく
	int opx = block[0].x;
	int opy = block[0].y;

	// キー入力を取得する
	rewind(stdin);
	int key = _getch();
	if (key == 0 || key == 0xe0) {
		key = _getch(); // 戻り値：ASCIIコード
	}
	system("cls");

	
	// キーボードから読み込み 0xとは16進数 \0とは8進数
	// 横スクロールフィールド処理
	if (GetMode() == GAME_SCROLL)
	{
		LIGHT* light = GetLight();
		block[0].y = p->y - 2;
		switch (key) {
			case 0x4b:
				block[0].x--;
				break;
			case 0x4d:
				block[0].x++;
				break;
			case 'r':
				{
					int tempx = p->x;
					int tempy = p->y;
					p->x = block[0].x;
					p->y = block[0].y;
					block[0].x = p->x;
					block[0].y = p->y;
					break;
				}
		}
		switch (GetScrollBGData(block[0].y, block[0].x)) {
		case B: // 建物等通れない
		case K:
			block[0].x = opx;
			break;
		}
	}
}

// フィールド表示処理

void DrawBlock(void)
{
	printf("B");
}

// 指定されたXY座標を返す
BLOCK* GetBlock(void)
{
	return block;
}
void SetBlock(int y, int x, int num)
{
	
}