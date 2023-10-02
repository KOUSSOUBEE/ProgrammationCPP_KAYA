#include <iostream>
#include <list>
// Définition de la classe Personne
class Personne {
public:
    std::string nomP;
    std::string prenomP;
    int age;

    Personne(){
        nomP="nom";
        prenomP="prenom";
        age=0;
    }
    
    Personne(std::string n, std::string p, int a) {
        nomP=n;
        prenomP=p;
        age=a;
    }
};  

int main() {
    // Création d'une liste de Personnes
    std::list<Personne> listeDePersonnes;
    // Ajout d'objets Personne à la liste
    std::string n,p;
    int a,c=1;
    std::cout << "Saisie de la liste"<<  std::endl;
    do
    {
        std::cout << "Entrer nom: " ;
        std::cin >>n ;
        std::cout << "Entrer prenom: " ;
        std::cin >>p ;
        std::cout << "Entrer age: " ;
        std::cin >>a ;
        listeDePersonnes.push_back(Personne(n,p, a));
        std::cout << "Voulez vous continuer?"<<  std::endl;
        std::cout << "1 pour oui"<<  std::endl;
        std::cout << "0 pour non"<<  std::endl;
        std::cin >>c ;
    } while (c==1);
    
    listeDePersonnes.push_back(Personne("KABORE","Alice", 25));
    // Ajoute au début de la liste
    // listeDePersonnes.push_front(Personne("Alice", 25));  
     
    listeDePersonnes.push_back(Personne("ZONGO","Bob", 30));
    listeDePersonnes.push_back(Personne("NEYA","Charlie", 22));
    // Affichage de la liste d'origine
    std::cout << "Liste d'origine : " << std::endl;
    for (const Personne& p : listeDePersonnes) {
        std::cout << "Nom: " << p.nomP << ", Age: " << p.age << std::endl;
    }
    // Modification d'un objet dans la liste
    for (Personne& p : listeDePersonnes) {
        if (p.nomP == "Bob") {
            p.age = 31; // Modification de l'âge de Bob
            break; // Sortez de la boucle après la modification
        }
    }
    // Affichage de la liste mise à jour
    std::cout << "\nListe mise à jour : " << std::endl;
    for (const Personne& p : listeDePersonnes) {
        std::cout << "Nom: " << p.nomP << ", Age: " << p.age << std::endl;
    }
    // Suppression d'un objet de la liste
    std::string nomASupprimer = "Charlie";
    auto it = listeDePersonnes.begin();
    while (it != listeDePersonnes.end()) {
        if (it->nomP == nomASupprimer) {
            it = listeDePersonnes.erase(it); // Suppression de l'objet
        } else {
            ++it;
        }
    }
    // Affichage de la liste après suppression
    std::cout << "\nListe après suppression : " << std::endl;
    for (const Personne& p : listeDePersonnes) {
        std::cout << "Nom: " << p.nomP << ", Age: " << p.age << std::endl;
    }

    return 0;
}
