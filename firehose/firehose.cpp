/* 
 LANG: CPP
 NAME: CHARLES
 QUESTION: 
 COMMENT:
 
 
*/

#include <bits/stdc++.h>

using namespace std;

int houseNum , dd;
vector<int> graph;
int jj = 1000000;
int ge(int hoses){
    int result = graph.size();
    int dia = hoses*2;
    int i = 0 ;
    while(i < graph.size() && graph[i] <= (graph[0] + dia)){
        int counter = 1;
        int currentEnd = graph[i];
        int j = 1+i;
        while(j < graph.size()&& (graph[i]>(graph[j]+dia - jj))){
            if(graph[j] > currentEnd){
                counter++;
                currentEnd = graph[j] + dia;
            }
            j++;
        }
        i++;
        result = min(result , counter);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>> houseNum;
    for(int i = 0 ; i < houseNum ; i++){
        int ind; cin>> ind; graph.push_back(ind);
    }
    sort(graph.begin() , graph.end());
    cin >> dd;
    int h = jj , l = -1;
    while(h > (l +1)){
        int av = (l+h)/2;
        if(ge(av) > dd){
            l = av;
        }else{
            h = av;
        }
    }
    cout<<h<<endl;
    return 0;
}
