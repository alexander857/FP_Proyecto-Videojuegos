#include <iostream>
#include<stdio.h>
#include<cstdlib>//para cambiar el color
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

//funciones de la consola
void games();
//la loteria  ZAIR ALEXANDER ORTIZ FLORES 00355519
void instruccionesL();
void loteria(); //FUNCION PRINCIPAL
void menu(); //MENU DEL JUEGO
void modo(); //MODOS DE JUEGO FACIL, NORMAL, DIFICIL
void facil();
void normal();
void dificil();
char listasFND(); //MENU DE LISTAS DE ARCHIVOS DE CADA MODO DE JUEGO
//arreglos y matrices CRISTIAN RICARDO ROSALES MONICO 00362519
void instruccionesA();
void AMYBM(); //FUNCION PRINCIPAL
void menuA(); //MENU DEL JUEGO
void niveles(); //MODOS DE JUEGO FACIL, NORMAL, DIFICIL, EXTREMO
void facil1();
void normal2();
void dificil3();
void extremo();
bool verifica(int primero[4][3], int num); //VERIFICA QUE NO SE REPITA EL NUMERO EN LA MATRIZ
bool exsegundo(int segundo[4][4], int num2);  //VERIFICA QUE NO SE REPITA EL NUMERO EN LA MATRIZ
char listasFNDE(); //LISTA DE ARCHIVOS DE CADA MODO DE JUEGO
//quien quiere ser millonario CESAR OMAR GALAN MARROQUIN 00370819
void millonario(); //FUNCION PRINCIPAL
void menuM(); //MENU DEL JUEGO
void InstruccionesM();
void nivelesM(); //MENU DE PREMIOS QUE GANA EL USUARIO CADA QUE CONTESTA UNA PREGUNTA
void preguntas(); //LAS PREGUNTAS DEL JUEGO
void pregunta11(); 
void pregunta12();
void pregunta13();
void pregunta14();
void pregunta15();


int main(){
	system("color 02"); //cambia de color el fondo de la consola
	char play; 
	int i=5; //variable que ira disminuyendo si el usuario no elije una opcion existente
	
	games(); //mostramos al usuario el menu de los juegos
	cout<<endl;
	cout<<"Opcion: ";cin>>play;  //opcion para que el usuario elija sy juego
	system("cls"); //borra lo que hay en pantalla
	
	while(i>0){
		if(play=='1'){
			AMYBM(); //primer juego arreglos y matrices
		}
		else if(play=='2'){
			loteria(); //segundo juego la loteria
		}
		else if(play=='3'){
			millonario(); //tercer juego quien quiere ser millonario
		}
		else if(play=='4'){
			break;  //si el usuario decide salir, se cierra la consola
		}
		else{
			cout<<"Opcion no disponible"<<endl;
			i--;  //el usuario solo tiene 5 intentos de ingresar una opcion existente, al acabarse la consola se cierra
			system("pause");
			system("cls");
		}	
		
		games(); //se vuelve a mostrar el menu de juegos 
		cout<<endl;
		cout<<"Opcion: ";cin>>play;
		system("cls");
		
	}
	
	if(i==0){ //cuando el usuario haya ingresado muchas veces una opcion que no esta en el menu
		cout<<"Ha ingresado muchos datos que no existen en el menu. La consola se cerrara..."<<endl;	
	}

	
	return 0;
}

void games(){ //menu principal de la consola donde se muestran en pantalla los juegos disponibles
	cout<<"CONSOLA DE JUEGOS"<<endl; //by Acrices©
	cout<<"\n\n";
	cout<<"1- ARREGLOS, MATRICES Y UNA BUENA MEMORIA\n2- LA LOTERIA\n3- QUIEN QUIERE SER MILLONARIO\n4- Salir de la consola"<<endl;	
}

//FUNCIONES DE LA LOTERIA

void instruccionesL(){
	char opc;
	int i=1; //variable i para que este funcionando el while mientras el ususario elija una opcion existente
	
	while(i==1){
		
		cout<<"INDICACIONES: "<<endl;
		cout<<endl;
		cout<<"1-COMO SE JUEGA?\n2-OMITIR."<<endl;
		cout<<endl;
		cout<<"Opcion: ";cin>>opc;
		system("cls");
		if(opc=='1'){
			
			//se hace la lectura de un archivo de texto de las instrucciones del juego
			string line;
			ifstream miTXT ("instruccionesLoto.txt"); 
			if (miTXT.is_open()){	
			while (getline (miTXT,line)){	
				cout << line << '\n';
			}
			system("pause");
			system("cls");
			if(miTXT.eof()){	
				cout<<"Se ha terminado de leer. Fin del archivo";
				system("cls");
			}
				miTXT.close(); //se termina de leer el archivo
			}
			else cout << "No se puede abrir el archivo o no existe.";
				break;
			
		}	
		else if(opc=='2'){
			break; //si el ususario elije la opcion 2, se omiten las instrucciones
		}
		else{ //se seguira mostrando hasta que se elija una opcion existente
			cout<<"Seleccione una opcion existente!"<<endl;
			system("pause");
			system("cls");
		}

	}

}

void loteria(){ //funcion principal del juego la loteria
	system("color 20"); //funcion que cambia el color de fondo. Primer numero es para el fondo y el segundo para las letras
	char opc, op,opt;
	int i=5,K=1; //variable que disminuye cada vez que el ususario ingrese una opcion que no esta, es decir, tiene solo 5 oportunidades
	
	instruccionesL(); //se llama el menu donde el ususario elige si ver las instrucciones o no
	
	while(i>0){ //el menu se le mostrara al usuario y cada vez que ingrese una opcion que no esta, i va disminuir y si llega a 0 se saldra del juego
		menu(); //se le muestra el menu de jugar o salir del juego
		cout<<endl;
		cout<<"Opcion: ";cin>>opc;
		system("cls"); //funcion que limpia la pantalla
		
		if(opc=='1'){
			while(i>0){  //el menu de modos se mostrara igual durante 5 veces que el usuario ingresa una opcion que no esta, si llega a 0 se sale al menu princial
				modo(); //le mostramos los modos de juego al susario
				cout<<endl;
				cout<<"Seleccione el modo: ";cin>>op;
				system("cls");
				//se llaman a las funciones que tienen cada modo de juego segun elija el ususario
				if(op=='1'){
					facil(); 
				}
				else if(op=='2'){
					normal();
				}
				else if(op=='3'){
					dificil();
				}
				else if(op=='4'){  //se sale al menu principal
					break;
				}
				else{  //se muestra cada vez que el usuario ingrese una opcion que no esta en el menu
					cout<<"Ha ingresado una opcion que no esta. Seleccione una existente!"<<endl; 
					i--;
					system("pause");
					system("cls");
				}
				if(i==0){ //si ingresa una opcion que no esta 5 veces se saldra del juego
					cout<<"Ha ingresado repetidas veces una opcion inexistente. Saldra del juego!"<<endl;
					system("pause");
					system("cls");
				}
			}			
		}
		else if(opc=='2'){
			opt=listasFND();
			system("cls");
			while(K==1){
				if(opt=='1'){
					
					string line;
					ifstream miTXT ("loteria facil.txt"); //se lee un archivo de loteria facil
					if (miTXT.is_open()){	
					while (getline (miTXT,line)){	
						cout << line << '\n';
					}
					system("pause");
					system("cls");
					if(miTXT.eof()){	
						cout<<"Se ha terminado de leer. Fin del archivo";
						system("cls");
					}
						miTXT.close();
					}
					else cout << "No se puede abrir el archivo o no existe.";					
				}
				else if(opt=='2'){
					
					string line;
					ifstream miTXT ("Loteria normal.txt"); //se lee un archivo de loteria normal
					if (miTXT.is_open()){	
					while (getline (miTXT,line)){	
						cout << line << '\n';
					}
					system("pause");
					system("cls");
					if(miTXT.eof()){	
						cout<<"Se ha terminado de leer. Fin del archivo";
						system("cls");
					}
						miTXT.close();
					}
					else cout << "No se puede abrir el archivo o no existe.";					
				}
				else if(opt=='3'){
					
					string line;
					ifstream miTXT ("Loteria Dificil.txt"); //se lee un archivo de loteria dificil
					if (miTXT.is_open()){	
					while (getline (miTXT,line)){	
						cout << line << '\n';
					}
					system("pause");
					system("cls");
					if(miTXT.eof()){	
						cout<<"Se ha terminado de leer. Fin del archivo";
						system("cls");
					}
						miTXT.close();
					}
					else cout << "No se puede abrir el archivo o no existe.";					
				}
				else if(opt=='4'){
					break;
				}
				else{
					cout<<"Ingrese una opcion existente"<<endl;
					system("pause");
					system("cls");
				}
				opt=listasFND();
				system("cls");
			}
		}
		else if(opc=='3'){
			break;
		}
		else{	//se muestra cada vez que el usuario ingrese una opcion que no esta en el menu
			cout<<"Esa opcion no esta, selecciones una existente."<<endl;
			i--;
			system("pause");
			system("cls");
		}
		if(i==0){	//si ingresa una opcion que no esta 5 veces se saldra del juego
			cout<<"Ha seleccionado repetidas veces una opcion inexistente. Saldra al menu de la consola"<<endl;
			system("pause");
			system("cls");
		}
	}	//while	
}	//loteria

void menu(){
	cout<<"LA LOTERIA"<<endl;
	cout<<endl;
	cout<<"1-Jugar\n2-Lista de partidas jugadas\n3-Salir del juego"<<endl;
	
}

void modo(){
	system("color 20");//cambia el color del fondo
	cout<<"SELECCIONE EL MODO: "<<endl;
	cout<<endl;
	cout<<"1-Facil\n2-Normal\n3-Dificil\n4-Salir al menu principal"<<endl;
}

void facil(){
	int A, B, C, D, intentos, dinero;
	char name[30];  //para el nombre del usuario
	srand(time(NULL)); //para generar numeros aleatorios diferentes cada vez que se ejecute el programa
	
	cout<<"Cual es tu nombre? ";cin>>name;  //se pide el nombre del usuario
	system("cls");
	
	cout<<"CUANTO APUESTAS "<<name<<"? $"; cin>>dinero; //se le pide al usuario cuanto dinero apuesta
	system("cls");
	
	cout<<"TU CAJA [$"<<dinero<<"]"<<endl;  //se le muestra el dinero que ha apostado
	system("pause");
	system("cls");
	
	if(dinero<=100){
		intentos = 30; //si apuesta $100 o menos, tendra 30 intentos
	}
	else if(dinero<=1000){ //si apuesta $1000 o menos, tendra 60 intentos
		intentos=60;
	}
	else if(dinero>=1001){ //si apuesta mas de $1000 tendra 100 intentos
		intentos=100;
	}
	
//	cout<<"Ingresa los intentos que desees: ";cin>>intentos;
	system("cls");
	
	while(intentos>=0){ //el while funcionara miestras los intentos no se acaben o cuando el usuario gane
		cout<<"                         $LA LOTERIA$"<<endl;
		cout<<"\n";
		//se generan 3 numeros aleatorios entre 0 y 4 que se guardaran en las variables A,B y C
		A = rand()% 4; 
		B = rand()% 4;
		C = rand()% 4;
							//se van imprimento en pantalla los numeros que se van generando
		cout<<"                       _________________"<<endl;
		cout<<"                      |                 |"<<endl;
		cout<<"                      |    ["<<A<<"]["<<B<<"]["<<C<<"]    |"<<endl;
		cout<<"                      |_________________|"<<endl;
		cout<<"                          Intentos: "<<intentos<<endl;
		cout<<"\n\n";
		if(A==B && A==C){ //si los 3 numeros coinciden
			
			time_t   t,x;		//se crean unas funciones que guardan la fecha y hora actual

			char *fecha;
													
			x = time (&t);
			
			fecha = ctime (&x);  
			
			ofstream lotof("loteria facil.txt",ios_base::app); //se crea u archivo en el escritorio
			 
			if (lotof.is_open()){  //luego en ese archivo se guarda la fecha, y los datos de como gano el usuario como los intentos, el dinero que gano y su nombre
				
				lotof<<"Jugador: "<<name<<"                                 Fecha: "<<fecha<<endl;
				lotof<<"Ha ganado con la combinacion: "<<A<<" "<<B<<" "<<C<<", a los "<<intentos<<" intentos y se llevo $"<<dinero+dinero<<endl;;				
				for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
					lotof<<"_";
				}
				lotof<<endl;
				lotof.close(); //se cierra el archivo creado
				
			}
			
			
			else {
				
				cout<<"No se puede abrir el archivo o no existe"<<endl;
				
			}
			
			cout<<"Felicidades "<<name<<"!! Ganaste!!"<<endl; //se muestra en pantalla lo que gano el usuario
			cout<<"Te llevas $"<<dinero+dinero<<endl;
			cout<<"\n\n\n\n\n\n";
			
			for(int i=0;i<100;i++){ //un for que contiene una funcion para cambiar el fondo de la consola pra un efecto como de varios colores
				system("color 17"); //a la hora que el usuario gana la partida
				system("color 57");
			}
			
			system("pause"); //dos funciones para detener la consola y no se cierre antes de mostrar que el usuario ha ganado
			system("pause");
			system("cls");
			break;
		}

		intentos--; //los intetos van disminuyendo cada vez que se generan nuevos numeros aleatorios
		system("pause");
		system("cls");
	}
	if(intentos==-1){ //si los intentos terminan y los numeros nunca coincidieron
		system("color 47");
		
		time_t   t,x;  //sevuelve a generar la fecha

		char *fecha;
						
		x = time (&t);
			
		fecha = ctime (&x);  
			
		ofstream lotof("loteria facil.txt",ios_base::app); //se vuelve a utilizar el archivo que se creo cuando el usuario gana
			
		if (lotof.is_open()){ //esta vez se llena con informacion de como ha perdido el usuario, como por ejemplo el dinero que perdio
				
			lotof<<"Jugador: "<<name<<"                                 Fecha: "<<fecha<<endl;
			lotof<<"Perdio con la combinacion: "<<A<<" "<<B<<" "<<C<<", $"<<dinero<<endl;
			for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
				lotof<<"_";
			}
			lotof<<endl;
			lotof.close(); //se cierra el archivo creado
		}
			
			
		else {
				
			cout<<"No se puede abrir el archivo o no existe"<<endl;
				
		}
		
		cout<<"Parece que no ganaste nada "<<name<<" jeje"<<endl; //se imprime en pantalla cuando el usuario pierde
		cout<<"TU CAJA: "<<dinero-dinero<<endl;	
		system("pause");
		system("cls");
		}
	
}

void normal(){  //es exactamente el mismo proceso que se hace en la funcion de modo facil
	int A, B, C, D, intentos, dinero;
	char name[30];
	srand(time(NULL));
	
	cout<<"Cual es tu nombre? ";cin>>name;  //se pide el nombre del usuario
	system("cls");
	
	cout<<"CUANTO APUESTAS "<<name<<"? $"; cin>>dinero; //cuanto apuesta el usuario
	system("cls");
	
	cout<<"TU CAJA [$"<<dinero<<"]"<<endl; //lo que ha apostado
	system("pause");
	system("cls");
	
	if(dinero<=100){ //si apuesta $100 o menos en modo normal seran 40 intentos
		intentos = 40;
	}
	else if(dinero<=1000){ //si apuesta $1000 o menos seran 70 intentos
		intentos=70;
	}
	else if(dinero>=1001){ //si apuesta mas de $1000 seran 100 intentos
		intentos=100;
	}
	
//	cout<<"Ingresa los intentos que desees: ";cin>>intentos;
	system("cls");
	
	while(intentos>=0){
		cout<<"                           $LA LOTERIA$"<<endl;
		cout<<"\n";
		
		A = rand()% 4;  //en el modo normal se generan 4 numeros aleatorios entre 0 y 4
		B = rand()% 4;
		C = rand()% 4;
		D = rand()% 4;				//se muestran en pantalla los numeros que se van generando
		cout<<"                       ____________________"<<endl;
		cout<<"                      |                    |"<<endl;
		cout<<"                      |    ["<<A<<"]["<<B<<"]["<<C<<"]["<<D<<"]    |"<<endl;
		cout<<"                      |____________________|"<<endl;
		cout<<"                            Intentos: "<<intentos<<endl;
		cout<<"\n\n";
		if(A==B && A==C && A==D){	//si los 4 numeros coinciden
			
			time_t   t,x;

			char *fecha;		//se genera la fecha
						
			x = time (&t);
			
			fecha = ctime (&x);  
			
			ofstream lotoN("Loteria normal.txt",ios_base::app); //se crea otro archivo para el modo normal
			
			if (lotoN.is_open()){  //se almacena informacion de como gano el usuario
				
				lotoN<<"Jugador: "<<name<<"                                 Fecha: "<<fecha<<endl;
				lotoN<<"Ha ganado con la combinacion: "<<A<<" "<<B<<" "<<C<<" "<<D<<", a los "<<intentos<<" intentos y se llevo $"<<dinero+dinero<<endl;
				for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
					lotoN<<"_";
				}
				lotoN<<endl;
				lotoN.close(); //se cierra el archivo creado
			}
			
			
			else {
				
				cout<<"No se puede abrir el archivo o no existe"<<endl;
				
			}
			
			cout<<"Felicidades "<<name<<"!! Ganaste!!"<<endl; //se muestra le pantalla cuando el usuario gana
			cout<<"Te llevas $"<<dinero+dinero<<endl;
			cout<<"\n\n\n\n\n\n";
			
			for(int i=0;i<100;i++){ //nuevamente la pantalla parpadeara con varios colores al ganar el usuario
				system("color a7");
				system("color 57");
			}
			
			system("pause");
			system("pause");
			system("cls");
			break;
		}

		intentos--; //siempre los intentos van disminuyendo por cada vez que se generan numeros aleatorios
		system("pause");
		system("cls");
	}
	if(intentos==-1){ //si el usuario pierde
		system("color 47");
		
		time_t   t,x;

		char *fecha;
						//se genera la fecha
		x = time (&t);
			
		fecha = ctime (&x);  
			
		ofstream lotoN("Loteria normal.txt",ios_base::app); //se utiliza el archivo mismo de modo normal
			
		if (lotoN.is_open()){ //se llena con la informacion de como perdio el usuario
					
			lotoN<<"Jugador: "<<name<<"                                 Fecha: "<<fecha<<endl;
			lotoN<<"Perdio con la combinacion: "<<A<<" "<<B<<" "<<C<<" "<<D<<", $"<<dinero<<endl;
			for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
				lotoN<<"_";
			}
			lotoN<<endl;
			lotoN.close(); //se cierra el archivo creado
				
		}
			
			
		else {
				
			cout<<"No se puede abrir el archivo o no existe"<<endl;
				
		}
		
		cout<<"Parece que no ganaste nada "<<name<<" jeje"<<endl; //se imprime en pantalla que no gano 
		cout<<"TU CAJA: "<<dinero-dinero<<endl;	
		system("pause");
		system("cls");
		}
	
}

void dificil(){ //sigue siendo el mismo proceso que las funciones facil y normal
	int A, B, C, D, E, intentos, dinero;
	char name[30];
	srand(time(NULL));
	
	cout<<"Cual es tu nombre? ";cin>>name; //se pide el nombre al usuario
	system("cls");
	
	cout<<"CUANTO APUESTAS "<<name<<"? $"; cin>>dinero; //cuanto dinero apuesta
	system("cls");
	
	cout<<"TU CAJA [$"<<dinero<<"]"<<endl; //se le muestra lo que apuesta
	system("pause");
	system("cls");
	
	if(dinero<=100){ //si apuesta $100 o menos seran 50 intentos en el modo dificil
		intentos = 50;
	}
	else if(dinero<=1000){ //si apuesta $1000 o menos seran 100 intentos
		intentos=100;
	}
	else if(dinero>=1001){ //si apuesta mas de $1000 seran 150 intentos
		intentos=150; 
	}
	
//	cout<<"Ingresa los intentos que desees: ";cin>>intentos;
	system("cls");
	
	while(intentos>=0){
		cout<<"                           $LA LOTERIA$"<<endl;
		cout<<"\n";
		
		A = rand()% 4;  //en el modo dificil se generan 5 numeros aleatorios entre 0 y 4
		B = rand()% 4;
		C = rand()% 4;
		D = rand()% 4;
		E = rand()% 4;
						//se imprime en pantalla los numeros que se van generando
		cout<<"                       ______________________"<<endl;
		cout<<"                      |                      |"<<endl;
		cout<<"                      |    ["<<A<<"]["<<B<<"]["<<C<<"]["<<D<<"]["<<E<<"]   |"<<endl;
		cout<<"                      |______________________|"<<endl;
		cout<<"                             Intentos: "<<intentos<<endl;
		cout<<"\n\n";
		if(A==B && A==C && A==D && A==E){ //si los nuemros coinciden
			
			time_t   t,x;

			char *fecha;
								//se genera la fecha
			x = time (&t);
			
			fecha = ctime (&x);  
			
			ofstream lotoD("Loteria Dificil.txt",ios_base::app); //se crea otro archivo para el modo dificil
			
			if (lotoD.is_open()){ //se llena con la informacion de como gano el usuario
				
				lotoD<<"Jugador: "<<name<<"                                 Fecha: "<<fecha<<endl;
				lotoD<<"Ha ganado con la combinacion: "<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<E<<", a los "<<intentos<<" intentos y se llevo $"<<dinero+dinero<<endl;
				for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
					lotoD<<"_";
				}
				lotoD<<endl;
				lotoD.close(); //se cierra el archivo creado
				
			}
			
			
			else {
				
				cout<<"No se puede abrir el archivo o no existe"<<endl;
				
			}
			
			cout<<"Felicidades "<<name<<"!! Ganaste!!"<<endl; //se muestra en pantalla cuando gana el usuario
			cout<<"Te llevas $"<<dinero+dinero<<endl;
			cout<<"\n\n\n\n\n\n";
			
			for(int i=0;i<100;i++){ //la pantalla parpadea de colores
				system("color 27");
				system("color 47");
			}
		
			system("pause");
			system("pause");
			system("cls");
			break;
		}

		intentos--; //los intentos siempre disminuyendo cada vez que se generan numeros aleatorios
		system("pause");
		system("cls");
	}
	if(intentos==-1){ //si el usuario pierde
		system("color 47");
		
		time_t   t,x;

		char *fecha;
						//se genera la fecha
		x = time (&t);
			
		fecha = ctime (&x);  
		
		ofstream lotoD("Loteria Dificil.txt",ios_base::app); //en el mismo archivo del modo dificil 
			
		if (lotoD.is_open()){ //se guarda la informacion de como perdio el usuario y lo que perdio de dinero
				
			lotoD<<"Jugador: "<<name<<"                                 Fecha: "<<fecha<<endl;
			lotoD<<"Perdio con la combinacion: "<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<E<<", $"<<dinero<<endl;
			for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
				lotoD<<"_";
			}
			lotoD<<endl;
			lotoD.close(); //se cierra el archivo creado
				
		}
			
			
		else {
				
			cout<<"No se puede abrir el archivo o no existe"<<endl;
				
		}
		
		cout<<"Parece que no ganaste nada "<<name<<" jeje"<<endl; //se muestra en pantalla cuando el usuario pierde
		cout<<"TU CAJA: "<<dinero-dinero<<endl;	
		system("pause");
		system("cls");
		}
}

char listasFND(){ //menu para que el usuario elija que partidas quiere ver
	char opcion;
	cout<<"1-Partidas de Modo Facil\n2-Partidas de Modo Normal\n3-Partidas de Modo Dificil\n4-Salir al menu principal"<<endl;
	cout<<"Opcion: ";cin>>opcion;
	
	return opcion;
}

//fIN DE LAS FUNCIONES DE LA LOTERIA

//FUNCIONES DE ARREGLOS Y MATRICES

void instruccionesA(){
		char opc;
		int i=1; //variable i para que el while este funcionando miestras el usuario no elija una opcion existente
	
	while(i==1){
		cout<<"INDICACIONES: "<<endl;
		cout<<endl;
		cout<<"1-COMO SE JUEGA?\n2-OMITIR."<<endl;
		cout<<endl;
		cout<<"Opcion: ";cin>>opc; //se pide una opcion al usuario
		system("cls");
		if(opc=='1'){
			
			string line;
			ifstream miTXT ("instruccionesMatrix.txt"); //se lee un archivo con las instrucciones del juego
			if (miTXT.is_open()){	
			while (getline (miTXT,line)){	
				cout << line << '\n';
			}
			system("pause");
			system("cls");
			if(miTXT.eof()){	
				cout<<"Se ha terminado de leer. Fin del archivo";
				system("cls");
			}
				miTXT.close();
			}
			else cout << "No se puede abrir el archivo o no existe.";
				break;	
			i--; //si el usuario elije una opcion existente, el while terminara y pasara al siguiente menu
		}
		else if(opc=='2'){
			break;
		}
		else{
			cout<<"Seleccione una opcion existente!"<<endl; //se mostrara mientras le usuario elija una opcion que exista
			system("pause");
			system("cls");
		}
	}
}

void AMYBM(){ //funcion incipal del juego de matrices
	system("color 60"); //cambia color del fondo
	char opc, op, opti;
	int i=5, K=1; //variable i para que el while este funcionando mientras el usuario no elija una opcion existente y si i es 0 se sale del juego
	
	instruccionesA(); //se llama el menu de instrucciones
	
	while(i>0){
		menuA(); //menu de jugar o salir del juego
		cout<<endl;
		cout<<"Opcion: ";cin>>opc;
		system("cls");
		
		if(opc=='1'){ //si el usuario le da a jugar
			while(i>0){
				niveles(); //se le muestran los niveles del juego
				cout<<endl;
				cout<<"Seleccione el modo: ";cin>>op;
				system("cls");
				//segun el nivel que el usuario elija se llaman a cada una de las funciones que contienen el proceso de cada modo de juego
				if(op=='1'){
					facil1();
				}
				else if(op=='2'){
					normal2();
				}
				else if(op=='3'){
					dificil3();
				}
				else if(op=='4'){
					extremo();
				}
				else if(op=='5'){ //si le da salir en el menu de los modos, saldra al menu anterior
					break;
				}
				else{
					cout<<"Ha ingresado una opcion que no esta. Seleccione una existente!"<<endl;
					i--; 
					system("pause");
					system("cls");
				}
				if(i==0){		//si el usuario nunca elije una opcion existente se saldra del juego
					cout<<"Ha ingresado repetidas veces una opcion inexistente. Saldra del juego!"<<endl;
					system("pause");
					system("cls");
				}
			}			
		}
		else if(opc=='2'){ 
			opti=listasFNDE();
			system("cls");
			while(K==1){
				if(opti=='1'){
					
					string line;
					ifstream miTXT ("Matrices Facil.txt"); //se lee un archivo de matrices facil
					if (miTXT.is_open()){	
					while (getline (miTXT,line)){	
						cout << line << '\n';
					}
					system("pause");
					system("cls");
					if(miTXT.eof()){	
						cout<<"Se ha terminado de leer. Fin del archivo";
						system("cls");
					}
						miTXT.close();
					}
					else cout << "No se puede abrir el archivo o no existe.";					
				}
				else if(opti=='2'){
					
					string line;
					ifstream miTXT ("Matrices Normal.txt"); //se lee un archivo de matrices normal
					if (miTXT.is_open()){	
					while (getline (miTXT,line)){	
						cout << line << '\n';
					}
					system("pause");
					system("cls");
					if(miTXT.eof()){	
						cout<<"Se ha terminado de leer. Fin del archivo";
						system("cls");
					}
						miTXT.close();
					}
					else cout << "No se puede abrir el archivo o no existe.";					
				}
				else if(opti=='3'){
					
					string line;
					ifstream miTXT ("Matrices Dificil.txt"); //se lee un archivo de matrices dificil
					if (miTXT.is_open()){	
					while (getline (miTXT,line)){	
						cout << line << '\n';
					}
					system("pause");
					system("cls");
					if(miTXT.eof()){	
						cout<<"Se ha terminado de leer. Fin del archivo";
						system("cls");
					}
						miTXT.close();
					}
					else cout << "No se puede abrir el archivo o no existe.";					
				}
				else if(opti=='4'){
					
					string line;
					ifstream miTXT ("Matrices Extremo.txt"); //se lee un archivo de matrices extremo
					if (miTXT.is_open()){	
					while (getline (miTXT,line)){	
						cout << line << '\n';
					}
					system("pause");
					system("cls");
					if(miTXT.eof()){	
						cout<<"Se ha terminado de leer. Fin del archivo";
						system("cls");
					}
						miTXT.close();
					}
					else cout << "No se puede abrir el archivo o no existe.";					
				}
				else if(opti=='5'){
					break;
				}
				else{
					cout<<"Ingrese una opcion existente!"<<endl;
					system("pause");
					system("cls");
				}
				opti=listasFNDE();
				system("cls");
			}
		}
		else if(opc=='3'){//si elije salir del juego, saldra al menu de juegos
			break;
		}
		else{
			cout<<"Esa opcion no esta, selecciones una existente."<<endl;
			i--;
			system("pause");
			system("cls");
		}
		if(i==0){		//si el usuario nunca elije una opcion existente se saldra del juego
			cout<<"Ha seleccionado repetidas veces una opcion inexistente. Saldra al menu de la consola"<<endl;
			system("pause");
			system("cls");
		}
	}	//while	
}//arreglos

void menuA(){
	cout<<"ARREGLOS, MATRICES Y UNA BUENA MEMORIA"<<endl;
	cout<<endl;
	cout<<"1-Jugar\n2-Lista de partidas jugadas\n3-Salir del juego"<<endl;
}

void niveles(){
	system("color 60");
	cout<<"Seleccione la dificultad: "<<endl;
	cout<<endl;
	cout<<"1-Facil (6 Niveles)\n2-Normal (6 Niveles)\n3-Dificil (6 Niveles)\n4-Extremo (4 Niveles)\n5-Salir al menu principal"<<endl;
}

void facil1(){
					//se declaran los 6 arreglos para cada nivel del modo facil
	int opcion, N=1, primero[2]={1,2}, segundo[3]={1,2,3}, tercero[5]={1,2,3,4,5}, cuarto[3],quinto[5], sexto[8];
	char name[30];	
	srand(time(NULL)); //para generar numeros aleatorios diferentes cada vez que se ejecute el juego
	
	cout<<"Cual es tu nombre? ";cin>>name; //pedimos el nombre al usuario
	system("cls");
		
	while(N<=6){ //la variable N es para ir mostrando en el nivel que va el jugador, cuando N sea 6 osea el ultimo nivel, termina el while
		cout<<"NIVEL "<<N<<endl;                                                 //nivel 1 
		cout<<"Observe el arreglo el tiempo que le sea necesario: \n\n";
		for(int i=0;i<2;i++){
			cout<<primero[i]<<" |";			//se muestra el arreglo del nivel 1
		}
		cout<<"\n\n";
		system("pause");		//funcion para darle tiempo al usuario de ver el arreglo
		system("cls");        //funcion que limpia la pantalla
		cout<<"Que numero estaba en la posicion [0]? ";cin>>opcion; //se le hace una pregunta al usuario sobre el arreglo mostrado
		if(opcion==primero[0]){		 //si la opcion del usuario es igual al de la posicion indicada del arreglo, para de nivel										
			cout<<"Muy bien!! vamos al siguiente nivel."<<endl;
			for(int i=0;i<2;i++){
				cout<<primero[i]<<" |";		//se le vuelve a mostrar el mismo arreglo al usuario para ver que su respuesta si es correcta	
			}
			cout<<endl;
			N++; //la variable N aumenta en 1 para el siguiente nivel
			system("pause");
			system("cls");
			
			cout<<"NIVEL "<<N<<endl;                                          //fin de nivel 1 y empieza nivel 2
			cout<<"Observe el arreglo el tiempo que le sea necesario: \n\n";
			for(int i=0;i<3;i++){
				cout<<segundo[i]<<" |";			//se muestra el arreglo del nivel 2		
			}
			cout<<"\n\n";
			system("pause");
			system("cls");
			cout<<"Que numero estaba en la posicion [2]? ";cin>>opcion; //se le hace la pregunta al usuario
			if(opcion==segundo[2]){
				cout<<"Muy bien!! vamos al siguiente nivel."<<endl; //si acierta la pregunta pasa al siguiente nivel
				for(int i=0;i<3;i++){
					cout<<segundo[i]<<" |";			 //se le vuelve a mostrar el arreglo del nivel 2 para verificar la respuesta
					}
					cout<<endl;
				N++; //vuelve a aumentar N para el nivel 3
				system("pause");
				system("cls");
				cout<<"NIVEL "<<N<<endl;                                         //fin de nivel 2 y empieza nivel 3
				cout<<"Observe el arreglo el tiempo que le sea necesario: \n\n";
				for(int i=0;i<5;i++){
					cout<<tercero[i]<<" |";  //se le muestra el arreglo del nivel 3 al usuario
				}
				cout<<"\n\n";
				system("pause");
				system("cls");
				cout<<"Que numero estaba en la posicion [3]? ";cin>>opcion; //se le hace otra pregunta sobre el arreglo
				if(opcion==tercero[3]){
					cout<<"Muy bien!! siguiente nivel."<<endl;
					for(int i=0;i<5;i++){
						cout<<tercero[i]<<" |";  //si acierta pasa al siguiente nivel y se le muestra nuevamente el arreglo al usuario para verificar
					}
					cout<<endl;
					N++;  //N aumenta para el nivel 4
					system("pause");
					system("cls");														//fin del nivel 3 y empieza el nivel 4
					cout<<"NIVEL "<<N<<endl;
					cout<<"Observe el arreglo que fue llenado con numeros aleatorios: \n\n";
					for(int i=0;i<3;i++){
						cuarto[i]=rand()% 9; //el arreglo del nivel 4 se llena con numeros aleatorios entre 0 y 9
					}
					for(int i=0;i<3;i++){
						cout<<cuarto[i]<<" |"; //se le muestra el arreglo del nivel 4 al usuario 
					}
					cout<<"\n\n";
					system("pause");
					system("cls");
					cout<<"Que numero estaba en la posicion [2]? ";cin>>opcion; //pregunta sobre el arreglo del nivel 4
					if(opcion==cuarto[2]){
						cout<<"Excelente!! siguiente nivel."<<endl; //pasa al siguiente nivel si acierta
						for(int i=0;i<3;i++){
							cout<<cuarto[i]<<" |"; //se muestra nuveamente el arreglo para confirmar la respuesta
						}
						cout<<endl;
						N++; //N aumenta para el nivel 5
						system("pause");
						system("cls");
						cout<<"NIVEL "<<N<<endl;														//termina el 4 y empieza el 5
						cout<<"Observe el siguiente arreglo llenado con numeros aleatorios: \n\n";
						for(int i=0;i<5;i++){
							quinto[i]=rand()% 9; //se llema el arreglo del nivel 5 con numeros aleatorios entre 0 y 9
						}
						for(int i=0;i<5;i++){
							cout<<quinto[i]<<" |"; //se muestra el arreglo nivel 5 en pantalla
						}
						cout<<"\n\n";
						system("pause");
						system("cls");
						cout<<"Que numero estaba en la posicion [4]? ";cin>>opcion; //pregunta del nivel 5
						if(opcion==quinto[4]){
							cout<<"Excelente!! siguiente nivel."<<endl; //pasa de nivel
							for(int i=0;i<5;i++){
								cout<<quinto[i]<<" |";  //se confirma la respuesta mostrando el arreglo nuevamente
							}
							cout<<endl;
							N++; //N aumenta para el nivel 6 y ultimo
							system("pause");
							system("cls");
							cout<<"NIVEL "<<N<<endl;															//termina el nivel 5 y empieza el 6 y ultimo
							cout<<"Observe el siguiente arreglo llenado con numeros aleatorios: \n\n";
							for(int i=0;i<8;i++){
								sexto[i]=rand()% 9; //se llena el arreglo del nivel 6 con nuemros aleatorios entre 0 y 9
							}
							for(int i=0;i<8;i++){
								cout<<sexto[i]<<" |"; //se muestra el arreglo nivel 6
							}
							cout<<"\n\n";
							system("pause");
							system("cls");
							cout<<"Que numero estaba en la posicion [5]? ";cin>>opcion; //pregunta del nivel 6
							if(opcion==sexto[5]){
								cout<<"Excelente!! Eres bueno memorizando."<<endl; //pasa el nivel
								for(int i=0;i<8;i++){
									cout<<sexto[i]<<" |"; //se le muestra el arreglo para confirmar la respuesta
								}
								cout<<"\n\n";
								cout<<"Has finalizado el modo facil. FELICIDADES "<<name<<"!!!"<<endl; //finaliza los 6 nvieles del modo facil
								
								time_t   t,x;					
								char *fecha;											
								x = time (&t);					//se genera la fecha y hora actual			
								fecha = ctime (&x);  
								
								ofstream matf("Matrices Facil.txt",ios_base::app);	 //se crea un archivo del modo facil del juego de matrices 							
								if (matf.is_open()){			//se guarda la informacion en el archivo de que el usuario paso los 6 niveles del modo facil de matrices						
									
									matf<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;					
									matf<<"Ha pasado los 6 niveles del modo facil"<<endl;
									for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
										matf<<"_";
									}
									matf<<endl;
									matf.close(); //se cierra el archivo creado
									
								}														
								else {									
									cout<<"No se puede abrir el archivo o no existe"<<endl;									
								}
								
								for(int i=0;i<100;i++){ //for que cambia el color de la pantalla con varios colores cuando el usuario gana
									system("color 17");
									system("color 57");
								}
								system("pause");
								system("cls");
								break;
							}
							else{
								system("color 47");																	//else del nivel 6
								//si el usuario pierde en el nivel 6 se genera el mismo archivo de matrices modo facil 
								time_t   t,x;					
								char *fecha;											
								x = time (&t);								
								fecha = ctime (&x);  
								
								ofstream matf("Matrices Facil.txt",ios_base::app); //se crea el archivo								
								if (matf.is_open()){									
									 //se guarda la informacion en el archivo de en que nivel perido el usuario
									matf<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
									matf<<"Perdiste en el nivel 6 del modo facil"<<endl;
									for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
										matf<<"_";
									}
									matf<<endl;
									matf.close(); //se cierra el archivo creado
									
								}														
								else {									
									cout<<"No se puede abrir el archivo o no existe"<<endl;									
								}
								
								cout<<"Fallaste!! El numero en esa posicion era: "<<sexto[5]<<endl; //se muestra en pantalla de que le usuario ha perido
								for(int i=0;i<8;i++){
									cout<<sexto[i]<<" |"; //se le muestra al usuario nuevamente el arreglo del nivel 6 para que vea la respuesta correcta
								}
								cout<<"\n\n";							
								system("pause");
								system("cls");
								cout<<"Game Over!"<<endl; //fin del juego y sale al menu de modos de juego
								system("pause");
								system("cls");
							}
							break;
						}
						else{
							system("color 47");																	//else del nivel 5
								//archivo del nivel 5 donde se guarda informacion de que le usuario perdio en el nivel 5
								time_t   t,x;					
								char *fecha;											
								x = time (&t);								
								fecha = ctime (&x);  
								
								ofstream matf("Matrices Facil.txt",ios_base::app);								
								if (matf.is_open()){									;
									matf<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
									matf<<"Perdiste en el nivel 5 del modo facil"<<endl;
									for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
										matf<<"_";
									}
									matf<<endl;
									matf.close(); //se cierra el archivo creado
									
								}														
								else {									
									cout<<"No se puede abrir el archivo o no existe"<<endl;									
								}
							
							cout<<"Fallaste!! El numero en esa posicion era: "<<quinto[4]<<endl;
							for(int i=0;i<5;i++){
								cout<<quinto[i]<<" |"; //se le muestra el arreglo nivel 5 para que vea la respuesta correcta el usuario
							}
							cout<<"\n\n";
							system("pause");
							system("cls");
							cout<<"Game Over!"<<endl; //fin del juego y sale al menu de modos de juego
							system("pause");
							system("cls");
							break;	
						}
						break;
					}
					else{
						system("color 47");																//else del nivel 4
						//archivo del nivel 4 donde se guarda informacion de que le usuario perdio en el nivel 4
						time_t   t,x;					
						char *fecha;											
						x = time (&t);								
						fecha = ctime (&x);  
								
						ofstream matf("Matrices Facil.txt",ios_base::app);								
						if (matf.is_open()){									
							matf<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
							matf<<"Perdiste en el nivel 4 del modo facil"<<endl;
							for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
								matf<<"_";
							}
							matf<<endl;
							matf.close(); //se cierra el archivo creado
									
						}														
						else {									
							cout<<"No se puede abrir el archivo o no existe"<<endl;									
						}		
						
						cout<<"Fallaste!! El numero en esa posicion era: "<<tercero[3]<<endl;
						for(int i=0;i<3;i++){
							cout<<cuarto[i]<<" |"; //se le muestra el arreglo nivel 4 para que vea la respuesta correcta el usuario
						}
						cout<<"\n\n";
						system("pause");
						system("cls");
						cout<<"Game Over!"<<endl; //fin del juego y sale al menu de modos de juego
						system("pause");
						system("cls");
						break;
					}
					break;
				}
				else{
					system("color 47");																	//else del nivel 3
						//archivo del nivel 3 donde se guarda informacion de que le usuario perdio en el nivel 3
						time_t   t,x;					
						char *fecha;											
						x = time (&t);								
						fecha = ctime (&x);  
								
						ofstream matf("Matrices Facil.txt",ios_base::app);								
						if (matf.is_open()){									
							matf<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
							matf<<"Perdiste en el nivel 3 del modo facil"<<endl;
							for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
								matf<<"_";
							}
							matf<<endl;
							matf.close(); //se cierra el archivo creado
									
						}														
						else {									
							cout<<"No se puede abrir el archivo o no existe"<<endl;									
						}		
					
					cout<<"Fallaste!! El numero en esa posicion era: "<<tercero[3]<<endl;
					for(int i=0;i<5;i++){
						cout<<tercero[i]<<" |"; //se le muestra el arreglo nivel 3 para que vea la respuesta correcta el usuario
					}
					cout<<"\n\n";
					system("pause");
					system("cls");
					cout<<"Game Over!"<<endl; //fin del juego y sale al menu de modos de juego
					system("pause");
					system("cls");
					break;
				}	
				
			}
			else{
				system("color 47");																	//else del nivel 2
				//archivo del nivel 2 donde se guarda informacion de que le usuario perdio en el nivel 2
				time_t   t,x;					
				char *fecha;											
				x = time (&t);								
				fecha = ctime (&x);  
								
				ofstream matf("Matrices Facil.txt",ios_base::app);								
				if (matf.is_open()){									
					matf<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
					matf<<"Perdiste en el nivel 2 del modo facil"<<endl;
					for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
						matf<<"_";
					}
					matf<<endl;
					matf.close(); //se cierra el archivo creado
									
				}														
				else {									
					cout<<"No se puede abrir el archivo o no existe"<<endl;									
				}		
				
				cout<<"Fallaste!! El numero en esa posicion era: "<<segundo[2]<<endl;
				for(int i=0;i<3;i++){
					cout<<segundo[i]<<" |";		 //se le muestra el arreglo nivel 2 para que vea la respuesta correcta el usuario	
				}
				cout<<"\n\n";
				system("pause");
				system("cls");
				cout<<"Game Over!"<<endl; //fin del juego y sale al menu de modos de juego
				system("pause");
				system("cls");
				break;
			}	
		}		
		else{
			system("color 47");																		//else del nivel 1
			//archivo del nivel 1 donde se guarda informacion de que le usuario perdio en el nivel 1
			time_t   t,x;					
			char *fecha;											
			x = time (&t);								
			fecha = ctime (&x);  
								
			ofstream matf("Matrices Facil.txt",ios_base::app);								
			if (matf.is_open()){									
				matf<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
				matf<<"Perdiste en el nivel 1 del modo facil"<<endl;
				for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
					matf<<"_";
				}
				matf<<endl;
				matf.close(); //se cierra el archivo creado
									
			}														
			else {									
				cout<<"No se puede abrir el archivo o no existe"<<endl;									
			}		
			
			cout<<"Fallaste!! El numero en esa posicion era: "<<primero[0]<<endl;
			for(int i=0;i<2;i++){
				cout<<primero[i]<<" |";		 //se le muestra el arreglo nivel 1 para que vea la respuesta correcta el usuario	
			}
			cout<<"\n\n";
			system("pause");
			system("cls");
			cout<<"Game Over!"<<endl; //fin del juego y sale al menu de modos de juego
			system("pause");
			system("cls");
			break;
			
		}
		
	}
		
}

void normal2(){	
	srand(time (NULL)); //para generar aleatorios diferentes        Se declaran los arreglos y matrices del modo normal
	int opcion, N=1, primero[8], segundo[2][2], tercero[2][3]={{2,4,6},{1,3,5}}, cuarto[2][4], quinto[4][2],sexto[3][3]={{9,8,7},{6,5,4},{3,2,1}};
	char name[30];                 
	//en la funcion de modo normal es el mismo proceso y logica que se lleva en la funcion de modo facil, se muestran los arreglos o matrices y se hace la pregunta al usuario
	cout<<"Cual es tu nombre? ";cin>>name;//se pide el nombre dle usuario
	system("cls");
	
	while(N<=6){ //misma variable N que va mostrando al usuario el nivel en el que esta
		cout<<"NIVEL "<<N<<endl;																	//nivel 1
		cout<<"Observe el arreglo de numeros aleatorios el tiempo que considere necesario: \n\n";
		for(int i=0;i<8;i++){
			primero[i]= rand()% 9;  //se llena el areglo nivel 1 con aleatorios del 0 al 9
		}
		for(int i=0;i<8;i++){
			cout<<primero[i]<<" |"; //se muestra el arreglo al usuario
		}
		cout<<"\n\n";
		system("pause");
		system("cls");
		cout<<"Que numero se encontraba en la posicion [7]? ";cin>>opcion; //se le hace la pregunta
		if(opcion==primero[7]){
			cout<<"Buen trabajo!! Siguiente nivel."<<endl; //si al acierta pasa al siguiente nivel
			for(int i=0;i<8;i++){
				cout<<primero[i]<<" |"; //se le muestra nuevamente el arreglo para confirmar la respuesta
			}
			cout<<endl;
			N++; //aumenta N para el nivel 2
			system("pause");															//nivel 2
			system("cls");													//termina nivel 1 y empieza el 2 modo normal
			cout<<"NIVEL "<<N<<endl;
			cout<<"Observe la matriz detenidamente el tiempo que desees: \n\n";
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					segundo[i][j]=rand()% 9; //se llena una matriz de 2x2 con numeros aleatorios entre 0 y 9
				}
			}
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					cout<<segundo[i][j]<<" |"; //se muestra la matriz al usuario
				}
				cout<<endl;
			}
			cout<<"\n\n";
			system("pause");
			system("cls");
			cout<<"Que numero se encontraba en la posicion [1][1]? ";cin>>opcion; //se le hace la pregunta
			if(opcion==segundo[1][1]){
				cout<<"Bien hecho!! Siguiente nivel."<<endl; //si acierta pasa al siguiente nivel
				for(int i=0;i<2;i++){
					for(int j=0;j<2;j++){
						cout<<segundo[i][j]<<" |"; //se le muestra de nuevo la matriz para confirmar respuesta
					}
					cout<<endl;
				}
				cout<<endl;
				N++; //N aumenta para el nivel 3
				system("pause");
				system("cls");													//fin del nivel 2 y empieza el 3 modo normal
				cout<<"NIVEL "<<N<<endl;
				cout<<"Observe la matriz y toma tu tiempo: \n\n";
				for(int i=0;i<2;i++){
					for(int j=0;j<3;j++){
						cout<<tercero[i][j]<<" |"; //se le muestra al usuario una matriz con datos que han sido quemados, es decir, no son aleatorios
					}
					cout<<endl;
				}
				cout<<"\n\n";
				system("pause");
				system("cls");
				cout<<"Que numero habia en la posicion [1][2]? ";cin>>opcion; //se le hace la preugnta al usuario
				if(opcion==tercero[1][2]){
					cout<<"Fastastico!! Siguiente nivel."<<endl;//pasa de nivel
					for(int i=0;i<2;i++){
						for(int j=0;j<3;j++){
							cout<<tercero[i][j]<<" |"; //se le muestra nuevamente la matriz para confirmar
						}
						cout<<endl;
					}
					cout<<endl;
					N++; //aumenta N a para el nivel 4
					system("pause");
					system("cls");													//fin del nivel 3 y empieza el 4 modo normal
					cout<<"NIVEL "<<N<<endl;
					cout<<"Vea detenidamente la matriz: \n\n";
					for(int i=0;i<2;i++){
						for(int j=0;j<4;j++){
							cuarto[i][j]=rand()% 9; //se llena la matriz del nivel 4 con aleatorios entre 0 y 9
						}
					}
					for(int i=0;i<2;i++){
						for(int j=0;j<4;j++){
							cout<<cuarto[i][j]<<" |"; //se muestra la matriz al usuario
						}
						cout<<endl;
					}
					cout<<"\n\n";
					system("pause");
					system("cls");
					cout<<"Que numero habia en la pocision [0][2]? ";cin>>opcion; //se le hace la pregunta
					if(opcion==cuarto[0][2]){
						cout<<"Excelente!! Siguiente nivel."<<endl; //pasa al siguiente nivel
						for(int i=0;i<2;i++){ 
							for(int j=0;j<4;j++){
								cout<<cuarto[i][j]<<" |"; //se muestra nuevamente la matriz para confirmar
							}
								cout<<endl;
						}
						cout<<endl;
						N++; //N aumenta para el nivel 5
						system("pause");
						system("cls");												//fin del nivel 4 y comienza el 5 modo normal
						cout<<"Nivel "<<N<<endl;
						cout<<"Observa la siguiente matriz con cuidado: \n\n";
						for(int i=0;i<4;i++){
							for(int j=0;j<2;j++){
								quinto[i][j]=rand()% 9;  //se llena la matriz del nivel 5 con aleatorios entre 0 y 9
							}
						}
						for(int i=0;i<4;i++){
							for(int j=0;j<2;j++){
								cout<<quinto[i][j]<<" |"; //se muestra la matriz al usuario
							}
							cout<<endl;
						}
						cout<<"\n\n";
						system("pause");
						system("cls");
						cout<<"Que numero se podia observar en la posicion [2][1]? ";cin>>opcion; //se le hace la pregunta
						if(opcion==quinto[2][1]){
							cout<<"Genial!! Siguiente nivel."<<endl; //pasa al siguiente nivel
							for(int i=0;i<4;i++){
								for(int j=0;j<2;j++){
									cout<<quinto[i][j]<<" |"; //nuevamente se le muestra la matriz para confirmar respuesta
								}
								cout<<endl;
							}
							cout<<endl;
							N++; //N aumenta para el nivel 6 y ultimo
							system("pause");
							system("cls");												//fin del nivel 5 y empieza el 6 modo normal
							cout<<"NIVEL "<<N<<endl;
							cout<<"Este es el ultimo nivel. Podras completar este modo? Veamos..."<<endl;
							system("pause");
							system("cls");
							cout<<"Observa la siguiente matriz: \n\n";
							for(int i=0;i<3;i++){
								for(int j=0;j<3;j++){
									cout<<sexto[i][j]<<" |"; // se le muestra una matriz de 3x3 con datos quemados
								}
								cout<<endl;
							}
							cout<<"\n\n";
							system("pause");
							system("cls");
							cout<<"Que numero se hospedaba en la posicion [2][2] de la matriz? ";cin>>opcion; //se le hace la pregunta al usuario
							if(opcion==sexto[2][2]){
								cout<<"Excelentisimo mi amigo!!!"<<endl; //pasa el nivel 6
								for(int i=0;i<3;i++){
									for(int j=0;j<3;j++){
										cout<<sexto[i][j]<<" |"; //se le muestra nuevamente la matriz para confirmar respuesta
									}
									cout<<endl;
								}
								cout<<endl;
								system("pause");
								system("cls");
								cout<<"FELICIDADES "<<name<<"!! TERMINASTE EL MODO NORMAL, ERES MUY ATENTO!"<<endl; //se imprime que el usuario ha pasado los 6 niveles del modo normal
								//se crea un archivo de texto donde se guarda la informacion de que le usuario ha terminado los 6 niveles del modo normal
								time_t   t,x;					
								char *fecha;											
								x = time (&t);								
								fecha = ctime (&x);  								
								ofstream matN("Matrices Normal.txt",ios_base::app);								
								if (matN.is_open()){									
									matN<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
									matN<<"Ha pasado los 6 niveles del modo normal."<<endl;								
									for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
										matN<<"_";
									}
									matN<<endl;
									matN.close(); //se cierra el archivo creado							
								}														
								else {									
									cout<<"No se puede abrir el archivo o no existe"<<endl;									
								}
								
								for(int i=0;i<100;i++){ //for donde secambia el color del fondo de la consola a diferentes colores cuando el usuario gana
									system("color 17");
									system("color 57");
								}
								system("pause");
								system("cls");
								break;
							}
							else{
								system("color 47");																//else del nivel 6 modo normal
								//se crea un archivo donde se guarda que el usuario perdio en la pregunta 6
								time_t   t,x;					
								char *fecha;											
								x = time (&t);								
								fecha = ctime (&x);  								
								ofstream matN("Matrices Normal.txt",ios_base::app);								
								if (matN.is_open()){									
								matN<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
								matN<<"Perdiste en el nivel 6 del modo normal."<<endl;								
								for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
									matN<<"_";
								}
								matN<<endl;
								matN.close(); //se cierra el archivo creado									
								}														
								else {									
									cout<<"No se puede abrir el archivo o no existe"<<endl;									
								}				
								
								cout<<"Fallaste!! El numero en esa posicion era: "<<cuarto[2][2]<<endl;
								for(int i=0;i<3;i++){
									for(int j=0;j<3;j++){
										cout<<sexto[i][j]<<" |"; //se le vuelve a mostrar la matriz del nivel 6 para que vea cual era la respuesta
									}
									cout<<endl;
								}								
								system("pause");
								system("cls");
								cout<<"Game Over!"<<endl; //pierde y vuelve al menu de modos de juego
								system("pause");
								system("cls");
								break;	
							}
						}
						else{
							system("color 47");																//else del nivel 5 modo normal
							//se crea un archivo donde se guarda que el usuario perdio en la pregunta 5
							time_t   t,x;					
							char *fecha;											
							x = time (&t);								
							fecha = ctime (&x);  								
							ofstream matN("Matrices Normal.txt",ios_base::app);								
							if (matN.is_open()){									
							matN<<"Jugador: "<<name<<"				Fecha:"<<fecha<<endl;
							matN<<"Perdiste en el nivel 5 del modo normal."<<endl;								
							for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
								matN<<"_";
							}
							matN<<endl;
							matN.close(); //se cierra el archivo creado										
							}														
							else {									
								cout<<"No se puede abrir el archivo o no existe"<<endl;									
							}
							
							cout<<"Fallaste!! El numero en esa posicion era: "<<cuarto[2][1]<<endl;
							for(int i=0;i<4;i++){
								for(int j=0;j<2;j++){
									cout<<quinto[i][j]<<" |";//se le vuelve a mostrar la matriz del nivel 5 para que vea cual era la respuesta
								}
								cout<<endl;
							}						
							system("pause");
							system("cls");
							cout<<"Game Over!"<<endl;//pierde y vuelve al menu de modos de juego
							system("pause");
							system("cls");
							break;	
						}						
					}
					else{
						system("color 47");																	//else del nivel 4 modo normal
						//se crea un archivo donde se guarda que el usuario perdio en la pregunta 4
						time_t   t,x;					
						char *fecha;											
						x = time (&t);								
						fecha = ctime (&x);  								
						ofstream matN("Matrices Normal.txt",ios_base::app);								
						if (matN.is_open()){									
						matN<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
						matN<<"Perdiste en el nivel 4 del modo normal."<<endl;								
						for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
							matN<<"_";
						}
						matN<<endl;
						matN.close(); //se cierra el archivo creado									
						}														
						else {									
							cout<<"No se puede abrir el archivo o no existe"<<endl;									
						}
						
						cout<<"Fallaste!! El numero en esa posicion era: "<<cuarto[0][2]<<endl;
						for(int i=0;i<2;i++){
							for(int j=0;j<4;j++){
								cout<<cuarto[i][j]<<" |";//se le vuelve a mostrar la matriz del nivel 4 para que vea cual era la respuesta
							}
								cout<<endl;
						}					
						system("pause");
						system("cls");
						cout<<"Game Over!"<<endl;//pierde y vuelve al menu de modos de juego
						system("pause");
						system("cls");
						break;	
					}
				}
				else{
					system("color 47");																	//else del nivel 3 modo normal
					//se crea un archivo donde se guarda que el usuario perdio en la pregunta 3
					time_t   t,x;					
					char *fecha;											
					x = time (&t);								
					fecha = ctime (&x);  								
					ofstream matN("Matrices Normal.txt",ios_base::app);								
					if (matN.is_open()){									
					matN<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
					matN<<"Perdiste en el nivel 3 del modo normal."<<endl;								
					for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
						matN<<"_";
					}
					matN<<endl;
					matN.close(); //se cierra el archivo creado									
					}														
					else {									
						cout<<"No se puede abrir el archivo o no existe"<<endl;									
					}
						
					cout<<"Fallaste!! El numero en esa posicion era: "<<tercero[1][2]<<endl;
					for(int i=0;i<2;i++){
						for(int j=0;j<3;j++){
							cout<<tercero[i][j]<<" |";//se le vuelve a mostrar la matriz del nivel 3 para que vea cual era la respuesta
						}
						cout<<endl;
					}				
					system("pause");
					system("cls");
					cout<<"Game Over!"<<endl;//pierde y vuelve al menu de modos de juego
					system("pause");
					system("cls");
					break;	
				}
			}
			else{
				system("color 47");																	//else del nivel 2 modo normal
				//se crea un archivo donde se guarda que el usuario perdio en la pregunta 2
				time_t   t,x;					
				char *fecha;											
				x = time (&t);								
				fecha = ctime (&x);  								
				ofstream matN("Matrices Normal.txt",ios_base::app);								
				if (matN.is_open()){									
				matN<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
				matN<<"Perdiste en el nivel 2 del modo normal."<<endl;								
				for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
					matN<<"_";
				}
				matN<<endl;
				matN.close(); //se cierra el archivo creado										
				}														
				else {									
					cout<<"No se puede abrir el archivo o no existe"<<endl;									
				}
				
				cout<<"Fallaste!! El numero en esa posicion era: "<<segundo[1][1]<<endl;
				for(int i=0;i<2;i++){
					for(int j=0;j<2;j++){
						cout<<segundo[i][j]<<" |";//se le vuelve a mostrar la matriz del nivel 2 para que vea cual era la respuesta
					}
					cout<<endl;
				}			
				system("pause");
				system("cls");
				cout<<"Game Over!"<<endl;//pierde y vuelve al menu de modos de juego
				system("pause");
				system("cls");
				break;
			}
		}
		else{
			system("color 47");																		//else del nivel 1 modo normal
			//se crea un archivo donde se guarda que el usuario perdio en la pregunta 1
			time_t   t,x;					
			char *fecha;											
			x = time (&t);								
			fecha = ctime (&x);  								
			ofstream matN("Matrices Normal.txt",ios_base::app);								
			if (matN.is_open()){									
			matN<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
			matN<<"Perdiste en el nivel 1 del modo normal."<<endl;								
			for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
				matN<<"_";
			}
			matN<<endl;
			matN.close(); //se cierra el archivo creado										
			}														
			else {									
				cout<<"No se puede abrir el archivo o no existe"<<endl;									
			}
			
			cout<<"Fallaste!! El numero en esa posicion era: "<<primero[7]<<endl;
			for(int i=0;i<8;i++){
				cout<<primero[i]<<" |";//se le vuelve a mostrar el arreglo del nivel 1 para que vea cual era la respuesta
			}			
			system("pause");
			system("cls");
			cout<<"Game Over!"<<endl;//pierde y vuelve al menu de modos de juego
			system("pause");
			system("cls");
			break;	
		}
	}

}

void dificil3(){
	int opcion, N=1, primero[3][3], segundo[3][3]={{1,2,3},{4,5,6},{7,8,9}}, tercero[3][3]={{1,2,3},{4,5,6},{7,8,9}}, cuarto[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int quinto[2][2]={{1,2},{3,4}}, sexto[3][3], suma=0, suma2=0, suma3=0, prod=1, prod1=1, prod2=1, prod3=1; 
	char name[30];		//se declaran las matrices para el nivel dificil, y algunas variables de suma y producto porque en unas matrices se hacen sumas y multiplicaciones
	srand(time(NULL));//para generar aleatorios sin repetir
	//ESTA FUNCION LLVA TAMBIEN LOS MISMOS PROCESOS DE LAS FUNCIONES DE MODO FACIL Y NORMAL. SE MUESTRAN LAS MATRICES Y SE HACE LA PREGUNTA y asi siempre
	cout<<"Cual es tu nombre? ";cin>>name; //se le pide el nombre al usuario
	system("cls");
	
	while(N<=6){
		cout<<"Puedes sumar y multiplicar? Atento porque aqui necesitaras saber!!"<<endl;
		system("pause");
		system("cls");
		cout<<"NIVEL "<<N<<endl;//la variable N siempre contando los niveles						//nivel 1
		cout<<"Observa muy bien la siguiente matriz: \n\n";
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				primero[i][j]=rand()% 9; //se llena la matriz del nivel 1 con numeros aleatorios entre 1 y 9
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout<<primero[i][j]<<" |"; //se muestra al usuario la matriz del nivel 1
			}
			cout<<endl;
		}
		cout<<"\n\n";
		system("pause");
		system("cls");
		cout<<"Que numero se encontraba en la posicion [1][1]? ";cin>>opcion; //se hace la pregunta sobre la matriz
		if(opcion==primero[1][1]){
			cout<<"Muy bien!! Siguiente nivel."<<endl; //pasa al siguiente nivel
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<primero[i][j]<<" |"; //se vuelve a mostrar la matriz para confirmar respuesta
				}
				cout<<endl;
			}
			cout<<endl;
			N++; //N aumenta para el nivel 2
			system("pause");
			system("cls");									//termina el nivel 1 y empieza el 2 modo dificil
			cout<<"NIVEL "<<N<<endl;                           //nivel 2
			cout<<"Mira bien esta matriz, muy atento: \n\n";
			
			for(int j=0;j<3;j++){
				suma=suma+segundo[0][j]; //se hace una suma de los digitos de la fila 0 de la matriz
			}
			
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<segundo[i][j]<<" |"; //se muestra la matriz del nivel 2 el cual tiene numeros quemados
				}
				cout<<endl;
			}
			cout<<"\n\n";
			system("pause");
			system("cls");
			cout<<"Cuanto sumaban los digitos de la fila [0]? "; cin>>opcion; //se hace la pregunta al usuario
			if(opcion==suma){
				cout<<"Excelente amigo!! Eres bueno. Siguiente nivel."<<endl; //pasa al siguente nivel
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						cout<<segundo[i][j]<<" |"; //se vuelve a mostrar la matriz para confirmar respuesta
					}
					cout<<endl;
				}
				cout<<endl;
				N++; //N aumenta para el nivel 3
				system("pause");
				system("cls");												//termina el nivel 2 y empieza el 3 modo dificil
				cout<<"NIVEL "<<N<<endl;								//nivel 3 modo dificil
				cout<<"Observa detenidamente la matriz: \n\n";
				for(int i=0;i<3;i++){
					suma2=suma2+tercero[i][1]; //se hace una suma de los numeros de la columna 1 de la matriz
				}
				
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						cout<<tercero[i][j]<<" |"; //se muestra la matriz que ha sido llenada con numeros quemados
					}
					cout<<endl;
				}
				cout<<"\n\n";
				system("pause");
				system("cls");
				cout<<"Cuanto sumaban los numeros de la columna [1]? ";cin>>opcion; //se hace la pregunta al usuario
				if(opcion==suma2){
					cout<<"Genial!! Si que sumas rapido!!. Siguiente nivel."<<endl; //pasa al siguiente nivel
					for(int i=0;i<3;i++){ 
						for(int j=0;j<3;j++){
							cout<<tercero[i][j]<<" |"; //se muestra la matriz para confirmar respuesta
						}
						cout<<endl;
					}
					cout<<endl;
					N++; //N aumenta al nivel 4
					system("pause");
					system("cls");									//termina el nivel 3 y empieza el 4
					cout<<"NIVEL "<<N<<endl;				//nivel 4 modo dificil
					cout<<"Mira bien la matriz: \n\n";
					for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							if(i==j){
								suma3=suma3+cuarto[i][j]; //se suman los digitos de la diagonal principal de la matriz donde i j son iguales
							}
						}
					}
					
					for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							cout<<cuarto[i][j]<<" |"; //se muestra en pantalla la matriz del nivel 4 al usuario
						}
						cout<<endl;
					}
					cout<<"\n\n";
					system("pause");
					system("cls");
					cout<<"Cuanto sumaban los digitos de la diagonal principal? ";cin>>opcion; //se hace la pregunta
					if(opcion==suma3){
						cout<<"Fantastico!! Eres bueno!! Siguiente nivel."<<endl; //pasa al siguiente nivel
						for(int i=0;i<3;i++){
							for(int j=0;j<3;j++){
								cout<<cuarto[i][j]<<" |"; //se muestra la matriz de nuevo para conifrmar
							}
							cout<<endl;
						}
						cout<<endl;
						N++; //N aumenta al nivel 5
						system("pause");
						system("cls");											//termina el nivel 4 y empieza el 5 modo dificil
						cout<<"NIVEL "<<N<<endl;			//nivel 5 modo dificil
						cout<<"Observa muy detenidamente la siquiente matriz: \n\n";
						
						for(int i=0;i<2;i++){
							for(int j=0;j<2;j++){
								if(i==j){
									prod=prod*quinto[i][j]; //se multiplican los numeros de la diagonal principal de la matriz 
								}
							}
						}
						for(int i=0;i<2;i++){
							for(int j=0;j<2;j++){
								cout<<quinto[i][j]<<" |"; //se le muestra al usuario la matriz
							}
							cout<<endl;
						}
						cout<<"\n\n";
						system("pause");
						system("cls");				//se le hace la preugnta al usuario
						cout<<"Que numeros su producto daba "<<prod<<"?"<<endl;
						cout<<"1-Los de la fila 0\n2-Los de la fila 1\n3-Los de la columna 0\n4-Los de la columna 1\n"
						"5-Los de la diagonal principal\n6-Los de la diagonal secundaria"<<endl;
						cin>>opcion;
						if(opcion==5){
							cout<<"Excelente!! eres bueno multiplicando!! Siguiente nivel."<<endl; //pasa al siguente nivel
							for(int i=0;i<2;i++){
								for(int j=0;j<2;j++){
									cout<<quinto[i][j]<<" |"; //se muestra de nuevo la matriz para confirmar respuesta
								}
								cout<<endl;
							}
							cout<<endl;
							N++; //N pasa al nivel 6
							system("pause");
							system("cls");
							cout<<"NIVEL "<<N<<endl;													//termina el 5 y empieza el nivel 6 modo dificil
							cout<<"Llegaste al ultimo nivel de este modo!! Podras superarlo? Adelante..."<<endl;
							system("pause");
							system("cls");
							cout<<"Mira bien la siguiente matriz: \n\n";
							for(int i=0;i<3;i++){
								for(int j=0;j<3;j++){
									sexto[i][j]= 1 + rand()% 9; //se llena la matriz del nivel 6 con aleatorios entre 1 y 9
								}
							}
							
							for(int j=0;j<3;j++){
								prod1=prod1*sexto[2][j]; //se multiplican los numeros de la fila 2 de la matriz
							}
							
							for(int j=0;j<3;j++){
								prod2=prod2*sexto[1][j]; //producto de la fila 1 de la matriz
							}
							
							for(int j=0;j<3;j++){
								prod3=prod3*sexto[0][j]; //producto de la fila 0 de la matriz
							}
							
							for(int i=0;i<3;i++){
								for(int j=0;j<3;j++){
									cout<<sexto[i][j]<<" |"; //se muestra la matriz al usuario en pantalla
								}
								cout<<endl;
							}
							cout<<"\n\n";
							system("pause");
							system("cls");
							cout<<"Cual era el producto de los numeros de la fila 2? "<<endl; //se le hace la pregunta al usuario
							cout<<"1- "<<prod2<<"\n2- "<<prod1<<"\n3- "<<prod3<<endl;
							cin>>opcion;
							if(opcion==2){
								cout<<"Fantastido!! Eres muy bueno en esto!! "<<endl; //pasa de nivel
								for(int i=0;i<3;i++){
									for(int j=0;j<3;j++){
										cout<<sexto[i][j]<<" |"; //sele vuelve a mostrar la matriz del nivel 6 para confirmar respuesta
									}
									cout<<endl;
								}
								cout<<endl;
								system("pause");
								system("cls");    //se muestra en pantalla que el usuario a terminado los niveles del modo dificil
								cout<<"FELICIDADES "<<name<<"!!! Terminaste el modo dificil! Eres bueno es este juego!"<<endl;
								//se crea un archivo para el modo dificil de matrices donde se guarda la informacion de que le usuario paso los 6 niveles del modo dificil
								time_t   t,x;					
								char *fecha;											
								x = time (&t);								
								fecha = ctime (&x);  	
															
								ofstream matD("Matrices Dificil.txt",ios_base::app);		 //archivo que se crea						
								if (matD.is_open()){									
									matD<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
									matD<<"Ha pasado los 6 niveles del modo dificil."<<endl;									
									for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
										matD<<"_";
									}
									matD<<endl;
									matD.close(); //se cierra el archivo creado										
								}															
								else {									
									cout<<"No se puede abrir el archivo o no existe"<<endl;									
								}
								
								for(int i=0;i<100;i++){ //la pantalla parpadea con diferentes colores cuando el usuario gana
									system("color 17");
									system("color 57");
								}						
								system("pause");
								system("cls");
								break;
							}
							
							else{
							system("color 47");											//else del nivel 6 modo dificil
							//se crea el mismo archivo del modo dificil donde se guarda informacion de que le usuario perdio en el nivel 6
							time_t   t,x;					
							char *fecha;											
							x = time (&t);								
							fecha = ctime (&x);  	
																			
							ofstream matD("Matrices Dificil.txt",ios_base::app);								
							if (matD.is_open()){									
								matD<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
								matD<<"Perdiste en el nivel 6 del modo dificil."<<endl;									
								for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
									matD<<"_";
								}
								matD<<endl;
								matD.close(); //se cierra el archivo creado										
							}															
							else {									
								cout<<"No se puede abrir el archivo o no existe"<<endl;									
							}
							
							cout<<"Fallaste!! El producto era "<<prod1<<endl;
							for(int i=0;i<3;i++){
								for(int j=0;j<3;j++){
									cout<<sexto[i][j]<<" |"; //se le vuelve a mostrar al usuario la matriz del nivel 6 para que vea cual era la respuesta
								}
								cout<<endl;
							}
							cout<<endl;
							system("pause");
							system("cls");
							cout<<"Game Over!"<<endl; //termina el juego y sale al menu de los modos
							system("pause");
							system("cls");
							}
							
						}
						else{
						system("color 47");																					//else del nivel 5 modo dificil
						//se crea el mismo archivo del modo dificil donde se guarda informacion de que le usuario perdio en el nivel 5
						time_t   t,x;					
						char *fecha;											
						x = time (&t);								
						fecha = ctime (&x);  	
																		
						ofstream matD("Matrices Dificil.txt",ios_base::app);								
						if (matD.is_open()){									
							matD<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
							matD<<"Perdiste en el nivel 5 del modo dificil."<<endl;									
							for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
								matD<<"_";
							}
							matD<<endl;
							matD.close(); //se cierra el archivo creado									
						}															
						else {									
							cout<<"No se puede abrir el archivo o no existe"<<endl;									
						}
						
						cout<<"Fallaste!! Los numeros que su producto era "<<prod<<", eran los de la diagonal principal"<<endl;
						for(int i=0;i<2;i++){
							for(int j=0;j<2;j++){
								cout<<quinto[i][j]<<" |";//se le vuelve a mostrar al usuario la matriz del nivel 5 para que vea cual era la respuesta
							}
							cout<<endl;
						}
						cout<<endl;
						system("pause");
						system("cls");
						cout<<"Game Over!"<<endl;//termina el juego y sale al menu de los modos
						system("pause");
						system("cls");
						}
					}
					else{
					system("color 47");															//else del nivel 4 modo dificil
					//se crea el mismo archivo del modo dificil donde se guarda informacion de que le usuario perdio en el nivel 4
					time_t   t,x;					
					char *fecha;											
					x = time (&t);								
					fecha = ctime (&x);  	
																	
					ofstream matD("Matrices Dificil.txt",ios_base::app);								
					if (matD.is_open()){									
						matD<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
						matD<<"Perdiste en el nivel 4 del modo dificil."<<endl;									
						for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
							matD<<"_";
						}
						matD<<endl;
						matD.close(); //se cierra el archivo creado										
					}															
					else {									
						cout<<"No se puede abrir el archivo o no existe"<<endl;									
					}
					
					cout<<"Fallaste!! La suma de los digitos de la diagonal principal era: "<<suma3<<endl;
					for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							cout<<cuarto[i][j]<<" |";//se le vuelve a mostrar al usuario la matriz del nivel 4 para que vea cual era la respuesta
						}
						cout<<endl;
					}
					cout<<endl;
					system("pause");
					system("cls");
					cout<<"Game Over!"<<endl;//termina el juego y sale al menu de los modos
					system("pause");
					system("cls");
				break;	
					}
				}
				else{
				system("color 47");														//else del nivel 3 modo dificil
				//se crea el mismo archivo del modo dificil donde se guarda informacion de que le usuario perdio en el nivel 3
					time_t   t,x;					
					char *fecha;											
					x = time (&t);								
					fecha = ctime (&x);  	
																	
					ofstream matD("Matrices Dificil.txt",ios_base::app);								
					if (matD.is_open()){									
						matD<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
						matD<<"Perdiste en el nivel 3 del modo dificil."<<endl;									
						for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
							matD<<"_";
						}
						matD<<endl;
						matD.close(); //se cierra el archivo creado										
					}															
					else {									
						cout<<"No se puede abrir el archivo o no existe"<<endl;									
					}
				
				cout<<"Fallaste!! La suma de los digitos en esa columna era: "<<suma2<<endl;
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						cout<<tercero[i][j]<<" |";//se le vuelve a mostrar al usuario la matriz del nivel 3 para que vea cual era la respuesta
					}
					cout<<endl;
				}
				cout<<endl;
				system("pause");
				system("cls");
				cout<<"Game Over!"<<endl;//termina el juego y sale al menu de los modos
				system("pause");
				system("cls");
				break;	
				}
				
			}
			else{
				system("color 47");															//else del nivel 2 modo dificil
				//se crea el mismo archivo del modo dificil donde se guarda informacion de que le usuario perdio en el nivel 2
				time_t   t,x;					
				char *fecha;											
				x = time (&t);								
				fecha = ctime (&x);  	
																
				ofstream matD("Matrices Dificil.txt",ios_base::app);								
				if (matD.is_open()){									
					matD<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
					matD<<"Perdiste en el nivel 2 del modo dificil."<<endl;									
					for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
						matD<<"_";
					}
					matD<<endl;
					matD.close(); //se cierra el archivo creado										
				}															
				else {									
					cout<<"No se puede abrir el archivo o no existe"<<endl;									
				}
				
				cout<<"Fallaste!! La suma de los digitos de esa fila era: "<<suma<<endl;
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						cout<<segundo[i][j]<<" |";//se le vuelve a mostrar al usuario la matriz del nivel 2 para que vea cual era la respuesta
					}
					cout<<endl;
				}
				cout<<endl;
				system("pause");
				system("cls");
				cout<<"Game Over!"<<endl;//termina el juego y sale al menu de los modos
				system("pause");
				system("cls");
				break;		
			}
		}
		else{
			system("color 47");																	//else del nivel 1 modo dificil
			//se crea el mismo archivo del modo dificil donde se guarda informacion de que le usuario perdio en el nivel 1
			time_t   t,x;					
			char *fecha;											
			x = time (&t);								
			fecha = ctime (&x);  	
															
			ofstream matD("Matrices Dificil.txt",ios_base::app);								
			if (matD.is_open()){									

				matD<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
				matD<<"Perdiste en el nivel 1 del modo dificil."<<endl;									
				for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
					matD<<"_";
				}
				matD<<endl;
				matD.close(); //se cierra el archivo creado										
			}															
			else {									
				cout<<"No se puede abrir el archivo o no existe"<<endl;									
			}
			
			cout<<"Fallaste!! El numero en esa posicion era: "<<primero[1][1]<<endl;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<primero[i][j]<<" |";//se le vuelve a mostrar al usuario la matriz del nivel 1 para que vea cual era la respuesta
				}
				cout<<endl;
			}
			cout<<endl;
			system("pause");
			system("cls");
			cout<<"Game Over!"<<endl;//termina el juego y sale al menu de los modos
			system("pause");
			system("cls");
			break;	
		}
	}
	
}

void extremo(){ //se declara una variable de suma para uno de los niveles
	int opcion, N=1, suma=0, num, num2, num3, num4 , primero[4][3], segundo[4][4], tercero[4][4], cuarto[5][5], sum=0;
	char name[30];    //se declaran las matrices de cada nivel
	srand(time(NULL)); //paa generar aleatorios diferentes
	
	cout<<"Cual es tu nombre? ";cin>>name;
	system("cls");
	
	while(N<=4){ //la variable N lleva la cuenta del nivel en el que va el usuario
		cout<<"CONCENTRATE!!"<<endl;
		system("pause");
		system("cls");
		cout<<"NIVEL "<<N<<endl;									//nivel 1 extremo
		cout<<"Observa bien la siguiente matriz: \n\n";
		for(int i=0;i<4;i++){  //aqui se llena la matriz con numeros aleatorios entre 1 y 50 sin repetirse en la matriz
			for(int j=0;j<3;j++){
				num = 1 + rand()% 50;
				while(!verifica(primero,num)){//una funcion llamada verifica que tiene como parametros la primera matriz y la variable num, se encarga de ver si el numero que se va a
					num = 1 + rand()% 50;		//introducir en la matriz esta repetido o no, y si lo esta se va a generar otro ramdom hasta que sea un numero que no este en la matriz							
				}
				primero[i][j]=num; //si el numero no esta repetido podra meterse a la matriz, y asi se valenando
			}
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<3;j++){
				cout<<setw(2)<<primero[i][j]<<" |"; //se muestra la matriz al usuario. la funcion setw() es para que haya espacio entre cada numero de la matriz y se vean ordenados
			}
			cout<<endl;
		}
		cout<<"\n\n";
		system("pause");
		system("cls");
		cout<<"Que numero se encontraba en la posicion [2][1]? ";cin>>opcion; //se le hace la pregunta al usuario
		if(opcion==primero[2][1]){
			cout<<"Grandioso!! Has acertado. Siguiente nivel."<<endl; //pasa al siguiente nivel
			for(int i=0;i<4;i++){
				for(int j=0;j<3;j++){
					cout<<setw(2)<<primero[i][j]<<" |"; //se le muestra nuevamente la matriz al usuario para verificar la respuesta
				}
				cout<<endl;
			}
			cout<<endl;
			N++; //N aumente al nivel 2
			system("pause");
			system("cls");																//termina el 1 y empieza el nivel 2 extremo
			cout<<"NIVEL "<<N<<endl;                                          //nivel 2 extremo
			cout<<"Observa detenidamente la siguiente matriz: \n\n";
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					num2 = 1 + rand()% 50;
					while(!exsegundo(segundo,num2)){//nuevamente se van verificando los numeros que no esten repetidos en la matriz para que se llene de numeros aleatorios sin repetir
						num2 = 1 + rand()% 50;								
					}
					segundo[i][j]=num2; //aqui se introduce el numero que no se repite a la matriz
				}
			}
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					cout<<setw(2)<<segundo[i][j]<<" |"; //se muestra la matriz del nivel 2 al usuario
				}
				cout<<endl;
			}
			cout<<"\n\n";
			system("pause");
			system("cls");			//se le hace la pregunta al usuario
			cout<<"En que posicion estaban los numeros "<<segundo[0][3]<<" y "<<segundo[3][1]<<"?"<<endl;
			cout<<"1-En la posicion [0][3] y [3][1]\n2-El la posicion [0][2] y [1][1]\n3-En la posicion [2][2] y [3][3]"<<endl;
			cin>>opcion;
			cout<<"\n\n";			
			if(opcion == 1){
				cout<<"Espectacular!! Eres excelente memorizando!! Siguiente nivel."<<endl; //pasa al siguiente nivel
				for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						cout<<setw(2)<<segundo[i][j]<<" |"; //se le vuelve a mostrar la matriz al usuario para verificar la respuesta
					}
					cout<<endl;
				}
				cout<<endl;
				N++;		//N aumenta al nivel 3
				system("pause");
				system("cls");															//termina el 2 y empieza el 3 extemo
				cout<<"NIVEL "<<N<<endl;												//nivel 3 extremo
				cout<<"Mira bien la siguiente matriz: \n\n";
				for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						tercero[i][j]= 1 + rand()% 20;  //se llena la matriz del nivel 3 con aleatorios entre 1 y 20
					}
				}
				for(int j=0;j<4;j++){
					suma = suma+ tercero[1][j]; //se hace una sumatoria de los numeros de la fila 1
				}
				
				for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						cout<<setw(2)<<tercero[i][j]<<" |"; //se le muestra la matriz al usuario
					}
					cout<<endl;
				}
				cout<<"\n\n";
				system("pause");
				system("cls");													
				cout<<"Cuanto sumaban los numeros de la fila 1? ";cin>>opcion; //se le hace la pregunta al usuario
				if(opcion==suma){
					cout<<"Excelente!! Siguiente nivel."<<endl;  //pasa al siguiente nivel
					for(int i=0;i<4;i++){
						for(int j=0;j<4;j++){
							cout<<setw(2)<<tercero[i][j]<<" |"; //se le muestra de nuevo la matriz de nivel 3 al usuario para verificar la respuesta
						}
						cout<<endl;
					}
					cout<<endl;
					N++; //N aumenta al nivel 4 y ultimo nivel
					system("pause");
					system("cls");											//temina el nivel 3 y empieza el 4 extremo
					cout<<"NIVEL "<<N<<endl;									//nivel 4
					cout<<"Observa muy atentamente XD\n\n";	
					for(int i=0;i<5;i++){
						for(int j=0;j<5;j++){
							cuarto[i][j]=rand()% 9; //se llena la matriz con numeros aleatorios entre 0 y 9
						}
					}
					
					for(int i=0;i<5;i++){
						sum=sum+cuarto[i][2]; //se hace una sumatoria de los numeros de la columna 2
					}
					
					for(int i=0;i<5;i++){
						for(int j=0;j<5;j++){
							cout<<cuarto[i][j]<<" |"; //se muestra al usuario la matriz del nivel 4
						}
						cout<<endl;
					}													
					cout<<"\n\n";
					system("pause");
					system("cls");
					cout<<"Cual era la suma de los digitos del la columna [2]? "; cin>>opcion; //se le hace la pregunta al usuario
					if(opcion==sum){						
						cout<<"Fantastico!! Eres realmente increible."<<endl; //pasa al siguiente nivel
						for(int i=0;i<5;i++){
							for(int j=0;j<5;j++){
								cout<<cuarto[i][j]<<" |"; //se le muestra nuevamente la matriz al usuario para verificar respuesta
							}
							cout<<endl;
						}				
						system("pause");
						system("cls");
						cout<<"FELICIDADES "<<name<<"!! FINALIZASTE EL MODO EXTREMO!!"<<endl; //le moestramos al usuario que ha terminado todos los niveles del modo extremo
						//se crea un archivo para el modo extremo donde se guarda la informacion de que el usuario paso todos los niveles de este modo
						time_t   t,x;					
						char *fecha;											
						x = time (&t);								
						fecha = ctime (&x);  
													
						ofstream matE("Matrices Extremo.txt",ios_base::app);	//se crea el archivo							
						if (matE.is_open()){									
							matE<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
							matE<<"Ha pasado los 4 niveles del modo extremo."<<endl;									
							for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
								matE<<"_";
							}
							matE<<endl;
							matE.close(); //se cierra el archivo creado									
						}																
						else {								
							cout<<"No se puede abrir el archivo o no existe"<<endl;									
						}
						
						for(int i=0;i<100;i++){ //for que hace que el fondo de la consola cambie a distintos colores cuando el usuario gana
							system("color 17");
							system("color 57");
						}		
						system("pause");
						system("cls");
						break;
					}					//if del nivel 4
					else{
						system("color 47");												//else del nivel 4 extremo
						//Se crea el mismo archivo del modo extremo donde se guarda la informacion de que el usuario a perdido en el nivel 4
						time_t   t,x;					
						char *fecha;											
						x = time (&t);								
						fecha = ctime (&x);  
																
						ofstream matE("Matrices Extremo.txt",ios_base::app);								
						if (matE.is_open()){									
							matE<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
							matE<<"Perdiste en el nivel 4 del modo extremo."<<endl;									
							for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
								matE<<"_";
							}
							matE<<endl;
							matE.close(); //se cierra el archivo creado									
						}																
						else {								
							cout<<"No se puede abrir el archivo o no existe"<<endl;									
						}
						
						cout<<"Fallaste!! La suma de los digitos de la columna [2] era "<<sum<<endl;
						for(int i=0;i<5;i++){
							for(int j=0;j<5;j++){
								cout<<cuarto[i][j]<<" |"; //se le muestra la matriz para que vea cual era la respuesta
							}
							cout<<endl;
						}																															
						cout<<endl;
						system("pause");
						system("cls");
						cout<<"Game Over!"<<endl; //termina el juego y vuelve al menu de los modos
						system("pause");
						system("cls");
						break;	
					}
				}		//if del nivel 3
				else{													//else del nivel 3 extremo
				//Se crea el mismo archivo del modo extremo donde se guarda la informacion de que el usuario a perdido en el nivel 3
					time_t   t,x;					
					char *fecha;											
					x = time (&t);								
					fecha = ctime (&x);  
															
					ofstream matE("Matrices Extremo.txt",ios_base::app);								
					if (matE.is_open()){									
						matE<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
						matE<<"Perdiste en el nivel 3 del modo extremo."<<endl;									
						for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
							matE<<"_";
						}
						matE<<endl;
						matE.close(); //se cierra el archivo creado							
					}																
					else {								
						cout<<"No se puede abrir el archivo o no existe"<<endl;									
					}
				
				system("color 47");
				cout<<"Fallaste!! La suma era "<<suma<<endl;
				for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						cout<<setw(2)<<tercero[i][j]<<" |"; //se le muestra la matriz para que vea cual era la respuesta
					}
					cout<<endl;
				}
				cout<<endl;
				system("pause");
				system("cls");
				cout<<"Game Over!"<<endl;  //termina el juego y vuelve al menu de los modos
				system("pause");
				system("cls");
				break;	
				}
			} //if del nivel 2
			else{																//else del nivel 2 extremo
			//Se crea el mismo archivo del modo extremo donde se guarda la informacion de que el usuario a perdido en el nivel 2
				time_t   t,x;					
				char *fecha;											
				x = time (&t);								
				fecha = ctime (&x);  
														
				ofstream matE("Matrices Extremo.txt",ios_base::app);								
				if (matE.is_open()){									
					matE<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
					matE<<"Perdiste en el nivel 2 del modo extremo."<<endl;									
					for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
						matE<<"_";
					}
					matE<<endl;
					matE.close(); //se cierra el archivo creado							
				}																
				else {								
					cout<<"No se puede abrir el archivo o no existe"<<endl;									
				}
			
				system("color 47");
				cout<<"Fallaste!! Eran en las posiciones [0][3] y [3][1]"<<endl;
				for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						cout<<setw(2)<<segundo[i][j]<<" |"; //se le muestra la matriz para que vea cual era la respuesta
					}
					cout<<endl;
				}
				cout<<endl;
				system("pause");
				system("cls");
				cout<<"Game Over!"<<endl; //termina el juego y vuelve al menu de los modos
				system("pause");
				system("cls");
				break;
			}
		}
		
		else{																//else del nivel 1 modo extremo
		//Se crea el mismo archivo del modo extremo donde se guarda la informacion de que el usuario a perdido en el nivel 1
			time_t   t,x;					
			char *fecha;											
			x = time (&t);								
			fecha = ctime (&x);  
													
			ofstream matE("Matrices Extremo.txt",ios_base::app);								
			if (matE.is_open()){									
				matE<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
				matE<<"Perdiste en el nivel 1 del modo extremo."<<endl;									
				for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
					matE<<"_";
				}
				matE<<endl;
				matE.close(); //se cierra el archivo creado								
			}																
			else {								
				cout<<"No se puede abrir el archivo o no existe"<<endl;									
			}
		
			system("color 47");
			cout<<"Fallaste!! El numero en la posicion [2][1] era : "<<primero[2][1]<<endl;
			for(int i=0;i<4;i++){
				for(int j=0;j<3;j++){
					cout<<setw(2)<<primero[i][j]<<" |"; //se le muestra la matriz para que vea cual era la respuesta
				}
				cout<<endl;
			}
			cout<<endl;
			system("pause");
			system("cls");
			cout<<"Game Over!"<<endl; //termina el juego y vuelve al menu de los modos
			system("pause");
			system("cls");
			break;	
		}
	}
}

bool verifica(int primero[][3], int num){ //funcion para verificar si un numero se repite en la matriz  //funcion bool del nivel 1 extremo
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(num==primero[i][j]){
				return false; //si se repite retornara un false
			}
		}
	}
	return true; //si no se repide retornara un true
}

bool exsegundo(int segundo[][4], int num2){ //funcion para verificar si un numero se repite en la matriz  //funcion bool del nivel 2 extremo
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(num2==segundo[i][j]){
				return false; //si se repite retornara un false
			}
		}
	}
	return true; //si no se repide retornara un true
}

char listasFNDE(){
	char option;
	cout<<"1-Partidas del Modo Facil\n2-Partidas del Modo Normal\n3-Partidas del Modo Dificil\n4-Partidas del Modo Extremo\n5-Salir al menu principal"<<endl;
	cout<<"Opcion: ";cin>>option;
	
	return option;
}

//FIN DE FUNCIONES DE ARREGLOS Y MATRICES

//FUNCIONES DE QUIEN QUIERE SER MILLONARIO

void millonario(){
	system("color 5b"); //cambia el color del fondo
	char O;
	int s=1; //variable s para que este funcionando infinitamente el while
	
	while(s==1){ //mientras el usuario no ingrese una opcion existente, el menu se le seguira mostrando
		menuM(); //menu del juego
		cout<<"Opcion: ";cin>>O;
		system("cls");
		
		if(O=='1'){
			preguntas();	//se llama a la funcion que contiene las preguntas de todo el juego
		}
		else if(O=='2'){
			InstruccionesM(); //funcion de las instrucciones de como se juega
			system("pause");
		}
		else if(O=='3'){
			
			string line;
			ifstream miTXT ("QUIEN QUIERE SER MILLONARIO.txt"); //se lee un archivo de quien quiere ser millonario
			if (miTXT.is_open()){	
			while (getline (miTXT,line)){	
				cout << line << '\n';
			}
			system("pause");
			system("cls");
			if(miTXT.eof()){	
				cout<<"Se ha terminado de leer. Fin del archivo";
				system("cls");
			}
				miTXT.close();
			}
			else cout << "No se puede abrir el archivo o no existe.";
			
		}
		else if(O=='4'){
			break;
		}

		system("cls");
	}
}

void menuM(){
	system("color 5b");
	cout<<"[MENU DE INICIO]"<<endl;
	cout<<endl;
	cout<<"1-Jugar\n2-Como se juega\n3-Lista de partidas jugadas\n4-Salir del juego"<<endl;
}

void InstruccionesM(){
	cout<<"[INSTRUCCIONES]"<<endl;
	cout<<endl;
	cout<<"Se te iran presentando preguntas y tienes que contestarlas correctamente.\n"
	"Cada vez vas a ir avanzando en las preguntas y el premio ira aumentando a \nmedida "
	"que vayas avanzando. \n\nSi te equivocas Pierdes!"<<endl;
	cout<<endl;
	nivelesM();
	
}

void preguntas(){
	int premio=100, Q=1, k=1; //la variable premio es lo que el usuario ira ganando conforme avanza en las preguntas
	char selec, name[30];    //variable Q lleva la cuenta de el numero de la pregunta..pregunta 1, pregunta 2 etc...
								//variable k es para que el while siga funcionando y mostrando la pregunta si el usuario no ingresa una opcion existente
	cout<<"Cual es tu nombre? ";cin>>name;
	system("cls");
	
	while(Q<=15 && k==1){
		system("color 30");
		cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 1
		cout<<endl;
		cout<<"Cuanto es 9x8?\n\na) 72\nb) 81\nc) 100\nd) 9"<<endl;
		cout<<"Opcion: ";cin>>selec;
		
		if(selec=='a'){
			cout<<"Coorectoo!! ya tienes: $"<<premio<<endl; //si la acierta ya tiene una cantidad de premio ganada y para de una vez a la siguiente
			cout<<"Vamos a la siguiente pregunta"<<endl;
				Q++; //Q aumenta para la pregunta 2
				system("pause");
				system("cls");
				while(Q<=15 && k==1){
					system("color a0");
					cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 2
					cout<<endl;
					cout<<"A que es igual el seno de un angulo?\n\na) Cateto opuesto sobre Hipotenusa\nb) Cateto adyacente sobre Hipotenusa\nc) Hipotenusa sobre Cateto opuesto\n"
					"d) Cateto opuesto sobre Cateto adyacente\ne) Me retiro con $"<<premio<<endl;
					cout<<"Opcion: ";cin>>selec;
					
					if(selec=='a'){
						cout<<"Corecctoo!! ya tienes: $"<<premio+100<<endl; //si la acierta se le suma mas al premio
						cout<<"Vamos a la siguiente pregunta"<<endl;
						Q++; //Q aumenta para la pregunta 3
						system("pause");
						system("cls");
						
						while(Q<=15 && k==1){
							system("color e0");
							cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 3
							cout<<endl;
							cout<<"Simbolo quimico del Nitrogeno:\n\na) Ni\nb) N\nc) Nitro\nd) Ni idea\ne) Me retiro con $"<<premio+100<<endl;
							cout<<"Opcion: ";cin>>selec;
							
							if(selec=='b'){
								cout<<"Corecctoo!! ya tienes: $"<<premio+200<<endl; //se le vuelve a sumar al premio mas, si la acierta
								cout<<"Vamos a la siguiente pregunta"<<endl;
								Q++; //Q aumenta de nuevo para la pregunta 4
								system("pause");
								system("cls");
								
								while(Q<=15 && k==1){
									system("color b0");
									cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 4
									cout<<endl;
									cout<<"K es la onceava letra del abecedario. Cierto o Falso?:\n\na) Cierto\nb) Falso\nc) Me retiro con $"<<premio+200<<endl;
									cout<<"Opcion: ";cin>>selec;
									
									if(selec=='a'){
										cout<<"Corecctoo!! ya tienes: $"<<premio+400<<endl; //si la acierta el premio aumenta mas
										cout<<"Vamos a la siguiente pregunta"<<endl;
										Q++; //Q aumenta para la pregunta 5
										system("pause");
										system("cls");
							
										
										while(Q<=15 && k==1){
											system("color a0");
											cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 5
											cout<<endl;
											cout<<"Como describirias a un hombre que no tiene todos los dedos en una mano?\n\na) Discapacitado\nb) Con capadicades especiales\n"
											"c) Normal\nd) Sin dedos\ne) Me retiro con $"<<premio+400<<endl;
											cout<<"Opcion: ";cin>>selec;
											
											if(selec=='c'){
												cout<<"Corecctoo!! ya tienes: $"<<premio+900<<endl; //el premio vuelve a aumentar si la contesta bien
												cout<<"Vamos a la siguiente pregunta"<<endl;
												Q++; //Q aumenta para la pregunta 6
												system("pause");
												system("cls");
												//se le muestra un mensaje de que llego a una zona segura 
												cout<<"Has llegado a la primer zona segura, has acertado 5 preguntas!\n"
												"De aqui en adelnate si pierdes ya tienes asegurado $1000"<<endl;
												system("pause");
												system("cls");
												
												while(Q<=15 && k==1){
													system("color b0");
													cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 6
													cout<<endl;
													cout<<"En que orden van los colores de cada letra de Google?\n\na) Rojo, Verde, Azul, Amarillo, Rojo, Azul\n"
													"b) Verde, Amarillo, Rojo, Verde, Azul, Rojo\nc) Azul, Rojo, Amarillo, Azul, Verde, Rojo\n"
													"d) Azul, Rojo, Amarillo, Azul, Rojo, Verde"<<endl;
													cout<<"Opcion: ";cin>>selec;
													
													if(selec=='c'){
														cout<<"Corecctoo!! ya tienes: $"<<premio+1200<<endl; //si la acierta aumenta el premio
														cout<<"Vamos a la siguiente pregunta"<<endl;
														Q++; //Q aumenta para la pregunta 7
														system("pause");
														system("cls");
														
														while(Q<=15 && k==1){
															system("color 60");
															cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 7
															cout<<endl;
															cout<<"Es para referirse a encontrar algo en tercera persona:\n\na) Haya\nb) Halla\nc) Alla\nd) Ahi\n"
															"e) Me retiro con $"<<premio+1200<<endl;
															cout<<"Opcion: ";cin>>selec;
															
															if(selec=='b'){
																cout<<"Corecctoo!! ya tienes: $"<<premio+1400<<endl; //el premio vuelve a aumentar al contestar bien la pregunta
																cout<<"Vamos a la siguiente pregunta"<<endl;
																Q++; //Q aumenta para la pregunta 8
																system("pause");
																system("cls");
																
																while(Q<=15 && k==1){
																	system("color e0");
																	cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 8
																	cout<<endl;
																	cout<<"Es el cuarto planeta del sistema solar:\n\na) Urano\nb) Jupiter\nc) Mercurio\nd) Marte\n"
																	"e) Me retiro con $"<<premio+1400<<endl;
																	cout<<"Opcion: ";cin>>selec;
																	
																	if(selec=='d'){
																		cout<<"Corecctoo!! ya tienes: $"<<premio+1900<<endl; //si la acierta aumenta mas el premio
																		cout<<"Vamos a la siguiente pregunta"<<endl;
																		Q++; //Q aumenta para la pregunta 9
																		system("pause");
																		system("cls");
																		
																		while(Q<=15 && k==1){
																			system("color e0");
																			cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 9
																			cout<<endl;
																			cout<<"Todo bien? Todo correcto?, es una frase de:\n\na) HolaSoyGerman\nb) Fernanfloo\nc) El Rubius OMG\n"
																			"d) Auronplay\ne) Me retiro con $"<<premio+1900<<endl;
																			cout<<"Opcion: ";cin>>selec;
																			
																			if(selec=='d'){
																				cout<<"Corecctoo!! ya tienes: $"<<premio+2400<<endl; //si la acierta aumenta el premio aun mas
																				cout<<"Vamos a la siguiente pregunta"<<endl;
																				Q++; //Q aumenta para la pregunta 10
																				system("pause");
																				system("cls");
																				
																				while(Q<=15 && k==1){
																					system("color 90");
																					cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 10
																					cout<<endl;
																					cout<<"Es una de las 7 maravillas del mundo moderno:\n\na) El Coliseo de Roma, Italia\n"
																					"b) La Estatua de la Libertad, EE.UU\nc) El Salvador del Mundo, El Salvador\n"
																					"d) El Rio Lempa, El Salvador\ne) Me retiro con $"<<premio+2400<<endl;
																					cout<<"Opcion: ";cin>>selec;
																					
																					if(selec=='a'){
																						cout<<"Corecctoo!! ya tienes: $"<<premio+3100<<endl; //premio vuelve a aumentar porque la 
																						cout<<"Vamos a la siguiente pregunta"<<endl;		//contesto bien
																						Q++; //Q aumenta a la pregunta 11
																						system("pause");
																						system("cls");
																						//se le dice al usuario que llego a la segunda zona segura
																						cout<<"Has llegado a la segunda zona segura, has acertado 10 preguntas!\n"
																						"De aqui en adelante si pierdes ya tienes asegurado $3200"<<endl;
																						system("pause");
																						system("cls");
																						
																						while(Q<=15 && k==1){
																							system("color 80");
																							cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 11
																							cout<<endl;
																							pregunta11();
																							cout<<"Opcion: ";cin>>selec;
																							
																							if(selec=='a'){   //premio aumenta mas si acierta la pregunta
																								cout<<"Corecctoo!! ya tienes: $"<<premio+3600<<endl;
																								cout<<"Vamos a la siguiente pregunta"<<endl;
																								Q++; //Q aumenta para la pregunta 12
																								system("pause");
																								system("cls");
																								
																								while(Q<=15 && k==1){
																									system("color e0");
																									cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 12
																									cout<<endl;
																									//se llama a una funcion que tiene la pregunta doce ya que por motivos de espacio 
																									pregunta12();  //se puso mejor en una funcion  para luego llamarla
																									cout<<"Opcion: ";cin>>selec;
																									
																									if(selec=='d'){  //aumenta el premio si acierta la pregunta
																										cout<<"Corecctoo!! ya tienes: $"<<premio+3900<<endl;
																										cout<<"Vamos a la siguiente pregunta"<<endl;
																										Q++; //Q aumenta a la pregunta 13
																										system("pause");
																										system("cls");
																										
																										while(Q<=15 && k==1){
																											system("color a0");
																											cout<<"Pregunta "<<Q<<":"<<endl; //pregunta 13
																											cout<<endl;
																											pregunta13(); //se llama a otra funcion que contiene la pregunta 13
																											cout<<"Opcion: ";cin>>selec;
																											
																											if(selec=='b'){ //el premio aumenta mas si la acierta
																												cout<<"Corecctoo!! ya tienes: $"<<premio+4400<<endl;
																												cout<<"Vamos a la siguiente pregunta"<<endl;
																												Q++; //Q aumenta a la pregunta 14
																												system("pause");
																												system("cls");
																												
																												while(Q<=15 && k==1){
																													system("color 90");
																													cout<<"Pregunta "<<Q<<":"<<endl;//pregunta 14
																													cout<<endl;
																													pregunta14(); //se llama a la pregunta 14
																													cout<<"Opcion: ";cin>>selec;
																													
																													if(selec=='c'){ //el premio aumenta mas
																														cout<<"Corecctoo!! ya tienes: $"<<premio+4900<<endl;
																														cout<<"Vamos a la siguiente pregunta"<<endl;
																														Q++; //Q aumenta a la pregunta 15
																														system("pause");
																														system("cls");
																														
																														while(Q<=15 && k==1){
																															system("color 30");
																															cout<<"Pregunta "<<Q<<":"<<endl;//pregunta 15
																															cout<<endl;
																															pregunta15();//se llama a la funcion de la pregunta 15
																															cout<<"Opcion: ";cin>>selec;
																															 //se imprime en pantalla que ha pasado todas las preguntas
																															if(selec=='b'){ //y se lleva el premio mayor
																																cout<<"FELICIDADES!! TE LLEVAS EL PREMIO MAYOR: $"<<premio+9900<<endl;
																																//se crea un archivo donde se guarda que ha contestado todas las preguntas y gano el
																																//premio mayor
																																time_t   t,x;																																
																																char *fecha;																																
																																x = time (&t);																																
																																fecha = ctime (&x);  
																																
																																ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app); //se crea el archivo																															
																																if (millon.is_open()){																																	
																																	millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																																	millon<<"CONTESTASTE TODAS LAS PREGUNTAS Y GANASTE EL PREMIO MAYOR!!! "<<premio+9900<<endl;																																
																																	for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																																		millon<<"_";
																																	}
																																	millon<<endl;
																																	millon.close(); //se cierra el archivo creado																															
																																}																																																														
																																else {																														
																																	cout<<"No se puede abrir el archivo o no existe"<<endl;																																	
																																}
																																
																																Q++; //Q llega a mas de 15 y termina el while
																																for (int i=0;i<100;i++){ //for que cambia el color de fondo de la consola con varios colores
																																	system("color e0"); //cuando gana el usuario
																																	system("color 30");
																																}																																
																																system("pause");
																																system("cls");																																																																
																																break;
																															}
																															
																															else if(selec=='a' || selec=='c' || selec=='d'){
																																system("color 4f");
																																cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+3100<<endl; //se muestra cuando el usuario pierde
																																//si el usuario pierde en la ultima pregunta se guarda en el mismo archivo antes creado
																																//la informacion de que ha perdido 
																																time_t   t,x;
																																char *fecha;																																			
																																x = time (&t);																																
																																fecha = ctime (&x);  
																																
																																ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																																
																																if (millon.is_open()){	
																																	millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																																	millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
																																	for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																																		millon<<"_";
																																	}
																																	millon<<endl;
																																	millon.close(); //se cierra el archivo creado																													
																																}																																																																
																																else {																																	
																																	cout<<"No se puede abrir el archivo o no existe"<<endl;																																	
																																}
																																
																																system("pause");
																																k--;
																																break;
																															}
																															else if(selec=='e'){
																																cout<<"Gracias por participar! Tu premio $"<<premio+4900<<endl;
																																//se crea un archivo cuando el usuario se retira en una pregunta que no sabia contestar
																																//y se guarda la informacion de en que pregunta se retiro y cuanto se llevo de premio
																																time_t   t,x;																
																																char *fecha;																													
																																x = time (&t);																										
																																fecha = ctime (&x);  
																																																										
																																ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																									
																																if (millon.is_open()){																										
																																	millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																																	millon<<"Te retiraste en la pregunta 15 con $"<<premio+4900<<endl;																										
																																	for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																																		millon<<"_";
																																	}
																																	millon<<endl;
																																	millon.close(); //se cierra el archivo creado																								
																																}																																																		
																																else {																											
																																	cout<<"No se puede abrir el archivo o no existe"<<endl;																											
																																}
																																
																																k--;
																																system("pause");
																															}																																													
																											
																															system("cls");	
																														}//while pregunta 15
																														
																													}
																													
																													else if(selec=='a' || selec=='b' || selec=='d'){
																														system("color 4f");
																														cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+3100<<endl;
																														//el usuario pierde en la pregunta 14 y se guarda en el archivo mismo creado
																														time_t   t,x;
																														char *fecha;																																	
																														x = time (&t);																														
																														fecha = ctime (&x);  
																														
																														ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																														
																														if (millon.is_open()){																															
																															millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																															millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
																															for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																																millon<<"_";
																															}
																															millon<<endl;
																															millon.close(); //se cierra el archivo creado																															
																														}																																																												
																														else {																															
																															cout<<"No se puede abrir el archivo o no existe"<<endl;																															
																														}																														
																														system("pause");
																														k--;
																														break;
																													}
																													else if(selec=='e'){
																														cout<<"Gracias por participar! Tu premio $"<<premio+4400<<endl;
																														//el usuario se retira en la pregunta 14 y se guarda en el archivo
																														time_t   t,x;																
																														char *fecha;																													
																														x = time (&t);																										
																														fecha = ctime (&x);  
																																																								
																														ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																									
																														if (millon.is_open()){																										
																															millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																															millon<<"Te retiraste en la pregunta 14 con $"<<premio+4400<<endl;																										
																															for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																																millon<<"_";
																															}
																															millon<<endl;
																															millon.close(); //se cierra el archivo creado																									
																														}																																																		
																														else {																											
																															cout<<"No se puede abrir el archivo o no existe"<<endl;																											
																														}
																														
																														k--;
																														system("pause");
																													}																																													
																									
																													system("cls");	
																												}//while pregunta 14
																												
																											}
																											
																											else if(selec=='a' || selec=='c' || selec=='d'){
																												system("color 4f");
																												cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+3100<<endl;
																												//el usuario pierde en la pregunta 13 y se guarda en el archivo
																												time_t   t,x;
																												char *fecha;																															
																												x = time (&t);																												
																												fecha = ctime (&x);  
																												
																												ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																												
																												if (millon.is_open()){																													
																													millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																													millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
																													for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																														millon<<"_";
																													}
																													millon<<endl;
																													millon.close(); //se cierra el archivo creado																											
																												}																																																								
																												else {																													
																													cout<<"No se puede abrir el archivo o no existe"<<endl;																													
																												}																												
																												system("pause");
																												k--;
																												break;
																											}
																											else if(selec=='e'){
																												cout<<"Gracias por participar! Tu premio $"<<premio+3900<<endl;
																												//el usuario se retira en la pregunta 13 y se guarda en el archivo
																												time_t   t,x;																
																												char *fecha;																													
																												x = time (&t);																										
																												fecha = ctime (&x);  
																																																						
																												ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																									
																												if (millon.is_open()){																										
																													millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																													millon<<"Te retiraste en la pregunta 13 con $"<<premio+3900<<endl;																										
																													for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																														millon<<"_";
																													}
																													millon<<endl;
																													millon.close(); //se cierra el archivo creado																										
																												}																																																		
																												else {																											
																													cout<<"No se puede abrir el archivo o no existe"<<endl;																											
																												}
																												
																												k--;
																												system("pause");
																											}																																													
																							
																											system("cls");	
																										}//while pregunta 13
																										
																									}
																									
																									else if(selec=='a' || selec=='b' || selec=='c'){
																										system("color 4f");
																										cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+3100<<endl;
																										//el usuario pierde en la pregunta 12 y se guarda en el mismo archivo
																										time_t   t,x;																
																										char *fecha;																													
																										x = time (&t);																										
																										fecha = ctime (&x);  
																																																				
																										ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																									
																										if (millon.is_open()){																										
																											millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																											millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;																										
																											for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																												millon<<"_";
																											}
																											millon<<endl;
																											millon.close(); //se cierra el archivo creado																									
																										}																																																		
																										else {																											
																											cout<<"No se puede abrir el archivo o no existe"<<endl;																											
																										}
																										
																										system("pause");
																										k--;
																										break;
																									}
																									else if(selec=='e'){
																										cout<<"Gracias por participar! Tu premio $"<<premio+3600<<endl;
																										//el usuario se retira en la pregunta 12 y se guarda en el archivo
																										time_t   t,x;
																										char *fecha;						
																										x = time (&t);			
																										fecha = ctime (&x);  
																										
																										ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
																										if (millon.is_open()){				
																											millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																											millon<<"Te retiraste en la pregunta 12 con $"<<premio+3600<<endl;				
																											for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																												millon<<"_";
																											}
																											millon<<endl;
																											millon.close(); //se cierra el archivo creado		
																										}						
																										else {				
																											cout<<"No se puede abrir el archivo o no existe"<<endl;				
																										}		
																										
																										k--;
																										system("pause");
																									}																																													
																					
																									system("cls");	
																								}//while pregunta 12
																								
																							}
																							
																							else if(selec=='b' || selec=='c' || selec=='d'){
																								system("color 4f");
																								cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+3100<<endl;
																								//el usuario pierde en la pregunta 11 y se guarda en el archivo mismo
																									time_t   t,x;
																									char *fecha;																												
																									x = time (&t);																									
																									fecha = ctime (&x);  
																									
																									ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																									
																									if (millon.is_open()){																									
																										millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																										millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
																										for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																											millon<<"_";
																										}
																										millon<<endl;
																										millon.close(); //se cierra el archivo creado																								
																									}																																																		
																									else {																										
																										cout<<"No se puede abrir el archivo o no existe"<<endl;																										
																									}
																								
																								system("pause");
																								k--;
																								break;
																							}																																													
																			
																							system("cls");	
																						}//while pregunta 11
																						
																					}
																					
																					else if(selec=='b' || selec=='c' || selec=='d'){
																						system("color 4f");
																						cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+900<<endl;
																						//el usuario pierde en la pregunta 10 y se guarda en el archivo
																						time_t   t,x;																			
																						char *fecha;																									
																						x = time (&t);																						
																						fecha = ctime (&x);  
																						
																						ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																						
																						if (millon.is_open()){																							
																							millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																							millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
																							for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																								millon<<"_";
																							}
																							millon<<endl;
																							millon.close(); //se cierra el archivo creado																					
																						}																																												
																						else {																							
																							cout<<"No se puede abrir el archivo o no existe"<<endl;																							
																						}
																						
																						system("pause");
																						k--;
																						break;
																					}
																					else if(selec=='e'){
																						cout<<"Gracias por participar! Tu premio $"<<premio+2400<<endl;
																						//el usuario se retira en la pregunta 10 y se guarda en el archivo
																						time_t   t,x;
																						char *fecha;						
																						x = time (&t);			
																						fecha = ctime (&x);  
																						
																						ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
																						if (millon.is_open()){				
																							millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																							millon<<"Te retiraste en la pregunta 10 con $"<<premio+2400<<endl;				
																							for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																								millon<<"_";
																							}
																							millon<<endl;
																							millon.close(); //se cierra el archivo creado		
																						}						
																						else {				
																							cout<<"No se puede abrir el archivo o no existe"<<endl;				
																						}	
																						
																						k--;
																						system("pause");
																					}
																						
																	
																					system("cls");	
																				}//while pregunta 10
																				
																			}
																			
																			else if(selec=='a' || selec=='b' || selec=='c'){
																				system("color 4f");
																				cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+900<<endl;
																				//el usuario pierde en la pregunta 9 y se guarda en el archivo
																				time_t   t,x;
																				char *fecha;																							
																				x = time (&t);																				
																				fecha = ctime (&x);  
																				
																				ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																				
																				if (millon.is_open()){																					
																					millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																					millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
																					for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																						millon<<"_";
																					}
																					millon<<endl;
																					millon.close(); //se cierra el archivo creado																				
																				}																																								
																				else {																					
																					cout<<"No se puede abrir el archivo o no existe"<<endl;																					
																				}
																				
																				system("pause");
																				k--;
																				break;
																			}
																			else if(selec=='e'){
																				cout<<"Gracias por participar! Tu premio $"<<premio+1900<<endl;
																				//el usuario se retira en la pregunta 9 y se guarda en el archivo
																				time_t   t,x;
																				char *fecha;						
																				x = time (&t);			
																				fecha = ctime (&x);  
																				
																				ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
																				if (millon.is_open()){				
																					millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																					millon<<"Te retiraste en la pregunta 9 con $"<<premio+1900<<endl;				
																					for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																						millon<<"_";
																					}
																					millon<<endl;
																					millon.close(); //se cierra el archivo creado			
																				}						
																				else {				
																					cout<<"No se puede abrir el archivo o no existe"<<endl;				
																				}																					
																				k--;
																				system("pause");
																			}																																			
																			system("cls");	
																		}//while pregunta 9
																		
																	}
																	
																	else if(selec=='a' || selec=='b' || selec=='c'){
																		system("color 4f");
																		cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+900<<endl;
																		//el usuario pierde en la pregunta 8 y se guarda en el archivo
																			time_t   t,x;
																			char *fecha;																						
																			x = time (&t);																			
																			fecha = ctime (&x);  
																			
																			ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																			
																			if (millon.is_open()){																				
																				millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																				millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
																				for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																					millon<<"_";
																				}
																				millon<<endl;
																				millon.close(); //se cierra el archivo creado	
																			}																																						
																			else {																				
																				cout<<"No se puede abrir el archivo o no existe"<<endl;																				
																			}																		
																		system("pause");
																		k--;
																		break;
																	}
																	else if(selec=='e'){
																		cout<<"Gracias por participar! Tu premio $"<<premio+1400<<endl;
																		//el usuario se retira en la pregunta 8 y se guarda en el archivo
																		time_t   t,x;
																		char *fecha;						
																		x = time (&t);			
																		fecha = ctime (&x);  
																		
																		ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
																		if (millon.is_open()){				
																			millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																			millon<<"Te retiraste en la pregunta 8 con $"<<premio+1400<<endl;				
																			for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																				millon<<"_";
																			}
																			millon<<endl;
																			millon.close(); //se cierra el archivo creado		
																		}						
																		else {				
																			cout<<"No se puede abrir el archivo o no existe"<<endl;				
																		}																												
																		k--;
																		system("pause");
																	}																															
																	system("cls");	
																}//while pregunta 8
																
															}															
															else if(selec=='a' || selec=='c' || selec=='d'){
																system("color 4f");
																cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+900<<endl;
																//el usuario pierde en la pregunta 7 y se guarda en el archivo
																time_t   t,x;
																char *fecha;																			
																x = time (&t);																
																fecha = ctime (&x);  
																
																ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);																
																if (millon.is_open()){																	
																	millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																	millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
																	for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																		millon<<"_";
																	}
																	millon<<endl;
																	millon.close(); //se cierra el archivo creado	
																}																																
																else {																	
																	cout<<"No se puede abrir el archivo o no existe"<<endl;																	
																}				
																
																system("pause");
																k--;
																break;
															}
															else if(selec=='e'){
																cout<<"Gracias por participar! Tu premio $"<<premio+1200<<endl;
																//el usuario se retira en la pregunta 7 y se guarda en el archivo mismo
																time_t   t,x;
																char *fecha;						
																x = time (&t);			
																fecha = ctime (&x);  
																
																ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
																if (millon.is_open()){				
																	millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
																	millon<<"Te retiraste en la pregunta 7 con $"<<premio+1200<<endl;				
																	for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																		millon<<"_";
																	}
																	millon<<endl;
																	millon.close(); //se cierra el archivo creado			
																}						
																else {				
																	cout<<"No se puede abrir el archivo o no existe"<<endl;				
																}																
																k--;
																system("pause");
															}																											
															system("cls");	
														}//while pregunta 7
														
													}
													
													else if(selec=='a' || selec=='b' || selec=='d'){
														system("color 4f");
														cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio+900<<endl;
														//el usuario pierde en la pregunta 6 y se guarda en el archivo
															time_t   t,x;
															char *fecha;																		
															x = time (&t);															
															fecha = ctime (&x);  
															
															ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);															
															if (millon.is_open()){																
																millon<<"Jugador: "<<name<<endl;
																millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
																for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
																	millon<<"_";
																}
																millon<<endl;
																millon.close(); //se cierra el archivo creado																
															}																														
															else {																
																cout<<"No se puede abrir el archivo o no existe"<<endl;																
															}														
														system("pause");
														k--;
														break;
													}
														
													system("cls");	
												}//while pregunta 6
												
											}
											
											else if(selec=='a' || selec=='b' || selec=='d'){
												system("color 4f");
												cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio-100<<endl;
												//el usuario pierde en la pregunta 5 y se guarda en el archivo creado
												time_t   t,x;
												char *fecha;																		
												x = time (&t);															
												fecha = ctime (&x);  
																											
												ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);															
												if (millon.is_open()){													
													millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
													millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
													for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
														millon<<"_";
													}
													millon<<endl;
													millon.close(); //se cierra el archivo creado														
												}																														
												else {																
													cout<<"No se puede abrir el archivo o no existe"<<endl;																
												}												
												system("pause");
												k--;
												break;
											}
											else if(selec=='e'){
												cout<<"Gracias por participar! Tu premio $"<<premio+400<<endl;
												//el usuario se retira en la preunta 5 y se guarda en el archivo
												time_t   t,x;
												char *fecha;						
												x = time (&t);			
												fecha = ctime (&x);  
												
												ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
												if (millon.is_open()){				
													millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
													millon<<"Te retiraste en la pregunta 5 con $"<<premio+400<<endl;				
													for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
														millon<<"_";
													}
													millon<<endl;
													millon.close(); //se cierra el archivo creado				
												}						
												else {				
													cout<<"No se puede abrir el archivo o no existe"<<endl;				
												}												
												k--;
												system("pause");
											}																			
											system("cls");	
										}//while pregunta 5
										
									}
									
									else if(selec=='b'){
										system("color 4f");
										cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio-100<<endl;
										//el usuario pierde en la preugnta 4 y se guarda en el archivo
										time_t   t,x;							
										char *fecha;													
										x = time (&t);										
										fecha = ctime (&x);  
										
										ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);										
										if (millon.is_open()){											
											millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
											millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
											for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
												millon<<"_";
											}
											millon<<endl;
											millon.close(); //se cierra el archivo creado										
										}																				
										else {											
											cout<<"No se puede abrir el archivo o no existe"<<endl;											
										}										
										system("pause");
										k--;
										break;
									}
									else if(selec=='c'){
										cout<<"Gracias por participar! Tu premio $"<<premio+200<<endl;
										//el usuario se retira en la pregunta 4 y se guarda en el archivo
										time_t   t,x;
										char *fecha;						
										x = time (&t);			
										fecha = ctime (&x);  
										
										ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
										if (millon.is_open()){				
											millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
											millon<<"Te retiraste en la pregunta 4 con $"<<premio+200<<endl;				
											for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
												millon<<"_";
											}
											millon<<endl;
											millon.close(); //se cierra el archivo creado	
										}						
										else {				
											cout<<"No se puede abrir el archivo o no existe"<<endl;				
										}										
										k--;
										system("pause");
										break;
									}														
									system("cls");	
								}//while pregunta 4								
							}
							
							else if(selec=='a' || selec=='c' || selec=='d'){
								system("color 4f");
								cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio-100<<endl;
								//el usuario pierde en la pregunta 3 y se guarda en el archivo
								time_t   t,x;					
								char *fecha;											
								x = time (&t);								
								fecha = ctime (&x);  
								
								ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);								
								if (millon.is_open()){									
									millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
									millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
									for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
										millon<<"_";
									}
									millon<<endl;
									millon.close(); //se cierra el archivo creado									
								}																
								else {									
									cout<<"No se puede abrir el archivo o no existe"<<endl;									
								}								
								system("pause");
								k--;
								break;
							}
							else if(selec=='e'){
								cout<<"Gracias por participar! Tu premio $"<<premio+100<<endl;
								//el usuario se retira en la pregunta 3 y se guarda en el archivo creado
								time_t   t,x;
								char *fecha;						
								x = time (&t);			
								fecha = ctime (&x);  
								
								ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
								if (millon.is_open()){				
									millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;							
									millon<<"Te retiraste en la pregunta 3 con $"<<premio+100<<endl;				
									for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
										millon<<"_";
									}
									millon<<endl;
									millon.close(); //se cierra el archivo creado				
								}						
								else {				
									cout<<"No se puede abrir el archivo o no existe"<<endl;				
								}
								
								system("pause");
								k--;
								break;
							}											
							system("cls");	
						}//while pregunta 3						
					}
					
					else if(selec=='b' || selec=='c' || selec=='d'){
						system("color 4f");
						cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio-100<<endl;
					//el usuario pierde en la pregunta 2 y se guarda en el archivo creado	
					time_t   t,x;		
					char *fecha;								
					x = time (&t);					
					fecha = ctime (&x);  
					
					ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);					
					if (millon.is_open()){						
						millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
						millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;
						for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
							millon<<"_";
						}
						millon<<endl;
						millon.close(); //se cierra el archivo creado				
					}										
					else {						
						cout<<"No se puede abrir el archivo o no existe"<<endl;						
					}						
						system("pause");
						k--;
						break;
					}
					else if(selec=='e'){
						cout<<"Gracias por participar! tu premio $"<<premio<<endl;
						//el usuario se retira en la pregunta 2 y se guarda en el archivo
						time_t   t,x;
						char *fecha;						
						x = time (&t);			
						fecha = ctime (&x);  
						
						ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
							millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
							millon<<"Te retiraste en la pregunta 2 con $"<<premio<<endl;				
							for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
								millon<<"_";
							}
							millon<<endl;
							millon.close(); //se cierra el archivo creado			
						}						
						else {				
							cout<<"No se puede abrir el archivo o no existe"<<endl;				
						}
						
						system("pause");
						k--;
						break;
					}							
					system("cls");	
				}//while pregunta 2						
		else if(selec=='b' || selec=='c' || selec=='d'){
			system("color 4f");
			cout<<"Uuuh, fallaste. Has perdido!. Te llevas $"<<premio-100<<endl;
			//el usuario pierde en la pregunta 1 y se guarda en el archivo
			time_t   t,x;
			char *fecha;						
			x = time (&t);			
			fecha = ctime (&x);  
			
			ofstream millon("QUIEN QUIERE SER MILLONARIO.txt",ios_base::app);			
			if (millon.is_open()){				
				millon<<"Jugador: "<<name<<"				Fecha: "<<fecha<<endl;
				millon<<"La ultima vez perdiste en la pregunta "<<Q<<endl;				
				for(int i=0;i<120;i++){ //crea una linea en el archivo entre cada jugador
					millon<<"_";
				}
				millon<<endl;
				millon.close(); //se cierra el archivo creado				
			}						
			else {				
				cout<<"No se puede abrir el archivo o no existe"<<endl;				
			}			
			system("pause");
			break;
		}
		else{			
			cout<<"Elige una opcion existente"<<endl;			
		}
		system("cls");
	} //while pregunta 1
	
	
}

//funciones que contiene las ultimas 5 preguntas que por motivos de espacio se pusieron en una funcion

void pregunta11(){
	cout<<"Juego donde no se usa una pelota:\n\na) Hockey\nb) Soccer\nc) Ping Pong\nd) Pool"<<endl;
}

void pregunta12(){
	cout<<"Es una de las frases comunes de Argentina:\n\na) Que chivo!\nb) No mames!\nc) Ostia\nd) Que quilombo!\ne) Me retiro con $3700"<<endl;
}

void pregunta13(){
	cout<<"Pijin es una palabra de:\n\na) Guatemala\nb) Honduras\nc) Nicaragua\nd) Colombia\ne) Me retiro con $4000"<<endl;
}

void pregunta14(){
	cout<<"A que reino pertenecen los hongos?\n\na) Reino Protista\nb) Reino Animal\nc) Reino Fungi\nd) Reino Archaea\ne) Me retiro con $4500"<<endl;
}

void pregunta15(){
	cout<<"Es una funcion para las salidas de C:\n\na) print\nb) printf\nc) cout\nd) cin\ne) Me retiro con $5000"<<endl;
}

void nivelesM(){
	cout<<"La pregunta 5 y 10 son zonas seguras, si logras contestarlas ya tendras asegurado el\n"
	"premio que tienen."<<endl;
	cout<<endl;
	cout<<"01- $100\n02- $200\n03- $300\n04- $500\n05- $1,000 zona segura\n06- $1,300\n07- $1,500\n08- $2,000\n09- $2,500\n10- $3,200 zona segura\n11- $3,700\n12- $4,000\n"
	"13- $4,500\n14- $5,000\n15- $10,000 premio mayor\n"<<endl;
}
