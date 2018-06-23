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

    cerr << *d.begin() << endl;
    cerr << *(d.begin() + 1) << endl;
    cerr << *(d.begin() + 2) << endl;
    cerr << *(d.begin() + 3) << endl;

    auto it = d.end();
    it -= 2;
    d.insert(d.erase(it), 321);

    for (auto it = d.begin(); it != d.end(); ++it) {
        cerr << *it << endl;
    }
    cerr << endl;

    cerr << "!!!!!\n";

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

    cerr << *(d3.rbegin()) << endl;
    circular_buffer<int>::const_iterator re = d3.end();

    --re;
    cerr << *re << endl;

    circular_buffer<int>::const_iterator re2 = d3.end();
    --re2;

    cerr << (re == re2);

    circular_buffer<int> a;

    for (int i = 0; i < 10; ++i) {
        a.push_back(i);
    }

    for (int i = 11; i < 100; ++i) {
        a.insert(a.begin(), i);
        a.erase(a.end() - 2);
    }

    cerr << endl;
    for (auto i = a.begin(); i != a.end(); ++i) {
        cerr << *i << " ";
    }

    circular_buffer<int> c;
    c.push_back(6);
    c.push_back(7);

    circular_buffer<int>::iterator ncon = c.begin();
    circular_buffer<int>::const_iterator con = c.begin();

    cerr << "!!!!!\n";

    cerr << endl << (con == ncon )<< endl;
    cerr << endl << (ncon == con)<< endl;

    circular_buffer<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    cerr << *(test.end() - 1);

    return 0;
}