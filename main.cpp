/*******************************************************************************
* タイトル:		2Dフィールド
* プログラム名:	main.cpp
* 作成者:		GP11A132 17 鍾政殷
* 作成日:		2022/06/05
*******************************************************************************/


/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "Title.h"
#include "Player.h"
#include "Enemy.h"
#include "Field.h"
#include "ScrollBG.h"
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

// シーン遷移用の変数
int mode = 0; // 0: Title 1: Field 2:

/*******************************************************************************
 関数名:	int main (void)
 引数:		void
 戻り値:		0
 説明:		メイン
*******************************************************************************/


int main(void)
{
/*	
	***************************************
	*　　　初期設定                          *
	*　　　Game Loop                       *
	*　　　　１　アップデート                 *
	*　　　　２　描画                        *
	***************************************
*/
	Init(); // 初期化処理
	while (1) {
		Update();		// 更新処理
		Draw();			// 描画処理
	}
	Uninit();
	
	/* 終了 */
	return 0;
}

// 初期化処理
void Init(void) {

	// ランダムの初期化処理
	srand((unsigned)time(NULL));

	InitTitle();	//　タイトルの初期化処理
	InitScrollBG(); //  スクロールフィールドの初期化処理
	InitField();	//　フィールドの初期化処理

	// 開始メッセージの表示
	printf("ゲーム開始！\n");
	printf("←↑→↓で移動します\n");
	// printf("WASDで移動します\n");
	// キー入力待ち
	rewind(stdin);
	(void)_getch();
}

// 終了処理
void Uninit(void) {

	UninitTitle();		//　タイトルの終了処理
	UninitScrollBG();	//  スクロールフィールドの終了処理
	UninitField();		//　フィールドの終了処理

	// キー入力待ち
	rewind(stdin);
	(void)_getch();

}

// 更新処理
void Update(void) {
	switch (GetMode()){
	case GAME_TITLE:
		// タイトルの更新処理
		UpdateTitle();
		break;
	case GAME_SCROLL:
		UpdateScrollBG();
		break;
	case GAME_FIELD:
		// フィールドの更新処理
		UpdateField();
		break;
	case GAME_BATTLE:
		// バトルの更新処理
		break;
	default:
		printf("[Error]: Mode out of range: %d\n", mode);
	}
}

// 描画処理
void Draw(void) {
	switch (GetMode()) {
	case GAME_TITLE:
		// タイトルの表示処理
		DrawTitle();
		break; 
	case GAME_SCROLL:
		DrawScrollBG();
		break;
	case GAME_FIELD:
		// フィールドの表示処理
		DrawField();
		break;
		//　バトルの表示処理
	case GAME_BATTLE:

		break;
		//　音ゲーの更新処理

	default:
		printf("[Error]: Mode out of range: %d\n", mode);
	}
}

// シーン遷移用の関数
// セッター
void SetMode(int no) {
	mode = no;
}
// ゲッター
int GetMode(void) {
	return mode;
}



