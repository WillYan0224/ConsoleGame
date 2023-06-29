/*******************************************************************************
* タイトル:		エネミーヘッダー
* プログラム名:	Enemy.h
* 作成者:		GP11A132 17 鍾政殷
* 作成日:		2023/06/19
*******************************************************************************/

#pragma once	// インクルードガード（多重インクルード防止）

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "Enemy.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define ENEMY_MAX 1
#define BOSS_MAX 1


/*******************************************************************************
* 構造体定義
*******************************************************************************/
struct ENEMY {
	int x;
	int y;
	int HP;
	int ox;
	int oy;
};

struct BOSS
{
	int x;
	int y;

	char shape [5][5];

};

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
// エネミーOBJ
void InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);

ENEMY* GetEnemy(void);
