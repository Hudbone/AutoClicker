#include "AutoClicker.h"
#include <iostream>
#include <windows.h>
using namespace std;

ostream &operator<<(ostream &o, const AutoClicker &a) {
    o << "*************************************************\n";
    o << "* 7 = Mouse auto clicks and saves position      *\n";
    o << "* 8 = Activate auto clicker                     *\n";
    o << "* 9 = Choose interval for auto clicker          *\n";
    o << "* 0 = Stop the clicker                          *\n";
    o << "* Escape = Close program                        *\n";
    o << "*************************************************\n";
    return o;
}

AutoClicker::AutoClicker() {
    xPos = 0;
    yPos = 0;
    active = false;
    ms = 0;
}

void AutoClicker::click() {
    while(!GetAsyncKeyState(VK_ESCAPE)){
        if(GetAsyncKeyState(0x37)){
            cout << "Auto Clicker Starting. . .\n";
            SetActive(true);
            POINT p;
            if(GetCursorPos(&p)){
                SetxPos(p.x);
                SetyPos(p.y);
            }
            while(GetActive()){
                SetCursorPos(GetxPos(), GetyPos());
                INPUT ip[2];
                ip[0].type = INPUT_MOUSE;
                ip[0].mi.time = 0;
                ip[0].mi.mouseData = 0;
                ip[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                ip[1].type = INPUT_MOUSE;
                ip[1].mi.time = 0;
                ip[1].mi.mouseData = 0;
                ip[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
                SendInput(2, ip, sizeof(INPUT));
                if(GetAsyncKeyState(0x30)){
                    SetActive(false);
                    cout << "Stopping Auto Clicker. . .\n";
                }
            }
        }
        if(GetAsyncKeyState(0x38)){
            cout << "Auto Clicker Starting. . .\n";
            SetActive(true);
            while(GetActive()){
                INPUT ip[2];
                ip[0].type = INPUT_MOUSE;
                ip[0].mi.time = 0;
                ip[0].mi.mouseData = 0;
                ip[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                ip[1].type = INPUT_MOUSE;
                ip[1].mi.time = 0;
                ip[1].mi.mouseData = 0;
                ip[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
                SendInput(2, ip, sizeof(INPUT));
                if(GetAsyncKeyState(0x30)){
                    SetActive(false);
                    cout << "Stopping Auto Clicker. . .\n";
                }
            }
        }
        if(GetAsyncKeyState(0x39)){
            int s;
            cout << "\nChoose the ms window to activate the auto clicker: ";
            cin >> s;
            if(!cin){
                throw invalid_argument("Number must be an integer.");
            }
            while(s <= 0){
                cout << "\nNumber needs to be greater than 0: ";
                cin >> s;
                if(!cin){
                    throw invalid_argument("Number must be an integer.");
                }
            }
            int i = static_cast<int>(s);
            SetMS(i);
            cout << "Auto Clicker Starting. . .\n";
            SetActive(true);
            while(GetActive()){
                INPUT ip[2];
                ip[0].type = INPUT_MOUSE;
                ip[0].mi.time = 0;
                ip[0].mi.mouseData = 0;
                ip[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                ip[1].type = INPUT_MOUSE;
                ip[1].mi.time = 0;
                ip[1].mi.mouseData = 0;
                ip[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
                SendInput(2, ip, sizeof(INPUT));
                srand((unsigned)time(nullptr));
                Sleep((rand()%(1+GetMS())));
                if (GetAsyncKeyState(0x30))
                {
                    SetActive(false);
                    cout << "Stopping Auto Clicker. . .\n";
                }
            }
        }
    }
}

int AutoClicker::GetxPos() const {
    return xPos;
}

int AutoClicker::GetyPos() const {
    return yPos;
}

void AutoClicker::SetxPos(int x) {
    this->xPos = x;
}

void AutoClicker::SetyPos(int y) {
    this->yPos = y;
}

bool AutoClicker::GetActive() const {
    return active;
}

void AutoClicker::SetActive(bool b) {
    this->active = b;
}

int AutoClicker::GetMS() const {
    return ms;
}

void AutoClicker::SetMS(int s) {
    this->ms = s;
}
