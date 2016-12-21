#include<iostream>
#include<queue>
#include<string>
   
using namespace std;
	 
int main (){
	queue <string> names; 
	names.push(""); 
	names.push("Ed"); 
	names.push("is"); 
	names.push("Gwapo");
	
	names.pop ();
	cout << names.front() << endl;
	
	names.pop ();
	cout << names.front() << endl;
	
	names.pop ();
	cout << names.front() << endl;
	
	system("pause");
	return 0;
}
