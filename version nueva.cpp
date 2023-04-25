#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;
// Vertebrados
struct Mamifero {
  std::string nombre;
  int peso;
  std::string color;
  int patas;
};

struct Ave {
  std::string nombre;
  int peso;
  std::string color;
  int alas;
};

struct Pez {
  std::string nombre;
  int peso;
  std::string color;
  int aletas;
  std::string escamas;
};

struct Anfibio {
  std::string nombre;
  int peso;
  std::string color;
  std::string piel;
};

struct Reptil {
  std::string nombre;
  int peso;
  std::string color;
  std::string tipo;
};
// invertebrado
struct Artropodos {
  std::string nombre;
  int peso;
  std::string color;
  int patas;
  std::string antenas;
};
struct Moluscos {
  std::string nombre;
  int peso;
  std::string color;
  std::string tipo;
};
struct Equinodermos {
  std::string nombre;
  int peso;
  std::string color;
  std::string tipo;
};
struct Gusanos {
  std::string nombre;
  int peso;
  std::string color;
  std::string tipo;
};
struct Poriferos {
  std::string nombre;
  int peso;
  std::string color;
};
struct Celenteros {
  std::string nombre;
  int peso;
  std::string color;
  std::string tipo;
  std::string tentaculos;
};

int contarAnimales(string archivo) {
  ifstream entrada(archivo.c_str());
  int contador = 0;
  string linea;
  while (getline(entrada, linea)) {

    contador++;
  }
  entrada.close();
  return contador;
}
void mostrarAnimales(string tipo) {
  ifstream archivo;
  string nombreArchivo;

  if (tipo == "mamiferos") {
    nombreArchivo = "mamiferos.txt";
  } else if (tipo == "aves") {
    nombreArchivo = "aves.txt";
  } else if (tipo == "anfibios") {
    nombreArchivo = "anfibios.txt";
  } else if (tipo == "peces") {
    nombreArchivo = "peces.txt";
  } else if (tipo == "moluscos") {
    nombreArchivo = "moluscos.txt";
  } else if (tipo == "artropodos") {
    nombreArchivo = "artropodos.txt";
  } else if (tipo == "equinodermos") {
    nombreArchivo = "equinodermos.txt";
  } else if (tipo == "gusanos") {
    nombreArchivo = "gusanos.txt";
  } else if (tipo == "poriferos") {
    nombreArchivo = "poriferos.txt";
  } else if (tipo == "celenteros") {
    nombreArchivo = "celenteros.txt";
  } else if (tipo == "invertebrados") {
    nombreArchivo = "invertebrados.txt";
  } else if (tipo == "reptiles") {
    nombreArchivo = "reptiles.txt";
  } else {
    cout << "Tipo de animal no válido." << endl;
    return;
  }

  archivo.open(nombreArchivo);
  if (archivo.is_open()) {
    cout << "\nLista de " << tipo << ":" << endl;
    string linea;
    while (getline(archivo, linea)) {
      cout << linea << endl;
    }
    archivo.close();
  } else {
    cout << "No se pudo abrir el archivo " << nombreArchivo << "." << endl;
  }
}

int main() {
  std::ifstream archivo("animales.txt");
  std::string linea;
  std::string nombre;
  char tipo1, tipo2, opcionmenu;
  int opcion;
  int generador();

  std::cout << "MENU ZOOLOGICO\n";

  std::cout << "1. Mostrar Lista de animales\n";
  std::cout << "2. Porcentajes de Tipos de Animales\n";
  std::cout << "3. Porcentajes de vertebrados e invertebrados\n";
  std::cout << "4. Generar un animal de forma aleatoria \n";
  std::cout << "5. Salir.\n";
  std::cout << "Seleccione una Opcion del Menu: ";
  std::cin >> opcionmenu;

  switch (opcionmenu) {
  case '1': {
    int opcion2;
    cout << "¿Qué tipo de animal quieres ver?" << endl;
    cout << "1. Mamíferos" << endl;
    cout << "2. Aves" << endl;
    cout << "3. Reptiles" << endl;
    cout << "4. Anfibios" << endl;
    cout << "5. Peces" << endl;
    cout << "6. Invertebrados" << endl;
    cout << "7. Moluscos" << endl;
    cout << "8. Artropodos" << endl;
    cout << "9. Equinodermos" << endl;
    cout << "10. Gusanos" << endl;
    cout << "11. Poriferos" << endl;
    cout << "12. Celenteros" << endl;
    cout << "\nSelecciona una opción: ";
    cin >> opcion2;

    switch (opcion2) {
    case 1:
      mostrarAnimales("mamiferos");
      break;
    case 2:
      mostrarAnimales("aves");
      break;
    case 3:
      mostrarAnimales("reptiles");
      break;
    case 4:
      mostrarAnimales("anfibios");
      break;
    case 5:
      mostrarAnimales("peces");
      break;
    case 6:
      mostrarAnimales("invertebrados");
      break;
    case 7:
      mostrarAnimales("moluscos");
      break;
    case 8:
      mostrarAnimales("artropodos");
      break;
    case 9:
      mostrarAnimales("equinodermos");
      break;
    case 10:
      mostrarAnimales("gusanos");
      break;
    case 11:
      mostrarAnimales("poriferos");
      break;
    case 12:
      mostrarAnimales("celenteros");
      break;
    default:
      cout << "Opción no válida." << endl;
    }
    return 0;
  }

  // OPCIÓN 2
  case '2': {
    vector<string> tiposAnimales = {
        "mamiferos.txt",  "reptiles.txt",  "aves.txt",         "peces.txt",
        "artropodos.txt", "moluscos.txt",  "equinodermos.txt", "gusanos.txt",
        "poriferos.txt",  "celenteros.txt"};
    vector<string> nombreTiposAnimales = {
        "Mamiferos", "Reptiles",     "Aves",    "Peces",     "Artropodos",
        "Moluscos",  "Equinodermos", "Gusanos", "Poriferos", "Celenteros"};

    int totalAnimales = 0;
    int totalVI = 0;
    vector<int> numeroAnimales;

    for (int i = 0; i < tiposAnimales.size(); i++) {
      int cantidad = contarAnimales(tiposAnimales[i]);
      totalAnimales += cantidad;
      numeroAnimales.push_back(cantidad);

      if (i <= 2) {
        totalVI += cantidad;
      }
    }

    for (int i = 0; i < tiposAnimales.size(); i++) {

      float porcentaje = (float)numeroAnimales[i] / totalAnimales * 100;
      cout << nombreTiposAnimales[i] << ": " << numeroAnimales[i] << " ("
           << porcentaje << "%)" << endl;
    }
    return 0;
  }

    // OPCIÓN 3
  case '3': {
    // VERTEBRADOS
    vector<string> tiposAnimales = {"mamiferos.txt", "reptiles.txt", "aves.txt",
                                    "peces.txt"};
    vector<string> nombresTiposAnimales = {"Mamiferos", "Reptiles", "Aves",
                                           "Peces"};
    // INVERTEBRADOS
    vector<string> animalInv = {"artropodos.txt",   "moluscos.txt",
                                "equinodermos.txt", "gusanos.txt",
                                "poriferos.txt",    "celenteros.txt"};
    vector<string> tiposAnimalesInv = {"Artropodos",   "Moluscos",
                                       "Equinodermos", "Gusanos",
                                       "Poriferos",    "Celenteros"};

    int totalAnimales = 0;
    int totalanimal = 0;
    int totalVertebrados = 0;
    int totalInverebrados = 0;

    int sumaanm;
    float porcentaje_ver;

    vector<int> numeroAnimales;
    vector<int> numeroAnimal;

    cout << "\n VERTEBRADOS : " << endl;

    for (int i = 0; i < tiposAnimales.size(); i++) {
      int cantidad = contarAnimales(tiposAnimales[i]);
      totalAnimales += cantidad;
      numeroAnimales.push_back(cantidad);

      totalVertebrados += cantidad;
    }
    for (int i = 0; i < tiposAnimales.size(); i++) {
      float porcentaje = (float)numeroAnimales[i] / totalAnimales * 100;
      cout << nombresTiposAnimales[i] << ": " << numeroAnimales[i] << " ("
           << porcentaje << "%)" << endl;
    }

    for (int i = 0; i < animalInv.size(); i++) {
      int cantidad = contarAnimales(animalInv[i]);
      totalanimal += cantidad;
      numeroAnimal.push_back(cantidad);

      totalInverebrados += cantidad;
    }
    cout << "\n INVERTEBRADOS : " << endl;
    for (int i = 0; i < animalInv.size(); i++) {
      float porcentaje = (float)numeroAnimal[i] / totalanimal * 100;
      cout << tiposAnimalesInv[i] << ": " << numeroAnimal[i] << " ("
           << porcentaje << "%)" << endl;
    }
    sumaanm = totalVertebrados + totalInverebrados;

    int vert = totalVertebrados;
    porcentaje_ver = vert / sumaanm;

    cout << "\nTotal de vertebrados: " << totalVertebrados
         << "\nTotal de invertebrados: " << totalInverebrados << endl;

    return 0;
  }

  // OPCIÓN 4
  case '4':

    // Leer el archivo y mostrar los nombres de los animales
    while (std::getline(archivo, linea)) {
      if (linea.length() > 0) {
        nombre = linea.substr(0, linea.find(" | "));
        std::cout << nombre << std::endl;
      }
    }

    archivo.close();

    // Solicitar al usuario que seleccione una opción
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 121);
    int num = dis(gen);
    std::cout << "Animal Elegido: " << num << std::endl;
    opcion = num;

    // Leer el archivo nuevamente y buscar el animal seleccionado
    archivo.open("animales.txt");

    int contador = 0;
    while (std::getline(archivo, linea)) {
      contador++;
      if (contador == opcion) {
        nombre = linea.substr(0, linea.find(" | "));
        tipo1 = linea.substr(linea.find(" | ") + 3, 1)[0];
        tipo2 = linea.substr(linea.find(" | ") + 4, 1)[0];

        switch (tipo1) {
        case 'v':
          switch (tipo2) {
          case 'm':
            // Mamifero es M
            {
              Mamifero mamifero;
              mamifero.nombre = nombre;
              std::cout << "Ingrese el peso del mamífero: ";
              std::cin >> mamifero.peso;
              std::cout << "Ingrese el color del mamífero: ";
              std::cin >> mamifero.color;
              std::cout << "Ingrese la cantidad de patas del mamífero: ";
              std::cin >> mamifero.patas;

              // Guardar en archivo
              std::ofstream archivoMamiferos("mamiferos.txt", std::ios::app);
              archivoMamiferos << mamifero.nombre << "-" << mamifero.peso
                               << "K-" << mamifero.color << "-"
                               << mamifero.patas << std::endl;
              archivoMamiferos.close();

              std::cout << "Información del mamífero guardada en mamiferos.txt"
                        << std::endl;
            }
            break;
          case 'a':
            // Ave es A
            {
              Ave ave;
              ave.nombre = nombre;
              std::cout << "Ingrese el peso del ave: ";
              std::cin >> ave.peso;
              std::cout << "Ingrese el color del ave: ";
              std::cin >> ave.color;
              std::cout << "Ingrese la cantidad de alas del ave: ";
              std::cin >> ave.alas;

              std::ofstream archivoAves("aves.txt", std::ios::app);
              archivoAves << ave.nombre << "-" << ave.peso << "K-" << ave.color
                          << "-" << ave.alas << std::endl;
              archivoAves.close();
              std::cout << "Información del ave guardada en aves.txt"
                        << std::endl;
            }

            break;
            //Pez es P
          case 'p': {
            Pez pez;
            pez.nombre = nombre;
            std::cout << "Ingrese el peso del Pez: ";
            std::cin >> pez.peso;
            std::cout << "Ingrese el color del Pez: ";
            std::cin >> pez.color;
            std::cout << "Ingrese la cantidad de aletas: ";
            std::cin >> pez.aletas;
            std::cout << "Este posee escamas? s/n: ";
            std::cin >> pez.escamas;

            std::ofstream archivoPez("peces.txt", std::ios::app);
            archivoPez << pez.nombre << "-" << pez.peso << "K-" << pez.color
                       << "-" << pez.aletas << "-" << pez.escamas << std::endl;
            archivoPez.close();
            std::cout << "Información del vertebrado guardada en peces.txt"
                      << std::endl;
          }
            std::cout << nombre << " es un pez" << std::endl;
            break;
            //anfibio N
          case 'n': {
            Anfibio anfibio;
            anfibio.nombre = nombre;
            std::cout << "Ingrese el peso del Anfibio: ";
            std::cin >> anfibio.peso;
            std::cout << "Ingrese el color del Anfibio: ";
            std::cin >> anfibio.color;
            std::cout << "Ingrese el tipo de piel (Babosa/No): ";
            std::cin >> anfibio.piel;

            std::ofstream archivoAnf("anfibio.txt", std::ios::app);
            archivoAnf << anfibio.nombre << "-" << anfibio.peso << "K-"
                       << anfibio.color << "-" << anfibio.piel << std::endl;
            archivoAnf.close();
            std::cout << "Información del vertebrado guardada en anfibio.txt"
                      << std::endl;
          }
            std::cout << nombre << " es un anfibio" << std::endl;
            break;

          // INVERTEBRADOS
          // moluscos es X
          case 'x': {
            Moluscos moluscos;
            moluscos.nombre = nombre;
            std::cout << "Ingrese el peso: ";
            std::cin >> moluscos.peso;
            std::cout << "Ingrese el color: ";
            std::cin >> moluscos.color;
            std::cout << "Ingrese el tipo: ";
            std::cin >> moluscos.tipo;

            std::ofstream archivoMol("moluscos.txt", std::ios::app);
            archivoMol << moluscos.nombre << "-" << moluscos.peso << "K-"
                       << moluscos.color << "-" << moluscos.tipo << std::endl;
            archivoMol.close();
            std::cout << "Información del Invertebrado guardada en moluscos.txt"
                      << std::endl;
          }
            std::cout << nombre << " es un Mosluco invertebrado" << std::endl;
            break;

            // Artropodo es U
          case 'u': {
            Artropodos artropodos;
            artropodos.nombre = nombre;
            std::cout << "Ingrese el peso: ";
            std::cin >> artropodos.peso;
            std::cout << "Ingrese el color: ";
            std::cin >> artropodos.color;
            std::cout << "Ingrese la cantidad de patas: ";
            std::cin >> artropodos.patas;
            std::cout << "Ingrese la cantidad de antenas: ";
            std::cin >> artropodos.antenas;

            std::ofstream archivoArt("artropodos.txt", std::ios::app);
            archivoArt << artropodos.nombre << "-" << artropodos.peso << "K-"
                       << artropodos.color << "-" << artropodos.patas << "-"
                       << artropodos.antenas << std::endl;
            archivoArt.close();
            std::cout
                << "Información del Invertebrado guardada en artropodos.txt"
                << std::endl;
          }
            std::cout << nombre << " Es un Artropodo invertebrado" << std::endl;
            break;

            // Equinodermos es O
          case 'o': {
            Equinodermos equinodermos;
            equinodermos.nombre = nombre;
            std::cout << "Ingrese el peso: ";
            std::cin >> equinodermos.peso;
            std::cout << "Ingrese el color: ";
            std::cin >> equinodermos.color;
            std::cout << "Ingrese el tipo: ";
            std::cin >> equinodermos.tipo;

            std::ofstream archivoEqui("equinodermos.txt", std::ios::app);
            archivoEqui << equinodermos.nombre << "-" << equinodermos.peso
                        << "K-" << equinodermos.color << "-"
                        << equinodermos.tipo << std::endl;
            archivoEqui.close();
            std::cout
                << "Información del Invertebrado guardada en equinodermos.txt"
                << std::endl;
          }
            std::cout << nombre << " Es un Equinodermo invertebrado"
                      << std::endl;
            break;
            // Gusanos es L
          case 'l': {
            Gusanos gusanos;
            gusanos.nombre = nombre;
            std::cout << "Ingrese el peso: ";
            std::cin >> gusanos.peso;
            std::cout << "Ingrese el color: ";
            std::cin >> gusanos.color;
            std::cout << "Ingrese el tipo: ";
            std::cin >> gusanos.tipo;

            std::ofstream archivoGusa("gusanos.txt", std::ios::app);
            archivoGusa << gusanos.nombre << "-" << gusanos.peso << "ML-"
                        << gusanos.color << "-" << gusanos.tipo << std::endl;
            archivoGusa.close();
            std::cout << "Información del Invertebrado guardada en gusanos.txt"
                      << std::endl;
          }
            std::cout << nombre << " Es un gusano invertebrado" << std::endl;
            break;
            // Poriferos es E
          case 'e': {
            Poriferos poriferos;
            poriferos.nombre = nombre;
            std::cout << "Ingrese el peso: ";
            std::cin >> poriferos.peso;
            std::cout << "Ingrese el color: ";
            std::cin >> poriferos.color;

            std::ofstream archivoPoli("poriferos.txt", std::ios::app);
            archivoPoli << poriferos.nombre << "-" << poriferos.peso << "GR-"
                        << poriferos.color << std::endl;
            archivoPoli.close();
            std::cout
                << "Información del Invertebrado guardada en poriferos.txt"
                << std::endl;
          }
            std::cout << nombre << " Es un Porifero invertebrado" << std::endl;
            break;

            // Celenteros es Z
          case 'z': {
            Celenteros celenteros;
            celenteros.nombre = nombre;
            std::cout << "Ingrese el peso: ";
            std::cin >> celenteros.peso;
            std::cout << "Ingrese el color: ";
            std::cin >> celenteros.color;
            std::cout << "Ingrese el tipo: ";
            std::cin >> celenteros.tipo;
            std::cout
                << "Ingrese la cantidad de tentaculos (Si no tiene marca 0): ";
            std::cin >> celenteros.tentaculos;

            std::ofstream archivoCelen("celenteros.txt", std::ios::app);
            archivoCelen << celenteros.nombre << "-" << celenteros.peso << "K-"
                         << celenteros.color << "-" << celenteros.tipo << "-"
                         << celenteros.tentaculos << std::endl;
            archivoCelen.close();
            std::cout
                << "Información del Invertebrado guardada en celenteros.txt"
                << std::endl;
          }
            std::cout << nombre << " Es un Celentero invertebrado" << std::endl;
            break;

          case 'r': {
            Reptil reptil;
            reptil.nombre = nombre;
            std::cout << "Ingrese el peso del Reptil: ";
            std::cin >> reptil.peso;
            std::cout << "Ingrese el color: ";
            std::cin >> reptil.color;
            std::cout << "Ingrese el tipo(Tierra, Mar o Ambos): ";
            std::cin >> reptil.tipo;

            std::ofstream archivoRep("reptil.txt", std::ios::app);
            archivoRep << reptil.nombre << "-" << reptil.peso << "L-"
                       << reptil.color << "-" << reptil.tipo << std::endl;
            archivoRep.close();
            std::cout << "Información del vertebrado guardada en reptil.txt"
                      << std::endl;
          }
            std::cout << nombre << " es un reptil" << std::endl;
            break;
          default:
            std::cout << "Tipo de animal desconocido" << std::endl;
            break;
          }
          
          break;
        case 'i':
          std::cout << nombre << " es un invertebrado" << std::endl;
          break;
        default:
          std::cout << "Tipo de animal desconocido" << std::endl;
          break;
        }
        break;
      }
    }

    archivo.close();
    return 0;
    break;
  }
}
