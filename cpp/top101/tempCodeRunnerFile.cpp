#include <iostream>
using namespace std;

pair<int, int> calculateGap(pair<int, int> r1, pair<int, int> r2) {
    int lower1 = r1.first, upper1 = r1.second;
    int lower2 = r1.first, upper2 = r1.second;
    int lower, upper;
    if ((lower1 >= lower2 && lower1 <= upper2) || (upper1 >= lower2 &&
            upper1 <= upper2)) {
        lower = 0;
    } else lower =
            upper = max(upper1 - lower2, upper2 - lower1);
    return {lower, upper};
}

pair<int, int> calculateRange(bool ishour, string t) {
    int lower, upper;
    if (t[0] == '?' && t[1] == '?') {
        if (ishour) {
            lower = 0;
            upper = 23;
        } else {
            lower = 0;
            upper = 59;
        }
    } else if (t[0] != '?' && t[1] == '?') {
        lower = 10 * (t[0] - '0');
        if (ishour && t[0] == '2') {
            upper = 23;
        } 
        else upper = 9 + lower;
    } else if (t[0] == '?' && t[1] != '?') {
        lower = t[1] - '0';
        if (ishour) {
            if (t[1] <= 3) upper = 20 + (t[1] - '0');
            else upper = 10 + (t[1] - '0');
        } else {
            upper = 50 + (t[1] - '0');
        }
    } else {
        lower = stoi(t);
        upper = lower;
    }
    return {lower, upper};
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    auto hourrange1 = calculateRange(true, s1.substr(0, 2));
    auto hourrange2 = calculateRange(true, s2.substr(0, 2));
    auto minrange1 = calculateRange(false, s1.substr(3, 2));
    auto minrange2 = calculateRange(false, s2.substr(3, 2));
    cout << "hourrange1" << hourrange1.first << ' ' << hourrange1.second << endl;
    cout << "hourrange2" << hourrange2.first << ' ' << hourrange2.second << endl;
    cout << "minrange1" << minrange1.first << ' ' << minrange1.second << endl;
    cout << "minrange2" << minrange2.first << ' ' << minrange2.second << endl;
    int maxt = (hourrange2.second - hourrange1.first) * 60 + minrange2.second -
               minrange1.first;
    int mint = 0;
    if(hourrange2.first > hourrange1.second){
        mint = 60*(hourrange2.first - hourrange1.second);
        if(minrange2.first > minrange1.second) mint += minrange2.first - minrange1.second;
        else if(minrange2.second < minrange1.first) mint += minrange1.first - minrange2.second;
    }
    else{
        if(minrange2.first > minrange1.second) mint = minrange2.first - minrange1.second;
        else if(minrange2.second < minrange1.first) mint = 60 + minrange2.first - minrange1.second;
        else mint = 1;
    }
    cout << mint << ' ' << maxt << endl;
}
// 64 位输出请用 printf("%lld")