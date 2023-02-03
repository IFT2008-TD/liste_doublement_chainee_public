//
// Created by etudiant on 22-05-14.
//

#ifndef LISTE_MAIN_LISTE_IMPLANTATION_H
#define LISTE_MAIN_LISTE_IMPLANTATION_H

#include "Liste.h"

namespace td3 {

    template<typename T>
    Liste<T>::Liste() : premier(new Noeud), dernier(new Noeud), cardinal(0) {
        premier->suivant = dernier ;
        dernier->precedent = premier ;
    }

    template<typename T>
    Liste<T>::Liste(const Liste &source) {

    }

    template<typename T>
    Liste<T>::~Liste() {

    }

    template<typename T>
    Liste<T> &Liste<T>::operator=(const Liste<T> &rhs) {
        return *this;
    }

    template<typename T>
    void Liste<T>::ajouter(const T &valeur, const int &position) {
        if (!positionEstValideEnEcriture(position)) throw std::invalid_argument("ajouter: index non-valide") ;

        auto nouveau = new Noeud(valeur) ;
        auto courant = trouverAdresseAPosition(position) ;

        nouveau->precedent = courant->precedent ;
        courant->precedent->suivant = nouveau ;
        nouveau->suivant = courant ;
        courant->precedent = nouveau ;

        ++ cardinal ;
    }

    template<typename T>
    void Liste<T>::enleverEl(const T &valeur) {

    }

    template<typename T>
    void Liste<T>::enleverPos(const int &position) {

    }

    template<typename T>
    int Liste<T>::taille() const {
        return cardinal ;
    }

    template<typename T>
    bool Liste<T>::estVide() const {
        return (cardinal == 0) ;
    }

    template<typename T>
    bool Liste<T>::appartient(const T &valeur) const {
        return false;
    }

    template<typename T>
    T Liste<T>::element(const int &position) const {
        return nullptr;
    }

    template<typename T>
    int Liste<T>::position(const T &valeur) const {
        return 0;
    }

    template<typename T>
    void Liste<T>::verifieInvariant() const {

    }

    template<class U>
    std::ostream &operator<<(std::ostream & os, const Liste<U> &) {
        return os;
    }

    template<typename T>
    bool Liste<T>::positionEstValideEnEcriture(int pos) {
        return ((pos > 0) && (pos <= cardinal + 1)) ;
    }

    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::trouverAdresseAPosition(int pos) {
        Noeud* adresse = premier ;
        for (int i = 0; i < pos; ++i) adresse = adresse->suivant ;
        return adresse ;
    }

    template<typename T>
    std::string Liste<T>::format() const {
        if (estVide()) return "[]" ;

        std::ostringstream os ;
        os << "[" ;
        for (Noeud* p = premier->suivant ; p != dernier ; p = p->suivant ) {
            os << p->donnee ;
            if (p->suivant != dernier) os << ", " ;
        }
        os << "]" ;

        return os.str() ;
    }


}

#endif //LISTE_MAIN_LISTE_IMPLANTATION_H
