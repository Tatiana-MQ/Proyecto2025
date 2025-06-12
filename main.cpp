#include <iostream> // Profe, esto es una libreria para usar cout y cin
#include <string>   // Profe, esto es una libreria para usar textos digamos los strings
#include <vector>   // Profe, esto lo agregue para usar vectores dinamicos
#include <iomanip>  // Profe, esto lo agregue para alinear columnas con setw, o ordenar bien a la hora de dar aprobados y reporbados, con sus datos
#include <cctype>   // Profe, esto es para usar isalpha e isdigit o lo de ordenar bien 
#include <limits>   // Profe, esto es otra libreria estándar de C++ para manejar límites y propiedades de tipos de datos, usada para limpiar el buffer de entrada
#undef max          // Profe, con esto se evita error de linea con max

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

bool soloLetrasSinEspaciosUNA(const string &textoUNA)
{

    for (char letraUNA : textoUNA)
    {
        if (!isalpha(letraUNA))
            return false; // Si hay algo que no sea letra, falso
    }
    if (textoUNA.find(' ') != string::npos)
        return false; // Si hay espacios, falso
    return true;
}

// Funcion para validar que un string tenga solo digitos
bool soloDigitosUNA(const string &textoUNA)
{
    for (char caracterUNA : textoUNA)
    {
        if (!isdigit(caracterUNA))
            return false;
    }
    return true;
}

int main()
{
    int cantidaddeestudiantesUNA = 0;
    int intentosUNA = 0;
    const int maxIntentosUNA = 5;         // Aca es lo de maximo 5 intentos para ingresar bien
    const int limiteestudiantesUNA = 100; // Esto es el limite de estudiantes
    cout << endl;

    // Esto es un ciclo que le da 5 intentos al usuario para meter una cantidad válida de estudiantes
    while (intentosUNA < maxIntentosUNA)
    {
        cout << endl;
        cout << "Ingrese el numero de estudiantes para agregar sus notas (entre 1 y " << limiteestudiantesUNA << "): ";
        cin >> cantidaddeestudiantesUNA;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;

            cout << "Eso no es un numero, intentelo de nuevo" << endl;

            intentosUNA++;
        }
        else if (cantidaddeestudiantesUNA <= 0 || cantidaddeestudiantesUNA > limiteestudiantesUNA)
        {
            cout << endl;
            cout << "El numero debe estar entre 1 y " << limiteestudiantesUNA << endl;
            intentosUNA++;
        }
        else
        {
            char respuestaUNA;
            cout << endl;
            cout << "Esta seguro que desea evaluar " << cantidaddeestudiantesUNA << " estudiantes de la UNA? (S/N): ";
            cin >> respuestaUNA;
            respuestaUNA = toupper(respuestaUNA);

            if (respuestaUNA == 'S')
            {
                break;
            }
            else if (respuestaUNA == 'N')
            {
                continue;
            }
            else
            {
                cout << endl;
                cout << "Error, ingrese un dato valido \n";
                intentosUNA++;
                continue;
            }
        }
        cout << endl;
        cout << "Intento " << intentosUNA << " de " << maxIntentosUNA << endl;
    }

    if (intentosUNA == maxIntentosUNA)
    {
        char volverIntentarUNA;

        cout << endl;
        cout << "Demasiados intentos fallidos." << endl;

        while (true)
        {
            cout << "¿Desea volver a intentar agregar los alumnos? (S/N): ";
            cin >> volverIntentarUNA;
            volverIntentarUNA = toupper(volverIntentarUNA);

            if (volverIntentarUNA == 'S' || volverIntentarUNA == 'N')
            {
                break; // Respuesta válida, salir del ciclo
            }
            else
            {

                cout << "Error: respuesta no válida. Por favor ingrese 'S' o 'N'." << endl;

                // Limpiar buffer en caso de que haya más caracteres
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        if (volverIntentarUNA == 'S')
        {
            intentosUNA = 0;
            cantidaddeestudiantesUNA = 0;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            main();   // Volver a ejecutar main
            return 0; // Terminar la ejecución actual
        }
        else
        {

            cout << endl
                 << "Gracias por usar el programa. ¡Hasta luego!" << endl;

            return 1;
        }
    }
    return 0;
}