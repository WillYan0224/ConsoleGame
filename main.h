/*******************************************************************************
* タイトル:		メインヘッダー
* プログラム名:	main.h
* 作成者:		GP11A132 17 鍾政殷
* 作成日:		2023/06/14
*******************************************************************************/

#pragma once	// インクルードガード（多重インクルード防止）

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
enum {
	GAME_TITLE,
	GAME_FIELD,
	GAME_BATTLE,

	GAME_MAX,
};

enum {
	TITLE_NEWGAME,
	TITLE_LOADGAME,
	TITLE_OPTION,

	TITLE_MAX,
};
/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
// mainOBJ
void Init(void);
void Uninit(void);
void Update(void);
void Draw(void);

// モードのセッター
void SetMode(int no);
// モードのゲッター
int GetMode(void);




