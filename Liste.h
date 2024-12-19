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

        void ajouter(const T &, const int &);

        void enleverEl(const T &);

        void enleverPos(size_t);

        int taille() const;

        bool estVide() const;

        bool appartient(const T &) const;

        T element(const int &) const;

        size_t position(const T &) const;


        template<class U>
        friend std::ostream &operator<<(std::ostream &, const Liste<U> &);
        std::string format() const ;

    private:

        struct NoeudSentinelle {
            NoeudSentinelle *suivant ;
            NoeudSentinelle *precedent ;

            explicit NoeudSentinelle (NoeudSentinelle *adrSuivant = nullptr, NoeudSentinelle *adrPrec = nullptr) : suivant (adrSuivant), precedent (adrPrec) {} ;
            virtual const T& lireCle() const {throw std::runtime_error("Une sentinelle ne possède pas de clé!") ; }
            virtual ~NoeudSentinelle() = default;
        };


        struct Noeud : public NoeudSentinelle {
            T donnee;

            explicit Noeud(const T &item, Noeud *adrSuivant = nullptr, Noeud *adrPrec = nullptr): NoeudSentinelle(adrSuivant, adrPrec), donnee(item) {}
            const T& lireCle() const override {return donnee ; }
        };


        NoeudSentinelle *premier;
        NoeudSentinelle *dernier;
        int cardinal{};

        bool invariant() const;

        bool positionEstValideEnEcriture(int pos) const  ;
        bool positionEstValideEnLecture(size_t pos) const ;
        NoeudSentinelle* trouverAdresseAPosition(int pos) const ;
        Noeud* revAdresseAPosition(int position) const ;
        NoeudSentinelle * localiserLaCle(const T& cle) const ;

        void insererDansAdresse(NoeudSentinelle *noeud, NoeudSentinelle *adresse) ;
        void desinsererDeAdresse(NoeudSentinelle *adresse) ;





    };


}


#include "Liste_Implantation.h"


#endif //LISTE_DOUBLEMENT_CHAINEE_SQUELETTE_LISTE_H
