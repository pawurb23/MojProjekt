#include "ProstyUAR.h"

ProstyUAR::ProstyUAR() : model({ -1.0 }, { 1.0 }, 1, 0.0), regulator(1.0, 0.0, 0.0) {

    reset();
}

double ProstyUAR::symuluj(double y_zad) {

    double uchyb = y_zad - y_ost;
    double u_wej = regulator.symuluj(uchyb);
    double y_wyj = model.symuluj(u_wej);

    y_ost = y_wyj;
    u_akt = u_wej;
    e_akt = uchyb;

    return y_wyj;
}

void ProstyUAR::reset() {
    y_ost = 0.0;
    u_akt = 0.0;
    e_akt = 0.0;
    regulator.resetPamieci();
}

void ProstyUAR::setPID(double k, double ti, double td) {
    regulator.setNastawy(k, ti, td);
}

void ProstyUAR::setModel(std::vector<double> A, std::vector<double> B, int k, double z) {
    model.setWspA(A);
    model.setWspB(B);
    model.setOpoznienie(k);
    model.setZaklocenia(z);
}
