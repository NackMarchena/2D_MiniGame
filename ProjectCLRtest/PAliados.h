#pragma once
#include "PersonajeBase.h"

enum PoseAliado
{
    lCaminarArriba = 3,
    lCaminarAbajo = 0,
    lCaminarIzquierda = 1,
    lCaminarDerecha = 2
};


class PAliados :
    public PersonajeBase
{

protected:

    PoseAliado posealiado;
    int direccionAliado;

public:

    PAliados(Bitmap^ img, int _alto, int _ancho);

    void Mover(Graphics^ g);

    void Dibujar(Graphics^ g, Bitmap^ img);

    void AsistirHabitante();

    void EvadirAgente();

    void Destruir();

};

class GenPAliados
{
private:
    vector<PAliados*> aliados;
public:

    ~GenPAliados();
    int EliminaAliado(Rectangle r);
    int Size();
    PAliados* Get(int pos);
    void Agregar(PAliados* aliado);
    void Vaciar();
    void Mover(Graphics^ g);
    void Dibujar(Graphics^ g, Bitmap^ img);
    PAliados* getAliado();
};


