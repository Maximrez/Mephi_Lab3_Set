#pragma once

#include <chrono>
#include <utility>
#include <cassert>
#include <set>
#include "Heap.hpp"

pair<int, int> test_create_int(const int n) {
    int values[n];
    set<int> target;
    for (int i = 0; i < n; i++) {
        int value = int(i / 2);
        values[i] = value;
        target.insert(value);
    }

    auto startTime = chrono::steady_clock::now();
    Heap<int> heap_node(values, n);
    auto endTime = chrono::steady_clock::now();
    int node_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    Heap<int> heap_array(values, n);
    endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    assert(heap_node == target);
    assert(heap_array == target);

    return {node_time, array_time};
}

pair<int, int> test_create_double(const int n) {
    double values[n];
    set<double> target;
    for (int i = 0; i < n; i++) {
        double value = int(i / 2);
        values[i] = value;
        target.insert(value);
    }

    auto startTime = chrono::steady_clock::now();
    Heap<double> heap_node(values, n);
    auto endTime = chrono::steady_clock::now();
    int node_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    Heap<double> heap_array(values, n);
    endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    assert(heap_node == target);
    assert(heap_array == target);

    return {node_time, array_time};
}

pair<int, int> test_insert_int(const int n) {
    auto *heap_node = new Heap<int>();
    auto *heap_array = new Heap<int>();
    set<int> target;
    for (int i = 0; i < n; i++) {
        int value = int(i / 2);
        target.insert(value);
    }
    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = int(i / 2);
        heap_node->insert(item);
    }
    auto endTime = chrono::steady_clock::now();
    int node_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        int item = int(i / 2);
        heap_array->insert(item);
    }
    endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    assert(*heap_node == target);
    assert(*heap_array == target);

    return {node_time, array_time};
}

pair<int, int> test_insert_double(const int n) {
    auto *heap_node = new Heap<double>();
    auto *heap_array = new Heap<double>();
    set<double> target;
    for (int i = 0; i < n; i++) {
        double value = int(i / 2);
        target.insert(value);
    }
    auto startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = int(i / 2);
        heap_node->insert(item);
    }
    auto endTime = chrono::steady_clock::now();
    int node_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    startTime = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        double item = int(i / 2);
        heap_array->insert(item);
    }
    endTime = chrono::steady_clock::now();
    int array_time = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    assert(*heap_node == target);
    assert(*heap_array == target);

    return {node_time, array_time};
}