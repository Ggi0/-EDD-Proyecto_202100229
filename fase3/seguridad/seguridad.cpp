#include "seguridad.h"

void comprimirUsuarios() {
    Huffman h;
    
    std::string allUsers = generarJSONUsuarios(arbolGlobal_usuarios);
    
    h.crearArbol(allUsers);
    //h.graficar();
    h.crearCodigosHuffman(h.getRaiz(), "");
    //h.imprimirCodigos();

    std::string comprimido = h.comprimir(allUsers);
    
    if (comprimido.empty()) {
        std::cerr << "Error: El texto comprimido está vacío." << std::endl;
        return;
    }

    // Guardar los códigos Huffman junto con el texto comprimido
    std::ofstream outfile("/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/huffman/compresiones/backupUser.edd");
    
    // Primero guardamos cada carácter y su código
    for(int i = 0; i < 256; i++) {
        if(h.codigos[i] != "") {
            outfile << (unsigned char)i << h.codigos[i] << "\n";
        }
    }
    outfile << "---\n"; // Marcador para separar códigos del texto comprimido
    outfile << comprimido;
    outfile.close();
}

// Función para generar el JSON completo del árbol
std::string generarJSONUsuarios(AVL& arbol) {
    std::stringstream ss;
    bool esElPrimero = true;
    
    ss << "[";
    
    // Usamos el operador . en lugar de -> ya que ahora es una referencia
    if (arbol.getRaiz() != nullptr) {
        recorrerArbolJSON(arbol.getRaiz(), ss, esElPrimero);
    }
    
    ss << "]";
    return ss.str();
}

// Función recursiva para recorrer el árbol en orden
void recorrerArbolJSON(NodoAVL* nodo, std::stringstream& ss, bool& esElPrimero) {
    if (nodo == nullptr) return;
    
    // Recorrer izquierda
    recorrerArbolJSON(nodo->getIzq(), ss, esElPrimero);
    
    // Procesar nodo actual
    if (!esElPrimero) {
        ss << ",";
    } else {
        esElPrimero = false;
    }
    ss << "  " << usuarioToJSON(nodo->getData());
    
    // Recorrer derecha
    recorrerArbolJSON(nodo->getDrcha(), ss, esElPrimero);
}


// Función para convertir un usuario individual a formato JSON
std::string usuarioToJSON(Usuarios& usuario) {
    std::stringstream ss;
    ss << "{";
    ss << "\"nombres\": \"" << usuario.getNombres() << "\",";
    ss << "\"apellidos\": \"" << usuario.getApellidos() << "\",";
    ss << "\"fecha_de_nacimiento\": \"" << usuario.getFechaN() << "\",";
    ss << "\"correo\": \"" << usuario.getCorreo() << "\",";
    ss << "\"contraseña\": \"" << usuario.getContrasenia() << "\"";
    ss << "  }";
    return ss.str();
}

// ------------ metodo para comprimir las solicitudes generales.
void comprimirSolicitudes() {
    Huffman h;

    // Generar el JSON de todas las solicitudes en la lista global.
    std::string allSolicitudes = generarJSONSolicitudes(listaGlobal_solicitudes);
    
     h.crearArbol(allSolicitudes);
    //h.graficar();
    h.crearCodigosHuffman(h.getRaiz(), "");
    //h.imprimirCodigos();

    std::string comprimido = h.comprimir(allSolicitudes);
    
    if (comprimido.empty()) {
        std::cerr << "Error: El texto comprimido está vacío." << std::endl;
        return;
    }

    // Guardar los códigos Huffman junto con el texto comprimido
    std::ofstream outfile("/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/huffman/compresiones/backupSolicitudes.edd");
    
    // Primero guardamos cada carácter y su código
    for(int i = 0; i < 256; i++) {
        if(h.codigos[i] != "") {
            outfile << (unsigned char)i << h.codigos[i] << "\n";
        }
    }
    outfile << "---\n"; // Marcador para separar códigos del texto comprimido
    outfile << comprimido;
    outfile.close();
}


// Función para generar el JSON completo de las solicitudes en la lista global.
std::string generarJSONSolicitudes(arrayList_soli& listaSolicitudes) {
    std::stringstream ss;
    bool esPrimera = true;

    // Formato de apertura del arreglo JSON.
    ss << "[";

    // Recorrer la lista global de solicitudes.
    solicitud_Nodo* actual = listaSolicitudes.getPrimero();  // Obtener el nodo inicial de la lista
    while (actual != nullptr) {
        // Añadir coma entre objetos si no es el primero.
        if (!esPrimera) {
            ss << ",";
        } else {
            esPrimera = false;
        }

        // Convertir la solicitud actual a formato JSON y agregarla al stream.
        ss << "  {";
        ss << "      \"emisor\": \"" << actual->getDato().getEmisor() << "\",";
        ss << "      \"receptor\": \"" << actual->getDato().getReceptor() << "\",";
        ss << "      \"estado\": \"" << actual->getDato().getEstado() << "\"";
        ss << "  }";

        // Avanzar al siguiente nodo en la lista.
        actual = actual->getSig();
    }

    // Formato de cierre del arreglo JSON.
    ss << "]";
    return ss.str();
}


// para descomprimir el texto al iniciar el programa:
void descomprimirUsuarios() {
    std::cout << " -------------- descomprimiendo info -----------------" << std::endl;
    Huffman h;
    
    std::string contenido;
    std::string line;
    bool leyendoCodigos = true;
    std::ifstream f("/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/huffman/compresiones/backupUser.edd");

    if(!f.is_open()) {
        std::cerr << "Error abriendo el archivo";
        return;
    }

    // Leer los códigos Huffman
    while(getline(f, line)) {
        if(line == "---") {
            leyendoCodigos = false;
            break;
        }
        if(line.length() > 1) {
            char c = line[0];
            std::string codigo = line.substr(1);
            h.codigos[(unsigned char)c] = codigo;
        }
    }

    // Leer el texto comprimido
    std::string textoComprimido;
    while(getline(f, line)) {
        textoComprimido += line;
    }
    f.close();

    // Crear un nodo raíz inicial
    Nodo_huff* raiz = new Nodo_huff('~');
    h.setRaiz(raiz);

    // Construir el árbol
    for(int i = 0; i < 256; i++) {
        if(h.codigos[i] != "") {
            Nodo_huff* actual = raiz;
            std::string codigo = h.codigos[i];
            
            for(size_t j = 0; j < codigo.length(); j++) {
                if(codigo[j] == '0') {
                    if(actual->izq == nullptr) {
                        actual->izq = new Nodo_huff('~');
                    }
                    actual = actual->izq;
                } else {
                    if(actual->der == nullptr) {
                        actual->der = new Nodo_huff('~');
                    }
                    actual = actual->der;
                }
                
                if(j == codigo.length() - 1) {
                    actual->c = (char)i;
                }
            }
        }
    }

    // Ahora descomprimimos
    std::string descomprimido = h.descomprimir(textoComprimido);

    // Verificar si el contenido descomprimido está vacío
    if (descomprimido.empty()) {
        std::cerr << "El archivo descomprimido está vacío." << std::endl;
        return;
    }

    // Escribir el contenido en un archivo JSON
    std::string outputPath = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/backupsGenerales/backupUsuarios.json";
    std::ofstream outFile(outputPath);
    
    if (!outFile.is_open()) {
        std::cerr << "Error al abrir el archivo para escribir el JSON" << std::endl;
        return;
    }

    outFile << descomprimido;
    outFile.close();


    std::cout << "Texto descomprimido: " + descomprimido << std::endl;
    leerBackup_Usuarios();
    descomprimirSolicitudes();
}

void leerBackup_Usuarios(){
    std::string path = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/backupsGenerales/backupUsuarios.json";

    // Convertir la ruta de QString a std::string
    std::string rutaArchivo = path;

    // Remover comillas dobles si las hay
    rutaArchivo.erase(std::remove(rutaArchivo.begin(), rutaArchivo.end(), '\"'), rutaArchivo.end());

    // Llamar a la función leerUsuarios() pasando la ruta del archivo
    leerUsuarios(rutaArchivo);
    

}


void descomprimirSolicitudes(){
    std::cout << " -------------- descomprimiendo info solicitudes -----------------" << std::endl;
    Huffman h;
    
    std::string contenido;
    std::string line;
    bool leyendoCodigos = true;
    std::ifstream f("/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/huffman/compresiones/backupSolicitudes.edd");

    if(!f.is_open()) {
        std::cerr << "Error abriendo el archivo";
        return;
    }

    // Leer los códigos Huffman
    while(getline(f, line)) {
        if(line == "---") {
            leyendoCodigos = false;
            break;
        }
        if(line.length() > 1) {
            char c = line[0];
            std::string codigo = line.substr(1);
            h.codigos[(unsigned char)c] = codigo;
        }
    }

    // Leer el texto comprimido
    std::string textoComprimido;
    while(getline(f, line)) {
        textoComprimido += line;
    }
    f.close();

    // Crear un nodo raíz inicial
    Nodo_huff* raiz = new Nodo_huff('~');
    h.setRaiz(raiz);

    // Construir el árbol
    for(int i = 0; i < 256; i++) {
        if(h.codigos[i] != "") {
            Nodo_huff* actual = raiz;
            std::string codigo = h.codigos[i];
            
            for(size_t j = 0; j < codigo.length(); j++) {
                if(codigo[j] == '0') {
                    if(actual->izq == nullptr) {
                        actual->izq = new Nodo_huff('~');
                    }
                    actual = actual->izq;
                } else {
                    if(actual->der == nullptr) {
                        actual->der = new Nodo_huff('~');
                    }
                    actual = actual->der;
                }
                
                if(j == codigo.length() - 1) {
                    actual->c = (char)i;
                }
            }
        }
    }

    // Ahora descomprimimos
    std::string descomprimido = h.descomprimir(textoComprimido);

    // Verificar si el contenido descomprimido está vacío
    if (descomprimido.empty()) {
        std::cerr << "El archivo descomprimido está vacío." << std::endl;
        return;
    }

    // Escribir el contenido en un archivo JSON
    std::string outputPath = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/backupsGenerales/backupSolicitudes.json";
    std::ofstream outFile(outputPath);
    
    if (!outFile.is_open()) {
        std::cerr << "Error al abrir el archivo para escribir el JSON" << std::endl;
        return;
    }

    outFile << descomprimido;
    outFile.close();


    std::cout << "Texto descomprimido: " + descomprimido << std::endl;
    leerBackup_solicitudes();

}

void leerBackup_solicitudes(){
    std::string path = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/backupsGenerales/backupSolicitudes.json";

    // Convertir la ruta de QString a std::string
    std::string rutaArchivo = path;

    // Remover comillas dobles si las hay
    rutaArchivo.erase(std::remove(rutaArchivo.begin(), rutaArchivo.end(), '\"'), rutaArchivo.end());

    // Llamar a la función leerUsuarios() pasando la ruta del archivo
    leerSolicitudes(rutaArchivo);

}