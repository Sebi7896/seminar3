#include<iostream>
using namespace std;


class Employee {
public:
	int muie;
	enum StareCivila {
		Singur,
		Casatorit,
		Divortat,
		Vaduv
	};
private:
	char* nume;//al dinamica
	int varsta;
	bool starePermis;//bool
	int cnp[13];//vector numeric
	StareCivila stareCivila;//enum

	void afisareStareCivila(StareCivila stareCivila) {
		switch (stareCivila)
		{
		case Employee::Singur:cout << "Singur";
			break;
		case Employee::Casatorit:cout << "Casatorit";
			break;
		case Employee::Divortat:cout << "Divortat";
			break;
		case Employee::Vaduv:cout << "Vaduv";
			break;
		default:
			break;
		}
	}
	

public:
	
	Employee() {
		
		nume = nullptr;
		varsta = 0;
		starePermis = false;
		for (int i = 0; i < sizeof(cnp)/sizeof(int); i++) {
			cnp[i] = 0;
		}
		stareCivila = StareCivila::Singur;		
	}

	~Employee() {
		delete[] nume;
		//nume = nullptr;
	
	}
	
	//Setters
	void setNume(const char* nume) {

		if (strlen(nume) > 30 || strlen(nume) < 4 || nume == nullptr) {
			cout << "Nume invalid!\n";
			return;
		}
		char CaractereInvalide[] = "!@#$%^&*()";
		for (int i = 0; i < strlen(nume); i++) {
			if (strchr(CaractereInvalide, nume[i]) != 0) {
				cout << "Numele contine caractere invalide!\n";
				return;	
			}
		}

		if (this->nume == nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			delete[] this->nume;
			this->nume = nullptr;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}

				
	}
	void setVarsta(const int varsta) {
		if (varsta >= 14 && varsta <= 100) {
			this->varsta = varsta;
		}
			
		else
			cout << "Varsta neelibigila\n";
	}

	void setStarePermis(const bool starePermis) {
		if (varsta < 18)
			this->starePermis = false;
		else
			this->starePermis = starePermis;
	}

	void setCnp(const int cnp[13]) {
		//restrictii cnp
		int s = cnp[0];
		int an = 0;
		int luna = cnp[3] * 10 + cnp[4];
		int zi = cnp[5] * 10 + cnp[6];
		int judet = cnp[7] * 10 + cnp[8];
		//sex
		if (s < 1 || s > 6 || s == 3 || s == 4) {
			cout << "Invalid\n";
			return;
		}
		//an
		switch (s) {
			case 1: case 2: an = 1900; 
				break;
			case 5: case 6: an = 2000;
				break;
		}
		an = an + cnp[1] * 10 + cnp[2];
		if (an > 2009 || an <= 1950) {
			cout << "An invalid\n";
			return;
		}
		//luna
		if (luna < 1 || luna > 12) {
			cout << "Luna invalida\n";
			return;
		}
		//zi
		if (zi < 1 || zi > 31) {
			cout << "Zi invalida\n";
			return;
		}
		if (luna == 2 && zi > 28) {
			cout << "februrie are decat 28 de zile";
			return;
		}

		//judet
		if (judet < 1 || judet > 48) {
			cout << "Judet Invalid\n";
			return;
		}

		for (int i = 0; i < 13; i++) {
			this->cnp[i] = cnp[i];
		}

	}
	void setStareCivila(const StareCivila stareCivila) {
		if (stareCivila == StareCivila::Divortat && this->stareCivila == StareCivila::Singur) {
			cout << "Nu poti sa fii divortat daca nu ai fost casatorit!\n";
			return;
		}
		if (stareCivila == StareCivila::Vaduv && this->stareCivila == StareCivila::Singur) {
			cout << "Nu poti sa fii vaduv daca nu ai fost casatorit!\n";
			return;
		}
		if (stareCivila == this->stareCivila) {
			cout << "Nu se poate sa fii aceeasi stare!\n";
			return;
		}

		this->stareCivila = stareCivila;
	}
	


	//getters
	const char* getNume()  {
		return nume;//sau nume
	}

	const int getVarsta() {
		return varsta;
	}

	const bool getStarePermis() {
		
		return starePermis;
	}

	const int* getCnp() {
		return cnp;
	}
	const StareCivila getStareCivila() {
		return stareCivila;
	}

	

	//Afisare
	void afisare() {
		cout << "\n^^^^^^^^^^^^^^^^^^";
		if(nume != nullptr)
			cout << "\nNume: " << nume;
		else
			cout << "\nNume: Necunoscut";
		cout << "\nVarsta: " << varsta;
		cout << "\nPermis de conducere: ";
		if (starePermis)
			cout << "Da";
		else
			cout << "Nu";
		cout << "\nCNP: ";
		bool ok = false;
		for (int i = 0; i < sizeof(cnp) / sizeof(int) && !ok; i++) {
			if (cnp[i] != 0)
				ok = true;
		}
		if (ok == true) {
			for (int i = 0; i < sizeof(cnp) / sizeof(int) && ok; i++) {
				cout << cnp[i];
			}
		}
		else {
			cout << "INVALID!";
		}
		cout << "\nStare civila: ";
		Employee::afisareStareCivila(stareCivila);
			
		cout << "\n" << "^^^^^^^^^^^^^^^^^^^^^^^^^^";

	}

	


};

int main() {

	
	Employee e1{};
	e1.setNume("Sebastian");
	e1.setVarsta(20);
	int CNP[] = { 5, 0, 3, 0, 1, 1, 4, 4, 1, 5, 6, 7, 8 };
	e1.setCnp(CNP);
	e1.setStarePermis(true);
	e1.setStareCivila(Employee::StareCivila::Casatorit);
	e1.afisare();
	

	return 0;
}