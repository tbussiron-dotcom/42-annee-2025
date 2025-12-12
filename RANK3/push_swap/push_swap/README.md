<em>This project has been created as part of the 42 curriculum by thbussir</em>

# push_swap

## 📌 Description

**push_swap** est un projet de l’école 42 dont le but est d’implémenter un algorithme de tri performant en utilisant uniquement un jeu restreint d’opérations sur deux piles : **A** et **B**.  
L'objectif principal est de :

- Lire une liste de nombres entiers.
- Trier ces nombres dans la pile A **avec le moins d’opérations possible**.
- Produire **la liste d’instructions** permettant d'obtenir ce résultat.

Le projet met fortement l’accent sur :
- L’algorithmie (choix d’un algorithme efficace selon la taille de l’entrée).
- L’optimisation des opérations.
- La gestion des erreurs (doublons, overflow, argument non valide, etc.).
- La manipulation rigoureuse de structures de données.

## ⚙️ Instructions

### ✔️ Compilation

Le projet est fourni avec un `Makefile` supportant les règles classiques :

```sh
make        # compile le programme push_swap
make clean  # supprime les fichiers objets
make fclean # supprime les objets + l'exécutable
make re     # recompile entièrement
Cela génère un exécutable appelé push_swap.

▶️ Exécution
Le programme s’utilise ainsi :

sh
Copier le code
./push_swap <liste d'entiers>
Exemple :

sh
Copier le code
./push_swap 4 67 3 87 23
Le programme affiche sur la sortie standard la suite minimale (ou optimisée) d’instructions nécessaires pour trier la pile A.

❗ Erreurs gérées
Valeur non entière

Overflow / underflow d’un int

Doublons

Aucun argument

Espaces malformés dans les arguments multiples

En cas d’erreur, le programme affiche :

Error
📚 Resources
Voici quelques ressources utiles pour comprendre les concepts clés du projet :

Documentation & Articles
Documentation sur les listes chaînées (ex. GeeksforGeeks)

Articles sur les algorithmes de tri (quicksort, insertion sort, radix sort…)

Concepts de complexité algorithmique

Discussions sur StackOverflow autour de la manipulation de piles et d’algorithmes de tri.

Tutoriels et contenus liés au projet
Explications du sujet sur des blogs d’étudiants 42

Vidéos YouTube présentant la logique du projet et les stratégies populaires (radix sort, approach “chunking”, etc.)

GitHub de projets open-source similaires pour s’inspirer des structures (sans copier !)

🧠 Utilisation de l’IA dans ce projet
L’IA a été utilisée de manière limitée et contrôlée, conformément aux règles de l’école 42.
Voici précisément comment :

Aide à la compréhension du sujet : clarification de certaines consignes du projet.

Recherche d’informations : explications d’algorithmes de tri et comparaison de stratégies.

Rediger ce README.md.
