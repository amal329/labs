//Create a hypercube graph for any given degree
#include<bits/stdc++.h>
using namespace std;

bool differbyone(int a, int b){
	int x=a^b;
	if(x && (!(x & (x-1))))
		return true;
	else
		return false;	
}

void print(vector<int> g[],int m)
{   
	cout<<"The adjacency list representation of the graph is:"<<endl;
    for(int i=0;i<m;i++)
    {	
	int degree=0;
        cout<<i<<": ";
        for(int j=0;j<g[i].size();j++)
        {
        	cout<<" -> ";
			degree++;
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
	cout<<"Degree : "<<degree<<endl;
    }
}

int main(){
	
	int deg,size;
	cout<<"Enter the degree: "<<endl;
	cin>>deg;
	
	size=pow(2,deg);
	cout<<size<<endl;
	vector<int> g[size];
	set<int> s;
	
	for(int i=0;i<size;i++){
		s.insert(i);
	}
	
	for(int i=0;i<size;i++){
		int n1=i;
		set<int> ::iterator itr;
		for(itr=s.begin();itr!=s.end();itr++){
			if(differbyone(n1,*(itr))){
				g[n1].push_back(*itr);
			}
		}
	}
	print(g,size);
}
