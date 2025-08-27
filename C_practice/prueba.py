import TADEstudiante

from TADEstudiante import *


estudiante1 = crearEstudiante()

nombre = input("Ingrese el nombre del estudiante: ")
apellido = input("Ingrese el apellido del estudiante: ")
legajo = int(input ("Ingrese el legajo del estudiante: "))
promedio = float(input("Ingrese el promedio del estudiante"))

cargarEstudiante(estudiante1,nombre,apellido,legajo,promedio)

print("el nombre del estudiante es: ",verNombre(estudiante1))
print(verApellido(estudiante1))
print(verLegajo(estudiante1))
print(verPromedio(estudiante1))


estudiante2 = crearEstudiante()

nombre = input("Ingrese el nombre del estudiante: ")
apellido = input("Ingrese el apellido del estudiante: ")
legajo = int(input ("Ingrese el legajo del estudiante: "))
promedio = float(input("Ingrese el promedio del estudiante"))

cargarEstudiante(estudiante2,nombre,apellido,legajo,promedio)

print(verNombre(estudiante2))
print(verApellido(estudiante2))
print(verLegajo(estudiante2))
print(verPromedio(estudiante2))


if verPromedio(estudiante1) > verPromedio(estudiante2):
    print("El estudiante 1 tiene mayor promedio")
else:
    print("El estudiante 2 tiene mayor promedio")