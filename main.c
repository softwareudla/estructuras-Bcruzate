#include <stdio.h>
#include <string.h>

struct Libro {
    int id;
    char titulo[101];
    char autor[51];
    int anio_publicacion;
    char estado[11];
};

const int MAX_LIBROS = 20;
struct Libro biblioteca[20];
int total_libros = 0;

void agregarLibro();
void mostrarLibros();
void buscarLibro();
void modificarEstado();
void eliminarLibro();

int main() {
    int opcion;

    do {
        printf("\n=== Menu Biblioteca ===\n");
        printf("1. Agregar libro\n");
        printf("2. Mostrar todos los libros\n");
        printf("3. Buscar un libro\n");
        printf("4. Modificar estado de un libro\n");
        printf("5. Eliminar un libro\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarLibro();
                break;
            case 2:
                mostrarLibros();
                break;
            case 3:
                buscarLibro();
                break;
            case 4:
                modificarEstado();
                break;
            case 5:
                eliminarLibro();
                break;
            case 6:
                printf("Gracias por usar nuestra biblioteca\n");
                break;
            default:
                printf("Opción no valida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}

void agregarLibro() {
    if (total_libros >= MAX_LIBROS) {
        printf("No se pueden agregar mas libros.\n");
        return;
    }

    struct Libro nuevo_libro;

    do {
        printf("Ingrese el ID del libro (positivo): ");
        if (scanf("%d", &nuevo_libro.id) != 1 || nuevo_libro.id <= 0) {
            printf("Error: debe ingresar un numero entero positivo.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    } while (1);

    for (int i = 0; i < total_libros; i++) {
        if (biblioteca[i].id == nuevo_libro.id) {
            printf("Error: Ya existe un libro con ese ID.\n");
            return;
        }
    }

    printf("Ingrese el titulo del libro: ");
    getchar();
    fgets(nuevo_libro.titulo, 101, stdin);
    nuevo_libro.titulo[strcspn(nuevo_libro.titulo, "\n")] = 0;

    printf("Ingrese el autor del libro: ");
    fgets(nuevo_libro.autor, 51, stdin);
    nuevo_libro.autor[strcspn(nuevo_libro.autor, "\n")] = 0;

    do {
        printf("Ingrese el año de publicacion (positivo): ");
        if (scanf("%d", &nuevo_libro.anio_publicacion) != 1 || nuevo_libro.anio_publicacion <= 0) {
            printf("Error: debe ingresar un numero entero positivo.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    } while (1);

    strcpy(nuevo_libro.estado, "Disponible");

    biblioteca[total_libros++] = nuevo_libro;
    printf("Libro agregado correctamente.\n");
}

void mostrarLibros() {
    if (total_libros == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\nLista de libros:\n");
    printf("ID\tTítulo\t\tAutor\t\tAño\tEstado\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < total_libros; i++) {
        printf("%d\t%s\t%s\t%d\t%s\n", biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio_publicacion, biblioteca[i].estado);
    }
}

void buscarLibro() {
    int id;
    printf("Ingrese el ID del libro a buscar: ");
    scanf("%d", &id);

    for (int i = 0; i < total_libros; i++) {
        if (biblioteca[i].id == id) {
            printf("\nInformación del libro:\n");
            printf("ID: %d\n", biblioteca[i].id);
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Año de publicación: %d\n", biblioteca[i].anio_publicacion);
            printf("Estado: %s\n", biblioteca[i].estado);
            return;
        }
    }

    printf("Libro no encontrado.\n");
}

void modificarEstado() {
    int id;
    printf("Ingrese el ID del libro a modificar: ");
    scanf("%d", &id);

    for (int i = 0; i < total_libros; i++) {
        if (biblioteca[i].id == id) {
            printf("Estado actual: %s\n", biblioteca[i].estado);
            printf("Ingrese el nuevo estado (Disponible/Prestado): ");
            char nuevo_estado[11];
            getchar();
            fgets(nuevo_estado, 11, stdin);
            nuevo_estado[strcspn(nuevo_estado, "\n")] = 0;

            if (strcmp(nuevo_estado, "Disponible") == 0 || strcmp(nuevo_estado, "Prestado") == 0) {
                strcpy(biblioteca[i].estado, nuevo_estado);
                printf("Estado actualizado correctamente.\n");
            } else {
                printf("Estado no válido. Intente de nuevo.\n");
            }
            return;
        }
    }

    printf("Libro no encontrado.\n");
}

void eliminarLibro() {
    int id;
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < total_libros; i++) {
        if (biblioteca[i].id == id) {
            for (int j = i; j < total_libros - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            total_libros--;
            printf("Libro eliminado correctamente.\n");
            return;
        }
    }

    printf("Libro no encontrado.\n");
}
