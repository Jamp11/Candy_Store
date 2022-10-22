#include<conio.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>

using namespace std;





//Proveedores

typedef class Proveedores *Milista1;

class Proveedores{
	protected:
		char codigo[20];
		char nomEmpresa[20];
		char nomEmpleado[20];
		char nomDulceP[20];
		char formaPagoP[15];
		int cantP;
		float costoP;
		
		public:
			class Proveedores *sgte;
			
			void RegistrarG();
		 	void ConsultarG();
			void EliminarG();
		 	void ModificarG();
		 	void MostrarG(Milista1&);
}proveedores;

void Proveedores::RegistrarG(){
	
  ofstream RegistrarG;
  RegistrarG.open("proveedores.dat",ios::out|ios::app|ios::binary);
  
  if(RegistrarG.fail())
  {
    cout<<"No se pudo crear el archivo";
    getch();      
  }
  
  else{
	cout<<endl<<"Codigo: "<<endl;
	fflush(stdin); gets(proveedores.codigo);
	cout<<endl<<"Nombre de la Empresa: "<<endl;
	fflush(stdin); gets(proveedores.nomEmpresa);
	cout<<endl<<"Nombre del Empleado: "<<endl;
	fflush(stdin); gets(proveedores.nomEmpleado);
	cout<<endl<<"Nombre del Dulce: "<<endl;
	fflush(stdin); gets(proveedores.nomDulceP);
	cout<<endl<<"Forma de Pago: "<<endl;
	fflush(stdin); gets(proveedores.formaPagoP);
	cout<<endl<<"Cantidad : "<<endl;
	cin>>proveedores.cantP;
	cout<<endl<<"Costo: "<<endl;
	cin>>proveedores.costoP;
	
  RegistrarG.write((char *)&proveedores,sizeof(Proveedores));
  RegistrarG.close();
}
}


void Proveedores::EliminarG(){
	
	 ofstream RegistrarG;
     RegistrarG.open("cambio1.dat",ios::out|ios::binary);
      
     ifstream ConsultarG;
     ConsultarG.open("proveedores.dat",ios::in|ios::binary);
     
     if (RegistrarG.fail()||ConsultarG.fail())
     {
     cout<<"No se pudo abrir el archivo"<<endl;
     getch();                  
     }
     
     else
     {
     	
     int bit, i;
     char nums[20];
     
     cout<<endl<<"A que Proveedor deseas eliminar? :"<<endl;
     cout<<"Codigo: "<<endl;
     cin>>nums;
     
     ConsultarG.seekg(0,ios::end);//Para ir al final del fichero
     bit=ConsultarG.tellg()/sizeof(Proveedores);//tellg para saber en que posicion estamos, se puede usar para conocer el tamano del fichero
     ConsultarG.seekg(0);  //seekg Saltar cierta posicion del fichero de lectura
     
       for(i=0;i<bit;i++)
              {
              ConsultarG.read((char *)&proveedores,sizeof(Proveedores));
                   if(strcmp(proveedores.codigo,nums)==0)
                     {
                     cout<<endl<<"Se ha eliminado el registro"<<endl;                             
                     }
                     
                     else
                     {
                     RegistrarG.write((char *)&proveedores,sizeof(Proveedores));    
                     }
                    
              }
     ConsultarG.close();
     RegistrarG.close();
     remove("proveedores.dat");
     rename("cambio1.dat","proveedores.dat");
     
     getch();   
     
     }
}

void Proveedores::ModificarG(){

	  ofstream RegistrarG;
      RegistrarG.open("cambio1.dat",ios::out|ios::binary);
      
      
     ifstream ConsultarG;
     ConsultarG.open("proveedores.dat",ios::in|ios::binary);
     
     if (RegistrarG.fail()||ConsultarG.fail()){
     cout<<"No se pudo abrir el archivo"<<endl;
     getch();                  
     }
     
     else{
     	
     int bit, reg, i;
     char nums[20];
     
     cout<<endl<<"A que Proveedor deseas modificar?:"<<endl;
     cout<<"Codigo: "<<endl;
     cin>>nums;
     
     
     ConsultarG.seekg(0,ios::end);
     bit=ConsultarG.tellg()/sizeof(Proveedores);
     ConsultarG.seekg(0);  
     
       for(i=0;i<bit;i++)
              {
              ConsultarG.read((char *)&proveedores,sizeof(Proveedores));
                   if(strcmp(proveedores.codigo,nums)==0){
                   	
                   	cout<<endl<<"Codigo: "<<endl;
	                fflush(stdin); gets(proveedores.codigo);
	                cout<<endl<<"Nombre de la Empresa: "<<endl;
	                fflush(stdin); gets(proveedores.nomEmpresa);
	                cout<<endl<<"Nombre del Empleado: "<<endl;
	                fflush(stdin); gets(proveedores.nomEmpleado);
	                cout<<endl<<"Nombre del Dulce: "<<endl;
	                fflush(stdin); gets(proveedores.nomDulceP);
	                cout<<endl<<"Forma de Pago: "<<endl;
	                fflush(stdin); gets(proveedores.formaPagoP);
                   	cout<<endl<<"Cantidad : "<<endl;
                 	cin>>proveedores.cantP;
                 	cout<<endl<<"Costo: "<<endl;
                 	cin>>proveedores.costoP;                   
                     }
                     
                     RegistrarG.write((char *)&proveedores,sizeof(Proveedores));    
              }
     ConsultarG.close();
     RegistrarG.close();
     remove("proveedores.dat");
     rename("cambio1.dat","proveedores.dat");
     
     getch();   
     
     }	
}

void Proveedores::MostrarG(Milista1 &lista)
{
	
	ifstream Consultar;
     Consultar.open("proveedores.dat",ios::in|ios::binary);
     
     if (Consultar.fail())
     {
     cout<<" No hay proveedores registrados "<<endl;
     getch();                  
     }
     
     else{
     	
     int bit, i;
    	Milista1 q;	
		  
     
     Consultar.seekg(0,ios::end);
     bit=Consultar.tellg()/sizeof(Proveedores);
     Consultar.seekg(0);  
     
       for(i=0;i<bit;i++)
              {
              Consultar.read((char *)&proveedores,sizeof(Proveedores));
               q=new(class Proveedores);
               strcpy(q->codigo,proveedores.codigo);
               strcpy(q->nomDulceP,proveedores.nomDulceP);
               strcpy(q->nomEmpresa,proveedores.nomEmpresa);
               strcpy(q->nomEmpleado,proveedores.nomEmpleado);
               strcpy(q->formaPagoP,proveedores.formaPagoP);
               q->cantP=proveedores.cantP;
			   q->costoP=proveedores.costoP;
			
			cout<<endl<<"Codigo: "<<q->codigo<<endl;
              cout<<"Nombre del Dulce: "<<q->nomDulceP<<endl;
              cout<<"Nombre del Empleado: "<<q->nomEmpleado<<endl;
              cout<<"Nombre de la Empresa: "<<q->nomEmpresa<<endl;
              cout<<"Forma de Pago: "<<q->formaPagoP<<endl;
              cout<<"Cantidad : "<<q->cantP<<endl;
              cout<<"Costo: "<<q->costoP<<endl;
			
				q->sgte=lista;
				lista=q;
			  
			  }
     
	 
	 Consultar.close();
     getch();
       
     }
	
}





//Dulces

typedef class Dulces *Milista2;

class Dulces{
	protected:
		char codigo[20];
		char nombre[40];
		int cant;
		float costo;
		
		public:
			class Dulces *sgte;
			
			void RegistrarG();
		 	void ConsultarG();
			void EliminarG();
		 	void ModificarG();
		 	void MostrarG(Milista2&);
}dulce;

void Dulces::RegistrarG(){
	
  ofstream RegistrarG;
  RegistrarG.open("dulces.dat",ios::out|ios::app|ios::binary);
  
  if(RegistrarG.fail())
  {
    cout<<"No se pudo crear el archivo";
    getch();      
  }
  
  else{
	cout<<endl<<"Codigo: "<<endl;
	fflush(stdin); gets(dulce.codigo);
	cout<<endl<<"Nombre del dulce: "<<endl;
	fflush(stdin); gets(dulce.nombre);
	cout<<endl<<"Cantidad de dulces: "<<endl;
	cin>>dulce.cant;
	cout<<endl<<"Precio del dulces: "<<endl;
	cin>>dulce.costo;
	
  RegistrarG.write((char *)&dulce,sizeof(Dulces));
  RegistrarG.close();
}
}


void Dulces::EliminarG(){
	
	 ofstream RegistrarG;
     RegistrarG.open("cambio1.dat",ios::out|ios::binary);
      
     ifstream ConsultarG;
     ConsultarG.open("dulces.dat",ios::in|ios::binary);
     
     if (RegistrarG.fail()||ConsultarG.fail())
     {
     cout<<"No se pudo abrir el archivo"<<endl;
     getch();                  
     }
     
     else
     {
     	
     int bit, i;
     char nums[20];
     
     cout<<endl<<"Que dulce deseas eliminar? :"<<endl;
     cout<<"Codigo: "<<endl;
     cin>>nums;
     
     ConsultarG.seekg(0,ios::end);
     bit=ConsultarG.tellg()/sizeof(Dulces);
     ConsultarG.seekg(0);  
     
       for(i=0;i<bit;i++)
              {
              ConsultarG.read((char *)&dulce,sizeof(Dulces));
                   if(strcmp(dulce.codigo,nums)==0)
                     {
                     cout<<endl<<"Se ha eliminado el dulce"<<endl;                             
                     }
                     
                     else
                     {
                     RegistrarG.write((char *)&dulce,sizeof(Dulces));    
                     }
                    
              }
     ConsultarG.close();
     RegistrarG.close();
     remove("dulces.dat");
     rename("cambio1.dat","dulces.dat");
     
     getch();   
     
     }
}

void Dulces::ModificarG(){

	  ofstream RegistrarG;
      RegistrarG.open("cambio1.dat",ios::out|ios::binary);
      
      
     ifstream ConsultarG;
     ConsultarG.open("dulces.dat",ios::in|ios::binary);
     
     if (RegistrarG.fail()||ConsultarG.fail()){
     cout<<"No se pudo abrir el archivo"<<endl;
     getch();                  
     }
     
     else{
     	
     int bit, reg, i;
     char nums[20];
     
     cout<<endl<<"Que dulce deseas modificar?:"<<endl;
     cout<<"Codigo: "<<endl;
     cin>>nums;
     
     
     ConsultarG.seekg(0,ios::end);
     bit=ConsultarG.tellg()/sizeof(Dulces);
     ConsultarG.seekg(0);  
     
       for(i=0;i<bit;i++)
              {
              ConsultarG.read((char *)&dulce,sizeof(Dulces));
                   if(strcmp(dulce.codigo,nums)==0){
                   	
                   	cout<<endl<<"Codigo: "<<endl;
	                fflush(stdin); gets(dulce.codigo);
	                cout<<endl<<"Nombre: "<<endl;
	                fflush(stdin); gets(dulce.nombre);
                   	cout<<endl<<"Cantida de dulces: "<<endl;
                 	cin>>dulce.cant;
                 	cout<<endl<<"Precio del dulce: "<<endl;
                 	cin>>dulce.costo;                   
                     }
                     
                     RegistrarG.write((char *)&dulce,sizeof(Dulces));    
              }
     ConsultarG.close();
     RegistrarG.close();
     remove("dulces.dat");
     rename("cambio1.dat","dulces.dat");
     
     getch();   
     
     }	
}

void Dulces::MostrarG(Milista2 &lista2)
{
	
	ifstream Consultar;
     Consultar.open("dulces.dat",ios::in|ios::binary);
     
     if (Consultar.fail())
     {
     cout<<" No hay dulces registrados "<<endl;
     getch();                  
     }
     
     else{
     	
     int bit, i;
    	Milista2 q;	
		  
     
     Consultar.seekg(0,ios::end);
     bit=Consultar.tellg()/sizeof(Dulces);
     Consultar.seekg(0);  
     
       for(i=0;i<bit;i++)
              {
              Consultar.read((char *)&dulce,sizeof(Dulces));
               q=new(class Dulces);
               strcpy(q->codigo,dulce.codigo);
               strcpy(q->nombre,dulce.nombre);
               q->cant=dulce.cant;
			   q->costo=dulce.costo;
			
			cout<<endl<<"Codigo: "<<q->codigo<<endl;
              cout<<"Nombre: "<<q->nombre<<endl;
              cout<<"Cantidad de dulces: "<<q->cant<<endl;
              cout<<"Precio del dulce: "<<q->costo<<endl;
			
				q->sgte=lista2;
				lista2=q;
			  
			  }
     
	 
	 Consultar.close();
     getch();
       
     }
	
}






//Ventas

typedef class Ventas *Milista3;

class Ventas{
	protected:
		char codigo[20];
		char nombre[40];
		char formaPagoP[15];
		int cant;
		float costo;
		
		public:
			class Ventas *sgte;
			
			void RegistrarG();
		 	void ConsultarG();
			void EliminarG();
		 	void ModificarG();
		 	void MostrarG(Milista3&);
}venta;

void Ventas::RegistrarG(){
	
  ofstream RegistrarG;
  RegistrarG.open("ventas.dat",ios::out|ios::app|ios::binary);
  
  if(RegistrarG.fail())
  {
    cout<<"No se pudo crear el archivo";
    getch();      
  }
  
  else{
	cout<<endl<<"Codigo: "<<endl;
	fflush(stdin); gets(venta.codigo);
	cout<<endl<<"Nombre del dulce a vender: "<<endl;
	fflush(stdin); gets(venta.nombre);
	cout<<endl<<"Cantidad de dulces vendidos: "<<endl;
	cin>>venta.cant;
	cout<<endl<<"Costo de la venta: "<<endl;
	cin>>venta.costo;
	cout<<endl<<"Forma de Pago: "<<endl;
	fflush(stdin); gets(venta.formaPagoP);
	
  RegistrarG.write((char *)&venta,sizeof(Ventas));
  RegistrarG.close();
}
}


void Ventas::EliminarG(){
	
	 ofstream RegistrarG;
     RegistrarG.open("cambio1.dat",ios::out|ios::binary);
      
     ifstream ConsultarG;
     ConsultarG.open("ventas.dat",ios::in|ios::binary);
     
     if (RegistrarG.fail()||ConsultarG.fail())
     {
     cout<<"No se pudo abrir el archivo"<<endl;
     getch();                  
     }
     
     else
     {
     	
     int bit, i;
     char nums[20];
     
     cout<<endl<<"Que venta deseas eliminar? :"<<endl;
     cout<<"Codigo: "<<endl;
     cin>>nums;
     
     ConsultarG.seekg(0,ios::end);
     bit=ConsultarG.tellg()/sizeof(Ventas);
     ConsultarG.seekg(0);  
     
       for(i=0;i<bit;i++)
              {
              ConsultarG.read((char *)&venta,sizeof(Ventas));
                   if(strcmp(venta.codigo,nums)==0)
                     {
                     cout<<endl<<"Se ha eliminado la venta"<<endl;                             
                     }
                     
                     else
                     {
                     RegistrarG.write((char *)&venta,sizeof(Ventas));    
                     }
                    
              }
     ConsultarG.close();
     RegistrarG.close();
     remove("ventas.dat");
     rename("cambio1.dat","ventas.dat");
     
     getch();   
     
     }
}

void Ventas::ModificarG(){

	  ofstream RegistrarG;
      RegistrarG.open("cambio1.dat",ios::out|ios::binary);
      
      
     ifstream ConsultarG;
     ConsultarG.open("ventas.dat",ios::in|ios::binary);
     
     if (RegistrarG.fail()||ConsultarG.fail()){
     cout<<"No se pudo abrir el archivo"<<endl;
     getch();                  
     }
     
     else{
     	
     int bit, reg, i;
     char nums[20];
     
     cout<<endl<<"Que venta deseas modificar?:"<<endl;
     cout<<"Codigo: "<<endl;
     cin>>nums;
     
     
     ConsultarG.seekg(0,ios::end);
     bit=ConsultarG.tellg()/sizeof(Ventas);
     ConsultarG.seekg(0);  
     
       for(i=0;i<bit;i++)
              {
              ConsultarG.read((char *)&venta,sizeof(Ventas));
                   if(strcmp(venta.codigo,nums)==0){
                   	
                   	cout<<endl<<"Codigo: "<<endl;
	                fflush(stdin); gets(venta.codigo);
	                cout<<endl<<"Nombre del dulce a vender: "<<endl;
	                fflush(stdin); gets(venta.nombre);
                   	cout<<endl<<"Cantidad de dulces vendidos: "<<endl;
                 	cin>>venta.cant;
                 	cout<<endl<<"Costo de la venta: "<<endl;
                 	cin>>venta.costo;  
					cout<<endl<<"Forma de Pago: "<<endl;
	                fflush(stdin); gets(venta.formaPagoP);                 
                     }
                     
                     RegistrarG.write((char *)&venta,sizeof(Ventas));    
              }
     ConsultarG.close();
     RegistrarG.close();
     remove("ventas.dat");
     rename("cambio1.dat","ventas.dat");
     
     getch();   
     
     }	
}

void Ventas::MostrarG(Milista3 &lista3)
{
	
	ifstream Consultar;
     Consultar.open("ventas.dat",ios::in|ios::binary);
     
     if (Consultar.fail())
     {
     cout<<" No hay ventas registradas "<<endl;
     getch();                  
     }
     
     else{
     	
     int bit, i;
    	Milista3 q;	
		  
     
     Consultar.seekg(0,ios::end);
     bit=Consultar.tellg()/sizeof(Ventas);
     Consultar.seekg(0);  
     
       for(i=0;i<bit;i++)
              {
              Consultar.read((char *)&venta,sizeof(Ventas));
               q=new(class Ventas);
               strcpy(q->codigo,venta.codigo);
               strcpy(q->nombre,venta.nombre);
               strcpy(q->formaPagoP,venta.formaPagoP);
               q->cant=venta.cant;
			   q->costo=venta.costo;
			
			cout<<endl<<"Codigo: "<<q->codigo<<endl;
              cout<<"Nombre del dulce a vender: "<<q->nombre<<endl;
              cout<<"Cantidad de dulces vendidos: "<<q->cant<<endl;
              cout<<"Costo de la venta: "<<q->costo<<endl;
              cout<<"Forma de Pago: "<<q->formaPagoP<<endl;
			
				q->sgte=lista3;
				lista3=q;
			  
			  }
     
	 
	 Consultar.close();
     getch();
       
     }
	
}
