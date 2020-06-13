#include <bits/stdc++.h>
using namespace std;

#define MAX 100005 // suports O(n log n)

string s; // the input string, up to MAX characters
int n; // the length of input string

int ra[MAX], auxra[MAX]; // rank array and temporary rank array
int sa[MAX], auxsa[MAX]; // suffix array and temporary suffix array

int c[MAX]; // for counting/radix sort
void countingSort(int k) { // O(n)
    memset(c, 0, sizeof c); // clear frequency table
    for (int i = 0; i < n; i++) c[(i + k < n)? ra[i + k] : 0]++; // count the frequency of each integer rank

    int sum = 0, maxi = max(255, n); // up to 255 ASCII chars or length of n
    for (int i = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }

    for (int i = 0; i < n; i++) auxsa[c[sa[i]+k < n ? ra[sa[i]+k] : 0]++] = sa[i]; // shuffle the suffix array if necessary
    for (int i = 0; i < n; i++) sa[i] = auxsa[i]; // update the suffix array sa
}

void constructSA() {
    for (int i = 0; i < n; i++) {
        ra[i] = s[i]; // initial rankings
        sa[i] = i; // initial sa: {0, 1, 2, ..., n-1}
    }

    for (int k = 1; k < n; k <<= 1) { // repeat sorting process log n times
        countingSort(k); // actually radix sort: sort based on the k-th item
        countingSort(0); // then (stable) sort based on the first item

        int r = 0;
        auxra[sa[0]] = r; // re-ranking; start from rank r = 0
        for (int i = 1; i < n; i++) { // compare adjacent suffixes
            // if same pair => same rank; otherwise, increase rank
            if (ra[sa[i-1]] != ra[sa[i]] || ra[sa[i-1]+k] != ra[sa[i]+k]) r++;
            auxra[sa[i]] = r;
        }

        for (int i = 0; i < n; i++) ra[i] = auxra[i]; // update the rank array ra
        if (ra[sa[n-1]] == n-1) break; // nice optimization trick
    }
}

int main() {
    cin >> s; // input str as normal, without the ‘$’
    s += '$'; // add terminating character
    n = s.size(); // set str size

    constructSA();
    for (int i = 0; i < n; i++) printf("%d: %s\n", sa[i], s.c_str() + sa[i]);
}
