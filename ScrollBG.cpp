/*******************************************************************************
* タイトル:		横スクロールフィールドプログラム
* プログラム名:	Field.cpp
* 作成者:		GPBBAB32 B7 鍾政殷
* 作成日:		2023/06/B9
*******************************************************************************/



/*******************************************************************************
* インクルードファイル
*******************************************************************************/

#include "Player.h"
#include "Enemy.h"
#include "ScrollBG.h"
#include "main.h"
#include "Block.h"

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
LIGHT light;


// 2Dフィールド　80 * B0
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
 関数名:	
 引数　:	
 戻り値:	
 説明　:	
*******************************************************************************/

// フィールドの初期化処理
void InitScrollBG(void) {
	light.X = 6;
	// プレイヤーの初期化 
	InitPlayer();
	// ブロックの初期化
	InitBlock();

	// エネミーの初期化
	InitEnemy();
}

void UpdateScrollBG(void) {
	//　アニメーションカウンターを進める


	UpdatePlayer();
	UpdateEnemy();
	UpdateBlock();
	// モード切り替え

	// SetMode(GAME_FIELD); // フィールドへ遷移

}

// フィールドの終了処理

// フィールド表示処理
void DrawScrollBG(void) {
	
	PLAYER* player = GetPlayer();
	ENEMY* enemy = GetEnemy();
	BLOCK* block = GetBlock();
		printf("\n     ");
		for (int y = player->y - bg_uPOV; y < player->y + bg_dPOV; y++) {
			// B行表示
			for (int x = player->x - bg_lPOV; x < player->x + bg_rPOV + light.X; x++) {
				if (y < 0 || y >= bg_HEIGHT || x < 0 || x >= bg_WIDTH) {
					printf(" ");
				}
				// Y行目のX列目がプレイヤーの座標と一致したら
				else if (x == player->x && y == player->y) {
					// Pを表示
					DrawPlayer();
				}
				else if (x == block->x && y == block->y) {
					// Bを表示
					DrawBlock();
				}
				else if ((x == enemy->x && y == enemy->y))
				{
					// Mを表示
					DrawEnemy();
				}
				else if((x == block->bx && y == block->y))
				{
					// :を表示
					DrawBullet();
				}
				else { 
					// 配列の中身にしたがって表示する
					switch (scrollBG[y][x]) {
					case g: // 重力
						printf(" ");
						break;
					case N: // 何もない
						printf(" ");
						break;
					case T: // トラップ
						printf("/");
						break;
					case B: // 建物
						printf("#");
						break;
					case K: // 壁
						printf("!");
						break;
					case M: // ゴール
						printf("O");
						break;
					case J:
						printf("J");
						break;
					default: // エラー検知
						printf("$");
						break;
					}
				}
			}
			printf("\n     ");
		}
		printf("\n\n A: プレイヤー左移動\tD: プレイヤー右移動\n ←: ブロック左移動\t→: ブロック右移動\n r: ブロックの位置までテレポート\n c: 魔法の追尾玉発射\n");

		switch (player->status)
		{
		case SCROLL_TUTORIAL:
			printf("\n\n  ///とMを避けながら終点まで行こう！");
			break;
		case SCROLL_GOAL:
			printf("\n\n よくここにたどり着いたな！もしや、逃げられると思っていたのか！");
			break;
		}
		Sleep(150);
}


void UninitScrollBG(void) {
	UninitPlayer();
	UninitEnemy();
}

// 指定されたXY座標を返す
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




