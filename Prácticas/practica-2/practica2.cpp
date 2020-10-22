/**
 * practica2.cpp - Archivo base de la práctica.
 *
 * Práctica: 2.
 * Objetivo:
 *   Realizar un programa que reciba un alfabeto y calcule la N-ésima potencia.
 *
 * Equipo:
 *   - Diego Akira Martinez Rodriguez  (2014110833) <dmartinezr1301@alumno.ipn.mx>
 *   - Humberto Alejandro Ortega Alcocer (2016630495) <hortegaa1500@alumno.ipn.mx>
 *
 * Materia: Teoría Computacional
 * Grupo: 2CM1
 * Profesor: Roberto Alcántara
 * ESCOM - IPN
 * 11/Oct/2020.
 */
#include <iostream> // Estándar de acceso a archivos.
#include <string>   // Para operaciones con strings.
#include <vector>   // Para operaciones con vectores.

// Constante para almacenar el número máximo de elementos dentro de un alfabeto.
#ifndef MAX_ELEMENTS
#define MAX_ELEMENTS 100
#endif

// Constante para almacenar el valor que interpretamos como épsilon dentro del programa.
#ifndef EPSILON
#define EPSILON "ε" // Cambiar para ajustar al formato de la entrada.
// #define EPSILON "(e)"
#endif

/**
 * Prototipos de las funciones a utilizar en el programa.
 */
void print_vector(std::vector<std::string>);
std::vector<std::string> prefixes_from_string(std::string);
std::vector<std::string> suffixes_from_string(std::string);

/**
 * Función principal.
 */
int main(int argc, char *argv[])
{
  // Variables necesarias.
  std::string cadena;                // Variable para almacenar la cadena
  std::vector<std::string> prefijos, // Los prefijos calculados para la cadena.
      sufijos;                       // Los sufijos calculados para la cadena.

  // Mensajes de inicio.
  std::cout << "Escuela Superior de Cómputo - IPN" << std::endl
            << "Teoría Computacional - Roberto Alcántara" << std::endl
            << "Práctica 2: Calcular los sufijos y prefijos para una cadena." << std::endl
            << "Equipo:" << std::endl
            << "  - Diego Akira Martinez Rodriguez  (2014110833) <dmartinezr1301@alumno.ipn.mx>" << std::endl
            << "  - Humberto Alejandro Ortega Alcocer (2016630495) <hortegaa1500@alumno.ipn.mx>" << std::endl
            << std::endl;

  // Leer la cadena.
  do
  {
    std::cout << "Ingresa la cadena ω: " << std::endl
              << "Longitud máxima " << MAX_ELEMENTS << " caracteres. > ";
    std::cin >> cadena;
  } while (cadena.length() < 1 || cadena.length() > MAX_ELEMENTS); // Validar que no sea una cadena enorme.

  // Mostrar al usuario su entrada.
  std::cout << std::endl
            << "Cadena original: " << cadena << std::endl
            << std::endl;

  // Realizamos los cálculos de sufijos y prefijos.
  prefijos = prefixes_from_string(cadena);
  sufijos = suffixes_from_string(cadena);

  // Imprimir resultados.
  std::cout << "Resultados:" << std::endl
            << "  - Prefijos: ";
  print_vector(prefijos);
  std::cout << std::endl
            << "  - Sufijos: ";
  print_vector(sufijos);
  std::cout << std::endl
            << std::endl;

  // Imprimimos mensaje de finalización.
  std::cout << "Fin de ejecución." << std::endl
            << std::endl;

  // Todo correcto, exit status: 0.
  return 0;
}

/**
 * Prefixes From String
 * Esta función calcula todos los prefijos para la cadena proporcionada.
 * Parámetros:
 *   - std::string cadena_original La cadena original
 * Valor de retorno: std::vector<std::string> Un vector con los prefijos calculados.
 */
std::vector<std::string> prefixes_from_string(std::string cadena_original)
{
  // Variables para la función.
  std::vector<std::string> resultado; // Para almacenar el resultado con los prefijos.
  std::string temp = "";              // Variable temporal.

  // Ingresar épsilon.
  resultado.push_back(EPSILON);

  // Recorremos la cadena, de izquierda a derecha.
  for (std::string::iterator it = cadena_original.begin(); it != cadena_original.end(); ++it)
  {
    // Concatenamos `temp` con el valor actual de `it`.
    temp = temp + *it;
    // Emujamos el resultado concatenado al vector con los resultados.
    resultado.push_back(temp);
  }

  // Regresamos el vector final.
  return resultado;
}

/**
 * Suffixes From String
 * Esta función calcula todos los sufijos para la cadena proporcionada.
 * Parámetros:
 *   - std::string cadena_original La cadena original
 * Valor de retorno: std::vector<std::string> Un vector con los sufijos calculados.
 */
std::vector<std::string> suffixes_from_string(std::string cadena_original)
{
  // Variables para la función.
  std::vector<std::string> resultado; // Para almacenar el resultado con los prefijos.
  std::string temp = "";              // Variable temporal.

  // Ingresar épsilon.
  resultado.push_back(EPSILON);

  // Recorremos la cadena, de izquierda a derecha.
  for (std::string::iterator it = (cadena_original.end() - 1); it != (cadena_original.begin() - 1); --it)
  {
    // Concatenamos `temp` con el valor actual de `it`.
    temp = *it + temp;
    // Emujamos el resultado concatenado al vector con los resultados.
    resultado.push_back(temp);
  }

  // Regresamos el vector final.
  return resultado;
}

/**
 * Print Vector
 * Función que imprime un vector con strings en formato de Conjuntos.
 * Parámetros: std::vector<std::string> vector_a_imprimir
 * Valor de retorno: void
 */
void print_vector(std::vector<std::string> vector_a_imprimir)
{
  // Iterador para simplificar la operación.
  std::vector<std::string>::iterator iterador;

  // Imprimir cada elemento en notación de conjuntos {}.
  std::cout << "{";
  for (iterador = vector_a_imprimir.begin(); iterador != vector_a_imprimir.end(); iterador++)
  {
    // Imprimir el dato actual.
    std::cout << *iterador;

    // Revisar si es el último elemento.
    if (iterador + 1 != vector_a_imprimir.end())
    {
      std::cout << ",";
    }
  }
  std::cout << "}";
}