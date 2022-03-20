#include <bits/stdc++.h>
#define LIM 100005

using namespace std;

vector<int> merge_(vector<int> &A, vector<int> &B) {
    int i = 0, j = 0;
    vector<int> C;
    while(i < A.size() && j < B.size()) {
        if(A[i] <= B[j]) C.push_back(A[i++]);
        else C.push_back(B[j++]);
    }

    while(i < A.size()) C.push_back(A[i++]);
    while(j < B.size()) C.push_back(B[j++]);
}

int n, cnt = 0;
vector<int> A;

void Merge(int lft, int rgt) {
    int md = (lft+rgt)/2;
    int i = lft, j = md+1;
    vector<int> C;
    while(i <= md && j <= rgt) {
        if(A[i] <= A[j])
            C.push_back(A[i++]);
        else{
            C.push_back(A[j++]);
            //cout << A[i] << " " << A[j - 1] << endl;
            cnt ++;
            if(i < md)
                cnt += abs(md - i);
        }
    }
    while(i <= md) C.push_back(A[i++]);
    while(j <= rgt) C.push_back(A[j++]);

    for(int i=lft, k=0; i<=rgt; i++, k++) A[i] = C[k];

}

void MergeSort(int lft, int rgt) {
    if(lft >= rgt) return;
    int md = (lft+rgt)/2;
    MergeSort(lft, md);
    MergeSort(md+1, rgt);
    //printf("left :%d right :%d\n", lft, rgt);
    Merge(lft, rgt);
}

int main() {
//    srand(time(NULL));
//    scanf("%d", &n);
//    A.resize(n);
//    for(int i=0; i<n; i++) {
//        A[i] = rand() % 10 + 1;
//    }

    int n, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i ++){
        cin >> x;
        A.push_back(x);
    }

    MergeSort(0, n-1);

    for(int v : A) printf("%d ", v);
    cout << endl;
    cout << cnt << endl;
}

/*
4
2 4 1 3

6
6 5 4 3 2 1

8
1 2 100 3 2 500 7 8
*/

