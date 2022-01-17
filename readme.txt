MATRIX

Matrix(std::vector<int> vec, int rep)
-> Il a été décidé d'utiliser un simple vecteur plutôt qu'un vecteur
de vecteur par simplicité et par désir de rendre le code applicable
à des matrices non carré

readFromFile et fromString (static)
-> Ces fonctions ont été rendues statiques, car il était désagréable
de faire un constructeur pour chacune de ces manières plutôt que
d'invoquer un seul constructeur avec les données extraites de ces
différentes manières.

----------------
WAVE

Il a été ajouté la fonction size(), ainsi que les deux opérateurs
(accès modification et accès constant) d'accès [], pour simplifier
le développement.

----------------
VECTOR

Pareillement, ont été ajoutées push_back(), size() et les deux []

----------------
FUNC
 
Wave addHiddenMsg(Wave& wave, const string &hiddenMsg, int cleMsg)

la fonction remplace un caractère tout les cleMsg par un caractère du message caché

void Wave::readHiddenMsg(const Wave wave,const int key, const int sizeMsg)const

decrypte le message caché en utilisant la clé de decryptage (key = cleMsg) puis l'affiche


















