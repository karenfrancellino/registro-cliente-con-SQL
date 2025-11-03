#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

class Cliente{
    private:
        string nombre;
        string apellidos;
        int edad;

    public:
        Cliente() : nombre(""), apellidos(""), edad(0) {}
        string obterDatos(){
            return "Nombre: " + nombre + "\n" + "Apellidos: " + apellidos + "\n" + "edad: " + to_string(edad) + " años" + "\n";
        }
        Cliente(string nombre, string apellidos, int edad){
            this->nombre = nombre;
            this->apellidos = apellidos;
            this->edad = edad;
        }
};

int main(){
    string nombre, apellidos;
    int edad;
    
    cout << "Introduzca el nombre del cliente" "\n";
    getline (cin, nombre);

    cout << "Introduzca los apellidos del cliente" "\n";
    getline (cin, apellidos);

    cout << "Introduzca la edad del cliente" "\n";
    cin >> edad;
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (edad > 100){
        cout << "La edad deve ser menor que 100 años";
    } else {
        Cliente cliente(nombre, apellidos, edad);
        ofstream arquivo("cliente.txt", ios::app);
        if (arquivo.is_open()){
            arquivo << cliente.obterDatos() << endl;
            cout << "Los datos del cliente se han añadido al archivo cliente.txt." << endl;
            arquivo.close();
        } else {
            cout << "Error: No se pudo abrir el archivo cliente.txt." << endl;
        }
    }
return 0;
}