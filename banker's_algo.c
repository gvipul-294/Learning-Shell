#include<iostream>
using namespace std;
int main(){
int m,n;
cout<<"Enter number of processes and resources : ";
cin>>n>>m;
int allocation[n][m], max[n][m], available[m], need[n][m];
int finish[n];
for(int i=0;i<n;i++){
finish[i]=-1;
}
cout<<"Enter allocated resources for each process :\n";
for(int i=0; i<n; i++){
cout<<"P"<<i+1<<" : ";
for(int j=0;j <m;j++){
cin>>allocation[i][j];
}
}
cout<<"Enter maximum resources for each process :\n";
for(int i=0; i<n; i++){
cout<<"P"<<i+1<<" : ";
for(int j=0;j <m;j++){
cin>>max[i][j];
}
}
cout<<"Enter available resources : "<<endl;
char ch;
for(int i=0,ch='A';i <m;i++ ,ch++){
cout<<(char)ch<<" : ";
cin>>available[i];
}
cout<<"Need :"<<endl;
for(int i=0;i<n; i++){
for(int j=0;j<m;j++){
need[i][j]= max[i][j]- allocation[i][j];
cout << need[i][j]<<" ";
}
cout<<endl;
}
bool t=true,r[n];
int c=0,j=0;
for(int i=0 ;i<n;i++){
if(r[i]==false){
for(j=0;j<m;j++){
if(need[i][j]>available[j])
break;
} if(j==m){
t=false;
finish[c]=i;
c++;
r[i]=true;
for(int k=0;k<m;k++){
available[k]= available[k]+ allocation[i][k];
}
}
} if(i==n-1 && t== false ){
i=-1; t=true;
cout<<endl;
}
}
if(c!=n) cout<<"Unsafe state!!";
else { cout<<"System is in safe state.\nExecution sequence is : ";
for (int i=0;i<c;i++){
cout<<"P"<<finish[i]+1<<" ";
}
}
}
