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

        Liste<T> &operator=(const Liste<T> &);

        void ajouter(const T &, const int &);

        void enleverEl(const T &);

        void enleverPos(const int &);

        int taille() const;

        bool estVide() const;

        bool appartient(const T &) const;

        T element(const int &) const;

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

            explicit Noeud () : donnee (), suivant (),  precedent () {} ;

            explicit Noeud(const T &data_item, Noeud *next_ptr = nullptr, Noeud *prev_ptr = nullptr) :
                    donnee(data_item), suivant(next_ptr), precedent(prev_ptr) {}
        };


        Noeud *premier;
        Noeud *dernier;
        int cardinal;

        void verifieInvariant() const;
        bool positionEstValideEnEcriture(int pos) ;
        Noeud* trouverAdresseAPosition(int pos) ;


    };


}


#include "Liste_Implantation.h"


#endif //LISTE_DOUBLEMENT_CHAINEE_SQUELETTE_LISTE_H
