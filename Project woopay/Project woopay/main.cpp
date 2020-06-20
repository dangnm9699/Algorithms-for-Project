//
//  main.cpp
//  Project woopay
//
//  Created by Võ Đức Quân
//  23-04-2020
//

#include <bits/stdc++.h>
#include <cstdlib>
typedef long long ll;
#define gift 40
#define rate 23000;
#define reward 10
using namespace std;

int CountDate(double m, double x){
    int k = 0;
    while (m*0.002 > x) {
        m = (double)m - (double)m * 0.002;
        k += 1;
    }
    return k;
}
double CountOnDate(double m, int a, int n){
    double result;
    for (int i = 1; i < a; i++){
        m -= m * 0.002;
    }
    result = m * 0.002 * n;
    return result;
}
double TotalOnDate(double m, int a, int n){
    double result = 0;
    for (int i = 0; i < a; i++){
        result += m * 0.002 * n;
        m -= m * 0.002;
    }
    return result;
}
void chuyendoi(int value){
    int k = 0, a[10];
    ll p = 1;
    for (int i = 3; i < 20; i += 3){
        if(pow(10, i-3) > value) break;
        for(int j = 0; j < i;j++)
            p = p * 10;
        a[k] = (value % p) / pow(10, i - 3);
        value -= a[k] * pow(10,i-3);
        p = 1;
        k += 1;
    }
    cout << "Tương đương với ";
    for (int i = k-1; i >= 0; i--){
        if(i > 0) {
            if (a[i-1]/100 == 0){
                cout << a[i] << ",0";
            } else cout << a[i] << ",";
        }
        else cout << a[i] << " VNĐ" << endl;
    }
}

int main(){
    int n, a, k = 0;
    int value;
    double m, x;
    while (k == 0){
        cout << "Nhập tổng số nick muốn có: ";
        cin >> n;
        cout << "Nhập số điểm mà mỗi nick muốn có: ";
        cin >> m;
        cout << "Tổng số nick cần ref: " << (m - gift) * n / reward + n << endl;
        cout << endl;
        cout << "Bạn muốn xem số ngày cho đến khi mỗi nick chỉ còn nhận được bao nhiêu kc: ";
        cin >> x;
        cout << "Đến ngày thứ " << CountDate(m, x) << " và khi đó mỗi nick chỉ nhận được dưới " << x <<" gem !" << endl;
        cout << endl;
        cout << "Bạn muốn xem tổng kc nhận được ở ngày thứ mấy: ";
        cin >> a;
        cout << "Tổng kc nhận được ở ngày thứ " << a << " là: ";
        printf("%.3f \n", CountOnDate(m, a, n));
        cout << "Số kc nhận từ đầu đến ngày thứ " << a << " là: ";
        printf("%.3f ", TotalOnDate(m, a, n));
        value = TotalOnDate(m, a, n) * rate;
        chuyendoi(value);
        cout << endl;
        cout << "Bạn có muốn tính toán tiếp không? /Nhập 0 nếu có, 1 nếu không: ";
        cin >> k;
        cout << endl;
    }
    return 0;
}
