#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]){
	if(argc<2){
		cout<<"Here is how to use it: Put a space & give me a WORD, do you hear that, GIVE ME A WORD to tell the meaning of\n";
		return 1;
	}
	transform(argv[1],argv[1]+(sizeof(argv[1])/sizeof(argv[1][0])),argv[1],::tolower);// converting to lowercase
//	cout<<argv[1]<<endl;
	bool log=true;
	if(argc>2)
		log=false;
	string str,cmpstr;
	bool found = false;
	ifstream fin("OxfordEnglishDictionary.txt");
	ofstream fout("history.log", ios::app);
	ofstream failed("failed.log", ios::app);
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
		if(log)
			fout<<str<<endl;
	}
	else if(log){
		failed<<argv[1]<<endl;
	}
	fin.close();
	fout.close();
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
