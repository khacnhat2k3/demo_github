#include<bits/stdc++.h>

using namespace std;

class Contact {
	public :
		string hoTen;
		string soDT;
		string diaChi;
	public :
		Contact(const string &name, const string &phone, const string &email)
			: hoTen(name), soDT(phone), diaChi(email){
			}
	void showContact () const {
		cout << "Ho ten :" << hoTen << endl;
		cout << "So dien thoai :" << soDT << endl;
		cout << "Dia chi email :" << diaChi << endl;

	}
};

class AddressBook {
	private :
		vector<Contact> contacts;
		
	public : 
		void Them(const Contact &contact){
			contacts.push_back(contact);
		}
		
		void Xoa(const string &phoneN){
			for(auto it = contacts.begin(); it != contacts.end(); it++){
				if(it->soDT == phoneN){
					contacts.erase(it);
					cout << "Lien he da duoc xoa" << endl;
					return;
				}
			}
			cout << "Khong tim thay so dien thoai hop le" << endl;
		}
		
		void Tim(const string &phoneN){
			for(const Contact &contact : contacts){
				if(contact.soDT == phoneN){
					cout << "Tim thay lien he" << endl;
					contact.showContact();
					return;
				}
			}
			cout << "Khong tim thay lien he " << endl;
		}
		
		void ShowAll() const {
			cout << "Danh sach tat ca cac lien he " << endl;
			for(const Contact &contact : contacts){
					contact.showContact();
					cout << "----------------" << endl;
				}
		}
};

int main(){
	AddressBook address;
	
	while(true){
		cout << "Chon tuy chon " << endl;
		cout << "1. Them lien he moi " << endl;
		cout << "2. Xoa lien he " << endl;
		cout << "3. Tim kiem lien he " << endl;
		cout << "4. Hien thi danh sach tat ca cac lien he " << endl;
		cout << "5. Thoat " << endl;
		cout << "------------------";
		
		
		int choice;
		cin >> choice;
		
		switch (choice){
			case 1 : {
				string name, phone, email;
                cout << "Nhap ho ten: ";
                cin.ignore();
                getline(cin, name);
                cout << "Nhap so dien thoai: ";
                cin >> phone;
                cout << "Nhap email: ";
                cin >> email;
                Contact newContact(name, phone, email);
                address.Them(newContact);
                break;
			}
			case 2: {
                string phone;
                cout << "Nhap so dien thoai can xoa";
                cin >> phone;
                address.Xoa(phone);
                break;
            }
            case 3: {
                string phone;
                cout << "Nhap so dien thoai can tim ";
                cin >> phone;
                address.Tim(phone);
                break;
            }
            case 4:
                address.ShowAll();
                break;
            case 5:
                return 0;
            default:
                cout << "Lua chon khong hop le" << endl;
                break;
		}
	}
}








































































