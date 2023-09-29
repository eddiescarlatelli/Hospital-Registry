#include "cadastro.h"
#include <exception>
class NullPtrException : public exception{
    public:
        virtual const char* what () const throw (){
            return "NullPtr inserido";
        }
};
int main(){
    
    Paciente p1("J","1");
    Paciente p2("d","2");
    Cadastro<Paciente> c;

    int exit = 0;
    while(exit < 3){
        
        std::cout << "Escolha uma opcao" << std::endl;
        std::cout << "1. Cadastrar um paciente;" << std::endl;
        std::cout << "2. Imprimir todos os pacientes cadastrados;" << std::endl;
        std::cout << "3. Para encerrar;" << std::endl;
        std::cin >> exit;
        switch(exit){
            case(1):
            {
                std::string n;
                std::string t;
                std::cout << "Insira o nome do paciente: " << std::endl;
                std::cin >> n;
                std::cout << "Insira o telefone do paciente: " << std::endl;
                std::cin >> t;
                Paciente p(n,t);
                try{
                    c+=p;
                }
                catch(NullPtrException &error){
                    std::cout << error.what() << std::endl;
                }
            }
            case(2):
            {
                 std::cout << c;
            }


        }
    }
    return 0;
}