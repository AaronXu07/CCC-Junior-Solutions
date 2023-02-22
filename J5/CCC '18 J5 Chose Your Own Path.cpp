#include <bits/stdc++.h>
using namespace std;


int main(){
    int N, M, x;
    int s = 1;
    int p = 0;
    bool min = false;
    char r = 'Y';
  
    vector<vector<int>> pageLink = {{0}};

    cin >> N;
  
    pageLink.resize(N+1);
  
    for(int i = 1; i <= N; i++){
      
        cin >> M;
      
        if(M == 0) {
          
          pageLink[i].push_back(0);
          
        }
      
        for(int j = 0; j < M; j++){
          
          cin >> x;
          
          pageLink[i].push_back(x);
          
        }
    }
    
    queue<int> q;
  
    vector<bool> VisitedPages;
  
    for(int i = 0; i < N + 1; i++){
      
        VisitedPages.push_back(false);
      
    }
  
    q.push(s);
  
    VisitedPages[0] = true;
  
    VisitedPages[s] = true;

    int qsize = q.size();
  
    int it = 0;
    
    while(!q.empty()){
      
        s = q.front();
      
        it++;
        
        if(it == qsize && !min){
            p++;
            qsize = q.size();
            it = 0;
        }
        
        q.pop();
      
        if(pageLink[s].empty()){
          
            continue;
          
        }
      
        for(int i = 0; i < pageLink[s].size(); i++){
          
            if(pageLink[s][0] == 0){
              
                min = true;
              
            }
            if(!VisitedPages[pageLink[s][i]]){
              
                q.push(pageLink[s][i]);
              
                VisitedPages[pageLink[s][i]] = true;
            }
        }
    }
    
    for(int i = 0; i <= N; i++){
      
        if(VisitedPages[i] == false){
          
            r = 'N';
          
            break;
        }
    }
  
    cout << r << endl << p;
    
}