# Laboratorio 1: Fuerza bruta.
La empresa de inversiones internacional clover inversions es reconocida a nivel mundial por sus grandes ganancias en este rubro. Últimamente han nacido muchas nuevas empresas y con ello la lista de inversiones ha crecido de forma exponencial. Esto ha preocupado a los inversionistas ya que ante tantas posibilidades no pueden maximizar sus beneficios. Por este motivo el equipo de inversionistas le ha pedido a usted que diseñe un algoritmo que dado un capital inicial, pueda comprar inversiones con tal de garantizar el máximo de utilidad. Debe ser desarrollado por fuerza bruta. Asuma que cada inversión tiene una utilidad específica.

## Funcionalidades:
Construya un programa en C que logre entregar la lista de inversiones que se deben comprar con tal de garantizar el máximo de utilidades.
Su código debe contener el la función bruteForce( entradas ). Las entradas de la función anterior queda su criterio pero debe comentar que es lo que entra en la función. Por ejemplo :
```
ENTRADAS: dos enteros que representan la cantidad de ciudades y la cantidad de recursos respectivamente.
SALIDA : entrega como salida un puntero al nodo inicial de la lista dónde está la ruta óptima.

nodo* bruteForce(int A, int B) {...}
```

Su código debe incluir la función printCurrent( entradas ) que imprime por pantalla el estado actual del nodo que está siendo visitado. Esta función es solo para el control del flujo de la ejecución, le ayudará a la revisión y la ubicación dentro de su código. Las entradas de la función anterior queda su criterio pero debe comentar que es lo que entra en la función. Para mayor facilidad se le facilitara parte del código
```
printCurrent(...) {
#ifdef DEBUG
printf(“enter para continuar…\n”)
while(getchar() != ‘\n’);
/*
en esta parte debe escribir su código para imprimir lo que sea necesario para mostrar el estado actual del nodo.
*/
#endif
}
```

Entrada:
Como entrada se debe tener un archivo “entrada.in” el cual contiene; el capital inicial, el número de inversiones disponibles y el listado de inversiones con su costo y utilidad.