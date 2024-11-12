#include <stdio.h>
#include <stdlib.h>
#include<string.h>>

typedef struct paciente {
    int dni;
    char nombre[30];
    char apellido[30];
    struct paciente* next;
}paciente;

typedef struct profesional {
    int dni;
    char Nombre[30];
    char Apellido[30];
    char Especialidad[30];
    int pacientesAtendidos;
    struct profesional* next;
}profesional;

typedef struct turno {
    int dni;
    char nombre[30];
    char apellido[30];
    int horario;
    int dni_profesional;
    char tipo_atencion; // P = particular; S = Obra social
    struct turno* next;
} turno;

typedef struct atencion {
    int dni;
    int dni_profesional;
    char tipo_atencion;
    struct atencion* next;
}atencion;

turno* crearturno(int dni, char* nombre, char* apellido, int horario, int dni_profesional, char tipo_atencion) {
    turno* nuevoTurno = (turno*)malloc(sizeof(turno));
    nuevoTurno->dni = dni;
    strcpy(nuevoTurno->nombre, nombre);
    strcpy(nuevoTurno->apellido, apellido);
    nuevoTurno->horario = horario;
    nuevoTurno->dni_profesional = dni_profesional;
    nuevoTurno->tipo_atencion = tipo_atencion;
    nuevoTurno->next = NULL;
    return nuevoTurno;
}

void encolarTurno(turno** cola, turno* nuevoTurno){
    if (*cola == NULL) {
        *cola = nuevoTurno;
    }else {
        turno* temp = *cola;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next= nuevoTurno;
    }
}

atencion* registrarAtencion(atencion* lista,int dni, int dni_profesional, char tipo_atencion) {
    atencion* nuevaAtencion= (atencion*)malloc(sizeof(atencion));
    nuevaAtencion->dni = dni;
    nuevaAtencion->dni_profesional = dni_profesional;
    nuevaAtencion->tipo_atencion = tipo_atencion;
    nuevaAtencion->next = lista;
    return nuevaAtencion;
}

paciente* buscarPaciente(paciente* agenda, int dni) {
    paciente* temp = agenda;
    while (temp != NULL) {
        if (temp->dni == dni) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

paciente* agregarPaciente(paciente* agenda, int dni, char* nombre, char* apellido, char obra_social){
    paciente* nuevoPaciente = (paciente*)malloc(sizeof(paciente));
    nuevoPaciente->dni = dni;
    strcpy(nuevoPaciente->nombre, nombre);
    strcpy(nuevoPaciente->apellido, apellido);
    nuevoPaciente->obra_social = obra_social;
    nuevoPaciente->next = agenda;
    return nuevoPaciente;
}

profesional* buscarProfesional(profesional* listaProfesionales, int dni) {
    profesional* temp = listaProfesionales;
    while (temp != NULL) {
        if (temp->dni == dni) return temp;
        temp = temp->next;
    }
    return NULL;
}

void procesarAtencion(turno** cola, paciente** agenda, atencion** listaAtenciones, profesional* listaProfesionales) {
    turno* turnoActual;
    while (*cola != NULL) {
        turnoActual = *cola;
        *cola = (*cola)->next;

        paciente* paciente = buscarPaciente(*agenda, turnoActual->dni);
        if (paciente == NULL) {
            *agenda = agregarPaciente(*agenda, turnoActual->dni, turnoActual->nombre, turnoActual->apellido, turnoActual->tipo_atencion);
        }
        
        *listaAtenciones = registrarAtencion(*listaAtenciones, turnoActual->dni, turnoActual->dni_profesional, turnoActual->tipo_atencion);
        
        profesional* profesional = buscarProfesional(listaProfesionales, turnoActual->dni_profesional);
        if (profesional != NULL) profesional->pacientesAtendidos++;
        
        free(turnoActual);
    }
}

void informeProfesionales(profesional* listaprofesionales){
    if listaprofesionales == NULL){
        return;
    }else {
        printf("Profesional: %s %s - Atendió %d pacientes\n", listaprofesionales->nombre, listaprofesionales->apellido, listaprofesionales->pacientesAtendidos);
        informePorProfesional(listaProfesionales->next);

    }
}