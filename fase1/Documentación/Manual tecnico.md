# **Manual de Tecnico - Proyecto Estructuras de Datos**
## **Fase 1 - 2024**

### **Universidad de San Carlos de Guatemala**
**Facultad de Ingeniería**  
**Escuela de Ciencias y Sistemas**  
**Curso: Estructuras de Datos**  
**Ingeniero: Edgar Ornelis**  
**Auxiliares: José Montenegro**  
**Programador: Giovanni Saul Concohá Cax**  
**Carne: 202100229**  
**Correo: 3035111680110@ingenieria.usac.edu.gt**  

---



#### **1. Descripción General**

Este manual técnico proporciona una visión detallada del sistema desarrollado, que es una aplicación de consola en C++ diseñada para la gestión de usuarios, relaciones y publicaciones en una plataforma tipo red social. El sistema incluye funcionalidades tanto para usuarios finales como para administradores, y está compuesto por diversos módulos interconectados. Las tecnologías utilizadas en este proyecto incluyen C++, el compilador `g++`, la herramienta `Graphviz` para la generación de reportes visuales y la librería `json.hh` para la manipulación de datos en formato JSON.

---

### **2. Estructura del Proyecto**

El proyecto está organizado en varias carpetas y archivos, cada uno con una responsabilidad específica:

- **/Administrador**: Contiene el código relacionado con las funcionalidades del administrador del sistema, como la gestión de usuarios y generación de reportes.

- **/archivos Json**: Almacena archivos JSON que son utilizados por el sistema para guardar o leer configuraciones y datos específicos.

- **/Documentación**: Esta carpeta incluye la documentación del proyecto, con archivos como el Manual de Usuario y el Manual Técnico en formato Markdown (.md).

- **/Herramientas**: Incluye herramientas o utilidades auxiliares que apoyan las funcionalidades principales del sistema.

- **/listaCircularDobleEnlazada**: Contiene la implementación de la estructura de datos Lista Circular Doble Enlazada utilizada en el proyecto.

- **/listaDobleEnlazada**: Contiene la implementación de la estructura de datos Lista Doble Enlazada utilizada en el proyecto.

- **/listaEnlazadaInt**: Implementación de una lista enlazada de enteros, probablemente para propósitos específicos dentro del proyecto.

- **/listaEnlazadaSolicitudes**: Contiene el código relacionado con la gestión de solicitudes, utilizando una lista simplemente enlazada.

- **/listaEnlazadaUsuarios**: Almacena la implementación de la lista simplemente enlazada de usuarios, crucial para la gestión de usuarios en el sistema.

- **/ModuloUsuario**: Incluye los componentes que gestionan la interacción del usuario con el sistema, como menús y funcionalidades relacionadas.

- **/pilaSolicitudes**: Implementa una pila para gestionar las solicitudes dentro del sistema.

- **/publicaciones**: Contiene el código relacionado con la gestión de publicaciones dentro de la plataforma.

- **/Registro**: Incluye clases y funciones relacionadas con el registro y manejo de datos de los usuarios.

- **/Solicitudes**: Almacena funcionalidades específicas para la gestión y administración de solicitudes.

- **main.cpp**: Archivo principal donde se inicia la ejecución del programa.

- **README_f1.md**: Archivo de documentación específico para la fase 1 del proyecto.

- **tempCodeRunnerFile.cpp**: Archivo temporal generado por el entorno de desarrollo para ejecutar fragmentos de código.

---

***Nota:*** La estructura del proyecto se puede expandir en fases posteriores (fase2, fase3), donde se integrarán nuevas funcionalidades o módulos adicionales según los requerimientos del proyecto.
---

#### **3. Tecnologías Utilizadas**

- **C++**: Lenguaje de programación utilizado para desarrollar todo el sistema. Se hace uso intensivo de la orientación a objetos y estructuras de datos como listas enlazadas, pilas, y árboles para gestionar las funcionalidades del sistema.

- **g++**: Compilador de GNU utilizado para compilar el código C++. Para compilar el proyecto, se utiliza el siguiente comando en la terminal:

  ```bash
  g++ -o bin/social_structure src/*.cpp -Iinclude -std=c++11
  ```

- **Graphviz**: Herramienta para la visualización de grafos. Se utiliza para generar reportes en forma de gráficos que muestran las relaciones entre los usuarios, el número de publicaciones, y otras estadísticas importantes. Los reportes son generados en archivos con extensión `.dot`, que luego pueden ser convertidos a formatos de imagen como `.png` o `.pdf` utilizando el siguiente comando:

  ```bash
  dot -Tpng reports/usuarios.dot -o reports/usuarios.png
  ```

- **json.hh**: Biblioteca JSON para C++ utilizada para la serialización y deserialización de datos en formato JSON. Esto permite que la información del sistema (como usuarios y relaciones) se almacene y se recupere de manera eficiente.

---

#### **4. Detalle del Código**

##### **4.1. Clases Principales**

 ### Explicación de la Clase `Usuarios`

La clase `Usuarios` es una de las clases más importantes del proyecto, ya que representa a los usuarios del sistema y encapsula todas las funcionalidades relacionadas con la gestión de estos. A continuación, se detalla cada uno de sus componentes clave:

#### **Atributos**

1. **Datos personales del usuario:**
   - **int ID**: Identificador único del usuario. 
   - **static int contadorID**: Contador estático utilizado para asignar IDs únicos automáticamente a los nuevos usuarios.
   - **std::string nombres**: Nombre o nombres del usuario.
   - **std::string apellidos**: Apellidos del usuario.
   - **std::string fechaN**: Fecha de nacimiento del usuario.
   - **std::string correo**: Correo electrónico, que también puede servir como identificador único en algunos contextos.
   - **std::string contrasenia**: Contraseña del usuario, almacenada como cadena de texto.

2. **Estructuras de datos relacionadas:**
   - **arrayList_soli listaSolicitudes**: Lista simplemente enlazada que almacena las solicitudes enviadas o recibidas por el usuario.
   - **solicitud_pila pilaSolicitudes**: Pila de solicitudes que puede almacenar solicitudes en un orden particular (LIFO: Last In, First Out).
   - **listaSimpleEnlazada lista_amigos**: Lista simplemente enlazada que contiene los IDs de los amigos del usuario.
   - **ListaCircular_Dpp lista_publicacionesP**: Lista circular doblemente enlazada que contiene las publicaciones hechas por el usuario.

#### **Constructores**

- **Usuarios()**: Constructor por defecto que inicializa los atributos básicos del usuario.
- **Usuarios(std::string nombres, std::string apellidos, std::string fechaN, std::string correo, std::string contrasenia)**: Constructor parametrizado que permite crear un usuario asignando sus datos personales.

#### **Destructores**

- **~Usuarios()**: Destructor de la clase `Usuarios` que se encarga de liberar recursos si es necesario.

#### **Getters y Setters**

Estos métodos permiten acceder y modificar los atributos privados del usuario:

- **int getID()**: Devuelve el ID del usuario.
- **std::string getNombres()**, **getApellidos()**, **getFechaN()**, **getCorreo()**, **getContrasenia()**: Devuelven los valores correspondientes de los atributos personales.
- **arrayList_soli& getListaSolicitudes()**, **solicitud_pila& getPilaSolicitudes()**, **listaSimpleEnlazada& getLista_amigos()**, **ListaCircular_Dpp& getLista_publicacionesP()**: Devuelven referencias a las estructuras de datos asociadas con el usuario.
- **void setID(int ID)**, **setNombres(std::string& nombre)**, **setApellidos(std::string& apellidos)**, **setFechaN(std::string& fecha)**, **setCorreo(std::string& correo)**, **setContrasenia(std::string& contrasena)**: Permiten modificar los datos personales del usuario.
- **void setListaSolicitudes(const arrayList_soli& listaSolicitudes)**, **setPilaSolicitudes(const solicitud_pila& pilaSolicitudes)**, **setLista_amigos(const listaSimpleEnlazada& lista_amigos)**, **setLista_publicacionesP(const ListaCircular_Dpp& lista_publicacionesP)**: Permiten modificar las estructuras de datos asociadas.

#### **Métodos Funcionales**

- **void printUsuario()**: Imprime en consola los datos del usuario.
- **void asignarID()**: Asigna un ID único al usuario usando `contadorID`.
- **void guardarUsuario()**: Guarda los datos del usuario en un archivo o base de datos.
- **void graficarUsuario()**: Genera gráficos visuales relacionados con los datos del usuario, como su red de amigos o publicaciones.

#### **Manejo de Solicitudes**

- **void agregarSolicitud(const Solicitud& solicitud)**: Agrega una solicitud a la lista de solicitudes del usuario.
- **void agregarSolicitudPila(const Solicitud& solicitud)**: Agrega una solicitud a la pila de solicitudes del usuario.

#### **Gestión de Amigos**

- **void agregarAmigo(int idAmigo)**: Agrega un amigo a la lista de amigos del usuario, usando su ID.
- **void eliminarAmigo(int idAmigo)**: Elimina un amigo de la lista de amigos.
- **bool esAmigo(int idAmigo)**: Verifica si un ID corresponde a un amigo del usuario.
- **void imprimirAmigos()**: Imprime la lista de amigos del usuario.

#### **Gestión de Publicaciones**

- **void agregarPublicacion(const Publicacion& publicacion)**: Agrega una publicación a la lista de publicaciones del usuario.
- **void eliminarPublicacion(const std::string& correo)**: Elimina una publicación específica según el correo del usuario que la realizó.
- **bool tienePublicacion(const std::string& correo) const**: Verifica si el usuario tiene una publicación relacionada con el correo dado.
- **void imprimirPublicaciones() const**: Imprime todas las publicaciones del usuario.
  
#### **Métodos de Gráfica**

- **void graficaAmigos() const**: Genera una gráfica de la lista de amigos del usuario.

---

### **Importancia en el Proyecto**

La clase `Usuarios` es central para el proyecto, ya que es la representación básica de cualquier entidad de usuario en el sistema. Controla y maneja todas las interacciones y datos asociados con los usuarios, desde solicitudes de amistad hasta publicaciones y gráficos. Además, su diseño modular permite extender las funcionalidades del sistema fácilmente, simplemente agregando o modificando los métodos y atributos en la clase.

##### **4.2. Uso de la Librería JSON**

La librería `json.hh` se utiliza para convertir objetos del sistema a formato JSON y viceversa. Esto es útil para guardar el estado del sistema o para compartir datos entre diferentes componentes. A continuación se presenta un ejemplo de cómo se usa esta librería para serializar un objeto `Usuario`:

```cpp
#include "json.hh"

void guardarUsuarioEnJSON(const Usuario& usuario, const std::string& archivo) {
    nlohmann::json j;
    j["nombre"] = usuario.getNombre();
    j["apellidos"] = usuario.getApellidos();
    j["correo"] = usuario.getCorreo();
    j["fechaNacimiento"] = usuario.getFechaNacimiento();
    // Otros campos...

    std::ofstream file(archivo);
    file << j.dump(4); // Indentar con 4 espacios
}

Usuario cargarUsuarioDeJSON(const std::string& archivo) {
    std::ifstream file(archivo);
    nlohmann::json j;
    file >> j;
  
    Usuario usuario(j["nombre"], j["apellidos"], j["correo"], j["contrasena"]);
    // Otros campos...

    return usuario;
}
```

##### **4.3. Generación de Reportes con Graphviz**

Los reportes en `Graphviz` se generan a partir de la estructura interna del sistema. Por ejemplo, se puede generar un reporte de la red de amigos de un usuario utilizando el siguiente código:

```cpp
void generarReporteDeAmigos(const Usuario& usuario) {
    std::ofstream file("reports/amigos.dot");
    file << "digraph G {\n";
    file << "  \"" << usuario.getNombre() << "\" [shape=box];\n";

    for (const auto& amigo : usuario.getListaAmigos()) {
        file << "  \"" << usuario.getNombre() << "\" -> \"" << amigo.getNombre() << "\";\n";
    }
  
    file << "}\n";
    file.close();
}
```

Este código crea un archivo `.dot` que luego puede ser procesado con `Graphviz` para visualizar la red de amigos del usuario.

---
### Explicación de la Clase `arrayList_us`

La clase `arrayList_us` es una implementación de una lista enlazada personalizada que almacena objetos de tipo `Usuarios`. Proporciona varias funcionalidades para gestionar esta lista, como insertar, eliminar, buscar, y graficar usuarios. Aquí se detalla cada uno de sus componentes clave:

#### **Atributos**

- **usuarios_Nodo *primero**: Puntero al primer nodo de la lista.
- **usuarios_Nodo *ultimo**: Puntero al último nodo de la lista.

#### **Constructores y Destructores**

- **arrayList_us()**: Constructor por defecto que inicializa la lista enlazada con punteros `primero` y `ultimo` como `nullptr`, indicando que la lista está vacía.
- **~arrayList_us()**: Destructor que se encarga de liberar la memoria utilizada por los nodos en la lista. Recorre la lista y elimina cada nodo.

#### **Métodos Principales**

1. **Inserción de Usuarios:**
   - **void push(Usuarios usuario)**: Inserta un nuevo usuario al principio de la lista. Si la lista está vacía, el nodo insertado se convierte tanto en el `primero` como en el `ultimo`.
   - **void append(Usuarios usuario)**: Inserta un nuevo usuario al final de la lista. Similar al método anterior, pero añade el nodo al final de la lista.

2. **Eliminación de Usuarios:**
   - **void pop()**: Elimina el último nodo de la lista. Si la lista tiene un solo nodo, se elimina y se actualizan los punteros `primero` y `ultimo` a `nullptr`.
   - **void removeIf(bool (*condition)(const Usuarios&))**: Elimina nodos de la lista basados en una condición pasada como función. Recorre la lista, y si un nodo cumple la condición, se elimina de la lista.
   - **void eliminarUsuario(const std::string& correo)**: Elimina un nodo específico de la lista, cuyo usuario tiene el correo electrónico pasado como parámetro.

3. **Búsqueda de Usuarios:**
   - **Usuarios* buscarPorCorreo(const std::string& correo)**: Busca un usuario en la lista por su correo electrónico. Retorna un puntero al usuario si lo encuentra, de lo contrario retorna `nullptr`.
   - **Usuarios* buscarPorID(int id)**: Busca un usuario en la lista por su ID. Retorna un puntero al usuario si lo encuentra, de lo contrario retorna `nullptr`.
   - **Usuarios* buscarUsuarioPorID(int id) const**: Similar al método anterior, pero es una versión constante del método de búsqueda por ID.

4. **Otras Operaciones:**
   - **int size()**: Retorna el número de nodos (usuarios) en la lista.
   - **void printAll()**: Imprime la información de todos los usuarios en la lista, usando el método `printUsuario` de la clase `Usuarios`.

5. **Métodos de Graficación:**
   - **void graficar() const**: Genera un archivo `.dot` para visualizar la lista de usuarios utilizando Graphviz. Cada nodo en la lista se representa con su ID, nombre, apellidos y correo.
   - **void graficarTop5ConMasPublicaciones()**: Genera un archivo `.dot` con los 5 usuarios que tienen más publicaciones, visualizándolos en orden descendente.
   - **void graficarTop5ConMenosAmigos()**: Genera un archivo `.dot` con los 5 usuarios que tienen menos amigos, visualizándolos en orden ascendente.

6. **Top 5 Usuarios:**
   - **std::vector<Usuarios*> top5UsuariosConMasPublicaciones()**: Retorna un vector con punteros a los 5 usuarios que tienen más publicaciones, ordenados en orden descendente.
   - **std::vector<Usuarios*> top5UsuariosConMenosAmigos()**: Retorna un vector con punteros a los 5 usuarios que tienen menos amigos, ordenados en orden ascendente.

#### **Métodos de Acceso (Getters y Setters)**

- **usuarios_Nodo* getPrimero()**: Devuelve el puntero al primer nodo de la lista.
- **usuarios_Nodo* getUltimo()**: Devuelve el puntero al último nodo de la lista.
- **void setPrimero(usuarios_Nodo* nuevoPrimero)**: Establece el puntero `primero` al nodo pasado como parámetro. Si `primero` se establece como `nullptr`, también se actualiza `ultimo` a `nullptr`.
- **void setUltimo(usuarios_Nodo* nuevoUltimo)**: Establece el puntero `ultimo` al nodo pasado como parámetro. Si `ultimo` se establece como `nullptr`, también se actualiza `primero` a `nullptr`.

### **Importancia en el Proyecto**

La clase `arrayList_us` es fundamental para la gestión de usuarios en el sistema. Proporciona una estructura de datos flexible para almacenar y manipular objetos `Usuarios`. Los métodos de inserción, eliminación, búsqueda y graficación permiten gestionar de manera eficiente los datos de los usuarios, incluyendo funcionalidades avanzadas como el análisis de los 5 usuarios con más publicaciones o menos amigos. Esta clase forma el núcleo de la lógica de almacenamiento y manipulación de usuarios en el proyecto.

---

#### **5. Compilación y Ejecución**

Para compilar el proyecto, asegúrese de que todos los archivos `.cpp` y `.h` estén en las ubicaciones correctas. Utilice el siguiente comando en la terminal:

```bash
g++ -o bin/social_structure src/*.cpp -Iinclude -std=c++11
```

Luego, para ejecutar el programa:

```bash
./bin/social_structure
```

---

### 1. **Lista Simplemente Enlazada**
Una lista simplemente enlazada es una colección de elementos llamados nodos, donde cada nodo contiene dos partes:
- **Dato**: El valor que almacena el nodo.
- **Puntero**: Una referencia al siguiente nodo en la lista.

**Características:**
- **Acceso Secuencial**: Solo se puede acceder a los elementos de manera secuencial, desde el primer nodo hasta el último.
- **Inserción y Eliminación**: Las operaciones de inserción y eliminación son eficientes cuando se realizan al principio de la lista (O(1)). Sin embargo, insertar o eliminar en posiciones intermedias o finales puede ser costoso (O(n)).
- **Memoria**: Consume menos memoria que otras estructuras, como listas doblemente enlazadas, ya que solo necesita un puntero por nodo.

**Uso en el Proyecto:**
- **Lista de Solicitudes**: La lista simplemente enlazada se utiliza para manejar solicitudes de amistad o conexión en el sistema. Esta estructura es adecuada para este caso, ya que las operaciones de inserción y eliminación no requieren acceso directo a elementos intermedios.

### 2. **Lista Doblemente Enlazada**
Una lista doblemente enlazada es similar a una lista simplemente enlazada, pero cada nodo tiene dos punteros:
- **Puntero al Siguiente**: Referencia al siguiente nodo.
- **Puntero al Anterior**: Referencia al nodo anterior.

**Características:**
- **Acceso Bidireccional**: Permite recorrer la lista en ambos sentidos (hacia adelante y hacia atrás).
- **Mayor Costo en Memoria**: Requiere más memoria que una lista simplemente enlazada debido al segundo puntero.
- **Inserción y Eliminación Eficientes**: Las operaciones son eficientes en cualquier posición (O(1)) si se tiene una referencia directa al nodo, aunque la búsqueda de un nodo específico puede ser costosa (O(n)).

**Uso en el Proyecto:**
- **Lista de Amigos**: Esta estructura se puede utilizar para gestionar amigos del usuario, permitiendo recorrer la lista en ambas direcciones, lo cual es útil para operaciones que necesitan acceso tanto al nodo siguiente como al anterior.

### 3. **Lista Circular Doblemente Enlazada**
Una lista circular doblemente enlazada es una variación de la lista doblemente enlazada donde:
- **El último nodo apunta al primero**: Y el primer nodo apunta al último, formando un círculo.
  
**Características:**
- **Acceso Continuo**: Se puede recorrer la lista indefinidamente en cualquier dirección.
- **Eficiente para Ciertas Operaciones**: Adecuada para aplicaciones donde se requiere un acceso cíclico, como en sistemas de turnos.

**Uso en el Proyecto:**
- **Lista de Publicaciones**: Ideal para gestionar publicaciones de usuarios, permitiendo un recorrido continuo de publicaciones sin tener que volver a iniciar el recorrido desde el principio o el final de la lista.

### 4. **Pila**
Una pila es una estructura de datos que sigue el principio LIFO (Last In, First Out), donde:
- **Último en entrar, primero en salir**: Los elementos se insertan y se eliminan desde la parte superior de la pila.

**Características:**
- **Operaciones Principales**:
  - **Push**: Inserta un elemento en la parte superior.
  - **Pop**: Elimina el elemento en la parte superior.
  - **Top/Peek**: Devuelve el elemento en la parte superior sin eliminarlo.
- **Aplicaciones**: Útil en situaciones que requieren un seguimiento de tareas pendientes, como deshacer acciones.

**Uso en el Proyecto:**
- **Pila de Solicitudes**: Gestiona las solicitudes de usuarios de manera que la última solicitud enviada es la primera en ser procesada o atendida.

### 5. **Matriz Dispersa**
Una matriz dispersa es una estructura optimizada para almacenar matrices con un gran número de elementos nulos (ceros o valores por defecto). En lugar de almacenar todos los elementos, solo se almacenan los elementos no nulos junto con sus índices.

**Características:**
- **Ahorro de Espacio**: Ahorra una cantidad significativa de espacio cuando la mayoría de los elementos son nulos.
- **Representación Eficiente**: Se utiliza una estructura de datos como una lista enlazada o un diccionario para representar los elementos no nulos y sus posiciones.
- **Aplicaciones**: Útil en aplicaciones como representación de grafos, matrices de adyacencia en grafos dispersos, y almacenamiento de grandes conjuntos de datos donde la mayoría de los datos son cero.

**Uso en el Proyecto:**
- **Uso Potencial**: En proyectos más complejos, podría utilizarse para representar conexiones entre usuarios (por ejemplo, amistades) o interacciones donde la mayoría de las posibles conexiones no existen (son nulas).

### **Resumen**
Cada una de estas estructuras de datos tiene características específicas que las hacen adecuadas para diferentes partes del proyecto. Su elección influye directamente en la eficiencia y el rendimiento del sistema, optimizando el manejo de datos como usuarios, solicitudes, amigos y publicaciones. En un manual técnico, este análisis permite entender la razón detrás de cada elección y cómo cada estructura se adapta a los requerimientos funcionales del sistema.

---
### **6. Mantenimiento y Actualizaciones**

El mantenimiento y las actualizaciones son esenciales para asegurar la longevidad y el correcto funcionamiento del sistema. Este apartado cubre las prácticas recomendadas para mantener el código, realizar respaldos de datos y generar reportes, así como la integración de nuevas características.

#### **6.1. Actualización del Software**

Con el tiempo, será necesario realizar actualizaciones y mejoras en el código fuente para agregar nuevas funcionalidades, corregir errores o mejorar el rendimiento del sistema. Para garantizar que estas actualizaciones se integren de manera eficiente, siga los pasos detallados a continuación:

1. **Modificación del Código Fuente**:
   - Asegúrese de que cualquier cambio en el código sea compatible con las estructuras de datos existentes, como listas enlazadas, pilas y matrices dispersas.
   - Utilice un control de versiones, como `Git`, para rastrear los cambios en el código y facilitar la colaboración entre diferentes desarrolladores.

2. **Recompilación del Proyecto**:
   - Después de realizar cambios en el código, recompile el proyecto utilizando el compilador `g++`. 
   - Ejecute el siguiente comando en la terminal, asumiendo que el archivo principal es `main.cpp`:
     ```bash
     g++ -o proyecto main.cpp -std=c++11
     ```
   - Incluya todas las dependencias necesarias, como archivos `.hh` y `.cpp`, para asegurar que el proyecto se compile correctamente sin errores.

3. **Pruebas de Regresión**:
   - Ejecute pruebas de regresión para verificar que los cambios no hayan introducido errores en el sistema. 
   - Asegúrese de probar todas las funciones principales, incluidas las que manejan listas enlazadas, listas dobles, pilas y matrices dispersas.

4. **Documentación**:
   - Actualice la documentación técnica y de usuario cada vez que se realicen cambios importantes en el código. 
   - Describa cualquier nueva funcionalidad y los cambios en la lógica del sistema.

#### **6.2. Respaldo de Datos**

El sistema maneja datos críticos sobre usuarios, sus relaciones y actividades. Para evitar la pérdida de datos, es crucial realizar copias de seguridad regulares:

1. **Archivos JSON**:
   - Los datos de los usuarios y las relaciones se almacenan en archivos JSON. Realice copias de seguridad periódicas de estos archivos para proteger los datos contra fallos del sistema o corrupción de archivos.
   - Utilice un script automatizado para copiar los archivos JSON a un servidor seguro o a un almacenamiento en la nube. Por ejemplo:
     ```bash
     cp usuarios.json /ruta/a/backup/
     ```

2. **Frecuencia de Respaldo**:
   - Programe respaldos diarios o semanales, dependiendo del volumen de cambios en los datos.
   - Mantenga múltiples versiones de las copias de seguridad para poder restaurar datos en caso de que una copia reciente esté corrupta.

3. **Restauración de Datos**:
   - Documente el proceso de restauración de datos desde las copias de seguridad, asegurando que el equipo de mantenimiento pueda restaurar rápidamente los datos en caso de una emergencia.

#### **6.3. Generación de Nuevos Reportes**

Los reportes gráficos son fundamentales para analizar y visualizar las relaciones y actividades de los usuarios dentro del sistema. Para generar y actualizar estos reportes, siga los siguientes pasos:

1. **Ejecución de Graphviz**:
   - Utilice `Graphviz` para convertir archivos `.dot` en imágenes visuales que representen las estructuras de datos como listas de usuarios y sus relaciones.
   - Ejecute el comando `dot` de `Graphviz` en la terminal para generar un gráfico, por ejemplo:
     ```bash
     dot -Tpng listaGlobal_usuarios.dot -o listaGlobal_usuarios.png
     ```

2. **Actualización de Reportes**:
   - Generar nuevos reportes cada vez que se produzcan cambios significativos en los datos, como la adición o eliminación de usuarios, o cuando se modifiquen relaciones entre ellos.
   - Mantenga un registro de las versiones anteriores de los reportes para analizar la evolución del sistema.

3. **Automatización**:
   - Considere la automatización del proceso de generación de reportes mediante scripts que se ejecuten después de actualizaciones en los datos. Esto asegurará que siempre se disponga de la versión más reciente de los reportes.

4. **Integración de Reportes**:
   - Integre los reportes generados en las interfaces de usuario del sistema para facilitar la visualización y análisis de datos por parte de los usuarios y administradores.

### **7. Conclusión**

Este manual técnico proporciona una guía integral para el desarrollo, mantenimiento y evolución del sistema. La implementación de estructuras de datos robustas como listas simplemente enlazadas, listas doblemente enlazadas, pilas y matrices dispersas, combinada con tecnologías como C++, `g++`, `Graphviz`, y la librería `json.hh`, crea un sistema altamente eficiente y escalable.

#### **7.1. Mejores Prácticas de Programación**
- **Modularidad**: Mantenga el código modular y organizado en clases y métodos claramente definidos. Esto no solo mejora la legibilidad del código sino que también facilita el mantenimiento y la extensión del sistema.
- **Uso Eficiente de Estructuras de Datos**: Seleccione las estructuras de datos más apropiadas para cada operación, teniendo en cuenta la complejidad en tiempo y espacio. Por ejemplo, utilice listas simplemente enlazadas para operaciones que requieren inserciones rápidas al principio de la lista y pilas para manejar elementos en un orden LIFO.
---
#### **7.2. Mantenimiento Continuo**
- **Monitoreo y Actualización**: Monitoree constantemente el rendimiento del sistema y actualice el software y la documentación según sea necesario. Asegúrese de que las actualizaciones no comprometan la integridad del sistema.
- **Copias de Seguridad Regulares**: Realice copias de seguridad regulares para proteger los datos del sistema. Un plan de respaldo sólido es esencial para prevenir la pérdida de datos y asegurar la continuidad del servicio.

#### **7.3. Evolución del Sistema**
- **Escalabilidad**: El sistema está diseñado para ser escalable. A medida que la base de usuarios crezca, las estructuras de datos como las listas doblemente enlazadas y las matrices dispersas permitirán manejar el aumento de complejidad sin comprometer el rendimiento.
- **Extensibilidad**: Gracias a la modularidad del código, es fácil agregar nuevas funcionalidades. Siga las mejores prácticas de codificación y documentación para garantizar que futuras modificaciones se integren de manera fluida.

Seguir las directrices establecidas en este manual asegurará el desarrollo continuo y la evolución exitosa del sistema, manteniéndolo eficiente, seguro y adaptable a las necesidades futuras.
---