Lien vers le diapo drive : https://drive.google.com/open?id=1kZmobaLUInqyEL9ylhOZvzZrMQTL8v9vPvg8C6GTepw

# Mytho structure du tp :

L'idée de Ghislain (faire comme le cours d'angular et structurer les exos comme les branches d'un dépôt git) s'adapte plutôt pas mal à notre tp, perso ça me paraît pas mal de partir sur cette structure, faudra voir

Plan (provisoire) du tp : 

- Initialisation de la fenêtre SDL (explication du contexte) -> On donne un code à trous

- Initialisation OpenGL -> On donne le code

- Dessiner un triangle -> On leur dit comment faire puis ils se débrouillent (avec la doc [Quelle doc ? lolilol] ) / Celle-ci : https://www.khronos.org/registry/OpenGL-Refpages/gl4/ 
on leur donne les noms des fonctions et ils regardent comment on les utilise

- Dessiner plus de triangles (un exercice où ils doivent reproduire une capture d'écran) -> Ils se débrouillent tous seuls (trouver ce qu'ils doivent changer)

- Structurer en classes (avec headers etc) -> On leur donne les headers et ils doivent remettre ce qu'ils ont fait avant dans les corps des fonctions ? //PAS SUR C'est pas idiot, au même titre que dans le tuto openclassroom, ça pose une structure pour la suite. / Ué mais ça fait un peu "remplissage" non ? Ca peut être assez rapide. Mais mettons que c'est optionnel

- Shaders ! -> On explique en gros et on leur file le code des shaders, et aussi comment les appeler je pense

- Exo rapide avec le shader des couleurs -> On explique et ils doivent trouver comment les envoyer au programme avec la même fonction que pour les vertices (+ explication interpolation)

- Explication des matrices de projection et de transformation (projection et modelView) + Exos matriciels (translation etc.) ??? (Là je suis vraient pas sûr de vouloir leur infliger ça xD) Moi non plus mais dans le concept c'est assez interessant.

- 3D : fonction perspective de glm : Initialisation des matrices -> Pas sûr qu'on puisse en faire un exo ? (peut être avec la réinitialisation de la matrice modelView : ils essaient et ça marche pas, faut qu'ils comprennent qu'il faut réinitialiser la matrice)

- Mise en 3d des triangles et envoi au shader 3D -> On donne tout fait, ou alors mini exo avec le paramètre de la fonction expliqué (doc) et ils remplissent

- Exo translation et rotation aec les fonctions glm -> Capture d'écran et ils se débrouillent

- **A continuer**


-Exo bonus si ils sont trop bons : Faire bouger des objets sans toucher aux coordonnées. (Avec des push et des pop)

