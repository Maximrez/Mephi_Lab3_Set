#pragma once

#include "Heap.hpp"

using namespace std;

template<class T>
struct MySet {
    Heap<T> data;

    MySet() : data() {}

    explicit MySet(Heap<T> *heap) : data(*heap) {}

    explicit MySet(const vector<T> &vec) : data(vec) {}

    MySet(const MySet<T> &st) : data(st.data) {}

    [[nodiscard]] bool search(const T &target) const {
        return data.search(target);
    }

    void insert(const T &target) {
        data.insert(target);
    }

    void print(ostream &out) {
        out << "{";
        if (data.root) data.root->print(out);
        out << "}";
    }

    void remove(const T &target) {
        data.remove(target);
    }

    [[nodiscard]] vector<T> getValues() const {
        return data.getValues();
    }

    [[nodiscard]] bool include(const MySet<T> st) const {
        auto values = st.getValues();
        for (T item: values)
            if (!search(item))
                return false;
        return true;
    }

    [[nodiscard]] MySet<T> &intersection(const MySet<T> &st) const {
        auto *intersection = new MySet<T>();
        vector<T> values = data.getValues();
        for (T item: values)
            if (st.search(item))
                intersection->insert(item);
        return *intersection;
    }

    [[nodiscard]] MySet<T> &unification(const MySet<T> &st) const {
        auto *unity = new MySet<T>();
        vector<T> values1 = data.getValues();
        vector<T> values2 = st.data.getValues();
        for (T item: values1)
            unity->insert(item);
        for (T item: values2)
            unity->insert(item);
        return *unity;
    }

    [[nodiscard]] MySet<T> &subtraction(const MySet<T> &st) const {
        auto *sub = new MySet<T>();
        vector<T> values = data.getValues();
        for (T item: values)
            if (!st.search(item))
                sub->insert(item);
        return *sub;
    }

    const MySet &operator*(const MySet &st) const {
        return intersection(st);
    }

    const MySet &operator+(const MySet &st) const {
        return unification(st);
    }

    const MySet &operator-(const MySet &st) const {
        return subtraction(st);
    }

    friend bool operator==(const MySet<T> &st1, const MySet<T> &st2) {
        auto values1 = st1.data.getValues();
        auto values2 = st2.data.getValues();
        sort(values1.begin(), values1.end());
        sort(values2.begin(), values2.end());
        return values1 == values2;
    }

    friend bool operator!=(const MySet<T> &st1, const MySet<T> &st2) {
        return !(st1 == st2);
    }

    ~MySet() = default;
};

MySet<int> &setFromString(const string &str) {
    auto *st = new MySet<int>();
    int item;
    for (int i = 0; i < str.size(); i++) {
        int j = i;
        while (j < str.size() && str[j] != ' ')
            j++;
        if (str[i] == '-') {
            item = -convert(str.substr(i + 1, j - i - 1));
        } else {
            item = convert(str.substr(i, j - i));
        }
        st->insert(item);
        i = j;
    }
    return *st;
}