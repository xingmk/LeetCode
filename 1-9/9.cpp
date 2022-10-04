#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

    int x;
    cout << "Enter a num:" << endl;
    cin >> x;
    string s = to_string(x);
    int len = s.size() - 1;
    int flag = 0;
    for (int i = 0, len; i < len; i++, len--) {
        if (s[i] != s[len]) {
            flag = 1;
        }
    }
    if (flag = 1)
        return true;
    else
        return false;

    return 0;
}
