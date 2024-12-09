#include "registrarBlock.h"
#include <dirent.h>
#include <sys/stat.h>

// llamando a la lista global de bloques, para la permanencia de datos.
listaBloques global_listaBlock;
int global_index = 0;

void saveBlock(){
    // para el top hash del arbol
    std::string rootMerkle;
    rootMerkle = registroArbolMerkle();

    // para el timestamp
    std::string timeStamp;
    timeStamp = obtenerTimestamp();

    if (global_index == 0){
        std::string prev_hash = "0000";

        std::string data_Hash;
        data_Hash = std::to_string(global_index) + timeStamp + rootMerkle + prev_hash;

        auto resultado = determinarNonce(data_Hash);
        std::string nonce = resultado.first;
        std::string hash = resultado.second;
        std::cout << "Nonce: " << nonce << std::endl;
        std::cout << "Hash: " << hash << std::endl;

        std::string Data = generarJsonPublicaciones();
        
        // Crear un objeto Bloque con todos los datos recolectados
        Bloque nuevoBloque(global_index, timeStamp, Data, nonce, prev_hash, hash, rootMerkle);
        global_index = global_index + 1; 
        global_listaBlock.append(nuevoBloque);
        // Puedes imprimir el bloque para verificar
        nuevoBloque.printBloque();
        
    }else{
        std::string prev_hash;
        // buscar hash del anterior en la lista
        Bloque_Nodo* ultimoNodo = global_listaBlock.getUltimo();
        if (ultimoNodo != nullptr) {
            prev_hash = ultimoNodo->getDato().getHash();
        }

        std::string data_Hash;
        data_Hash = std::to_string(global_index) + timeStamp + rootMerkle + prev_hash;

        auto resultado = determinarNonce(data_Hash);
        std::string nonce = resultado.first;
        std::string hash = resultado.second;
        std::cout << "Nonce: " << nonce << std::endl;
        std::cout << "Hash: " << hash << std::endl;

        std::string Data = generarJsonPublicaciones();
        
        // Crear un objeto Bloque con todos los datos recolectados
        Bloque nuevoBloque(global_index, timeStamp, Data, nonce, prev_hash, hash, rootMerkle);
        global_index = global_index + 1; 
        global_listaBlock.append(nuevoBloque);
        // Puedes imprimir el bloque para verificar
        nuevoBloque.printBloque();
    }

    escribirJsonBLOCKCHAIN();

}

std::string obtenerTimestamp() {
    // Obtener la fecha y hora actual
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* tiempoLocal = std::localtime(&tiempoActual);

    // Formatear la fecha y hora en el formato deseado
    std::ostringstream oss;
    oss << std::put_time(tiempoLocal, "%d-%m-%y::%H:%M:%S");

    return oss.str();
}



std::pair<std::string, std::string> determinarNonce(const std::string& s) {
    std::string hash = sha256(s);
    int nonce = 0;

    // Bucle hasta que el hash empiece con "0000"
    while (hash.substr(0, 4) != "0000") {
        hash = sha256(hash);
        nonce++;
    }

    // Convertir el nonce a string para el retorno
    std::string nonceStr = std::to_string(nonce);

    // Retornar el nonce (como string) y el hash encontrado
    return std::make_pair(nonceStr, hash);
    
}


// Generar JSON de todas las publicaciones sin espacios ni saltos de línea
std::string generarJsonPublicaciones() {
    std::ostringstream dataStream;
    dataStream << "[";

    // Iterar sobre `listaGlobal_publicaciones`
    PublicacionNodo* actual = listaGlobal_publicaciones.getPrimero();
    bool firstPublication = true;

    while (actual != nullptr) {
        if (!firstPublication) {
            dataStream << ",";  // Separador entre publicaciones
        }
        firstPublication = false;

        const Publicacion& pub = actual->getData();
        dataStream << "{"
                   << "\"correo\":\"" << pub.getCorreoP() << "\","
                   << "\"contenido\":\"" << pub.getContenido() << "\","
                   << "\"fecha\":\"" << pub.getFecha() << "\","
                   << "\"hora\":\"" << pub.getHora() << "\","
                   << "\"comentarios\":" << pub.getArbolBComentarios().obtenerComentariosJson()
                   << "}";

        actual = actual->getSig();
    }

    dataStream << "]";
    return dataStream.str();
}

// Función para formatear el JSON de `data`
std::string formatearJson(const std::string& json) {
    std::ostringstream formattedJson;
    int nivelIndentacion = 0;
    bool enString = false;

    for (char c : json) {
        if (c == '\"') {
            enString = !enString;  // Cambia el estado cuando encuentra una comilla doble
        }

        if (!enString) {
            if (c == '{' || c == '[') {
                formattedJson << c << "\n" << std::string(++nivelIndentacion * 4, ' ');
            } else if (c == '}' || c == ']') {
                formattedJson << "\n" << std::string(--nivelIndentacion * 4, ' ') << c;
            } else if (c == ',') {
                formattedJson << c << "\n" << std::string(nivelIndentacion * 4, ' ');
            } else {
                formattedJson << c;
            }
        } else {
            formattedJson << c;
        }
    }

    return formattedJson.str();
}

void escribirJsonBLOCKCHAIN() {
    // Directorio para guardar los archivos JSON de los bloques
    const std::string directorio = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/BLOCKCHAIN/";

    // Itera sobre la lista global de bloques
    Bloque_Nodo* actual = global_listaBlock.getPrimero();  // Asegúrate de que `global_listaBlock` esté bien configurada
    while (actual != nullptr) {
        Bloque& bloque = actual->getDato();  // Accede a los datos del bloque

        // Nombre del archivo con el índice del bloque
        std::string nombreArchivo = directorio + "bpBlockchain_" + std::to_string(bloque.getIndex()) + ".json";
        
        // Crear y abrir el archivo JSON
        std::ofstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
            return;
        }

        // Formatear `data` usando la función `formatearJson`
        std::string dataFormateada = formatearJson(bloque.getData());

        // Generar el contenido JSON del bloque
        archivo << std::setw(4) << "{\n"
                << "  \"INDEX\": " << bloque.getIndex() << ",\n"
                << "  \"TIMESTAMP\": \"" << bloque.getTimestamp() << "\",\n"
                << "  \"NONCE\": " << bloque.getNonce() << ",\n"
                << "  \"DATA\": " << dataFormateada << ",\n"  // Se asume que `getData()` retorna el JSON de `data` formateado
                << "  \"PREVIOUSHASH\": \"" << bloque.getPrev() << "\",\n"
                << "  \"HASH\": \"" << bloque.getHash() << "\",\n"
                << "  \"ROOTMERKLE\": \"" << bloque.getRootMerkle() << "\",\n"
                << "  \"INFORMACIONVALIDA\": " << (bloque.getInformacionValida() ? "true" : "false") << "\n"
                << "}\n";

        // Cerrar el archivo JSON
        archivo.close();

        std::cout << "Archivo " << nombreArchivo << " escrito correctamente.\n";

        // Mover al siguiente bloque en la lista
        actual = actual->getSig();
    }

    global_listaBlock.grafica();
}





/*
void leerbpBlockchain() {
    listaBloques listaBloques_aux;
    const std::string directorio = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/BLOCKCHAIN/";

    DIR* dir;
    struct dirent* entrada;
    
    dir = opendir(directorio.c_str());
    if (dir == nullptr) {
        std::cerr << "No se pudo abrir el directorio" << std::endl;
        return;
    }

    std::vector<std::string> archivos;
    while ((entrada = readdir(dir)) != nullptr) {
        std::string nombreArchivo = entrada->d_name;
        if (nombreArchivo.length() > 5 && nombreArchivo.substr(nombreArchivo.length() - 5) == ".json") {
            archivos.push_back(directorio + nombreArchivo);
        }
    }
    closedir(dir);

    // Procesa los archivos en el orden ordenado
    for (const auto& archivoPath : archivos) {
        std::ifstream archivo(archivoPath);
        if (!archivo.is_open()) {
            std::cerr << "No se pudo abrir el archivo: " << archivoPath << std::endl;
            continue;
        }

        json jsonData;
        archivo >> jsonData;
        archivo.close();

        int index = jsonData["INDEX"];
        std::string timestamp = jsonData["TIMESTAMP"];
        std::string nonce = std::to_string(jsonData["NONCE"].get<int>());
        std::string data = jsonData["DATA"].dump();
        std::string prev = jsonData["PREVIOUSHASH"];
        std::string hash = jsonData["HASH"];
        std::string rootMerkle = jsonData["ROOTMERKLE"];
        bool informacionValida = jsonData["INFORMACIONVALIDA"];

        Bloque nuevoBloque(index, timestamp, data, nonce, prev, hash, rootMerkle);
        std::string rootMerkleVerificada = verficarRootMerkle(data);

        std::string data_Hash;
        data_Hash = std::to_string(index) + timestamp + rootMerkleVerificada + prev;

        auto resultado = determinarNonce(data_Hash);
        std::string nonce_verificado = resultado.first;
        std::string hash_verificado  = resultado.second;

        if (hash_verificado == hash){
            nuevoBloque.setInformacionValida(true);
        }else{
            nuevoBloque.setInformacionValida(false);
        }
            

        listaBloques_aux.append(nuevoBloque);
        listaBloques_aux.grafica();
        std::cout << "Bloque agregado: " << index << std::endl;
    }
}

std::string verficarRootMerkle(std::string& data) {
    const std::string rutaArchivo = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/backupsGenerales/validarINFO.json";

    // Abre el archivo en modo de escritura
    std::ofstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo crear o abrir el archivo: " << rutaArchivo << std::endl;
        return;
    }

    // Escribe `data` tal cual en el archivo
    archivo << data;

    // Cierra el archivo
    archivo.close();

    std::cout << "Archivo 'validarINFO.json' creado y datos escritos exitosamente en: " << rutaArchivo << std::endl;


        // Convertir la ruta de QString a std::string
        std::string rutaArchivo = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/seguridad/backupsGenerales/validarINFO.json";

        // Remover comillas dobles si las hay
        rutaArchivo.erase(std::remove(rutaArchivo.begin(), rutaArchivo.end(), '\"'), rutaArchivo.end());

        // Llamar a la función leerUsuarios() pasando la ruta del archivo
        leerPublicaciones(rutaArchivo);

        std::string rootMerkle;
        rootMerkle = registroArbolMerkle();
        listaGlobal_publicaciones.vaciarLista();
        return rootMerkle;

}*/