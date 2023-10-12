// BubbleSort.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <cstdlib>
using namespace std;

enum ORDER {
    ascend = 1 ,//昇順
    descend = 2,//降順
};

void Show(int* BOX, int size);
void AscendingOrder(int* BOX, int size);//昇順
void DescendingOrder(int* BOX, int size);//降順

const int maxNum = 99;

int main()
{
    int order = 0;//昇順か降順か
    int size = 0;//ソートする値の数

    do {
        cout << "並べる順番を選んでください\n1:昇順　2:降順　＞　" << flush;
        cin >> order;
    } while (order < 1 || 2 < order);

    cout << "値の数を入力せよ　＞　" << flush;
    cin >> size;

    int* box = new int[size];

    if (box != NULL) {
        //箱内を初期化
        srand((unsigned int)time(NULL));
        for (int i = 0; i < size; ++i) {
            box[i] = rand() % maxNum + 1;
        }

        cout << endl;
        cout << "ソート前：" << flush;
        Show(box, size);

        switch (order)
        {
            case ascend: AscendingOrder(box, size); break;
            case descend: DescendingOrder(box, size); break;
        }

        cout << "ソート後：" << flush;
        Show(box, size);

        delete[] box;
    }
}

void AscendingOrder(int* BOX, int size)
{
    for (int i = size; i > 1; --i) {
        for (int j = 0; j < size - 1; ++j) {
            if (BOX[j] > BOX[j + 1]) {
                swap(BOX[j], BOX[j + 1]);
            }
        }
    }
}

void DescendingOrder(int* BOX, int size)
{
    for (int i = size; i > 1; --i) {
        for (int j = 0; j < size - 1; ++j) {
            if (BOX[j] < BOX[j + 1]) {
                swap(BOX[j], BOX[j + 1]);
            }
        }
    }
}

void Show(int* BOX, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d, ", BOX[i]);
    }
    cout << endl << endl;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
