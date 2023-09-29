#ifndef PACIENTE_H 
#define PACIENTE_H

#include <iostream>
#include <string.h>

class Paciente{
    public:
        Paciente() = default;
        Paciente(std::string, std::string);
        bool operator> (Paciente &);
        bool operator< (Paciente &);
        bool operator== (Paciente &);
        bool operator>= (Paciente &);
        bool operator<= (Paciente &);
        void setNome(std::string);
        void setTel(std::string);
        std::string getNome();
        std::string getTel();
        virtual std::string getString();
        friend std::ostream &operator<< (std::ostream &output, Paciente &other){
			output << "(" << other.getNome() << " ; " << other.getTel() << ")" << std::endl;
			return output;
		}
    protected:
        std::string nome;
        std::string tel;
};
#endif