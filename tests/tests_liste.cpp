//
// Created by etudiant on 22-05-14.
//

#include "gtest/gtest.h"
#include "Liste.h"

using namespace td3 ;

class ListeTest : public ::testing::Test {
protected:
    ListeTest() : l5() {
        l5.ajouter(666, 0) ;
        l5.ajouter(777, 1) ;
        l5.ajouter(888, 2) ;
    }

protected:

    Liste<int> l5 ;
};

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

TEST(Liste, ajouter_un_element_cardinal_un) {
    Liste<int> l ;
    l.ajouter(42, 0) ;
    EXPECT_EQ(1, l.taille()) ;
}

TEST(Liste, format_liste_vide) {
    Liste<int> l ;
    EXPECT_EQ("[]", l.format()) ;
}

TEST(Liste, ajouter_un_element_format_correct) {
    Liste<int> l ;
    l.ajouter(42, 0) ;
    EXPECT_EQ("[42]", l.format()) ;
}

TEST(Liste, ajouter_deux_elements_format_correct) {
    Liste<int> l ;
    l.ajouter(42, 0) ;
    l.ajouter(43, 1) ;
    EXPECT_EQ("[42, 43]", l.format()) ;
}

TEST(Liste, ajouter_deux_elements_ordre_inverse_format_correct) {
    Liste<int> l ;
    l.ajouter(42, 0) ;
    l.ajouter(43, 0) ;
    EXPECT_EQ("[43, 42]", l.format()) ;
}

TEST(Liste, ajouter_et_supprimer_un_element) {
    Liste<int> l ;
    l.ajouter(666, 0) ;
    l.enlever(0) ;
    EXPECT_TRUE(l.estVide()) ;

}

TEST_F(ListeTest, dispositif_bien_construit) {
    EXPECT_EQ("[666, 777, 888]", l5.format()) ;
}

TEST_F(ListeTest, suppression_a_1) {
    l5.enlever(1) ;
    EXPECT_EQ("[666, 888]", l5.format()) ;
}

TEST_F(ListeTest, constructeur_copie) {
    Liste<int> copie(l5) ;
    EXPECT_EQ(l5.format(), copie.format()) ;
}

TEST_F(ListeTest, assignation) {
    Liste<int> lassign ;
    lassign = l5 ;
    EXPECT_EQ(l5.format(), lassign.format()) ;
}

TEST_F(ListeTest, enleverEl) {
    l5.enleverEl(777) ;
    EXPECT_EQ("[666, 888]", l5.format()) ;
}





