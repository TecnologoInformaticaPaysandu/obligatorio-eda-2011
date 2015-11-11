#include<iostream.h>
#include<conio.h>
#include<string.h>

typedef struct nodo 
{ 
  int numP;
  char dato[25];
  nodo *sig;
} palabra;

typedef struct NODO
{
       int numF;
       palabra *primero;
       NODO *sig;
} fila;

//operaciones con lineas
void insertar_fila_final(fila **);// 1)insertar linea vacia al final
void insertar_fila_posicion(int, fila **);// 2)insertar linea vacia en una posicion
void borrar_fila(int, fila **);// 3)borrar linea en una posicion
void borrar_todo(fila **);// 4)borrar todas las lineas
void imprimir_fila(int, fila **);// 10)imprime la linea indicada
void imprimir_texto(fila **);// 6)imprimir todo el texto

//operaciones con palabras
void borrar_palabras_todas(fila **);// 5)borra todas las ocurrencias de una palabra en el texto
void insertar_palabra(int, int, fila **);// 7)insertar palabra en una linea
void borrar_palabra(int, int, fila **);// 8)borrar palabra en una posicion
void borrar_palabras_fila(int, fila**);// 9)borrar todas las ocurrencias de una palabra en una linea

int cant_filas(fila **);
int cant_palabras(int, fila**);
void cargar_palabra();

const int largo=5;
char pal[25];

main()
{
      int opcion, x, y;
      char c;
      fila* L=NULL;
      
      
      do{
          system("cls");
          cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MENU <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
          cout<<"\n1) Inserta una nueva linea vacia al final del texto";
          cout<<"\n2) Inserta una nueva linea vacia en la posicion indicada";
          cout<<"\n3) Borra la linea en la posicion indicada";
          cout<<"\n4) Borra todas las lineas del texto";
          cout<<"\n5) Borra todas las ocurrencias de una palabra en el texto";
          cout<<"\n6) Imprime el texto por pantalla";
          cout<<"\n7) Inserta una palabra en una linea";
          cout<<"\n8) Borra la palabra en la posicion indicada";
          cout<<"\n9) Borra todas las ocurrencias de una palabra en la linea indicada";
          cout<<"\n10) Imprime la linea por pantalla";
          cout<<"\n\n0) SALIR";
          
          cout<<"\n\nOpcion: ";
          cin>>opcion;
          system("cls");
          
          switch(opcion)
          {
              case 1: {  cout<<"LINEA INSERTADA, PRESIONE UNA TECLA PARA CONTINUAR...";
                         insertar_fila_final(&L);
                      } break;
                      
              case 2: {  cout<<"Posicion ha insertar la linea: ";
                         cin>>x;
                         if(x>0 && x<=(cant_filas(&L)+1) )
                         {  
                            insertar_fila_posicion(x, &L);
                            system("cls");
                            cout<<"LINEA INSERTADA, PRESIONE UNA TECLA PARA CONTINUAR...";
                         }
                         else
                            cout<<"La posicion ingresada no es correcta";              
                      } break;
                      
              case 3: {  cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> BORRAR LINEA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
                         cout<<"Inserte posicion a borrar: ";
                         cin>>x;
                         if(x>0 && x<=cant_filas(&L) )
                         {
                            borrar_fila(x, &L);
                            system("cls");
                            cout<<"LINEA BORRADA, PRESIONE UNA TECLA PARA CONTINUAR...";
                         }
                         else
                            cout<<"La Linea no existe"; 
                      } break;
              case 4: {  cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> BORRAR TODO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
                         cout<<"ELIMINAR TEXTO? (S/N) ";
                         cin>>c;
                         if(c=='s'||c=='S')
                         {
                            borrar_todo(&L);
                            system("cls");
                            cout<<"TEXTO BORRADO, PRESIONE UNA TECLA PARA CONTINUAR...";
                         }
                         else
                         {   system("cls");
                             cout<<"OPERACION CANCELADA, PRESIONE UNA TECLA PARA CONTINUAR...";      
                         }
                      } break;
              case 5: {   cout<<">>>>>>>>>>>>>>>>>>>> BORRAR OCURRENCIAS DE PALABRA EN TEXTO <<<<<<<<<<<<<<<<<<<<";
                          cargar_palabra();
                          borrar_palabras_todas(&L);       
                          system("cls");
                          cout<<"PALABRA BORRADA, PRESIONE UNA TECLA PARA CONTINUAR...";
                      }break;
                      
              case 6: {  cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> IMPRIMIR TEXTO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
                         if(cant_filas(&L)>0)              
                           imprimir_texto(&L);
                         else
                           cout<<"EL TEXTO ESTA VACIO";
                      } break;
                      
              case 7: {  cout<<">>>>>>>>>>>>>>>>>>>>>>>> INSERTAR PALABRA SEGUN POSICION <<<<<<<<<<<<<<<<<<<<<<<"; 
                         cout<<"Numero de linea: ";
                         cin>>x;
                         cout<<"Numero de palabra: ";
                         cin>>y;
                         if(x>0 && x<=cant_filas(&L) && y>0 && y<=(cant_palabras(x, &L)+1) && y<=largo)
                         {
                            cargar_palabra();    
                            insertar_palabra(x,y,&L);
                            system("cls");
                            cout<<"PALABRA INSERTADA, PRESIONE UNA TECLA PARA CONTINUAR...";
                         }
                         else
                            cout<<"El numero de fila o posicion de palabra no es correcto";
                      }break;
              case 8: {  cout<<">>>>>>>>>>>>>>>>>>>>>>>>> BORRAR PALABRA SEGUN POSICION <<<<<<<<<<<<<<<<<<<<<<<<";
                         cout<<"Numero de linea: ";
                         cin>>x;
                         cout<<"Numero de palabra: ";
                         cin>>y;
                         if(x>0 && x<=cant_filas(&L) && y>0 && y<=cant_palabras(x, &L) )
                         { 
                            borrar_palabra(x,y,&L);
                            system("cls");
                            cout<<"PALABRA BORRADA, PRESIONE UNA TECLA PARA CONTINUAR...";
                         }
                         else
                            cout<<"El numero de fila o posicion de palabra no es correcto";
                      }break;
              case 9: {   cout<<">>>>>>>>>>>>>>>>>>>> BORRAR OCURRENCIAS DE PALABRA EN LINEA <<<<<<<<<<<<<<<<<<<<"; 
                          cout<<"Numero de fila: ";
                          cin>>x;
                          if(x>0 && x<=cant_filas(&L))
                          {
                                 cargar_palabra();
                                 borrar_palabras_fila(x,&L);
                                 system("cls");
                                 cout<<"PALABRA BORRADA, PRESIONE UNA TECLA PARA CONTINUAR...";
                          }
                          else
                              cout<<"El numero de fila no es correcto";
                      }break;
              case 10: {  cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> IMPRIMIR LINEA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
                          cout<<"\nIngrese la linea que desea imprimir: ";
                          cin>>x;
                          if(x>0 && x<=cant_filas(&L)) 
                             imprimir_fila(x, &L);
                          else
                             cout<<"\nEl numero de linea no es correcto";    
                       } break;
              case 0: cout<<"Presione una tecla para salir..."; break;
              default: cout<<"OPCION INCORRECTA"; break;
          }
          getch();
      }
      while(opcion!=0);
      
      
}
//cargar palabras en la variable pal
void cargar_palabra()
{
    int espacio, i;
    do{
         espacio=0;
         cout<<"Ingrese la palabra: ";
         fflush(stdin);
         gets(pal);
       
         for(i=0; i<25; i++)
            if(pal[i]==' ')
               espacio=1;
             
         if(espacio==1)
         {
            cout<<"La Palabra no debe contener espacio";
            getch(); 
            system("cls");
         }               
      } while(espacio!=0);
}
//insertar linea vacia al final
void insertar_fila_final(fila **p)
{
     int cont=0;
     fila *aux=new(fila);
     fila *temp=*p;
     
     aux->primero=NULL;
     aux->sig=NULL;
     if(temp==NULL)  
        *p=aux;
     else
     {
         while(temp->sig!=NULL)
             temp=temp->sig;
         temp->sig=aux;
         cont=temp->numF;
     }
     cont++;                           
     aux->numF=cont;
}
//insertar linea vacia en posicion indicada
void insertar_fila_posicion(int pos, fila **p)
{
     fila *nuevo, *actual, *anterior;
     
     nuevo=new(fila);
     if(nuevo!=NULL)
     {
         nuevo->numF=pos;
         nuevo->sig=NULL;
         nuevo->primero=NULL;
         actual=*p;
         anterior=NULL;
         
         if(pos==1)
         {
            nuevo->sig=*p;
            *p=nuevo;
         }
         else
         {
             while(actual!=NULL && pos>actual->numF)
             {
                anterior=actual;
                actual=actual->sig;
             }
                      
             anterior->sig=nuevo;
             nuevo->sig=actual;
             
         }
         
         while(actual!=NULL)
         {
             actual->numF++;
             actual=actual->sig;
         }
     }
     else
         cout<<"No hay memoria disponible";     
} 
//imprimir linea
void imprimir_fila(int pos, fila **p)
{
     fila *temp=*p;
     palabra *aux;
     
     if(temp==NULL)
     cout<<"No hay lineas para mostrar";
     else
     {
         while(temp->numF!=pos)
            temp=temp->sig;
         
         aux=temp->primero;
         cout<<pos<<") ";
         while(aux!=NULL)
         {  
            cout<<aux->numP<<": "<<aux->dato;
            aux=aux->sig;
         }
     }  
}

//cuanta la cantidad de lineas que tiene el texto
int cant_filas(fila **p)
{
    int cant=0;
    fila *temp=*p;
    
    while(temp!=NULL)
    {
       cant++;
       temp=temp->sig;
    }
    return cant;
}              
//cantidad de palabras en una linea
int cant_palabras(int pos, fila** p)
{
    int cant=0;
    fila *temp=*p;
    palabra *actual;
    
    while(temp->numF!=pos)
       temp=temp->sig;
    
    actual=temp->primero;
    while(actual!=NULL)
    {
       cant++;
       actual=actual->sig;
    }
    return cant;
}
//insertar palabra en fila y posicion determinada    
void insertar_palabra(int f, int c, fila **p)
{
   fila *actual=*p,*aux;
   palabra *nuevo, *previo, *temp;
   
   nuevo=new(palabra);
   strcpy(nuevo->dato,pal);
   nuevo->numP=c;
   
   while(actual->numF<f)
      actual=actual->sig;
      
   temp=actual->primero;
   if(c==1)
   {
       nuevo->sig=actual->primero;
       actual->primero=nuevo;
   }
   else
   {
       while(temp!=NULL && c>temp->numP)
       {
          previo=temp;
          temp=temp->sig;
       }
       previo->sig=nuevo;
       nuevo->sig=temp;
       previo=nuevo;
   }
   
   while(temp!=NULL)
   { 
       temp->numP++;
       if(temp->numP>largo)
          previo->sig=NULL;
       previo=temp;   
       temp=temp->sig;
   
       if(previo->numP>largo)
       {
           previo->numP=1;
           if(actual->sig==NULL)
           {
              aux=new(fila);
              actual->sig=aux;
              aux->sig=NULL;
              aux->primero=previo;
              aux->numF=(actual->numF)+1;
              previo->sig=NULL;
           }             
           else
           { 
              actual=actual->sig;
              previo->sig=actual->primero;
              actual->primero=previo;
              temp=previo->sig;
           }  
        }
   
   }
}
//imprime el texto completo
void imprimir_texto(fila** p)
{
     fila *temp=*p;
     palabra *aux;
     
     while(temp!=NULL)
     {  
        aux=temp->primero;
        cout<<temp->numF<<") ";
        while(aux!=NULL)
        {  
           cout<<aux->numP<<": "<<aux->dato<<" ";
           aux=aux->sig;
        }
        cout<<"\n";
        temp=temp->sig;
     }   
}  

//borra la fila deseada
void borrar_fila(int pos, fila** p)
{
     fila *temp, *anterior, *aux;
     palabra *actual;
     
     if(pos==(*p)->numF)
     {
         aux=*p;
         *p=(*p)->sig;
     }
     else
     {
         anterior=*p;
         temp=(*p)->sig;
         while(temp->numF!=pos)
         {
            anterior=temp;
            temp=temp->sig;
         }
         aux=temp;
         anterior->sig=temp->sig;
     
     }
     temp=aux->sig;
     actual=aux->primero;
     while(actual!=NULL)
     {
        aux->primero=actual->sig;
        free(actual);
        actual=aux->primero;
     }               
     free(aux);
     while(temp!=NULL)
     {
        temp->numF--;
        temp=temp->sig;
     }
}

//borra todo el texto
void borrar_todo(fila** p)
{
     fila *aux;
     palabra *actual;
     
     while(*p!=NULL)
     {
        aux=*p;
        *p=(*p)->sig;
        actual=aux->primero;
        
        while(actual!=NULL)
        {
           aux->primero=actual->sig;
           free(actual);
           actual=aux->primero;
        }
        free(aux);
     }
}
//borrar palabra segun posicion
void borrar_palabra(int f, int c, fila** p)
{
     fila *actual=*p;
     palabra *temp, *anterior, *aux;
     
     while(actual->numF<f)
        actual=actual->sig;
        
     temp=actual->primero;
     while(temp->numP<c)
     {
         anterior=temp;
         temp=temp->sig;
     }
     
     if(c==1)
         actual->primero=temp->sig;
     else
         anterior->sig=temp->sig;
         
     aux=temp;
     temp=aux->sig;
     free(aux);
     while(temp!=NULL)
     {
         temp->numP--;
         temp=temp->sig;
     }
}            
//borrar ocurrencias de una palabra en una fila
void borrar_palabras_fila(int pos, fila** p)
{
     fila *temp=*p;
     palabra *actual, *anterior, *aux;
     
     while(temp->numF<pos)
        temp=temp->sig;
     
     actual=temp->primero;   
     while(actual!=NULL)
     {                   
         if(strcmp(actual->dato,pal)==0)
         {
            if(actual==temp->primero)
            {
               temp->primero=actual->sig;
               aux=actual;
               actual=aux->sig;
               free(aux);  
            }
            else
            {
                anterior->sig=actual->sig;
                aux=actual;
                actual=aux->sig;
                free(aux);
            }
         }
         else
         {
            anterior=actual;
            actual=actual->sig;
         }
     }
     
     if(temp->primero!=NULL)
     {
        temp->primero->numP=1;
        anterior=temp->primero;
        actual=temp->primero->sig;
     }
     while(actual!=NULL)
     {
        actual->numP=(anterior->numP)+1;
        anterior=actual;
        actual=actual->sig;
     }                                    
}           
//borrar las ocurrencias de una palabra en el texto
void borrar_palabras_todas(fila ** p)              
{
     fila *temp=*p;
     
     while(temp!=NULL)
     {
         borrar_palabras_fila(temp->numF,p);
         temp=temp->sig;
     }            
}
