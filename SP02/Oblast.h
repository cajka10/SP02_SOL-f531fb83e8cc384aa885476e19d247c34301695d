#pragma once
#include <string>
#include <iostream>

class Oblast
{
private:
	std::string nazov_;

	int pocetZapVolicov1_;
	int pocetVydObalok1_;
	double ucastVolicovPercenta1_;
	int pocetOdovzdObalok1_;
	int pocetPlatHlasov1_;

	int pocetZapVolicov2_;
	int pocetVydObalok2_;
	double ucastVolicovPercenta2_;
	int pocetOdovzdObalok2_;
	int pocetPlatHlasov2_;

public:

	Oblast(std::string nazov)
		: nazov_(nazov)

	{
	}
	~Oblast()
	{

	}
	void vypisInfo() {
		std::cout << "-------------------------------------------------------------\n";
		std::cout << this->get_nazov() << "\n";
		std::cout << "1.Kolo: \n";
		std::cout << "Volici:" << this->get_pocet_zap_volicov(1) << "\n";
		std::cout << "Vydane Obalky:" << this->get_pocet_vyd_obalok(1) << "\n";
		std::cout << "Ucast:" << this->get_ucast_volicov_percenta(1) << "\n";
		std::cout << "Odovzdane Obalky:" << this->get_pocet_odovzd_obalok(1) << "\n";
		std::cout << "2.Kolo: \n";
		std::cout << "Volici:" << this->get_pocet_zap_volicov(2) << "\n";
		std::cout << "Vydane Obalky:" << this->get_pocet_vyd_obalok(2) << "\n";
		std::cout << "Ucast:" << this->get_ucast_volicov_percenta(2) << "\n";
		std::cout << "Odovzdane Obalky:" << this->get_pocet_odovzd_obalok(2) << "\n";

		std::cout << "-------------------------------------------------------------\n";
	}
	void vypisInfoKolo(int kolo) {
		if (kolo == 1)
		{


			std::cout << "-------------------------------------------------------------\n";
			std::cout << this->get_nazov() << "\n";
			std::cout << "1.Kolo: \n";
			std::cout << "Volici:" << this->get_pocet_zap_volicov(1) << "\n";
			std::cout << "Vydane Obalky:" << this->get_pocet_vyd_obalok(1) << "\n";
			std::cout << "Ucast:" << this->get_ucast_volicov_percenta(1) << "\n";
			std::cout << "Odovzdane Obalky:" << this->get_pocet_odovzd_obalok(1) << "\n";


			std::cout << "-------------------------------------------------------------\n";
		}
		else if (kolo == 2)
		{
			std::cout << "-------------------------------------------------------------\n";
			std::cout << this->get_nazov() << "\n";

			std::cout << "2.Kolo: \n";
			std::cout << "Volici:" << this->get_pocet_zap_volicov(2) << "\n";
			std::cout << "Vydane Obalky:" << this->get_pocet_vyd_obalok(2) << "\n";
			std::cout << "Ucast:" << this->get_ucast_volicov_percenta(2) << "\n";
			std::cout << "Odovzdane Obalky:" << this->get_pocet_odovzd_obalok(2) << "\n";
			std::cout << "-------------------------------------------------------------\n";
		}
		
	}

	std::string get_nazov() const
	{
		return nazov_;
	}

	void set_nazov(const std::string& nazov)
	{
		nazov_ = nazov;
	}

	int get_pocet_zap_volicov(int kolo) const
	{
		if (kolo == 1)
		{
			return pocetZapVolicov1_;

		}
		if (kolo == 2)
		{
			return pocetZapVolicov2_;

		}
	}

	void set_pocet_zap_volicov1(int pocet_zap_volicov1)
	{
		pocetZapVolicov1_ = pocet_zap_volicov1;
	}

	int get_pocet_vyd_obalok(int kolo) const
	{
		if (kolo == 1)
		{
			return  pocetVydObalok1_;

		}
		else if (kolo == 2)
		{
			return  pocetVydObalok2_;

		}
		else
		{
			return  pocetVydObalok1_ + pocetVydObalok2_;
		}
	}

	void set_pocet_vyd_obalok1(int pocet_vyd_obalok1)
	{
		pocetVydObalok1_ = pocet_vyd_obalok1;
	}

	double get_ucast_volicov_percenta(int kolo) const
	{
		if (kolo == 1)
		{
			return ucastVolicovPercenta1_;

		}
		else if (kolo == 2)
		{
			return ucastVolicovPercenta2_;

		}

	}

	void set_ucast_volicov_percenta1(double ucast_volicov_percenta1)
	{
		ucastVolicovPercenta1_ = ucast_volicov_percenta1;
	}

	int get_pocet_odovzd_obalok(int kolo) const
	{
		if (kolo == 1)
		{
			return pocetOdovzdObalok1_;

		}
		else if (kolo == 2)
		{
			return pocetOdovzdObalok2_;

		}
	}

	void set_pocet_odovzd_obalok1(int pocet_odovzd_obalok1)
	{
		pocetOdovzdObalok1_ = pocet_odovzd_obalok1;
	}

	int get_pocet_plat_hlasov1(int kolo) const
	{
		if (kolo == 1)
		{
			return pocetPlatHlasov1_;

		}
		if (kolo == 2)
		{
			return  pocetPlatHlasov2_;

		}
	}

	void set_pocet_plat_hlasov1(int pocet_plat_hlasov1)
	{
		pocetPlatHlasov1_ = pocet_plat_hlasov1;
	}


	void set_pocet_zap_volicov2(int pocet_zap_volicov2)
	{
		pocetZapVolicov2_ = pocet_zap_volicov2;
	}



	void set_pocet_vyd_obalok2(int pocet_vyd_obalok2)
	{
		pocetVydObalok2_ = pocet_vyd_obalok2;
	}



	void set_ucast_volicov_percenta2(double ucast_volicov_percenta2)
	{
		ucastVolicovPercenta2_ = ucast_volicov_percenta2;
	}



	void set_pocet_odovzd_obalok2(int pocet_odovzd_obalok2)
	{
		pocetOdovzdObalok2_ = pocet_odovzd_obalok2;
	}


	void set_pocet_plat_hlasov2(int pocet_plat_hlasov2)
	{
		pocetPlatHlasov2_ = pocet_plat_hlasov2;
	}

	//neimplementovane zatial
	bool nachadzaSa(Oblast* oblast) const
	{
		return oblast->get_nazov() == this->get_nazov();
	};
};