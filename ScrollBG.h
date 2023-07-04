/*******************************************************************************
* タイトル:		横スクロールフィールドヘッダー
* プログラム名:	Field.h
* 作成者:		GP11A132 17 鍾政殷
* 作成日:		2023/06/19
*******************************************************************************/

#pragma once	// インクルードガード（多重インクルード防止）

/*******************************************************************************
* インクルードファイル
*******************************************************************************/


/*******************************************************************************
*******************************************************************************/
#define bg_WIDTH  80
#define bg_HEIGHT 10

// プレイヤーの表示範囲
#define bg_lPOV 5 //　左
#define bg_rPOV 9 //　右 
#define bg_uPOV 4 //　上
#define bg_dPOV 4 //　下



/*******************************************************************************
* 構造体定義
*******************************************************************************/
struct LIGHT
{
	int X;
};

enum
{
	g = 0, // 重力
	F, // 床
	N, // ヌル
	A, // 障害物
	T, // トラップ
	B, // 建物
	K, // 壁
	M, // BOSS
	J, // 檻（モンスター用）
	O,
};

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
// フィールドOBJ
void InitScrollBG(void);
void UninitScrollBG(void);
void UpdateScrollBG(void);
void DrawScrollBG (void);

int GetScrollBGData(int y, int x);
void GetScrollBGData(int y, int x, int num);

LIGHT* GetLight(void);



