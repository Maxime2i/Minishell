# Minishell

Ce projet consiste à recréer votre propre shell, en prenant bash comme référence. C'est le premier projet de groupe.


## Qu’est-ce que Bash et comment ça marche ?

Le shell est un programme que l'utilisateur peut utiliser pour interagir avec les services d'un système d'exploitation. Bash est le shell GNU et est actuellement le programme shell le plus courant. Nous avons relevé le défi de recréer bash très littéralement. La première chose que nous avons faite a donc été d'apprendre comment bash fonctionne réellement à l'aide de cet article. Essentiellement, il décompose le processus en 4 étapes : lexer → analyseur → expandeur → exécuteur, que nous avons répliqué dans notre projet.


## 3 etapes :

- Initialisation :
  
     + Les éléments de la structure qui sont globaux : Le code d'état + Les variables d'environnement.
     + Sauvegarde de stdin/stdout à l'aide de dup
     + Lecture de la commande d'entrée utilisateur à l'aide de la fonction readline. homme lisant la ligne
    
- Analyse :
  
     + Construire une liste doublement chaînée contenant la commande en la spécifiant sous forme de jetons en utilisant la grammaire du shell.
     + Lors de la tokenisation de la commande, je vérifie les erreurs de syntaxe.
     + Ensuite, j'ai réorganisé le cmd en utilisant l'algorithme Shunting yard qui m'a permis de construire facilement l'arbre de manière récursive.
     + Construire l'arbre.
  
- Exécution :
  
     + Exécuter l'arbre de manière récursive de bas en haut et de gauche à droite.
     + Si le jeton est et/ou/pipe. (Cela sera expliqué plus tard)
     + sinon, le jeton serait une commande. 1. développer $ 2. diviser la cmd par des espaces hors guillemets -- 3. développer le caractère générique 4. éliminer les guillemets principaux 5. gérer les redirections 4. vérifier si la cmd est une commande intégrée -- 5. si ce n'est pas une commande intégrée, je fork puis exécutez le cmd en utilisant execve.


## a faire

   * Afficher une invite en attendant une nouvelle commande.
   * Avoir un historique de travail.
   * Recherchez et lancez les exécutables (en utilisant la variable PATH ou un chemin absolu).
   * Gérez les guillemets ' (simples) et " (doubles) comme dans bash.
   * Implémentez des redirections telles que :
       * < rediriger l'entrée.
       * \> rediriger la sortie.
       * << heredoc (n'affecte pas l'historique).
       * \>> rediriger la sortie en mode ajout.
   * Mettre en œuvre | (pipe).
   * Gérer les variables d'environnement.
   * Gérer $ ?.
   * ctrl-C, ctrl-D et ctrl-\ devraient se comporter comme dans bash.
   * Recréez les éléments intégrés suivants :
       * echo avec l'option -n.
       * cd avec seulement un chemin relatif ou absolu.
       * pwd (pas de flag).
       * export (pas de flag).
       * unset (pas de flag).
       * env (pas d'indicateurs ni d'arguments).
       * exit (pas de flag).
         
         
## Builtins :

Il nous a été demandé d'implémenter quelques éléments builtins de base à l'aide de certaines fonctions :

|Description |builtin| Options| Paramètres| Fonctions utiles|
|:----:|:-----|:-----:|:-----:|:----:|
|echo| Imprime les arguments séparés par un espace suivi d'une nouvelle ligne|-n |✔️ |write|
|cd| Modifie le répertoire de travail actuel, mettant à jour PWD et OLDPWD |❌ |✔️ |chdir|
|pwd| Imprime le répertoire de travail actuel |❌ |❌ |getcwd|
|env |Environnement d'impression |❌| ❌ |écrire|
|export| Ajoute/remplace une variable dans l'environnement |❌| ✔️ |❌|
|unset| Supprime la variable de l'environnement| ❌ |✔️ |❌|

