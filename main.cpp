#include <iostream>
#include "Mylib.h"
using namespace std;


enum TT {
	RIGHT, LEFT, UP, DOWN,  // Trang thai cua Person
};

struct Toado {				// Giu toa do cua Person, Virus, Heal, Rua tay
	int x, y;
};

class Person {
public:						//Giu thong tin cua Person
	Toado Person;
	TT tt;
};
void Khoi_tao(Person& person) {     // Ham kho tao Person voi toa do (1,1)
	person.Person.x = 1;
	person.Person.y = 1;
	gotoXY(person.Person.x, person.Person.y);
	cout << "0";
	person.tt = DOWN;
}

class Corona_Game {					
private:
	Toado p[80];					// Toa do cua 80 Virus 
	Toado q[20];					// Toa do cua 20 Heal
	Toado y[10];					// Toa do cua 10 Rua tay 
public:

	

	Corona_Game() {};
	~Corona_Game() {};


	// Ham tao hieu ung nhap nhay cho Heal va Rua tay 
	void Nhapnhay(Person& person, Corona_Game& A) {

		//Nhap nhay cho Rua tay 
		for (int i = 0; i < 10; i++) {
			if ((person.Person.x != A.y[i].x) && (person.Person.y != A.y[i].y)) {
				gotoXY(A.y[i].x, A.y[i].y);
				cout << " ";
				Sleep(3);
				SetColor(14);
				gotoXY(A.y[i].x, A.y[i].y);
				cout << "Y";
				SetColor(15);

			}
		}

		//Nhap nhay cho Heal
		for (int i = 0; i < 20; i++) {
			if ((person.Person.x != A.q[i].x) && (person.Person.y != A.q[i].y)) {
				gotoXY(A.q[i].x, A.q[i].y);
				cout << " ";
				Sleep(3);
				SetColor(2);
				gotoXY(A.q[i].x, A.q[i].y);
				cout << "+";
				SetColor(15);
			}
		}
	}

	// Ham tao Virus, Heal, Rua tay
	void Creat_Virus_Heal(Corona_Game& A) {

		//Ham tao Rua tay 

		for (int i = 0; i < 10; i++) {
			SetColor(14);
			if (i == 0) { //Tao 1 Rua tay truoc 
				A.y[i].x = 1 + rand() % 99;
				A.y[i].y = 1 + rand() % 24;
				gotoXY(A.y[i].x, A.y[i].y);
				cout << "Y";
				continue;
			}
			int x = i;
			int y = i;
			A.y[x].x = 1 + rand() % 99;
			A.y[x].y = 1 + rand() % 24;
			for (int j = 0; j < y; j++) {
				if (A.y[x].x == A.y[j].x && A.y[x].y == A.y[j].y) {
					A.y[x].x = 1 + rand() % 99;
					A.y[x].y = 1 + rand() % 24;
					i = 0;
				}
			}
			gotoXY(A.y[x].x, A.y[x].y);
			cout << "Y";
		}

		//Ham tao Heal 
		for (int i = 0; i < 20; i++) {
			if (i == 0) { // Tao 1 Heal truoc 
				SetColor(2);
				A.q[i].x = 1 + rand() % 99;
				A.q[i].y = 1 + rand() % 24;
				for (int j = 0; j < 10; j++) {
					while ((A.q[i].x == A.y[j].x) && (A.q[i].y == A.y[j].y)) {
						A.q[i].x = 1 + rand() % 99;
						A.q[i].y = 1 + rand() % 24;
						j = 0;
					}
				}
				gotoXY(A.q[i].x, A.q[i].y);
				cout << "+";
				continue;
			}
			SetColor(2);
			A.q[i].x = 1 + rand() % 99;
			A.q[i].y = 1 + rand() % 24;
			int x = i;
			int y = i;
			QuangDong: for (int a = 1; a <= y; a++) {
				while ((A.q[x].x == A.q[a - 1].x) && (A.q[x].y == A.q[a - 1].y)) {
					A.q[x].x = 1 + rand() % 99;
					A.q[x].y = 1 + rand() % 24;
					a = 1;
				}
			}
			for (int j = 0; j < 10; j++) {
				while ((A.q[x].x == A.y[j].x) && (A.q[x].y == A.y[j].y)) {
					A.q[x].x = 1 + rand() % 99;
					A.q[x].y = 1 + rand() % 24;
					goto QuangDong;
					j = 0;
				}
			}
			gotoXY(A.q[x].x, A.q[x].y);
			cout << "+";
		}

		//Ham tao Virus 
		for (int i = 0; i < 80; i++) {
			SetColor(4);
			if (i == 0) { // Tao 1 Virus truoc 
				A.p[i].x = 1 + rand() % 99;
				A.p[i].y = 1 + rand() % 24;
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 20; k++) {
						while (((A.p[i].x == A.y[j].x) && (A.p[i].y == A.y[j].y)) || ((A.p[i].x == A.q[k].x) && (A.p[i].y == A.q[k].y))) {
							A.p[i].x = 1 + rand() % 99;
							A.p[i].y = 1 + rand() % 24;
							j = 0;
							k = 0;
						}
					}
				}
				gotoXY(A.p[i].x, A.p[i].y);
				cout << "*";
				continue;
			}
			int x = i;
			int y = i;
			A.p[x].x = 1 + rand() % 99;
			A.p[x].y = 1 + rand() % 24;

			MinhDuc: for (int a = 1; a <= y; a++) {
				while ((A.p[x].x == A.p[a - 1].x) && (A.p[x].y == A.p[a - 1].y)) {
					A.p[x].x = 1 + rand() % 99;
					A.p[x].y = 1 + rand() % 24;
					a = 1;
				}
			}
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 20; k++) {
					while (((A.p[x].x == A.y[j].x) && (A.p[x].y == A.y[j].y)) || ((A.p[x].x == A.q[k].x) && (A.p[x].y == A.q[k].y))) {
						A.p[x].x = 1 + rand() % 99;
						A.p[x].y = 1 + rand() % 24;
						goto MinhDuc;
						j = 0;
						k = 0;
					}
				}
			}
			gotoXY(A.p[x].x, A.p[x].y);
			cout << "*";
			SetColor(15);
		}

	}

	//Ham su li chuong trinh 
	void DieuKhien_DiChuyen(Person& person, Corona_Game& A)
	{
		Khoi_tao(person);
		int count = 20;
		gotoXY(105, 10);
		cout << "DIEM CUA BAN : ";
		while (true) {
			Nocursortype();
			gotoXY(122, 10);
			cout << "       ";
			gotoXY(122, 10);
			cout << count;
			switch (person.tt) {
				// Su li khi Nguoi di chuyen tren 
			case UP: {
				Nhapnhay(person, A);
				SetColor(15);
				Nocursortype();
				gotoXY(person.Person.x, person.Person.y);
				cout << " ";
				gotoXY(person.Person.x, person.Person.y - 1);
				cout << "0";
				//Ham khi cham bien 
				for (int i = 1; i < 99; i++) {
					if (person.Person.x == i && person.Person.y == 1) {
						system("cls");
						cout << "THUA CUOC !! " << endl;
						Sleep(2000);
						cout << "DIEM CUA BAN LA : " << count << endl;
						exit(1);
					}
				}
				
				// Ham xu li khi an Heal 
				for (int i = 0; i < 20; i++) {
					if ((person.Person.x == A.q[i].x) && (person.Person.y == A.q[i].y)) {
						int x = i;
						count = count + 5;
						SetColor(2);
						A.q[x].x = 1 + rand() % 99;
						A.q[x].y = 1 + rand() % 24;
					TanPhong: for (int a = 0; a < 20; a++) {
						if (a != x) {
							while ((A.q[x].x == A.q[a].x) && (A.q[x].y == A.q[a].y)) {
								A.q[x].x = 1 + rand() % 99;
								A.q[x].y = 1 + rand() % 24;
								a = 0;
							}
						}
					}
					for (int j = 0; j < 10; j++) {
						for (int k = 0; k < 80; k++) {
							while (((A.q[x].x == A.y[j].x) && (A.q[x].y == A.y[j].y)) || ((A.q[x].x == A.p[k].x) && (A.q[x].y == A.p[k].y))) {
								A.q[x].x = 1 + rand() % 99;
								A.q[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto TanPhong;
							}
						}
					}

					gotoXY(A.q[x].x, A.q[x].y);
					cout << "+";
					SetColor(15);
					}
				}

				//Ham su li khi di vao Virus 
				for (int i = 0; i < 80; i++) {
					if ((person.Person.x == A.p[i].x) && (person.Person.y == A.p[i].y)) {
						int x = i;
						count = count - 10;
						SetColor(4);
						A.p[x].x = 1 + rand() % 99;
						A.p[x].y = 1 + rand() % 24;
					MinhQuang:for (int a = 0; a < 80; a++) {
						if (a != x) {
							while ((A.p[x].x == A.p[a].x) && (A.p[x].y == A.p[a].y)) {
								A.p[x].x = 1 + rand() % 99;
								A.p[x].y = 1 + rand() % 24;
								a = 0;
							}
						}
					}
					for (int j = 0; j < 10; j++) {
						for (int k = 0; k < 20; k++) {
							while (((A.p[x].x == A.y[j].x) && (A.p[x].y == A.y[j].y)) || ((A.p[x].x == A.q[k].x) && (A.p[x].y == A.q[k].y))) {
								A.p[x].x = 1 + rand() % 99;
								A.p[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto MinhQuang;
							}
						}
					}
					gotoXY(A.p[x].x, A.p[x].y);
					cout << "*";
					}
					SetColor(15);
				}

				//Ham su li khi an Rua tay 
				for (int i = 0; i < 10; i++) {
					if ((person.Person.x == A.y[i].x) && (person.Person.y == A.y[i].y)) {
						int x = i;
						count = count + 2;
						SetColor(14);
						A.y[x].x = 1 + rand() % 99;
						A.y[x].y = 1 + rand() % 24;
					LapTrinh: for (int a = 0; a < 10; a++) {
						if (a != x) {
							while ((A.y[x].x == A.y[a].x) && (A.y[x].y == A.y[a].y)) {
								A.y[x].x = 1 + rand() % 99;
								A.y[x].y = 1 + rand() % 24;
							}
						}
					}
					for (int j = 0; j < 20; j++) {
						for (int k = 0; k < 80; k++) {
							while (((A.y[x].x == A.q[j].x) && (A.y[x].y == A.q[j].y)) || ((A.y[x].x == A.p[k].x) && (A.y[x].y == A.p[k].y))) {
								A.y[x].x = 1 + rand() % 99;
								A.y[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto LapTrinh;
							}
						}
					}
					gotoXY(A.y[x].x, A.y[x].y);
					cout << "Y";
					}
				}
				(person.Person.y)--;
				//Sleep(30);
				if (count <= 0) {
					system("cls");
					cout << "BAN DA BI NHIEM BENH !!! " << endl;
					cout << "THUA CUOC !! " << endl;
					Sleep(2000);
					exit(1);
				}
				if (count >= 200) {
					system("cls");
					cout << "BAN DA HOAN THANH NHIEM VU !! " << endl;
					cout << "CHUC MUNG BAN DA THOAT KHOI VUNG DICH !!" << endl;
					Sleep(3000);
					exit(1);
				}
				break;
			}

			//Su li khi nguoi di chuyen xuong duoi

			case DOWN: {
				Nhapnhay(person, A);
				Nocursortype();
				SetColor(15);
				gotoXY(person.Person.x, person.Person.y);
				cout << " ";
				gotoXY(person.Person.x, person.Person.y + 1);
				cout << "0";
				for (int i = 1; i < 99; i++) {
					if (person.Person.x == i && person.Person.y == 24) {
						system("cls");
						cout << "THUA CUOC !! " << endl;
						Sleep(2000);
						cout << "DIEM CUA BAN LA : " << count << endl;
						exit(1);
					}
				}

				for (int i = 0; i < 20; i++) {
					if ((person.Person.x == A.q[i].x) && (person.Person.y == A.q[i].y)) {
						int x = i;
						count = count + 5;
						SetColor(2);
						A.q[x].x = 1 + rand() % 99;
						A.q[x].y = 1 + rand() % 24;
					TanPhong1: for (int a = 0; a < 20; a++) {
						if (a != x) {
							while ((A.q[x].x == A.q[a].x) && (A.q[x].y == A.q[a].y)) {
								A.q[x].x = 1 + rand() % 99;
								A.q[x].y = 1 + rand() % 24;
								a = 0;
							}
						}
					}
					for (int j = 0; j < 10; j++) {
						for (int k = 0; k < 80; k++) {
							while (((A.q[x].x == A.y[j].x) && (A.q[x].y == A.y[j].y)) || ((A.q[x].x == A.p[k].x) && (A.q[x].y == A.p[k].y))) {
								A.q[x].x = 1 + rand() % 99;
								A.q[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto TanPhong1;
							}
						}
					}

					gotoXY(A.q[x].x, A.q[x].y);
					cout << "+";
					SetColor(15);
					}
				}
				for (int i = 0; i < 80; i++) {
					if ((person.Person.x == A.p[i].x) && (person.Person.y == A.p[i].y)) {
						int x = i;
						count = count - 10;
						SetColor(4);
						A.p[x].x = 1 + rand() % 99;
						A.p[x].y = 1 + rand() % 24;
					MinhQuang1:for (int a = 0; a < 80; a++) {
						if (a != x) {
							while ((A.p[x].x == A.p[a].x) && (A.p[x].y == A.p[a].y)) {
								A.p[x].x = 1 + rand() % 99;
								A.p[x].y = 1 + rand() % 24;
								a = 0;
							}
						}
					}
					for (int j = 0; j < 10; j++) {
						for (int k = 0; k < 20; k++) {
							while (((A.p[x].x == A.y[j].x) && (A.p[x].y == A.y[j].y)) || ((A.p[x].x == A.q[k].x) && (A.p[x].y == A.q[k].y))) {
								A.p[x].x = 1 + rand() % 99;
								A.p[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto MinhQuang1;
							}
						}
					}
					gotoXY(A.p[x].x, A.p[x].y);
					cout << "*";
					}
					SetColor(15);
				}
				for (int i = 0; i < 10; i++) {
					if ((person.Person.x == A.y[i].x) && (person.Person.y == A.y[i].y)) {
						int x = i;
						count = count + 2;
						SetColor(14);
						A.y[x].x = 1 + rand() % 99;
						A.y[x].y = 1 + rand() % 24;
					LapTrinh1: for (int a = 0; a < 10; a++) {
						if (a != x) {
							while ((A.y[x].x == A.y[a].x) && (A.y[x].y == A.y[a].y)) {
								A.y[x].x = 1 + rand() % 99;
								A.y[x].y = 1 + rand() % 24;
							}
						}
					}
					for (int j = 0; j < 20; j++) {
						for (int k = 0; k < 80; k++) {
							while (((A.y[x].x == A.q[j].x) && (A.y[x].y == A.q[j].y)) || ((A.y[x].x == A.p[k].x) && (A.y[x].y == A.p[k].y))) {
								A.y[x].x = 1 + rand() % 99;
								A.y[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto LapTrinh1;
							}
						}
					}
					gotoXY(A.y[x].x, A.y[x].y);
					cout << "Y";
					}
				}
				(person.Person.y)++;
				//Sleep(30);
				if (count <= 0) {
					system("cls");
					cout << "BAN DA BI NHIEM BENH !!! " << endl;
					cout << "THUA CUOC !! " << endl;
					Sleep(2000);
					exit(1);
				}
				if (count >= 200) {
					system("cls");
					cout << "BAN DA HOAN THANH NHIEM VU !! " << endl;
					cout << "CHUC MUNG BAN DA THOAT KHOI VUNG DICH !!" << endl;
					Sleep(3000);
					exit(1);
				}
				break;
			}

			case LEFT: {
				Nhapnhay(person, A);
				Nocursortype();
				SetColor(15);
				gotoXY(person.Person.x, person.Person.y);
				cout << " ";
				gotoXY(person.Person.x - 1, person.Person.y);
				cout << "0";
				for (int i = 1; i < 24; i++) {
					if (person.Person.x == 1 && person.Person.y == i) {
						system("cls");
						cout << "THUA CUOC !! " << endl;
						Sleep(2000);
						cout << "DIEM CUA BAN LA : " << count << endl;
						exit(1);
					}
				}

				for (int i = 0; i < 20; i++) {
					if ((person.Person.x == A.q[i].x) && (person.Person.y == A.q[i].y)) {
						int x = i;
						count = count + 5;
						SetColor(2);
						A.q[x].x = 1 + rand() % 99;
						A.q[x].y = 1 + rand() % 24;
					TanPhong2: for (int a = 0; a < 20; a++) {
						if (a != x) {
							while ((A.q[x].x == A.q[a].x) && (A.q[x].y == A.q[a].y)) {
								A.q[x].x = 1 + rand() % 99;
								A.q[x].y = 1 + rand() % 24;
								a = 0;
							}
						}
					}
					for (int j = 0; j < 10; j++) {
						for (int k = 0; k < 80; k++) {
							while (((A.q[x].x == A.y[j].x) && (A.q[x].y == A.y[j].y)) || ((A.q[x].x == A.p[k].x) && (A.q[x].y == A.p[k].y))) {
								A.q[x].x = 1 + rand() % 99;
								A.q[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto TanPhong2;
							}
						}
					}

					gotoXY(A.q[x].x, A.q[x].y);
					cout << "+";
					SetColor(15);
					}
				}
				for (int i = 0; i < 80; i++) {
					if ((person.Person.x == A.p[i].x) && (person.Person.y == A.p[i].y)) {
						int x = i;
						count = count -10;
						SetColor(4);
						A.p[x].x = 1 + rand() % 99;
						A.p[x].y = 1 + rand() % 24;
					MinhQuang2:for (int a = 0; a < 80; a++) {
						if (a != x) {
							while ((A.p[x].x == A.p[a].x) && (A.p[x].y == A.p[a].y)) {
								A.p[x].x = 1 + rand() % 99;
								A.p[x].y = 1 + rand() % 24;
								a = 0;
							}
						}
					}
					for (int j = 0; j < 10; j++) {
						for (int k = 0; k < 20; k++) {
							while (((A.p[x].x == A.y[j].x) && (A.p[x].y == A.y[j].y)) || ((A.p[x].x == A.q[k].x) && (A.p[x].y == A.q[k].y))) {
								A.p[x].x = 1 + rand() % 99;
								A.p[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto MinhQuang2;
							}
						}
					}
					gotoXY(A.p[x].x, A.p[x].y);
					cout << "*";
					}
					SetColor(15);
				}
				for (int i = 0; i < 10; i++) {
					if ((person.Person.x == A.y[i].x) && (person.Person.y == A.y[i].y)) {
						int x = i;
						count = count + 2;
						SetColor(14);
						A.y[x].x = 1 + rand() % 99;
						A.y[x].y = 1 + rand() % 24;
					LapTrinh2: for (int a = 0; a < 10; a++) {
						if (a != x) {
							while ((A.y[x].x == A.y[a].x) && (A.y[x].y == A.y[a].y)) {
								A.y[x].x = 1 + rand() % 99;
								A.y[x].y = 1 + rand() % 24;
							}
						}
					}
					for (int j = 0; j < 20; j++) {
						for (int k = 0; k < 80; k++) {
							while (((A.y[x].x == A.q[j].x) && (A.y[x].y == A.q[j].y)) || ((A.y[x].x == A.p[k].x) && (A.y[x].y == A.p[k].y))) {
								A.y[x].x = 1 + rand() % 99;
								A.y[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto LapTrinh2;
							}
						}
					}
					gotoXY(A.y[x].x, A.y[x].y);
					cout << "Y";
					}
				}
				(person.Person.x)--;
				//Sleep(300);
				if (count <= 0) {
					system("cls");
					cout << "BAN DA BI NHIEM BENH !!! " << endl;
					cout << "THUA CUOC !! " << endl;
					Sleep(2000);
					exit(1);
				}
				if (count >= 200) {
					system("cls");
					cout << "BAN DA HOAN THANH NHIEM VU !! " << endl;
					cout << "CHUC MUNG BAN DA THOAT KHOI VUNG DICH !!" << endl;
					Sleep(3000);
					exit(1);
				}
				break;
			}

			case RIGHT: {
				Nhapnhay(person, A);
				Nocursortype();
				SetColor(15);
				gotoXY(person.Person.x, person.Person.y);
				cout << " ";
				gotoXY(person.Person.x + 1, person.Person.y);
				cout << "0";
				for (int i = 1; i < 24; i++) {
					if (person.Person.x == 99 && person.Person.y == i) {
						system("cls");
						cout << "THUA CUOC !! " << endl;
						Sleep(2000);
						cout << "DIEM CUA BAN LA : " << count << endl;
						exit(1);
					}
				}
				for (int i = 0; i < 20; i++) {
					if ((person.Person.x == A.q[i].x) && (person.Person.y == A.q[i].y)) {
						int x = i;
						count = count + 5;
						SetColor(2);
						A.q[x].x = 1 + rand() % 99;
						A.q[x].y = 1 + rand() % 24;
					TanPhong3: for (int a = 0; a < 20; a++) {
						if (a != x) {
							while ((A.q[x].x == A.q[a].x) && (A.q[x].y == A.q[a].y)) {
								A.q[x].x = 1 + rand() % 99;
								A.q[x].y = 1 + rand() % 24;
								a = 0;
							}
						}
					}
					for (int j = 0; j < 10; j++) {
						for (int k = 0; k < 80; k++) {
							while (((A.q[x].x == A.y[j].x) && (A.q[x].y == A.y[j].y)) || ((A.q[x].x == A.p[k].x) && (A.q[x].y == A.p[k].y))) {
								A.q[x].x = 1 + rand() % 99;
								A.q[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto TanPhong3;
							}
						}
					}

					gotoXY(A.q[x].x, A.q[x].y);
					cout << "+";
					SetColor(15);
					}
				}
				for (int i = 0; i < 80; i++) {
					if ((person.Person.x == A.p[i].x) && (person.Person.y == A.p[i].y)) {
						int x = i;
						count = count - 10;
						SetColor(4);
						A.p[x].x = 1 + rand() % 99;
						A.p[x].y = 1 + rand() % 24;
					MinhQuang3:for (int a = 0; a < 80; a++) {
						if (a != x) {
							while ((A.p[x].x == A.p[a].x) && (A.p[x].y == A.p[a].y)) {
								A.p[x].x = 1 + rand() % 99;
								A.p[x].y = 1 + rand() % 24;
								a = 0;
							}
						}
					}
					for (int j = 0; j < 10; j++) {
						for (int k = 0; k < 20; k++) {
							while (((A.p[x].x == A.y[j].x) && (A.p[x].y == A.y[j].y)) || ((A.p[x].x == A.q[k].x) && (A.p[x].y == A.q[k].y))) {
								A.p[x].x = 1 + rand() % 99;
								A.p[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto MinhQuang3;
							}
						}
					}
					gotoXY(A.p[x].x, A.p[x].y);
					cout << "*";
					}
					SetColor(15);
				}
				for (int i = 0; i < 10; i++) {
					if ((person.Person.x == A.y[i].x) && (person.Person.y == A.y[i].y)) {
						int x = i;
						count = count + 2;
						SetColor(14);
						A.y[x].x = 1 + rand() % 99;
						A.y[x].y = 1 + rand() % 24;
					LapTrinh3: for (int a = 0; a < 10; a++) {
						if (a != x) {
							while ((A.y[x].x == A.y[a].x) && (A.y[x].y == A.y[a].y)) {
								A.y[x].x = 1 + rand() % 99;
								A.y[x].y = 1 + rand() % 24;
							}
						}
					}
					for (int j = 0; j < 20; j++) {
						for (int k = 0; k < 80; k++) {
							while (((A.y[x].x == A.q[j].x) && (A.y[x].y == A.q[j].y)) || ((A.y[x].x == A.p[k].x) && (A.y[x].y == A.p[k].y))) {
								A.y[x].x = 1 + rand() % 99;
								A.y[x].y = 1 + rand() % 24;
								j = 0;
								k = 0;
								goto LapTrinh3;
							}
						}
					}
					gotoXY(A.y[x].x, A.y[x].y);
					cout << "Y";
					}
				}
				(person.Person.x)++;
				//Sleep(300);
				if (count <= 0) {
					system("cls");
					cout << "BAN DA BI NHIEM BENH !!! " << endl;
					cout << "THUA CUOC !! " << endl;
					Sleep(2000);
					exit(1);
				}
				if (count >= 200) {
					system("cls");
					cout << "BAN DA HOAN THANH NHIEM VU !! " << endl;
					cout << "CHUC MUNG BAN DA THOAT KHOI VUNG DICH !! " << endl;
					Sleep(3000);
					exit(1);
				}
				break;
			}
			default: {
				break;
			}
			}
			if (_kbhit()) // Neu phat hien co phim nhan vao 
			{
				char key = _getch();

				if (key == 'A' || key == 'a') {
					person.tt = LEFT;
				}
				else if (key == 'D' || key == 'd') {
					person.tt = RIGHT;
				}
				else if (key == 'W' || key == 'w') {
					person.tt = UP;
				}
				else if (key == 'S' || key == 's') {
					person.tt = DOWN;
				}
			}
		}
	}
};




	//Ham ve tuong 
	void vetuongtren() {
		int i;
		for (i = 0; i < 100; i++) {
			gotoXY(i, 0);
			Sleep(5);
			SetColor(4);
			cout << "o";
		}
	}


	void vetuongphai() {
		int i;
		for (i = 0; i < 25; i++) {
			gotoXY(100, i);
			Sleep(5);
			SetColor(4);
			cout << "o";
		}
	}


	void vetuongduoi() {
		int i;
		for (i = 100; i >= 0; i--) {
			gotoXY(i, 25);
			Sleep(5);
			SetColor(4);
			cout << "o";
		}
	}


	void vetuongtrai() {
		int i;
		for (i = 25; i >= 0; i--) {
			gotoXY(0, i);
			Sleep(5);
			SetColor(4);
			cout << "o";
		}
	}


	void Vetuong() {
		vetuongtren();
		vetuongphai();
		vetuongduoi();
		vetuongtrai();
	}


	int main() {
		Nocursortype();
		cout << "=====================================================" << endl;
		cout << "|                                                   |" << endl;
		cout << "|                                                   |" << endl;
		cout << "|                                                   |" << endl;
		cout << "|                                                   |" << endl;
		cout << "|                                                   |" << endl;
		cout << "|                                                   |" << endl;
		cout << "|                                                   |" << endl;
		cout << "|                                                   |" << endl;
		cout << "|                                                   |" << endl;
		cout << "=====================================================" << endl;
		Sleep(2000);
		gotoXY(20, 1);
		Nocursortype();
		cout << "HELLO PLAYER";
		Sleep(1000);
		gotoXY(16, 2);
		Nocursortype();
		cout << "HAPPY NEW YEAR 2021";
		Sleep(1000);
		gotoXY(13, 3);
		Nocursortype();
		cout << "WELL COME TO CORONAME_GAME";
		Sleep(1000);
		int l = 1;
		while (l < 5) {
			Nocursortype();
			gotoXY(20, 8);
			cout << "            ";
			Sleep(500);
			gotoXY(20, 8);
			cout << "GOOD LUCK !!";
			Sleep(500);
			SetColor(l);
			l++;
		}
		SetColor(15);
		system("cls");
		while (true) {
			Nocursortype();
			cout << "===================CORONAVIRUT_GAME =================" << endl;
			cout << "|                  		                    |" << endl;
			cout << "|                                                   |" << endl;
			cout << "|                                                   |" << endl;
			cout << "|                                                   |" << endl;
			cout << "|                                                   |" << endl;
			cout << "=====================================================" << endl;;
			Sleep(500);
			Nocursortype();
			gotoXY(1, 1);
			cout << "1. BAT DAU " << endl;
			Sleep(1000);
			gotoXY(1, 3);
			cout << "2. HUONG DAN " << endl;
			Sleep(1000);
			gotoXY(1, 5);
			cout << "3. EXIT " << endl;
			Sleep(1000);
			char lua_chon;
			int k = 1;
			char Huongdan[] = "Game gom 1 nguoi, co the di chuyen (len, xuong, phai, trai) tren duong di gap cac chuong ngai vat la virus hoac cac chat dinh duong hoac rua tay thi se tang muc diem ve suc khoe. Neu gan virus se bi tru diem ve suc khoe, va khi muc diem ve suc khoe = 0 thi ban da bi nhiem benh virus corona. Neu dat duoc 200 diem thi ban se hoan thanh nhiem vu va thanh cong thoat khoi vung dich. Neu cham bien lap tuc ban se that bai.";
			gotoXY(0, 7);
			cout << "Enter Option : ";
			cin >> lua_chon;
			switch (lua_chon) {
			case '1': {
				system("cls");
				Vetuong();
				SetColor(15);
				Corona_Game C1;
				Person person;
				C1.Creat_Virus_Heal(C1);
				C1.DieuKhien_DiChuyen(person, C1);
				_getch();
				system("cls");
				break;
			}

			case '2': {
				Nocursortype();
				system("cls");
				SetColor(15);
				cout << "================================ HUONG DAN ================================" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "|                                                                         |" << endl;
				cout << "===========================================================================" << endl;
				int i;
				gotoXY(1, 1);
				for (i = 0; i < strlen(Huongdan); i++) {
					cout << Huongdan[i];
					Sleep(50);
					if ((i + 1) % 65 == 0) {
						while (Huongdan[i + 1] != ' ') {
							cout << Huongdan[i + 1];
							Sleep(50);
							i++;
						}
						cout << "\n|";
					}
				}
				cout << endl;
				char a[] = "'A' de di chuyen sang trai ";
				char s[] = "'S' de di chuyen xuong duoi ";
				char d[] = "'D' de di chuyen sang phai ";
				char w[] = "'W' de di chuyen len tren ";
				cout << "|";
				for (int i = 0; i < strlen(a); i++) {
					cout << a[i];
					Sleep(50);
				}
				cout << endl;
				cout << "|";
				for (int i = 0; i < strlen(s); i++) {
					cout << s[i];
					Sleep(50);
				}
				cout << endl;
				cout << "|";
				for (int i = 0; i < strlen(d); i++) {
					cout << d[i];
					Sleep(50);
				}
				cout << endl;
				cout << "|";
				for (int i = 0; i < strlen(w); i++) {
					cout << w[i];
					Sleep(50);
				}
				cout << endl;
				char Virus[] = "'*' la VIRUS ";
				char Heal[] = "'+' la HEAL ";
				char Y[] = "'Y' la rua tay ";
				char B[] = "'oooooooo' la BIEN ";
				cout << "|";
				for (int i = 0; i < strlen(Virus); i++) {
					if (i == 1) {
						SetColor(4);
					}
					cout << Virus[i];
					SetColor(15);
					Sleep(50);
				}
				cout << "\n|";
				for (int i = 0; i < strlen(Heal); i++) {
					if (i == 1) {
						SetColor(2);
					}
					cout << Heal[i];
					SetColor(15);
					Sleep(50);
				}
				cout << "\n|";
				for (int i = 0; i < strlen(Y); i++) {
					if (i == 1) {
						SetColor(14);
					}
					cout << Y[i];
					SetColor(15);
					Sleep(50);
				}
				char Person[] = "'0' la nguoi dang trong vung dich.";
				cout << endl;
				cout << "|";
				for (int i = 0; i < strlen(Person); i++) {
					cout << Person[i];
					Sleep(50);
				}
				cout << "\n|";
				for (int i = 0; i < strlen(B); i++) {
					if ((i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 6) || (i == 7) || (i == 8)) {
						SetColor(4);
					}
					cout << B[i];
					SetColor(15);
					Sleep(50);
				}
				cout << endl;
				cout << endl;
				int j = 1;
				while (!_kbhit()) {
					if (j > 15) {
						j = 1;
					}
					gotoXY(1, 17);
					cout << "                                    ";
					Sleep(1000);
					gotoXY(1, 17);
					SetColor(j);
					cout << "NHAN PHIM BAT KI DE QUAY LAI SANH ! ";
					Sleep(1000);
					j++;
				}
				system("cls");
				SetColor(15);
				break;
			}
			case '3': {
				break;
			}
			default: {
				cout << "Ban da nhap sai lua chon ! " << endl;
				Sleep(1000);
				cout << "Moi thu lai sau vai giay " << endl;
				Sleep(2000);
				system("cls");
				break;
				}
			}
		}
			cout << "NHAN PHIM BAT KI DE KET THUC !! ";
			_getch();
			return 0;
		}






























































