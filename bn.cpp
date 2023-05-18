#include<iostream>
#include<map>
#include<iterator>
#include<vector>
using namespace std;
struct information {
    string type[2];
    string number[2];
};
void add(map<string, information>& x) {
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
void del(string test, map<string, information>& x) {
    int index = 0;
    map<string, information>::iterator it;
    for (it = x.begin(); it != x.end(); it++) {
        if (it->first == test)
            break;
        index++;
    }
    x.erase(test);
}
void edit_name(string test, map<string, information>& x) {
    map<string, information>::iterator it;
    it = x.find(test);
    string m;
    cout << "now enter the second name\n";
    cin >> m;
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
void f_add(vector<pair<string, information>>& y, map<string, information>x) {
    map<string, information>::iterator it;
    string m;
    information temp;
    cout << "enter the name so you want to add to favorite list:";
    cin >> m;
    it = x.find(m);
    temp = it->second;
    y.push_back(pair<string, information>(m, temp));
}
void f_del(string test, vector<pair<string, information>>& x) {
    vector<pair<string, information>>::iterator it;
    for (it = x.begin(); it != x.end(); it++) {
        if ((*it).first == test) {
            break;
        }
    }
    x.erase(it);
}
void edit_favorite_list(vector<pair<string, information>>& x) {
    string s1, s2;
    int counter1 = 0, counter2 = 0;
    vector<pair<string, information>> t1, t2;
    cout << "enter the two names you want to change order:";
    cin >> s1 >> s2;
    vector<pair<string, information>>::iterator it1, it2;
    for (it1 = x.begin(); it1 != x.end(); it1++) {
        if ((*it1).first == s1) {
            break;
        }
        counter1++;
    }
    for (it2 = x.begin(); it2 != x.end(); it2++) {
        if ((*it2).first == s2) {
            break;
        }
        counter2++;
    }
    t1.push_back(*it1);
    t2.push_back(*it2);
    x[counter1] = t2[0];
    x[counter2] = t1[0];

}
void show_list(map<string, information>& x) {
    cout << "CONTACT LIST:" << endl;
    map<string, information>::iterator it;
    for (it = x.begin(); it != x.end(); it++) {
        cout << (*it).first << "  " << endl;
    }
}
void show_number_of_person(map<string, information>& x) {
    string name;
    cout << "Enter the name you want to see his/her numbers:";
    cin >> name;
    map<string, information>::iterator it;
    it = x.find(name);
    cout << "this user numbers are: " << (*it).second.type[0] << "   " << (*it).second.number[0] << endl;
    cout << (*it).second.type[1] << "   " << (*it).second.number[1] << endl;

}
void show_favorite_list(vector<pair<string, information>>& x) {
    vector<pair<string, information>>::iterator it;
    cout << "FAVORITE LIST:"<<endl;
    for (it = x.begin(); it != x.end(); it++) {
        cout << (*it).first << endl;
    }
}
int main() {
    map<string, information> lists;
    vector<pair<string, information>> favorite_lists;
    add(lists);
    add(lists);
    f_add(favorite_lists, lists);
    f_add(favorite_lists, lists);
    show_favorite_list(favorite_lists);

}