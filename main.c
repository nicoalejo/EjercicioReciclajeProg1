#include <stdio.h>
#include <string.h>

int login();
void menu();
void reciclaje();
float calcularPrecioMaterial(char tipo_material, float cantidad);
float calcularBono(float total);
void interactuarRedSocial();

int main() {
    int acceso = login();

    if (acceso == 1) {
        menu();
    }
    return 0;
}

int login() {
    int intentos = 3;    
    char usuario1[20] = "usuario1";
    char usuario2[20] = "usuario2";
    char usuario3[20] = "usuario3";     
    char password1[20] = "pass1";
    char password2[20] = "pass2";
    char password3[20] = "pass3";
    char usuario[20];
    char password[20];

    for (int i = 1; i <= intentos; i++) {
        printf("Ingrese su usuario: ");
        scanf("%s", usuario);
        printf("Ingrese su contraseña: ");
        scanf("%s", password);

        if (strcmp(usuario, usuario1) == 0 && strcmp(password, password1) == 0) {
                printf("Login Exitoso\n");
                return 1;
            }
        else if (strcmp(usuario, usuario2) == 0 && strcmp(password, password2) == 0)
        {
            printf("Login Exitoso\n");
            return 1;
        }else if (strcmp(usuario, usuario3) == 0 && (strcmp(password, password3) == 0))
        {
            printf("Login Exitoso\n");
            return 1;
        }
        
        printf("Usuario o contraseña fallidos intento #%d\n", i);
    }
    printf("Imposible ingresar\n");
    return 0;
}

void menu() {
    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Realizar reciclaje\n");
        printf("2. Red social\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                reciclaje();
                break;
            case 2:
                interactuarRedSocial();
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida, por favor intente de nuevo.\n");
        }
    } while (opcion != 3);
}

void reciclaje() {
    for (int i = 0; i < 2; i++) {
        char tipo_material;
        float cantidad;
        printf("\nCliente %d\n", i + 1);
        printf("Ingrese el tipo de material (P: Papel, V: Vidrio, L: Plastico, M: Metal): ");
        scanf(" %c", &tipo_material);
        printf("Ingrese la cantidad en kilogramos: ");
        scanf("%f", &cantidad);

        float total = calcularPrecioMaterial(tipo_material, cantidad);
        float bono = calcularBono(total);

        printf("Total: $%.2f\n", total);
        printf("Bono: $%.2f\n", bono);
        printf("Total + Bono: $%.2f\n", total+bono);
    }
}

float calcularPrecioMaterial(char tipo_material, float cantidad) {
    float precio;
    switch (tipo_material) {
        case 'P':
        case 'p':
            precio = 0.10;
            break;
        case 'V':
        case 'v':
            precio = 0.20;
            break;
        case 'L':
        case 'l':
            precio = 0.15;
            break;
        case 'M':
        case 'm':
            precio = 0.25;
            break;
        default:
            printf("Tipo de material invalido.\n");
            return 0;
    }
    return precio * cantidad;
}

float calcularBono(float total) {
    float bono;
    if (total < 50) {
        bono = 0;
    } else if (total >= 50 && total < 100) {
        bono = total * 0.05;
    } else if (total >= 100 && total < 500) {
        bono = total * 0.10;
    } else {
        bono = total * 0.20;
    }
        return bono;
}

void interactuarRedSocial(){
    for (int i = 0; i < 5; i++)
    {
        char mensaje[200];
        int puntuacion;
        char puntuacionTexto[50];        
        printf("Ingrese su mensaje en la red social\n");
        scanf("%s", &mensaje);
        do
        {
            fflush(stdin);            
            printf("Ingrese su puntuacion en la red social entre 1 y 5\n");            
            scanf("%d", &puntuacion);
            if(puntuacion < 1 || puntuacion > 5){
                printf("Puntuacion incorrecta ingrese un valor entre 1 y 5\n");
                //break;
            }
        } while (puntuacion < 1 || puntuacion > 5);
                
        switch (puntuacion)
        {
            case 1:
            case 2:
                //printf("Mensaje Negativo");
                strncpy(puntuacionTexto, "Mensaje Negativo", 50); 
                break;
            case 3:    
                strncpy(puntuacionTexto, "Mensaje Neutral", 50); 
                break;
            case 4:
            case 5:
                strncpy(puntuacionTexto, "Mensaje Positivo", 50); 
                break;        
        }

        printf("Su mensaje es %s\n", mensaje);
        printf("Su valoracion es %s\n", puntuacionTexto);
    }
    
}