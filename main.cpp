#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
//
// ��λ���ӷ�
///*
//����ר�ž��㷨�еĴ����������һ��ͳһ����
//*/
//
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//���֧�ֵ����λ��
//����������ݾ����������
//const static int M = 2000;
//
//
//int numA[M];
//int numB[M];
//
//
//ʹ��string����numA
//void resetNumA(string numAStr)
//{
//    memset(numA, 0, M * sizeof(int));
//
//    ���ַ�����ÿһλ��ת�������ִ�������
//    for (int i = 0; i < numAStr.length(); i++)
//    {
//        numA[i] = numAStr[numAStr.length() - i - 1] - '0';
//    }
//}
//
//ʹ��string����numB
//void resetNumB(string numBStr)
//{
//    memset(numB, 0, M * sizeof(int));
//
//    ���ַ�����ÿһλ��ת�������ִ�������
//    for (int i = 0; i < numBStr.length(); i++)
//    {
//        numB[i] = numBStr[numBStr.length() - i - 1] - '0';
//    }
//}
//
//
//������ת��Ϊ�ַ������������
//string getNumString(int* num)
//{
//    string numString;
//    bool isBegin = false;
//    for (int i = M - 1; i >= 0; i--)
//    {
//        if (num[i] != 0)
//        {
//            isBegin = true;
//        }
//
//        if (isBegin)
//        {
//            numString += num[i] + '0';
//        }
//    }
//    return numString;
//}
//
//�ж����������ĸ���
//int compare(string numAStr, string numBStr)
//{
//    if (numAStr.length() > numBStr.length())
//    {
//        return 1;
//    }
//    else if (numAStr.length() < numBStr.length())
//    {
//        return -1;
//    }
//    else
//    {
//        for (int i = 0; i < numAStr.length(); i++)
//        {
//            if (numAStr[i] > numBStr[i])
//            {
//                return 1;
//            }
//
//            if (numAStr[i] < numBStr[i])
//            {
//                return -1;
//            }
//        }
//        return 0;
//    }
//}
//
//�ӷ�
//string Plus(string numAStr, string numBStr)
//{
//    resetNumA(numAStr);
//    resetNumB(numBStr);
//
//    for (int i = 0; i < M; i++)
//    {
//        ���������numA��
//        numA[i] += numB[i];
//
//        ���ִ���9���λ
//        if (numA[i] > 9)
//        {
//            numA[i] -= 10;
//            numA[i + 1]++;
//        }
//    }
//
//    return getNumString(numA);
//}
//
//����
//string Minus(string numAStr, string numBStr)
//{
//    bool isNegative = false;
//
//    ���numA��numBС
//    ����Ϊ����
//    ����λ�ý��м���
//    if (compare(numAStr, numBStr) == -1)
//    {
//        isNegative = true;
//        string temp = numAStr;
//        numAStr = numBStr;
//        numBStr = temp;
//    }
//    else if (compare(numAStr, numBStr) == 0)
//    {
//        return "0";
//    }
//
//    resetNumA(numAStr);
//    resetNumB(numBStr);
//
//
//
//    for (int i = 0; i < M; i++)
//    {
//        ����С�ڱ������ͽ�λ
//        if (numA[i] < numB[i])
//        {
//            numA[i] = numA[i] + 10 - numB[i];
//            numA[i + 1]--;
//        }
//        else
//        {
//            numA[i] -= numB[i];
//        }
//    }
//    if (isNegative)
//    {
//        return "-" + getNumString(numA);
//    }
//    else
//    {
//        return getNumString(numA);
//    }
//
//}
//
//�˷�
//
//string mul(string numAStr, string numBStr)
//{
//    resetNumA(numAStr);
//    resetNumB(numBStr);
//
//    vector<string> nums;
//    for (int i = 0; i < numBStr.length(); i++)
//    {
//        ��ʼ��һ����ʱ���������汻�����������ĳһλ��˵Ľ��
//        int temp[M];
//        memset(temp, 0, M * sizeof(int));
//
//
//        for (int j = i; j < numAStr.length() + i; j++)
//        {
//            temp[j] += numA[j - i] * numB[i] % 10;
//
//            temp[j + 1] = numA[j - i] * numB[i] / 10;
//
//            �������9����ô������λ����
//            if (temp[j] > 9)
//            {
//                temp[j] -= 10;
//                temp[j + 1]++;
//            }
//        }
//        nums.push_back(getNumString(temp));
//    }
//
//    ÿλ��˵Ľ�����üӷ�������
//    string result = nums[0];
//    for (int i = 1; i < nums.size(); i++)
//    {
//        result = Plus(result, nums[i]);
//    }
//
//    return result;
//}
//
//
//
//��,�����ȷ����λ
//string div(string numAStr, string numBStr)
//{
//    resetNumA(numAStr);
//    resetNumB(numBStr);
//
//    string result;
//    string left;
//
//    if (compare(numAStr, numBStr) == -1)
//    {
//        return "0";
//    }
//
//    ��ǵ�һ����Ϊ0��λ���ĳ���
//    bool flag = false;
//    for (int i = 0; i < numAStr.length(); i++)
//    {
//        left += numAStr[i];
//
//        �����ȳ�����
//        if (compare(left, numBStr) == 1)
//        {
//            flag = true;
//
//            int count = 1;
//            string temp = numBStr;
//
//            while (true)
//            {
//                ÿѭ��һ�μ���һ������
//                temp = Plus(temp, numBStr);
//
//                ������Ȼ���ڳ����������ۼ�
//                if (compare(left, temp) == 1)
//                {
//                    count++;
//                }
//                ����С�ڳ���
//                ���Լ�����
//                else if (compare(left, temp) == -1)
//                {
//                    result += count + '0';
//                    left = Minus(left, Minus(temp, numBStr));
//                    break;
//                }
//                ��ʱ�����պ��ǳ����ı���
//                else if (compare(left, temp) == 0)
//                {
//                    count++;
//                    result += count + '0';
//                    left = "";
//                    break;
//                }
//            }
//        }
//        �պó���
//        else if (compare(left, numBStr) == 0)
//        {
//            flag = true;
//            result += "1";
//            left = "";
//        }
//        �����ȳ���С��������һλ
//        else if (flag)
//        {
//            result += "0";
//        }
//    }
//
//    return left;
//}
//
//void printTitle()
//{
//    cout << endl;
//    cout << "����1���ӷ�" << endl;
//    cout << "����2������" << endl;
//    cout << "����3���˷�" << endl;
//    cout << "����4������" << endl;
//    cout << "ѡ�� : ";
//}
//
//int main()
//{
//
//    string numAStr, numBStr;
//    string operation;
//    string result;
//
//    printTitle();
//
//    while (cin >> operation)
//    {
//        cout << "�����������֣� ";
//        cin >> numAStr >> numBStr;
//
//        if (operation == "1")
//        {
//            result = Plus(numAStr, numBStr);
//        }
//        else if (operation == "2")
//        {
//            result = Minus(numAStr, numBStr);
//        }
//        else if (operation == "3")
//        {
//            result = mul(numAStr, numBStr);
//        }
//        else
//        {
//            result = div(numAStr, numBStr);
//        }
//
//        cout << "���Ϊ��" << result << endl;
//
//        printTitle();
//    }
//    system("pause");
//}

int CompareLength(string a, string b)
{
    if (a.length() == b.length()) {
        return 0;
    }
    else if (a.length() > b.length()) {
        return 1;
    }
    else {
        return -1;
    }
}

int CompareValue(string a, string b)
{
    if (a.length() > b.length()) {
        return 1;
    }
    else if (a.length() < b.length()) {
        return -1;
    }
    else {
        for (int i = 0; i < a.length(); i++) {
            if ((a[i] - '0') > (b[i] - '0')) {
                return 1;
            }
            else if ((a[i] - '0') < (b[i] - '0')) {
                return -1;
            }
            else {
                continue;
            }
        }
        return 0;
    }
}

/*
*@brief ��ַ������Ѷ̵�ǰ�油�����볤�Ĳ���һ����
*/
void FixNumber(string &a, string &b)
{
    switch (CompareLength(a, b))
    {
    case 0: {
        return;
    }
    case 1: {
        int n = a.length() - b.length();
        for (int i = 0; i < n; i++) {
            b = "!" + b;
        }
        return;
    }
    case -1: {
        int n = b.length() - a.length();
        for (int i = 0; i < n; i++) {
            a = "!" + a;
        }
        return;
    }
    default:
        break;
    }
}
/*  jian fa kai shi*/
string Minus(string a, string b)
{
    string subtractor; //����
    string minuend; //������
    int flag = CompareValue(a, b);
    if (flag == 0) {
        return "0";
    }
    else if (flag == 1) {
        subtractor = a;
        minuend = b;
    }
    else {
        subtractor = b;
        minuend = a;
    }
    int carry = 0;
    FixNumber(subtractor, minuend);
    reverse(subtractor.begin(), subtractor.end());
    reverse(minuend.begin(), minuend.end());
    deque<int> result;
    for (int i = 0; i < subtractor.length(); i++) {
        int tempA = subtractor[i] == '!' ? 0 : subtractor[i] - '0';
        int tempB = minuend[i] == '!' ? 0 : minuend[i] - '0';
        int tempMinus = tempA - tempB + carry;
        if (tempMinus < 0) {
            result.push_front(10 + tempMinus);
            carry = -1;
        }
        else {
            result.push_front(tempMinus);
            carry = 0;
        }
    }
    string rs = "";
    result;
    for (int i : result) {
        if (i == 0 && rs == "") {
            continue;
        }
        else {
            rs += to_string(i);
        }
    }
    if (flag == -1) {
        rs = "-" + rs;
    }
    return rs;
}
/* -------------------������ʼ---------------------------------------*/
enum Flag
{
    Quotient, ///>��
    Remainder ///>����
};

string Dezero(string a)//����ȥ������ǰ���0��Ҳ����˵��������000001��������������
{
    string b = "";
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '0' && b == "") {
            continue;
        }
        else {
            b.push_back(a[i]);
        }
    }
    if (b == "") {
        b = "0";
    }
    return b;
}

string LargeNumberDevision(string a, string b, Flag flag)
{
    if (b.length() == 1 && b.at(0) == 48) {
        return "error";
    }
    int i, j;
    string d, e;
    if (CompareValue(a, b) == 0) {
        if (flag == Remainder) {
            return "0";
        }
        else {
            return "1";
        }
    }
    if (CompareValue(a, b) == -1) {
        if (flag == Remainder) {
            return b;
        }
        else {
            return "0";
        }
    }
    d = "";
    e = "";
    for (i = 0; i < a.length(); i++) {
        j = 0;
        //����Ҫ����һ�£���Ϊ������ϴμ����d = '0',��ʱ�����push'0'���ͱ������'00',���жϳ���λ��
        d.push_back(a[i]);
        d = Dezero(d);
        while (CompareValue(d, b) >= 0){
            d = Minus(d, b);//����֮ǰ�ļ�������minus���ڱ�����Ҳ���˽���
            j++;
        }
        e.push_back(j + '0');
    }
    e = Dezero(e);
    if (flag == Quotient) {
        return e;
    }
    else {
        return d;
    }
}

/* -------------------��������--------------------------------------*/
/*
* @brief �Ƚ�����string�ĳ���
* @retval 0:һ�� 1:a�� 2:b��
*/



/*
*@brief �ӷ�
*@return s �ַ���
*@retval �ӷ����
*/
string LargeNumberPluse(string a, string b)
{
    deque<int> result;
    FixNumber(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for (int i = 0; i < static_cast<int>(a.length()); i++) {
        int tempA = (a[i] == '!' ? 0 : a[i] - '0');
        int tempB = (b[i] == '!' ? 0 : b[i] - '0');
        int tempSum = tempA + tempB + carry;
        if (tempSum > 9) {
            result.push_front(tempSum % 10);
            carry = tempSum / 10;
        }
        else {
            result.push_front(tempSum);
            carry = tempSum / 10;
        }
    }
    if (carry != 0) {
        result.push_front(carry);
    }
    string s;
    for (int i : result) {
        s += to_string(i);
    }
    return s;
}

/*
*@brirf �˷��м����
*@param a b �����ַ���
*@return int���ִ�
*/
deque<deque<int>> Multiply(string a, string b)
{
    deque<deque<int>> result;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for (int i = 0; i < a.length(); i++) {
        deque<int> tempDeque;
        carry = 0;
        for (int j = 0; j < b.length(); j++) {
            int tempA = a[i] - '0';
            int tempB = b[j] - '0';
            int tempSum = tempA * tempB + carry;
            if (tempSum > 9) {
                tempDeque.push_front(tempSum % 10);
                carry = tempSum / 10;
            }
            else {
                carry = tempSum / 10;
                tempDeque.push_front(tempSum);
            }
        }
        while (carry / 10 != 0) {
            tempDeque.push_front(carry % 10);
            carry /= 10;
        }
        if (carry != 0) {
            tempDeque.push_front(carry);
        }
        for (int k = 0; k < i; k++) {
            tempDeque.push_back(0);
        }
        result.push_back(tempDeque);
    }
    return result;
}

/*
*@brief �˷�
*/
string LargeNumberMultipy(string a, string b) {
    deque<deque<int>> dataList = Multiply(a, b);
    string result;
    result.clear();
    for (auto s : dataList) {
        string temp = "";
        for (auto ss : s) {
            temp += to_string(ss);
        }
        result = LargeNumberPluse(result, temp);
    }
    return result;
}

/* 
*@brief շת�����,�����Լ��
*/
string Gcd(string a, string b)
{
    string chushu;
    string beichushu;
    if (CompareValue(a, b) == 1) {
        beichushu = b;
        chushu = a;
    }
    else if (CompareValue(a, b) == -1) {
        beichushu = a;
        chushu = b;
    }
    else {
        return a;
    }

    string yushu = "-1";

    while (LargeNumberDevision(chushu, beichushu, Remainder) != "0") {
        yushu = LargeNumberDevision(chushu, beichushu, Remainder);
        int flag = CompareValue(beichushu, yushu);
        if (flag == 1) {
            chushu = beichushu;
            beichushu = yushu;
        }
        else {
            chushu = yushu;
        }
    }
    return beichushu;
}

/*
*@brief ��<=n����С������
*/
void Fun(int n)
{
    string now = "3";
    if (n < 3) {
        cout << n << endl;
        return;
    }
    if (n == 3) {
        cout << 6 << endl;
    }
    for (int i = 3; i < n; i++) {
        int b = i + 1;
        if (b == 18) {
            b = b - 1;
            b = b + 1;
        }
        string mul = LargeNumberMultipy(now, to_string(b));
        int flag = CompareValue(now, to_string(b));
        string yueshu;
        if (flag == 1) {
            yueshu = Gcd(now, to_string(b));
        }
        else {
            yueshu = Gcd(to_string(b), now);
        }
        now = LargeNumberDevision(mul, yueshu, Quotient);
    }
    cout << now << endl;
}

/* num �Ľ׳� */
string LargeNumberMultipyN(string num)
{
    int intNum = atoi(num.c_str());
    string temp = "1";
    if (num == "0") {
        return "1";
    }
    for (int i = 2; i <= intNum; i++) {
        temp = LargeNumberMultipy(temp, to_string(i));
    }
    return temp;
}

string C(string n, string m)
{
    // c(n,m) = n!/((n-m)! * m!);
    string result;
    // n - m 
    string step1 = Minus(n, m);
    // (n - m)!
    string step2 = LargeNumberMultipyN(step1);
    // m!
    string step3 = LargeNumberMultipyN(m);
    //(n-m)! * m! 13!
    string step4 = LargeNumberMultipy(step2, step3);
    // n!
    string step5 = LargeNumberMultipyN(n);
    //finally
    result = LargeNumberDevision(step5, step4, Quotient);
    return result;
}
#include <vector>
int main()
{
    int b;
    vector<string> dataList;
    while (cin >> b) {
        dataList.clear();
        for (int i = b; (2*i-1) >= 1; i--) {
            //cout << 2 * b << 2 * i - 1<< endl;
            dataList.push_back(C(to_string(2 * b),to_string(2 * i - 1)));
       }
        string temp = dataList[0];
        for (int i = 1; i < dataList.size(); i++) {
            //cout << temp << endl;
            temp = Gcd(temp,dataList[i]);
            //cout << temp;
        }
        cout << temp << endl;
        dataList;
    }
    //cout << LargeNumberDevision("4","4",Remainder);

    system("pause");
    return 0;
}

/**

 *  �����ֱ�Ӱ�����ϵĹ�ʽ����ڴ治����������Ҫ����շת����ȼ۵�˼·��⡣a,b�����Լ�����ȼ���a-b(a>b)��b�Ĺ�Լ��
 *  ��ô C(2n,1),c(2n,3)...,c(2n,2n-1)�����Լ�� �ȼ��� ��c(2n,1)��c(2n,1)+c(2n,3)+..+c(2n,2n-1)(��͵���(2n)^(2n-1)����ż�����ȣ��������ܺ͵�һ��)�����Լ��
 *  �ȼ��� 2n ��(2n)^(2n-1)�����Լ������ô�ȼ���n������м���2��n����м���2���⣬������n-n&(n-1)��ȡ��
 */
//# include<iostream>
//    using namespace std;
//int gcb(int n)
//{
//    return n - (n & (n - 1));// ����n & (-n)
//}
//int main() {
//
//    int n;
//    while (cin >> n)
//    {
//        cout << gcb(n * 2) << ::endl;
//    }
//    return 0;
//}



