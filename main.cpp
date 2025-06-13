#include <iostream> // Profe, esto es una libreria para usar cout y cin
#include <string>   // Profe, esto es una libreria para usar textos digamos los strings
#include <iomanip>  // Profe, esto lo agregue para alinear columnas con setw, o ordenar bien a la hora de dar aprobados y reporbados, con sus datos
#include <vector>   // Profe, esto lo agregue para usar vectores dinamicos
#include <windows.h> // Profe, esto es una libreria especial para windows, para lograr hacer ciertas tareas, por ejemplo agregar colores
#include <cctype> // Profe, esto es para usar isalpha e isdigit o lo de ordenar bien
#include <limits> // Profe, esto es otra libreria estándar de C++ para manejar límites y propiedades de tipos de datos, usada para limpiar el buffer de entrada
#undef max        // Profe, con esto se evita error de linea con max

using namespace std;

// Esto es para poner colores
void setColor(int texto, int fondo)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (fondo << 4) | texto);
}

// Esto es una funcion para validar que un string tenga solo letras y no tenga espacios
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
    // Aca creamos las variables para medir los intentos en el inicio
    int cantidaddeestudiantesUNA = 0;
    int intentosUNA = 0;
    const int maxIntentosUNA = 5;         // Aca es lo de maximo 5 intentos para ingresar bien
    const int limiteestudiantesUNA = 100; // Esto es el limite de estudiantes
    cout << endl;
    // Aca usamos el primer setColor, y se logra con la libreria de windows
    setColor(2, 0);
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    cout << right << setw(40) << "Bienvenido al programa" << endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n";
    setColor(7, 0);

    // Esto es un ciclo que le da 5 intentos al usuario para meter una cantidad válida de estudiantes
    while (intentosUNA < maxIntentosUNA)
    {
        cout << endl;
        cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;
        cout << "Ingrese el numero de estudiantes para agregar sus notas (entre 1 y " << limiteestudiantesUNA << "):";
        cin >> cantidaddeestudiantesUNA;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            setColor(4, 0);
            cout << "⇒Eso no es un numero, intentelo de nuevo" << endl;
            setColor(7, 0);
            intentosUNA++;
        }
        else if (cantidaddeestudiantesUNA <= 0 || cantidaddeestudiantesUNA > limiteestudiantesUNA)
        {
            cout << endl;
            cout << "⇒El numero debe estar entre 1 y " << limiteestudiantesUNA << endl;
            intentosUNA++;
        }
        else
        {
            char respuestaUNA;
            cout << endl;
            cout << "⇒Esta seguro que desea evaluar " << cantidaddeestudiantesUNA << " estudiantes de la UNA? (S/N): ";
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
                setColor(4, 0);
                cout << "Error, ingrese un dato valido \n";
                setColor(7, 0);
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
        setColor(4, 0);
        cout << "Demasiados intentos fallidos." << endl;
        setColor(7, 0);

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
                setColor(4, 0);
                cout << "Error: respuesta no válida. Por favor ingrese 'S' o 'N'." << endl;
                setColor(7, 0);

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
            setColor(2, 0);
            cout << endl
                 << "Gracias por usar el programa. ¡Hasta luego!" << endl;
            setColor(7, 0);

            return 1;
        }
    }

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
    notasUNA.resize(cantidaddeestudiantesUNA, vector<float>(5)); // Aca son las 5 notas por estudiante
    promediosUNA.resize(cantidaddeestudiantesUNA);
    estadosUNA.resize(cantidaddeestudiantesUNA);

    int numeroestudianteUNA = 0;
    cin.ignore(); // Esto es para limpiar el buffer

    while (numeroestudianteUNA < cantidaddeestudiantesUNA)
    {
        setColor(1, 2);
        cout << "\n◌◌◌◌◌◌◌◌◌◌◌◌◌◌ Estudiante # " << (numeroestudianteUNA + 1) << " ◌◌◌◌◌◌◌◌◌◌◌◌◌◌\n";
        setColor(7, 0);

        while (true)
        {
            cout << endl;
            cout << "Ingrese el primer nombre:";
            getline(cin, nombresUNA[numeroestudianteUNA]);
            if (!soloLetrasSinEspaciosUNA(nombresUNA[numeroestudianteUNA]))
            {

                setColor(4, 0);
                cout << endl;
                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n";
                cout << "Error, el nombre debe contener solo letras y no puede tener espacios\n";
                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n";
                setColor(7, 0);
            }
            else
            {
                break;
            }
        }
        while (true)
        {
            cout << endl;
            cout << "Ingrese el primer apellido:";
            getline(cin, primerApellidoUNA[numeroestudianteUNA]);
            if (!soloLetrasSinEspaciosUNA(primerApellidoUNA[numeroestudianteUNA]))
            {
                cout << endl;
                setColor(4, 0);
                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n";
                cout << "Error, el primer apellido debe contener solo letras y no puede tener espacios\n";
                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n";
                setColor(7, 0);
            }
            else
            {
                break;
            }
        }
        while (true)
        {

            cout << endl;
            cout << "Ingrese el segundo apellido:";
            getline(cin, segundoApellidoUNA[numeroestudianteUNA]);
            if (!soloLetrasSinEspaciosUNA(segundoApellidoUNA[numeroestudianteUNA]))
            {

                cout << endl;
                setColor(4, 0);
                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ \n";
                cout << "Error, el segundo apellido debe contener solo letras y no puede tener espacios \n";
                cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ \n";
                setColor(7, 0);
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            cout << endl;
            cout << "Ingrese el ciclo de estudio en la nacional (entre 1 y 8): ";
            cin >> ciclosUNA[numeroestudianteUNA];

            if (cin.fail() || ciclosUNA[numeroestudianteUNA] < 1 || ciclosUNA[numeroestudianteUNA] > 8)
            {
                setColor(4, 0);
                cout << endl;
                cout << "Error, en la UNA no existe este ciclo, solo del 1 al 8, y recuerda no ingresar espacios o letras. \n";
                setColor(7, 0);
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                break;
            }
        }
        while (true)
        {
            string cedulaTemporalUNA;
            cout << endl;
            cout << "Ingrese numero de cedula (9 digitos):";
            cin >> cedulaTemporalUNA;
            cout << "═══════════════════════════════════════════════════════════";

            if (!soloDigitosUNA(cedulaTemporalUNA) || cedulaTemporalUNA.length() != 9)
            {
                setColor(4, 0);
                cout << endl;
                cout << "Error, la cedula debe contener exactamente 9 digitos numericos y evitar los espacios. \n";
                setColor(7, 0);
            }
            else
            {
                cedulasUNA[numeroestudianteUNA] = stoi(cedulaTemporalUNA);
                break;
            }
        }
        float sumanotasUNA = 0;
        int numeroexamenUNA = 0;

        while (numeroexamenUNA < 5)
        {
            while (true)
            {
                cout << endl;
                cout << "Ingrese nota del examen #" << (numeroexamenUNA + 1) << " (0-100): ";
                cin >> notasUNA[numeroestudianteUNA][numeroexamenUNA];

                if (cin.fail() || notasUNA[numeroestudianteUNA][numeroexamenUNA] < 0 || notasUNA[numeroestudianteUNA][numeroexamenUNA] > 100)
                {
                    setColor(4, 0);
                    cout << endl;
                    cout << "Error, la nota esta fuera de rango de, recuerda que es de 0 a 100, y es numero, no se permiten letras \n";
                    setColor(7, 0);
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                {
                    break;
                }
            }

            sumanotasUNA += notasUNA[numeroestudianteUNA][numeroexamenUNA];
            numeroexamenUNA++;
        }

        promediosUNA[numeroestudianteUNA] = sumanotasUNA / 5;

        if (promediosUNA[numeroestudianteUNA] >= 70)
        {
            estadosUNA[numeroestudianteUNA] = "Aprobado";
        }
        else
        {
            estadosUNA[numeroestudianteUNA] = "Reprobado";
        }

        numeroestudianteUNA++;
        cin.ignore();
    }

    cout << fixed << setprecision(2);
    setColor(2, 0);
    cout << "\n▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬APROBADOS▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n";
    cout << left << setw(30) << "✦Nombre completo"
         << setw(10) << "✦Ciclo"
         << setw(15) << "✦Cedula"
         << setw(10) << " ✦Promedio" << endl;
    cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n";
    setColor(7, 0);
    int indiceaprobadoUNA = 0;
    // Aca se hace un while, para verificar si es mayor y mostrar si aprobo
    while (indiceaprobadoUNA < cantidaddeestudiantesUNA)
    {
        if (estadosUNA[indiceaprobadoUNA] == "Aprobado")
        {
            cout << left
                 << setw(30) << (nombresUNA[indiceaprobadoUNA] + " " + primerApellidoUNA[indiceaprobadoUNA] + " " + segundoApellidoUNA[indiceaprobadoUNA])
                 << setw(10) << ciclosUNA[indiceaprobadoUNA]
                 << setw(15) << cedulasUNA[indiceaprobadoUNA]
                 << setw(10) << promediosUNA[indiceaprobadoUNA] << endl;
        }
        indiceaprobadoUNA++;
    }
    setColor(4, 0);
    cout << "\n▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬REPROBADOS▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n";
    cout << left << setw(30) << "✦Nombre completo"
         << setw(10) << "✦Ciclo"
         << setw(15) << "✦Cedula"
         << setw(10) << " ✦Promedio" << endl;
    cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n";
    setColor(7, 0);
    cout << endl;
    int indicereprobadoUNA = 0;
    // Aca hacemos un while para que se cumpla, lo de mostrar Reprobado
    while (indicereprobadoUNA < cantidaddeestudiantesUNA)
    {
        if (estadosUNA[indicereprobadoUNA] == "Reprobado")
        {
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
