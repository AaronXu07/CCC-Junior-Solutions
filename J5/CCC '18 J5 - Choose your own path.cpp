#include <bits/stdc++.h>
using namespace std;

typedef struct node{

int value;

vector< shared_ptr<struct node> >children;

} node_t;

int ShortestPath(vector< shared_ptr<node_t> > nodes, int PageLvl){

  PageLvl++;

  vector< shared_ptr<node_t> > childNodes;

  for (auto node : nodes){

    if (node->children.size() == 0){

      return PageLvl;
    }

    else{
      
      for (auto a : node->children){

        childNodes.push_back(a);
      
      }
    }
  }

  return ShortestPath(childNodes, PageLvl);
  
}

void getReachablePages(shared_ptr<node_t> node, set<int>& pages){

  if (pages.find(node->value) == pages.end()){

    pages.insert(node->value);

    for (auto a : node->children){

      getReachablePages(a, pages);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;

  cin >> N;

  map< int, shared_ptr<node_t> > BookMap;

  for (int i = 0; i < N; i++){

    BookMap[i + 1] = make_unique<node_t>();
    BookMap[i + 1]->value = i+1;
  }

  for (int i = 1; i<=N; i++){

    int num = 0;
    
    cin >> num;

    for (int j = 0; j < num; j++){

      int page = 0;

      cin >> page;

      BookMap[i]->children.push_back(BookMap[page]);
    }
  }

  set<int> pages;

  getReachablePages(BookMap[1], pages);

  if (pages.size() == N){

    cout << "Y" << endl;
    
  }

  else{

    cout << "N" << endl;
  }

  int PageLvl = 0;

  vector< shared_ptr<node_t> > nodesToCheck;

  nodesToCheck.push_back(BookMap[1]);

  cout << ShortestPath(nodesToCheck, PageLvl) << endl;

  return 0;
}