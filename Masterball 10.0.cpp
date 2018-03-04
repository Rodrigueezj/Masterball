#include <iostream>

using namespace std;

int main()
{
	//print masterball
	unsigned int x,y;
	int mB[4][8]{{1,2,3,4,5,6,7,8},
				 {1,2,3,4,5,6,7,8},
				 {1,2,3,4,5,6,7,8},
				 {1,2,3,4,5,6,7,8}};
	string repetir;
	cout<<"Let's move the Masterball. \n\n"
		<<"If during the proccess you type negative values, the program will not work properly. \n\n";
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
	cout<<"\n1 to move the masterball to the left."
		<<"\n2 to move the masterball to the right."
		<<"\n3 to move the masterball vertically.\n\n";
	cin>>opcion;
		while(opcion!=1 && opcion!=2 && opcion!=3)
		{
			cout<<"type a valid option."<<endl;
			cin>>opcion;
		}
	switch(opcion)
	{
        case 1:
		{
			cout<<"\n"<<"\xA8"<<"Which of the four rows? \n\n";
			cin>> in;		
			f[(in - 1)%4] = 1;
			cout<<"\n"<<"\xA8"<<"Hoy many times? \n\n";
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
			cout<<"\n"<<"\xA8"<<"Which of the four rows? \n\n";
			cin>>in;
			f[(in - 1)%4] = 1;
			cout<<"\n"<<"\xA8"<<"Hoy many times? \n\n";
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

			cout<<"-Keep in mind that in order to do a vertical movement in the masteball, rows have to be aligned.\n"
			    <<"-Also, at moving a column, you will move the 3 thar are at the right side due to its tridimensional structure.\n";
			cout<<"\n"<<"\xA8"<<"Cu"<<"\xA0"<<"l de las ocho columnas? \n\n";
			cin>>ol;
			c[(ol-1)%8]=1;
			//c[(ol+3)%8]=1;
			cout<<"\n"<<"\xA8"<<"How many times? \n\n";
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
						//column chosen 				
						for(y=0; y<4;y++)
						{
							temp[y]=mB[3-y][j%8];
						}
						//second column
						for(x=4; x<8; x++)
						{
							temp[x]=mB[3+(4-x)][(j+1)%8];				
						}				
						//thid column
						for(z=0; z<4;z++)
						{
							arreglo[z]=mB[3-z][(j+2)%8];
						}
						//fourth column
						for(a=4; a<8; a++)
						{
							arreglo[a]=mB[3+(4-a)][(j+3)%8];				
						}	
						//equivalences
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
		cout<<"\n"<<"\xA8"<<"Do you want to do another movement?\n\ntype -yes- to do another movement, type -no- to exit.\n\n";	
		cin>>repetir;
	}while (repetir=="yes");
return(0);
}
