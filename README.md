# Blockchain

El presente proyecto consiste en la implementación de una "BlockChain" en base a las estructuras que se han visto previamente en clase (Listas enlazadas, Arboles binarios, etc.) y otras que son derivadas de las estructuras bases con las que hemos trabajado, pero que dependiendo de en qué caso trabajemos están mejor optimizadas (B Tree, ChainHash, etc). En las siguientes secciones se podrá visualizar mejor la implementación y documentación respecto a estas, así como los casos de estudio para los cuales resultan más pertinentes.

------------------------------------------------------------------------------------------------------------------------------
# Casos de estudio

Si bien la tecnología **BlockChain** es asociada principalmente a las criptomonedas como bitcoin, Ethereum, etc. Su uso no se limita a estas de hecho, se prevé que en los próximos años muchas corporaciones alrededor del mundo inviertan en servicios técnicos de **BlockChain**.  
Es en esta situación que resulta de importancia estudiar los casos para los cuales la aplicación de esta tecnología resulte favorable.
## Sistema de votaciones  

Un sistema de votaciones resulta en un caso importante por las repercusiones que tendría una mala ejecución del mismo, sin embargo, con el uso de tecnologías **BlockChain**, no debería representar un problema.  
Lo primero que debemos considerar es la transparencia, privacidad y confianza que implica un sistema como este, poder acceder a todos los votos realizados para poder realizar un conteo transparente, sin exponer los datos de los votantes ni de sus votos.  
 En la actualidad ya existen plataformas que permitan manejar un caso como el sistema de votaciones (Voatz), quienes toman todas las precauciones que se deben considerar sin poner en riesgo alguno de los principios mencionados (transparencia, privacidad y confianza).  
 
<img src="https://user-images.githubusercontent.com/102536323/205092267-043e7c2d-c71a-482e-9939-bea792f29599.png"  width="25%"  heiht="25%">
[https://voatz.com/](https://voatz.com/)

## Transferencias de dinero

La transferencia de dinero es un tema muy importante en un mundo donde la globalización ha virtualizado casi todas nuestras acciones. El proceso de transferir dinero se hace a diario y cada vez más personas prefieren realizarlo por internet o un aplicativo movil, muchas veces poniéndose en riesgo en que una mala ejecución de su banco los lleve a perder todo. Es en este contexto que el uso de la tecnología **BlockChain** pueda volverse no solo una alternativa, sino una solución. Una de las principales razones por la cual muchas empresas ya están implementando esta tecnología en su ecosistema es que está tecnología es también una tecnología de registro distribuido, lo que implica que la información que maneja es replicada, compartida y sincronizada, y finalmente distribuida geográficamente a través de múltiples sitios. Una de las compañías que ya ha implementado el uso de esta tecnología es Everex, una firma con sede en Singapur.

![image](https://user-images.githubusercontent.com/102536323/205092400-4ee0ce33-4e85-4c92-879d-9d5904c8e150.png)

[https://everex.io/](https://everex.io/)

------------------------------------------------------------------------------------------------------------------------------

# Importancia de BlockChain

La tecnología que usamos para el Blockchain cumple varios requisitos muy importantes en la actualidad, permitiéndonos poder contar con maneras nuevasde realizar actividades complejas. Entre las necesidades que cubre el Blockchain encontramos la ciberseguridad, rapidez y simple manera de utilizar.

------------------------------------------------------------------------------------------------------------------------------

# Integridad del contenido

------------------------------------------------------------------------------------------------------------------------------

# Estructuras de datos
## Forward List (Simple Linked List)
Estructura de datos que consiste en el enlazamiento simple de nodos, donde cada nodo almacena algún elemento o conjunto de elementos y un enlace al nodo posterior mas no al previo. Como recordaremos está estructura representa una mejora parcial en algunos aspectos respecto a un array, ya que en la presente estructura no es necesario que los nodos sean adyacentes en memoria.
La estructura del **BlockChain** o cadena de bloques se asemeja a esta estructura pues al igual que la lista simplemente enlazada representa un conjunto de nodos, el **BlockChain** representa un conjunto de bloques, los cuales almacenan las transacciones, que se enlazan. Podría bien implementarse de una forma en la que se asemeje a otras estructuras enlazadas, sin embargo, consideramos que su comportamiento es más apegado al de un ForwardList que de otros.

![image](https://user-images.githubusercontent.com/102536323/194790493-f0fa8a43-ae51-45b1-80c8-be28d4b47388.png)

https://www.geeksforgeeks.org/what-is-linked-list/

## Doubly Linked List
Estructura que solo difiere de una lista simplemente enlazada en que los nodos que la conforman almacenan un puntero adicional a un nodo previo y no solo al posterior.
Si bien nuestra **BlockChain** sigue la estructura de una lista simplemente enlazada, al realizar algunas operaciones necesitamos el almacenamiento de datos, ya sean nodos, bloques, transacciones, etc. Para lo cual y como objeto único de esta presentación se desiste de usar estructuras previamente definidas en la STL. Debido a esto se decide usar una lista doblemente enlazada por ser la estructura más simple que cumpla con lo que necesitamos a nivel de almacenamiento y recorrido de la misma.

![image](https://user-images.githubusercontent.com/102536323/194790489-a35aa211-548d-43b7-97d5-3d02dbbcda22.png)
[https://www.geeksforgeeks.org/introduction-and-insertion-in-a-doubly-linked-list/](url)

## Circulay Array
Implementació particular con modificaciones de un array ordinario, la presente estructura de datos permite realizar acciones de insercción y modificación con una compejidad computacional de O(1), aunque representa agunos problemas de tener que redimensioarla o de tener que buscar un espacio de memoria contigua que pueda almacenar toda la información necesaria. Si bien en un principio se menciona que se trabajará con las estructuras de Forward List, debido a propositos academícos y buscando reducir la complejidad computacional en el acceso tanto de bloques como de transacciones, se remplaza dicha estructura Forward List por un Circular Array y lo mismo para sus transacciones.

![image](https://user-images.githubusercontent.com/102536323/205095428-99182b38-54d4-4688-8ee6-47e3c92cb31e.png)

https://www.geeksforgeeks.org/circular-array/

## Heap's (max & min)
Los heaps, tanto maxHeap como minHeap nos permiten encontrar los valores máximos y mínimos almacenados en las trasacciones o el nombre más largo. Para objetos de este proyecto se usa una implementación del heap vista en clase con ligeras modificaciones para indexar adecuadamente las transacciones en las que el monto es mayor o igual a la cantidad máxima registrada hasta el momento. Las modificaciones de está estructura se encuentran unicamente en la función pop(), la cual no solo elimina un valor, sino que a su vez devuelve el elemento almacenado.

<img src="https://user-images.githubusercontent.com/102536323/205106521-9734d8bd-5288-4f1c-b5f3-c4b4902fa487.png"  width="60%" height="30%">

https://walker.uz/2020/10/02/binary-heap-malumotlar-toplami/

## Btree
El btree resulta una estructura adecuada para manejar la indexación de grandes cantidades de datos. Para objetos de este proyecto usamos esta estructura para almacenar los índices de las transacciones y realiazar búsquedas por rango. Cabe destacar que realizar busqueda por rangos es un operación que se realiza mucho mejor y con una complejidad computacional menor en un b+tree que sería la estructura ideal para este tipo de operaciones.


<img src="https://user-images.githubusercontent.com/102536323/205104374-e4612995-a28a-4640-92ff-cbf917fa6059.png"  width="60%" height="30%">

https://www.geeksforgeeks.org/introduction-of-b-tree-2/

## Hash
El hash es un proceso de asignación de clave, valor en una tabla hash mediante una función hash. Está estructura tiene entre sus caracteristicas más importantes un acceso de complejidad computacional O(1), por lo que suele ser usada para hayar datos específicos de los que tenemos asociada su llave (key). Para objetos del presente proyecto se usa la estructura hash para realizar la operación "igual a", en donde el nombre de quien lo envia o quien lo recive son las llaves y las transacciones que han hecho sus valores correspondientes.

<img src="https://user-images.githubusercontent.com/102536323/205105657-47fcedea-cf53-4858-8f50-86ac014e822f.png"  width="60%" height="30%">

https://en.wikipedia.org/wiki/Hash_table

------------------------------------------------------------------------------------------------------------------------------

# Comparación de tiempos lineal vs indexada


## Lineal vs hash (chaining hash)
![image](https://user-images.githubusercontent.com/102536323/205111283-27ab6a7a-29fe-4afd-8e9a-c725f578b6ad.png)

## Lineal vs Btree

![image](https://user-images.githubusercontent.com/102536323/205111455-fd701de6-9b5d-4759-8cbf-a8bf259c6fcd.png)

## Lineal vs MaxHeap

![image](https://user-images.githubusercontent.com/102536323/205111532-10c65772-edf2-47b0-ab63-51192c096a57.png)

## Lineal vs MinHeap

![image](https://user-images.githubusercontent.com/102536323/205111714-987214c5-7725-43f7-91f7-76dd240151d9.png)

------------------------------------------------------------------------------------------------------------------------------

# Complejidad de métodos

## Transaccion
|Método|Complejidad|
|-----------|-----------------|
|get( )       | O(1) |
## Block
|Método|Complejidad|
|-----------|-----------------|
|get_hash( )| O(1) |
|get_prev_hash( )|O(1) |
|get_transactions( )|O(n) |
|get_nonce( )|O(1) |
|get_size( )|O(1) |
|get_merkleroot( )|O(1) |
|set_precision( )|O(1) |
|set_max_transaction( )|O(1) |
|set_prev_hash( )|O(1) |
|add_transaction( )|O(n) + O(j)*O(k)|
|mine( )|O(j)*O(k)|
|calculate_hash( )|O(k)|

O(k): Complejidad de algoritmo sha-256  
O(j): Complejidad del cálculo del valor nonce
## BlockChain
|Método|Complejidad|
|-----------|-----------------|
|insert( )|O(1) |
|modify( )|O(n) + O(j)*O(k)|
|print_chain( )|O(n) |
|size_block( )|O(1) |

## CircularArray
|Método|Complejidad|
|-----------|-----------------|
|resize()|O(n)|
|push_front()|O(1)|
|push_back()|O(1)|
|insert()|O(n)|
|pop_front()|O(1)|
|pop_back()|O(1)|
|is_full()|O(1)|
|is_empty()|O(1)|
|size()|O(1)|
|clear()|O(n)|

## Hash (ChainHash)
|Método|Complejidad|
|-----------|-----------------|
|empty( )|O(1) |
|fill_factor()|O(1)|
|insert()|O(1) |
|rehashing()|O(n)|
|get()|O(1)|
|find()|O(1)|
|remove()|O(1)|

## Btree
|Método|Complejidad|
|-----------|-----------------|
|insert()|O(log(n))|
|get( )|O(log(n)) |
|min_node()|O(log(n))|
|max_node()|O(log(n))|
|high()|O(log(n))|
|to_string()|O(n)|
|search()|O(log(n))|

## heap()
|Método|Complejidad|
|-----------|-----------------|
|push()|O(log(n))|
|get_value()|O(1)|
|heapify_up()|O(log(n))|
|heapify_down()|O(log(n))|

------------------------------------------------------------------------------------------------------------------------------
# Conclusiones
Podemos mencionar que esta tecnología nos da la capacidad de modificar y realizar transacciones de forma segura, confidencial y transparente para el manejo de información. Además, las Blockchain poseen la capacidad de mejorar procesos y reducir costos de las mismas transacciones. De esta manera, identificamos los diferentes sectores en los que el uso de este tipo de tecnología alcanzaría su máximo desarrollo: Cadena de Suministro , Sector Legal, Sector de salud y Sector Financiero.
Finalmente, resaltamos que el mayor aprovechamiento de las Blockchain así como el logro de su mayor potencial, se alcanzaría en el Sector Financiero. Ya que las empresas basan sus modelos de negocio en el registro e intercambio de información y valor mediante cualquier clase de activos que sean propensos a poseer un mayor riesgo (impacto económico y financiero)  por la tecnología blockchain las cuales a su vez buscarían el beneficio de todos sus miembros.

------------------------------------------------------------------------------------------------------------------------------
# Referencias bibliográficas
* Antonopoulos, A. (2017, 25 julio). Mastering Bitcoin: Programming the Open Blockchain (2nd ed.). O’Reilly Media.
* GeeksforGeeks. (2022, 14 marzo). 7 Project Ideas on Blockchain For Professionals. Recuperado 9 de octubre de 2022, de https://www.geeksforgeeks.org/7-project-ideas-on-blockchain-for-professionals/?ref=rp
* Academy, B. (s. f.). Blockchain. Binance Academy. Recuperado 9 de octubre de 2022, de https://academy.binance.com/en/glossary/blockchain?utm_campaign=googleadsxacademy
* Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++. Pearson.
