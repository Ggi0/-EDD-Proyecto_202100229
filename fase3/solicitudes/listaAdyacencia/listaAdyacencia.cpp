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