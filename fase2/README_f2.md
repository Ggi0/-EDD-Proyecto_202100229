El proyecto que estás desarrollando, según el documento, se titula *Social Structure* y es parte de un curso sobre Estructuras de Datos. En la primera fase, creaste una aplicación de consola que simula una red social utilizando diversas estructuras de datos. En la segunda fase, el enfoque se centra en migrar esa funcionalidad a una aplicación de escritorio con una interfaz gráfica de usuario (GUI), la cual proporcionará una experiencia más intuitiva.

La aplicación incluye las siguientes características clave:

1. **Usuarios**: Los usuarios se gestionarán con un árbol AVL, reemplazando la lista simple anterior, lo que optimizará la búsqueda por correos electrónicos.
2. **Publicaciones**: Se almacenarán en una lista doblemente enlazada y se organizarán en un Árbol Binario de Búsqueda (ABB) según la fecha de las publicaciones, lo que facilitará la búsqueda y visualización cronológica.
3. **Comentarios**: Los comentarios de las publicaciones se almacenarán en un Árbol B de orden 5, que optimiza la inserción y búsqueda eficiente de los comentarios por fecha y hora.
4. **Carga Masiva**: Un administrador podrá cargar datos en masa (usuarios, publicaciones, solicitudes) a través de archivos JSON.
5. **Reportes**: La aplicación deberá generar reportes gráficos utilizando Graphviz, mostrando estructuras como el árbol AVL de usuarios y el ABB de publicaciones.

### Interfaz Gráfica (QT Creator)
La interfaz gráfica que vas a desarrollar con *Qt Creator* será crucial para migrar las funcionalidades de la consola a un entorno visual. Se espera que incluya:

- **Manejo de usuarios**: Visualización y búsqueda eficiente mediante un árbol AVL.
- **Publicaciones**: Un feed interactivo que permita al usuario ver publicaciones filtradas por fecha, gestionadas con un ABB.
- **Comentarios**: Visualización de comentarios asociados a publicaciones, organizados en un Árbol B.
- **Reportes**: Se deben generar y visualizar reportes gráficos directamente dentro de la aplicación, sin necesidad de herramientas externas.

Este proyecto, al utilizar estructuras de datos no lineales y herramientas como Graphviz para visualización, representa una simulación más robusta de una red social, combinando un backend eficiente con una interfaz gráfica moderna.