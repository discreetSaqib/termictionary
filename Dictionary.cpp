#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]){
	transform(argv[1],argv[1]+(sizeof(argv[1])/sizeof(argv[1][0])),argv[1],::tolower);// converting to lowercase
//	cout<<argv[1]<<endl;
	ifstream fin("OxfordEnglishDictionary.txt");
	string str,cmpstr;
	bool found = false;
	while(fin){
		getline(fin, str);		
		int pos=str.find_first_of(' ');
		cmpstr=str.substr(0,pos);
		transform(cmpstr.begin(), cmpstr.end(), cmpstr.begin(), ::tolower);
//		cout<<"pos="<<pos<<cmpstr<<endl;
//		if(!strcmpi(cmpstr, argv[1])){
		if(!cmpstr.compare((argv[1]))){
			found=true;
			break;
		}
	}
	if(found){
		cout<<str<<endl;
	}
	return 0;
}
/*
int main(){
	string str="sAqib";
	char *a="saqib";
	cout<<str.compare(a);
	return 0;
}
*/
