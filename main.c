#include <stdio.h>
#include <string.h>

void IngreseMascota(int numMascotas[10], char mascota[10][50], char tipo[10][50], int edad[10], char nombreDueno[10][50], int id);
void serviciosDisponibles(float precioservicio[4], char *servicios[], char *descripcion[]);
void FacturacionMascotas(float precioservicio[4], char *servicios[], char *descripcion[], int numMascotas[10], char mascota[10][50], char tipo[10][50], int edad[10], char nombreDueno[10][50], int id);

int main(int argc, char const *argv[])
{
    int numMascotas[10] = {0};
    float precioservicio[4] = {12, 6, 5, 1.20};
    char opcion;
    char mascota[10][50];
    char tipo[10][50];
    int edad[10] = {0};
    char nombreDueno[10][50];
    char *servicios[] = {"Corte de pelo", "Chequeo medico", "Collar", "Comida Mascotas"};
    char *descripcion[] = {"Corte de Maquina", "Revision medica", "Collar artesanal", "Comida nutricional"};
    do
    {
        printf("--------------MENU-------------\n");
        printf("a. Ingreso de Mascota\n");
        printf("b. Servicios\n");
        printf("c. Facturar servicio\n");
        printf("d. Salir\n");
        printf("--------------------------------\n");

        printf("Seleccione una opcion:\n");
        scanf(" %c", &opcion);
        switch (opcion)
        {
        case 'a':
            printf("Ingrese el ID de la mascota: ");
            int id;
            scanf("%d", &id);
            if (id >= 1 && id <= 10)
            {
                IngreseMascota(numMascotas, mascota, tipo, edad, nombreDueno, id);
            }
            else
            {
                printf("ID de mascota no valido.\n");
            }
            break;
        case 'b':
            serviciosDisponibles(precioservicio, servicios, descripcion);
            break;
        case 'c':
            printf("Ingrese el ID de la mascota: ");
            int facturaId;
            scanf("%d", &facturaId);
            if (facturaId >= 1 && facturaId <= 10 && numMascotas[facturaId - 1] == 1){
                FacturacionMascotas(precioservicio, servicios, descripcion, numMascotas, mascota, tipo, edad, nombreDueno, id);
            }
            else{
                printf("ID de mascota no valido o no existe una mascota con ese ID.\n");
            }
            break;
        case 'd':
            printf("Se ha elegido la opcion de salir\n");
            break;
        default:
            printf("Opcion no valida. Intenta de nuevo.\n\n");
            break;
        }
    } while (opcion != 'd');

    return 0;
}

void IngreseMascota(int numMascotas[10], char mascota[10][50], char tipo[10][50], int edad[10], char nombreDueno[10][50], int id)
{
    if (id >= 1 && id <= 10)
    {
        id--; 
        if (numMascotas[id] == 0)
        {
            printf("Ingrese el nombre de su mascota: ");
            scanf("%s", mascota[id]);
            printf("Ingrese el tipo de mascota: ");
            scanf("%s", tipo[id]);
            printf("Ingrese la edad de su mascota: ");
            scanf("%d", &edad[id]);
            printf("Ingrese el nombre de su dueno: ");
            scanf("%s", nombreDueno[id]);
            numMascotas[id] = 1;
            printf("Mascota ingresada correctamente.\n");
        }
        else
        {
            printf("Ya existe una mascota con ese ID.\n");
        }
    }
    else
    {
        printf("ID de mascota no valido.\n");
    }
}

void serviciosDisponibles(float precioservicio[4], char *servicios[], char *descripcion[])
{
    printf("------------------------------- SERVICIOS -------------------------------\n");
    printf("|   ID   |      Nombre      |       Descripcion       |   Precio   |\n");
    printf("-------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 4; i++)
    {
        printf("|   %d    | %-16s | %-25s | %9.2f |\n", i + 1, servicios[i], descripcion[i], precioservicio[i]);
    }
    printf("-------------------------------------------------------------------------------------------\n");
}

void FacturacionMascotas(float precioservicio[4], char *servicios[], char *descripcion[], int numMascotas[10], char mascota[10][50], char tipo[10][50], int edad[10], char nombreDueno[10][50], int id)
{
    printf("+---------------------------------------------------+\n");
    printf("---------------------Factura-------------------------\n");

    if (id >= 1 && id <= 10 && numMascotas[id - 1] == 1)
    {
        id--; 
        printf("Nombre: %s\n", mascota[id]);
        printf("Tipo: %s\n", tipo[id]);
        printf("Edad: %d\n", edad[id]);
        printf("Dueno: %s\n", nombreDueno[id]);
    }
    else
    {
        printf("ID de mascota no valido o no existe una mascota con ese ID.\n");
        return;
    }

    printf("+---------------------------------------------------+\n");
    printf("+--------------------Servicios----------------------+\n");

    int numServicios = 0; 
    char opcion;
    int servicio;
    float total = 0;

    do{
        serviciosDisponibles(precioservicio, servicios, descripcion);
        printf("Ingrese el ID del servicio a realizar: ");
        scanf(" %d", &servicio);

        if (servicio >= 1 && servicio <= 4){
            total += precioservicio[servicio - 1];
        }
        else{
            printf("ID de servicio no valido.\n");
        }
        printf("¿Desea anadir otro servicio? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');
    printf("+---------------------------------------------------+\n");
    printf("Total a pagar: %.2f\n", total);
}