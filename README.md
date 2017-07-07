# Distributed - Backup
## Práctica 3 Sistemas Operativos Avanzados

Con la ayuda de QtCreator me he servido para crear un DistributedBackup el cual permitira mandar ficheros y archivos entre dos clientes
conectados a un mismo servidor

## Funcionamiento

Este proyecto consiste en un servidor creado en QtCreator a la vez de un conjunto de clientes los cuales se conectaran al servidor en el puerto que en este, se haya asignado.

Se trata de una aplicacion de uso en Terminal en la que:

### Cliente

Cuando abrimos el programa, se nos aparecerán las instrucciones necesarias para saber como hacer funcionar el cliente y como rellenar campos tales como:

+ Address
+ Port
+ Username
+ Save Route
+ Como enviar un archivo

Se ha implementado en el Cliente un telnet propio en el que tenemos un hilo corriendo en el sistema continuamente a la espera de que el usuario escriba una linea en la terminal. 


![Ejemplo Cliente 1](/../master/EJEMPLOCLIENTE1.png)

Como se comento anteriormente, se tendrá que especificar un "Save Route" en el cual se almacenarán los archivos que reciba este Cliente. En la imagen anterior tenemos dos clientes "Kunal" y "Kapil" los cuales han definido un Save Route en /home/kali/Escritorio/FICHEROS-KUNAL/ y /home/kali/Escritorio/FICHEROS-KAPIL/. Además, se puede ver como se han ido enviando una serie de archivos (una imagen y un pdf). Para comprobar que todo ha llegado correctamente, accederemos a las carpetas especificadas (FICHEROS-KUNAL y FICHEROS-KAPIL) y:

![Ejemplo Cliente 1](/../master/COMPROBARQUETODOLLEGA.png)


### Servidor

Cuando abrimos el programa, tal y como pasa con el Cliente, se nos aparecerán las instrucciones necesarias para saber como hacer funcionar el servidor y como rellenar campos tales como:

+ Server Name
+ Port

Un ejemplo de como hacer funcionar el servidor es el siguiente:

![Ejemplo Cliente 1](/../master/SERVIDOR.png)

