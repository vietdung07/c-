
/*
- Thông tin sinh viên bao gồm:
	+) Mã sinh viên (id)
	+) Họ và tên (name)
	+) Giới tính (gender)
	+) Lớp (clas)
	+) Ngày sinh (day, month, year)
	+) GPA hệ số 4 (gpa)
- Xây dựng chương trình thực hiện yêu cầu sau:
	+) Thêm 1 sinh viên mới
	+) Xoá 1 sinh viên
	+) Hiển thị toàn bộ danh sách sinh viên
	+) Tìm kiếm sinh viên theo tên (name), hiển thị thông tin sinh viên đó
	+) Liệt kê sinh viên có GPA cao nhất
	+) Liệt kê sinh viên có GPA >= 2.5 theo thứ tự giảm dần
	+) Sắp xếp sinh viên theo tên (name)
	+) Cập nhật thông tin sinh viên
	+) Ghi thông tin sinh viên vào File
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#if 0

struct Sinhvien
{
	string id, name, gender, clas;
	int day, month, year;
	float gpa;
	Sinhvien *next;
};

struct List
{
	Sinhvien *head;
	Sinhvien *tail;
};

void khoitao(List &list)
{
	list.head = list.tail = nullptr;
}

Sinhvien *input()
{
	Sinhvien *newsv = new Sinhvien;

	cout << "Enter ID: ";
	cin >> newsv->id;
	cin.ignore();

	cout << "Enter Name: ";
	getline(cin, newsv->name);
	cout << "Enter Gender: ";
	getline(cin, newsv->gender);
	cout << "Enter Class: ";
	getline(cin, newsv->clas);

	cout << "Enter Day of birth: ";
	cin >> newsv->day;
	cout << "Enter Month of birth: ";
	cin >> newsv->month;
	cout << "Enter Year of birth: ";
	cin >> newsv->year;
	cin.ignore();

	cout << "Enter Your GPA: ";
	cin >> newsv->gpa;
	cin.ignore();

	newsv->next = nullptr;

	return newsv;
}

void themsinhvien(List &list)
{
	Sinhvien *sv = input();
	if (!list.head)
	{
		list.head = list.tail = sv;
	}
	else
	{
		list.tail->next = sv;
		list.tail = sv;
	}
}

void xoasinhvien(List &list)
{
	if (!list.head)
	{
		cout << "List is empty." << endl;
		return;
	}

	string id;
	cout << "Enter the ID you want to delete: ";
	cin.ignore();
	getline(cin, id);
	Sinhvien *svdel = list.head;
	Sinhvien *tmp = nullptr;

	while (svdel != nullptr && svdel->id != id)
	{
		tmp = svdel;
		svdel = svdel->next;
	}

	if (svdel == nullptr)
	{
		cout << "ID not found in the list." << endl;
		return;
	}

	if (tmp == nullptr)
	{
		list.head = svdel->next;
		if (list.head == nullptr)
			list.tail = nullptr;
	}
	else
	{
		tmp->next = svdel->next;
		if (list.tail == svdel)
		{
			list.tail = tmp;
			// tmp->next = nullptr;
		}
	}
	delete svdel;
	svdel = nullptr;
}

void output(Sinhvien *sv)
{
	cout << "------------------------------" << endl;
	cout << "ID: " << sv->id << endl;
	cout << "Name: " << sv->name << endl;
	cout << "Gender: " << sv->gender << endl;
	cout << "Date birth: "
		 << (sv->day >= 10 ? to_string(sv->day) : "0" + to_string(sv->day)) << "/"
		 << (sv->month >= 10 ? to_string(sv->month) : "0" + to_string(sv->month)) << "/"
		 << sv->year << endl;
	cout << "GPA: " << sv->gpa << endl;
	cout << "Class: " << sv->clas << endl;
}

void print(const List &list)
{
	if (!list.head)
	{
		cout << "List  is empty.";
		return;
	}

	Sinhvien *sv = list.head;
	while (sv != nullptr)
	{
		output(sv);
		sv = sv->next;
	}
}

void timkiemsinhvien(const List &list)
{
	if (!list.head)
	{
		cout << "List is empty." << endl;
		return;
	}

	cout << "Enter the name you want to find: ";
	cin.ignore();
	string id;
	getline(cin, id);

	Sinhvien *sv = list.head;
	bool found = false;
	while (sv != nullptr)
	{
		if (sv->id == id)
		{
			found = true;
			output(sv);
		}
		sv = sv->next;
	}
	if (!found)
	{
		cout << "No student were found in the list" << endl;
	}
}

void sinhviencogpacaonhat(List &list)
{
	if (list.head == nullptr)
	{
		cout << "List is empty." << endl;
		return;
	}

	Sinhvien *sv = list.head;
	float gpa = 0;

	while (sv != nullptr)
	{
		if (sv->gpa > gpa)
		{
			gpa = sv->gpa;
		}
		sv = sv->next;
	}

	sv = list.head;
	while (sv != nullptr)
	{
		if (sv->gpa == gpa)
		{
			output(sv);
		}
		sv = sv->next;
	}
}

bool check_gpa(Sinhvien *sv1, Sinhvien *sv2)
{
	return sv1->gpa > sv2->gpa;
}

void sinhviengpakha(List &list)
{
	if (list.head == nullptr)
	{
		cout << "List is empty." << endl;
		return;
	}

	vector<Sinhvien *> vec;
	Sinhvien *sv = list.head;
	while (sv != nullptr)
	{
		if (sv->gpa >= 2.5)
		{
			vec.push_back(sv);
		}
		sv = sv->next;
	}
	sort(vec.begin(), vec.end(), check_gpa);

	for (Sinhvien *i : vec)
	{
		output(i);
	}
}

void capnhatthongtinsinhvien(List &list)
{
	if (!list.head)
	{
		cout << "List is empty!" << endl;
		return;
	}

	string id;
	cout << "Tim ID: ";
	cin >> id;
	cin.ignore();
	Sinhvien *sv = list.head;
	while (sv != nullptr)
	{
		if (sv->id == id)
		{
			break;
		}
		sv = sv->next;
	}
	if (sv == nullptr)
	{
		cout << "Danh sach khong co sinh vien!" << endl;
	}
	else
	{
		cout << "Cap nhat thong tin sinh vien." << endl;
		cin.ignore(); // Clear the input buffer before reading new line input

		cout << "Enter Name: ";
		getline(cin, sv->name);
		cout << "Enter Gender: ";
		getline(cin, sv->gender);
		cout << "Enter Class: ";
		getline(cin, sv->clas);

		cout << "Enter Day of birth: ";
		cin >> sv->day;
		cout << "Enter Month of birth: ";

		cin >> sv->month;
		cout << "Enter Year of birth: ";
		cin >> sv->year;
		cin.ignore();

		cout << "Enter Your GPA: ";
		cin >> sv->gpa;
		cin.ignore();
	}
}

void ghiDanhSachVaoFile(const List &list, const string &filename)
{
	ofstream outFile(filename);

	if (!outFile)
	{
		cout << "Khong the mo file!" << endl;
		return;
	}

	if (!list.head)
	{
		cout << "Danh sach trong, khong co gi de ghi!" << endl;
		return;
	}

	Sinhvien *sv = list.head;
	while (sv != nullptr)
	{
		outFile << "ID: " << sv->id << endl;
		outFile << "Name: " << sv->name << endl;
		outFile << "Gender: " << sv->gender << endl;
		outFile << "Class: " << sv->clas << endl;
		outFile << "Date of Birth: " << sv->day << "/" << sv->month << "/" << sv->year << endl;
		outFile << "GPA: " << sv->gpa << endl;
		outFile << "------------------------------" << endl;
		sv = sv->next;
	}

	outFile.close();
	cout << "Du lieu da duoc ghi vao file: " << filename << endl;
}

int main()
{
	List list;
	khoitao(list);

	cout << "---------------Quan ly danh sach sinh vien---------------" << endl;
	cout << " " << endl;
	cout << "[1]  Them sinh vien moi" << endl;
	cout << "[2]  Xoa sinh vien" << endl;
	cout << "[3]  Hien thi ALL sinh vien" << endl;
	cout << "[4]  Tim kiem sinh vien theo ID" << endl;
	cout << "[5]  Danh sach sinh vien GPA cao nhat" << endl;
	cout << "[6]  Danh sach sinh vien co GPA >= 2.5" << endl;
	cout << "[7]  Thay doi thong tin sinh vien" << endl;
	cout << "[8]  Ghi danh sach sinh vien vao CSDL" << endl;
	cout << "[9]  Exit" << endl;

	cout << " " << endl;
	cout << "---------------------------------------------------------" << endl;

	while (1)
	{
		cout << " " << endl;
		cout << "Moi ban chon lua:";
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			int n;
			cout << "Ban muon nhap them bao nhieu sinh vien: ";
			cin >> n;
			while (n--)
			{
				themsinhvien(list);
				cout << " " << endl;
			}
		}

		else if (choice == 2)
		{
			int n;
			cout << "Ban muon nhap them bao nhieu sinh vien: ";
			cin >> n;
			while (n--)
			{
				xoasinhvien(list);
				cout << " " << endl;
			}
		}

		else if (choice == 3)
		{
			print(list);
			cout << " " << endl;
		}

		else if (choice == 4)
		{
			timkiemsinhvien(list);
			cout << " " << endl;
		}

		else if (choice == 5)
		{
			sinhviencogpacaonhat(list);
			cout << " " << endl;
		}

		else if (choice == 6)
		{
			sinhviengpakha(list);
			cout << " " << endl;
		}

		else if (choice == 7)
		{
			capnhatthongtinsinhvien(list);
			cout << " " << endl;
		}
		else if (choice == 8)
		{
			ghiDanhSachVaoFile(list, "sinhvien.txt");
			cout << " " << endl;
		}
		else if (choice == 9)
		{
			cout << "OK" << endl;
			break;
		}

		else
		{
			cout << "Lua chon cua ban khong chinh xac!" << endl;
			cout << "Vui long nhap lai!" << endl;
			cout << " " << endl;
		}
	}

	return 0;
}
#endif

int main()
{
	
	return 0;
}