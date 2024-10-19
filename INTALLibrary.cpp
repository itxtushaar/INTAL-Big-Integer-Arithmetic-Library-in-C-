#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string initializeINTAL() {
    string intal(1000, '0');
    return intal;
}
string removeLeadingZeros(string str) {
    int non_zero_pos = 0;
    while (non_zero_pos < str.size() && str[non_zero_pos] == '0') {
        ++non_zero_pos;
    }
    return str.substr(non_zero_pos);
}
int compareINTAL(string intal_a, string intal_b) {
    intal_a = removeLeadingZeros(intal_a);
    intal_b = removeLeadingZeros(intal_b);
    if (intal_a.size() > intal_b.size()) return 1;
    if (intal_a.size() < intal_b.size()) return -1;
    for (int i = 0; i < intal_a.size(); ++i) {
        if (intal_a[i] > intal_b[i]) return 1;
        if (intal_a[i] < intal_b[i]) return -1;
    }
    return 0;
}
string addINTAL(string intal_a, string intal_b) {
    intal_a = removeLeadingZeros(intal_a);
    intal_b = removeLeadingZeros(intal_b);
    if (intal_a.size() < intal_b.size()) swap(intal_a, intal_b);
    string result = "";
    int carry = 0;
    int i = intal_a.size() - 1, j = intal_b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += intal_a[i--] - '0';
        if (j >= 0) sum += intal_b[j--] - '0';
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    reverse(result.begin(), result.end());
    return removeLeadingZeros(result);
}
string subtractINTAL(string intal_a, string intal_b) {
    intal_a = removeLeadingZeros(intal_a);
    intal_b = removeLeadingZeros(intal_b);
    string result = "";
    int borrow = 0;
    int i = intal_a.size() - 1, j = intal_b.size() - 1;
    while (i >= 0) {
        int sub = (intal_a[i--] - '0') - borrow;
        if (j >= 0) sub -= (intal_b[j--] - '0');
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(sub + '0');
    }
    reverse(result.begin(), result.end());
    return removeLeadingZeros(result);
}
string multiplyINTAL(string intal_a, string intal_b) {
    intal_a = removeLeadingZeros(intal_a);
    intal_b = removeLeadingZeros(intal_b);
    if (intal_a == "0" || intal_b == "0") return "0";
    if (intal_a == "1") return intal_b;
    if (intal_b == "1") return intal_a;
    int m = intal_a.size(), n = intal_b.size();
    vector<int> result(m + n, 0);
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int mul = (intal_a[i] - '0') * (intal_b[j] - '0');
            mul += result[i + j + 1];
            result[i + j + 1] = mul % 10;
            result[i + j] += mul / 10;
        }
    }
    string result_str = "";
    for (int val : result) result_str.push_back(val + '0');
    return removeLeadingZeros(result_str);
}
string fibonacciINTAL(unsigned int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    string a = "0", b = "1", temp;
    for (unsigned int i = 2; i <= n; ++i) {
        temp = addINTAL(a, b);
        a = b;
        b = temp;
    }
    return b;
}
string factorialINTAL(unsigned int n) {
    string result = "1";
    for (unsigned int i = 2; i <= n; ++i) {
        result = multiplyINTAL(result, to_string(i));
    }
    return result;
}
int main() {
    string intal = initializeINTAL();
    cout << "Initialized INTAL: " << intal << endl;
    string a = "999";
    string b = "1";
    cout << "Addition of " << a << " and " << b << " = " << addINTAL(a, b) << endl;
    string c = "1000";
    string d = "1";
    cout << "Subtraction of " << c << " and " << d << " = " << subtractINTAL(c, d) << endl;
    string e = "123";
    string f = "456";
    cout << "Multiplication of " << e << " and " << f << " = " << multiplyINTAL(e, f) << endl;
    unsigned int n = 10;
    cout << "Fibonacci of " << n << " = " << fibonacciINTAL(n) << endl;
    unsigned int m = 10;
    cout << "Factorial of " << m << " = " << factorialINTAL(m) << endl;
    return 0;
}