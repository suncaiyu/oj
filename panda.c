#include <deque>
#include <iostream>
using namespace std;

bool HasSameCard(deque<int> desktopCard)
{
    int temp = desktopCard.back();
    while (desktopCard.size() > 1) {
        if (desktopCard.front() == temp) {
            return true;
        }
        else {
            desktopCard.pop_front();
        }
    }
    return false;
}
int cccc = 0;
void Process(deque<int> &card, deque<int> &desktopCard)
{
    if (cccc == 25) {
        cout << endl;
    }
    if (HasSameCard(desktopCard)) {
        int finalCard = desktopCard.back();
        deque<int> tempresult;
        tempresult.push_back(desktopCard.back());
        desktopCard.pop_back();
        while (desktopCard.back() != finalCard) {
            tempresult.push_back(desktopCard.back());
            desktopCard.pop_back();
        }
        tempresult.push_back(desktopCard.back());
        desktopCard.pop_back();

        while (tempresult.size() > 0) {
            int temp = tempresult.front();
            card.push_back(temp);
            tempresult.pop_front();
        }
    }
}

void Cout(deque<int> mm, deque<int> xx, deque<int> desk)
{
    cccc++;
    cout << "!!!!!!!" << cccc << endl;
    cout << "mm : ";
    while (!mm.empty()) {
        cout << mm.front() << " ";
        mm.pop_front();
    }
    cout << endl << "xx : ";
    while (!xx.empty()) {
        cout << xx.front() << " ";
        xx.pop_front();
    }
    cout << endl << "desktop: ";
    while (!desk.empty()) {
        cout << desk.front() << " ";
        desk.pop_front();
    }
    cout << endl;
}

int main()
{
    int num;
    deque<int> mmCard;
    deque<int> xxCard;
    deque<int> desktopCard;

    cin >> num;
    for (int i = 0; i < num; i++) {
        int card;
        cin >> card;
        mmCard.push_back(card);
    }
    for (int i = 0; i < num; i++) {
        int card;
        cin >> card;
        xxCard.push_back(card);
    }


    while (!mmCard.empty() && !xxCard.empty()) {
        cccc++;
        int curmmCard = mmCard.front();
        int curxxCard = xxCard.front();

        // mm 出牌
        desktopCard.push_back(curmmCard);
        mmCard.pop_front();
        // 比较是否有同样的
        Process(mmCard, desktopCard);
        //Cout(mmCard, xxCard, desktopCard);
        // xx
        desktopCard.push_back(curxxCard);
        xxCard.pop_front();
        Process(xxCard, desktopCard);
        //Cout(mmCard, xxCard, desktopCard);
    }

    if (mmCard.empty()) {
        cout << cccc << endl;
        cout << "xx" << endl;
        while (!xxCard.empty()) {
            cout << xxCard.front() << " ";
            xxCard.pop_front();
        }
        cout << endl;
    }
    else {
        cout << cccc << endl;
        cout << "mm" << endl;
        while (!mmCard.empty()) {
            cout << mmCard.front() << " ";
            mmCard.pop_front();
        }
        cout << endl;
    }
    return 0;
}