//
// Created by etudiant on 22-05-14.
//

#ifndef LISTE_MAIN_LISTE_IMPLANTATION_H
#define LISTE_MAIN_LISTE_IMPLANTATION_H

#include "Liste.h"

namespace td3 {

    /**
     * Créer une liste vide.
     * @tparam T Type des données stockées dans la liste
     */
    template<typename T>
    Liste<T>::Liste() : premier(new Noeud), dernier(new Noeud), cardinal(0) {
        premier->suivant = dernier ;
        dernier->precedent = premier ;
    }

    /**
     * Constructeur par copie.
     * @tparam T
     * @param source
     */
    template<typename T>
    Liste<T>::Liste(const Liste &source) : premier(new Noeud), dernier(new Noeud), cardinal(0) {
        premier->suivant = dernier ;
        dernier->precedent = premier ;
        for (auto p = source.dernier->precedent; p != source.premier; p = p->precedent) {
            auto donnee = p->donnee ;
            ajouter(donnee, 0 ) ;
        }
    }

    /**
     * Destructeur
     * @tparam T
     */
    template<typename T>
    Liste<T>::~Liste() {
        while (!estVide()) enlever(0) ;
        delete premier ;
        delete dernier ;
    }

    /**
     * Opérateur d'assignation
     * @tparam T Type de données stockées dans la liste
     * @param rhs Membre de droite de l'assignation
     * @return A = B assigne B à A et retourne A.
     */
    template<typename T>
    Liste<T> &Liste<T>::operator=(Liste<T> rhs) {
        std::swap(premier, rhs.premier) ;
        std::swap(dernier, rhs.dernier) ;
        std::swap(cardinal, rhs.cardinal) ;
        return *this ;
    }

    /**
     * Ajouter une données dans la liste à une position donnée. Si l'élément est ajouté à la position n, après insertion
     * l'élément occupe la position n.
     * @tparam T Type de l'élément ajouté
     * @param valeur Valeur de l'élément ajouté
     * @param position Position de l'ajout
     * @pre position est compris entre 0 et cardinal inclusivement.
     * @throw std::invalid_argument si position est non-valide
     */
    template<typename T>
    void Liste<T>::ajouter(const T &valeur, size_t position) {
        if (!positionEstValideEnEcriture(position)) throw std::invalid_argument("ajouter: index non-valide") ;

        auto nouveau = new Noeud(valeur) ;
        auto courant = trouverAdresseAPosition(position) ;
        insererDansAdresse(nouveau, courant) ;

        ++ cardinal ;
    }

    /**
     * Enlever un élément de la liste.  enleverEl(v) enlève de la liste le premier élément de valeur v trouvé à partir
     * du début.  Si l'élément est absent, ou si la liste est vide, il ne se passe rien.
     * @tparam T Type de l'élément enlevé.
     * @param valeur Valeur à enlever et retirer de la liste.
     */
    template<typename T>
    void Liste<T>::enleverEl(const T &valeur) {
        auto p = adresseDeLaCle(valeur) ;
        if (p != nullptr) desinsererDeAdresse(p) ;
        -- cardinal ;
    }

    /**
     * Enlever un élément de la liste.  Retire l'élément situé à une position donnée.
     * @tparam T Type dde données stockées dans la liste.
     * @param position Position à laquelle retire l'élément.
     * @pre position est comprise entre 0 et cardinal-1 inclusivement.
     * @throw std::invalid_argument si la position est non-valide
     */
    template<typename T>
    void Liste<T>::enlever(size_t position) {
        if (!positionEstValideEnLecture(position)) throw std::invalid_argument("enlever: index non-valide") ;

        auto p = trouverAdresseAPosition(position) ;
        desinsererDeAdresse(p) ;

        -- cardinal ;
    }

    /**
     * Compte les éléments dans la liste
     * @tparam T
     * @return Le cardinal de la liste
     */
    template<typename T>
    int Liste<T>::taille() const {
        return cardinal ;
    }

    /**
     * Vérifie si la liste est vide
     * @tparam T
     * @return true si la liste est vide
     */
    template<typename T>
    bool Liste<T>::estVide() const {
        return (cardinal == 0) ;
    }

    /**
     * Vérifie la présence d'un élément dans la liste
     * @tparam T
     * @param valeur Valeur qu'on veut détecter dans la liste
     * @return true si valeur est dans la liste.
     */
    template<typename T>
    bool Liste<T>::appartient(const T &valeur) const {
        return position(valeur) == cardinal ;
    }

    /**
     * Retourne la valeur à une position donnée
     * @tparam T
     * @param position
     * @return La valeur de l'élément à la position position
     * @pre Position est comprise entre 1 et cardinal inclusivement.
     */
    template<typename T>
    T Liste<T>::element(size_t position) const {
        if (!positionEstValideEnLecture(position)) throw std::invalid_argument("element: index non-valide") ;
        auto p = trouverAdresseAPosition(position) ;
        return p->donnee ;
    }

    /**
     * Détecte la position de la première occurrence de valeur dans la liste.
     * @tparam T
     * @param valeur
     * @return L'indice où se trouve la valeur cherchée.  Si la valeur est absente de la liste, retourne cardinal.  Attention
     * sur une liste vide, le résultat sera toujours 0.
     */
    template<typename T>
    int Liste<T>::position(const T &valeur) const {
        int i = 0 ;
        for (Noeud* p = premier->suivant ; p != dernier ; p = p->suivant ) {
            if (p->donnee == valeur) return i ;
            ++ i ;
        }
        return i ;
    }

    /**
     * Insère une représentation textuelle de la liste dans un stream d'IO.
     * @tparam U
     * @param os Stream d'IO
     * @param liste liste à afficher
     * @return Le stream additionné de la liste.
     */
    template<class U>
    std::ostream &operator<<(std::ostream &os, const Liste<U> &liste) {
        os << liste.format();
        return os;
    }

    /**
     * Vérifie si un élément se trouve à la position demandée
     * @tparam T
     * @param pos Un entier, la position demandée
     * @return true si 0 <= pos <= cardinal
     */
    template<typename T>
    bool Liste<T>::positionEstValideEnEcriture(size_t pos) const {
        return (pos <= cardinal ) ;
    }

    /**
     * Trouve l'adresse du noeud se trouvant à la position demandée
     * @tparam T
     * @param pos Un entier, la position demandée
     * @return L'adresse du noeud à la position demandée
     */
    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::trouverAdresseAPosition(size_t pos) const {
        Noeud* adresse = premier->suivant ;
        for (int i = 0; i < pos; ++i) adresse = adresse->suivant ;
        return adresse ;
    }

    /**
     * Retourne un représentation textuelle de la liste: "[e1, e2, e3]"
     * @tparam T
     * @return Un objet string contenant cette représentation
     */
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

    /**
     * Retourne true si on peut lire un élément à la position demandée
     * @tparam T
     * @param pos Position demandée
     * @return true si 0 <= pos < cardinal
     */
    template<typename T>
    bool Liste<T>::positionEstValideEnLecture(size_t pos) const {
        return pos < cardinal ;
    }


    /**
     * Trouve l'adresse du noeud comportant la première occurrence de la clé à partir du début
     * @tparam T
     * @param cle
     * @return L'adresse du premier noeud contenant la clé cherchée, sinon nullptr
     */
    template<typename T>
    typename Liste<T>::Noeud *Liste<T>::adresseDeLaCle(const T &cle) const {
        for (Noeud* p = premier->suivant ; p != dernier ; p = p->suivant ) {
            if (p->donnee == cle) return p ;
        }
        return nullptr ;
    }


    /**
     * Insère un noeud à l'adresse indiquée.  Le noeud présentement à cette adresse sera la suivant du nouveau noeud.
     * @tparam T
     * @param noeud Nouveau noeud à insérer
     * @param adresse Adresse où faire l'insertion
     */
    template<typename T>
    void Liste<T>::insererDansAdresse(Liste::Noeud *nouveau, Liste::Noeud *courant) {
        nouveau->precedent = courant->precedent ;
        courant->precedent->suivant = nouveau ;
        nouveau->suivant = courant ;
        courant->precedent = nouveau ;
    }

    /**
     * Retire le noeud à l'adresse demandée.  Raccorde ensemble le précédent et le suivant.
     * @tparam T
     * @param adresse Adresse du noeud à retirer
     */
    template<typename T>
    void Liste<T>::desinsererDeAdresse(Liste::Noeud *p) {
        p->precedent->suivant = p->suivant ;
        p->suivant->precedent = p->precedent ;
        delete p ;
    }
}

#endif //LISTE_MAIN_LISTE_IMPLANTATION_H
