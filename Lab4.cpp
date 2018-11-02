
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


// #include <stlib.h>

//Crea la matriz 3x3
int*** crearCubo();

//inicializa la matriz
void llenarMatriz(int***);

//Imprime una matriz 
void printCubo(int***);

//liberar la  matriz 
void liberarCubo(int***);

//Llena el tablero con barcos aleatorios
void barquitos(int***);

//Ataques
void Normal(int***,int,int,int);
//Ataques Wave
void XY(int***,int);
void XZ(int***,int);
void YZ(int***,int);

//
void Expansive(int***,int,int,int);

//Muestra los barcos del Jugador
void mostrarbarcos(int***);

int main(){
    srand(time(NULL));
    int tam=12;
    int*** cubo=crearCubo();
    llenarMatriz(cubo);
    barquitos(cubo);
    int*** cubo2=crearCubo();
    llenarMatriz(cubo2);
    barquitos(cubo2);
    // printCubo(cubo);
    bool t=true;
    int turno=1;
    //ataques
    int wave_1=3;
    int wave_2=3;
    while(t){
        if(turno%2!=0){
            cout<<"Mapa de submarinos del Jugador 1"<<endl;        
            mostrarbarcos(cubo);
            cout<<endl;
            cout<<"----------MENU DE ATAQUES----------"<<endl;
            cout<<"1) Ataque Normal"<<endl;
            cout<<"2) Ataque wave en XY"<<endl;
            cout<<"3) Ataque wave en XZ"<<endl;
            cout<<"4) Ataque wave en YZ"<<endl;
            cout<<"5) Ataque Expansive"<<endl;
            int des;
            cin>>des;
            if(des==1){
                int x,y,z;
                cout<<"Ingrese la coordenada en x:"<<endl;
                cin>>x;
                cout<<"Ingrese la coordenada en y:"<<endl;
                cin>>y;
                cout<<"Ingrese la coordenada en z:"<<endl;
                cin>>z;
                if(x<0||x>11){
                cout<<"Dato no valido"<<endl;
                }else if(y<0||y>11){
                cout<<"Dato no valido"<<endl;
                }else if(z<0||z>11){
                cout<<"Dato no valido"<<endl;
                }else{
                Normal(cubo2,x,y,z);
                turno++;
                }
            }else if(des==2&&wave_1>0){
                cout<<"Ingrese la coordenada en Z:";
                int z;
                cin>>z;
                if(z<0||z>11){
                    cout<<"Dato no valido";
                }else{
                    XY(cubo2,z);
                    turno++;
                    wave_1--;
                }
            }else if(des==3&&wave_1>0){
                cout<<"Ingrese la coordenada en Y:";
                int y;
                cin>>y;
                if(y<0||y>11){
                    cout<<"Dato no valido";
                }else{
                    XZ(cubo2,y);
                    turno++;
                    wave_1--;
                }
            }else if(des==4&&wave_1>0){
                cout<<"Ingrese la coordenada en X:";
                int x;
                cin>>x;
                if(x<0||x>11){
                    cout<<"Dato no valido";
                }else{
                    YZ(cubo2,x);
                    turno++;
                    wave_1--;
                }
            }else if(des==5){
                turno++;
            }else{
            cout<<"Dato no Valido"<<endl;
            t=false;
            }


        }else{
            cout<<"Mapa de submarinos del Jugador 2"<<endl; 
            mostrarbarcos(cubo2);

            cout<<endl;
            cout<<"----------MENU DE ATAQUES----------"<<endl;
            cout<<"1) Ataque Normal"<<endl;
            cout<<"2) Ataque wave en XY"<<endl;
            cout<<"3) Ataque wave en XZ"<<endl;
            cout<<"4) Ataque wave en YZ"<<endl;
            cout<<"5) Ataque Expansive"<<endl;
            int des;
            cin>>des;
            if(des==1){
                int x,y,z;
                cout<<"Ingrese la coordenada en x:"<<endl;
                cin>>x;
                cout<<"Ingrese la coordenada en y:"<<endl;
                cin>>y;
                cout<<"Ingrese la coordenada en z:"<<endl;
                cin>>z;
                if(x<0||x>11){
                cout<<"Dato no valido"<<endl;
                }else if(y<0||y>11){
                cout<<"Dato no valido"<<endl;
                }else if(z<0||z>11){
                cout<<"Dato no valido"<<endl;
                }else{
                Normal(cubo,x,y,z);
                turno++;
                }
            }else if(des==2&&wave_2>0){
                cout<<"Ingrese la coordenada en Z:";
                int z;
                cin>>z;
                if(z<0||z>11){
                    cout<<"Dato no valido";
                }else{
                    XY(cubo,z);
                    turno++;
                    wave_2--;
                }

            }else if(des==3&&wave_2>0){
                cout<<"Ingrese la coordenada en Y:";
                int y;
                cin>>y;
                if(y<0||y>11){
                    cout<<"Dato no valido";
                }else{
                    XZ(cubo,y);
                    turno++;
                    wave_2--;

                }

            }else if(des==4&&wave_2>0){
                cout<<"Ingrese la coordenada en X:";
                int x;
                cin>>x;
                if(x<0||x>11){
                    cout<<"Dato no valido";
                }else{
                    YZ(cubo,x);
                    turno++;
                    wave_2--;

                }
            }else if(des==5){
                
            }else{
            cout<<"Dato no Valido"<<endl;
            t=false;
            }

        }

    }
    liberarCubo(cubo);
    return 0;
}

int*** crearCubo(){
    int*** cubo=new int**[12];
    for(int i=0;i<12;i++){
        cubo[i]=new int*[12];
    }
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            cubo[i][j]=new int[12];
        }
    }

    return cubo;
}

void llenarMatriz(int*** cubo){
 
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            for(int z=0;z<12;z++){
                cubo[i][j][z]=0;
            }
        }
    }
    
}

void printCubo(int*** cubo){
  for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            for(int z=0;z<12;z++){
               cout<<" "<<cubo[i][j][z];
            }
        cout<<endl;
        }
    cout<<endl;
    cout<<endl;
    }
cout<<endl;
}

void liberarCubo(int*** mat){
	for(int i=0;i<12;i++){
		for(int j=0;j<3;j++){	
			delete [] mat[i][j];	
			mat[i][j] = NULL;
		}
	}

	for(int i=0;i<12;i++){
		delete[] mat[i];
		mat[i] =NULL;
	}
	delete[]mat;
}

void barquitos(int*** cubo){
   for(int i=0;i<15;i++){   
    int a,b,c;
    a=rand() % 11;
    b=rand() % 11;
    c=rand() % 11;       
    while(cubo[a][b][c]!=0){
        a=rand() % 11;
        b=rand() % 11;
        c=rand() % 11; 
    }
    if(cubo[a][b][c]==0){
      cubo[a][b][c]=1;

     }     
        
    }
}

void Normal(int*** cubo,int x,int y,int z){
    if(cubo[x][y][z]==1){
         cout<<"Destruyo un barco en la posicion x: "<<x<<" y: "<<y<<" z: "<<z;
         cout<<endl;
         cubo[x][y][z]=0;
    }else if(cubo[x][y][z]==0){
         cout<<"Nada que destruir"<<endl;
    }       

}

void Expansive(int*** cubo,int x,int y,int z){



}

void mostrarbarcos(int*** cubo){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            for(int z=0;z<12;z++){
               if(cubo[i][j][z]==1){
                    cout<<"("<<i<<","<<j<<","<<z<<")"<<endl;
                }
            }
        
        }
    }
}

void XY(int*** cubo,int z){
//[x][y][z]
//[i][j][z]
    for(int i=0;i<12;i++){
        for(int j=0;i<12;j++){
            if(cubo[i][j][z]==1){
                 cout<<"Destruyo un barco en la posicion x: "<<i<<" y: "<<j<<" z: "<<z;
                 cout<<endl;
                 cubo[i][j][z]=0;
            }else{
                cout<<"No destruyo nada"<<endl;
            } 
        }
    }

}
void XZ(int*** cubo,int y){
//[x][y][z]
//[i][y][j]
    for(int i=0;i<12;i++){
        for(int j=0;i<12;j++){
            if(cubo[i][y][j]==1){
                 cout<<"Destruyo un barco en la posicion x: "<<i<<" y: "<<y<<" z: "<<j;
                 cout<<endl;
                 cubo[i][y][j]=0;
            }else{
                cout<<"No destruyo nada"<<endl;
            }

        }
    }

}

void YZ(int*** cubo,int x){
//[x][y][z]
//[x][i][j]
    for(int i=0;i<12;i++){
        for(int j=0;i<12;j++){
            if(cubo[x][i][j]==1){
                 cout<<"Destruyo un barco en la posicion x: "<<x<<" y: "<<i<<" z: "<<j;
                 cout<<endl;
                 cubo[x][i][j]=0;
            }else{
                cout<<"No destruyo nada"<<endl;
            }

        }
    }

}




