/* インクルードガード */
#pragma once


class MdHighAndLow// classの定義
{
private: // privateはクラス内からしかアクセスできない

public: // publicはどこからでもアクセス可能
MdHighAndLow();
void getTrump(int* heart,int* spade);
bool getWinLose(int* heart,int* spade);
};
