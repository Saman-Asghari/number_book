#include<iostream>
#include<map>
#include<iterator>
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
	for (auto i = x.begin(); i!= x.end(); i++) {
		if (i->first == test)
			break;
		index++;
	}
	x.erase(test);
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

int main() {
	map<string, information> lists;
	add(lists);
	add(lists);
	edit("saman", lists);
}