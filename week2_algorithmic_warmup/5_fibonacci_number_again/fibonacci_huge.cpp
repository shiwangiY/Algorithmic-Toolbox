#include <bits/stdc++.h>  
using namespace std;
#define ll long long 


//function to find length of pisano period 
ll pisano(ll m){

      ll prev=0;
      ll curr=1;
      ll ans=0; 

      for(int i=0; i<m*m; i++){
             //to find the mpdulo using swap 
            ll temp=0;
            temp= curr;
            curr= (prev+ curr) % m;
            prev= temp;

            if(prev==0 && curr==1)
            ans= i+1;  //to count the length of the sequence
      }
return ans;
}
 
 ll fibonacci_huge(ll n, ll m){
       
          ll pisanoPeriod = pisano(m);
          n= n% pisanoPeriod; //to find ex: 2015%8= 7 therefore we will find F7 since it will be equal to F2015 using pisano

          ll prev=0;
          ll curr=1;

          if(n==0) return 0;
          if(n==1) return 1; //first two digits of the sequence
         //to find F7
          for(int i=0; i<n-1; i++){
                ll temp=0;

                temp=curr;
                curr= (prev+curr)% m;
                prev= temp;
          } 
   return (curr%m); //F7%m (m=3(inthis example))
}
 

 int main(){

       ll n,m;
       cin>>n>>m;
       cout<<fibonacci_huge(n,m);
       return 0;
 }