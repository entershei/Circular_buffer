#include <iostream>
#include "circular_buffer.h"
#include <gtest/gtest.h>

using namespace my;
using namespace std;

int main() {
    circular_buffer<int> d;

    for (int i = 0; i < 10; ++i) {
        d.push_back(i);
    }
    const circular_buffer<int> d3(d);

    d.erase(d.erase(d.begin()));

    d[4] = 100;

    auto it = d.end();
    it -= 2;
    d.insert(d.erase(it), 321);

    for (auto it = d.begin(); it != d.end(); ++it) {
        cerr << *it << endl;
    }
    cerr << endl;

    for (auto it = d.begin(); it != d.end(); ++it) {
        cerr << *it << endl;
    }

    cerr << endl;

    circular_buffer<int> d2;
    d2 = d;
    d.clear();

    for (auto it = d.begin(); it != d.end(); ++it) {
        cerr << *it << endl;
    }

    cerr << endl;

    for (auto it = d2.begin(); it != d2.end(); ++it) {
        cerr << *it << endl;
    }

    cerr << endl;

    for (auto it = d3.begin(); it != d3.end(); ++it) {
        cerr << *it << endl;
    }

    cerr << endl;

    return 0;
}