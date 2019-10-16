#include<cmath>
#include<cstdio>
#include<iostream>

using namespace std;

bool es_primo(int x){
    if(x==1||x==2)
        return true;

    for(int i=2;i<x/2;i++){
        if(x%i==0)
            return false;
    }

    return true;
}


int total;
int circle[20];
bool used[20];


void backtracking(int index) {
    if(index == total - 1 && es_primo(circle[total - 1] + circle[total])) {
        for(int i = 0; i < total; i++)
            printf(i == total - 1? "%d" : "%d ", circle[i]);
        printf("\n");
        return;
    }
    for(int i = 2; i <= total; i++)
        if(!used[i] && es_primo(circle[index] + i)) {
            used[i] = true;
            circle[index + 1] = i;
            backtracking(index + 1);
            used[i] = false;
        }
}

int main() {
    int cases=0;
    while(scanf("%d", &total) == 1) {
        circle[0] = circle[total] = 1;

        cases++;
        if(cases > 1)
            cout<<endl;
        cout<<"Case "<<cases<<":\n";
        if(total<=16)
            backtracking(0);
    }
}