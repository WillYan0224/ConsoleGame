/*******************************************************************************
* タイトル:		プレイヤープログラム
* プログラム名:	Player.cpp
* 作成者:		GP11A132 17 鍾政殷
* 作成日:		2023/06/19
*******************************************************************************/



/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
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
PLAYER player[PLAYER_MAX];

/*******************************************************************************
 関数名:	
 引数　:	
 戻り値:	
 説明　:	
*******************************************************************************/

// プレイヤーの初期化
void InitPlayer(void) {
	player[0].x = 1;
	player[0].y = 1;
	player[0].HP = 30;

	printf("旅人よ、お名前は？←　");
	scanf("%s", player[0].name);
	Sleep(1500);

	player[0].log = ERROR_NO;
}
// プレイヤーの終了処理
void UninitPlayer(void) {

}
// プレイヤーの更新処理
void UpdatePlayer(void) {
	ENTITY* entity = getLigth();

	if (_kbhit() == 0) {
		system("cls");
		return;
	}

	// 現在の座標を保存しておく
	int opx = player[0].x;
	int opy = player[0].y;

	// キー入力を取得する
	rewind(stdin);
	int key = _getch();
	if (key == 0 || key == 0xe0) {
		key = _getch(); // 戻り値：ASCIIコード
	}
	system("cls");

	// printf("key: %d\n\n", key);

	// キーボードから読み込み 0xとは16進数 \0とは8進数
	switch (key) {
	case 'w':
	case 0x48:
		player[0].y--;
		break;
	case 'a':
	case 0x4b:
		player[0].x--;
		break;
	case 's':
	case 0x50:
		player[0].y++;
		break;
	case 'd':
	case 0x4d:
		player[0].x++;
		break;
	}

	// 移動後の場所をチェックする
	switch (getFieldData(player->y, player->x)) {
		case 0:
			break;
		case 1:
			player->y = opy;
			player->x = opx;
			break;
		case 2:
			entity->X++;
			setFieldData(player->y, player->x, 0);
			break;
		case 3:
			entity->key++;
			setFieldData(player->y, player->x, 0);
		case 4:
			if (entity->key <= 0) {
				player->log = ERROR_KEY;
				player->y = opy;
				player->x = opx;
			}
			else{
				entity->key--;
				setFieldData(player->y, player->x, 0);
			}
			break;
		default:
			printf("$");
			break;
	}
}
// プレイヤーの描画処理
void DrawPlayer(void) {
	printf("P");
}

PLAYER* getPlayer(void) {
	return player;
}



