# C/C++
- ***strcpy(s1, s2)***
    Copy to s1 s2

- ***strcat(s1, s2)***
    At the end of the connection to s1 s2

- ***strlen(s1)***
    For the length of the array of s1

- ***strcmp(s1, s2)***
    If s1 and s2 are the same, it returns 0. If s1 < s2, return less than zero; And greater than zero if s1 > s2

- ***strchr(s1, ch)***
    Returns a pointer to the string s1 in the position of the first occurrence of character ch

- ***strstr(s1, s2)***
    Returns a pointer to the string string in s1 s2 position for the first time


---
# C
- ***sprintf***
    The Numbers into an array **x-->s**
    `sprintf(s,"%d",x)`


---
# C++
- ***.size()***
    Access to the array length
    `Array.size()`

- ***to_string***
    The Numbers into an array **x-->s**
    `String s = to_string(x)`

- ***reverse***
    To reverse the string
    ```cpp
    1. Use func:reverse from <algorithm>
    #include <iostream>
    #include <string>
    #include <algorithm>

    int main(){

    string s = "hello";
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
    }

    2. DIY
    #include <iostream>
    using namespace std;

    void Reverse( char *s, int n){
    for ( int i=0,j=n-1;i<j;i++,j--){
    char c=s[i];
    s[i]=s[j];
    s[j]=c;
    }
    }

    int main()
    {

    char s[]= "hello" ;
    Reverse(s,5);
    cout << s << endl;

    return 0;
    }

    3. Use func:strrev from string.h
    #include<iostream>
    #include <cstring>

    int main(){

    char s[]="hello";
    strrev(s);
    cout << s << endl;

    return 0;
    }

    ```

- ***INT_MAX INT_MIN***
    因为int占4字节32位，根据二进制编码的规则，INT_MAX = 2^31-1，INT_MIN= -2^31.
    C/C++中，所有超过该限值的数，都会出现溢出，出现warning，但是并不会出现error。
    如果想表示的整数超过了该限值，可以使用长整型long long 占8字节64位。











