#include "FolhaDePagamento.hpp"

double FolhaDePagamento::calcular(Remuneravel *contract) {
    this->saldo = contract->remuneracao();
}
