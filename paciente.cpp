#include "paciente.h"

Paciente::Paciente(std::string _nome, std::string _tel){
    nome = _nome;
    tel = _tel;
}

void Paciente::setNome(std::string _nome){
    nome = _nome;
}

void Paciente::setTel(std::string _tel){
    tel = _tel;
}

std::string Paciente::getNome(){
    return nome;
}

std::string Paciente::getTel(){
    return tel;
}

bool Paciente::operator>(Paciente &other){
    return this->getNome() > other.getNome();
}

bool Paciente::operator<(Paciente &other){
    return this->getNome() < other.getNome();
}

bool Paciente::operator==(Paciente &other){
    return this->getNome() == other.getNome();
}

bool Paciente::operator>=(Paciente &other){
    return this->getNome() >= other.getNome();
}

bool Paciente::operator<=(Paciente &other){
    return this->getNome() <= other.getNome();
}

std::string Paciente::getString(){
    return "(" + getNome() + " ; " + getTel() + ")\n";
}