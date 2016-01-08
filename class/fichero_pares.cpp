#include "fichero_pares.h"
#include <fstream>

using namespace Herramientas_proyecto;

Fichero_pares::Fichero_pares(const std::string& nf, char sep, char com):
	nombre_fichero(nf), separador(sep), comentario(com)
{
	cargar();
}

/**
* Carga el contenido del fichero en el mapa.
*/

void Fichero_pares::cargar()
{
	configuracion=generar_mapa_pares(nombre_fichero, separador, comentario);
}

/**
* Guarda el contenido del mapa en el fichero. Al usarse un mapa, que es un contenedor
* si ordenar, no se conservará el orden original de los elementos. De la misma forma
* no se conservarán comentarios o líneas en blanco que estuvieran presentes en
* el fichero original.
*/
 
void Fichero_pares::guardar()
{
	std::ofstream fichero(nombre_fichero.c_str());
	
	for(const auto& par : configuracion)
	{
		fichero<<par.first<<separador<<par.second<<std::endl;
	}
}