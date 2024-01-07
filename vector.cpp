#include <iostream>
#include<vector>
using namespace std;

int main() {

vector<int>n;

n.push_back(1);
n.push_back(2);
n.push_back(3);
n.push_back(4);

for (int i = 0; i < n.size(); i++)
{
   cout<<" "<<n[i];
//    n.pop_back();
}
//  insert value at the head of array 
n.insert(n.begin() , 10);

cout << "\n last value";
cout<< n.back();


cout << "\n first  value";
cout<< *n.begin();


 cout<<" \n\n";

for (int i = 0; i < n.size(); i++)
{
   cout<<"\n "<<n[i];
}

 cout<<" \n when we generate loop for reaching  specific value";

for (auto i = n.begin() ; i != n.end() ; i++){
          cout<<"  "<<*i;
}


n.clear();
cout << "\n Vector is cleared."<<n.size() ;

  
    return 0;
}