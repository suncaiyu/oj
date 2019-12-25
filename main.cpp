#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
//
// 大位数加法
///*
//这里专门就算法中的大数问题进行一个统一归纳
//*/
//
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//结果支持的最大位数
//这个可以依据具体需求调整
//const static int M = 2000;
//
//
//int numA[M];
//int numB[M];
//
//
//使用string重置numA
//void resetNumA(string numAStr)
//{
//    memset(numA, 0, M * sizeof(int));
//
//    将字符串的每一位都转换成数字传入数组
//    for (int i = 0; i < numAStr.length(); i++)
//    {
//        numA[i] = numAStr[numAStr.length() - i - 1] - '0';
//    }
//}
//
//使用string重置numB
//void resetNumB(string numBStr)
//{
//    memset(numB, 0, M * sizeof(int));
//
//    将字符串的每一位都转换成数字传入数组
//    for (int i = 0; i < numBStr.length(); i++)
//    {
//        numB[i] = numBStr[numBStr.length() - i - 1] - '0';
//    }
//}
//
//
//将数组转换为字符串，用于输出
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
//判断两个数字哪个大
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
//加法
//string Plus(string numAStr, string numBStr)
//{
//    resetNumA(numAStr);
//    resetNumB(numBStr);
//
//    for (int i = 0; i < M; i++)
//    {
//        结果保存在numA中
//        numA[i] += numB[i];
//
//        数字大于9则进位
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
//减法
//string Minus(string numAStr, string numBStr)
//{
//    bool isNegative = false;
//
//    如果numA比numB小
//    则结果为负数
//    调换位置进行计算
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
//        减数小于被减数就借位
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
//乘法
//
//string mul(string numAStr, string numBStr)
//{
//    resetNumA(numAStr);
//    resetNumB(numBStr);
//
//    vector<string> nums;
//    for (int i = 0; i < numBStr.length(); i++)
//    {
//        初始化一个临时数据来保存被乘数与乘数的某一位相乘的结果
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
//            如果大于9，那么就做进位处理
//            if (temp[j] > 9)
//            {
//                temp[j] -= 10;
//                temp[j + 1]++;
//            }
//        }
//        nums.push_back(getNumString(temp));
//    }
//
//    每位相乘的结果再用加法加起来
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
//除,结果精确到个位
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
//    标记第一个不为0的位数的出现
//    bool flag = false;
//    for (int i = 0; i < numAStr.length(); i++)
//    {
//        left += numAStr[i];
//
//        余数比除数大
//        if (compare(left, numBStr) == 1)
//        {
//            flag = true;
//
//            int count = 1;
//            string temp = numBStr;
//
//            while (true)
//            {
//                每循环一次加上一个余数
//                temp = Plus(temp, numBStr);
//
//                余数仍然大于除数，继续累加
//                if (compare(left, temp) == 1)
//                {
//                    count++;
//                }
//                余数小于除数
//                可以计算结果
//                else if (compare(left, temp) == -1)
//                {
//                    result += count + '0';
//                    left = Minus(left, Minus(temp, numBStr));
//                    break;
//                }
//                此时余数刚好是除数的倍数
//                else if (compare(left, temp) == 0)
//                {
//                    count++;
//                    result += count + '0';
//                    left = "";
//                    break;
//                }
//            }
//        }
//        刚好除尽
//        else if (compare(left, numBStr) == 0)
//        {
//            flag = true;
//            result += "1";
//            left = "";
//        }
//        余数比除数小，跳到下一位
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
//    cout << "输入1：加法" << endl;
//    cout << "输入2：减法" << endl;
//    cout << "输入3：乘法" << endl;
//    cout << "输入4：除法" << endl;
//    cout << "选择 : ";
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
//        cout << "输入两个数字： ";
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
//        cout << "结果为：" << result << endl;
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
*@brief 填补字符串，把短的前面补！，与长的补成一样长
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
    string subtractor; //减数
    string minuend; //被减数
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
/* -------------------除法开始---------------------------------------*/
enum Flag
{
    Quotient, ///>商
    Remainder ///>余数
};

string Dezero(string a)//用来去掉正数前面的0，也就是说可以输入000001类似这样的数字
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
        //这里要处理一下，因为会出现上次减完后d = '0',此时后面加push'0'，就变成了了'00',会判断成两位数
        d.push_back(a[i]);
        d = Dezero(d);
        while (CompareValue(d, b) >= 0){
            d = Minus(d, b);//调用之前的减法函数minus，在本文中也加了进来
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

/* -------------------除法结束--------------------------------------*/
/*
* @brief 比较两个string的长度
* @retval 0:一样 1:a长 2:b长
*/



/*
*@brief 加法
*@return s 字符串
*@retval 加法结果
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
*@brirf 乘法中间过程
*@param a b 数字字符串
*@return int型字串
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
*@brief 乘法
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
*@brief 辗转相除法,求最大公约数
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
*@brief 求<=n的最小公倍数
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

/* num 的阶乘 */
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

 *  这道题直接按照组合的公式求解内存不够，所以需要利用辗转相减等价的思路求解。a,b的最大公约数，等价于a-b(a>b)与b的公约数
 *  那么 C(2n,1),c(2n,3)...,c(2n,2n-1)的最大公约数 等价于 从c(2n,1)和c(2n,1)+c(2n,3)+..+c(2n,2n-1)(求和等于(2n)^(2n-1)，奇偶项和相等，各等于总和的一半)的最大公约数
 *  等价于 2n 和(2n)^(2n-1)的最大公约数，那么等价于n中最多有几个2（n最多有几个2问题，可以用n-n&(n-1)求取）
 */
//# include<iostream>
//    using namespace std;
//int gcb(int n)
//{
//    return n - (n & (n - 1));// 或者n & (-n)
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



