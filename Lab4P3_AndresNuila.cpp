#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
using namespace std;
class Jugador
{
    friend class Juego;
    friend int main();

private:
    string nombre;
    vector<string> baraja;
    int puntuacion;

public:
    Jugador();
    Jugador(string);
};

Jugador::Jugador(string _nombre)
{
    nombre = _nombre;
}

class Juego
{
private:
public:
    static int jugar(vector<string>, Jugador);
};

int limiteBusqueda = 52;

int Juego::jugar(vector<string> _baraja, Jugador _player)
{
    _player.puntuacion = 0;
    int indCartaRepartir = 1 + rand() % (limiteBusqueda + 1);
    _player.baraja.push_back(_baraja.at(indCartaRepartir));
    _baraja.erase(_baraja.begin() + indCartaRepartir);
    limiteBusqueda--;
    _player.puntuacion = 0;
    for (int i = 0; i < _player.baraja.size(); i++)
    {
        int cartaAux = _player.baraja.at(i).size();
        if (cartaAux == 4)
        {
            string valorDeCarta = _player.baraja.at(i).substr(0, 1);
            if (valorDeCarta == "A")
            {
                _player.puntuacion += 1;
            }
            else if (valorDeCarta == "J")
            {
                _player.puntuacion += 11;
            }
            else if (valorDeCarta == "Q")
            {
                _player.puntuacion += 12;
            }
            else if (valorDeCarta == "K")
            {
                _player.puntuacion += 13;
            }
            else
            {
                _player.puntuacion += stoi(valorDeCarta);
            }
        }
        else if (cartaAux == 5)
        {
            _player.puntuacion += 10;
        }
    }
    if (_player.nombre.at(1) != *"b")
    {
        for (int i = 0; i < _player.baraja.size(); i++)
        {
            cout << _player.baraja.at(i) << " ";
        }
    }
    return _player.puntuacion;
}

static vector<string> crearBaraja(vector<string> _baraja)
{
    string carta = "";
    for (int i = 1; i <= 52; i++)
    {
        if (i == 1)
        {
            carta = "A <>";
            _baraja.push_back(carta);
        }
        else if (i >= 2 && i <= 10)
        {
            carta = to_string(i) + "<>";
            _baraja.push_back(carta);
        }
        else if (i == 11)
        {
            carta = "J<>";
            _baraja.push_back(carta);
        }
        else if (i == 12)
        {
            carta = "Q<>";
            _baraja.push_back(carta);
        }
        else if (i == 13)
        {
            carta = "K<>";
            _baraja.push_back(carta);
        }
        else if (i == 14)
        {
            carta = "A<3";
            _baraja.push_back(carta);
        }
        else if (i >= 15 && i <= 23)
        {
            carta = to_string(i - 13) + "<3";
            _baraja.push_back(carta);
        }
        else if (i == 24)
        {
            carta = "J<3";
            _baraja.push_back(carta);
        }
        else if (i == 25)
        {
            carta = "Q<3";
            _baraja.push_back(carta);
        }
        else if (i == 26)
        {
            carta = "K<3";
            _baraja.push_back(carta);
        }
        else if (i == 27)
        {
            carta = "AO?";
            _baraja.push_back(carta);
        }
        else if (i >= 28 && i <= 36)
        {
            carta = to_string(i - 26) + "O?";
            _baraja.push_back(carta);
        }
        else if (i == 37)
        {
            carta = "JO?";
            _baraja.push_back(carta);
        }
        else if (i == 38)
        {
            carta = "QO?";
            _baraja.push_back(carta);
        }
        else if (i == 39)
        {
            carta = "KO?";
            _baraja.push_back(carta);
        }
        else if (i == 40)
        {
            carta = "A-#";
            _baraja.push_back(carta);
        }
        else if (i >= 40 && i <= 49)
        {
            carta = to_string(i - 39) + "-#";
            _baraja.push_back(carta);
        }
        else if (i == 50)
        {
            carta = "J-#";
            _baraja.push_back(carta);
        }
        else if (i == 51)
        {
            carta = "Q-#";
            _baraja.push_back(carta);
        }
        else if (i == 52)
        {
            carta = "K-#";
            _baraja.push_back(carta);
        }
    }
    return _baraja;
}

int main()
{
    srand((unsigned int)time(NULL));
    int opcion;
    char resp = 's';
    while (resp == 's')
    {
        cout << "1. JUGAR\n2. SALIR\nSeleccione una opcion" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            int jugadores = 0;
            int puntajeJugadorPrincipal = 0;
            int puntajeBots = 0;
            string nombre;
            vector<string> baraja;
            baraja = crearBaraja(baraja);
            cout << "Ingrese el numero de jugadores";
            cin >> jugadores;
            cout << "Ingrese su nombre";
            cin >> nombre;
            Jugador principal(nombre);
            vector<Jugador> bots;
            for (int i = 0; i < jugadores - 1; i++)
            {
                Jugador bot("Bot-" + to_string(i + 1));
                bots.push_back(bot);
            }
            for (int i = 0; i < 2; i++)
            {
                Juego::jugar(baraja, principal);
            }
            for (int i = 0; i < bots.size(); i++)
            {
                for (int j = 0; j < 1; j++)
                {
                    Juego::jugar(baraja, bots.at(i));
                }
            }
            int repeticion = 0;
            cout << "Desea tomar otra carta? 1.SI 2.NO" << endl;
            cin >> repeticion;
            while (repeticion == 1)
            {
                Juego::jugar(baraja, principal);
                for (int i = 0; i < bots.size(); i++)
                {
                    Juego::jugar(baraja, bots.at(i));
                }
                cout << "Desea tomar otra carta? 1.SI 2.NO" << endl;
                cin >> repeticion;
            }
            puntajeJugadorPrincipal = principal.puntuacion;
            cout << principal.nombre << " " << puntajeJugadorPrincipal << endl;
            for (int i = 0; i < bots.size(); i++)
            {
                puntajeBots = bots.at(i).puntuacion;
                cout << bots.at(i).nombre << " " << puntajeBots << endl;
            }
        }
        break;
        case 2:
        {
            resp = 'n';
        }
        break;
        }
    }
}
