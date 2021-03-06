GROSU MARILENA, GRUPA 1060, SERIA A, ANUL III

#include<iostream>
#include<string>
using namespace std;

class CoffeeShop
{
private:
	static int NrCafenele; //Numarul de cafenele din oras
	const int CodCafenea; //Codul fiecarei cafenele
	char* NumeCafenea; //Numele fiecarei cafenele
	int NrTipCafea; // Cate tipuri de cafea se regasesc intr-o cafenea
	float* PreturiTipCafea; // Preturile fiecarui tip de cafele regasite intr-o cafenea, in lei
	bool* ContineLapte; // Cafeaua are/ nu are in compozitia ei lapte
	float ProfitCafenea[12]; //Profitul fiecarei cafenele, din fiecare luna, pentru un an de zile, in lei
	bool DeschisaInWeekend; //Disponibilitatea cafenelei in timpul Weekend-ului.	
	int NrAngajatiCafenea; //Numarul de angajati din fiecare cafenea.

public:
	//Destructor
	~CoffeeShop()
	{
		if (this->NumeCafenea != NULL)
			delete[] this->NumeCafenea;
		if (this->PreturiTipCafea != NULL)
			delete[] this->PreturiTipCafea;
		if (this->ContineLapte != NULL)
			delete[] this->ContineLapte;
	}

	//Constructorul implicit
	CoffeeShop() :CodCafenea(1)
	{
		//this->NumeCafenea = NULL;
		this->NumeCafenea = new char[strlen("Necunoscut") + 1];
		strcpy(this->NumeCafenea, "Necunoscut");
		this->NrTipCafea = 0;
		this->PreturiTipCafea = NULL;
		this->ContineLapte = NULL;
		for (int i = 0; i<12; i++)
			this->ProfitCafenea[i] = 0;
		this->DeschisaInWeekend = false;
		this->NrAngajatiCafenea = 0;
		NrCafenele++;
	}

	//Constructori expliciti
	CoffeeShop(int Cod, char* NumeCafenea) :CodCafenea(Cod)
	{
		this->NumeCafenea = new char[strlen(NumeCafenea) + 1];
		strcpy(this->NumeCafenea, NumeCafenea);
		this->NrTipCafea = 0;
		this->PreturiTipCafea = NULL;
		this->ContineLapte = NULL;
		for (int i = 0; i<12; i++)
			this->ProfitCafenea[i] = 0;
		this->DeschisaInWeekend = false;
		this->NrAngajatiCafenea = 0;
		NrCafenele++;
	}

	CoffeeShop(int cod, char* NumeCafenea, int NrAngajatiCafenea, float* ProfitCafenea, bool DeschisaInWeekend) :CodCafenea(cod)
	{
		this->NumeCafenea = new char[strlen(NumeCafenea) + 1];
		strcpy(this->NumeCafenea, NumeCafenea);
		this->NrTipCafea = 0;
		this->PreturiTipCafea = NULL;
		this->ContineLapte = NULL;
		for (int i = 0; i<12; i++)
			this->ProfitCafenea[i] = ProfitCafenea[i];
		this->DeschisaInWeekend = DeschisaInWeekend;
		this->NrAngajatiCafenea = NrAngajatiCafenea;
		NrCafenele++;
	}

	CoffeeShop(int cod, char* NumeCafenea, int NrAngajatiCafenea, int NrTipCafea, float* PreturiTipCafea, bool* ContineLapte, float* ProfitCafenea, bool DeschisaInWeekend) :CodCafenea(3)
	{
		this->NumeCafenea = new char[strlen(NumeCafenea) + 1];
		strcpy(this->NumeCafenea, NumeCafenea);
		this->NrTipCafea = NrTipCafea;
		this->PreturiTipCafea = new float[NrTipCafea];
		for (int i = 0; i<NrTipCafea; i++)
			this->PreturiTipCafea[i] = PreturiTipCafea[i];
		this->ContineLapte = new bool[NrTipCafea];
		for (int i = 0; i<NrTipCafea; i++)
			this->ContineLapte[i] = ContineLapte[i];
		for (int i = 0; i<12; i++)
			this->ProfitCafenea[i] = ProfitCafenea[i];
		this->DeschisaInWeekend = DeschisaInWeekend;
		this->NrAngajatiCafenea = NrAngajatiCafenea;
		NrCafenele++;
	}

	//Constructorul de copiere
	CoffeeShop(const CoffeeShop& c) :CodCafenea(c.CodCafenea)
	{
		this->NumeCafenea = new char[strlen(c.NumeCafenea) + 1];
		strcpy(this->NumeCafenea, c.NumeCafenea);
		this->NrTipCafea = c.NrTipCafea;
		this->PreturiTipCafea = new float[c.NrTipCafea];
		for (int i = 0; i<c.NrTipCafea; i++)
			this->PreturiTipCafea[i] = c.PreturiTipCafea[i];
		this->ContineLapte = new bool[c.NrTipCafea];
		for (int i = 0; i<c.NrTipCafea; i++)
			this->ContineLapte[i] = c.ContineLapte[i];
		for (int i = 0; i<12; i++)
			this->ProfitCafenea[i] = c.ProfitCafenea[i];
		this->DeschisaInWeekend = c.DeschisaInWeekend;
		this->NrAngajatiCafenea = c.NrAngajatiCafenea;
		NrCafenele++;
	}

	//Supraincarcarea operatorului =
	CoffeeShop operator=(const CoffeeShop& c)
	{
		if (this->NumeCafenea != NULL)
			delete[] this->NumeCafenea;
		if (this->PreturiTipCafea != NULL)
			delete[] this->PreturiTipCafea;
		if (this->ContineLapte != NULL)
			delete[] this->ContineLapte;
		this->NumeCafenea = new char[strlen(c.NumeCafenea) + 1];
		strcpy(this->NumeCafenea, c.NumeCafenea);
		this->NrTipCafea = c.NrTipCafea;
		this->PreturiTipCafea = new float[c.NrTipCafea];
		for (int i = 0; i<c.NrTipCafea; i++)
			this->PreturiTipCafea[i] = c.PreturiTipCafea[i];
		this->ContineLapte = new bool[c.NrTipCafea];
		for (int i = 0; i<c.NrTipCafea; i++)
			this->ContineLapte[i] = c.ContineLapte[i];
		for (int i = 0; i<12; i++)
			this->ProfitCafenea[i] = c.ProfitCafenea[i];
		this->DeschisaInWeekend = c.DeschisaInWeekend;
		this->NrAngajatiCafenea = c.NrAngajatiCafenea;
		return *this;
	}


	//Get-eri & Set-eri
	int getCodCafenea()
	{
		return this->CodCafenea;
	}

	char* getNumeCafenea()
	{
		if (this->NumeCafenea != NULL)
			return this->NumeCafenea;
	}

	int getNrTipCafea()
	{
		return this->NrTipCafea;
	}

	float* getPreturiTipCafea()
	{
		return this->PreturiTipCafea;
	}

	bool* getContineLapte()
	{
		return this->ContineLapte;
	}

	float* getProfitCafenea()
	{
		return this->ProfitCafenea;
	}

	bool getDeschisaInWeekend()
	{
		return this->DeschisaInWeekend;
	}

	int getNrCafenele()
	{
		return this->NrCafenele;
	}

	int getNrAngajatiCafenea()
	{
		return this->NrAngajatiCafenea;
	}

	void setNumeCafenea(char* NumeCafenea)
	{
		if (NumeCafenea != NULL)
		{
			if (this->NumeCafenea != NULL)
				delete[] this->NumeCafenea;
			this->NumeCafenea = new char[strlen(NumeCafenea) + 1];
			strcpy(this->NumeCafenea, NumeCafenea);
		}
	}


	void setNrTipCafea(int NrTipCafea)
	{
		this->NrTipCafea = NrTipCafea;
	}

	void setPreturiTipCafea(int NrTipCafea, float* PreturiTipCafea)
	{
		this->NrTipCafea = NrTipCafea;
		if (this->PreturiTipCafea != NULL)
			delete[] this->PreturiTipCafea;
		this->PreturiTipCafea = new float[NrTipCafea];
		for (int i = 0; i<NrTipCafea; i++)
			this->PreturiTipCafea[i] = PreturiTipCafea[i];
	}

	void setContineLapte(int NrTipCafea, bool* ContineLapte)
	{
		if (this->ContineLapte != NULL)
			delete[] this->ContineLapte;
		this->ContineLapte = new bool[NrTipCafea];
		for (int i = 0; i<NrTipCafea; i++)
			this->ContineLapte[i] = ContineLapte[i];
	}

	void setProfitCafenea(float* ProfitCafenea)
	{
		for (int i = 0; i<12; i++)
			this->ProfitCafenea[i] = ProfitCafenea[i];
	}

	void setDeschisaInWeekend(bool DeschisaInWeekend)
	{
		this->DeschisaInWeekend = DeschisaInWeekend;
	}

	void setNrAngajatiCafenea(int NrAngajatiCafenea)
	{
		this->NrAngajatiCafenea = NrAngajatiCafenea;
	}

	void setNrCafenele(int NrCafenele)
	{
		this->NrCafenele = NrCafenele;
	}

	//Metode
	float PretulMediu()
	{
		float PretTotal = 0;
		for (int i = 0; i<this->NrTipCafea; i++)
			PretTotal += this->PreturiTipCafea[i];
		return PretTotal / this->NrTipCafea;
	}

	float ProfitAn()
	{
		float ProfitTotal = 0;
		for (int i = 0; i<12; i++)
			ProfitTotal += this->ProfitCafenea[i];
		return ProfitTotal;
	}

	//Supraincarcarea operatorilor
	friend ostream& operator<<(ostream& out, CoffeeShop& c)
	{
		out << "\Cafeneaua " << c.NumeCafenea << " are " << c.NrTipCafea << " tipuri de cafea care au preturile: " << endl;
		for (int i = 0; i < c.NrTipCafea; i++)
			out << c.PreturiTipCafea[i] << " ";
		for (int i = 0; i < c.NrTipCafea; i++)
			if (c.ContineLapte[i] == 1)
				out << "\nCafeaua " << i + 1 << " contine lapte";
			else
				out << "\nCafeaua " << i + 1 << " nu contine lapte";
		out << "\nS-au obtinut lunar, timp de un an de zile, urmatoarele cifre de profit: " << endl;
		for (int i = 0; i < 12; i++)
			out << c.ProfitCafenea[i] << " ";
		out << "\nCafeneaua dispune de un numar de " << c.NrAngajatiCafenea << " angajati.";
		if (c.DeschisaInWeekend == 1)
			out << "\nAceasta cafenea este deschisa si in weekend! Va asteptam!";
		else
			out << "\nAceasta cafenea nu este deschisa si in weekend! Ne pare rau!";
		return out;
	}

	friend istream& operator >> (istream& in, CoffeeShop& c)
	{
		cout << endl;
		if (c.NumeCafenea != NULL)
			delete[] c.NumeCafenea;
		char buffer[100];
		c.NumeCafenea = new char[strlen(buffer) + 1];
		cout << "\nNumele cafenelei: ";
		in.getline(buffer, 100);
		cout << "\nNumar tipuri de cafea: ";
		in >> c.NrTipCafea;
		if (c.PreturiTipCafea != NULL)
			delete[] c.PreturiTipCafea;
		c.PreturiTipCafea = new float[c.NrTipCafea];
		cout << "\nPretul fiecarui tip de cafea: " << endl;
		for (int i = 0; i < c.NrTipCafea; i++)
			in >> c.PreturiTipCafea[i];
		if (c.ContineLapte != NULL)
			delete[] c.ContineLapte;
		c.ContineLapte = new bool[c.NrTipCafea];
		cout << "\nFiecare tip de cafea enumerat mai sus contine sau nu lapte? (1-contine, 0-nu contine)"<<endl;
		for (int i = 0; i < c.NrTipCafea; i++)
			in >> c.ContineLapte[i];
		cout << "\nCifrele de profit obtinute lunar, pentru anul 2017, sunt: " << endl;
		for (int i = 0; i < 12; i++)
			in >> c.ProfitCafenea[i];
		cout << "\nNumarul de angajati al cafenelei este: ";
		in >> c.NrAngajatiCafenea;
		cout << "\nCafeneaua este deschisa sau nu in timpul Weekend-ului? (1-Da, 0-Nu)" << endl;
		in >> c.DeschisaInWeekend;
		return in;
	}

	CoffeeShop operator+(float x)
	{
		CoffeeShop copie = *this;
		for (int i = 0; i < copie.NrTipCafea; i++)
			copie.PreturiTipCafea[i] += x;
		return copie;
	}

	CoffeeShop operator+=(float x)
	{
		CoffeeShop copie = *this;
		for (int i = 0; i < copie.NrTipCafea; i++)
			copie.ProfitCafenea[i] += x;
		return copie;
	}

	bool operator<=(CoffeeShop c)
	{
		if (this->ProfitAn() <= c.ProfitAn())
			return true;
		else
			return false;
	}

	bool operator!()
	{
		if (this->NrTipCafea >= 5)
			return true;
		else
			return false;
	}

	float operator[](int index)
	{
		if(index>=0 && index<this->NrTipCafea)
			return this->PreturiTipCafea[index - 1];
		else 
			throw exception("Index Invalid!");
	}

	CoffeeShop& operator++()
	{
		this->NrAngajatiCafenea++;
		return *this;
	}

	CoffeeShop operator++(int)
	{
		CoffeeShop copie = *this;
		this->NrAngajatiCafenea++;
		return copie;
	}

	CoffeeShop operator()(int reducere)
	{
		CoffeeShop copie = *this;
		//Reducere 10% din fiecare cafea cu ocazia venirii sarbatorilor
		for (int i = 0; i < copie.NrTipCafea; i++)
			copie.PreturiTipCafea[i] = copie.PreturiTipCafea[i] - (reducere*copie.PreturiTipCafea[i]) / 100;
		return copie;
	}

	explicit operator float()
	{
		return this->ProfitAn() / 12;
	}

	CoffeeShop operator*(int multiplicare)
	{
		CoffeeShop copie = *this;
		copie.NrAngajatiCafenea *= multiplicare;
		return copie;
	}
};

int CoffeeShop::NrCafenele = 0;

void main()
{
	cout << "GROSU MARILENA, GRUPA 1060, SERIA A, ANUL III, RESTANTA POO" << endl << "TEMA 1" << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	CoffeeShop c;
	cout << "Numele cafenelei " << c.getCodCafenea() << " este " << c.getNumeCafenea();
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;
	cout << endl;

	CoffeeShop c1(7, "Aroma");
	cout << "\nCafeneaua care are codul " << c1.getCodCafenea() << " se numeste " << c1.getNumeCafenea() << ".";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;
	cout << endl;

	CoffeeShop c2(10, "Hazelnut", 7, new float[12]{ 1300, 2500, 1370.5, 2378, 1190, 2778, 4325, 2200.5, 3345, 1290.5, 5001, 1945 }, true);
	cout << "\nCafeneaua " << c2.getNumeCafenea() << " a obtinut lunar, timp de un an de zile, urmatoarele cifre de profit: " << endl;
	for (int i = 0; i < 12; i++)
		cout << c2.getProfitCafenea()[i] << " ";
	cout << endl;
	cout << "Aceasta dispune de un numar de " << c2.getNrAngajatiCafenea() << " angajati.";
	if (c2.getDeschisaInWeekend() == 1)
		cout << "\nAceasta cafenea este deschisa si in weekend! Va asteptam!";
	else
		cout << "\nAceasta cafenea nu este deschisa si in weekend! Ne pare rau!";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;
	cout << endl;

	CoffeeShop c3(3, "Starbucks", 11, 12, new float[12]{ 12.5, 10, 9.5, 11.5, 12, 13, 12.5, 11.5, 10.5, 9, 9, 14 }, new bool[12]{ 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0 }, new float[12]{ 1200, 2300, 1270.5, 1370, 2190, 2778, 4325.5, 2222, 3345, 1600, 4996, 1407.5 }, false);
	cout << "\Cafeneaua " << c3.getNumeCafenea() << " are " << c3.getNrTipCafea() << " tipuri de cafea care au preturile: " << endl;
	for (int i = 0; i < 12; i++)
		cout << c3.getPreturiTipCafea()[i] << " ";
	cout << endl << "\nPretul mediu al unei cafele este in valoare de: " << c3.PretulMediu() << "." << endl;
	for (int i = 0; i < 12; i++)
		if (c3.getContineLapte()[i] == 1)
			cout << "\nCafeaua " << i + 1 << " contine lapte";
		else
			cout << "\nCafeaua " << i + 1 << " nu contine lapte";
	cout << "\nS-au obtinut lunar, timp de un an de zile, urmatoarele cifre de profit: " << endl;
	for (int i = 0; i < 12; i++)
		cout << c3.getProfitCafenea()[i] << " ";
	cout << endl;
	cout << "Aceasta dispune de un numar de " << c3.getNrAngajatiCafenea() << " angajati.";
	if (c3.getDeschisaInWeekend() == 1)
		cout << "\nAceasta cafenea este deschisa si in weekend! Va asteptam!";
	else
		cout << "\nAceasta cafenea nu este deschisa si in weekend! Ne pare rau!";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;
	cout << endl;

	CoffeeShop c4 = c2;
	cout << "\nCafeneaua " << c4.getNumeCafenea();
	if (c4.getDeschisaInWeekend() == 1)
		cout << " este deschisa in weekend.";
	else
		cout << " nu este deschisa in weekend.";

	cout << "\nIn oras sunt in total " << c4.getNrCafenele() << " cafenele, in momentul actual. " << endl;

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;
	cout << endl;

	CoffeeShop c5;
	float Preturi[] = { 5,5,10,5,7 };
	bool Lapte[] = { 1,0,0,1,1 };
	int NumarCafele = 5;
	c5.setNumeCafenea("Five To Go"); c5.setNrTipCafea(5); c5.setPreturiTipCafea(NumarCafele, Preturi);  c5.setContineLapte(NumarCafele, Lapte);
	cout << "\Cafeneaua " << c5.getNumeCafenea() << " are " << c5.getNrTipCafea() << " tipuri de cafea care au preturile: " << endl;
	for (int i = 0; i < NumarCafele; i++)
		cout << c5.getPreturiTipCafea()[i] << " ";
	for (int i = 0; i < NumarCafele; i++)
		if (c5.getContineLapte()[i] == 1)
			cout << "\nCafeaua " << i + 1 << " contine lapte";
		else
			cout << "\nCafeaua " << i + 1 << " nu contine lapte";
	float Profit[12] = { 278, 290, 778, 435, 500.5, 345, 994.5, 300, 500, 700.5, 378, 890 };
	c5.setProfitCafenea(Profit); c5.setDeschisaInWeekend(0);
	cout << "\nS-au obtinut lunar, timp de un an de zile, urmatoarele cifre de profit: " << endl;
	for (int i = 0; i < 12; i++)
		cout << c5.getProfitCafenea()[i] << " ";
	if (c5.getDeschisaInWeekend() == 1)
		cout << "\nAceasta cafenea este deschisa si in weekend! Va asteptam!";
	else
		cout << "\nAceasta cafenea nu este deschisa si in weekend! Ne pare rau!";
	c5.setNrAngajatiCafenea(12);
	cout << endl;
	cout << "De asemenea, dispune de un numar de " << c2.getNrAngajatiCafenea() << " angajati.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;
	cout << endl;


	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OPERATORI~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;
	cout << "---------------------PRETURILE CRESC CU 1.5 LEI---------------------" << endl;
	CoffeeShop c6 = c3 + 1.5; //Adauga la toata lista de preturi valoarea 1.5 => Preturile se maresc cu 1.5;
	cout << c6;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------PROFITUL LUNAR CRESTE CU 250 LEI---------------------" << endl;
	CoffeeShop c7 = c6 += 250;
	cout << c7;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------CARE PROFIT ANUAL ESTE MAI MARE?---------------------" << endl;
	if (c7 <= c4)
		cout << "\nProfitul anual al cafenelei " << c7.getNumeCafenea() << " este mai mic sau cel putin egal cu cel al cafenelei " << c4.getNumeCafenea() << "!";
	else
		cout << "\nProfitul anual al cafenelei " << c7.getNumeCafenea() << " este mai mare decat cel al cafenelei " << c4.getNumeCafenea() << "!";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------CAFENEAUA ARE UN NUMAR MINIM DE TIPURI DE CAFEA PUSE LA VANZARE?---------------------" << endl;
	if (!c7)
		cout << "\nCafeneaua " << c7.getNumeCafenea() << " are un numar minim de tipuri de cafea puse la vanzare!";
	else
		cout << "\nCafeneaua " << c7.getNumeCafenea() << " nu are un numar minim de tipuri de cafea puse la vanzare!";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------PRETUL CAFELEI---------------------" << endl;
	try
	{
		float Pret = c7[3];
		cout << "Pretul celui de-al 3-lea tip de cafea, din cafeneaua " << c7.getNumeCafenea() << ", este in valoare de: " << Pret << " lei.";
	}
	catch (exception ex)
	{
		cout << "\n" << ex.what();
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------CRESTEREA NUMARULUI DE ANGAJATI---------------------" << endl;
	CoffeeShop c8 = ++c7;
	cout << c8;
	cout << endl << endl;
	CoffeeShop c9 = c7++;
	cout << c9;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------REDUCERI DE 10% CU OCAZIA SARBATORILOR---------------------" << endl;
	cout << c9(10); //10 se refera la 10%, procentul considerat reducere
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------PROFITUL MEDIU PE AN---------------------" << endl;
	float ProfitulMediuAn = (float)c8;
	cout << "\nProfitul mediu pe anul 2017, al cafenelei " << c8.getNumeCafenea() << ", este in valoare de:  " << ProfitulMediuAn << ".";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------DUBLAREA PERSONALULUI CAFENELEI---------------------" << endl;
	CoffeeShop c10;
	c10 = c7 * 2;
	cout << c10;

	CoffeeShop c11;
	cin >> c11;

}