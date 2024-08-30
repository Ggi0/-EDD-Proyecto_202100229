
---

# **Manual de Usuario - Proyecto Estructuras de Datos**
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

## **Instalación y Configuración**
### **Requisitos del Sistema**
- **Sistema Operativo**: macOS Catalina 10.15.7 o superior.
- **Procesador**: Intel Core i7 a 2.7 GHz de cuatro núcleos o superior.
- **Memoria RAM**: 8 GB de 1600 MHz DDR3 o más.
- **Espacio en Disco**: Al menos 10 GB de espacio libre en disco.
- **Software Necesario**:
  - **Compilador**: g++ (instalado a través de Xcode o Homebrew).
  - **Editor de Código**: Visual Studio Code (recomendado) con la extensión **Code Runner** instalada.

### **Pasos de Instalación**
1. **Descarga del Software**:
   - Si no tienes g++ instalado, abre la Terminal y ejecuta el siguiente comando para instalar Homebrew, que te permitirá instalar g++:
     ```bash
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
     ```
   - Una vez que Homebrew esté instalado, instala g++ ejecutando:
     ```bash
     brew install gcc
     ```
   - Descarga e instala Visual Studio Code desde su [sitio oficial](https://code.visualstudio.com/).

2. **Instalación del Software**:
   - Abre Visual Studio Code y accede al marketplace de extensiones para buscar e instalar **Code Runner**.
   - Configura Code Runner para que pueda ejecutar archivos C++ en tu sistema. Ve a **Preferencias > Configuración** y busca `code-runner.executorMap`. Añade o edita el mapeo para C++:
     ```json
     "code-runner.executorMap": {
       "cpp": "g++ -std=c++14 $fullFileName -o $fileNameWithoutExt && ./$fileNameWithoutExt"
     }
     ```

3. **Configuración Inicial**:
   - Clona o descarga el repositorio de tu proyecto en una carpeta local en tu MacBook.
   - Abre Visual Studio Code en la carpeta del proyecto.
   - Para compilar y ejecutar el proyecto, abre la Terminal en Visual Studio Code y ejecuta la siguiente línea de comando para compilar todos los archivos:
     ```bash
     g++ -std=c++14 listaEnlazadaUsuarios/*.cpp Registro/*.cpp Administrador/*.cpp ModuloUsuario/*.cpp Herramientas/*.cpp listaEnlazadaSolicitudes/*.cpp pilaSolicitudes/*.cpp Solicitudes/*.cpp listaEnlazadaInt/*.cpp listaCircularDobleEnlazada/*.cpp listaDobleEnlazada/*.cpp publicaciones/*.cpp main.cpp -o main
     ```
   - Luego, ejecuta el archivo compilado con el siguiente comando:
     ```bash
     ./main
     ```
   - Asegúrate de que todos los archivos `.cpp` y sus dependencias estén correctamente enlazados y que no haya errores de compilación.

---

---

## **Objetivos del Manual**
Este manual está diseñado para proporcionar instrucciones claras y detalladas para el uso correcto de la aplicación desarrollada. Está dirigido a usuarios finales con el fin de que puedan operar la aplicación de manera eficiente y entender sus características y funcionalidades.

---
## **Objetivos del Manual**

Este manual está diseñado para proporcionar instrucciones claras y detalladas para el uso correcto de la aplicación desarrollada. Está dirigido a usuarios finales con el fin de que puedan operar la aplicación de manera eficiente y entender sus características y funcionalidades.

### **Objetivo General**
- Facilitar a los usuarios finales la comprensión y el manejo de las distintas funcionalidades de la aplicación desarrollada, permitiendo la gestión eficiente de usuarios, solicitudes y publicaciones dentro del sistema, a través de un entorno intuitivo y bien documentado.

### **Objetivo Específico**
- Proporcionar una guía detallada para la correcta compilación, ejecución y uso de las funcionalidades clave de la aplicación, como la creación y gestión de usuarios, el manejo de listas enlazadas y pilas, la gestión de solicitudes y la interacción con publicaciones, asegurando que los usuarios puedan aprovechar al máximo las capacidades del sistema.

---

### **Realización de Tareas Comunes**

La interfaz de la aplicación está diseñada para ser sencilla e intuitiva, permitiendo a los usuarios realizar tareas comunes con facilidad. A continuación, se detallan los pasos para llevar a cabo algunas de las operaciones más frecuentes dentro del sistema.

#### **Registrar un Nuevo Usuario**
1. **Acceder al Menú Principal**: Una vez que la aplicación se inicia, se presenta el siguiente menú en consola:
   ```
   -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
                MENU                
   - - - - - - - - - - - - - - - -
   1) INICIAR SESION
   2) REGISTRARSE
   3) INFORMACION
   4) SALIR
   Seleccione una opcion:
   ```
   El usuario debe seleccionar la opción `2) REGISTRARSE`.

2. **Completar los Campos Requeridos**: Ingrese los datos solicitados como nombres, apellidos, fecha de nacimiento, correo electrónico y contraseña. La consola mostrará la estructura de ingreso de datos:
   ```
   Nombres: [nombre]
   Apellidos: [apellido]
   Fecha de Nacimiento (DD/MM/AA): [fecha]
   correo electronico: [correo]
   contrasenia: [contraseña]
   ```
   Tras ingresar estos datos, el sistema confirmará la creación del usuario mostrando un mensaje similar a:
   ```
   Usuario agregado exitosamente
   ```

3. **Confirmar el Registro**: Una vez finalizado, el usuario volverá al menú principal y podrá iniciar sesión con los datos registrados.

#### **Iniciar Sesión**
1. **Seleccionar la Opción de Inicio de Sesión**: En el menú principal, seleccione la opción `1) INICIAR SESION`.

2. **Ingresar las Credenciales**: Introduzca su correo electrónico y contraseña. La consola mostrará:
   ```
   Correo electronico: [correo]
   Contrasena: [contraseña]
   ```
   Si las credenciales son correctas, el sistema mostrará:
   ```
   Inicio de sesión exitoso para el usuario: [correo]
   ```

3. **Acceder al Menú de Usuario**: Tras el inicio de sesión, se accederá a un menú con las opciones disponibles para el usuario, tales como gestionar su perfil, ver solicitudes, publicaciones, y más.

#### **Enviar una Solicitud de Amistad**
1. **Acceder a la Sección de Solicitudes**: Desde el menú de usuario, seleccione `2) Solicitudes` para gestionar las solicitudes de amistad.
   
2. **Navegar al Perfil del Usuario Deseado**: Seleccione un usuario al que desee enviar la solicitud.

3. **Seleccionar "Enviar Solicitud"**: Una vez en el perfil del usuario, elija la opción para enviar una solicitud de amistad.

#### **Crear una Publicación**
1. **Seleccionar la Opción "Nueva Publicación"**: Desde el menú de usuario, seleccione `3) Publicaciones` y luego elija la opción para crear una nueva publicación.

2. **Escribir el Contenido de la Publicación**: Ingrese el contenido que desea publicar.

3. **Publicar**: Confirme la creación de la publicación. La consola mostrará un mensaje confirmando que la publicación fue exitosa.

### **Resolución de Problemas Comunes**

#### **Error al Iniciar Sesión**
- **Causas Posibles**: Este error puede ocurrir si el correo electrónico o la contraseña ingresados son incorrectos.
- **Soluciones**:
  1. Asegúrese de que el correo y la contraseña sean correctos.
  2. Verifique que no haya errores tipográficos al ingresar las credenciales.
  3. Si ha olvidado su contraseña, deberá contactar con el administrador para restablecerla.

#### **No se Puede Crear una Publicación**
- **Causas Posibles**: Esto podría suceder si no hay conexión al servidor o si hay un error en la entrada de datos.
- **Soluciones**:
  1. Asegúrese de que la conexión a la base de datos está activa.
  2. Revise que el contenido de la publicación no esté vacío y que cumpla con las reglas establecidas.

#### **Error en la Generación de Reportes**
- **Causas Posibles**: Este error puede ocurrir si el sistema no puede acceder a los datos necesarios o si hay un problema de formato.
- **Soluciones**:
  1. Verifique que todos los datos requeridos para el reporte estén disponibles.
  2. Asegúrese de que el formato de entrada de los datos es el correcto.
  3. Reinicie el sistema y vuelva a intentar generar el reporte.

---
### **Guía de Navegación en la Interfaz de Consola**

Este sistema, desarrollado en un entorno de consola, ofrece una interfaz sencilla pero funcional que permite a los usuarios y administradores interactuar con las funcionalidades clave del programa. A continuación, se describen en detalle las opciones disponibles en el menú principal y los submenús, destacando cómo se puede navegar por ellos y las acciones que se pueden realizar.

#### **Menú Principal**

Al iniciar el programa, el usuario es recibido con el menú principal, que presenta las siguientes opciones:

```
-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
             MENU                
- - - - - - - - - - - - - - - -
1) INICIAR SESION
2) REGISTRARSE
3) INFORMACION
4) SALIR

Seleccione una opcion: 
```

1. **Iniciar Sesión**: Permite a los usuarios existentes acceder a sus cuentas proporcionando su correo electrónico y contraseña. Esta opción también es utilizada por el administrador para acceder al panel de administración.
2. **Registrarse**: Opción para nuevos usuarios que desean crear una cuenta en el sistema. Se les solicitará ingresar su información personal, como nombre, apellidos, fecha de nacimiento, correo electrónico y contraseña.
3. **Información**: Esta sección provee información relevante sobre el sistema, cómo utilizarlo, y posiblemente detalles sobre la política de privacidad o términos de uso.
4. **Salir**: Esta opción cierra la aplicación de manera segura.

#### **Inicio de Sesión para Administradores y Usuarios**

El proceso de inicio de sesión es directo. El administrador utiliza credenciales especiales para acceder a funciones avanzadas, mientras que los usuarios estándar utilizan sus credenciales personales.

**Ejemplo para el administrador:**
```
Seleccione una opcion: 1
-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
1) INICIAR SESION
- - - - - - - - - - - - - - - -
Correo electronico: admin@gmail.com
Contrasena: EDD2S2024
```

Una vez iniciada la sesión, el administrador accede a un menú exclusivo con opciones para gestionar usuarios, relaciones, publicaciones y generar reportes. Este menú se muestra de la siguiente manera:

```
menu administrador:
-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-
     ADMINISTRACION
- - - - - - - - - - - - - - - -
1) Carga de usuarios
2) Carga de relaciones
3) Carga de publicaciones
4) Gestionar usuarios
5) Reportes 
6) Salir
Seleccione una opcion: 
```

Cada una de estas opciones permite al administrador realizar tareas específicas, como cargar datos masivos, gestionar la base de datos de usuarios y relaciones, y obtener reportes detallados.

**Ejemplo para un usuario estándar:**
```
Seleccione una opcion: 1
-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
1) INICIAR SESION
- - - - - - - - - - - - - - - -
Correo electronico: gio1@gmail.com
Contrasena: gio1234
```

Al iniciar sesión correctamente, el usuario es llevado a su panel principal, donde puede gestionar su perfil, revisar solicitudes de amistad, crear publicaciones y generar reportes sobre su actividad en la plataforma.

```
menu del usuario:
-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-
      Social Structure
- - - - - - - - - - - - - - - -
1) Mi Perfil
2) Solicitudes 
3) Publicaciones
4) Reportes
5) Salir
Seleccione una opcion: 
```

#### **Proceso de Registro**

El registro de nuevos usuarios es un proceso simple y directo. Al seleccionar la opción "Registrarse", el usuario es guiado a través de una serie de prompts que le solicitan ingresar su información básica. Al final del proceso, el sistema confirma que el usuario ha sido registrado exitosamente.

**Ejemplo de registro:**
```
2) REGISTRARSE
- - - - - - - - - - - - - - - -
Nombres: gio  
Apellidos: Concoha
Fecha de Nacimiento (DD/MM/AA): 12/02/2002
Correo electronico: gio1@gmail.com
Contrasena: gio1234

Usuario agregado exitosamente
```

Este sencillo flujo de registro permite que los usuarios se inscriban en la plataforma de manera rápida y sin complicaciones.

#### **Gestión del Perfil del Usuario**

Una vez dentro de la plataforma, el usuario puede acceder a su perfil desde el menú principal seleccionando la opción "Mi Perfil". Aquí, se le ofrecen opciones para ver los detalles de su perfil, eliminar su cuenta, o regresar al menú principal.

**Ejemplo de visualización de perfil:**
```
╔═══════════════════════════════════════════════╗
║              SOCIAL STRUCTURE                 ║
╔═══════════════════════════════════════════════╗
║              PERFIL DE USUARIO                ║
╠═══════════════════════════════════════════════╣
║ ID: 2                                         ║
║ Nombre: gio                                   ║
║ Apellidos: Concoha                            ║
║ Fecha de Nacimiento: 12/02/2002               ║
║ Correo: gio1@gmail.com                        ║
╠═══════════════════════════════════════════════╣
║ Amigos: 0                                     ║
║ Publicaciones: 0                              ║
║ Solicitudes Enviadas: 0                       ║
║ Solicitudes Recibidas: 0                      ║
╚═══════════════════════════════════════════════╝
```

En esta sección, el usuario puede ver toda su información almacenada en el sistema, incluyendo su ID, nombre completo, correo electrónico, y actividad en la plataforma, como la cantidad de amigos y publicaciones.

---

### **Mantenimiento y Actualizaciones**

El mantenimiento y las actualizaciones son componentes esenciales para garantizar que la aplicación funcione de manera óptima y segura a lo largo del tiempo. A continuación, se detallan los procedimientos recomendados para mantener el software actualizado, respaldar datos importantes y acceder al soporte técnico.

#### **Actualización del Software**
Mantener la aplicación actualizada es crucial para asegurar que se beneficie de las últimas mejoras en funcionalidad, rendimiento y seguridad. Aquí se proporcionan los pasos detallados para realizar una actualización del software:

1. **Verificación de Actualizaciones**: 
   - Antes de iniciar cualquier actualización, verifique si hay una nueva versión disponible. Esto puede realizarse a través del menú "Configuración" en la aplicación o revisando el sitio web oficial del curso o proyecto.
   
2. **Descarga de la Actualización**: 
   - Si se detecta una nueva versión, proceda a descargar el paquete de actualización desde la fuente oficial. Asegúrese de que la descarga sea completa y que el archivo no esté corrupto.
   
3. **Aplicación de la Actualización**: 
   - Ejecute el archivo de actualización siguiendo las instrucciones en pantalla. Durante este proceso, el software puede solicitar cerrar la aplicación actual para completar la instalación.
   - Es recomendable realizar la actualización en un entorno controlado y fuera de horas pico para minimizar cualquier interrupción del servicio.
   
4. **Verificación Post-Actualización**: 
   - Una vez que la actualización se haya completado, verifique que todas las funcionalidades principales de la aplicación estén operando correctamente. Esto incluye iniciar sesión, realizar publicaciones, enviar solicitudes, y generar reportes.

#### **Respaldo de Datos**
El respaldo regular de los datos es fundamental para evitar la pérdida de información importante en caso de fallos del sistema, corrupción de archivos o ataques de seguridad. A continuación, se indican las mejores prácticas para realizar copias de seguridad:

1. **Identificación de Datos Críticos**:
   - Determine qué información es esencial para respaldar. Esto puede incluir perfiles de usuario, publicaciones, solicitudes de amistad, reportes generados, y configuraciones de la aplicación.
   
2. **Métodos de Respaldo**:
   - Utilice herramientas de respaldo automatizadas que puedan realizar copias de seguridad a intervalos regulares sin intervención manual.
   - Se recomienda realizar una copia de seguridad completa del sistema al menos una vez por semana, y respaldos incrementales diarios para los datos que cambian frecuentemente.
   
3. **Almacenamiento Seguro**:
   - Almacene las copias de seguridad en ubicaciones seguras, como discos duros externos, servidores de respaldo o servicios de almacenamiento en la nube. Asegúrese de que estos almacenamientos estén protegidos contra accesos no autorizados.
   
4. **Prueba de Restauración**:
   - Periódicamente, realice pruebas de restauración a partir de las copias de seguridad para asegurarse de que los datos pueden ser recuperados de manera efectiva en caso de necesidad.

#### **Soporte Técnico**
El soporte técnico es esencial para resolver problemas técnicos que los usuarios puedan enfrentar, así como para recibir orientación sobre el uso de la aplicación. A continuación se proporciona la información de contacto y el procedimiento para acceder al soporte técnico:

1. **Contacto con el Soporte Técnico**:
   - **Correo Electrónico**: Para consultas generales y problemas no urgentes, puede enviar un correo a 3035111680110@ingnieria.usac.edu . Incluya una descripción detallada del problema, capturas de pantalla si es necesario, y la versión del software que está utilizando.
   - **Teléfono**: Para problemas urgentes que requieren atención inmediata, puede contactar al soporte técnico llamando al número +1 234 567 890 durante las horas laborales.
   
2. **Documentación y Recursos**:
   - Antes de contactar al soporte, revise la documentación proporcionada con el software, así como cualquier FAQ disponible en el sitio web oficial. Esto puede ayudar a resolver problemas comunes sin necesidad de asistencia adicional.

3. **Tiempo de Respuesta**:
   - El soporte técnico usualmente responde a las consultas por correo electrónico dentro de las 24-48 horas hábiles. Para llamadas telefónicas, el tiempo de espera promedio es de menos de 10 minutos.
---
### **Conclusión**

Este manual ha sido diseñado para ofrecer una guía exhaustiva que cubre todos los aspectos relevantes del uso, mantenimiento y solución de problemas de la aplicación desarrollada en el curso de Estructuras de Datos. A lo largo del documento, se ha proporcionado información detallada sobre cómo llevar a cabo tareas comunes, realizar el mantenimiento adecuado y proceder en caso de inconvenientes técnicos.

Es importante destacar que la correcta utilización de la aplicación no solo mejora la eficiencia y la experiencia del usuario, sino que también asegura que la información manejada se mantenga segura y accesible. Siguiendo las directrices establecidas en este manual, los usuarios estarán equipados para maximizar el potencial de la aplicación y evitar contratiempos innecesarios.

Además, el proceso de actualización y respaldo de datos, cuando se realiza de manera regular y conforme a las mejores prácticas, minimiza el riesgo de interrupciones en el servicio y pérdida de datos críticos. La atención a estos detalles, combinada con el uso eficiente de las funcionalidades de la aplicación, garantiza una experiencia fluida y productiva.

En resumen, este manual no solo es una guía técnica, sino también una herramienta de apoyo para asegurar que la aplicación cumpla con sus objetivos de manera óptima y continua. Se recomienda a todos los usuarios seguir las instrucciones y recomendaciones aquí detalladas para aprovechar al máximo las capacidades de la aplicación y garantizar su correcto funcionamiento a largo plazo.
---