/*******************************************************************************
* タイトル:		フィールドプログラム
* プログラム名:	Field.h
* 作成者:		GP11A132 17 鍾政殷
* 作成日:		2023/06/19
*******************************************************************************/

#pragma once	// インクルードガード（多重インクルード防止）

/*******************************************************************************
* インクルードファイル
*******************************************************************************/


/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define WIDTH  25
#define HEIGHT 20

// プレイヤーの表示範囲
#define lPOV 5 //　左
#define rPOV 5 //　右 
#define uPOV 4 //　上
#define dPOV 4 //　下

/*******************************************************************************
* 構造体定義
*******************************************************************************/

struct ENTITY
{
	int X; // 横軸ライド
	int Y; // 縦軸ライド

	int key; // キー
};

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
// フィールドOBJ
void InitField(void);
void UninitField(void);
void UpdateField(void);
void DrawField(void);

int getFieldData(int y, int x);
void setFieldData(int y, int x, int num);

ENTITY* getEntity();



