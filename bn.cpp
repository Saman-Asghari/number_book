#include<iostream>
#include<map>
#include<iterator>
#include<vector>
using namespace std;
struct information{
	string type[2];
	string number[2];
};
void add(map<string,information>& x) {
	string ty[2];
	string num[2];
	string name;
	cout << "enter the name:\n";
	cin >> name;
	cout << "enter the type and after that enter number:";
	for (int i = 0; i < 2; i++) {
		cin >> ty[i] >> num[i];
	}
	information temp;
	for (int i = 0; i < 2; i++) {
		temp.type[i] = ty[i];
		temp.number[i] = num[i];
	}
	x.insert(pair<string, information>(name, temp));
}
void del(string test,map<string, information>& x) {
	int index=0;
    map<string, information>::iterator it;
	for (it = x.begin(); it!= x.end(); it++) {
		if (it->first == test)
			break;
		index++;
	}
	x.erase(test);
}
void edit_name(string test,map<string, information>& x){
    map<string, information>::iterator it;
    it=x.find(test);
    string m;
    cout<<"now enter the second name\n";
    cin>>m;
    information value = it->second;
    x.erase(it);
    x[m] = value;
    
}
void edit(string test, map<string, information>& x) {
	int index;
	int choose;
	int action;
	string option[2];
	string temp[2];
	map<string, information>::iterator it;
	it = x.find(test);
	cout << "enter the number of actions:\n";
	cin >> action;
	for (int i = 0; i < action; i++) {
		cout << "\nenter 1 for editing number type enter 2 for editing the number:";
		cin >> choose;
		if (choose == 1) {
			cout << "first number or second number:";
			cin >> index;
			if (index == 1) {
				cin >> option[0];
				(*it).second.type[0] = option[0];
			}
			if (index == 2) {
				cin >> option[1];
				(*it).second.type[1] = option[1];
			}

		}
		if (choose == 2) {
			cout << "first number or second number:";
			cin >> index;
			if (index == 1) {
				cin >> temp[0];
				(*it).second.number[0] = option[0];
			}
			if (index == 2) {
				cin >> temp[1];
				(*it).second.number[1] = option[1];
			}

		}
	}

}
void f_add(string s,vector<pair<string,information>>&y,map<string, information>x){
    map<string, information>::iterator it;
    string m;
    information temp;
    cout<<"enter the name so you want to add to favorite list:";
    cin>>m;
    it=x.find(m);
    temp=it->second;
    y.push_back(pair<string,information>(m,temp));
}
void f_del(string test,vector<pair<string,information>>&x){
    vector<pair<string,information>>::iterator it;
    for(it=x.begin();it!=x.end();it++){
        if((*it).first==test){
            break;
        }
    }
    x.erase(it);
}
int main() {
	map<string, information> lists;
    vector<pair<string,information>> favorite_lists;
	add(lists);
	add(lists);
	edit("saman", lists);
    edit_name("saman",lists);
}