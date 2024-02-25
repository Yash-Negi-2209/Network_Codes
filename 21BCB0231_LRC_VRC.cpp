// REG NO.: 21BCB0231
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of inputs:"<<endl;
	cin>>n;
	vector<string> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	
	// Code for finding VRC and appending it to each message
	for(int i=0; i<v.size(); i++){
		int count=0;
		for(int j=0; j<v[i].length(); j++){
			if(v[i][j]=='1') count++;
		}
		if(count%2==0) v[i]+='0';
		else v[i]+='1';
	}
	cout<<"\nVRC for the follwoing inputs are: "<<endl;
	for(auto& it: v){
		cout<<it<<" ";
	}
	cout<<endl;

	string LRC="";
	//Code for finding the LRC
	for(int i=0; i<v[0].size()-1; i++){
		int count=0;
		for(int j=0; j<v.size(); j++){
			if(v[j][i]=='1') count++;
		}
		if(count%2==0) LRC+='0';
		else LRC+='1';
	}

	cout<<"\nLRC for the following input is: "<<LRC<<endl;
}