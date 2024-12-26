#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


template<size_t S = 26>
class _bitset {
private:
    bool* mas;

public:

    _bitset() : mas(new bool[S]) {
        for (size_t i = 0; i < S; ++i) {
            mas[i] = false;
        }
    }

    _bitset& set_pos(size_t pos) {
        if (pos < S) {
            mas[S-1-pos] = true;
        }
        else cout<<"Wrong pos\n";
        return *this;
    }

    _bitset& _set() {
        for (int i = 0; i < S; ++i) set_pos(i);
        return *this;
    }

    _bitset& set(const string& str) {
        for (char c : str) {
            size_t index = c - 'a';
            if (index < S) {
                set_pos(index);
            }
            else cout << "Out_of_range. Use size bigger than " << index+1 << " if you want include this letter to set\n";
        }
        return *this;
    }

    _bitset& set(unsigned int a) {
        for (int i = S-1; i !=-1; --i) {
            bool mod = a % 2;
            mas[i] = mod;
            a = a / 2;
        }
        return *this;
    }

    _bitset(const string& str) : mas(new bool[S]) {
        bool is_numb = false;
        for (size_t i = 0; i < S; ++i) {
            mas[i] = false;
            if (str[i] == '1' || str[i] == '0') is_numb = 1;
        }
        if(!is_numb) set(str);
        else {
            for (size_t i = 0; i < S; ++i) {
                if (str[i] == '1') mas[i] = 1;
            }
        }
    }
    _bitset(unsigned int i) : mas(new bool[S]) {
        for (size_t i = 0; i < S; ++i) {
            mas[i] = false;
        }
        set(i);
    }
    unsigned long to_ulong() {
        unsigned long long res = 0;
        for (int i = S-1; i!=-1; --i) {
            if (mas[i]) res += pow(2, S-i-1);
        }
        return res;
    }

    void to_letters() {
        if (none()){ cout << "This set is empty\n"; return;}
        cout << "This set contains these letters: ";
        for (int i = S - 1; i != -1; --i) {
            if (mas[i]) {
                cout << (char)(97 + (S - 1 - i)) << ' ';
            }
        }
        cout << endl;
    }

    _bitset& reset(size_t pos) {
        if (pos < S) {
            mas[S-1-pos] = 0;
        }
        else cout << "Wrong pos\n";
        return *this;
    }

    bool test(size_t pos) {
        if (pos < S) {
            return mas[S-1-pos];
        }
        else cout << "Wrong pos\n";
        return 0;
    }

    _bitset& inverse(size_t pos) {
        if (pos < S) {
            mas[S-1-pos] = !mas[S-1-pos];
        }
        else cout << "Wrong pos\n";
        return *this;
    }

    _bitset& inverse() {
        for (size_t i = 0; i < S; ++i) {
            mas[i] = !mas[i];
        }
        return *this;
    }

    size_t count() {
        size_t count = 0;
        for (size_t i = 0; i < S; ++i) {
            if (mas[i]) {
                ++count;
            }
        }
        return count;
    }

    _bitset& reset() {
        for (size_t i = 0; i < S; ++i) {
            mas[i] = 0;
        }
        return *this;
    }

    bool none() {
        for (int i = 0; i < S; ++i) {
            if (mas[i]) return 0;
        }
        return 1;
    }

    bool all() {
        for (int i = 0; i < S; ++i) {
            if (!mas[i]) return 0;
        }
        return 1;
    }

    bool any() {
        for (int i = 0; i < S; ++i) {
            if (mas[i]) return 1;
        }
        return 0;
    }

    size_t size() { return S; }

    friend ostream& operator<<(ostream& os, _bitset& a) {
        for (size_t i = 0; i < a.size(); ++i) {
            os << a.mas[i];
        }
        os << endl;
        return os;
    }

    _bitset& operator&=(_bitset<S>& b) {
        for (int i = S - 1; i != -1; --i) {
            mas[i] &= b.mas[i];
        }
        return *this;
    }

    _bitset& operator|=(_bitset<S>& b) {
        for (int i = S - 1; i != -1; --i) {
            mas[i] |= b.mas[i];
        }
        return *this;
    }

    _bitset& operator^=(_bitset<S>& b) {
        for (int i = S - 1; i != -1; --i) {
            mas[i] ^= b.mas[i];
        }
        return *this;
    }

    bool& operator[](unsigned int i) {
        if (i > S) {
            cout << "out_of_range error\n"; return mas[0];
        }
        return mas[S-1-i];
    }

    bool operator!=(_bitset<S>& b) {
        for (int i = 0; i < S; ++i) {
            if (mas[i] != b.mas[i]) return 1;
        }
        return 0;
    }

    bool operator==(_bitset<S>& b) {
        return !(*this != b);
    }

    _bitset& operator>>=(unsigned int i) {
        for (int j = S-1; j >= i; --j) mas[j] = mas[j - i];
        for (int j = 0; j < i; ++j) mas[j] = 0;
        return *this;
    }

    _bitset& operator<<=(unsigned int i) {
        for (int j = 0; j < S-i; ++j) mas[j] = mas[j + i];
        for (int j = S-i; j < S; ++j) mas[j] = 0;
        return *this;
    }
   
    
};
