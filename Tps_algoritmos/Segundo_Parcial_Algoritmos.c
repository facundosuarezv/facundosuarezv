
//FACUNDO SUAREZ VIGUERA - 33797

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    int dni;
    char nombre[30];
    char apellido[30];
    struct Paciente* next;
} Paciente;

typedef struct Turno {
    int dni;
    char nombre[30];
    char apellido[30];
    int horario;
    int dni_profesional;
    char tipo_atencion; // P = particular; S = Obra social
    struct Turno* next;
} Turno;

typedef struct Profesional {
    int dni;
    char nombre[30];
    char apellido[30];
    char especialidad[30];
    int pacientesAtendidos;
    struct Profesional* next;
} Profesional;

typedef struct Atencion {
    int dni;
    int dni_profesional;
    char tipo_atencion; 
    struct Atencion* next;
} Atencion;

Paciente* crearPaciente(int dni, char* nombre, char* apellido) {
    Paciente* nuevoPaciente = (Paciente*)malloc(sizeof(Paciente));
    nuevoPaciente->dni = dni;
    strcpy(nuevoPaciente->nombre, nombre);
    strcpy(nuevoPaciente->apellido, apellido);
    nuevoPaciente->next = NULL;
    return nuevoPaciente;
}

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

Profesional* crearProfesional(int dni, char* nombre, char* apellido, char* especialidad) {
    Profesional* nuevoProfesional = (Profesional*)malloc(sizeof(Profesional));
    nuevoProfesional->dni = dni;
    strcpy(nuevoProfesional->nombre, nombre);
    strcpy(nuevoProfesional->apellido, apellido);
    strcpy(nuevoProfesional->especialidad, especialidad);
    nuevoProfesional->pacientesAtendidos = 0;
    nuevoProfesional->next = NULL;
    return nuevoProfesional;
}

Atencion* registrarAtencion(Atencion* lista, int dni, int dni_profesional, char tipo_atencion) {
    Atencion* nuevaAtencion = (Atencion*)malloc(sizeof(Atencion));
    nuevaAtencion->dni = dni;
    nuevaAtencion->dni_profesional = dni_profesional;
    nuevaAtencion->tipo_atencion = tipo_atencion;
    nuevaAtencion->next = lista;
    return nuevaAtencion;
}

void agregarTurno(Turno** listaTurnos, Turno* turno) {
    if (*listaTurnos == NULL) {
        *listaTurnos = turno;
    } else {
        Turno* temp = *listaTurnos;
        while (temp->next != NULL) temp = temp->next;
        temp->next = turno;
    }
}

void agregarProfesional(Profesional** listaProfesionales, Profesional* profesional) {
    profesional->next = *listaProfesionales;
    *listaProfesionales = profesional;
}

int pacienteRegistrado(Paciente* agenda, int dni) {
    while (agenda != NULL) {
        if (agenda->dni == dni){
            return 1;
        }
        agenda = agenda->next;
    }
    return 0;
}

Paciente* registrarPaciente(Paciente* agenda, int dni, char* nombre, char* apellido) {
    Paciente* nuevoPaciente = crearPaciente(dni, nombre, apellido);
    nuevoPaciente->next = agenda;
    return nuevoPaciente;
}

Profesional* buscarProfesional(Profesional* listaProfesionales, int dni_profesional) {
    while (listaProfesionales != NULL) {
        if (listaProfesionales->dni == dni_profesional){
            return listaProfesionales;
        }
        listaProfesionales = listaProfesionales->next;
    }
    return NULL;
}

void procesarTurnos(Paciente** agenda, Turno** listaTurnos, Profesional* listaProfesionales, Atencion** listaAtenciones) {
    Turno* turnoActual = *listaTurnos;
    while (turnoActual != NULL) {
        if (!pacienteRegistrado(*agenda, turnoActual->dni)) {
            *agenda = registrarPaciente(*agenda, turnoActual->dni, turnoActual->nombre, turnoActual->apellido);
        }

        Profesional* profesional = buscarProfesional(listaProfesionales, turnoActual->dni_profesional);
        if (profesional != NULL) {
            profesional->pacientesAtendidos++;
            *listaAtenciones = registrarAtencion(*listaAtenciones, turnoActual->dni, turnoActual->dni_profesional, turnoActual->tipo_atencion);
        }

        Turno* temp = turnoActual;
        turnoActual = turnoActual->next;
        free(temp);
    }
    *listaTurnos = NULL;
}

int contarAtencionesPorTipo(Atencion* listaAtenciones, char tipo_atencion) {
    if (listaAtenciones == NULL){
        return 0;
    } 
    if (listaAtenciones->tipo_atencion == tipo_atencion){
        return 1 + contarAtencionesPorTipo(listaAtenciones->next, tipo_atencion);
    }
    return contarAtencionesPorTipo(listaAtenciones->next, tipo_atencion);
}

void informePorProfesional(Profesional* listaProfesionales) {
    if (listaProfesionales == NULL) {
        return;
    }
    printf("Profesional: %s %s - Atendió %d pacientes\n", listaProfesionales->nombre, listaProfesionales->apellido, listaProfesionales->pacientesAtendidos);
    informePorProfesional(listaProfesionales->next);
}

int main() {
    Paciente* agenda = NULL;
    Turno* listaTurnos = NULL;
    Profesional* listaProfesionales = NULL;
    Atencion* listaAtenciones = NULL;

    // Agregar profesionales
    agregarProfesional(&listaProfesionales, crearProfesional(111, "Juan", "Perez", "Traumatologia"));
    agregarProfesional(&listaProfesionales, crearProfesional(222, "Ana", "Garcia", "Ortopedia"));

    // Agregar turnos (por simplicidad, se agregan manualmente)
    agregarTurno(&listaTurnos, crearTurno(12345678, "Facundo", "Lopez", 1300, 111, 'S'));
    agregarTurno(&listaTurnos, crearTurno(87654321, "Valentina", "Gomez", 1400, 222, 'P'));
    agregarTurno(&listaTurnos, crearTurno(11223344, "Jose", "Suarez", 1500, 111, 'S'));

    procesarTurnos(&agenda, &listaTurnos, listaProfesionales, &listaAtenciones);

    int totalConObraSocial = contarAtencionesPorTipo(listaAtenciones, 'S');
    int totalParticular = contarAtencionesPorTipo(listaAtenciones, 'P');

    printf("Total de pacientes con obra social: %d\n", totalConObraSocial);
    printf("Total de pacientes particulares: %d\n", totalParticular);

    printf("\nInforme por profesional:\n");
    informePorProfesional(listaProfesionales);

    return 0;
}
