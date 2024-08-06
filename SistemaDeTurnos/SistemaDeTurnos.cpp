#include <iostream>

class Pokemon {
    std::string nombre;
    int ataque;
    int vida;

public:
    Pokemon(std::string nombre, int vida, int ataque) {
        this->nombre = nombre;
        this->vida = vida;
        this->ataque = ataque;
    }

    std::string getNombre() { return this->nombre; };
    void setNombre(std::string nombre) { this->nombre = nombre; };

    int getAtaque() { return this->ataque; };
    void setAtaque(int ataque) { this->ataque = ataque; };

    int getVida() { return this->vida; };
    void setVida(int vida) { this->vida = vida; }

    int araniazo() {
        int potencia = 40;
        int danio = 0;

        danio = potencia / ataque;
        return danio;
    }

    int tackle() {
        int potencia = 30;
        int danio = 0;
        danio = potencia / ataque;
        return danio;
    }

};

void showStatus(Pokemon aliado, Pokemon rival) {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "---------- Inicia la batalla ------------" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;


    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "---------- Status ------------" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "---- Pokemon Propio ----" << std::endl << std::endl;

    std::cout << "El nombre del pokemon es: " << aliado.getNombre() << std::endl;
    std::cout << "El vida del pokemon es: " << aliado.getVida() << std::endl;
    std::cout << "El ataque del pokemon es: " << aliado.getAtaque() << std::endl;

    std::cout << "---- Pokemon Rival ----" << std::endl << std::endl;

    std::cout << "El nombre del pokemon es: " << rival.getNombre() << std::endl;
    std::cout << "El vida del pokemon es: " << rival.getVida() << std::endl;
    std::cout << "El ataque del pokemon es: " << rival.getAtaque() << std::endl;
}

void myTurn(Pokemon& atacante, Pokemon& defensor) {
    bool turn = false;
    int opcion = 0;

    do {

        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "---------- Turno del pokemon aliado ------------" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;

        std::cout << "" << std::endl;
        std::cout << "" << std::endl;

        std::cout << atacante.getNombre() << " (Aliado) " << " PS: " << atacante.getVida() << std::endl;
        std::cout << defensor.getNombre() << " (Rival) " << " PS: " << defensor.getVida() << std::endl;


        std::cout << "" << std::endl;
        std::cout << "" << std::endl;

        std::cout << "---- Ataques ----" << std::endl;
        std::cout << "1- Araniazo" << std::endl;
        std::cout << "2- Tackle" << std::endl;

        std::cout << "Introduce una opcion: " << std::endl;

        std::cin >> opcion;

        switch (opcion)
        {

        case 1:
        {
            int vida = 0;
            vida = defensor.getVida() - atacante.araniazo();
            defensor.setVida(vida);

            std::cout << atacante.getNombre() << " uso araniazo" << std::endl;
            turn = true;
            break;
        }
        case 2: 
        {
            int vida = 0;
            vida = defensor.getVida() - atacante.tackle();
            defensor.setVida(vida);

            std::cout << atacante.getNombre() << " uso tackle" << std::endl;
            turn = true;
            break;

        }
        default:
            std::cout << "La opcion ingresada no es valida!";
            break;
        }


    } while (!turn);
}

void rivalTurn(Pokemon& atacante, Pokemon& defensor) {
    int opcion = 0;
    int rango_bajo = 1;
    int rango_alto = 2;

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "---------- Turno del pokemon rival ------------" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;


    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << defensor.getNombre() << " (Aliado) " << " PS: " << defensor.getVida() << std::endl;
    std::cout << atacante.getNombre() << " (Rival) " << " PS: " << atacante.getVida() << std::endl;

    opcion = rango_bajo + std::rand() % (rango_alto - rango_bajo + 1);

    switch (opcion)
    {
    case 1:
    {
        int vida = 0;
        vida = defensor.getVida() - atacante.araniazo();
        defensor.setVida(vida);

        std::cout << atacante.getNombre() << " uso araniazo" << std::endl;
    }
        break;
    case 2:
    {
        int vida = 0;
        vida = defensor.getVida() - atacante.tackle();
        defensor.setVida(vida);

        std::cout << atacante.getNombre() << " uso tackle" << std::endl;
        break;
    }
    default:
        std::cout << "Ups! algo esta mal en la generacion del valor aleatorio del ataque" << std::endl;
        break;
    }


}

bool pokemonDefeated(Pokemon pokemon) {
    if (pokemon.getVida() <= 0) { return true; }

    return false;
}


int main()
{

    Pokemon pikachu("Pikachu", 25, 10);
    Pokemon charmander("Charmander", 25, 11);
    bool endBattle = false;

    showStatus(pikachu,charmander);

    do
    {

        myTurn(pikachu, charmander);

        if (pokemonDefeated(charmander)) {
            std::cout << "El pokemon rival fue derrotado. Tu ganas" << std::endl;
            endBattle = true;
        }
        else {
            rivalTurn(charmander, pikachu);

            if (pokemonDefeated(pikachu)) {
                std::cout << "El pokemon aliado fue derrotado. Tu pierdes!" << std::endl;
                endBattle = true;
            }
        }



    } while (!endBattle);



    return 0;
}

