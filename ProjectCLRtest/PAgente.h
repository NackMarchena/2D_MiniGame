#pragma once
#include "PersonajeBase.h"
#include  "PAliados.h"



enum PoseAgente
{
    AGCaminarArriba = 3,
    AGCaminarAbajo = 0,
    AGCaminarIzquierda = 1,
    AGCaminarDerecha = 2
};


class PAgente :
    public PersonajeBase
{

protected:

    PoseAgente poseagente;
    int direccionAgente;
    

public:
    
    PAgente(Bitmap^ img, int _alto, int _ancho);

    void Mover(Graphics^ g, Rectangle r, PAliados* aliado, GenPAliados* aliados);

    void Dibujar(Graphics^ g, Bitmap^ img);

    void EliminarAliado();
    


};

class GenPAgentes
{
private:
    vector<PAgente*> agentes;
public:

    ~GenPAgentes();
    int Size();
    PAgente* Get(int pos);
    void RebotaAgente(Rectangle lider);
    void Agregar(PAgente* aliado);
    void Vaciar();
    void Mover(Graphics^ g, Rectangle r, PAliados* aliado, GenPAliados* aliados);
    void Dibujar(Graphics^ g, Bitmap^ img);
};