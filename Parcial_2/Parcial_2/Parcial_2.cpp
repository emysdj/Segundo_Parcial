// Parcial_2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
#include <string.h>
using namespace std;
int q_estado;
MYSQL_ROW fila;
MYSQL_RES* resultado;
MYSQL* conectar;

int main()
{
	system("title Emily Juarez Carne: 3590-20-4067");
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_parcial 2", "Parcial123", "db_impar", 3306, NULL, 0);
	if (conectar) {
				cout << "Ingrese Tabla Empleados" << endl;
		string nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso;
		cout << "Ingrese Nombres:";
		cin >> nombres;
		cout << "Ingrese Apellidos:";
		cin >> apellidos;
		cout << "Ingrese Direccion:";
		cin >> direccion;
		cout << "Ingrese Telefono:";
		cin >> telefono;
		cout << "Ingrese DPI:";
		cin >> DPI;
		cout << "Ingrese Genero:";
		cin >> genero;
		cout << "Ingrese Fecha de nacimiento:";
		cin >> fecha_nacimiento;
		cout << "Ingrese idpuesto:";
		cin >> idPuesto;
		cout << "Ingrese Fecha de inicio de labores:";
		cin >> fecha_inicio_labores;
		cout << "Ingrese Fecha de ingreso:";
		cin >> fecha_ingreso;
		string insert = "insert into empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso) values('" + nombres + "', '" + apellidos + "', '" + direccion + "', '" + telefono + "', '" + DPI+ "', '" + genero + "', '" + fecha_nacimiento + "', '" + idPuesto + "', '" + fecha_inicio_labores + "', '" + fecha_ingreso + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso Exitoso..." << endl;
		}
		else {
			cout << "*** Error al ingresar ***" << endl;
			system("cls");
		}

				cout << "Empleados Registrados:" << endl;
		string consulta = "select *from empleados";
		const char* consultar = consulta.c_str();
		q_estado = mysql_query(conectar, consultar);

		if (!q_estado) {
			resultado = mysql_store_result(conectar);

			while (fila = mysql_fetch_row(resultado)) {

				cout << fila[0] << " - " << fila[1] << " - " << fila[2] << " - " << fila[3] << " - " << fila[4] << " - " << fila[5] << " - " << fila[6] << " - " << fila[7] << " - " << fila[8] << " - " << fila[9] << " - " << fila[10] << " - " << fila[11] << endl;
			}
			cout << "\n" << endl; system("pause");
		}
		else {
			cout << "xxx Error al consultar xxx" << endl;
		}
					cout << "Actualizar Empleados:" << endl;
		string dato; 
		cout << "Digita el id a actualizar:";  cin >> dato;
		string consulta = "UPDATE empleados set nombres = '" + nombres + "' , apellidos= '" + apellidos + "', direccion= '" + direccion + "', telefono= '" + telefono + "',DPI= '" + DPI + "',genero= '" + genero + "',fecha_nacimiento= '" + fecha_nacimiento + "',"' , idPuestos = '" +idPuesto+"',fecha_inicio_labores ='" + fecha_inicio-labores + "',fecha_ingreso= '" +fechaingreso+ "', WHERE idEmpleados = '"+dato"'";

			const char* i = consulta.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "\n\n\t\tDatos agregados con exito...\n\n" << endl;
			system("pause");
		}
		else {
			cout << "\n\n\t\tError al agregar los datos..\n\n" << endl;
			system("pause");
		}

				cout << "Empleados Registrados:" << endl;
		string consulta = "select *from empleados";
		const char* consultar = consulta.c_str();
		q_estado = mysql_query(conectar, consultar);

		if (!q_estado) {
			resultado = mysql_store_result(conectar);

			while (fila = mysql_fetch_row(resultado)) {

				cout << fila[0] << " - " << fila[1] << " - " << fila[2] << " - " << fila[3] << " - " << fila[4] << " - " << fila[5] << " - " << fila[6] << " - " << fila[7] << " - " << fila[8] << " - " << fila[9] << " - " << fila[10] << " - " << fila[11] << endl;
			}
			cout << "\n" << endl; system("pause");
		}
		else {
			cout << "xxx Error al consultar xxx" << endl;
		}

				cout << "Eliminar Empleado \n\n" << endl;
		string dato2;

		cout << "ID del empleado a eliminar: ";
		cin >> dato;

		cout << "Esta seguro que desa eliminar el dato (s/n): "; cin >> dato2;

		if (dato2 == "s") {
			consulta = "delete from Empleado  where idEmpleado = '" + dato + "'";
			const char* insertar = consulta.c_str();
			q_estado = mysql_query(conectar, insertar);

		}

		else {
			cout << " \n\nDatos no eliminados.." << endl;
		}


		if (!q_estado) {

			cout << "\n\n\t\tDatos eliminados con exito...\n\n" << endl;
			system("pause");
		}
		else {
			cout << "\n\n\t\tError al eliminar los datos..\n\n" << endl;
			system("pause");
		}

				cout << "Empleados Registrados:" << endl;

		string consulta = "select *from empleados";
		const char* consultar = consulta.c_str();
		q_estado = mysql_query(conectar, consultar);

		if (!q_estado) {
			resultado = mysql_store_result(conectar);

			while (fila = mysql_fetch_row(resultado)) {

				cout << fila[0] << " - " << fila[1] << " - " << fila[2] << " - " << fila[3] << " - " << fila[4] << " - " << fila[5] << " - " << fila[6] << " - " << fila[7] << " - " << fila[8] << " - " << fila[9] << " - " << fila[10] << " - " << fila[11] << endl;
			}
			cout << "\n" << endl; system("pause");
		}
		else {
			cout << "xxx Error al consultar xxx" << endl;
		}
		/*Tabla Puesto CRUD */
		cout << "Ingrese Tabla Puesto" << endl;
		string puesto;
		cout << "Ingrese Puesto:";
		cin >> puesto;
		string insert = "insert into puestos(puesto ) values('" + puesto + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso Exitoso..." << endl;
		}
		else {
			cout << "*** Error al ingresar ***" << endl;
			system("cls");
		}
		
				cout << "Modificar Tabla Puesto" << endl;

		cout << " el id del puesto a modificar";
		cin >> dato2;

		cout << "el nombre del nuevo puesto: ";
		cin >> dato;
		consulta = "update puestos set puesto = '" + dato + "' where idPuestos = ('" + dato2 + "'); ";
		const char* insertar = consulta.c_str();
		q_estado = mysql_query(conectar, insertar);

		if (!q_estado) {


			cout << "\n\n\t\tDatos agregados con exito...\n\n" << endl;
			system("pause");
		}
		else {

			cout << "\n\n\t\tError al agregar los datos..\n\n" << endl;
			cout << consulta;

			system("pause");
		}
		cout << "Eliminar Tabla Puesto" << endl;
		string dato_nuevo;
		cout << "\neliminar puesto por id: ";
		cin >> dato;

		cout << "Esta seguro que desa eliminar el dato (s/n): "; cin >> dato2;

		if (dato2 == "s" || dato2 == "S") {
			consulta = "delete from Puesto  where idPuesto = '" + dato + "'";
			const char* insertar = consulta.c_str();
			q_estado = mysql_query(conectar, insertar);

		}

		else if (dato_nuevo == "n" || dato_nuevo == "N") {
			cout << " \n\nDatos no eliminados.." << endl;
		}


		if (!q_estado) {

			cout << "\n\n\t\tDatos eliminados con exito...\n\n" << endl;
			system("pause");
		}
		else {
			cout << "\n\n\t\tError al agregar los datos..\n\n" << endl;
			system("pause");
		}


	 }
	else {
		cout << "Error en la Conexion" << endl;
	}
   system("pause");
   return 0; 
}

