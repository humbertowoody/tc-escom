/**
 * practica1.cpp - Archivo base de la práctica.
 *
 * Práctica: 1.
 * Objetivo:
 *   Realizar un programa que reciba un alfabeto y calcule la N-ésima potencia.
 *
 * Equipo:
 *   - Diego Akira Martinez Rodriguez  (2014110833) <dmartinezr1301@alumno.ipn.mx>
 *   - Humberto Alejandro Ortega Alcocer (2016630495) <hortegaa1500@alumno.ipn.mx>
 *
 * Materia: Teoría Computacional
 * Grupo: 2CM1
 * Profesor: Alberto Alcántara
 * ESCOM - IPN
 * 11/Oct/2020.
 */
#include <iostream>  // Estándar de acceso a archivos.
#include <string>    // Para operaciones con strings.
#include <vector>    // Para operaciones con vectores.
#include <algorithm> // Para el algoritmo que elimina duplicados dentro de un vector.

// Constante para almacenar el número máximo de elementos dentro de un alfabeto.
#ifndef MAX_ELEMENTS
#define MAX_ELEMENTS 100
#endif

// Constante para almacenar el número máximo para la potencia a la cual elevar un alfabeto.
#ifndef MAX_POWER
#define MAX_POWER 8
#endif

// Constante para almacenar el valor que interpretamos como épsilon dentro del programa.
#ifndef EPSILON
// #define EPSILON "ε" // Cambiar para ajustar al formato de la entrada.
#define EPSILON "(e)"
#endif

/**
 * Prototipos de las funciones a utilizar en el programa.
 */
void print_alphabet(std::vector<std::string>);
std::vector<std::string> alphabet_power(std::vector<std::string>, int);
std::vector<std::string> combine_alphabets(std::vector<std::string>, std::vector<std::string>);

/**
 * Función principal.
 */
int main(int argc, char *argv[])
{
  // Variables necesarias.
  std::string temporal;              // Para almacenamiento temporal sin re-declarar la variable dentro del ciclo.
  std::vector<std::string> alfabeto, // Vector con el alfabeto original.
      resultado;                     // Vector con el alfabeto resultante.
  int k = 0,                         // Potencia a la cual elevaremos nuestro alfabeto.
      elementos = 0;                 // Número de elementos que tendrá el alfabeto original.

  // Mensajes de inicio.
  std::cout << "Escuela Superior de Cómputo - IPN" << std::endl
            << "Teoría Computacional - Alberto Alcántara" << std::endl
            << "Práctica 1: Elevar un alfabeto a la N-ésima potencia." << std::endl
            << "Equipo:" << std::endl
            << "  - Diego Akira Martinez Rodriguez  (2014110833) <dmartinezr1301@alumno.ipn.mx>" << std::endl
            << "  - Humberto Alejandro Ortega Alcocer (2016630495) <hortegaa1500@alumno.ipn.mx>" << std::endl
            << std::endl;

  // Rutina para leer alfabeto.
  std::cout << "¿Cuántos elementos quieres ingresar en el alfabeto?" << std::endl;
  do
  {
    std::cout << "[0 - " << MAX_ELEMENTS << "]> ";
    std::cin >> elementos;
  } while (elementos < 0 || elementos > MAX_ELEMENTS); // Validamos que esté dentro de nuestros límites establecidos.

  /**
   * Esto de aquí es un turbo-hack porque, de otra forma, el stream del input
   * almacena el salto de línea ('\n') en el búfer por lo que el primer elemento
   * se guarda erróneamente.
   */
  std::getline(std::cin, temporal); // Perdón :'(

  // Imprimir instrucciones para el usuario.
  std::cout << "Se leerán los valores para los " << elementos << " elementos:" << std::endl
            << "(Si deseas representar épsilon, por favor, usa: " << EPSILON << ")" << std::endl;

  // Ciclo para leer todos los elementos del alfabeto.
  for (int i = 0; i < elementos; i++)
  {
    // Imprimimos mensaje.
    std::cout << "Elemento #" << i + 1 << " > ";
    // Leemos valor.
    std::getline(std::cin, temporal);
    // Añadimos al alfabeto.
    alfabeto.push_back(temporal);
  }

  // Imprimimos el alfabeto.
  std::cout << "Alfabeto ingresado:" << std::endl;
  print_alphabet(alfabeto);
  std::cout << std::endl;

  // Preguntamos la potencia.
  do
  {
    std::cout << "¿Qué potencia deseas calcular para el alfabeto?" << std::endl
              << "[0 - " << MAX_POWER << "]> ";
    std::cin >> k;
  } while (k < 0 || k > MAX_POWER); // Validamos que esté dentro de nuestros límites establecidos.

  // Imprimimos mensaje de confirmación.
  std::cout << "Se calculará la " << k << "a potencia para el alfabeto proporcionado..." << std::endl;

  // Llamamos a la función y esperamos el resultado.
  resultado = alphabet_power(alfabeto, k);

  // Imprimimos el resultado.
  std::cout << "Alfabeto resultante:" << std::endl
            << "L^" << k << " = ";
  print_alphabet(resultado);
  std::cout << std::endl;

  // Imprimimos mensaje de finalización.
  std::cout << "Fin de ejecución." << std::endl
            << std::endl;

  // Todo correcto, exit status: 0.
  return 0;
}

/**
 * Combine Alphabets
 * Esta función recibe 2 vectores y regresa un vector con todas las permutaciones posibles.
 * Parámetros:
 *   - std::vector<std::string> alfabeto_1
 *   - std::vector<std::string> alfabeto_2
 * Valor de retorno: Un std::vector<std::string> con las permutaciones posibles.
 */
std::vector<std::string> combine_alphabets(std::vector<std::string> alfabeto_1, std::vector<std::string> alfabeto_2)
{
  // Variable para almacenar el resultado.
  std::vector<std::string> resultado;

  // Realizar las permutaciones entre ambos vectores.
  for (std::vector<std::string>::iterator it1 = alfabeto_1.begin(); it1 != alfabeto_1.end(); ++it1)
  {
    for (std::vector<std::string>::iterator it2 = alfabeto_2.begin(); it2 != alfabeto_2.end(); ++it2)
    {
      // Para actuar apropiadamente ante un valor épsilon.
      if (it1->compare(EPSILON) == 0 && it2->compare(EPSILON) != 0) // εa = a
      {
        // Empujamos el valor que no es epsilon.
        resultado.push_back(*it2);
      }
      else if (it1->compare(EPSILON) != 0 && it2->compare(EPSILON) == 0) // aε = a
      {
        // Empujamos el valor que no es epsilon.
        resultado.push_back(*it1);
      }
      else if (it1->compare(EPSILON) == 0 && it2->compare(EPSILON) == 0) // εε = ε
      {
        // Ambos son épsilon, da lo mismo.
        resultado.push_back(EPSILON);
      }
      else // ab = ab
      {
        // Empujamos la concatenación de ambos valores dado que ninguno es épsilon.
        resultado.push_back(*it1 + *it2);
      }
    }
  }

  // Ordenar.
  std::sort(resultado.begin(), resultado.end());

  // Eliminar duplicados.
  resultado.erase(std::unique(resultado.begin(), resultado.end()), resultado.end());

  // Regresar resultado.
  return resultado;
}

/**
 * Print Alphabet
 * Esta función imprime todos los elementos contenidos dentro de un vector de
 * strings usando nomenclatura de conjuntos.
 * Parámetros:
 *   - std::vector<std::string> alfabeto_original El alfabeto original de cálculo.
 *   - int potencia La potencia a la cual elevaremos nuestro alfabeto.
 * Valor de retorno: void
 */
std::vector<std::string> alphabet_power(std::vector<std::string> alfabeto_original, int potencia)
{
  // Casos base.
  // Usamos 2 casos base porque sabemos cómo se comporta L^1 y L^0.
  if (potencia == 1)
  {
    // L^1 = L.
    std::cout << "L^1 = ";
    print_alphabet(alfabeto_original);
    std::cout << std::endl;
    return alfabeto_original;
  }
  else if (potencia < 1)
  {
    // L^0 = {ε}.
    std::cout << "L^0 = {" << EPSILON << "}" << std::endl;
    return std::vector<std::string>(1, EPSILON);
  }

  // Calculamos el alfabeto para la potencia inmediata anterior de forma recursiva.
  std::vector<std::string> alfabeto_inmediato_anterior = alphabet_power(alfabeto_original, potencia - 1);

  // Regresar un vector con todas las permutaciones entre ambos vectores.
  std::vector<std::string> resultado = combine_alphabets(alfabeto_original, alfabeto_inmediato_anterior);

  std::cout << "L^" << potencia << " = ";
  print_alphabet(resultado);
  std::cout << std::endl;

  return resultado;
}

/**
 * Print Alphabet
 * Esta función imprime todos los elementos contenidos dentro de un vector de
 * strings usando nomenclatura de conjuntos.
 * Parámetros: std::vector<std::string> alfabeto_a_imprimir
 * Valor de retorno: void
 */
void print_alphabet(std::vector<std::string> alfabeto_a_imprimir)
{
  // Iterador para simplificar la operación.
  std::vector<std::string>::iterator iterador;

  // Imprimir cada elemento en notación de conjuntos {}.
  std::cout << "{";
  for (iterador = alfabeto_a_imprimir.begin(); iterador != alfabeto_a_imprimir.end(); ++iterador)
  {
    // Imprimir el dato actual.
    std::cout << *iterador;

    // Revisar si es el último elemento.
    if (iterador + 1 != alfabeto_a_imprimir.end())
    {
      std::cout << ",";
    }
  }
  std::cout << "}";
}
