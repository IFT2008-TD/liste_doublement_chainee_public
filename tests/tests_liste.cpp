//
// Created by etudiant on 22-05-14.
//

#include "gtest/gtest.h"
#include "Liste.h"

using namespace td3 ;

TEST(Liste, constructeur_defaut_nothrow) {
    EXPECT_NO_THROW(Liste<int> maliste) ;
}

TEST(Liste, constructeur_defaut_taille_zero) {
    Liste<int> l ;

    EXPECT_EQ(0, l.taille()) ;

}

TEST(Liste, ajouter_position_invalide_grande_exception) {
    Liste<int> l ;
    EXPECT_THROW(l.ajouter(2, 2), std::invalid_argument ) ;
}

TEST(Liste, ajouter_position_invalide_petite_exception) {
    Liste<int> l ;
    EXPECT_THROW(l.ajouter(2, 0), std::invalid_argument ) ;
}

TEST(Liste, ajouter_un_element_cardinal_un) {
    Liste<int> l ;
    l.ajouter(42, 1) ;
    EXPECT_EQ(1, l.taille()) ;
}

TEST(Liste, format_liste_vide) {
    Liste<int> l ;
    EXPECT_EQ("[]", l.format()) ;
}

TEST(Liste, ajouter_un_element_format_correct) {
    Liste<int> l ;
    l.ajouter(42, 1) ;
    EXPECT_EQ("[42]", l.format()) ;
}

TEST(Liste, ajouter_deux_elements_format_correct) {
    Liste<int> l ;
    l.ajouter(42, 1) ;
    l.ajouter(43, 2) ;
    EXPECT_EQ("[42, 43]", l.format()) ;
}

TEST(Liste, ajouter_deux_elements_ordre_inverse_format_correct) {
    Liste<int> l ;
    l.ajouter(42, 1) ;
    l.ajouter(43, 1) ;
    EXPECT_EQ("[43, 42]", l.format()) ;
}





