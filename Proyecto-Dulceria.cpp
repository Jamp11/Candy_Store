#include<stdio.h>
#include<iostream>
#include "Dulceria.h"

using namespace std;
int main(){
	
Milista1 lista1=NULL;
Milista2 lista2=NULL;
Milista3 lista3=NULL;

	
Proveedores proveedores;
Dulces dulce;
Ventas venta;
	
system("color B");

int opc, opc1;

cout<<endl;
cout<<"               Bienvendidos a la dulceria "<<endl;
cout<<"    By Ariadna Berenice Flores Jimenez & Jose Antonio Milanes ";
cout<<endl<<endl;

do{
	
cout<<endl;
cout<<"  1. Proveedores"<<endl;
cout<<"  2. Dulces"<<endl;
cout<<"  3. Ventas"<<endl<<endl;
cout<<"  4. Salir"<<endl<<endl;

cout<<" Introduzca opcion (1-4) ---> ";

cin>>opc;

switch(opc){
	case 1:
    	system("cls");
		do{
			cout<<endl<<endl;
		cout<<"Proveedores: "<<endl<<endl;
		cout<<" 1. Dar de alta un Proveedor"<<endl;
		cout<<" 2. Consultar informacion de los Proveedores"<<endl;
		cout<<" 3. Modificacion de un Proveedor"<<endl;
		cout<<" 4. Eliminar un Proveedor"<<endl<<endl;
		cout<<" 5. Salir"<<endl<<endl;
		
		cout<<" Introduzca opcion (1-5) ---> ";
		cin>>opc1;
		
		switch(opc1){
			
			case 1: 
			system("cls");cout<<" Registrar Proveedor"<<endl<<endl;
									proveedores.RegistrarG();	
			break;
			
			case 2: 
			system("cls");cout<<" Mostrar Proveedor"<<endl<<endl;
									proveedores.MostrarG(lista1);
			break;
			
			case 3: 
			system("cls");cout<<" Modificar Proveedor"<<endl<<endl;
									proveedores.ModificarG();
			break;
			
			case 4: 
			system("cls");cout<<" Eliminar Proveedor"<<endl<<endl;
									proveedores.EliminarG();
			break;
	            	}
		
		 } while ( opc1 != 5 );
		
		break;
				
	case 2:
		system("cls");
		do{
			cout<<endl<<endl;
		cout<<"Dulces: "<<endl<<endl;
		cout<<" 1. Dar de alta un dulce"<<endl;
		cout<<" 2. Consultar informacion de los dulces"<<endl;
		cout<<" 3. Modificacion de un dulce "<<endl;
		cout<<" 4. Eliminar un dulce"<<endl<<endl;
		cout<<" 5. Salir"<<endl<<endl;
		
		cout<<" Introduzca opcion (1-5) ---> ";
		cin>>opc1;
		
		switch(opc1){
			
			case 1: 
			system("cls");cout<<" Registrar Dulce"<<endl<<endl;
									dulce.RegistrarG();	
			break;
			
			case 2: 
			system("cls");cout<<" Mostrar Dulces"<<endl<<endl;
									dulce.MostrarG(lista2);
			break;
			
			case 3: 
			system("cls");cout<<" Modificar Dulces"<<endl<<endl;
									dulce.ModificarG();
			break;
			
			case 4: 
			system("cls");cout<<" Eliminar Dulce"<<endl<<endl;
									dulce.EliminarG();
			break;
	            	}
		
		 } while ( opc1 != 5 );
		 	
		break;
		
	case 3:
		system("cls");
		do{
			cout<<endl<<endl;
		cout<<"Ventas: "<<endl<<endl;
		cout<<" 1. Dar de alta una venta"<<endl;
		cout<<" 2. Consultar informacion de las ventas"<<endl;
		cout<<" 3. Modificacion de una venta"<<endl;
		cout<<" 4. Eliminar una venta"<<endl<<endl;
		cout<<" 5. Salir"<<endl<<endl;
		
		cout<<" Introduzca opcion (1-5) ---> ";
		cin>>opc1;
		
		switch(opc1){
		
			case 1: 
			system("cls");cout<<" Registrar Venta"<<endl<<endl;
									venta.RegistrarG();	
			break;
			
			case 2: 
			system("cls");cout<<" Mostrar Ventas"<<endl<<endl;
									venta.MostrarG(lista3);
			break;
			
			case 3: 
			system("cls");cout<<" Modificar Venta"<<endl<<endl;
									venta.ModificarG();
			break;
			
			case 4: 
			system("cls");cout<<" Eliminar Venta"<<endl<<endl;
									venta.EliminarG();
			break;
	            	}
		
		 } while ( opc1 != 5 );
	
	    break;	
		
            }
			
	    system("cls");	
	    
  } while ( opc != 4 );
  
system ("pause");
	
}
