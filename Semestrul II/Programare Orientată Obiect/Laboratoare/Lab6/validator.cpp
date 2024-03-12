#include "validator.h"

void MasinaValidation::validate_masina(const Masina& m) 
{
	int sem;
	string nrinm;
	string judet;
	string nr;
	string litere;
	nrinm = m.getNrInmatriculare();
	vector<string> err;
	if (nrinm.length() != 7)
		err.push_back("NumarInmatriculare invalid!/");
	else
	{
		sem = 1;
		nr = nrinm.substr(1, 3);
		for (int i = 0;i < nr.length();i++)
			if (nr.at(i) < '0' || nr.at(i)>'9')
			{
				sem = 0;
				break;}
		if (sem == 1)
		{
			judet = nrinm.substr(0, 1);
			litere = nrinm.substr(4, 3);
			if(judet.compare("B") != 0)
				err.push_back("NumarInmatriculare invalid!/");
			else if (litere.at(0) < 'A' || litere.at(0) > 'Z' || litere.at(1) < 'A' || litere.at(1) > 'Z' || litere.at(2) < 'A' || litere.at(2) > 'Z')
				err.push_back("NumarInmatriculare invalid!/");
		}
		if (sem == 0)
		{
			judet = nrinm.substr(0, 2);
			nr = nrinm.substr(2, 2);
			litere = nrinm.substr(4, 3);
			if (judet.compare("AB") != 0 && judet.compare("AG") != 0 && judet.compare("AR") != 0 && judet.compare("BC") != 0 && judet.compare("BH") != 0 && judet.compare("BN") != 0 && judet.compare("BR") != 0 && judet.compare("BT") != 0 && judet.compare("BV") != 0 && judet.compare("BZ") != 0 && judet.compare("CJ") != 0 && judet.compare("CL") != 0 && judet.compare("CS") != 0 && judet.compare("CT") != 0 && judet.compare("CV") != 0 && judet.compare("DB") != 0 && judet.compare("DJ") != 0 && judet.compare("GJ") != 0 && judet.compare("GL") != 0 && judet.compare("GR") != 0 && judet.compare("HD") != 0 && judet.compare("HR") != 0 && judet.compare("IF") != 0 && judet.compare("IL") != 0 && judet.compare("IS") != 0 && judet.compare("MH") != 0 && judet.compare("MM") != 0 && judet.compare("MS") != 0 && judet.compare("NT") != 0 && judet.compare("OT") != 0 && judet.compare("PH") != 0 && judet.compare("SB") != 0 && judet.compare("SJ") != 0 && judet.compare("SM") != 0 && judet.compare("SV") != 0 && judet.compare("TL") != 0 && judet.compare("TM") != 0 && judet.compare("TR") != 0 && judet.compare("VL") != 0 && judet.compare("VN") != 0 && judet.compare("VS") != 0)
				err.push_back("NumarInmatriculare invalid!/");
			else if (litere.at(0) < 'A' || litere.at(0) > 'Z' || litere.at(1) < 'A' || litere.at(1) > 'Z' || litere.at(2) < 'A' || litere.at(2) > 'Z')
				err.push_back("NumarInmatriculare invalid!/");
			else for (int i = 0;i < nr.length();i++)
				if (nr.at(i) < '0' || nr.at(i) > '9')
				{
					err.push_back("NumarInmatriculare invalid!/");
					break;
				}
		}
	}
	/*if(m.getProducator() == "")
		err.push_back("Producator invalid!/");
	if (m.getModel() == "")
		err.push_back("Model invalid!/");*/
	if(m.getTip() != "tractor" && m.getTip() != "tir" && m.getTip() != "camion" && m.getTip() != "automobil")
		err.push_back("Tip invalid!/");
	if (err.size() > 0)
		throw ValidationException(err);
}

void MasinaValidation::validate_nrInmatriculare(string nrInmatriculare)
{
	int sem;
	string judet;
	string nr;
	string litere;
	vector<string> err;
	if (nrInmatriculare.length() != 7)
		err.push_back("NumarInmatriculare invalid!/");
	else
	{
		sem = 1;
		nr = nrInmatriculare.substr(1, 3);
		for (int i = 0;i < nr.length();i++)
			if (nr.at(i) < '0' || nr.at(i) > '9')
			{
				sem = 0;
				break;
			}
		if (sem == 1)
		{
			judet = nrInmatriculare.substr(0, 1);
			litere = nrInmatriculare.substr(4, 3);
			if (judet.compare("B") != 0)
				err.push_back("NumarInmatriculare invalid!/");
			else if (litere.at(0) < 'A' || litere.at(0) > 'Z' || litere.at(1) < 'A' || litere.at(1) > 'Z' || litere.at(2) < 'A' || litere.at(2) > 'Z')
				err.push_back("NumarInmatriculare invalid!/");
		}
		if (sem == 0)
		{
			judet = nrInmatriculare.substr(0, 2);
			nr = nrInmatriculare.substr(2, 2);
			litere = nrInmatriculare.substr(4, 3);
			if (judet.compare("AB") != 0 && judet.compare("AG") != 0 && judet.compare("AR") != 0 && judet.compare("BC") != 0 && judet.compare("BH") != 0 && judet.compare("BN") != 0 && judet.compare("BR") != 0 && judet.compare("BT") != 0 && judet.compare("BV") != 0 && judet.compare("BZ") != 0 && judet.compare("CJ") != 0 && judet.compare("CL") != 0 && judet.compare("CS") != 0 && judet.compare("CT") != 0 && judet.compare("CV") != 0 && judet.compare("DB") != 0 && judet.compare("DJ") != 0 && judet.compare("GJ") != 0 && judet.compare("GL") != 0 && judet.compare("GR") != 0 && judet.compare("HD") != 0 && judet.compare("HR") != 0 && judet.compare("IF") != 0 && judet.compare("IL") != 0 && judet.compare("IS") != 0 && judet.compare("MH") != 0 && judet.compare("MM") != 0 && judet.compare("MS") != 0 && judet.compare("NT") != 0 && judet.compare("OT") != 0 && judet.compare("PH") != 0 && judet.compare("SB") != 0 && judet.compare("SJ") != 0 && judet.compare("SM") != 0 && judet.compare("SV") != 0 && judet.compare("TL") != 0 && judet.compare("TM") != 0 && judet.compare("TR") != 0 && judet.compare("VL") != 0 && judet.compare("VN") != 0 && judet.compare("VS") != 0)
				err.push_back("NumarInmatriculare invalid!/");
			else if (litere.at(0) < 'A' || litere.at(0) > 'Z' || litere.at(1) < 'A' || litere.at(1) > 'Z' || litere.at(2) < 'A' || litere.at(2) > 'Z')
				err.push_back("NumarInmatriculare invalid!/");
			else for (int i = 0;i < nr.length();i++)
				if (nr.at(i) < '0' || nr.at(i) > '9')
				{
					err.push_back("NumarInmatriculare invalid!/");
					break;
				}
		}
	}
	if (err.size() > 0)
		throw ValidationException(err);
}
