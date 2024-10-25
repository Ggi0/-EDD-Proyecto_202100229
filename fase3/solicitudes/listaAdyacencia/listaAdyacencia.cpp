#include "listaAdyacencia.h"

listaAdyacencia::listaAdyacencia(){
    this->cabeza = nullptr;
}

listaAdyacencia::~listaAdyacencia(){
    vnodo *aux = this->cabeza;
    vnodo *temp;

    while(aux != nullptr){
        temp = aux->getSiguiente();
        delete aux;
        aux = temp;
    }
}

void listaAdyacencia::insert(Usuarios vertice){
    if(this->cabeza == nullptr){
        this->cabeza = new vnodo();
        this->cabeza->setData(vertice);

    }else{
        vnodo *nuevo = new vnodo();
        nuevo->setData(vertice);

        if(vertice.getID() < this->cabeza->getData().getID()){
            nuevo->setSiguiente(cabeza);
            this->cabeza = nuevo;
        
        }else{
            vnodo *aux = this->cabeza;
            while(aux->getSiguiente() != nullptr){
                if(vertice.getID() < aux->getSiguiente()->getData().getID()){
                    nuevo->setSiguiente(aux->getSiguiente());
                    aux->setSiguiente(nuevo);
                    break;
                } 
                aux = aux->getSiguiente();
            }

            if(aux->getSiguiente() == nullptr){
                aux->setSiguiente(nuevo);
            }
        }
    }
}

void listaAdyacencia::crearConexion(Usuarios origen, Usuarios destino){
    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        if(aux->getData().getID() == origen.getID()){
            aux->insertarDestino(destino);
            break;
        }
        aux = aux->getSiguiente();
    }
}

void listaAdyacencia::crearGrafo(){
    // Ruta donde deseas guardar el archivo .dot y .png
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/usuarios/reportes/";

    std::ofstream outfile (outputDir + "grafo.dot");
    outfile << "digraph G {" << std::endl;

    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        // Obtener el ID y el nombre del usuario para el nodo
        int id = aux->getData().getID();
        std::string nombre = aux->getData().getNombres();

        // Construir el string para el nodo con ID y nombre
        std::string dec_nodo = "Nodo" + std::to_string(id) + " [label = \"ID: " + std::to_string(id) + "\\nNombre: " + nombre + "\"];";
        outfile << dec_nodo << std::endl;

        // Graficar las aristas
        aux->graficarAristas(outfile);

        // Avanzar al siguiente nodo
        aux = aux->getSiguiente();
    }

    outfile << "}" << std::endl;
    outfile.close();
    // Comando para generar el archivo .png usando dot, especificando la ruta completa
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "grafo.dot -o " + outputDir + "grafo.png";
    // Ejecutar el comando
    int returnCode = system(dotCommand.c_str());

    //int returnCode = system("/opt/local/bin/dot -Tpng ./grafo.dot -o ./grafo.png");

    if(returnCode == 0){
        std::cout << "(Grafico grafo) Command executed successfully." << std::endl;}
    else{
        std::cout << "(Grafico grafo) Command execution failed or returned non-zero: " << returnCode << std::endl;}
}

void listaAdyacencia::crearGrafoLista(){
    // Ruta donde deseas guardar el archivo .dot y .png
    std::string outputDir = "/Users/gio/Desktop/Edd_2s24/lab_edd_2s24/-EDD-Proyecto_202100229/fase3/usuarios/reportes/";

    std::ofstream outfile (outputDir + "grafoLista.dot");
    outfile << "digraph G {" << std::endl;
    outfile << "node[shape = \"box\" style = \"filled\"]" << std::endl;

    vnodo *aux = this->cabeza;
    while(aux != nullptr){
        // Obtener el ID y el nombre del usuario
        int id = aux->getData().getID();
        std::string nombreUsuario = aux->getData().getNombres();

        // Crear el string para el nodo con ID y nombre
        std::string nombre = "Nodo" + std::to_string(id) + 
                             "[label = \"ID: " + std::to_string(id) + 
                             "\\nNombre: " + nombreUsuario + 
                             "\" group = \"1\" fillcolor=\"lightgray\"];";
        outfile << nombre << std::endl;

        // Si hay un nodo siguiente, graficar la conexión
        if(aux->getSiguiente() != nullptr){
            outfile << "Nodo" + std::to_string(id) + "->Nodo" + std::to_string(aux->getSiguiente()->getData().getID()) + "[dir = none];";
        }

        // Graficar las conexiones con los destinos
        aux->graficarListaDestinos(outfile);
        aux = aux->getSiguiente();
    }

    outfile << "}" << std::endl;
    outfile.close();

    // Comando para generar el archivo .png usando dot, especificando la ruta completa
    std::string dotCommand = "/opt/local/bin/dot -Tpng " + outputDir + "grafoLista.dot -o " + outputDir + "grafoLista.png";
    // Ejecutar el comando
    int returnCode = system(dotCommand.c_str());

    //int returnCode = system("/opt/local/bin/dot -Tpng ./grafoLista.dot -o ./grafoLista.png");

    if(returnCode == 0){
        std::cout << "(Grafico lista) Command executed successfully." << std::endl;}
    else{
        std::cout << "(Grafico lista) Command execution failed or returned non-zero: " << returnCode << std::endl;}  
}


// ------------ sugerencias -----------------
listaSugerencias* listaAdyacencia::sugerirAmistades(std::string correo) {
    listaSugerencias* sugerencias = new listaSugerencias();
    
    // Encontrar el usuario por correo
    vnodo* usuarioActual = this->cabeza;
    while (usuarioActual != nullptr && usuarioActual->getData().getCorreo() != correo) {
        usuarioActual = usuarioActual->getSiguiente();
    }
    
    if (usuarioActual == nullptr) return sugerencias;  // Usuario no encontrado
    
    // Obtener la lista de amigos directos del usuario
    std::set<int> amigosDirectos;
    enodo* amigo = usuarioActual->getDestinos();
    while (amigo != nullptr) {
        amigosDirectos.insert(amigo->getDestino().getID());
        amigo = amigo->getSiguiente();
    }
    
    // Para cada amigo del usuario
    amigo = usuarioActual->getDestinos();
    while (amigo != nullptr) {
        // Para cada amigo del amigo (potencial sugerencia)
        vnodo* amigoNodo = this->cabeza;
        while (amigoNodo != nullptr && amigoNodo->getData().getID() != amigo->getDestino().getID()) {
            amigoNodo = amigoNodo->getSiguiente();
        }
        
        if (amigoNodo != nullptr) {
            enodo* amigoDeAmigo = amigoNodo->getDestinos();
            while (amigoDeAmigo != nullptr) {
                int idSugerido = amigoDeAmigo->getDestino().getID();
                
                // Si no es el usuario original y no es un amigo directo
                if (idSugerido != usuarioActual->getData().getID() && 
                    amigosDirectos.find(idSugerido) == amigosDirectos.end()) {
                    
                    // Contar amigos en común
                    int amigosEnComun = 0;
                    vnodo* sugerido = this->cabeza;
                    while (sugerido != nullptr && sugerido->getData().getID() != idSugerido) {
                        sugerido = sugerido->getSiguiente();
                    }
                    
                    if (sugerido != nullptr) {
                        enodo* amigoSugerido = sugerido->getDestinos();
                        while (amigoSugerido != nullptr) {
                            if (amigosDirectos.find(amigoSugerido->getDestino().getID()) != 
                                amigosDirectos.end()) {
                                amigosEnComun++;
                            }
                            amigoSugerido = amigoSugerido->getSiguiente();
                        }
                        
                        sugerencias->insertarOrdenado(
                            sugerido->getData().getID(),
                            sugerido->getData().getNombres(),
                            amigosEnComun
                        );
                    }
                }
                amigoDeAmigo = amigoDeAmigo->getSiguiente();
            }
        }
        amigo = amigo->getSiguiente();
    }
    
    return sugerencias;
}
