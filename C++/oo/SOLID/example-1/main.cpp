#include <iostream>
#include "ContratoClt.hpp"
#include "Estagio.hpp"
#include "ContratoPj.hpp"

int main() {

    ContratoClt *contratoClt = new ContratoClt();
    Estagio *estagio = new Estagio();
    ContratoPj *pj = new ContratoPj();

    std::cout << "ContratoClt " << contratoClt->remuneracao() << std::endl;
    std::cout << "Estagio " << estagio->remuneracao() << std::endl;
    std::cout << "Pj " << pj->remuneracao() << std::endl;

    std::cout << "Funcionando" << std::endl;

    return 0;
}
