#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
struct aa {
    ll h, v;
};
bool cmp(aa a, aa b) {
    if (a.h == b.h)
        return a.v > b.v;
    return a.h > b.h;
}
ll f(vector<aa>& a, vector<aa>& b) {
    ll ansa = 0, ansb = 0;
    int an, bn;
    an = a.size();
    bn = b.size();
    int i, j;
    i = j = 0;
    int count = 0;
    while (i < an || j < bn) {
        //只剩 b阵营
        if (i >= an) {
            if (count == 1)ansb += b[j].v;
            j++;
        }
        //只剩 a阵营
        else if (j >= bn) {
            cout << -123;
            if (count == 0)ansa += a[i].v;
            i++;
        }
        // 最高等级一样
        else  if (a[i].h == b[j].h) {
            if (a[i].v > b[j].v) {
                if (count == 0)ansa += a[i].v;
                i++;
            }
            else if (a[i].v < b[j].v) {
                if (count == 1)ansb += b[j].v;
                j++;
            }
            else {  //值也相同
                if (count == 0) { ansa += a[i].v; i++; }
                if (count == 1) { ansb += b[j].v; j++; }
            }
        }
        //等级不一样
        else if (a[i].h > b[j].h) {
            if (count == 0)ansa += a[i].v;
            i++;
        }
        else {
            if (count == 1)ansb += b[j].v;
            j++;
        }

        count = (count + 1) % 2;
    }
    cout << ansa << ' ' << ansb;
    return ansa - ansb;
}
void fun() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<ll>h1(n), v1(n);
    for (int i = 0; i < n; i++)
        cin >> h1[i];
    for (int i = 0; i < n; i++)
        cin >> v1[i];

    vector<aa>a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            a.push_back({ h1[i],v1[i] });
        else   b.push_back({ h1[i],v1[i] });
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    ll ans = f(a, b);
    if (ans > 0)cout << "Alice\n";
    if (ans == 0)cout << "Draw\n";
    if (ans < 0)cout << "Bob\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        fun();
    }
    return 0;
}