#include <queue>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    queue<char> orignaldata;
    queue<char> finaldata;
    string data;
    getline(cin, data);
    for(int i = 0; i < data.size(); i++){
        orignaldata.push(data[i]);
    }
    bool flag = true;
    while (orignaldata.size() > 0) {
        if (flag) {
            char c = orignaldata.front();
            finaldata.push(c);
            orignaldata.pop();
            flag = false;;
        }
        else {
            char c = orignaldata.front();
            orignaldata.push(c);
            orignaldata.pop();
            flag = true;
        }
    }
    while (!finaldata.empty()) {
        cout << finaldata.front();
        finaldata.pop();
    }
    return 0;
}