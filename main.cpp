#include <iostream> // Profe, esto es una libreria para usar cout y cin
#include <string>   // Profe, esto es una libreria para usar textos digamos los strings
#include <iomanip>  // Profe, esto lo agregue para alinear columnas con setw, o ordenar bien a la hora de dar aprobados y reporbados, con sus datos
#include <vector>   // Profe, esto lo agregue para usar vectores dinamicos
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
   
        float sumanotasUNA = 0;
        int numeroexamenUNA = 0;

        while (numeroexamenUNA < 5) {
            while (true) {
                cout<< endl;
                cout << "Ingrese nota del examen #" << (numeroexamenUNA + 1) << " (0-100): ";
                cin >> notasUNA[numeroestudianteUNA][numeroexamenUNA];

                if (cin.fail() || notasUNA[numeroestudianteUNA][numeroexamenUNA] < 0 || notasUNA[numeroestudianteUNA][numeroexamenUNA] > 100) {
                    setColor(4,0);
                    cout<< endl;
                    cout << "Error, la nota esta fuera de rango de, recuerda que es de 0 a 100, y es numero, no se permiten letras \n";
                    setColor(7,0);
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else {
                    break;
                }
            }

            sumanotasUNA += notasUNA[numeroestudianteUNA][numeroexamenUNA];
            numeroexamenUNA++;
        }

        promediosUNA[numeroestudianteUNA] = sumanotasUNA / 5;

        if (promediosUNA[numeroestudianteUNA] >= 70) {
            estadosUNA[numeroestudianteUNA] = "Aprobado";
        } else {
            estadosUNA[numeroestudianteUNA] = "Reprobado";
        }

        numeroestudianteUNA++;
        cin.ignore();
    }

    cout << fixed << setprecision(2);
    setColor(2,0);
    cout << "\n---------------------------APROBADOS-----------------------------\n";
    cout << left << setw(30) << "Nombre completo"
         << setw(10) << "Ciclo"
         << setw(15) << "Cedula"
         << setw(10) << " Promedio" << endl;
    cout << "-----------------------------------------------------------------\n";
    setColor(7,0);
    int indiceaprobadoUNA = 0;

    while (indiceaprobadoUNA < cantidaddeestudiantesUNA) {
        if (estadosUNA[indiceaprobadoUNA] == "Aprobado") {
            cout << left
                 << setw(30) << (nombresUNA[indiceaprobadoUNA] + " " + primerApellidoUNA[indiceaprobadoUNA] + " " + segundoApellidoUNA[indiceaprobadoUNA])
                 << setw(10) << ciclosUNA[indiceaprobadoUNA]
                 << setw(15) << cedulasUNA[indiceaprobadoUNA]
                 << setw(10) << promediosUNA[indiceaprobadoUNA] << endl;
        }
        indiceaprobadoUNA++;
    }
    setColor(4,0);
    cout << "\n---------------------------REPROBADOS-----------------------------\n";
    cout << left << setw(30) << "Nombre completo"
         << setw(10) << "Ciclo"
         << setw(15) << "Cedula"
         << setw(10) << " Promedio" << endl;
    cout << "------------------------------------------------------------------\n";
    setColor(7,0);
    cout<< endl;
    int indicereprobadoUNA = 0;

    while (indicereprobadoUNA < cantidaddeestudiantesUNA) {
        if (estadosUNA[indicereprobadoUNA] == "Reprobado") {
            cout << left
                // Este "setw", es lo de la libreria de alinear todo
                 << setw(30) << (nombresUNA[indicereprobadoUNA] + " " + primerApellidoUNA[indicereprobadoUNA] + " " + segundoApellidoUNA[indicereprobadoUNA])
                 << setw(10) << ciclosUNA[indicereprobadoUNA]
                 << setw(15) << cedulasUNA[indicereprobadoUNA]
                 << setw(10) << promediosUNA[indicereprobadoUNA] << endl;
        }
        indicereprobadoUNA++;
    }

    return 0;
}