#include "pch.h"
#include <iostream>
#include <exception>
using namespace std;
class Rule;

class String {
private:
    size_t size;
    char* str;

public:
    String() : size(0), str(nullptr) {}

    String(const char* a) {
        size = 0;
        while (a[size] != '\0') {
            size++;
        }
        str = new char[size + 1];
        for (size_t i = 0; i < size; ++i) {
            str[i] = a[i];
        }
        str[size] = '\0';
    }

    String(const String& other) {
        size = other.size;
        str = new char[size + 1];
        for (size_t i = 0; i < size; ++i) {
            str[i] = other.str[i];
        }
        str[size] = '\0';
    }

    ~String() {
        delete[] str;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            size = other.size;
            str = new char[size + 1];
            for (size_t i = 0; i < size; ++i) {
                str[i] = other.str[i];
            }
            str[size] = '\0';
        }
        return *this;
    }

    size_t length() const {
        return size;
    }

    String operator+(const String& other) const {
        size_t new_size = size + other.size;
        char* new_str = new char[new_size + 1];
        for (size_t i = 0; i < size; ++i) {
            new_str[i] = str[i];
        }
        for (size_t i = 0; i < other.size; ++i) {
            new_str[size + i] = other.str[i];
        }
        new_str[new_size] = '\0';
        String result(new_str);
        delete[] new_str;
        return result;
    }

    String& operator+=(const String& other) {
        size_t new_size = size + other.size;
        char* new_str = new char[new_size + 1];
        for (size_t i = 0; i < size; ++i) {
            new_str[i] = str[i];
        }
        for (size_t i = 0; i < other.size; ++i) {
            new_str[size + i] = other.str[i];
        }
        new_str[new_size] = '\0';
        delete[] str;
        size = new_size;
        str = new_str;
        return *this;
    }

    bool operator!=(const String& str2) {
        if (size != str2.length()) {
            return true;
        }
        for (size_t i = 0; i < size; ++i) {
            if (str[i] != str2[i]) {
                return true;
            }
        }
        return false;
    }

    String operator+(const char* other) const {
        String temp(other);
        return *this + temp;
    }

    String& operator+=(const char* other) {
        String temp(other);
        return *this += temp;
    }

    String& operator+=(char ch) {
        char* new_str = new char[size + 2];
        for (size_t i = 0; i < size; ++i) {
            new_str[i] = str[i];
        }
        new_str[size] = ch;
        new_str[size + 1] = '\0';
        delete[] str;
        str = new_str;
        ++size;
        return *this;
    }

    char& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return str[index];
    }

    const char& operator[](size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return str[index];
    }

    char at(size_t index) const {
        if (index >= size || index < 0) {
            throw out_of_range("Index out of range");
        }
        return str[index];
    }

    friend ostream& operator<<(ostream& os, const String& a) {
        os << a.str;
        return os;
    }
};

class Rule {
private:
    String from;
    String to;
    bool is_terminating;

public:
    Rule(const String& from_str, const String& to_str, bool t = 0) : from(from_str), to(to_str), is_terminating(t) {}

    bool is_term() const { return is_terminating; }

    const String& getFrom() const {
        return from;
    }

    const String& getTo() const {
        return to;
    }

};

static String markov_algorithm(const String& input, const Rule rules[], size_t num_rules) {
    String result;
    size_t pos = 0;
    bool terminated = false;

    while (pos < input.length() && !terminated) {
        bool rule_applied = false;
        for (size_t i = 0; i < num_rules; ++i) {
            bool is_found = true;
            for (size_t j = 0; j < rules[i].getFrom().length(); ++j) {
                if (pos + j >= input.length() || input[pos + j] != rules[i].getFrom()[j]) {
                    is_found = false;
                    break;
                }
            }
            if (is_found) {
                result += rules[i].getTo();
                pos += rules[i].getFrom().length();
                rule_applied = true;
                if (rules[i].is_term()) {
                    terminated = true;
                }
                break;
            }
        }
        if (!rule_applied) {
            result += input[pos];
            ++pos;
        }
    }
    if (terminated && pos < input.length()) {
        for (size_t i = pos; i < input.length(); ++i) {
            result += input[i];
        }
        return result;
    }
        if (result != input) result = markov_algorithm(result, rules, num_rules);
    return result;
}


