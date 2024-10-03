### **Manual Técnico - Proyecto Estructuras de Datos (Fase 2)**

## **Universidad de San Carlos de Guatemala**
**Facultad de Ingeniería**  
**Escuela de Ciencias y Sistemas**  
**Curso: Estructuras de Datos**  
**Ingenieros:**  
- **Luis Espino**  
- **Edgar Ornelis**  
- **Álvaro Hernández**  

**Auxiliares:**  
- **Kevin Martinez**  
- **Carlos Castro**  
- **José Montenegro**

**Programador:**  
Giovanni Saul Concohá Cax  
**Carne:** 202100229  
**Correo:** 3035111680110@ingenieria.usac.edu.gt  

---

## **1. Descripción General**

Este proyecto consiste en el desarrollo de una aplicación de escritorio con interfaz gráfica de usuario (GUI) utilizando **Qt Creator IDE** y **qmake** como compilador, para simular una red social con gestión de usuarios, publicaciones, y comentarios, además de incorporar estructuras no lineales avanzadas para optimizar la eficiencia de las operaciones. La fase 2 extiende el sistema implementado en la fase 1, donde se utilizó una aplicación de consola en C++.

### **Objetivo General**
Aplicar los conocimientos del curso de Estructuras de Datos para desarrollar soluciones de software basadas en estructuras no lineales.

### **Objetivos Específicos**
- Implementar estructuras como Árboles AVL, ABB y Árboles B en C++.
- Utilizar **Graphviz** para graficar las estructuras de datos.
- Migrar las funcionalidades de la consola a una GUI.
- Desarrollar algoritmos de búsqueda, recorrido y eliminación en estructuras no lineales.

---

## **2. Estructura del Proyecto**

El proyecto está dividido en varios módulos:

### **/Administrador**
Implementa las funcionalidades administrativas, como la gestión de usuarios y generación de reportes.

### **/archivosJson**
Almacena y carga archivos JSON para usuarios, solicitudes y publicaciones.

### **/listaDobleEnlazada**
Contiene la implementación de una lista doblemente enlazada, utilizada para almacenar publicaciones de usuarios.

### **/ArbolAVL**
Implementación del árbol AVL para gestionar usuarios, optimizando búsquedas por correo electrónico.

### **/ArbolABB**
Árbol Binario de Búsqueda utilizado para organizar las publicaciones de los usuarios por fecha.

### **/ArbolB**
Implementación del Árbol B para gestionar comentarios en publicaciones, indexando los comentarios por fecha y hora.

---

## **3. Tecnologías Utilizadas**

- **Lenguaje de programación:** C++
- **Entorno de Desarrollo:** Qt Creator IDE
- **Compilador:** qmake
- **Gráficas:** Generación de gráficos con **Graphviz**
- **JSON:** Librería **nlohmann/json.hpp** para manipulación de archivos JSON

---

## **4. Detalle del Código**

### **4.1. Implementación de Estructuras de Datos**

### **Explicación de las Estructuras Utilizadas en el Proyecto**

#### **1. Árbol AVL**

El **árbol AVL** es una variante de árbol binario de búsqueda que se mantiene balanceado automáticamente. Esto significa que, tras cada inserción o eliminación, el árbol se ajusta para garantizar que la diferencia de altura entre los subárboles izquierdo y derecho de cualquier nodo no sea mayor que 1. Esto asegura un rendimiento óptimo en operaciones de búsqueda, inserción y eliminación, con una complejidad de \(O(\log n)\).

**Código del Árbol AVL:**
```cpp
class AVL {
    private:
        NodoAVL *raiz; // Raíz del árbol AVL

        NodoAVL* insert(NodoAVL *raiz, Usuarios data); // Inserción de un nodo
        NodoAVL* del(NodoAVL *raiz, Usuarios data); // Eliminación de un nodo
        NodoAVL* rotacionIzquierda(NodoAVL *raiz); // Rotación izquierda para balancear el árbol
        NodoAVL* rotacionDerecha(NodoAVL *raiz); // Rotación derecha para balancear el árbol
        NodoAVL* obtenerMayorDeMenores(NodoAVL *raiz); // Obtener el mayor nodo del subárbol izquierdo

        int alturaMaxima(int izq, int drch); // Comparación de alturas de subárboles
        int obtenerAltura(NodoAVL *raiz); // Altura del árbol
        int obtenerBalance(NodoAVL *raiz); // Factor de balance

        // Recorridos y gráficos
        void postOrden(NodoAVL *raiz, bool accion); 
        void preOrden(NodoAVL *raiz); 
        void inOrden(NodoAVL *raiz);
        void graph(NodoAVL *raiz, std::ofstream &f); // Graficar árbol
    public:
        AVL(); // Constructor
        ~AVL(); // Destructor
        void insert(Usuarios data); // Método público de inserción
        void del(Usuarios data); // Método público de eliminación
        void graph(); // Generar gráfico del árbol
};
```

**Propósito:**
- Se utiliza para gestionar los usuarios del sistema, permitiendo búsquedas rápidas de usuarios por correo electrónico o ID. El balance automático del árbol asegura que la estructura no se degrade en rendimiento con el tiempo.

---

#### **2. Árbol Binario de Búsqueda (ABB)**

El **árbol binario de búsqueda (ABB)** es una estructura donde cada nodo tiene dos subárboles: uno izquierdo (con valores menores que el nodo) y uno derecho (con valores mayores). En este caso, el ABB organiza las publicaciones por fecha, permitiendo un acceso eficiente a publicaciones realizadas en fechas específicas.

**Código del ABB:**
```cpp
class BST {
    private:
        NodoBST *raiz; // Raíz del árbol binario de búsqueda

        // Métodos auxiliares de recorrido y gráfico
        void postOrden(NodoBST *raiz, bool accion); 
        void preOrden(NodoBST *raiz); 
        void inOrden(NodoBST *raiz); 
        void graph(NodoBST *raiz, std::ofstream &f); 

        // Método auxiliar para insertar un nodo en el ABB
        NodoBST* insertAndGetNodeHelper(NodoBST* nodo, const std::string& fechaID);
    public:
        BST(); // Constructor
        ~BST(); // Destructor
        NodoBST* insertAndGetNode(const std::string& fechaID); // Inserta y devuelve el nodo
        void graph() const; // Generar gráfico del ABB
        NodoBST* buscarNodoPorFecha(const std::string& fecha); // Buscar nodo por fecha
};
```

**Propósito:**
- Se utiliza para almacenar las publicaciones en orden cronológico. Cada nodo en el ABB contiene una lista de publicaciones realizadas en la misma fecha. Esto permite realizar consultas eficientes sobre publicaciones de fechas específicas y ordenar el feed de manera cronológica.

---

#### **3. Árbol B**

El **árbol B** es una estructura de datos balanceada que permite almacenar grandes volúmenes de datos. Los árboles B se utilizan cuando es necesario mantener ordenados grandes conjuntos de datos y realizar operaciones de búsqueda, inserción y eliminación de manera eficiente, incluso cuando los datos no caben en la memoria principal. En este caso, el árbol B almacena los comentarios de las publicaciones, utilizando la fecha y la hora como criterios de ordenación.

**Código del Árbol B:**
```cpp
class ArbolB {
    private:
        Nodo_b* raiz; // Raíz del árbol B
        int t; // Grado mínimo del árbol B

        // Métodos auxiliares para dividir nodos e insertar elementos
        void dividirHijo(Nodo_b* padre, int indice, Nodo_b* hijo);
        void insertarNoLleno(Nodo_b* nodo, const Comentario& clave);
        Comentario* buscarRecursivo(Nodo_b* nodo, const Comentario& clave);
        void borrarDe(Nodo_b* nodo, const Comentario& clave);

        // Métodos auxiliares para recorrer el árbol en inorden y graficar
        void recorridoInordenAux(Nodo_b* nodo) const;
        void grafoAux(Nodo_b* nodo, std::ofstream& outfile);

    public:
        ArbolB(); // Constructor
        ~ArbolB(); // Destructor
        void insertar(const Comentario& clave); // Insertar comentario
        void borrar(const Comentario& clave); // Eliminar comentario
        Comentario* buscar(const Comentario& clave); // Buscar comentario
        void recorridoInorden() const; // Recorrer árbol en inorden
        void graficar(); // Generar gráfico del árbol
};
```

**Propósito:**
- Se utiliza para gestionar los comentarios en las publicaciones. Cada publicación está asociada a un árbol B, donde los comentarios se almacenan en un nodo balanceado, permitiendo búsquedas eficientes por fecha y hora. Esta estructura es ideal para manejar grandes volúmenes de comentarios, asegurando que las operaciones de inserción y eliminación sean rápidas.

---

### **Comparación de las Estructuras**

| Estructura  | Uso en el Proyecto                   | Complejidad de Operaciones | Propósito Principal                                      |
|-------------|--------------------------------------|----------------------------|---------------------------------------------------------|
| **AVL**     | Gestión de usuarios                  | \(O(\log n)\)               | Búsqueda eficiente y balanceada de usuarios por correo o ID. |
| **ABB**     | Almacenamiento de publicaciones      | \(O(\log n)\)               | Organización cronológica de publicaciones por fecha.    |
| **Árbol B** | Gestión de comentarios en publicaciones | \(O(\log n)\)               | Manejo eficiente de grandes volúmenes de comentarios.    |

Estas tres estructuras se complementan para proporcionar un sistema robusto y escalable, donde cada tipo de dato tiene su propio mecanismo de almacenamiento y acceso optimizado.

---

### **4.2. Migración a GUI**

La interfaz gráfica fue desarrollada utilizando **Qt Creator IDE**, migrando las funcionalidades de la consola hacia un entorno visual. Esto incluye:
- **Ventana Principal:** Contiene el feed de publicaciones y opciones para filtrar.
- **Gestión de Usuarios:** Interfaz para que el administrador gestione los usuarios mediante operaciones sobre el Árbol AVL.
- **Comentarios:** Permite ver y agregar comentarios a las publicaciones, gestionados por un Árbol B.

---

## **5. Reportes Generados**

Utilizando **Graphviz**, se generan reportes gráficos de las estructuras de datos:

### **Árbol AVL (Usuarios)**
- Graficado en Preorden, Inorden y Postorden para visualizar la organización de los usuarios.

### **Árbol ABB (Publicaciones)**
- Graficado en Inorden para mostrar el feed de publicaciones de cada usuario.

### **Árbol B (Comentarios)**
- Muestra la jerarquía de comentarios en cada publicación, ordenados cronológicamente.

---

### **6. Integración del Backend con la Interfaz Gráfica (GUI)**

La conexión entre la lógica del backend (estructuras de datos y funcionalidades) y el frontend (interfaz gráfica desarrollada con Qt) se realiza utilizando un archivo de configuración `*.pro` en Qt Creator. Este archivo es esencial para que el proyecto compile y enlace correctamente todos los módulos y directorios. A continuación, se presenta una configuración que integra todos los componentes necesarios.

#### **Archivo de Configuración `*.pro`**
El siguiente archivo define la estructura del proyecto y especifica las rutas a los diferentes módulos de backend, que incluyen la gestión de usuarios, solicitudes, publicaciones y comentarios, así como las interfaces gráficas que interactúan con estos módulos.

```plaintext
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Define directories
USUARIOS_DIR = $$PWD/../../usuarios
ARBOLAVL_DIR = $$USUARIOS_DIR/arbolAVL
LISTAAMIGOS_DIR = $$USUARIOS_DIR/listaEnlazadaInt
SOLICITUDES_DIR = $$PWD/../../solicitudes
LISTSOLICITUDES_DIR = $$SOLICITUDES_DIR/listaEnlazadaSolicitudes
PILASOLICITUDES_DIR = $$SOLICITUDES_DIR/pilaSolicitudes
PUBLICACIONES_DIR = $$PWD/../../publicaciones
ARBOLBB_DIR = $$PUBLICACIONES_DIR/arbolBinario
COMENTARIOS_DIR = $$PUBLICACIONES_DIR/comentario
LISTACOMENTARIOS_DIR = $$COMENTARIOS_DIR/listaComentarios
ARBOLB_DIR = $$COMENTARIOS_DIR/arbolB
LISTADEPUBLI_DIR = $$PUBLICACIONES_DIR/listaDobleEnlazada
ADMIN_DIR = $$PWD/../../administracion

SOURCES += \
    form_admin.cpp \
    form_registrarusuarios.cpp \
    form_usuario.cpp \
    main.cpp \
    mainwindow.cpp \
    $$PUBLICACIONES_DIR/*.cpp \
    $$USUARIOS_DIR/*.cpp \
    $$ARBOLAVL_DIR/*.cpp \
    $$LISTAAMIGOS_DIR/*.cpp \
    $$SOLICITUDES_DIR/*.cpp \
    $$LISTSOLICITUDES_DIR/*.cpp \
    $$PILASOLICITUDES_DIR/*.cpp \
    $$ARBOLBB_DIR/*.cpp \
    $$COMENTARIOS_DIR/*.cpp \
    $$LISTADEPUBLI_DIR/*.cpp \
    $$LISTACOMENTARIOS_DIR/*.cpp \
    $$ARBOLB_DIR/*.cpp \
    $$ADMIN_DIR/*.cpp

HEADERS += \
    form_admin.h \
    form_registrarusuarios.h \
    form_usuario.h \
    mainwindow.h \
    $$PUBLICACIONES_DIR/*.h \
    $$USUARIOS_DIR/*.h \
    $$ARBOLAVL_DIR/*.h \
    $$LISTAAMIGOS_DIR/*.h \
    $$SOLICITUDES_DIR/*.h \
    $$LISTSOLICITUDES_DIR/*.h \
    $$PILASOLICITUDES_DIR/*.h \
    $$ARBOLBB_DIR/*.h \
    $$COMENTARIOS_DIR/*.h \
    $$LISTADEPUBLI_DIR/*.h \
    $$LISTACOMENTARIOS_DIR/*.h \
    $$ARBOLB_DIR/*.h \
    $$ADMIN_DIR/*.h

FORMS += \
    form_admin.ui \
    form_registrarusuarios.ui \
    form_usuario.ui \
    mainwindow.ui

# Include directories
INCLUDEPATH += \
    $$USUARIOS_DIR \
    $$ARBOLAVL_DIR \
    $$LISTAAMIGOS_DIR \
    $$SOLICITUDES_DIR \
    $$LISTSOLICITUDES_DIR \
    $$PILASOLICITUDES_DIR \
    $$PUBLICACIONES_DIR \
    $$ARBOLBB_DIR \
    $$COMENTARIOS_DIR \
    $$LISTACOMENTARIOS_DIR \
    $$ARBOLB_DIR \
    $$LISTADEPUBLI_DIR \
    $$ADMIN_DIR

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
```

#### **Explicación del Archivo de Configuración**

1. **Módulos Qt Utilizados**:  
   - **core** y **gui**: Son necesarios para el funcionamiento básico de la aplicación Qt.
   - **widgets**: Añadido si la versión de Qt es mayor a 4, permitiendo el uso de componentes visuales como formularios y ventanas.

2. **Directorio de Archivos Fuentes y Headers**:  
   Las rutas de los archivos **`.cpp`** (fuentes) y **`.h`** (headers) están organizadas en directorios según el tipo de estructura de datos o funcionalidad (usuarios, solicitudes, publicaciones, comentarios, etc.). El archivo asegura que todos los archivos relevantes sean incluidos en el proyecto.

3. **Archivos UI**:  
   Los archivos **`.ui`** correspondientes a los formularios diseñados en **Qt Designer** son mencionados bajo la sección `FORMS`. Estos archivos se traducen automáticamente a C++ al compilar el proyecto.

4. **Include Path**:  
   El archivo especifica los directorios donde se encuentran los archivos **header** de cada uno de los módulos, para que puedan ser incluidos correctamente en el proyecto.

#### **Proceso de Compilación y Ejecución**

Para compilar el proyecto con esta configuración en **Qt Creator**:

1. **Configuración del Proyecto**:  
   Asegúrese de que el archivo **`.pro`** esté correctamente configurado en su entorno Qt Creator. Si el proyecto aún no está configurado, seleccione "Abrir proyecto" en Qt Creator y elija este archivo.

2. **Compilación**:  
   Utilice el botón "Compilar" en Qt Creator o ejecute el comando:

   ```bash
   qmake
   make
   ```


Este archivo de configuración proporciona el enlace entre la lógica backend, que maneja toda la gestión de datos, y el frontend, que es la interfaz gráfica interactiva que los usuarios finales utilizarán.

---

## **8. Mantenimiento y Actualizaciones**

### **Mantenimiento**
- **Control de versiones:** Utilice **Git** para manejar las actualizaciones.
- **Pruebas:** Asegúrese de que los algoritmos de inserción, búsqueda y eliminación mantengan la eficiencia y la integridad de los datos.

### **Actualización**
Cuando se realicen actualizaciones importantes, es esencial probar la consistencia de las estructuras no lineales para evitar desbalanceos en los árboles o pérdida de datos.

---
### **10. Instalación de Qt Creator IDE (Versión Open Source)**

A continuación, se describen los pasos detallados para instalar **Qt Creator** en su versión de código abierto desde la página oficial. Qt Creator es el entorno de desarrollo integrado (IDE) que se utilizará para desarrollar la interfaz gráfica (GUI) del proyecto.

#### **Paso 1: Visitar el Sitio Oficial de Qt**
1. Abra su navegador web y diríjase a la página oficial de **Qt**:
   - [https://www.qt.io/download](https://www.qt.io/download)

2. En la página de inicio, encontrará varias opciones. Busque y haga clic en el botón que dice **"Go open source"** para acceder a la versión gratuita de Qt Creator.

#### **Paso 2: Descargar Qt Open Source**
1. Al hacer clic en **"Go open source"**, será redirigido a la página de descarga de **Qt Open Source**.
2. Aquí, haga clic en el botón **"Download the Qt Online Installer"** para comenzar la descarga del instalador en línea.
   - Esto descargará un archivo ejecutable que es el instalador de Qt.

#### **Paso 3: Ejecutar el Instalador de Qt**
1. Una vez descargado el instalador, localice el archivo (por lo general, en la carpeta de descargas) y ejecútelo.
   - En **Windows**, el archivo será algo como `qt-unified-windows-x86-64-xxx-online.exe`.
   - En **macOS**, será algo como `qt-unified-mac-x64-xxx-online.dmg`.
   - En **Linux**, será un archivo `.run`, como `qt-unified-linux-x64-xxx-online.run`. 
   
2. Al ejecutar el instalador, Qt le pedirá crear una cuenta de Qt o iniciar sesión con una cuenta existente. Si no tiene una cuenta, puede crear una de forma gratuita.

#### **Paso 4: Seleccionar Componentes para la Instalación**
1. Después de iniciar sesión, Qt le mostrará una lista de versiones y componentes para instalar. Asegúrese de seleccionar los siguientes componentes:
   - **Qt Creator**: Seleccione la última versión estable del IDE.
   - **Qt para C++**: Elija la versión más reciente de Qt que sea compatible con su sistema operativo.
   - **Herramientas Adicionales** (opcional): Dependiendo de su sistema, puede seleccionar otros componentes adicionales, como los kits de compilación (Mingw para Windows).

2. Si está en **Windows**, seleccione el compilador **MinGW** en las opciones disponibles para asegurarse de que pueda compilar sus proyectos.

3. Para **Linux** y **macOS**, Qt normalmente utilizará el compilador **GCC** (Linux) o **Clang** (macOS) que ya están instalados en el sistema.

#### **Paso 5: Iniciar la Instalación**
1. Después de seleccionar los componentes deseados, haga clic en el botón **"Next"** y luego en **"Install"**.
2. El proceso de instalación descargará los componentes seleccionados, lo que puede tardar varios minutos dependiendo de la velocidad de su conexión a internet.

#### **Paso 6: Verificar la Instalación**
1. Una vez finalizada la instalación, abra **Qt Creator** desde el menú de aplicaciones de su sistema.
2. Verifique que Qt Creator esté correctamente configurado creando un nuevo proyecto.
   - Para hacerlo, vaya a **File** > **New File or Project** y seleccione **Qt Widgets Application**.
   - Siga los pasos indicados para crear su proyecto y asegúrese de que el IDE detecte el compilador y las herramientas necesarias.



---

### **Conclusiones**

1. **Optimización del Rendimiento mediante Estructuras de Datos No Lineales**:  
   La implementación de estructuras avanzadas como el Árbol AVL, ABB y Árbol B ha permitido optimizar el manejo de datos complejos en la plataforma, proporcionando un rendimiento eficiente en operaciones clave como la búsqueda, inserción y eliminación de usuarios, publicaciones y comentarios. Estas estructuras garantizan un acceso rápido y balanceado, mejorando la escalabilidad del sistema.

2. **Migración Exitosa a una Interfaz Gráfica Usando Qt Creator**:  
   La migración de la aplicación de consola a una interfaz gráfica (GUI) utilizando **Qt Creator** ha resultado en una experiencia de usuario más accesible e intuitiva. Gracias a la flexibilidad y robustez de Qt, se ha logrado una integración eficiente del backend con el frontend, manteniendo la lógica del sistema intacta y permitiendo a los usuarios interactuar con el sistema de manera visual.

3. **Escalabilidad y Mantenimiento del Proyecto a Largo Plazo**:  
   La estructura modular del proyecto, junto con el uso de herramientas como **Graphviz** para la visualización de datos y **Git** para el control de versiones, garantiza que el sistema sea fácilmente escalable y mantenible. Esto asegura que futuras fases del proyecto o nuevas funcionalidades puedan integrarse sin afectar el rendimiento o la estabilidad del sistema.