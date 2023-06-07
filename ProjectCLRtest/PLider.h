#pragma once
#include "PersonajeBase.h"

enum PoseLider
{
    CaminarArriba = 3,
    CaminarAbajo =0,
    CaminarIzquierda = 1,
    CaminarDerecha = 2
};

class PLider :
    public PersonajeBase
{

    PoseLider xpose;

public:
    PLider(Bitmap^ img);

    void Mover(Graphics^ g);

    void Dibujar(Graphics^ g, Bitmap^ img);

    void SetAccion(PoseLider value);

    void EnviarOrden();

};

