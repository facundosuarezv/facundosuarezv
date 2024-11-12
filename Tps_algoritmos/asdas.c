#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    int dni;
    char nombre[30];
    char apellido[30];
    char obra_social; 
} Paciente;

typedef struct Profesional {
    int dni;
    char nombre[30];
    char apellido[30];
    char especialidad[30];
    int pacientesAtendidos;
} Profesional;

typedef struct Turno {
    int dni;
    char nombre[30];
    char apellido[30];
    int horario;
    int dni_profesional;
    char tipo_atencion; 
    struct Turno* next;
} Turno;

typedef struct Atencion {
    int dni;
    int dni_profesional;
    char tipo_atencion;
    struct Atencion* next;
} Atencion;

Turno* crearTurno(int dni, char* nombre, char* apellido, int horario, int dni_profesional, char tipo_atencion) {
    Turno* nuevoTurno = (Turno*)malloc(sizeof(Turno));
    nuevoTurno->dni = dni;
    strcpy(nuevoTurno->nombre, nombre);
    strcpy(nuevoTurno->apellido, apellido);
    nuevoTurno->horario = horario;
    nuevoTurno->dni_profesional = dni_profesional;
    nuevoTurno->tipo_atencion = tipo_atencion;
    nuevoTurno->next = NULL;
    return nuevoTurno;
}

void encolarTurno(Turno** cola, Turno* nuevoTurno) {
    if (*cola == NULL) {
        *cola = nuevoTurno;
    } else {
        Turno* temp = *cola;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuevoTurno;
    }
}

Atencion* registrarAtencion(Atencion* lista, int dni, int dni_profesional, char tipo_atencion) {
    Atencion* nuevaAtencion = (Atencion*)malloc(sizeof(Atencion));
    nuevaAtencion->dni = dni;
    nuevaAtencion->dni_profesional = dni_profesional;
    nuevaAtencion->tipo_atencion = tipo_atencion;
    nuevaAtencion->next = lista;
    return nuevaAtencion;
}

Paciente* buscarPaciente(Paciente* agenda, int dni) {
    Paciente* temp = agenda;
    while (temp != NULL) {
        if (temp->dni == dni) return temp;
        temp = temp->next;
    }
    return NULL;
}

Paciente* agregarPaciente(Paciente* agenda, int dni, char* nombre, char* apellido, char obra_social) {
    Paciente* nuevoPaciente = (Paciente*)malloc(sizeof(Paciente));
    nuevoPaciente->dni = dni;
    strcpy(nuevoPaciente->nombre, nombre);
    strcpy(nuevoPaciente->apellido, apellido);
    nuevoPaciente->obra_social = obra_social;
    nuevoPaciente->next = agenda;
    return nuevoPaciente;
}

Profesional* buscarProfesional(Profesional* listaProfesionales, int dni) {
    Profesional* temp = listaProfesionales;
    while (temp != NULL) {
        if (temp->dni == dni) return temp;
        temp = temp->next;
    }
    return NULL;
}

void procesarAtencion(Turno** cola, Paciente** agenda, Atencion** listaAtenciones, Profesional* listaProfesionales) {
    Turno* turnoActual;
    while (*cola != NULL) {
        turnoActual = *cola;
        *cola = (*cola)->next;

        Paciente* paciente = buscarPaciente(*agenda, turnoActual->dni);
        if (paciente == NULL) {
            *agenda = agregarPaciente(*agenda, turnoActual->dni, turnoActual->nombre, turnoActual->apellido, turnoActual->tipo_atencion);
        }
        
        *listaAtenciones = registrarAtencion(*listaAtenciones, turnoActual->dni, turnoActual->dni_profesional, turnoActual->tipo_atencion);
        
        Profesional* profesional = buscarProfesional(listaProfesionales, turnoActual->dni_profesional);
        if (profesional != NULL) profesional->pacientesAtendidos++;
        
        free(turnoActual);
    }
}

void informeTotalAtenciones(Atencion* listaAtenciones, int* total, int* conObraSocial, int* particular) {
    if (listaAtenciones == NULL) return;
    if (listaAtenciones->tipo_atencion == 'S') (*conObraSocial)++;
    else (*particular)++;
    (*total)++;
    informeTotalAtenciones(listaAtenciones->next, total, conObraSocial, particular);
}

void informePorProfesional(Profesional* listaProfesionales) {
    if (listaProfesionales == NULL) return;
    printf("Profesional: %s %s - Atendió %d pacientes\n", listaProfesionales->nombre, listaProfesionales->apellido, listaProfesionales->pacientesAtendidos);
    informePorProfesional(listaProfesionales->next);
}

int main() {
    Paciente* agenda = NULL;
    Atencion* listaAtenciones = NULL;
    Profesional* listaProfesionales = NULL;
    Turno* colaTurnos = NULL;

    encolarTurno(&colaTurnos, crearTurno(12345678, "Juan", "Perez", 13, 111, 'S'));
    encolarTurno(&colaTurnos, crearTurno(87654321, "Ana", "Lopez", 14, 222, 'P'));
    encolarTurno(&colaTurnos, crearTurno(11223344, "Luis", "Gomez", 15, 111, 'S'));

    listaProfesionales = (Profesional*)malloc(sizeof(Profesional) * 2);
    listaProfesionales[0] = (Profesional){111, "Carlos", "Martinez", "Ortopedia", 0, NULL};
    listaProfesionales[1] = (Profesional){222, "Laura", "Sanchez", "Fisioterapia", 0, NULL};

    procesarAtencion(&colaTurnos, &agenda, &listaAtenciones, listaProfesionales);

    int totalAtendidos = 0, conObraSocial = 0, particular = 0;
    informeTotalAtenciones(listaAtenciones, &totalAtendidos, &conObraSocial, &particular);

    printf("Total de pacientes atendidos: %d\n", totalAtendidos);
    printf("Pacientes con obra social: %d\n", conObraSocial);
    printf("Pacientes particulares: %d\n", particular);

    informePorProfesional(listaProfesionales);
