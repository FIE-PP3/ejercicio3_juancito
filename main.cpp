#include <iostream>

using namespace std;
class Empleado{
private:
    int dias_faltados;
    float resultados;
    float sueldo;
public:
    Empleado(int cant, float res,int s){
        dias_faltados=cant;
        resultados=res;
        sueldo=s;
    }
    int getDias_faltados()const{return dias_faltados;}
    float getResultados() const{return resultados;}
    float getSueldo() const{return sueldo;}
    virtual void calcularSueldo() const{
        float salario,bono1,bono2;
        int dias=getDias_faltados();
        float sueldos=getSueldo();
        float resultado=getResultados();
        if (dias==0){
            bono1=100;
        } else if( dias==1){
            bono1=50;
        } else{
            bono1=0;
        }
        if (resultado>6 && resultado<=10){
            bono2=sueldos*0.10;
        } else if(resultado<=6 && resultado>3){
            bono2=80;
        } else{
            bono2=0;
        }
        salario=(float )sueldos+bono1+bono2;
        cout<<"El sueldo del empleado de categoria gerente es de: "<<salario<<endl;

    }
};
class gerentes:public Empleado{
public:
    gerentes(int cant,float res): Empleado(cant,res,1000){}

};
class cadete:public Empleado{
public:
    cadete(int cant, float res): Empleado(cant,res,1500){}

};
int main() {
    gerentes pepe(0,8);
    pepe.calcularSueldo();
    cadete pepe2(2,2);
    pepe2.calcularSueldo();
    return 0;
}
