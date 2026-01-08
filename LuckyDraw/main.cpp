#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"

using namespace std;

void startDraw(vector<string> options) {
    rlutil::cls();
    rlutil::hidecursor();

    rlutil::locate(30, 5);
    rlutil::setColor(rlutil::WHITE);
    cout << "=== 抽籤準備開始 (按任意鍵停止) ===" << endl;
    rlutil::anykey("按任意鍵開始跑馬燈...");

    int index = 0;
    while (!rlutil::kbhit()) {
        index = rand() % options.size(); 
        rlutil::locate(35, 10);
        rlutil::setColor(rand() % 15 + 1);
        cout << "  " << options[index] << "  " << endl;
        rlutil::msleep(50); 
    }

    rlutil::getch(); 

    rlutil::locate(35, 10);
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::YELLOW);
    cout << "  " << options[index] << "  " << endl;

    rlutil::resetColor();
    rlutil::locate(30, 15);
    cout << "恭喜選中！";
    rlutil::anykey("\n按任意鍵返回主選單...");
}

int main() {
    srand(time(0));
    rlutil::saveDefaultColor();

    vector<string> food = {"雞腿飯", "牛肉麵", "麥當勞", "便利商店", "水餃", "不吃減肥"};
    vector<string> chores = {"倒垃圾", "掃廁所", "擦黑板", "買飲料", "不用做"};

    while(true) {
        rlutil::cls();
        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(30, 5);
        cout << "=== 終極決策抽籤機 ===" << endl;
        rlutil::locate(30, 7);
        cout << "1. 午餐吃什麼？" << endl;
        rlutil::locate(30, 8);
        cout << "2. 誰要做家事？" << endl;
        rlutil::locate(30, 9);
        cout << "3. 離開程式" << endl;
        rlutil::locate(30, 11);
        cout << "請選擇 (1-3): ";

        char key = rlutil::getch();

        if (key == '1') {
            startDraw(food);
        } else if (key == '2') {
            startDraw(chores);
        } else if (key == '3') {
            break;
        }
    }

    rlutil::showcursor();
    rlutil::resetColor();
    rlutil::cls();
    return 0;
}