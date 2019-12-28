# RelativeNeighborhoodGraph

![Code grade](https://www.code-inspector.com/project/2444/status/svg#1)
![Code score](https://www.code-inspector.com/project/2444/score/svg#1)
[![CodeFactor](https://www.codefactor.io/repository/github/guillaumebchd/relativeneighborhoodgraph/badge)](https://www.codefactor.io/repository/github/guillaumebchd/relativeneighborhoodgraph)

Ce logiciel est écrit en C++ et est issu d'un projet de DI4 de l'école Polytech Tours.

## Qu'est-ce que c'est ?

Le but est de mettre en place un Graphe de Voisinage (Relative Neighborhood Graph) à partir d'un fichier de donnée et d'analyser celui-ci grâce à un algorithme de parcours afin d'obtenir de multiples statistiques.

## Installation

Le projet est actuellement sous la forme d'un projet Xcode, néanmoins importer le dossier **src** sous Visual Studio où tout autre IDE devrait fonctionner.

## Besoin du logiciel
Le logiciel a besoin pour fonctionner d'un fichier de donnée complet, celui-ci ne doit contenir que des nombres ou alors doit être accompagné d'un fichier d'entête qui spécifie si une des colonnes est un attribut de classe et ne sera donc pas utiliser pour générer notre graphe.

**Le fichier de donnée** sépare peut être assimilé à une matrice où chaque colonne est séparé par un certain caractère de séparation (**par défaut ','**).

**Le fichier d'entête** ne contient qu'une seule ligne et doit posséder le même nombre de colonne que le fichier de donnée. 
Pour chaque colonne on spécifie une valeur précise :

* **0** signifie que la colonne n'est pas un attribut de classe et utilisée pour générer le graphe (**doit être un nombre**).
* **1** signifie que la colonne est un attribut de classe et n'est pas utilisée pour générer le graphe.
* **2** signifie que la colonne est un attribut de classe et est utilisée pour générer le graphe (**doit être un nombre**).

## Exemple de fichier

Fichier de donnée :

```
1,2,3,4,5,Attribut de classe
1,2,3,4,5,Attribut de classe
...
1,2,3,4,5,Attribut de classe
```

Fichier d'entête :

```
0,0,0,0,0,1
```

## Utilisation du logiciel

Une fois le logiciel build, on obtient un executable qui peut prendre plusieurs arguments :

* **-d "chemin du fichier de donnée"** permet de choisir le fichier de donnée, si cette option est manquante le logiciel se coupera et enverra le code 1.
* **-c "chemin du fichier d'entête"** permet de choisir le fichier d'entête, si cette option est manquante, on considèrera que toutes les colonnes du fichier de donnée sont utilisées pour créer le graphe et ne sont pas des attributs de classes.
*  **-e "chemin du dossier d'exportation"** permet de choisir le dossier dans lequel seront exportés les fichiers de résultats.
*  **-s 'charactère de séparation'** permet dee choisir le charactère de séparation utilisé pour séparer les colonnes dans les fichiers importés.
*  **-v version** permet de choisir quel version de l'algorithme de parcours le logiciel utilisera, la version 1 ne prend en compte que les voisins d'un noeud A (plus rapide mais moins précise) tandis que la version 2 prend en compte les voisins et les voisins des voisins d'un noeud A (moins rapide mais plus précise).
*  **-k nombre de noeuds** permet de choisir le nombre de noeuds que l'on souhaite utiliser pour l'algorithme de parcours. Si cette option est absente l'algorithme de parcours effectuera pour tous les noeuds du graphe une insertion sur tous les noeuds.

