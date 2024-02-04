//
// Created by etudiant on 22-05-14.
//

#ifndef LISTE_DOUBLEMENT_CHAINEE_SQUELETTE_LISTE_H
#define LISTE_DOUBLEMENT_CHAINEE_SQUELETTE_LISTE_H

#include <cstddef>
#include <iostream>
#include <string>
#include <sstream>

namespace td3 {
    template<typename T>
    class Liste {

    public:
        explicit Liste();

        Liste(const Liste &);

        ~Liste();

        Liste<T> &operator=(Liste<T> );

        void ajouter(const T &, size_t);

        void enleverEl(const T &);

        void enlever(size_t);

        int taille() const;

        bool estVide() const;

        bool appartient(const T &) const;

        T element(size_t) const;

        int position(const T &) const;


        template<class U>
        friend std::ostream &operator<<(std::ostream &, const Liste<U> &);
        std::string format() const ;

    private:


        class Noeud {
        public:
            T donnee;
            Noeud *suivant;
            Noeud *precedent;

            explicit Noeud () : donnee (), suivant (nullptr),  precedent (nullptr) {} ;

            explicit Noeud(const T &data_item, Noeud *next_ptr = nullptr, Noeud *prev_ptr = nullptr) :
                    donnee(data_item), suivant(next_ptr), precedent(prev_ptr) {}
        };


        Noeud *premier;
        Noeud *dernier;
        int cardinal;

        bool positionEstValideEnEcriture(size_t pos) const  ;
        bool positionEstValideEnLecture(size_t pos) const ;
        Noeud* trouverAdresseAPosition(size_t pos) const ;
        Noeud* adresseDeLaCle(const T& cle) const ;

        void insererDansAdresse(Noeud* nouveau, Noeud* courant) ;
        void desinsererDeAdresse(Noeud* p) ;

    };


}


#include "Liste_Implantation.h"


#endif //LISTE_DOUBLEMENT_CHAINEE_SQUELETTE_LISTE_H
