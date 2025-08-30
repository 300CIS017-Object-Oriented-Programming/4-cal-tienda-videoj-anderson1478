#ifndef GAMESTORE_H
#define GAMESTORE_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


const int  PRECIO_FIFA = 60000;
const int  PRECIO_FAST_AND_FURIOUS = 30000;
const int  PRECIO_EXTREMO = 400000;
const int  PRECIO_MARIO_INFINITY = 90000;
const int  PRECIO_KUNFU_PANDA = 35000;
const int  PRECIO_SAMURAI_X = 63000;
const int  PRECIO_STAR_WARS = 86000;
const int  PRECIO_SURVIVOR = 72000;
const int  PRECIO_ZOMBIE_100 = 100000;
const int  PRECIO_CALL_OF_DUTY = 120000;
const int  PRECIO_MERCENARIO = 110000;
const int  PRECIO_HITMAN = 84000;

const double DESCUENTO_AFILIADO = 0.15;
const double DESCUENTO_MEMBRESIA = 0.20;
const double DESCUENTO_POR_MAYOR = 0.12;
const int MAX_ITEMS = 50;

void mostrarCatalogoJuegos();

int leerCodigoJuego();

int leerCantidadJuegos();

string obtenerNombreJuego(int codigoJuego);

int obtenerPrecioJuego(int codigoJuego);

string obtenerPlataforma(int codigoJuego);

string obtenerCategoria(int codigoJuego);

void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);

double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);

int leerTipoCliente();

double obtenerPorcentajeDescuento(int tipoCliente);

double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);

double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales);

void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento);

void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);

#endif