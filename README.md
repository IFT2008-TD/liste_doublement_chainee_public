# IFT2008 Travail dirigé 3: la liste doublement chaînée

## Installation

### CLion

Dans la fenêtre du sélecteur de projets, choisissez ```Get fromm VCS``` et ensuite saisissez l'adresse du dépôt: 
```https://github.com/IFT2008-TD/liste_doublement_chainee_public``` cochez ensuite la case ```Trust project```et le projet
sera cloné et immédiatement prêt à l'emploi dans CLion.

### Netbeans


## Description de la structure de données

La classe ```Liste``` est une implantation de la liste doublement chaînée.  Il s'agit d'une liste où chaque élément pointe
sur l'élément suivant ET sur l'élément précédent, ce qui simplifie le travail pour insérer ou effacer de nouveaux éléments.

La classe Liste contient un type privé qui est la classe Noeud, celui-ci contient trois champs: donnée, suivant et précédent.

- Champ donnée: Contient les données utiles de la liste.  Remarquez que l'utilisateur ne voit jamais les noeuds, pour lui la liste contient simplement une suite de données.
- Champ précédent: adresse du noeud précédent
- Champe suivant: adresse du noeud suivant

On a fait le choix, dans la présente implantation, d'utiliser des noeuds sentinelles: il y a donc un noeud en première et
en dernière position.  Ces noeuds ne contiennent aucune donnée utile, ils ne servent qu'à remplir la première et la dernière
place de la liste, mais ne sont jamais comptés dans les données.  Donc, une liste vide contient deux noeuds: ce sont les deux 
sentinelles.  Pourquoi ce choix?  Cela simplifie beaucoup l'écriture de la classe.  Par-contre, ce choix entraîne une contrainte:  le
type des données doit être constructible par défaut, c'est à dire posséder un constructeur par défaut.

On adopte aussi la convention suivante pour les positions dans la liste:

      nullptr <--> premier(sentinelle) <--> noeud 0 <--> noeud 1 <--> noeud 2 <--> noeud 3 <--> dernier(sentinelle) --> nullptr

Dans cet exemple, le cardinal de la liste est 4, car la liste contient 4 noeuds aux positions allant de 0 à 3.  Je peux donc 
lire les noeuds 0, 1, 2 ou 3.

Par-contre: je peux insérer un noeud aux positions 0, 1, 2, 3 ou 4!!!  Si j'insére une donnée en position 2, celle-ci sera 
dans le nouveau noeud 2, et l'actuel noeud 2 deviendra le noeud 3.  Si j'insère un noeud en position 4, il sera donc inséré
entre le 3 et le dernier.

## Travail à faire

### Étape 1: Réfléchir

Lisez attentivement:
- Liste.h
- Liste_Implantation.h
- tests/tests_liste.cpp

Il s'agit de bien lire le code source fourni, et de bien analyser le fichier Liste.h et Liste_Implantation.h, de bien 
lire le présent README et bien comprendre ce qui est demandé.  Certaines primitives et certains tests ont déjà été
implantées pour simplifier le travail.  Les comportements attendus des diverses primitives sont indiqués en détail
dans la documentation du code.

### Étape 2: implanter les primitives demandées et LES TESTER

Vous devrez modifier ou compléter les fichiers suivants:
- Liste.h
- Liste_Implantation.h
- tests/tests_liste.cpp

Le travail demandé est d'implanter les primitives suivantes.  Vous devez aussi écrire des tests appropriés pour vérifier
votre implantation:

- Constructeur par défaut: crée une liste vide
- Constructeur de copie: crée une nouvelle liste à-partir d'une liste existante
- Opérateur d'assignation: assigne les éléments d'une liste de droite à la liste de gauche
- Destructeur: détruit la liste
- ajouter: un nouvel élément est ajouté à la liste à une position valide
- enlverEl: retire la première occurrence d'un élément de la liste
- enleverPos: retire l'élément se trouvant à position demandée
- taille: compte les éléments
- estVide: indique si la liste est vide
- appartient: indique si un élément donné se trouve dans la liste
- element: retourne l'élément contenu à la position demandée
- position: retourne la position de l'élément demandé

Remarquez que le code source fourni contient des méthodes privées.  Celles-ci sont simplement des suggestions
et vous n'êtes pas obligés de les utiliser ou les implanter.  Vous pouvez aussi en utiliser d'autres qui
vous semblent plus appropriées.