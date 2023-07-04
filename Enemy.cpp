/*******************************************************************************
* タイトル:		エネミープログラム
* プログラム名:	Enemy.cpp
* 作成者:		GP11A132 17 鍾政殷
* 作成日:		2023/06/19
*******************************************************************************/



/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "Enemy.h"
#include "Player.h"
#include "Field.h"

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
ENEMY enemy[ENEMY_MAX];

/*******************************************************************************
 関数名:	
 引数　:	
 戻り値:	
 説明　:	
*******************************************************************************/
// エネミーの初期化
void InitEnemy(void) {
	if(GetMode() == GAME_FIELD)
	{
		enemy[0].x = 8;
		enemy[0].y = 8;
		enemy[0].HP = 100;
	}
	if (GetMode() == GAME_SCROLL)
	{
		enemy[0].x = 8;
		enemy[0].y = 5;
		enemy[0].HP = 3;
	}
}
// エネミーの終了処理
void UninitEnemy(void) {

}
// エネミーの更新処理
void UpdateEnemy(void) {
	// 現在の座標を保存しておく エネミー.ver


	PLAYER* player = GetPlayer();

	enemy[0].ox = enemy[0].x;
	enemy[0].oy = enemy[0].y;


	if(GetMode() == GAME_FIELD)
	{
		for (int i = 0; i < ENEMY_MAX; i++){
			int rng = rand() % 20;
			switch(rng)
			{
			case 0:
				enemy[i].x--;
				break;
			case 1:
				enemy[i].x++;
				break;
			case 2:
				enemy[i].y--;
				break;
			case 3:
				enemy[i].y++;
				break;
			default:
				break;
			}
			
		}
		
		// 移動後の場所をチェックする　エネミー.ver
		for (int i = 0; i < ENEMY_MAX; i++) {
			switch (GetFieldData( (enemy + i)->y, (enemy + i)->x)) {
			case 0:
				break;
			case 1:
				enemy[i].y = enemy[i].oy;
				enemy[i].x = enemy[i].ox;
				break;
			default:
				printf("$");
				break;
			}
		}
	}

	if(GetMode() == GAME_SCROLL)
	{
		for (int i = 0; i < ENEMY_MAX; i++) {
			int rng = rand() % 4;
			switch (rng)
			{
			case 0:
				enemy[i].x--;
				break;
			case 1:
				enemy[i].x++;
				break;
			}
		}

		// 移動後の場所をチェックする　エネミー.ver
		for (int i = 0; i < ENEMY_MAX; i++) {
			switch (GetFieldData((enemy + i)->y, (enemy + i)->x)) {
			case 0:
				break;
			case 1:
				enemy[i].y = enemy[i].oy;
				enemy[i].x = enemy[i].ox;
				break;
			default:
				printf("$");
				break;
			}
		}
	}
	
}
// エネミーの描画処理
void DrawEnemy(void) {
	printf("M");
}

ENEMY* GetEnemy(void) {
	return enemy;
}







