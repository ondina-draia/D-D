# ReadMe du projet Dongeons & Dragons 5: Creation de feuille de personnage 
# Nom de l'application compilée: DDFeuillePerso
# Auteur: Draia-Nicolau Ondina

### Lancement de l'application

## 1) Installer les updates, au cas ou
```
sudo apt-get update 
```

## 2) Installer le compilateur Gnu g++ sachant qu'il va falloir compiler le code
```
sudo apt-get install g++
```

## 3) Installer gtkmm qui servira pour l'interface graphique de notre application de creation de feuille de personnage Dungeons et Dragons
```
sudo apt-get install libgtkmm-3.0-dev 
```

## 4) Lancer la commande make afin de lancer le makefile qui va permettre de compiler l'application, dans le dossier ou se trouvent les
## fichiers de l'application 
```
make
```

## 5) Lancer l'application avec le code
```
./DDFeuillePerso
```

# Fonctionnement de l'application

### Il est important de remplir tous les encadrés et faire ses choix d'armure / niveau / sexe, etc dans les menus deroulants afin d'avoir une fiche personnage complete

### Au milieu a gauche, il existe un menu deroulant avec les scores d'abilite possibles pour le personnage cree. Ce sont des scores tires au hasard suivant les regles du jeu.

### Ca peut etre amusant de jouer avec le choix de sexe, race et classe etant donne que l'image du personnage afiche dans la fenetre d'affichage du personnage changera en fonction de ces 3 criteres


# Presentation des fichiers composant l'application

# main_Projet_DD_Draia-Nicolau_Ondina.cpp :

Le fichier main de l'application. Il permet d'appeller les differentes classes et de controler le bon deroulement de l'application

# Race.cpp

Contient des fonctions qui extraient des informations de Races.html 

# Personnage.cpp

Contient enormement de fonctions: la classe personnage contient:
- un extracteur HTML (Lecture Html)
- un recuperateur specifique de donnees par rapport a ce qui a été extrait des fichiers html
- une fonction qui enleve les balises du html
- une fonction qui calcule les ability score et les envoie dans la fenetre
- une fonction print qui print des vecteurs proprement
- une fonction qui print des vecteurs string propremenet
- une fonction qui split des strings 
- une fonction de recuperation d'armes de classes

# Classe.cpp

Contient des fonctions qui recuperent des informations relatives aux classes

# IntGraph.cpp

Le fichier qui contient la classe Fenetre qui gere la fenetre mere de l'application.
- classe Fenetre avec tous les boutons, combobox et labels
- une fonction on button clicked qui cree la fenetre fille et envoie les informations vers cette fenetre fille
- 3 fonctions d'affichage des donnees entrees en live sur le terminal on_combo_changed, on_entry_activate, on_entry_focus_event
- une fonction ajout_description qui envoie la description d'une classe vers la fenetre fille
- une fonction qui set les ability points possibles dans une combobox de la fenetre mere

# win_fille

- gere la classe win_fille qui est la fenetre fille ou est affichee la feuille de personnage
- elle contient les conteneurs labels et les images qui sont definis dans la fenetre fille et qui sont remplis par la fenetre mere lors de la creation de celle ci
- une fonction on button clicked qui permet de fermer la fenetre quand on clicke sur le bouton fermer

# DD.h

- fichier qui definit tous les attributs et methodes de toutes les classes presentees 