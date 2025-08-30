#include <iostream>
#include "Gamestore.h"
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;



void mostrarMenuPrincipal()
{
    cout << "===== GAMESTORE - MENU PRINCIPAL =====\n";
    cout << "1. Ver catalogo de juegos\n";
    cout << "2. Agregar juego al carrito\n";
    cout << "3. Cargar compra demo\n";
    cout << "4. Mostrar resumen de compra\n";
    cout << "5. Finalizar y pagar\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opcion: ";
}

int leerOpcionMenu()
{
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 6)
    {
        cout << "Opcion invalida. Intente de nuevo (1-6): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> opcion;
    }
    return opcion;
}

int main()
{
    int codigos[MAX_ITEMS] = {0};
    int cantidades[MAX_ITEMS] = {0};
    int cantidadJuegosRegistrados = 0;

    int opcion = 0;
    do
    {
        mostrarMenuPrincipal();
        opcion = leerOpcionMenu();

        switch (opcion)
        {
        case 1:
            {
                mostrarCatalogoJuegos();
                break;
            }

        case 2:
            {
                agregarJuegoAlCarrito(codigos, cantidades, cantidadJuegosRegistrados);
                break;
            }

        case 3:
            {
                cargarCompraDemo(codigos, cantidades, cantidadJuegosRegistrados);
                break;
            }

        case 4:
            {
            if (cantidadJuegosRegistrados == 0)
            {
                cout << "\nEl carrito esta vacio.\n\n";
                break;
            }


            cout << "\n=== PRODUCTOS EN EL CARRITO ===\n";
            for (int i = 0; i < cantidadJuegosRegistrados; i++)
            {
                string nombre = obtenerNombreJuego(codigos[i]);
                int cantidad = cantidades[i];
                cout << nombre << " - Cantidad: " << cantidad << "\n";
            }


            double subtotal = calcularSubtotalCarrito(codigos, cantidades, cantidadJuegosRegistrados);
            cout << fixed << setprecision(2);
            cout << "Subtotal: $" << subtotal << "\n\n";
            break;
            }

        case 5:
            {
            if (cantidadJuegosRegistrados == 0)
            {
                cout << "\nNo hay productos en el carrito.\n\n";
                break;
            }

            int tipoCliente = leerTipoCliente();
            double descuentoCliente = obtenerPorcentajeDescuento(tipoCliente);
            double subtotal = calcularSubtotalCarrito(codigos, cantidades, cantidadJuegosRegistrados);

            double descuentoAdicional = 0.0;
            if (tipoCliente == 2)
            {
                cout << "\nClientes con membresia no aplican para descuentos adicionales.\n";
            }
            else
            {
                descuentoAdicional = calcularDescuentosAdicionales(codigos, cantidades, cantidadJuegosRegistrados);
            }


            cout << fixed << setprecision(2);
            cout << "\n=== RESUMEN FINAL DE COMPRA ===\n";
            cout << "Subtotal: $" << subtotal << "\n";
            cout << "Descuento por cliente (" << (descuentoCliente * 100) << "%): -$" << (subtotal * descuentoCliente) << "\n";

            if (tipoCliente != 2)
            {
                cout << "Descuento adicional (" << (descuentoAdicional * 100) << "%): -$" << (subtotal * descuentoAdicional) << "\n";
            }


            double totalFinal = calcularTotalFinal(subtotal, descuentoCliente, descuentoAdicional);
            cout << "TOTAL FINAL A PAGAR: $" << totalFinal << "\n\n";


            cantidadJuegosRegistrados = 0;
            cout << "¡Compra finalizada! Carrito reiniciado.\n\n";
            break;
            }
        case 6:
            {
                cout << "\nSaliendo del sistema. ¡Gracias por su compra!\n";
                break;
            }
        }
    }
    while (opcion != 6);

    return 0;
}