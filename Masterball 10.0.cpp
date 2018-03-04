#include <iostream>

using namespace std;

int main()
{
	//imprimir masterball
	unsigned int x,y;
	int mB[4][8]{{1,2,3,4,5,6,7,8},
				 {1,2,3,4,5,6,7,8},
				 {1,2,3,4,5,6,7,8},
				 {1,2,3,4,5,6,7,8}};
	string repetir;
	cout<<"Vamos a mover la Master Ball. \n\n"
		<<"Si durante el proceso digita valores diferentes a los enteros positivos, "
		<<"\x82"<<"ste se realizar"<<"\xA0"<<" de manera err"<<"\xA2"<<"nea. \n\n";
	for(x=0;x<=3;x++)
	{
		for(y=0;y<=7;y++)
		{
			cout<<mB[x][y]<<"\t";
		}
		cout<<"\n";
	}
	do
	{
	unsigned int f[4]={0},m[4],i,j,in,opcion,ol,c[8],w,a,z;
	cout<<"\n1 para mover la masterball hacia la izquierda."
		<<"\n2 para mover la masterball hacia la derecha."
		<<"\n3 para mover la masterball verticalmente.\n\n";
	cin>>opcion;
		while(opcion!=1 && opcion!=2 && opcion!=3)
		{
			cout<<"ingrese una opcion valida."<<endl;
			cin>>opcion;
		}
	switch(opcion)
	{
        case 1:
		{
			cout<<"\n"<<"\xA8"<<"Cu"<<"\xA0"<<"l de las cuatro filas? \n\n";
			cin>> in;		
			f[(in - 1)%4] = 1;
			cout<<"\n"<<"\xA8"<<"Cuant"<<"\xA0"<<"s veces? \n\n";
			cin>>m[0];
			for(int i = 0; i < 4; i++)
			{
				if(f[i] == 1)
				{		
					y=m[0]%8;
					w=y;
					int temp[8];
					for(y;y<=7;y++)
					{
						temp[y - w] = mB[i][y]; 
					}
					y = m[0]%8;
					for( z=0;z<w;z++)
					{
						temp[8 - y + z] = mB[i][z];	
					}
					for(int j = 0; j < 8; j++)
					{
						mB[i][j] = temp[j];
					}		
				}
			}	
			cout<<"\n";
			for(i=0; i<4; i++)
			{
				for(j=0; j<8; j++)
				{
					cout<<mB[i][j]<<"\t";
				}
			cout<<"\n";
			}	
			break;
		}
		case 2:	
		{
			cout<<"\n"<<"\xA8"<<"Cu"<<"\xA0"<<"l de las cuatro filas? \n\n";
			cin>>in;
			f[(in - 1)%4] = 1;
			cout<<"\n"<<"\xA8"<<"Cu"<<"\xA0"<<"ntas veces? \n\n";
			cin>>m[1];
			for(i = 0; i < 4; i++)
			{
				if(f[i] == 1)
				{
					w = -(m[1] % 8-8);
					int temp[8];
					for(int y=w;y<=7;y++)
					{
						temp[-(w-y)] = mB[i][y]; 
					}
					w = m[1] % 8;
					y = m[1] % 8;
					for( z=8-(8-w);z<8;z++)
					{
						temp[z] = mB[i][-(8-(8-w)-z)];	
					}
					for(int j = 0; j < 8; j++)
					{
						mB[i][j] = temp[j];
					}
				}	
			}
			cout<<"\n";
			for(i=0; i<4; i++)
			{
				for(j=0; j<8; j++)
				{
				cout<<mB[i][j]<<"\t";
				}
				cout<<"\n";
			}	
			break;
		}
		case 3:
		{

			cout<<"-Tenga en cuenta que para hacer un movimiento vertical la masterball girar"<<"\xA0"<<" 180"<<"\xF8"<<" para que las divisiones se alineen y se pueda ejecutar el movimiento horizontal.\n"
			    <<"-Adem"<<"\xA0"<<"s al mover una columna, tambi"<<"\x82"<<"n mover"<<"\xA0"<<" las 3 que se encuentren al lado derecho de "<<"\x82"<<"sta debido a su estructura\n tridimensional.\n";
			cout<<"\n"<<"\xA8"<<"Cu"<<"\xA0"<<"l de las ocho columnas? \n\n";
			cin>>ol;
			c[(ol-1)%8]=1;
			//c[(ol+3)%8]=1;
			cout<<"\n"<<"\xA8"<<"Cuant"<<"\xA0"<<"s veces? \n\n";
			cin>>m[2];
			w = -(m[2] % 8-8);
			for(int j = 0; j < 8; j++)
			{
				if(c[j]==1)
				{
					if(m[2]%2==0)
					{
						for(i=0; i<4; i++)
						{
							for(j=0; j<8; j++)
							{
								cout<<mB[i][j]<<"\t";
							}
							cout<<"\n";
						}	
					}
					else
					{
						y=c[j];
						w= y;
						int temp[8],arreglo[8];
						//columna elejida 				
						for(y=0; y<4;y++)
						{
							temp[y]=mB[3-y][j%8];
						}
						//segunda columna
						for(x=4; x<8; x++)
						{
							temp[x]=mB[3+(4-x)][(j+1)%8];				
						}				
						//tercera columna
						for(z=0; z<4;z++)
						{
							arreglo[z]=mB[3-z][(j+2)%8];
						}
						//cuarta columna
						for(a=4; a<8; a++)
						{
							arreglo[a]=mB[3+(4-a)][(j+3)%8];				
						}	
						//equivalencias
						for(int i=0;i<4;i++)
						{
							mB[i][(j+3)%8]=temp[i];
						}	
						for(int x = 4; x < 8; x++)
						{
							mB[x-4][(j+2)%8]=temp[x];
						}
						for(int z = 0; z < 4; z++)
						{
							mB[z][(j+1)%8]=arreglo[z];
						}
						for(int a=4;a<8;a++)
						{
							mB[a-4][(j)%8]=arreglo[a];
						}
						for(int i=0; i<4; i++)
						{
							for(j=0; j<8; j++)
							{
								cout<<mB[i][j]<<"\t";
							}
							cout<<"\n";
						}						
					}				
				}
			}
			break;
		}
	}
		cout<<"\n"<<"\xA8"<<"Desea hacer otro movimiento?\n\nEscriba -si- para hacer otro movimiento, escriba -no- para salir.\n\n";	
		cin>>repetir;
	}while (repetir=="si");
return(0);
}
