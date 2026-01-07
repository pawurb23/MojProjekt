#pragma once

#include "ModelARX.h"
#include "RegulatorPID.h"

class ProstyUAR {
private:

	ModelARX model;
	RegulatorPID regulator;
	double y_ost;
	double u_akt;
	double e_akt;

public:

	ProstyUAR();

	double symuluj(double y_zad);
	void reset();

	ModelARX& getModel() { return model; }
	RegulatorPID& getRegulator() { return regulator; }
	double getU() const { return u_akt; }
	double getE() const { return e_akt; }

	void setPID(double k, double ti, double td);
	void setModel(std::vector<double> A, std::vector<double> B, int k, double z);

};
