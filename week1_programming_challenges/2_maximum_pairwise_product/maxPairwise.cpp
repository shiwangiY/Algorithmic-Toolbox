#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll maximumPairwise(const vector<int>& num){
    
    int index1=0, index2=0;
    
    for(int i=0; i<num.size(); i++){

        if((index1 == 0) || (num[i]> num[index1]))
        { index1=i; 
        
        }
    }
        for(int j=1; j<num.size(); j++){
            if((j != index1) && ((index2 == 0) || (num[j]>num[index2])))
            index2=j;
        }

   // cout<<num[index1]<<" "<<num[index2]<<endl;
   ll result= (((ll)num[index1])*num[index2]);
  //  cout<<result<<endl;
    return result;
}

int main(){

    
    int n;

    cin>>n;
    vector<int>num(n);
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    ll result= maximumPairwise(num);
    cout<<result<<endl;

    return 0;
}
   