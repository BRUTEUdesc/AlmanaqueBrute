#include <bits/stdc++.h>
using namespace std;

int root, cnt[100005], v[100005], res, finalera[100005];

struct query{
    int esq, dir, idx;
    query(int a, int b, int c){esq = a; dir = b; idx = c;}
    bool operator <(const query& other) const{
        if(esq/root == other.esq/root) return dir < other.dir;
        else return esq/root < other.esq/root;
    }
};

vector<query> vec_query;

void add(int x){
    if(cnt[x] == x) res--;
    cnt[x]++;
    if(cnt[x] == x) res++;
}

void remove(int x){
    if(cnt[x] == x) res--;
    cnt[x]--;
    if(cnt[x] == x) res++;
}

int main(){
	cout.sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	root = sqrt(n);

	for(int i = 1; i <= n; i++){
		cin >> v[i];
		if(v[i] > 1e5) v[i] = 1e5+2;
	}
	for(int i = 0; i < m; i++){
		int esq, dir; cin >> esq >> dir;
		vec_query.push_back(query(esq, dir, i));
	}

    sort(vec_query.begin(), vec_query.end());

	int L = 1, R = 0;
    for(auto q : vec_query){
        int esq = q.esq, dir = q.dir, idx = q.idx;
        while(R < dir) R++, add(v[R]);
        while(R > dir) remove(v[R]), R--;
        while(L < esq) remove(v[L]), L++;
        while(L > esq) L--, add(v[L]);
        finalera[idx] = res;
    }
    for(int i = 0; i < m; i++)
        cout << finalera[i] << endl;
	return 0;
}
