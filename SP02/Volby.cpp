#include "Volby.h"
#include <fstream>
#include <iostream>
#include "structures/table/unsorted_sequence_table.h"
#include <experimental/filesystem>




Volby::Volby()
{
	this->obce_ = new structures::SortedSequenceTable<string, Obec*>();
	this->kraje_ = new structures::SortedSequenceTable<string, Kraj*>();
	this->okresy_ = new structures::SortedSequenceTable<string, Okres*>();
	

	this->filterNachadzaSa = new Filter_fi<bool, Obec>();
	this->filterUcast = new FilterFI<double, Oblast>();
	this->filterNazov = new Filter_fi<string, Oblast>();
	this->filterVolici = new FilterFI<int, Oblast>();

	this->kNazov = new KriteriumNazov<string, Oblast>();
	this->kVolici = new KriteriumVolici<int, Oblast>();
	this->kUcast = new KriteriumUcast<double, Oblast>();
	this->kNachadzaSa = new KriteriumNachadzaSa<bool, Obec>();
	//this->kNachadzaSa = new KriteriumNachadzaSa<bool, Oblast>();
	nacitajSubory();
	vypisMenu();
	
}
void Volby::nacitajSubory()
{

	ifstream is("dediny_vstup.csv");

	if (!is.is_open())
	{
		std::cout << "Error: File Open" << "\n";
	}
	string nazov;
	string pocetZapVolicov1;
	string pocetVydObalok1;
	string ucast1;
	string pocetOdovzObalok1;
	string pocetPlatHlasov1;

	string pocetZapVolicov2;
	string pocetVydObalok2;
	string ucast2;
	string pocetOdovzObalok2;
	string pocetPlatHlasov2;
	string nazovOkresu;
	string nazovKraju;

	while (is.good())
	{
		getline(is, nazov, ';');
		getline(is, pocetZapVolicov1, ';');
		getline(is, pocetVydObalok1, ';');
		getline(is, ucast1, ';');
		getline(is, pocetOdovzObalok1, ';');
		getline(is, pocetPlatHlasov1, ';');

		getline(is, pocetZapVolicov2, ';');
		getline(is, pocetVydObalok2, ';');
		getline(is, ucast2, ';');
		getline(is, pocetOdovzObalok2, ';');
		getline(is, pocetPlatHlasov2, ';');
		getline(is, nazovOkresu, ';');
		getline(is, nazovKraju, '\n');

		Obec* pomDedina = new Obec(nazov);
		pomDedina->set_pocet_zap_volicov1(stoi(pocetZapVolicov1));
		pomDedina->set_pocet_vyd_obalok1(stoi(pocetVydObalok1));
		pomDedina->set_ucast_volicov_percenta1(stod(ucast1));
		pomDedina->set_pocet_odovzd_obalok1(stoi(pocetOdovzObalok1));
		pomDedina->set_pocet_plat_hlasov1(stoi(pocetPlatHlasov1));

		pomDedina->set_pocet_zap_volicov2(stoi(pocetZapVolicov2));
		pomDedina->set_pocet_vyd_obalok2(stoi(pocetVydObalok2));
		pomDedina->set_ucast_volicov_percenta2(stod(ucast2));
		pomDedina->set_pocet_odovzd_obalok2(stoi(pocetOdovzObalok2));
		pomDedina->set_pocet_plat_hlasov2(stoi(pocetPlatHlasov2));
		pomDedina->set_nazov_okresu(nazovOkresu);
		pomDedina->set_nazov_kraju(nazovKraju);
		obce_->insert(nazov, pomDedina);

		

		

	}
	is.close();
	is.clear();

	is.open("kraje.csv");
	if (!is.is_open())
	{
		std::cout << "Error: File Open" << "\n";
	}
	while (is.good())
	{

		getline(is, nazov, ';');
		getline(is, pocetZapVolicov1, ';');
		getline(is, pocetVydObalok1, ';');
		getline(is, ucast1, ';');
		getline(is, pocetOdovzObalok1, ';');
		getline(is, pocetPlatHlasov1, ';');

		getline(is, pocetZapVolicov2, ';');
		getline(is, pocetVydObalok2, ';');
		getline(is, ucast2, ';');
		getline(is, pocetOdovzObalok2, ';');
		getline(is, pocetPlatHlasov2, '\n');

		Kraj* pomKraj = new Kraj(nazov);
		pomKraj->set_pocet_zap_volicov1(stoi(pocetZapVolicov1));
		pomKraj->set_pocet_vyd_obalok1(stoi(pocetVydObalok1));
		pomKraj->set_ucast_volicov_percenta1(stod(ucast1));
		pomKraj->set_pocet_odovzd_obalok1(stoi(pocetOdovzObalok1));
		pomKraj->set_pocet_plat_hlasov1(stoi(pocetPlatHlasov1));

		pomKraj->set_pocet_zap_volicov2(stoi(pocetZapVolicov2));
		pomKraj->set_pocet_vyd_obalok2(stoi(pocetVydObalok2));
		pomKraj->set_ucast_volicov_percenta2(stod(ucast2));
		pomKraj->set_pocet_odovzd_obalok2(stoi(pocetOdovzObalok2));
		pomKraj->set_pocet_plat_hlasov2(stoi(pocetPlatHlasov2));
		kraje_->insert(nazov, pomKraj);

	}

	is.close();

	is.clear();

	is.open("okresy_vstup.csv");
	if (!is.is_open())
	{
		std::cout << "Error: File Open" << "\n";
	}
	while (is.good())
	{

		getline(is, nazov, ';');
		getline(is, pocetZapVolicov1, ';');
		getline(is, pocetVydObalok1, ';');
		getline(is, ucast1, ';');
		getline(is, pocetOdovzObalok1, ';');
		getline(is, pocetPlatHlasov1, ';');

		getline(is, pocetZapVolicov2, ';');
		getline(is, pocetVydObalok2, ';');
		getline(is, ucast2, ';');
		getline(is, pocetOdovzObalok2, ';');
		getline(is, pocetPlatHlasov2, ';');
		getline(is, nazovKraju, '\n');


		Okres* pomOkres = new Okres(nazov);
		pomOkres->set_pocet_zap_volicov1(stoi(pocetZapVolicov1));
		pomOkres->set_pocet_vyd_obalok1(stoi(pocetVydObalok1));
		pomOkres->set_ucast_volicov_percenta1(stod(ucast1));
		pomOkres->set_pocet_odovzd_obalok1(stoi(pocetOdovzObalok1));
		pomOkres->set_pocet_plat_hlasov1(stoi(pocetPlatHlasov1));

		pomOkres->set_pocet_zap_volicov2(stoi(pocetZapVolicov2));
		pomOkres->set_pocet_vyd_obalok2(stoi(pocetVydObalok2));
		pomOkres->set_ucast_volicov_percenta2(stod(ucast2));
		pomOkres->set_pocet_odovzd_obalok2(stoi(pocetOdovzObalok2));
		pomOkres->set_pocet_plat_hlasov2(stoi(pocetPlatHlasov2));
		pomOkres->set_nazov_kraju(nazovKraju);
		okresy_->insert(nazov, pomOkres);

	}


	is.close();
	std::cout << "data su nacitane \n";

}
void Volby::vypisMenu()
{
	int c;

	bool cyklus = true;
	while (cyklus)
	{
		std::cout << "\n-------------------------------------------------------------\n" << endl;
		std::cout << "		Prezidentske volby 2019";
		std::cout << "\n-------------------------------------------------------------\n" << endl;
		cout << "1.Vypis Uzemny celok \n" << endl;
		cout << "2.Zorad dediny \n" << endl;
		cout << "0.Ukonci program \n" << endl;

		std::cout << "\n-------------------------------------------------------------\n" << endl;



		cin >> c;
		switch (c)
		{
		case 1: vypisPodla(); break;
		case 2: zoradMenu(); break;
		case 0: cyklus = false; break;
		default: std::cout << "zadal si zly znak:"; break;

		}
	}
}
void Volby::vypisPodla()
{

	char rozhodnutie;


	std::cout << "Podla coho chces vzhladat uzemny celok?: \n";
	cout << "a.Nazov \n" << endl;
	cout << "b.Volici \n" << endl;
	cout << "c.Ucast\n" << endl;
	std::cin >> rozhodnutie;
	switch (rozhodnutie)
	{
	case 'a': this->vypisPodlaNazvu(); break;
	case 'b': this->vypisPodlaVolicov(); break;
	case 'c': this->vypisPodlaUcasti(); break;
	default: std::cout << "zadal si zly znak"; break;
	}




}



void Volby::vypisPodlaNazvu()
{
	string vstup = "";


	std::cout << "zadaj Uzemny celok, ktory hladas: \n";
	cin.ignore();
	getline(std::cin, vstup);
	filterNazov->set_alpha(vstup);


	if (obce_->containsKey(vstup))
	{
		

		if (filterNazov->evaluate(*obce_->operator[](vstup), *kNazov)) {
			std::cout << "Obec\n";
			std::cout << "-------------------------------------------------------------\n";
			obce_->operator[](vstup)->vypisInfo();
			cout << obce_->operator[](vstup)->get_nazov_okresu()<< endl;
			cout << obce_->operator[](vstup)->get_nazov_kraju() << endl;

			std::cout << "\n-------------------------------------------------------------\n";

		}

	}


	if (okresy_->containsKey(vstup))
	{
		std::cout << "Okres\n";
		std::cout << "-------------------------------------------------------------\n";

		if (filterNazov->evaluate(*okresy_->operator[](vstup), *kNazov)) {
			okresy_->operator[](vstup)->vypisInfo();
			cout << okresy_->operator[](vstup)->get_nazov_kraju() << endl;
			
			std::cout << "\n-------------------------------------------------------------\n";

		}
	}


	if (kraje_->containsKey(vstup))
	{
		std::cout << "Kraj:\n";
		std::cout << "-------------------------------------------------------------\n";

		if (filterNazov->evaluate(*kraje_->operator[](vstup), *kNazov)) {
			kraje_->operator[](vstup)->vypisInfo();
			std::cout << "\n-------------------------------------------------------------\n";

		}
	}

}

void Volby::vypisPodlaVolicov()
{
	int a;
	int b;
	int kolo;

	std::cout << " Zadaj interval, pre pocet volicov a v ktorom kole: \n";

	std::cout << "zadaj dolna hranica: \n";
	std::cin >> a;
	std::cout << "zadaj horna hranica: \n";
	std::cin >> b;
	std::cout << "zadaj, pre ktore kolo: \n";
	std::cin >> kolo;
	filterVolici->set_alpha(a);
	filterVolici->set_beta(b);
	kVolici->set_kolo(kolo);

	for (auto *item : *obce_)
	{

		if (filterVolici->evaluate(*item->accessData(), *kVolici))
		{
			std::cout << "Obec\n";

			std::cout << "-------------------------------------------------------------\n";

			item->accessData()->vypisInfo();
			cout <<  item->accessData()->get_nazov_okresu() << endl;
			cout << item->accessData()->get_nazov_kraju() << endl;
			std::cout << "-------------------------------------------------------------\n";

			

		}
	}
	for (auto *item : *okresy_)
	{

		if (filterVolici->evaluate(*item->accessData(), *kVolici))
		{
			std::cout << "Okres\n";

			std::cout << "-------------------------------------------------------------\n";

			item->accessData()->vypisInfo();
			cout << item->accessData()->get_nazov_kraju() << endl;

			std::cout << "-------------------------------------------------------------\n";


		}
	}
	for (auto *item : *kraje_)
	{

		if (filterVolici->evaluate(*item->accessData(), *kVolici))
		{
			std::cout << "Kraj\n";

			std::cout << "-------------------------------------------------------------\n";

			item->accessData()->vypisInfo();

			std::cout << "-------------------------------------------------------------\n";

		}
	}
	
}

void Volby::vypisPodlaUcasti()
{
	int a;
	int b;
	int kolo;


	std::cout << " Zadaj interval, pre pocet volicov a v ktorom kole: \n";

	std::cout << "zadaj dolna hranica: \n";
	std::cin >> a;
	std::cout << "zadaj horna hranica: \n";
	std::cin >> b;
	std::cout << "zadaj, pre ktore kolo: \n";
	std::cin >> kolo;
	filterUcast->set_alpha(a);
	filterUcast->set_beta(b);
	kUcast->set_kolo(kolo);

	


	for (auto *item : *obce_)
	{


		if (filterUcast->evaluate(*item->accessData(), *kUcast))
		{
			std::cout << "Obec\n";

			std::cout << "-------------------------------------------------------------\n";

			item->accessData()->vypisInfo();
			cout << item->accessData()->get_nazov_okresu() << endl;
			cout << item->accessData()->get_nazov_kraju() << endl;
			std::cout << "-------------------------------------------------------------\n";

		}
	}

	for (auto *item : *okresy_)
	{

		if (filterUcast->evaluate(*item->accessData(), *kUcast))
		{
			std::cout << "Okres\n";

			std::cout << "-------------------------------------------------------------\n";

			item->accessData()->vypisInfo();
			cout << item->accessData()->get_nazov_kraju() << endl;
			std::cout << "-------------------------------------------------------------\n";


		}
	}

	for (auto *item : *kraje_)
	{

		if (filterUcast->evaluate(*item->accessData(), *kUcast))
		{
			std::cout << "Kraj\n";

			std::cout << "-------------------------------------------------------------\n";

			item->accessData()->vypisInfo();

			std::cout << "-------------------------------------------------------------\n";

		}
	}

}

void Volby::zoradMenu()
{
	int k;
	std::cout << "chces zotriedit?" << endl;
	std::cout << "1. Vsetky obce" << endl;
	std::cout << "2. Iba obce vyhovujuce filtru" << endl;
	cin >> k;
	switch (k)
	{
	case 1: zoradVsetko();break;
	case 2: zoradPodla(); break;
	default: zoradMenu(); break;
	}
}

void Volby::zoradVsetko()
{
	structures::UnsortedSequenceTable<string, Oblast*>* pomObce = new structures::UnsortedSequenceTable<string, Oblast*>();

	int kolo, triedenie;
	char rozhodnutie;
	std::cout << "zadaj, pre ktore kolo: \n";
	std::cin >> kolo;

	filterUcast->set_alpha(0);
	filterUcast->set_beta(100);
	kUcast->set_kolo(kolo);
	kVolici->set_kolo(kolo);
	for (auto *item : *obce_)
	{
		if (filterUcast->evaluate(*item->accessData(), *kUcast))
		{
			pomObce->insert(item->accessData()->get_nazov(), item->accessData());
		}
	}
	std::cout << "Podla coho chces Zoradit obce?: \n";
	cout << "a.Nazov \n" << endl;
	cout << "b.Volici \n" << endl;
	cout << "c.Ucast\n" << endl;
	cin >> rozhodnutie;
	if (rozhodnutie == 'a')
	{
		structures::HeapSort<string, Oblast*, string, Oblast>* heap_sort = new structures::HeapSort<string, Oblast*, string, Oblast>();
		std::cout << "1 - zostupne. \n";
		std::cout << "2 - vzostupne. \n";
		cin >> triedenie;
		if (triedenie == 1)
		{
			heap_sort->sortDesc(*pomObce, *kNazov);

		}
		else if (triedenie == 2)
		{
			heap_sort->sortAsc(*pomObce, *kNazov);

		}
		else
		{
			zoradVsetko();
		}
		delete heap_sort;

	}
	else if (rozhodnutie == 'b')
	{
		structures::HeapSort<string, Oblast*, int, Oblast>* heap_sort = new structures::HeapSort<string, Oblast*, int, Oblast>();
		std::cout << "1 - zostupne. \n";
		std::cout << "2 - vzostupne. \n";
		cin >> triedenie;
		if (triedenie == 1)
		{
			heap_sort->sortDesc(*pomObce, *kVolici);

		}
		else if (triedenie == 2)
		{
			heap_sort->sortAsc(*pomObce, *kVolici);

		}
		else
		{
			zoradVsetko();
		}
		delete heap_sort;

	}
	else if (rozhodnutie == 'c')
	{
		structures::HeapSort<string, Oblast*, double, Oblast>* heap_sort = new structures::HeapSort<string, Oblast*, double, Oblast>();

		std::cout << "1 - zostupne. \n";
		std::cout << "2 - vzostupne. \n";
		cin >> triedenie;
		if (triedenie == 1)
		{
			heap_sort->sortDesc(*pomObce, *kUcast);

		}
		else if (triedenie == 2)
		{
			heap_sort->sortAsc(*pomObce, *kUcast);

		}
		
		{
			zoradVsetko();
		}
		delete heap_sort;

	}
	else
	{
		zoradVsetko();
	}

	for (auto item : *pomObce)
	{
		if (rozhodnutie == 'a')
		{
			cout << item->accessData()->get_nazov() << endl;
		}
		else if (rozhodnutie == 'b')
		{
			cout << item->accessData()->get_nazov() << "-" << item->accessData()->get_pocet_zap_volicov(kolo) << endl;
		}
		else
		{
			cout << item->accessData()->get_nazov() << "-" << item->accessData()->get_ucast_volicov_percenta(kolo) << endl;

		}

	}



	delete pomObce;
}

void Volby::zoradPodla()
{
	
	structures::UnsortedSequenceTable<string, Oblast*>* pomObce = new structures::UnsortedSequenceTable<string, Oblast*>();
	
	int triedenie;
	char rozhodnutie;
	int a, b, kolo;
	string vyssiUzemnyCelok;
	std::cout << "Podla coho chces Zoradit uzemny celok?: \n";
	cout << "a.Nazov \n" << endl;
	cout << "b.Volici \n" << endl;
	cout << "c.Ucast\n" << endl;
	
	std::cin >> rozhodnutie;

	
		
	std::cout << " Zadaj kolo a rozmedzie pre ucast pre obce, ktore chces zotriedit: \n";

	std::cout << "zadaj dolna hranica: \n";
	std::cin >> a;
	std::cout << "zadaj horna hranica: \n";
	std::cin >> b;
	std::cout << "zadaj, pre ktore kolo: \n";
	std::cin >> kolo;
	
	std::cout << " Zadaj v ktorom uzemnom celku sa maju nachadzat: \n";
	cin.ignore();
	getline(std::cin, vyssiUzemnyCelok);
	
	filterUcast->set_alpha(a);
	filterUcast->set_beta(b);
	kUcast->set_kolo(kolo);
	kVolici->set_kolo(kolo);
	kNachadzaSa->set_vyssi_uz_celok(vyssiUzemnyCelok);
	for (auto *item : *obce_)
	{
		filterNachadzaSa->set_alpha(true);

		
		if (filterUcast->evaluate(*item->accessData(), *kUcast) && filterNachadzaSa->evaluate(*item->accessData(), *kNachadzaSa))
		{


			pomObce->insert(item->accessData()->get_nazov(), item->accessData());
		}
	}
	
	

	if (rozhodnutie == 'a')
	{
		structures::HeapSort<string, Oblast*, string, Oblast>* heap_sort = new structures::HeapSort<string, Oblast*, string, Oblast>();
		std::cout << "1 - zostupne. \n";
		std::cout << "2 - vzostupne. \n";
		cin >> triedenie;
		if (triedenie == 1)
		{
			heap_sort->sortDesc(*pomObce, *kNazov);

		}
		else if (triedenie == 2)
		{
			heap_sort->sortAsc(*pomObce, *kNazov);

		}
		else
		{
			zoradPodla();
		}
		delete heap_sort;

	}
	if (rozhodnutie == 'b')
	{
		structures::HeapSort<string, Oblast*, int, Oblast>* heap_sort = new structures::HeapSort<string, Oblast*, int, Oblast>();
		std::cout << "1 - zostupne. \n";
		std::cout << "2 - vzostupne. \n";
		cin >> triedenie;
		if (triedenie == 1)
		{
			heap_sort->sortDesc(*pomObce, *kVolici);

		}
		else if (triedenie == 2)
		{
			heap_sort->sortAsc(*pomObce, *kVolici);

		}
		else
		{
			zoradPodla();
		}
		delete heap_sort;

	}
	if (rozhodnutie == 'c')
	{
		structures::HeapSort<string, Oblast*, double, Oblast>* heap_sort = new structures::HeapSort<string, Oblast*, double, Oblast>();

		std::cout << "1 - zostupne. \n";
		std::cout << "2 - vzostupne. \n";
		cin >> triedenie;
		if (triedenie == 1)
		{
			heap_sort->sortDesc(*pomObce, *kUcast);

		}
		else if (triedenie == 2)
		{
			heap_sort->sortAsc(*pomObce, *kUcast);

		}
		else //if (triedenie == 3)
		{
			zoradPodla();
		} 
		delete heap_sort;

	}
	
	for (auto item : *pomObce)
	{
		if (rozhodnutie == 'a')
		{
			cout << item->accessData()->get_nazov() << endl;
		} else if (rozhodnutie == 'b')
		{
				cout << item->accessData()->get_nazov() << "-" << item->accessData()->get_pocet_zap_volicov(kolo) <<  endl;
		} else
		{
			cout << item->accessData()->get_nazov() << "-" << item->accessData()->get_ucast_volicov_percenta(kolo) << endl;

		}
		
	}

	

	delete pomObce;
}


Volby::~Volby()
{
	

	for (auto obce : *obce_)
	{

		delete obce->accessData();
	}
	delete obce_;

	for (auto kraj : *kraje_)
	{
		delete kraj->accessData();
	}
	delete kraje_;

	for (auto okres : *okresy_)
	{
		delete okres->accessData();
	}
	delete okresy_;

	delete filterNazov;
	delete filterNachadzaSa;
	delete filterUcast;
	delete filterVolici;

	delete kNazov;
	delete kVolici;
	delete kNachadzaSa;
	delete kUcast;


}

