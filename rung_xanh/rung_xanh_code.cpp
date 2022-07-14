#include <bits/stdc++.h>
using namespace std;

struct Muong_thu {
    string name;
    int so_hieu;
};

Muong_thu gan(string _name, int _so_hieu) {
    Muong_thu temp;
    temp.name = _name;
    temp.so_hieu = _so_hieu;
    return temp;
}

class Rung_xanh {
   public:
    Muong_thu muong_thu;
    Rung_xanh* next;
    Rung_xanh(Muong_thu _muong_thu) {
        this->muong_thu = _muong_thu;
        this->next = nullptr;
    }
};

Rung_xanh* add(Rung_xanh* head, Muong_thu muong_thu) {
    Rung_xanh* result = new Rung_xanh(muong_thu);
    result->next = head;
    return result;
}

void print_list(Rung_xanh* head) {
    int i = 1;
    for (Rung_xanh* p = head; p != nullptr; p = p->next) {
        cout << i << ". "
             << "Name: " << p->muong_thu.name << endl;
        cout << "   "
             << "Weight: " << p->muong_thu.so_hieu << " kg" << endl;
        i++;
    }
}

void save_file(string path, Rung_xanh* head) {
    fstream file;
    file.open(path, ios::out);
    int i = 1;
    for (Rung_xanh* p = head; p != nullptr; p = p->next) {
        string a;
        a += to_string(i);
        a += ". Name: ";
        a += p->muong_thu.name;
        file << a << endl;
        string b;
        b += "   Weight: ";
        b += to_string(p->muong_thu.so_hieu);
        b += " kg";
        file << b << endl;
        i++;
    }
}

int main() {
    Rung_xanh* rung_xanh = nullptr;
    int i = 1;
    while (i >= 1) {
        if (i >= 2) {
            cout << "Any other members? (Answer YES or NO ok?)" << endl;
            string s;
            getline(cin, s);
            string a;
            getline(cin, a);
            if (a == "NO" || a == "NO ") break;
        }
        cout << "Welcome to Rung Xanh" << endl;
        cout << "What's member's name ?" << endl;
        string name;
        getline(cin, name);
        cout << "What's member's weight ?" << endl;
        int so_hieu;
        cin >> so_hieu;
        Muong_thu temp = gan(name, so_hieu);
        rung_xanh = add(rung_xanh, temp);
        i++;
    }
    cout << "Rung Xanh resident:" << endl;
    print_list(rung_xanh);
    save_file("cudan.txt", rung_xanh);
}
