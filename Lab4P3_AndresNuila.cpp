#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Jugador
{
    friend class Juego;

private:
    string nombre, baraja;
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
    void jugar(string);
};

vector<string> crearBaraja(vector<string> _baraja)
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
            carta = "J <>";
            _baraja.push_back(carta);
        }
        else if (i == 12)
        {
            carta = "Q <>";
            _baraja.push_back(carta);
        }
        else if (i == 13)
        {
            carta = "K <>";
            _baraja.push_back(carta);
        }
        else if (i == 14)
        {
            carta = "A <3";
            _baraja.push_back(carta);
        }
        else if (i >= 15 && i <= 23)
        {
            carta = to_string(i - 13) + "<3";
            _baraja.push_back(carta);
        }
        else if (i == 24)
        {
            carta = "J <3";
            _baraja.push_back(carta);
        }
        else if (i == 25)
        {
            carta = "Q <3";
            _baraja.push_back(carta);
        }
        else if (i == 26)
        {
            carta = "K <3";
            _baraja.push_back(carta);
        }
        else if (i == 27)
        {
            carta = "A O?";
            _baraja.push_back(carta);
        }
        else if (i >= 28 && i <= 36)
        {
            carta = to_string(i - 26) + "O?";
            _baraja.push_back(carta);
        }
        else if (i == 37)
        {
            carta = "J O?";
            _baraja.push_back(carta);
        }
        else if (i == 38)
        {
            carta = "Q O?";
            _baraja.push_back(carta);
        }
        else if (i == 39)
        {
            carta = "K O?";
            _baraja.push_back(carta);
        }
        else if (i == 40)
        {
            carta = "A -#";
            _baraja.push_back(carta);
        }
        else if (i >= 40 && i <= 49)
        {
            carta = to_string(i - 39) + "-#";
            _baraja.push_back(carta);
        }
        else if (i == 50)
        {
            carta = "J -#";
            _baraja.push_back(carta);
        }
        else if (i == 51)
        {
            carta = "Q -#";
            _baraja.push_back(carta);
        }
        else if (i == 52)
        {
            carta = "K -#";
            _baraja.push_back(carta);
        }
    }
    return _baraja;
}

int main()
{
    int opcion;
    char resp = 's';
    while (resp == 's')
    {
        cout << "1. JUGAR\n.2. SALIR\nSeleccione una opcion" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            int jugadores;
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
