
#include "Gamestore.h"
#include <iomanip>


void mostrarCatalogoJuegos() {
    cout << "\n ---Catalogo video juegos--- \n";
    cout << "\n ---DEPORTES--- \n";
    cout << "1. Fifa 2025            $ " << PRECIO_FIFA << "\n";
    cout << "2. Fast and Furious     $ " << PRECIO_FAST_AND_FURIOUS << "\n";
    cout << "3. Extremo              $ " << PRECIO_EXTREMO << "\n";
    cout << "\n ---AVENTURA--- \n";
    cout << "4. Mario Infinity       $ " << PRECIO_MARIO_INFINITY << "\n";
    cout << "5. Kunfu Panda          $ " << PRECIO_KUNFU_PANDA << "\n";
    cout << "6. Samurai x            $ " << PRECIO_SAMURAI_X << "\n";
    cout << "\n --- ESTRATEGIA--- \n";
    cout << "7. Star Wars            $ " << PRECIO_STAR_WARS << "\n";
    cout << "8. Survivor             $ " << PRECIO_SURVIVOR << "\n";
    cout << "9. Zombie 100           $ " << PRECIO_ZOMBIE_100 << "\n";
    cout << "\n --- ACCION--- \n";
    cout << "10. Call Of Duty        $ " << PRECIO_CALL_OF_DUTY << "\n";
    cout << "11. mercenario          $ " << PRECIO_MERCENARIO << "\n";
    cout << "12. Hitman              $ " << PRECIO_HITMAN << "\n";

}

int leerCodigoJuego() {
    int codigo;
    do {
        cout <<" Ingrese el codigo del producto de (1-12): ";
        cin >> codigo;
        if (codigo < 1 || codigo > 12) {
            cout << "Codigo invalido. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(10000,'\n');

        }
    }while (codigo < 1 || codigo > 12);
    return codigo;
}

int leerCantidadJuegos() {
    int cantidad;
    do {
        cout <<"Ingrese la cantidad (1- 20):";
        cin >> cantidad;
        if (cantidad < 1 || cantidad > 20) {
            cout << "Cantidad invalida. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(10000,'\n');

        }
    }while (cantidad < 1 || cantidad > 20);
    return cantidad;

}



string obtenerNombreJuego(int codigoJuego) {
    switch (codigoJuego)
    {
    case 1:
        {
            return "Fifa 2025";
        }
    case 2:
        {
            return "Fast and Furious";
        }
    case 3:
        {
            return "Extremo";
        }
    case 4:
        {
            return "Mario Infinity";
        }
    case 5:
        {
            return "Kunfu Panda";
        }
    case 6:
        {
            return "Samurai x";
        }
    case 7:
        {
            return "Star Wars";
        }
    case 8:
        {
            return "Survivor";
        }
    case 9:
        {
            return "Zombie 100";
        }
    case 10:
        {
            return"Call Of Duty";
        }
    case 11:
        {
            return "Mercenario";
        }
    case 12:
        {
            return "Hitman";
        }
    default:
        {
            return "Desconocido";
        }

    }
}

int obtenerPrecioJuego(int codigoJuego) {
    switch (codigoJuego)
    {
    case 1:
        {
            return PRECIO_FIFA;
        }
    case 2:
        {
            return PRECIO_FAST_AND_FURIOUS;
        }
    case 3:
        {
            return PRECIO_EXTREMO ;
        }
    case 4:
        {
            return PRECIO_MARIO_INFINITY ;
        }
    case 5:
        {
            return PRECIO_KUNFU_PANDA ;
        }
    case 6:
        {
            return PRECIO_SAMURAI_X ;
        }
    case 7:
        {
            return PRECIO_STAR_WARS;
        }
    case 8:
        {
            return PRECIO_SURVIVOR;
        }
    case 9:
        {
            return PRECIO_ZOMBIE_100;
        }
    case 10:
        {
            return PRECIO_CALL_OF_DUTY;
        }
    case 11:
        {
            return PRECIO_MERCENARIO;
        }
    case 12:
        {
            return PRECIO_HITMAN;
        }
    default:
        {
            return 0;
        }
    }
}

string obtenerPlataforma(int codigoJuego) {
    switch (codigoJuego)
    {
    case 1:
        {
            return "PS5";
        }
    case 2:
        {
            return "XBOX";
        }
    case 3:
        {
            return "SWITCH";
        }
    case 4:
        {
            return "PC";
        }
    default:
        {
            return "desconocida";
        }
    }

}

string obtenerCategoria(int codigoJuego) {
    switch (codigoJuego)
    {
    case 1:
        {
            return "Deportes";
        }
    case 2:
        {
            return "Aventura";
        }
    case 3:
        {
            return "Estartegia";
        }
    case 4:
        {
            return "Accion";
        }
    default:
        {
            return "desconocida";
        }

    }

}

void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    if (cantidadJuegosRegistrados >= MAX_ITEMS)
    {
        cout << "No es posible registrar mas juegos en el carrito\n";
        return;
    }

    mostrarCatalogoJuegos();
    int codigo = leerCodigoJuego();
    int cantidad = leerCantidadJuegos();


    for (int i = 0; i < cantidadJuegosRegistrados; i++)
    {
        if (codigos[i] == codigo)
        {

            cantidades[i] += cantidad;
            cout << " Producto actualizado: " << obtenerNombreJuego(codigo)
                 << " x" << cantidades[i] << " (cantidad acumulada)\n\n";
            return;
        }
    }


    codigos[cantidadJuegosRegistrados] = codigo;
    cantidades[cantidadJuegosRegistrados] = cantidad;
    cantidadJuegosRegistrados++;

    cout << " Producto agregado: " << obtenerNombreJuego(codigo)
         << " x" << cantidad << "\n\n";
}


double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados) {
    double subtotal = 0.0;

    cout << "\n=== DETALLE DEL CARRITO ===\n";
    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        int codigo = codigos[i];
        int cantidad = cantidades[i];
        double precio = obtenerPrecioJuego(codigo);
        string nombre = obtenerNombreJuego(codigo);
        double totalProducto = precio * cantidad;
        subtotal += totalProducto;

        cout << nombre << " - " << cantidad
             << " x $" << precio << " = $" << totalProducto << "\n";
    }
    cout << "---------------------------\n";

    return subtotal;
}

int leerTipoCliente() {
    cout << "Tipo de usuario (1=Afiliado, 2=Membresia, 3=Por mayor): ";
    int tipo;
    cin >> tipo;
    while (tipo < 1 || tipo > 3) {
        cout << "Opción inválida. Intente de nuevo (1-3): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> tipo;
    }
    return tipo;
}



double obtenerPorcentajeDescuento(int tipoCliente) {
    if (tipoCliente == 1)
    {
        return DESCUENTO_AFILIADO;
    }
    if (tipoCliente == 2)
    {
        return DESCUENTO_MEMBRESIA;
    }
    if (tipoCliente == 3)
    {
        return DESCUENTO_POR_MAYOR;
    }
    return 0.0;
}

double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados) {
    int totalDeportes = 0;
    int totalAventura = 0;
    int totalEstrategia = 0;
    int totalAccion = 0;


    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        int codigo = codigos[i];
        if (codigo >= 1 && codigo <= 3) {
            totalDeportes += cantidades[i];
        }
        if (codigo >= 4 && codigo <= 6) {
            totalAventura += cantidades[i];
        }
        if (codigo >= 7 && codigo <= 9) {
            totalEstrategia += cantidades[i];
        }
        if (codigo >= 10 && codigo <= 12) {
            totalAccion += cantidades[i];
        }
    }


    if (totalAccion >= 3) {
        cout << "¡Descuento especial! 15% por 3+ juegos de Acción\n";
        return 0.15; // 15% de descuento por 3+ juegos de acción
    }
    if (totalEstrategia >= 3 && totalAccion >= 2) {
        cout << "¡Descuento especial! 12% por combo Estrategia + Acción\n";
        return 0.12; // 12% de descuento por combo
    }
    if (totalEstrategia >= 3) {
        cout << "¡Descuento especial! 10% por 3+ juegos de Estrategia\n";
        return 0.10; // 10% de descuento por 3+ juegos de estrategia
    }
    if (totalDeportes >= 2 && totalAventura >= 2) {
        cout << "¡Descuento especial! 8% por combo Deportes + Aventura\n";
        return 0.08; // 8% de descuento por mezcla de categorías
    }
    if (totalAccion >= 2) {
        cout << "¡Descuento especial! 5% por 2+ juegos de Acción\n";
        return 0.05; // 5% de descuento por 2+ juegos de acción
    }

    return 0.0;

}

double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales) {
    double total = subtotal * ( 1.0 - ( porcentajeDescuento + descuentosAdicionales ) );
    return total;
}

void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento) {
    cout << "\n--- Resumen de Compra ---\n";
    double subtotal = 0.0;

    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        string nombre = obtenerNombreJuego(codigos[i]);
        int precio = obtenerPrecioJuego(codigos[i]);
        double cuenta = precio * cantidades[i];
        subtotal += cuenta;
        cout << nombre << ", " << cantidades[i] << " = $ " << cuenta << "\n";
    }

    double descuentosExtra = calcularDescuentosAdicionales(codigos, cantidades, cantidadJuegosRegistrados);

    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Descuento cliente: " << (porcentajeDescuento * 100) << "%\n";
    cout << "Descuentos adicionales: " << (descuentosExtra * 100) << "%\n";

    double totalPagar = subtotal * (1.0 - porcentajeDescuento) * (1.0 - descuentosExtra);

    cout << "Total a pagar: $" << totalPagar << "\n";
}

void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {

    cantidadJuegosRegistrados = 0;


    codigos[0] = 1;     // FIFA 2025
    cantidades[0] = 2;

    codigos[1] = 4;     // Mario Infinity
    cantidades[1] = 1;

    codigos[2] = 7;     // Star Wars
    cantidades[2] = 3;

    codigos[3] = 10;    // Call of Duty
    cantidades[3] = 1;

    cantidadJuegosRegistrados = 4;

    cout << "Compra demo cargada exitosamente!\n";
    cout << "Se agregaron 4 productos al carrito.\n";

}

