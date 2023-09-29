#ifndef CADASTRO_H
#define CADASTRO_H

#include "paciente.h"
#include "arvore.h"

template<typename T>
class Cadastro{

	public:
		Node<T>* operator+=(T &);
		Node<T>* operator()(T &);
		friend std::ostream &operator<< (std::ostream &output, Cadastro<T> &other){
			output << other.elementos.get_string() << std::endl;
			return output;
		}

	private:
        Tree<T> elementos;
};

template<typename T>
Node<T>* Cadastro<T>::operator+=(T &i){
	elementos.add(i);
	return elementos.search(i);
}

template<typename T>
Node<T>* Cadastro<T>::operator()(T &i){
	return elementos.search(i);
}
#endif