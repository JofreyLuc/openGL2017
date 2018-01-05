Lien vers le dossier drive : https://drive.google.com/drive/folders/1G_bVH8AiEsM1fX6PCPQL2Yp4NwuD4uxG?usp=sharing
Lien vers les librairies : https://drive.google.com/file/d/1bu1eOr1hf9UCoL1Eox3gWI0SnGHqK9pn/view?usp=sharing

# Mytho structure du tp :

L'idée de Ghislain (faire comme le cours d'angular et structurer les exos comme les branches d'un dépôt git) s'adapte plutôt pas mal à notre tp, perso ça me paraît pas mal de partir sur cette structure, faudra voir -> Idée vraiment cool. Comme ça ceux qui sont perdus/ont la flemme peuvent passer à l'étape d'après sans avoir de retard. Et comme ça on peut timer notre tp comme on le veut

Plan (provisoire) du tp : 

- Initialisation de la fenêtre SDL (explication du contexte) -> On donne un code à trous
- Initialisation OpenGL -> On donne le code
On donne tout ensemble ? Je pensais qu'on pouvait leur faire faire un petit quelque chose sur l'initialisation sdl, c'est pas de l'opengl mais bon, ça peut servir (genre la boucle principale, etc.)
Je pense pas que directement commencer par un code à trous pour l'initialisation de la fenêtre est un bon début. Faudrait justement leur donner un main qui fonctionne et  voir si ça marche chez tout le monde. Bah le truc c'est que l'init SDL c'est pas vraiment de l'openGl, c'est un peu accessoire mais c'est quand même important, ça dit ce que ne fait pas openGl. Après on peut toujours commencer par un main vide

- Dessiner un triangle -> On leur dit comment faire puis ils se débrouillent (avec la doc [Quelle doc ? lolilol] ) / Celle-ci : https://www.khronos.org/registry/OpenGL-Refpages/gl4/ 
on leur donne les noms des fonctions et ils regardent comment on les utilise
On pourrait commencer par un carré comme ça on leur montre que tout se fait à partir de triangle justement. Ouais, ce genre de choses

- Dessiner plus de triangles (un exercice où ils doivent reproduire une capture d'écran) -> Ils se débrouillent tous seuls (trouver ce qu'ils doivent changer)
Plutôt leur demander de dessiner une forme que de reproduire une capture quand on pense à l'incident qu'il y a eu avec la carte graphique du pc xD Certes x) On pourra tester lundi merdi de toute façon

- Structurer en classes (avec headers etc) -> On leur donne les headers et ils doivent remettre ce qu'ils ont fait avant dans les corps des fonctions ? //PAS SUR C'est pas idiot, au même titre que dans le tuto openclassroom, ça pose une structure pour la suite. / Ué mais ça fait un peu "remplissage" non ? Ca peut être assez rapide. Mais mettons que c'est optionnel
Pourquoi ne pas leur donner un code structuré dès le début ? Je pense que c'est plus clair si on fait tout dans une seule fonction au début perso
A la rigueur, autant leur donner la structure, cela fera un exo en moins.

- Shaders ! -> On explique en gros et on leur file le code des shaders, et aussi comment les appeler je pense

- Exo rapide avec le shader des couleurs -> On explique et ils doivent trouver comment les envoyer au programme avec la même fonction que pour les vertices (+ explication interpolation)

-Exo rapide sur les textures dans le même esprit que celui sur les couleurs ? Ouais, c'est vrai qu'on peut mettre les textures là, ça  plus de ses (je suivais le tuto openclassroom et c'ets vrai qu'ils les mettent tard)

- Explication des matrices de projection et de transformation (projection et modelView) + Exos matriciels (translation etc.) ??? (Là je suis vraient pas sûr de vouloir leur infliger ça xD) Moi non plus mais dans le concept c'est assez interessant.
On peut leur expliquer que tout se fait avec les matrices mais il n'y a pas d'exos de transformation avec des matrices dans le tuto, il le font avec glm justement il me semble.
Sisi, il y a des exos théoriques, c'est de ceux là que je parlais :3
Je préfère l'explication sans la mise en pratique.

- 3D : fonction perspective de glm : Initialisation des matrices -> Pas sûr qu'on puisse en faire un exo ? (peut être avec la réinitialisation de la matrice modelView : ils essaient et ça marche pas, faut qu'ils comprennent qu'il faut réinitialiser la matrice)
On peut peut-être fusionner les 2 exos.
- Mise en 3d des triangles (ou carré) et envoi au shader 3D -> On donne tout fait, ou alors mini exo avec le paramètre de la fonction expliqué (doc) et ils remplissent

-Exo rapide de texturage de la forme 3D ?

- Exo translation et rotation aec les fonctions glm -> Capture d'écran et ils se débrouillent

-Exo bonus si ils sont trop bons : Faire bouger des objets sans toucher aux coordonnées. (Avec des push et des pop)
Pas sur que l'on puisse leur donner ça à faire sachant que d'après nos précedentes reflexions, on ne maitrise pas ce concept.

Proposition d'exo Bonus : on peut leur demander de dessiner un objet 3D plus complexe (exemple : une maison) pour voir s'ils ont bien assimilé ce qu'on leur a montrer.

IL Y A BEAUCOUP TROP D'EXERCICES !
8 Exercices + celui bonus c'est beaucoup trop.
Oubliez pas qu'en Qt on as mis 2h à faire un rectangle qui s'étire.
On pourrait arguer que c'était un tp de merde :S
Le truc c'est que c'est pour beaucoup des exos assez courts (genre changer une ligne ou deux), qui sont timables sur du 10/15 minutes, un peu au format des tp d'angular

