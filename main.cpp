//Tati
#include <iostream> // Profe, esto es una libreria para usar cout y cin
#include <string>   // Profe, esto es una libreria para usar textos digamos los strings
#include <vector>   // Profe, esto lo agregue para usar vectores dinamicos
#include <iomanip>  // Profe, esto lo agregue para alinear columnas con setw, o ordenar bien a la hora de dar aprobados y reporbados, con sus datos
#include <cctype>   // Profe, esto es para usar isalpha e isdigit o lo de ordenar bien 

using namespace std;

// Esto es una funcion para validar que un string tenga solo letras y no tenga espacios
bool soloLetrasSinEspaciosUNA(const string& textoUNA) {
    for (char letraUNA : textoUNA) {
        if (!isalpha(letraUNA)) return false;  // Si hay algo que no sea letra, falso
    }
    if (textoUNA.find(' ') != string::npos) return false; // Si hay espacios, falso
    return true;
}

// Funcion para validar que un string tenga solo digitos
bool soloDigitosUNA(const string& textoUNA) {
    for (char caracterUNA : textoUNA) {
        if (!isdigit(caracterUNA)) return false;
    }
    return true;
}

int main() {
    // Aca creamos los vectores para almacenar datos de los estudiantes
    vector<string> nombresUNA;
    vector<string> primerApellidoUNA;
    vector<string> segundoApellidoUNA;
    vector<int> ciclosUNA;
    vector<int> cedulasUNA;
    vector<vector<float>> notasUNA;
    vector<float> promediosUNA;
    vector<string> estadosUNA;
    // Ahora le dimos tamaño a los vectores segun la cantidad de estudiantes

    nombresUNA.resize(cantidaddeestudiantesUNA);
    primerApellidoUNA.resize(cantidaddeestudiantesUNA);
    segundoApellidoUNA.resize(cantidaddeestudiantesUNA);
    ciclosUNA.resize(cantidaddeestudiantesUNA);
    cedulasUNA.resize(cantidaddeestudiantesUNA);
    notasUNA.resize(cantidaddeestudiantesUNA, vector<float>(5)); //Aca son las 5 notas por estudiante
    promediosUNA.resize(cantidaddeestudiantesUNA);
    estadosUNA.resize(cantidaddeestudiantesUNA);

    int numeroestudianteUNA = 0;
    cin.ignore(); // Esto es para limpiar el buffer

    while (numeroestudianteUNA < cantidaddeestudiantesUNA) {
        cout << "\n-------------- Estudiante #" << (numeroestudianteUNA + 1) << " --------------\n";
        
        while (true) {
            cout<< endl;
            cout<<"------------------------------------------------------------\n";
            cout << "Ingrese el primer nombre:";
            getline(cin, nombresUNA[numeroestudianteUNA]);
            if (!soloLetrasSinEspaciosUNA(nombresUNA[numeroestudianteUNA])) {
                cout<< endl;
                cout << "Error, el nombre debe contener solo letras y no puede tener espacios\n";
            } else {
                break;
            }
        }
        while (true) {
            cout<< endl;
            cout << "Ingrese el primer apellido:";
            getline(cin, primerApellidoUNA[numeroestudianteUNA]);
            if (!soloLetrasSinEspaciosUNA(primerApellidoUNA[numeroestudianteUNA])) {
                cout<< endl;
                cout << "Error, el primer apellido debe contener solo letras y no puede tener espacios\n";
            } else {
                break;
            }
        }
        while (true) {

            cout<< endl;
            cout << "Ingrese el segundo apellido:";
            getline(cin, segundoApellidoUNA[numeroestudianteUNA]);
            if (!soloLetrasSinEspaciosUNA(segundoApellidoUNA[numeroestudianteUNA])) {
                
                cout<< endl;
                cout << "Error, el segundo apellido debe contener solo letras y no puede tener espacios\n";
               
            } else {
                break;
            }
        }

        while (true) {
            cout<< endl;
            cout << "Ingrese el ciclo de estudio en la nacional (entre 1 y 8): ";
            cin >> ciclosUNA[numeroestudianteUNA];

            if (cin.fail() || ciclosUNA[numeroestudianteUNA] < 1 || ciclosUNA[numeroestudianteUNA] > 8) {
                cout<< endl;
                cout << "Error, en la UNA no existe este ciclo, solo del 1 al 8\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                break;
            }
        }
        while (true) {
            string cedulaTemporalUNA;
            cout<< endl;
            cout << "Ingrese numero de cedula (9 digitos):";
            cin >> cedulaTemporalUNA;
            cout<<"------------------------------------------------------------";

            if (!soloDigitosUNA(cedulaTemporalUNA) || cedulaTemporalUNA.length() != 9) {
                cout<< endl;
                cout << "Error, la cedula debe contener exactamente 9 digitos y numericos \n";
                
            } else {
                cedulasUNA[numeroestudianteUNA] = stoi(cedulaTemporalUNA);
                break;
            }
        }
    return 0;
}