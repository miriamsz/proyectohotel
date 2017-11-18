#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

int ci = 0; //contador de clientes
int ri = 0;  //contador de reservas
int hi = 0; //contador de habitaciones
int ei = 0; //contador de empleados


struct Habitaciones{
		int numhabitacion;
		float precio;
		int numdepersonas;
		int desayuno;
		int camas;
		bool ocupada;
		bool ducha;
		bool cable; 
		bool ac;
		bool wifi;
		bool cajaF;
}habitaciones[16];

struct Clientes {
	bool sexo;
	string id;
	string nombre;
	string edad;
	string fnacimiento;
	string tel;
	 string procedencia;
}cliente[100]; 

struct Empleados{
	string nombre;
	string identidad;
	string tel;
	string direccion;
	string cargo;
	bool sexo;
	
}empleado[3];

struct Reserva{
	Clientes c;
	Habitaciones h;
	Empleados e;
	string codReserva;
	int numdehabitaciones;
	string fdeEntrada;
	string fdeSalida;
	int	numdedias;
	float total;
	//fecha de entrada, salida, total a pagar
	
}reserva[100];

	void addCliente(){
		int s;
		char id[15];
		char nombre[30] ;
		char fdenacimiento[10];
		char edad[3];
		char telef[15];
		char procedencia[20];
			
	FILE* fichcliente;
	fichcliente =fopen("clientes.txt","wt");
	
	cout<<"------------------------------------------------------------\n";
	cout<<"               Registro de Clientes.\n";
	cout<<"------------------------------------------------------------\n";
	cout<<"     Introduzca los datos que se le piden.\n";
	cout << "Ingrese el numero de identidad:  "<<endl;
	gets(id);
	cliente[ci].id=id;
	fputs(id,fichcliente);
	fputs("\n",fichcliente);
	cout << "Ingrese el nombre del cliente: "<<endl;
	gets(nombre);
	cliente[ci].nombre=nombre;
	fputs(nombre,fichcliente);
	fputs("\n",fichcliente);
	cout << "Ingrese la fecha de nacimiento del cliente: "<<endl;
	gets(fdenacimiento);
	cliente[ci].fnacimiento=fdenacimiento;
	fputs(fdenacimiento,fichcliente);
	fputs("\n",fichcliente);
	cout << "Ingrese la edad del cliente: "<<endl;
    gets(edad);
	cliente[ci].edad=edad;
	fputs(edad,fichcliente);
	fputs("\n",fichcliente);
	cout << "Ingrese el numero de telefono: "<<endl;
	gets(telef);
	cliente[ci].tel=telef;
	fputs(telef,fichcliente);
	fputs("\n",fichcliente);
	cout << "Ingrese el lugar de procedencia del cliente: "<<endl;
	gets(procedencia);
	cliente[ci].procedencia=procedencia;
	fputs(procedencia,fichcliente);
	fputs("\n",fichcliente);
	
	cout << "Ingrese el sexo de la persona: \n";
	cout << "1. Masculino"<<endl;
	cout << "2. Femenino"<<endl;
	cin >> s;
	switch (s){
		case 1: {cliente[ci].sexo= true;
			fputs("1",fichcliente);
			fputs("\n",fichcliente);	
		 break;
		 }
		case 2: {cliente[ci].sexo =false;
			fputs("0",fichcliente);
			fputs("\n",fichcliente);
		 break;
	 	}
		default: {cout<<"OPCION NO VALIDA. \n";
		break;
		}
	}
	//system("CLS");
	ci=ci+1;
	fclose(fichcliente);
}

void ficherodecargar(){

char linea[80];
int contalineas=0;
    
    FILE* fichcliente;
	 fichcliente = fopen("Clientes.txt", "rt");
	if(fichcliente == NULL)	
	{
		printf("No existe fichero! n");
		exit(1);
	}
	
		while(!feof(fichcliente)){
			//fgets(linea,80,fichcliente);
			contalineas++;	
		}
		ci=contalineas/7;
		for(int i=0; i<ci;i++){
			fgets(linea,80,fichcliente);
			cliente[i].id=linea;
			fgets(linea,80,fichcliente);
			cliente[i].nombre=linea;
			fgets(linea,80,fichcliente);
			cliente[i].fnacimiento=linea;
			fgets(linea,80,fichcliente);
			cliente[i].edad=linea;
			fgets(linea,80,fichcliente);
			cliente[i].tel=linea;
			fgets(linea,80,fichcliente);
			cliente[i].procedencia=linea;
			fgets(linea,80,fichcliente);
			cliente[i].sexo=linea;
			fclose(fichcliente);
		}
}




void showCliente(){
	string sex;
	 if(cliente[ci].sexo==true)
	 	sex="Masculino";
	 else
	 	sex="Femenino";
	 	
	for(int x=0;x<1;x++){
		
		cout<<"-------------------------------------------------------\n";
	cout<<"           Informacion del Cliente \n";
	cout<<"-------------------------------------------------------\n";
	cout<<"\tIDENTIDAD \tNOMBRE \tSEXO \tF.NACIMIENTO \tEDAD \tN.TELEFONO \tPROCEDENCIA \n";
	for(int c=0;c<ci;c++){
		cout<<cliente[c].id<<"\t"<<cliente[c].nombre<<"\t"<<sex<<"\t"<<cliente[c].fnacimiento<<"\t"<<cliente[c].edad<<"\t"<<cliente[c].tel<<"\t"<<cliente[c].procedencia<<"\n";
		cout<<endl;
	}
	cout<<"-------------------------------------------------------\n";
	}

}
	
 void buscarCliente(){
 	string id;
 	bool encontrado=false;
 	cout<<"Ingrese el numero de identidad: \n";
 	cin>>id;
 	for(int bc=0;bc<ci;bc++){
 	
 	if(id == cliente[bc].id){
 		encontrado=true;
 	
 	cout<<"Nombre: "<<cliente[bc].nombre<<"\n Telefono: "<<cliente[bc].tel<<"\n Sexo: "<<cliente[bc].sexo;
	}
}
	if(encontrado==false){
		cout<<"El cliente con no ha sido registrado \n";
	}

 }

 int buscarCliente(string id){
 	bool encontrado=false;
 	for(int bc=0;bc<ci;bc++){
 		if((id == cliente[bc].id)){
 			encontrado=true;
 			return bc;
 		}
 	}
	if(encontrado==false){
		return -1;
		}

	}
	
void modificarCliente(){
	string idC;	                     
	int posc; 
	int op;
	int respuesta;
	cout<<"------------------------------------------------------ \n";
	cout<<"           Modificacion de datos del Cliente. \n";
	cout<<"------------------------------------------------------ \n";
	cout<<"Ingrese la identidad del cliente que desea modificar";
	cin>>idC;
	posc=buscarCliente(idC);
	if(posc<0)
		cout<<"Cliente no existe";
	else
		cout<<cliente[posc].nombre;
		cout<<cliente[posc].procedencia;
	do{
		cout<< "Elija  el dato que desea modificar: \n";
		cout<<"1. Identidad \n";
		cout<<"2. Nombre \n";
		cout<<"3. Direccion \n";
		cin>> op;
		switch(op){
			case 1: {cout<<"Ingrese la  Identidad Corregida:";
			cin>>cliente[posc].id;
			break;
			}
			case 2:{cout<<"Ingrese la correccion del nombre: ";
			cin>>cliente[posc].nombre;
			break;
			}
			case 3:{cout<<"Ingrese el lugar de procedencia corregido: ";
			cin>>cliente[posc].procedencia;
				break;
			}
			default : {cout<<"Opcion no valida.";
			break;
			}
		}
			cout<<"------------------------ \n";
			cout<<"-  Datos Modificados \n-";
			cout<<"------------------------ \n";
			cout<<cliente[posc].id;
			cout<<cliente[posc].nombre;
			cout<<cliente[posc].procedencia;
	
		cout<<"Desea volver a Modificar un dato? \n";
		cout<<"1.SI \n";
		cout<<"0.NO \n";
		cin>>respuesta;
	
	}	while(respuesta = 1);
}
	
	 
void addHabitaciones(){
	
	int aireC; // para el switch del aire acondicionado
	int tvc;//para el switch de television por cable
	int wf; //para el switch de wifi
	int du; // para el switch de ducha
	int cf; //para el switch de caja fuerte
	int p;
	
	FILE* fichhabitacion;
	fichhabitacion = fopen("habitaciones.txt","wt");	                   
		cout<<"             Registro de Habitaciones \n";
		cout<<"                 Hotel Caxa Real. \n";
		cout<<"------------------------------------------------------ \n";
		cout<<"Ingrese los datos que se le piden a continuacion: \n";
		cout<<"Ingrese el numero de la habitacion:";
		cin>>habitaciones[hi].numhabitacion;
		habitaciones[hi].ocupada=false;
		cout<<"Ingrese el número de personas:";
		cin>>habitaciones[hi].numdepersonas;
	
		//arreglar esto
		if(habitaciones[hi].numdepersonas == 1){
			habitaciones[hi].precio =850;
		}
		else if(habitaciones[hi].numdepersonas == 2){
			habitaciones[hi].precio = 1295;
		}
		else if(habitaciones[hi].numdepersonas == 3){
			habitaciones[hi].precio = 1595;
		}
		else if(habitaciones[hi].numdepersonas ==4){
			habitaciones[hi].precio = 1677.9;
		}
		else{
			cout<<"\n ERROR no se aceptan mas de 4 adultos en una Habitacion!";
			cout<<"\n Vuelva a Intentarlo.";
		}
	
			cout<<"           Agregar Descripcion de la Habitacion \n";
			cout<<"------------------------------------------------------ \n";
			cout<<"Ingrese la cantidad de desayunos  que incluye: \n";
			cin>>habitaciones[hi].desayuno;
			cout<<"Ingrese la cantidad de camas que incluye: \n";
			habitaciones[hi].camas;
			cout<<"Ingrese si la habitacion cuenta con Aire Acondicionado en la ducha ";
			cout<<"1. SI \n";
			cout<<"2. NO \n";
			cin>>aireC;
				switch(aireC){
					case 1: {habitaciones[hi].ac = true; break;}
						fputs("1",fichhabitacion);
						fputs("\n",fichhabitacion);
					case 2: {habitaciones[hi].ac = false;break;}
						fputs("0",fichhabitacion);
						fputs("\n",fichhabitacion);
					default:{ cout<<"OPCION NO VALIDA!";break;}
		}
			cout<<"Ingrese si la habitacion cuenta con Agua Caliente: \n";
			cout<<"1. SI \n";
			cout<<"2. NO \n";
			cin>>du;
				switch(du){
					case 1: {habitaciones[hi].ducha = true;break;}
							fputs("1",fichhabitacion);
							fputs("\n",fichhabitacion);
					case 2: {habitaciones[hi].ducha = false;break;}
							fputs("0",fichhabitacion);
							fputs("\n",fichhabitacion);
					default:{ cout<<"OPCION NO VALIDA!";break;}
			}
			cout<<"Ingrese si la habitacion cuenta con Television por cable: \n";
			cout<<"1. SI \n";
			cout<<"2. NO \n";
			cin>>tvc;
				switch(tvc){
					case 1: {habitaciones[hi].cable = true;break;}
						fputs("1",fichhabitacion);
						fputs("\n",fichhabitacion);
					case 2: {habitaciones[hi].cable = false;break;}
						fputs("0",fichhabitacion);
						fputs("\n",fichhabitacion);
					default:{ cout<<"OPCION NO VALIDA!";break;}
			}
			cout<<"	Ingrese si la habitacion cuenta con wifi: \n";
			cin>>wf;
		 		switch(wf){
				 case 1:{habitaciones[hi].wifi = true;break;}
					 fputs("1",fichhabitacion);
					 fputs("\n",fichhabitacion);
				 case 2:{habitaciones[hi].wifi = false;break;}
					 fputs("1",fichhabitacion);
			   		 fputs("\n",fichhabitacion);
				 default:{ cout<<"OPCION NO VALIDA!";break;}
			}
				cout<<"Ingrese si la habitacion cuenta con Caja fuerte: \n";
			cout<<"1. SI \n";
			cout<<"2. NO \n";
			cin>>cf;
				switch(cf){
					case 1: {habitaciones[hi].cajaF = true;break;}
						fputs("1",fichhabitacion);
						fputs("\n",fichhabitacion);
					case 2: {habitaciones[hi].cajaF = false;break;}
						fputs("1",fichhabitacion);
						fputs("\n",fichhabitacion);
					default:{ cout<<"OPCION NO VALIDA!";break;}
			}
	hi=hi+1;
	fclose(fichhabitacion);
	}



void cargarficherodehabitacion(){
char lineaH[80];
int contalineasH=0;
    
    FILE* fichhabitacion;
	 fichhabitacion = fopen("habitaciones.txt", "rt");
	if(fichhabitacion == NULL)	
	{
		printf("No existe fichero! n");
		exit(1);
	}
	
		while(!feof(fichhabitacion)){
			//fgets(linea,80,fichcliente);
			contalineasH++;	
		}
		hi=contalineasH/10;
		for(int u=0; u<hi;u++){
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].numhabitacion=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].ocupada=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].numdepersonas=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].precio=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].desayuno=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].camas=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].ac=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].ducha=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].cable=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].wifi=lineaH;
			fgets(lineaH,80,fichhabitacion);
			habitaciones[u].cajaF=lineaH;
			fclose(fichhabitacion);
		}
}

void showHabitaciones(){

	string aireA;
	 if(habitaciones[hi].ac == true)
	 	aireA="si";
	 else
	 	aireA="no";
	 	
	 string Ducha;
	 if(habitaciones[hi].ducha == true)
	 	Ducha="si";
	 else
	 	Ducha="no";
	 	
	 string WiFi;
	 if(habitaciones[hi].wifi == true)
	 	WiFi="si";
	 else
	 	WiFi="no";	
	 	
	string CajaF;
	 if(habitaciones[hi].cajaF == true)
	 	CajaF="si";
	 else
	 	CajaF="no";
	
	string CAble;
	 if(habitaciones[hi].cable == true)
	 	CAble="si";
	 else
	 	CAble="no";
	
	 	
	for(int x=0;x<1;x++){
		
	cout<<"---------------------------------------------------------------\n";
	cout<<"-           Informacion de las  Habitaciones.                 - \n";
	cout<<"---------------------------------------------------------------\n";
	cout<<"Numero de personas que se pueden quedar:"<<habitaciones[hi].numdepersonas;
	cout<<"Numero de Camas: "<<habitaciones[hi].camas;
	cout<<"La Habitacion, "<<aireA<<" tiene Aire Acondicionado disponible. \n";
	cout<<"La Habitacion "<<Ducha<<"tiene disponible agua caliente en la ducha. \n";
	cout<<"La Habitacion "<<WiFi<<"tiene WiFi disponible. La contraseña es: comayagua1537. \n";
	cout<<"La Habitacion "<<CajaF<<"tiene caja fuerte disponible. Las instrucciones de uso estan en la habitacion.  \n";
	cout<<"La Habitacion "<<CAble<<" tiene cable disponible. \n";

	}
	cout<<"---------------------------------------------------------------\n";
	}

  void buscarHabitacion(){
 	int idH;
 	bool encontrado=false;
 	cout<<"Ingrese el numero de Habitacion: \n";
 	cin>>idH;
 	for(int bh=0;bh<hi;bh++){
 	
 	if(idH == habitaciones[hi].numhabitacion){
 		encontrado=true;
 	cout<<"-------------------------------------------------------------------------------------- \n";
 	cout<<"-       Informacion sobre la Habitacion numero"<<habitaciones[hi].numhabitacion<<"         - \n"; 
 	cout<<"-------------------------------------------------------------------------------------- \n";
	cout<<"Numero de Personas que se pueden quedar: "<<habitaciones[hi].numdepersonas;
	cout<<"Numero de Camas: "<<habitaciones[hi].camas;
	cout<<"La Habitacion, "<<habitaciones[hi].ac<<" tiene Aire Acondicionado disponible. \n";
	cout<<"La Habitacion "<<habitaciones[hi].ducha<<" tiene disponible agua caliente en la ducha. \n";
	cout<<"La Habitacion "<<habitaciones[hi].wifi<<" tiene WiFi disponible. La contraseña es: comayagua1537. \n";
	cout<<"La Habitacion "<<habitaciones[hi].cajaF<<" tiene caja fuerte disponible. Las instrucciones de uso estan en la habitacion.  \n";
	cout<<"La Habitacion "<<habitaciones[hi].cable<<" tiene cable disponible. \n";
	cout<<"-------------------------------------------------------------------------------------- \n";
	
	
	}
}
	if(encontrado==false){
		cout<<"El habitacion no existe\n";
	}

 }

 int buscarHabitacion(int idH){
 	bool encontrado=false;
 	for(int bh=0;bh<hi;bh++){
 		if(idH == habitaciones[hi].numhabitacion){
 			encontrado=true;
 			return bh;
 		}
 	}
	if(encontrado==false){
		return -1;
		}

	}
void modificarHabitacion(){
	int idHab;
	int posHab; 
	int op;
	int respuestaH;
	cout<<"Ingrese el numero de la Habitacion que desea modificar: ";
	cin>>idHab;
	posHab=buscarHabitacion(idHab);
	if(posHab<0)
		cout<<"Habitacion no existe";
	else
		cout<<habitaciones[posHab].numhabitacion;
		cout<<habitaciones[posHab].numdepersonas;
	
	do{
		cout<< "Elija  el dato que desea modificar: \n";
		cout<<"1. Aire acondicionado. \n";
		cout<<"2. Agua Client.e \n";
		cout<<"3. Wifi. \n";
		cout<<"4. Caja Fuerte. \n";
		cout<<"5. Cable. \n";
		cout<<"6. Numero de Camas. \n";
		cout<<"7. Numero de Personas. \n";
		cout<<"8. Numero de Desayunos. \n";
		cin>> op;
		switch(op){
			case 1: {cout<<"Ingrese si la habitacion tiene Aire Acondcionado:";
						cin>>habitaciones[posHab].ac;
			break;
			}
			case 2:{cout<<"Ingrese si la habitacion tiene Agua Aaliente: ";
					cin>>habitaciones[posHab].ducha;
			break;
			}
			case 3:{cout<<"Ingrese si la habitacion tiene Wifi: ";
					cin>>habitaciones[posHab].wifi;
				break;
			}
			case 4:{cout<<"Ingrese si la habitacion Caja Fuerte: ";
					cin>>habitaciones[posHab].cajaF;
			break;
			}
			case 5:{cout<<"Ingrese si la habitacion tiene Wifi: ";
					cin>>habitaciones[posHab].cable;
				break;
			}
			case 6:{cout<<"Ingrese el numero corregido de camas que tiene la habitacion: \n";
					cin>>habitaciones[posHab].camas;
				break;
			}
			case 7:{cout<<"Ingrese el numero de personas corregido: \n";
					cin>>habitaciones[posHab].numdepersonas;
				break;
			}
			case 8:{cout<<"Ingrese el numero de desayunos corregido: \n";
					cin>>habitaciones[posHab].desayuno;
				break;
			}
			default : {cout<<"Opcion no valida.";
			break;
			}
		}
			cout<<"------------------------ \n";
			cout<<"-  Datos Modificados \n-";
			cout<<"------------------------ \n";
			cout<<habitaciones[posHab].ac;
			cout<<habitaciones[posHab].cable;
	 		cout<<habitaciones[posHab].ducha;
	 		cout<<habitaciones[posHab].wifi;
	 		cout<<habitaciones[posHab].cajaF;
	 		cout<<habitaciones[posHab].camas;
	 		cout<<habitaciones[posHab].numdepersonas;
	 		cout<<habitaciones[posHab].desayuno;
	
		cout<<"Desea volver a Modificar un dato? \n";
		cout<<"1.SI \n";
		cout<<"0.NO \n";
		cin>>respuestaH;
	
	}	while(respuestaH = 1);

}



void addEmpleado(){
	int t;
	char identidadE[15];
	char nombreE[30];
	char telE[15];
	char direccionE[35];
	char cargo[15];
	bool sexo;
	
	FILE* fichEmpleado;
	fichEmpleado = fopen("empleados.txt","wt");
	
	cout<<"Ingrese el numero de Identidad: \n";
	gets(identidadE);
	empleado[ei].identidad=identidadE;
	fputs(identidadE,fichEmpleado);
	fputs("\n",fichEmpleado);
	cout<<" Nombre del Empleado: \n";
	gets(nombreE);
	empleado[ei].nombre=nombreE;
	fputs(nombreE,fichEmpleado);
	fputs("\n",fichEmpleado);
	cout<<" Numero de Telefono: \n";
	gets(telE);
	empleado[ei].tel=telE;
	fputs(telE,fichEmpleado);
	fputs("\n",fichEmpleado);;
	cout<<" Direccion del Empleado; \n";
	gets(direccionE);
	empleado[ei].direccion=direccionE;
	fputs(direccionE,fichEmpleado);
	fputs("\n",fichEmpleado);
	cout<<" Cargo: \n";
	gets(cargo);
	empleado[ei].cargo=cargo;
	fputs(cargo,fichEmpleado);
	fputs("\n",fichEmpleado);
	cout << "Ingrese el sexo de la persona: \n";
	cout << "1. Masculino"<<endl;
	cout << "2. Femenino"<<endl;
		cin >>t;
	switch (t){
	
	case 1: {empleado[ei].sexo = true;
			fputs("1",fichEmpleado);
			fputs("\n",fichEmpleado);	

		break;
	 }
	case 2: {empleado[ei].sexo = false;
			fputs("1",fichEmpleado);
			fputs("\n",fichcliente);	

	 	break;
	 }
	default: {cout<<"OPCION NO VALIDA. \n";break;}
}
ei=ei+1;
 	fclose(fichEmpleado);
}

void cargarficheroE(){

char lineaE[80];
int contalineasE=0;
    
    FILE* fichEmpleado;
	 fichEmpleado = fopen("empleados.txt", "rt");
	if(fichEmpleado == NULL)	
	{
		printf("No existe fichero! n");
		exit(1);
	}
	
		while(!feof(fichEmpleado)){
			//fgets(linea,80,fichcliente);
			contalineasE++;	
		}
		ei=contalineasE/6;
		for(int a=0; a<ei;a++){
			fgets(lineaE,80,fichEmpleado);
			empleado[a].identidad=lineaE;
			fgets(lineaE,80,fichEmpleado);
			empleado[a].nombre=lineaE;
			fgets(lineaE,80,fichEmpleado);
			empleado[a].tel=lineaE;
			fgets(lineaE,80,fichEmpleado);
			empleado[a].direccion=lineaE;
			fgets(lineaE,80,fichEmpleado);
			empleado[a].cargo=lineaE;
			fgets(lineaE,80,fichEmpleado);
			empleado[a].sexo=lineaE;
			fclose(fichEmpleado);
		}
}




void showEmpleado(){	
		for(int s=0;s<1;s++){
	cout<<"---------------------------------------------------------------------------\n";
	cout<<"                     Informacion del los Empleados \n";
	cout<<"---------------------------------------------------------------------------\n";
	cout<<"\t Identidad   Nombre   Sexo   Telefono   Direccion   Cargo \n";
	for(int e=0;e<ei;e++){
		cout<<"\t"<<empleado[e].identidad<<"  "<<empleado[e].nombre<<"  "<<empleado[e].sexo<<"  "<<empleado[e].tel<<"  "<<empleado[e].direccion<<"  "<<empleado[e].cargo<<"\n";
		cout<<endl;
	}
	cout<<"---------------------------------------------------------------------------\n";
	}

}




void buscarEmpleado(){
	string idE;
 	bool found =false;
 	cout<<"Ingrese el numero de identidad del Empleado: \n";
 	cin>>idE;
 	for(int be=0;be<ei;be++){
 	
 	if(idE == empleado[be].identidad){
 		found=true;
 	cout<<"Nombre: "<<empleado[be].nombre<<"\n";
 	cout<<"Cargo: "<<empleado[be].cargo<<"\n";
 	cout<<"Telefono: "<<empleado[be].tel<<"\n";
 	cout<<"Sexo: "<<empleado[be].sexo<<"\n";
 	cout<<"Direccion: "<<empleado[be].direccion<<"\n";
}
}
	if(found==false){
		cout<<"El empleado no existe. \n";
	}
system("CLS");
}

int buscarEmpleado(string idE){
 	bool found=false;
 	for(int be=0;be<ei;be++){
 		if(idE == empleado[ei].identidad){
 			found=true;
 			return be;
 		}
 	}
	if(found==false){
		return -1;
	}
}

void modificarEmpleado(){
	string idE;
	int posE; 
	int op;
	int respuestaE;
	cout<<"------------------------------------------------------ \n";
	cout<<"   \n   Modificacion de datos de los Empleados.";
	cout<<"------------------------------------------------------ \n";
	cout<<"Ingrese la identidad del Empleado que desea modificar";
	cin>>idE;
	posE=buscarCliente(idE);
	if(posE<0)
		cout<<"Empleado no existe";
	else
		cout<<empleado[posE].nombre;
		cout<<empleado[posE].cargo;
	do{
		cout<< "Elija  el dato que desea modificar: \n";
		cout<<"1. Identidad \n";
		cout<<"2. Nombre \n";
		cout<<"3. Direccion \n";
		cout<<"2. Cargo \n";
		cout<<"3. Sexo \n";
		cin>> op;
		switch(op){
			case 1: {cout<<"Ingrese la Identidad Corregida del Empleado:";
			cin>>empleado[posE].identidad;
			break;
			}
			case 2:{cout<<"Ingrese la correccion del nombre del Empleado: ";
			cin>>empleado[posE].nombre;
			break;
			}
			case 3:{cout<<"Ingrese la direccion corregida del empleado: ";
			cin>>empleado[posE].direccion;
				break;
			}
			case 4:{cout<<"Ingrese la correccion del cargo del Empleado: ";
			cin>>empleado[posE].cargo;
			break;
			}
			case 5:{cout<<"Ingrese el sexo corregido del empleado: ";
			cin>>empleado[posE].sexo;
				break;
			}
			default : {cout<<"Opcion no valida.";
			break;
			}
		}
			cout<<"------------------------ \n";
			cout<<"-  Datos Modificados \n-";
			cout<<"------------------------ \n";
			cout<<empleado[posE].identidad;
			cout<<empleado[posE].nombre;
			cout<<empleado[posE].direccion;
			cout<<empleado[posE].cargo;
			cout<<empleado[posE].sexo;
	
		cout<<"Desea volver a Modificar un dato? \n";
		cout<<"1.SI \n";
		cout<<"0.NO \n";
		cin>>respuestaE;
	
	}	while(respuestaE = 1);
}
	
void addReserva(){
	string idR;
	string idEmpleado;
	int idHabitacion;
	int posR;
	int posHa;
	int posEmp;
	int o;
	int x;
	
	cout<<"----------------------------------------------------------";
	cout<<"        \n          Ingreso de Reservas";
	cout<<"      \n              Hotel Caxa Real";
	cout<<"----------------------------------------------------------";
do{
	do{
	cout<<"Introduzca el Numero de identidad del Cliente: \n";
	cin>>idR;
	posR=buscarCliente(idR);
	if (posR<0){
		cout<<"El cliente no ha sido registrado";
		cout<<"Inténtelo de nuevo";
	}
	}while(posR <0);
	
	//datos del cliente
	reserva[ri].c.id=idR;
	reserva[ri].c.nombre=cliente[ci].nombre;
	reserva[ri].c.edad=cliente[ci].edad;
	reserva[ri].c.procedencia=cliente[ci].procedencia;
	reserva[ri].c.sexo=cliente[ci].sexo;
	reserva[ri].c.tel=cliente[ci].tel;
	//datos de la habitacion
	do{
	cout<<"Introduzca el Numero de la Habitacion: \n";
	cin>>idHabitacion;
	posHa=buscarHabitacion(idHabitacion);
	if (posHa<0){
		cout<<"La habitacion no ha sido registrada.";
		cout<<"Inténtelo de nuevo";
	}
	}while(posHa<0);
	
	reserva[ri].h.numhabitacion=idHabitacion;
	reserva[ri].h.numdepersonas=habitaciones[hi].numdepersonas;
	reserva[ri].h.precio=habitaciones[hi].precio;
	reserva[ri].h.desayuno=habitaciones[hi].desayuno;
	reserva[ri].h.camas=habitaciones[hi].camas;
	reserva[ri].h.ac=habitaciones[hi].ac;
	reserva[ri].h.cable=habitaciones[hi].cable;
	reserva[ri].h.cajaF=habitaciones[hi].cajaF;
	reserva[ri].h.wifi=habitaciones[hi].wifi;
	reserva[ri].h.ducha=habitaciones[hi].ducha;	
	//datos del empleado
		do{
	cout<<"Introduzca el Numero de Identidad del Empleado: \n";
	cin>>idEmpleado;
	posEmp=buscarEmpleado(idEmpleado);
	if (posEmp<0){
		cout<<"La habitacion no ha sido registrada.";
		cout<<"Inténtelo de nuevo";
	}
	}while(posEmp<0);
		
	reserva[ri].e.identidad=idEmpleado;
	reserva[ri].e.nombre=empleado[ei].nombre;
	reserva[ri].e.cargo=empleado[ei].cargo;
	reserva[ri].e.direccion=empleado[ei].direccion;
	reserva[ri].e.sexo=empleado[ei].sexo;
	reserva[ri].e.tel=empleado[ei].tel; 

	cout<<"___________________________________________________________________ \n";
	cout<<"			    	INFORMACION DE LA RESERVACION.\n"	;
	cout<<"___________________________________________________________________ \n";
	cout<<"Numero de Reserva:"; cout<<reserva[ri].codReserva;
	cout<<"Nombre: "; cout<<reserva[ri].c.nombre<<"\n";
	cout<<"Idetidad: "; cout<<reserva[ri].c.id<<"\n";
	cout<<"Edad: "; cout<<reserva[ri].c.edad<<"\n";
	cout<<"Lugar de Procedencia "; cout<<reserva[ri].c.procedencia<<"\n";
	cout<<"Sexo: "; cout<<reserva[ri].c.tel<<"\n";
	cout<<"Numero de Habitacion: "; cout<<reserva[ri].h.numhabitacion<<"\n";
	cout<<"Numero de Personas:"; cout<<reserva[ri].h.numdepersonas<<"\n";
	cout<<"Precio de la Habitacion: "; cout<<reserva[ri].h.precio<<"\n";
	cout<<"Numero de Desayunos: "; cout<<reserva[ri].h.desayuno<<"\n";
	cout<<"Numero de Camas: "; cout<<reserva[ri].h.camas<<"\n";
	cout<<"La habitacion"<<reserva[ri].h.ac<<" tiene Aire Acondicionado. \n";
	cout<<"La habitacion"<<reserva[ri].h.cable<<" tiene Television por Cable. \n";
	cout<<"La habitacion"<<reserva[ri].h.cajaF<<" tiene Caja Fuerte. \n";
	cout<<"La habitacion"<<reserva[ri].h.wifi<<" tiene WiFi. \n";
	cout<<"La habitacion"<<reserva[ri].h.wifi<<" tiene Agua Caliente en la Ducha. \n";
	cout<<"Nombre del empleado que realizo la reserva:"; cout<<reserva[ri].e.nombre<<"\n";
	cout<<"ID del Empleado:"; cout<<reserva[ri].e.identidad<<"\n";
	cout<<"Cargo del Empleado:"<<reserva[ri].e.cargo<<"\n";
	cout<<"Fecha de Entrada: "; cin>>reserva[ri].fdeEntrada;
	cout<<"Fecha de Salida: "; cin>>reserva[ri].fdeSalida;
	cout<<"Numero de Dias: "; cin>>reserva[ri].numdedias;
	
	

	cout<<"Desea ingresar otra reservacion? 1. SI 0.NO \n";
	cin>>o;
}while(x=1);
	ri=ri+1;                     
 }


void buscarReserva(){
	string ideR;
	int x=0;
	while(x<0){

	cout<<"Introduzca el numero de identidad de la perosna que hizo la reserva:\n";
	cin>>ideR;
	for(int br=0;br<ri;br++){

	if((cliente[ci].id==ideR)){
		cout<<"Nombre:\n"<<reserva[ri].c.nombre;
		cout<<"Numero de Telefono:\n"<<reserva[ri].c.tel;
		cout<<"Habitaciones reservadas:\n"<<reserva[ri].h.numhabitacion;
		cout<<"Numero de personas que se quedaran: \n"<<reserva[ri].h.numdepersonas;
		}
}
	cout<<"Desea, volver a buscar? 0.SI 1.NO\n";
	cin>>x;
}
cout<<"Fin de la Busqueda. \n";
}
 
  
void showReserva(){
for(int s=0;s<ri;s++){
	
	cout<<"INFORMACION DEL CLIENTE \n";
	cout<<"------------------------------------------------------------------------------------------------\n";
	cout<<" \t NOMBRE    TELEFONO    # DE HAB RESERVADAS    #DE PERSONAS QUE SE HOSPEDARAN \n";
	for(int r=0;r<=ri;r++){
		cout<<reserva[ri].c.nombre<<"\t"<<reserva[ri].c.tel<<"\t"<<reserva[ri].h.numhabitacion<<"\t"<<reserva[ri].h.numdepersonas<<endl;
		cout<<endl;
	}
	cout<<"-----------------------------------------------------------------------------------------------\n";
	}
}



int main (){
	int o;	
	int a;
	int aa;
	int aaa;
	int t=0;
	
while (t<1){	
	cout<<"___________________________________________________________________ \n";
	cout<<"                       HOTEL CAXA REAL \n";
	cout<<"                 SISTEMA DE REGISTRO DE CLIENTES \n";
	cout<<"                   BIENVENIDO AL MENU PRINCIPAL \n";
	cout<<"___________________________________________________________________ \n";
	cout<<"             1. MENU DE CLIENTES \n";
	cout<<"             2. HABITACIONES  \n";
	cout<<"             3. EMPLEADOS \n";
	cout<<"             4. RESERVAS \n";
	cout<<"___________________________________________________________________ \n";
	cout<<" INTRODUZCA EL NUMERO DEL MODULO A EJECUTAR.    \n";
	cin>>o;

	switch (o){ 
		case 1: { 	cout<<"___________________________________________________________________ \n";
					cout<< "           	        BIENVENIDO AL \n";
					cout<<"                    MENU DE CLIENTES \n";
					cout<<"___________________________________________________________________ \n";
					cout<<"             1. AGREGAR CLIENTE \n";
					cout<<"             2. BUSCAR CLIENTE \n";
					cout<<"             3. MOSTRAR CLIENTE  \n";
					cout<<"             4. MODIFICAR CLIENTE \n";
					cout<<"             5. VOLVER AL MENU PRINCIPAL \n";
					cout<<"___________________________________________________________________ \n";
					cout<<" Ingrese la  opcion que desea realizar: ";
					cin>>a;
				
					switch(a){
						case 1: {addCliente();break;}
						case 2: {buscarCliente();break;}
						case 3: {showCliente();break;}
						case 4: {modificarCliente();break;}
						case 5: {							break;}
						default : cout<<"Opcion no valida! \n";
						
					}
					
			break;
		}
		case 2: { 
					cout<<"___________________________________________________________________ \n";
					cout<< "           	        BIENVENIDO AL \n";
					cout<<"                   MENU DE HABITACIONES \n";
					cout<<"___________________________________________________________________ \n";
					cout<<"             1. AGREGAR HABITACION \n";
					cout<<"             2. BUSCAR HABITACION \n";
					cout<<"             3. MOSTRAR HABITACION  \n";
					cout<<"             4. MODIFICAR CHABITACION \n";
					cout<<"             5. VOLVER AL MENU PRINCIPAL \n";
					cout<<"___________________________________________________________________ \n";
					cout<<" Ingrese la  opcion que desea realizar: ";
					cin>>a;
					switch(a){
						case 1: {addHabitaciones();break;}
						case 2: {buscarHabitacion();break;}
						case 3: {showHabitaciones();break;}
						case 4: {modificarHabitacion();break;}
						case 5: {							break;}
						default : cout<<"Opcion no valida! \n";
						
					}
					
			break;
		}
		
			case 3:{
				
				
			cout<<"___________________________________________________________________ \n";
					cout<< "           	        BIENVENIDO AL \n";
					cout<<"                   MENU DE HABITACIONES \n";
					cout<<"___________________________________________________________________ \n";
					cout<<"             1. AGREGAR EMPLEADO \n";
					cout<<"             2. BUSCAR EMPLEADO \n";
					cout<<"             3. MOSTRAR EMPLEADO \n";
					cout<<"             4. MODIFICAR EMPLEADO \n";
					cout<<"             5. VOLVER AL MENU PRINCIPAL \n";
					cout<<"___________________________________________________________________ \n";
					cout<<" Ingrese la  opcion que desea realizar: ";
					cin>>a;
					switch(a){
						case 1: {addEmpleado();break;}
						case 2: {buscarEmpleado();break;}
						case 3: {showEmpleado();break;}
						case 4: {modificarEmpleado();break;}
						case 5: {					break;}
						default : {cout<<"Opcion no valida! \n";}
						
					}
				
			break;
		}
		
			case 4:{
					cout<<"___________________________________________________________________ \n";
					cout<< "           	        BIENVENIDO AL \n";
					cout<<"                  MENU DE RESERVACIONES \n";
					cout<<"___________________________________________________________________ \n";
					cout<<"             1. AGREGAR RESERVACIONES \n";
					cout<<"             2. BUSCAR RESERVACIONES \n";
					cout<<"             3. MOSTRAR RESERVACION \n";
					cout<<"             4. VOLVER AL MENU PRINCIPAL \n";
					cout<<"___________________________________________________________________ \n";
					cout<<" Ingrese la  opcion que desea realizar: ";
					cin>>a;
					switch(a){
						case 1: {addReserva();break;}
						case 2: {buscarReserva();break;}
						case 3: {showReserva();break;}
						case 4: {					break;}
						default : {cout<<"Opcion no valida! \n";}
						
					}
				
			break;
		}
	  
			default: {cout<<"EL NUMERO DE LA OPCIÓN QUE ESCOGIÓ NO EXISTE"<<endl;break;}

	}
cout<<"Desea Regresar al menu principal?  0.SI 1.NO";
cin>>t;	
}

cout<<"FIN DEL PROGRAMA \n";
getch();
}


    
